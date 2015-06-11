

# So, another configuration file library?
*instantConfig* is not a configuration file loader. It rather provides an abstraction over configuration file loaders to make their use easier.
Ever noticed how using configuration libraries is always so similar whatever the library? Load the file, look for an existing setting name, check its existence, its type, load the value to a variable. This is all so repetitive and tedious to get right.
*instantConfig* makes use of metaprogramming to make it all happen in a descriptive way.
Through the use of a Domain Specific Language to describe the expected content of a configuration, *instantConfig* generates the sequence of operations and verifications to properly load the content of the file. The result of the load operation is statically typed to match the content that you expect. You can easily check for errors during the load process and display them when loading fails.


# How to use it
 * Describe the expected content for your configuration file in C++ code.
 * Instantiate a loader depending of which file format you want to load (XML, json, ini, ...)
 * Load the configuration description using your loader. The result is the statically-typed content of your configuration file.
 * Check for errors if any, and display them.
 * Directly address the statically-typed settings from the loading step result. No need for a cast of any kind, it's all ready to use as you expect.
 

# Example
Let's suppose that I want to get from a configuration file a string setting "ApplicationName" and a list of strings "Modules". 

## Creating the configuration description
I can create my confirguration description in the following way:

```cpp
using namespace icfg;
auto myConfigDef = 
config(
  setting(ICFG_STR("ApplicationName"), string),
  setting(ICFG_STR("Modules"), list(string))
);
```

## Loading the configuration file
Now in the function where I want to load the settings, I instantiate a loader for the file format I want, use it to load the configuration description.

```cpp
//create the loader for a specific file format
MyFormatLoader loader("config.myformat");

//load the configuration using the loader
auto myConfig = myConfigDef.load(loader);
```

## Using the loaded settings
I can the easily access each setting using its name, and get a value of appropriate type
```cpp
//the access to the setting "ApplicationName" brings a std::string typed result
std::cout<<"ApplicationName : "<<myConfig.get(ICFG_STR("ApplicationName"))<<std::endl;

//whereas the access to "Modules" brings a std::vector<std::string> result
std::cout<<"Modules : ";
for (auto& name : myConfig.get(ICFG_STR("Modules"))){
  std::cout<<name<<',';
}
```

## Checking for errors
Before using the loaded configuration, it is strongly advised to check for errors:

```cpp
if (myConfig.hasError()){
  std::cout<<"Errors:"<<std::endl;
  for(auto& error : myConfig.getErrors()){
    std::cout<<err.getFailingSettingName()<<" : "<<err.what()<<std::endl;
  }
} else {
  std::cout<<"no error while loading configuration"<<std::endl;
}
```


# Features
 * Multiple data types : integers and unsigned integers of usual sizes, string, list of any type.
 * Hierarchical configurations (*section*)
 * Define the configuration for each class at the appropriate location (*include*)
 * Check for constraints validation (using lambdas or specific keywords)
 * Dependency injection
 * Descriptive compile-time error messages
 * Compiler compatibility
 * Available loaders

## Data types
instantConfig supports describing settings of various types.
The basic types are : 
 * integers : using keywords int8, uint8, int16, uint16, int32, uint32, int64, uint64
 * floating point : float32 and float64
 * boolean : the boolean keyword
 * strings : the string keyword

It also supports "template" types : 
 * list of value : list(element type) For instance : list(string) is a list of strings (std::vector<std::string>)
 * a map : an associative container from a string value to a configuration section.
 
Here is the match table between the instantConfig keyword and the corresponding c++ type:

| instantConfig |       c++      |
|:-------------:|:--------------:|
| u/int8        | std::u/int8_t  |
| u/int16       | std::u/int16_t |
| u/int32       | std::u/int32_t |
| u/int64       | std::u/int64_t |
| float32       | float          |
| float64       | double         |
| boolean       | bool           |
| string        | std::string    |
| list          | std::vector<T> |
| map           | std::unordered_map<std::string, T>|
 
## Hierarchical configuration
It is often practical in big configuration file to have separate locations for different semantics of settings. instantConfig implements this requirement by the mean of sections. A section is named, and contains settings of any kind (simple settings, lists, ...).

Here is an example of the use of sections, and how it maps to a json file:

```cpp
auto myConfigDef = 
config(
  section(ICFG_STR("Graphics"),
    section(ICFG_STR("Resolution"),
      setting(ICFG_STR("Width", uint32)),
      setting(ICFG_STR("Height", uint32))
    ),
    setting(ICFG_STR("Fullscreen"), boolean)
  ),
  section(ICFG_STR("Gameplay"),
    setting(ICFG_STR("PlayerName", string)
  )
);
```

could load: 
```javascript
{
  'Graphics':{
    'Resolution':{
      'Width':1920,
      'Height':1080
    },
    'Fullscreen':false
  },
  'Gameplay':{
    'PlayerName':'rubik'
  }
}
```

## Inclusion of subdefinitions
When in a complex project you have multiple classes, each needing its own set of settings, it makes sense to be able to define their configuration within their respective classe definition. instantConfig provides a way to include a configuration definition inside another.
For instance, we have an application with an Application main class and a Graphics subsystem defined as follows : 
```cpp
class Application{

};

class Graphics{

};
```

Defining the same configuration definition as the previous example can be done as follows:

```cpp
class Application{

  static auto getConfig(){
    return config(
      section(ICFG_STR("Gameplay"),
        setting(ICFG_STR("PlayerName", string)
      ),
      section(ICFG_STR("Graphics"),
        include(Graphics::getConfig())
      )
    );
  }
  
};

class Graphics{

  static auto getConfig(){
    return config(
      section(ICFG_STR("Resolution"),
        setting(ICFG_STR("Width", uint32)),
        setting(ICFG_STR("Height", uint32))
      ),
      setting(ICFG_STR("Fullscreen"), boolean)
    );
  }

};
```

## Check for constraints validation
More than just loading settings from a file, instantConfig also provides ways to define explicit constraints on those settings. These constraints are check at load time and an error is reported whenever one of them is not met.
Constraints can be defined in two ways : using a specific keyword or using the check() function, passing it a lambda.


### The length constraint
For now, only one keyword has been implemented as a constraint descriptor : length. By passing a comparison expression including the length keyword, you specify a constraint on the expected length of the loaded setting. It applies to setting type for which the length is meaningful (string and list).

Here is an example use of the length keyword:
```cpp
config(
  setting(ICFG_STR("PlayerName", string, length>3) //the string is required to be more than 3 characters
)
```

### Lambda constraints
A more generic way of defining a constraint uses the check() function. 
Check takes two parameters:
 * A name or short description of the constraint, using the ICFG_STR() macro.
 * A functor that is executed to check the validity of the setting : it must take a proper resulting parameter type, matching the specified setting definition, and return a bool value.

Here is an example of the use of the check function:

```cpp

bool is_valid_playername(const std::string& name){
  return std::all_of(std::begin(name), std::end(name), static_cast<int(*)(int)>(&std::isalnum));
}

config(
  setting(ICFG_STR("PlayerName", string, 
    check(ICFG_STR("ValidPlayerName"), 
      [](std::string name){
        return !name.empty() && std::all_of(std::begin(name), std::end(name), &is_valid_playername);
      }
    )
  ) //the string is required to be non-empty alphanumeric characters
)
```

## Dependency injection
[Dependency injection](http://en.wikipedia.org/wiki/Dependency_injection) gives the possibility to deeply modify the behavior of a program from the configuration file. Support for this pattern is provided by instantConfig by using the switchOn/caseOf keywords. Much like their counterparts from the c++ language, these keywords allow to define alternate reading of the configuration definition based on the value of a reference string setting.

Let's develop an example that will make its purpose and use more obvious. Let's suppose we have a game for which we want to give a choice for the user to play using either the keyboard or the mouse. The choice is set using the configuration file. Moreover, depending on the choice of one of the two controllers, some specific settings have to be set, such as the sensitivity for the mouse controller, or the key mappings for the keyboard controller.

With instantConfig, you can implement such a requirement using the switchOn/caseOf pair of function.
switchOn takes as first parameter the name of a setting, which must be a string setting, that will be tested against each case. All other parameters to switchOn must be caseOf functions.
caseOf function takes an ICFG_STR string as first parameter and settings definitions just like the config function for the rest. The first parameter is the value to the setting defined in switchOn that will enable this section of configuration.

Let's see the previous example implemented with instantConfig:
```cpp
auto getConfig(){
  return config(
    switchOn( ICFG_STR("Type"),
      caseOf( ICFG_STR("Mouse"),
        setting( ICFG_STR("Sensitivity"), float32)
      ),
      caseOf( ICFG_STR("Keyboard"),
        setting( ICFG_STR("Jump"), string),
        setting( ICFG_STR("Shoot"), string)
      )
    )
  );
}
```

An example of such a valid configuration file, using json format, looks like this:
```javascript
{
  'Type':'Mouse',
  'Sensitivity':0.5
}
//or 
{
  'Type':'Keyboard',
  'Jump':'Space',
  'Shoot':'Enter'
}
```

## Descriptive compile-time error messages
Given the complexity of the template metaprogramming that take place under the hood, mistakes in the configuration definition can lead to very harsh compilation errors. In order to avoid panick attacks in such cases, I tried to harness public functions with a solid harness of static error checking with descriptive error messages.

## Compiler compatibility
The whole set of static unit tests has been run and validated against g++ 4.7.2 and Visual Studio 2015 RC on Windows, as well as g++ 4.8.1 and clang 3.5 on Ubuntu 12.04. If you can contribute by running the test with other compilers on other OSes, it will be greatly appreciated.

## Available loaders
Available loaders can be found in the *loaders* subdirectory.

For now, only the json loader using json-cpp has been implemented.
Implementing a loader using another library is really easy and contributions are welcome.


