#include "../include/Configuration.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <map>

void Configuration::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) throw std::runtime_error("Configuration file not found");

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream is_line(line);
        std::string key, value;
        if (std::getline(is_line, key, '=') && std::getline(is_line, value)) {
        settings[key] = value;
        }
    }
}
std::string Configuration::getSetting(const std::string& key) {
    if (settings.find(key) == settings.end())
    throw std::runtime_error("Missing configuration key: " + key);
    return settings[key];
}
void Configuration::printSettings() const {
    std::cout << "Current Configuration Settings:" << std::endl;

    std::map<std::string, std::string>::const_iterator it;
    for (it = settings.begin(); it != settings.end(); ++it) {
    std::cout << it->first << " = " << it->second << std::endl;
    }
}