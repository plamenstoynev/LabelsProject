#pragma once
#include <string>
#include <memory>
#include "../Bridge/HelpText.h"

class LabelImpl {
private:
    std::unique_ptr<HelpText> helpTextProvider;
public:
    virtual std::string getText() const = 0;
    virtual LabelImpl* removeDecorator(const std::type_info& typeOfDecorator){return this;};
    virtual LabelImpl* removeDecoratorFrom(LabelImpl* label, const std::type_info& typeOfDecorator){return this;};
    virtual HelpText* getHelpText() const {return helpTextProvider.get();};
    virtual bool isHelpTextAvailable() const {return helpTextProvider != nullptr;};
    virtual ~LabelImpl() = default;
};