#ifndef INSTANTCFG_JSONCONS_LOADER
#define INSTANTCFG_JSONCONS_LOADER

#include "jsoncons/json.hpp"

#include <iterator>
#include <fstream>

namespace icfg{

  class jsoncons_loader{

  public:
    typedef jsoncons::json ValueType;

  public:
    //throws jsoncons::json_parse_exception on error
    jsoncons_loader(const std::string& fileName){
    
      mRoot = jsoncons::json::parse_file(fileName);
      
    }
    
    const ValueType& getRoot() const {
      return mRoot;
    }
    
    bool hasValue(const ValueType& from, const std::string& settingName) const {
      return from.has_member(settingName);
    }
    
    std::vector<std::string> getContainedValues(const ValueType& from) const{
      std::vector<std::string> lMembers;
      
      if (from.is<jsoncons::json::object>()){
        std::for_each(from.begin_members(), from.end_members(), [&lMembers](const jsoncons::json::member_type& val){lMembers.push_back(val.name());});
      }
      
      return lMembers;
    }
    
    const ValueType& getContainedValue(const ValueType& from, const std::string& name) const{
      return from[name];
    }

    template <typename SettingType>
    void getValue(const ValueType& parent, const std::string& name, SettingType& dest) const {
      const jsoncons::json& from = parent[name];
      
      if (from.is_null()) {
        throw std::string("missing value : " + name);
      }

      extract(from, name, dest);
    }
    
    void extract(const ValueType& from, const std::string& name, std::string& dest) const {

      if (!from.is_string()){
        throw std::string("value "+name+" is expected to be a string");
      }
      
      dest = from.as_string();
    }
    
    void extract(const ValueType& from, const std::string& name, int8_t& dest) const {

      if (!from.is<short>()){
        throw std::string("value "+name+" is expected to be a int8_t");
      }
      
      dest = static_cast<int8_t>(from.as<short>());
    }
    
    void extract(const ValueType& from, const std::string& name, uint8_t& dest) const {

      if (!from.is<unsigned short>()){
        throw std::string("value "+name+" is expected to be a uint8_t");
      }
      
      dest = static_cast<uint8_t>(from.as<unsigned short>());
    }
    
    void extract(const ValueType& from, const std::string& name, float& dest) const {

      if (!from.is<double>()){
        throw std::string("value "+name+" is expected to be a float");
      }
      
      dest = static_cast<float>(from.as<double>());
    }
    
    template <typename SettingType>
    void extract(const ValueType& from, const std::string& name, SettingType& dest) const {
      
      if (!from.is<SettingType>()) {
        throw std::string("value " + name + " is expected to be a "+getTypeName<SettingType>());
      }

      dest = static_cast<SettingType>(from.as<SettingType>());
    }
    
    template <typename ValueT>
    void extract(const ValueType& from, const std::string& name, std::vector<ValueT>& dest) const {
      
      if (!from.is_array()) {
        throw std::string("value " + name + " is expected to be an array");
      }
      
      std::size_t ind;
      std:for_each(from.begin_elements(), from.end_elements(), 
      [&](const jsoncons::json& elm){
        ValueT outputValue;
        this->extract(elm, name + "[" + std::to_string(ind) + "]", outputValue);
        dest.push_back(outputValue);
        ++ind;
      });
    }
    
  private:
    template <typename SettingType>
    std::string getTypeName() const{
      return "'unknown type'";
    }
    
  private:
    jsoncons::json mRoot;

  };
  
  
    template <>
    std::string jsoncons_loader::getTypeName<bool>() const{
      return "bool";
    }
    
    template <>
    std::string jsoncons_loader::getTypeName<int16_t>() const{
      return "int16_t";
    }
    
    template <>
    std::string jsoncons_loader::getTypeName<uint16_t>() const{
      return "uint16_t";
    }
    
    template <>
    std::string jsoncons_loader::getTypeName<int32_t>() const{
      return "int32_t";
    }
    
    template <>
    std::string jsoncons_loader::getTypeName<uint32_t>() const{
      return "uint32_t";
    }
    
    template <>
    std::string jsoncons_loader::getTypeName<int64_t>() const{
      return "int64_t";
    }
    
    template <>
    std::string jsoncons_loader::getTypeName<uint64_t>() const{
      return "uint64_t";
    }
    
    template <>
    std::string jsoncons_loader::getTypeName<double>() const{
      return "double";
    }
    
}

#endif //INSTANTCFG_JSONCONS_LOADER