#pragma once
#include <string>

class LabelImpl {
public:
    virtual std::string getText() const = 0;
    virtual LabelImpl* removeDecorator(const std::type_info& typeOfDecorator){return this;};
    virtual LabelImpl* removeDecoratorFrom(LabelImpl* label, const std::type_info& typeOfDecorator){return this;};
    virtual ~LabelImpl() = default;
};