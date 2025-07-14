#include "CyclingTransformationsDecorator.h"

CyclingTransformationsDecorator::CyclingTransformationsDecorator(LabelImpl *label, std::vector<std::unique_ptr<Transformation>>&& transformations_) : LabelDecoratorBase(label), transformations(std::move(transformations_)) {
    if (this->transformations.empty()) throw std::invalid_argument("Transformations cannot be empty");
}

std::string CyclingTransformationsDecorator::getText() const {
    if (currentTransformationIndex >= transformations.size()) currentTransformationIndex = 0;

    const std::string& transformText = transformations[currentTransformationIndex]->applyFix(LabelDecoratorBase::getText());
    currentTransformationIndex = (currentTransformationIndex + 1) % transformations.size();

    return transformText;
}