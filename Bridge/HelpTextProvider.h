#pragma once
#include <string>

class HelpTextProvider {
public:
    virtual std::string getHelpText() const = 0;
    virtual ~HelpTextProvider() = default;
};