#include "DecoratorFactory.h"
#include "TextTransformationDecorator.h"
#include <stdexcept>

namespace DecoratorFactory {

std::unique_ptr<LabelImpl> addCapitalize(std::unique_ptr<LabelImpl> label) {
    if (!label) throw std::invalid_argument("Label cannot be null");
    return std::unique_ptr<LabelImpl>(new CapatilizeDecorator(label.release()));
}

std::unique_ptr<LabelImpl> addLeftTrim(std::unique_ptr<LabelImpl> label) {
    if (!label) throw std::invalid_argument("Label cannot be null");
    return std::unique_ptr<LabelImpl>(new LeftTrimDecorator(label.release()));
}

std::unique_ptr<LabelImpl> addRightTrim(std::unique_ptr<LabelImpl> label) {
    if (!label) throw std::invalid_argument("Label cannot be null");
    return std::unique_ptr<LabelImpl>(new RightTrimDecorator(label.release()));
}

std::unique_ptr<LabelImpl> addNormalizeSpaces(std::unique_ptr<LabelImpl> label) {
    if (!label) throw std::invalid_argument("Label cannot be null");
    return std::unique_ptr<LabelImpl>(new NormalizeSpacesDecorator(label.release()));
}

std::unique_ptr<LabelImpl> addDecorate(std::unique_ptr<LabelImpl> label) {
    if (!label) throw std::invalid_argument("Label cannot be null");
    return std::unique_ptr<LabelImpl>(new DecorateDecorator(label.release()));
}

std::unique_ptr<LabelImpl> addCensor(std::unique_ptr<LabelImpl> label, const std::string &word) {
    if (!label) throw std::invalid_argument("Label cannot be null");
    return std::unique_ptr<LabelImpl>(new CensorDecorator(label.release(), word));
}

std::unique_ptr<LabelImpl> addReplace(std::unique_ptr<LabelImpl> label, const std::string &from, const std::string &to) {
    if (!label) throw std::invalid_argument("Label cannot be null");
    return std::unique_ptr<LabelImpl>(new ReplaceDecorator(label.release(), from, to));
}

std::unique_ptr<LabelImpl> addTransformation(std::unique_ptr<LabelImpl> label, std::unique_ptr<Transformation> transformation) {
    if (!label) throw std::invalid_argument("Label cannot be null");
    if (!transformation) throw std::invalid_argument("Transformation cannot be null");
    return std::unique_ptr<LabelImpl>(new TextTransformationDecorator(label.release(), std::move(transformation)));
}

}

