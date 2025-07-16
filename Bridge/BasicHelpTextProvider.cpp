#include "BasicHelpTextProvider.h"

BasicHelpTextProvider::BasicHelpTextProvider(const std::string& helpText) : helpText(helpText) {}

std::string BasicHelpTextProvider::getHelpText() const {
    return helpText;
}

void BasicHelpTextProvider::setHelpText(const std::string& helpText) {
    this->helpText = helpText;
}