#include "../include/Processor.hpp"
#include "../include/ProcessorFactory.hpp"
#include "../include/Configuration.hpp"
#include <iostream>
#include <sstream> 

int main() {
    try {
        Configuration config;
        config.load("config/settings.txt");
        config.printSettings();

        std::string processorType = config.getSetting("Processor.Options.Type");

        Processor* processor = ProcessorFactory::createProcessor(processorType);

        std::stringstream thresholdStream(config.getSetting("Processor.Options.Threshold"));
        double threshold = 0.0;
        thresholdStream >> threshold;
        processor->setThreshold(threshold);

        std::stringstream retriesStream(config.getSetting("Processor.Options.MaxRetries"));
        int maxRetries = 0;
        retriesStream >> maxRetries;
        processor->setMaxRetries(maxRetries);

        if (processorType == "Image") {
            ImageProcessor* imgProcessor = dynamic_cast<ImageProcessor*>(processor);
            if (imgProcessor) {
            imgProcessor->setQuality(config.getSetting("Processor.Options.Quality"));
            }
        }

        std::cout << "Processor created: " << processorType << std::endl;
        processor->process("Sample Data");

        delete processor;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}