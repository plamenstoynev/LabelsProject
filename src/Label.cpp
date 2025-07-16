#include "Label.h"
#include <stdexcept>

#include "LabelImp.h"

Label::Label(LabelImpl *impl, HelpTextProvider *helpTextProvider)
    : impl(impl), helpTextProvider(helpTextProvider) {}

std::string Label::getText() const {
    if (impl)
        return impl->getText();
    else
        throw std::runtime_error("Label implementation is not available");
}

HelpTextProvider *Label::getHelpTextProvider() const {
    if (isHelpTextAvailable())
        return helpTextProvider;
    else
        throw std::runtime_error("Help text provider is not available");
}

void Label::setText(const std::string& text) {
    // Add your implementation here
    // This might delegate to impl if needed
}

bool Label::checkTimeout() const {
    return false;
}

bool Label::isHelpTextAvailable() const {
    return helpTextProvider != nullptr;
}