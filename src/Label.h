#pragma once
#include <string>
class Label {
public:
    virtual std::string getText() const = 0;
    virtual Label* removeDecorator(const std::type_info& typeOfDecorator){return this;};
    virtual Label* removeDecoratorFrom(Label* label, const std::type_info& typeOfDecorator){return this;};
    virtual ~Label() = default;
};