#pragma once
#include <string>

class Helptext {
public:
    virtual std::string getHelpText() const = 0;
    virtual void setHelpText(const std::string& helpText) = 0;
    virtual  ~Helptext() = default;
};
