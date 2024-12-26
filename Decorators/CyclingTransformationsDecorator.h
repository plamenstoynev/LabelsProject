#pragma once
#include "../Decorators/LabelDecoratoBase.h"
#include "../src/Transormation.hpp"

class CyclingTransformationsDecorator : public LabelDecoratorBase {
private:
    std::vector<std::unique_ptr<Transformation>> transformations;
    mutable size_t currentTransformationIndex = 0;
public:
    CyclingTransformationsDecorator(Label *label, std::vector<std::unique_ptr<Transformation>>&& transformations);
    std::string getText() const override;
};