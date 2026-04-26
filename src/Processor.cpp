#include "../include/Processor.hpp"
#include <iostream>

void TextProcessor::process(const std::string& data){
    std::cout << "TextProcessor processing: " << data
              << " | Type: " << type
              << " | Threshold: " << threshold
              << " | MaxRetries: " << maxRetries << std::endl;
}

void NumericProcessor::process(const std::string& data){
    std::cout << "NumericProcessor processing: " << data
              << " | Type: " << type
              << " | Threshold: " << threshold
              << " | MaxRetries: " << maxRetries << std::endl;
}

void ImageProcessor::process(const std::string& data){
    std::cout << "ImageProcessor processing: " << data
              << " | Type: " << type
              << " | Quality: " << quality
              << " | Threshold: " << threshold
              << " | MaxRetries: " << maxRetries << std::endl;
}

void AudioProcessor::process(const std::string& data){
    std::cout << "AudioProcessor processing: " << data
              << " | Type: " << type
              << " | Threshold: " << threshold
              << " | MaxRetries: " << maxRetries << std::endl;
}