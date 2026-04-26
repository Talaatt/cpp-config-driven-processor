#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP
#include <iostream>
#include <map>
#include <string>

class Configuration{
public:
    Configuration(){} 
    std::map<std::string, std::string> settings;
    void load(const std::string& filename);
    std::string getSetting(const std::string& key);
    void printSettings() const;
};
#endif 