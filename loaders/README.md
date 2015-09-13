
# Creating a new loader for instantConfig

In instantConfig, a loader is only used as a template parameter to the `load` function of the configuration description. 
As such, the only required conformance of a class to be used as a loader is as follows:
 * Have a member typedef `ValueType` : this type will be passed back and forth between the loader and the loading function. It represents one entry of the configuration file in the dialect of the loader's library.
 * Have the following member functions defined:
   ** `const ValueType& getRoot() const`
      Returns the root of the configuration
      
   ** `bool hasValue(const ValueType& from, const std::string& settingName) const `
      
   ** `std::vector<std::string> getContainedValues(const ValueType& from) const`
      Returns the list of child settings to the given `from` entry.
      
   ** `const ValueType& getContainedValue(const ValueType& from, const std::string& name) const`
      Returns the child element of `from` going by `name`.
      
   ** `template <typename SettingType> void getValue(const ValueType& parent, const std::string& name, SettingType& dest) const `
      Sets `dest` to the value of the child element of `parent` going by `name`.
      
Error management is currently handled by throwing `std::string` which content is the description of the error.
