#include "../Composite/CompositeTransformation.h"

void CompositeTransformation::addTransformation(std::unique_ptr<Transformation> transformation) {
    transformations.push_back(std::move(transformation));
}

std::string CompositeTransformation::applyFix(const std::string &text) const {
    std::string result = text;

    for (const auto &transformation : transformations)
        result = transformation->applyFix(result);

    return result;
}


