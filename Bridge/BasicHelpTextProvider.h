#pragma once
#include "HelpTextProvider.h"

class BasicHelpTextProvider : public HelpTextProvider {
private:
    std::string helpText;
public:
    explicit BasicHelpTextProvider(const std::string& helpText);
    std::string getHelpText() const override;
    void setHelpText(const std::string& helpText);
    ~BasicHelpTextProvider() override = default;
};