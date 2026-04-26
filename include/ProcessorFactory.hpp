#ifndef PROCESSORFACTORY_HPP
#define PROCESSORFACTORY_HPP
#include <iostream>
#include "Processor.hpp"

class ProcessorFactory {
public:
    static Processor* createProcessor(const std::string& type);
};
#endif 