#pragma once
#include <string>

class HelpText {
private:
    std::string helpText;
public:
    explicit HelpText(const std::string& helpText) : helpText(helpText) {}
    ~HelpText() = default;
    std::string getHelpText() const {return helpText;};
};