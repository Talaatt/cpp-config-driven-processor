#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP
#include <iostream>
#include <string>

class Processor{
protected:
    std::string type;
    double threshold;
    int maxRetries;
public:
    Processor() : type("Undefined"), threshold(0.0), maxRetries(1) {}
    virtual void process(const std::string& data) = 0;
    virtual ~Processor() {}
    virtual std::string getName() const = 0;
    void setType(const std::string& t) { type = t; }
    void setThreshold(double t) { threshold = t; }
    void setMaxRetries(int m) { maxRetries = m; }
    std::string getType() const { return type; }
    double getThreshold() const { return threshold; }
    int getMaxRetries() const { return maxRetries; }
};

class TextProcessor : public Processor{
public:
    void process(const std::string& data);
    TextProcessor(){ type = "Text"; }
    std::string getName() const override{ return "TextProcessor";}
};

class NumericProcessor : public Processor{
public:
    NumericProcessor() { type = "Numeric"; }
    void process(const std::string& data) override;
    std::string getName() const override { return "NumericProcessor"; }
};

class ImageProcessor : public Processor{
private:
    std::string quality;

public:
    ImageProcessor() { type = "Image"; }
    void process(const std::string& data) override;
    std::string getName() const override { return "ImageProcessor"; }
    void setQuality(const std::string& q) { quality = q; }
    std::string getQuality() const { return quality; }
};

class AudioProcessor : public Processor {
public:
    AudioProcessor() { type = "Audio"; }
    void process(const std::string& data) override;
    std::string getName() const override { return "AudioProcessor"; }
};
#endif
