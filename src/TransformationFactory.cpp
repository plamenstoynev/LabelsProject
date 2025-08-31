#include "TransformationFactory.h"

namespace TransformationFactory {

std::unique_ptr<Transformation> createCapitalize() {
    return std::make_unique<Capitalize>();
}

std::unique_ptr<Transformation> createLeftTrim() {
    return std::make_unique<LeftTrim>();
}

std::unique_ptr<Transformation> createRightTrim() {
    return std::make_unique<RightTrim>();
}

std::unique_ptr<Transformation> createNormalizeSpaces() {
    return std::make_unique<NormalizeSpaces>();
}

std::unique_ptr<Transformation> createDecorate() {
    return std::make_unique<Decorate>();
}

std::unique_ptr<Transformation> createCensor(const std::string &word) {
    return std::make_unique<Censor>(word);
}

std::unique_ptr<Transformation> createReplace(const std::string &from, const std::string &to) {
    return std::make_unique<Replace>(from, to);
}

} // namespace TransformationFactory

