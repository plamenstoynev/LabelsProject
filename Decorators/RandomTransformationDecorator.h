#pragma once
#include "../Decorators/LabelDecoratoBase.h"
#include "../src/Transormation.hpp"


class RandomTransformationDecorator : LabelDecoratorBase {
private:
    std::vector<std::unique_ptr<Transformation>> transformations;
public:
    RandomTransformationDecorator(LabelImpl *label,  std::vector<std::unique_ptr<Transformation>> transformations);
    std::string getText() const override;
};