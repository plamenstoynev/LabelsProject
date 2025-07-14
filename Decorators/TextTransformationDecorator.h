#pragma once
#include "../Decorators/LabelDecoratoBase.h"
#include "../src/Transormation.hpp"

class TextTransformationDecorator : public LabelDecoratorBase{
private:
    std::unique_ptr<Transformation> transformation;
public:
    TextTransformationDecorator(LabelImpl* label,std::unique_ptr<Transformation>transformation);
    std::string getText() const override;
};