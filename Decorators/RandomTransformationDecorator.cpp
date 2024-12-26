#include "RandomTransformationDecorator.h"

RandomTransformationDecorator::RandomTransformationDecorator(Label *label,  std::vector<std::unique_ptr<Transformation>> transformations_) : LabelDecoratorBase(label), transformations(std::move(transformations_)) {
    if (transformations.empty()) throw std::invalid_argument("Transformation cannot be empty");
}

std::string RandomTransformationDecorator::getText() const {
    return transformations[rand() % transformations.size()]->applyFix(LabelDecoratorBase::getText());
}
