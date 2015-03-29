#ifndef INSTANTCFG_JSONCPP_LOADER
#define INSTANTCFG_JSONCPP_LOADER

#include <json/reader.h>
#include <json/value.h>

#include <iterator>
#include <fstream>

class jsoncppLoader{

public:
  typedef Json::Value ValueType;

public:

  jsoncppLoader(const std::string& fileName){
  
    std::string fileContent;
    std::ifstream file(fileName.c_str());
    if (!file){
      throw std::string("couldn't open config file "+fileName);
    }
    
    file>>std::noskipws;
    
    std::copy(std::istream_iterator<char>(file), std::istream_iterator<char>(), std::back_inserter(fileContent));
    Json::Reader reader;
    bool success = reader.parse(fileContent, mRoot);
    
    if (!success){
      throw std::string("parse error in file "+fileName + " : "+reader.getFormattedErrorMessages());
    }
  }
  
  const ValueType& getRoot() const {
    return mRoot;
  }
  
  bool hasValue(const ValueType& from, const std::string& settingName) const {
    return from.isMember(settingName);
  }
  
  std::vector<std::string> getContainedValues(const ValueType& from) const{
    return from.getMemberNames();
  }
  
  const ValueType& getContainedValue(const ValueType& from, const std::string& name) const{
    return from[name];
  }

  template <typename SettingType>
  void getValue(const ValueType& parent, const std::string& name, SettingType& dest) const {
	  Json::Value from = parent[name];
	  
	  if (from.isNull()) {
		  throw std::string("missing value : " + name);
	  }

	  extract(from, name, dest);
  }
  
  void extract(const ValueType& from, const std::string& name, std::string& dest) const {

    if (!from.isString()){
      throw std::string("value "+name+" is expected to be a string");
    }
    
    dest = from.asString();
  }

  void extract(const ValueType& from, const std::string& name, bool& dest) const {
	  
	  if (!from.isBool()) {
		  throw std::string("value " + name + " is expected to be a boolean");
	  }

	  dest = static_cast<bool>(from.asBool());
  }
  
  void extract(const ValueType& from, const std::string& name, int8_t& dest) const{
    
    if (!from.isInt()){
      throw std::string("value "+name+" is expected to be an integer");
    }
    
    dest = static_cast<int8_t>(from.asInt());
  }
  
  void extract(const ValueType& from, const std::string& name, uint8_t& dest) const{
    
    if (!from.isUInt()){
      throw std::string("value "+name+" is expected to be an integer");
    }
    
    dest = static_cast<uint8_t>(from.asUInt());
  }
  
  void extract(const ValueType& from, const std::string& name, int16_t& dest) const{
    
    if (!from.isInt()){
      throw std::string("value "+name+" is expected to be an integer");
    }
    
    dest = static_cast<int16_t>(from.asInt());
  }
  
  void extract(const ValueType& from, const std::string& name, uint16_t& dest) const{
    
    if (!from.isUInt()){
      throw std::string("value "+name+" is expected to be an integer");
    }
    
    dest = static_cast<uint16_t>(from.asUInt());
  }
  
  void extract(const ValueType& from, const std::string& name, int32_t& dest) const{
    
    if (!from.isInt()){
      throw std::string("value "+name+" is expected to be an integer");
    }
    
    dest = static_cast<int32_t>(from.asInt());
  }
  
  void extract(const ValueType& from, const std::string& name, uint32_t& dest) const{
    
    if (!from.isUInt()){
      throw std::string("value "+name+" is expected to be a string");
    }
    
    dest = static_cast<uint32_t>(from.asUInt());
  }
  
  void extract(const ValueType& from, const std::string& name, int64_t& dest) const{
    
    if (!from.isInt64()){
      throw std::string("value "+name+" is expected to be a string");
    }
    
    dest = static_cast<int64_t>(from.asInt64());
  }
  
  void extract(const ValueType& from, const std::string& name, uint64_t& dest) const{
    
    if (!from.isUInt64()){
      throw std::string("value "+name+" is expected to be an integer");
    }
    
    dest = static_cast<uint64_t>(from.asUInt64());
  }
  
  void extract(const ValueType& from, const std::string& name, float& dest) const{
    
    if (!from.isDouble()){
      throw std::string("value "+name+" is expected to be a string");
    }
    
    dest = from.asFloat();
  }
  
  void extract(const ValueType& from, const std::string& name, double& dest) const{
    
    if (!from.isDouble()){
      throw std::string("value "+name+" is expected to be a double");
    }
    
    dest = from.asDouble();
  }
  
  template <typename ValueT>
  void extract(const ValueType& from, const std::string& name, std::vector<ValueT>& dest) const {
	  
	  if (!from.isArray()) {
		  throw std::string("value " + name + " is expected to be an array");
	  }

	  for (size_t i = 0; i<from.size(); ++i) {
		  ValueT outputValue;
		  extract(from[i], name + "[" + std::to_string(i) + "]", outputValue);
		  dest.push_back(outputValue);
	  }
  }
  
private:
  Json::Value mRoot;

};


#endif