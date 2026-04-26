#include "../include/ProcessorFactory.hpp"
#include "../include/Processor.hpp"
#include <stdexcept>
#include <iostream>

Processor* ProcessorFactory::createProcessor(const std::string& type) {
    if (type == "Text") return new TextProcessor();
    if (type == "Numeric") return new NumericProcessor();
    if (type == "Image") return new ImageProcessor();
    if (type == "Audio") return new AudioProcessor();
    throw std::runtime_error("Invalid processor type: " + type);
}