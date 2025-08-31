#include "LabelDecoratoBase.h"

LabelDecoratorBase::LabelDecoratorBase(LabelImpl *label) : label(label) {
    if (!label) throw std::invalid_argument("Label cannot be null");
}

LabelDecoratorBase::~LabelDecoratorBase() {
    // own the inner label and delete it (if still present)
    if (label) {
        delete label;
        label = nullptr;
    }
}

std::string LabelDecoratorBase::getText() const {
    return label->getText();
}

LabelImpl* LabelDecoratorBase::removeDecorator(const std::type_info &typeOfDecorator) {
    if (typeid(*this) == typeOfDecorator) {
        LabelImpl* result = label;
        label = nullptr;
        return result;
    }

    if (label)
        return label->removeDecorator(typeOfDecorator);

    return this;
}

LabelImpl *LabelDecoratorBase::removeDecoratorFrom(LabelImpl *label, const std::type_info &typeOfDecorator) {
    if (!label)
        return nullptr;

    return label->removeDecorator(typeOfDecorator);
}


CapatilizeDecorator::CapatilizeDecorator(LabelImpl *label) : LabelDecoratorBase(label), capitalize() {}

std::string CapatilizeDecorator::getText() const {
    std::string text = LabelDecoratorBase::getText();

    if (text.empty())
        throw std::invalid_argument("Text cannot be empty");

    return capitalize.applyFix(text);
}

LeftTrimDecorator::LeftTrimDecorator(LabelImpl *label) : LabelDecoratorBase(label), leftTrim() {}

std::string LeftTrimDecorator::getText() const {
    std::string text = LabelDecoratorBase::getText();

    if (text.empty())
        throw std::invalid_argument("Text cannot be empty");

    return leftTrim.applyFix(text);
}

RightTrimDecorator::RightTrimDecorator(LabelImpl *label) : LabelDecoratorBase(label), rightTrim() {}

std::string RightTrimDecorator::getText() const {
    std::string text = LabelDecoratorBase::getText();

    if (text.empty())
        throw std::invalid_argument("Text cannot be empty");

    return rightTrim.applyFix(text);
}

NormalizeSpacesDecorator::NormalizeSpacesDecorator(LabelImpl *label) : LabelDecoratorBase(label), normalizeSpaces() {}

std::string NormalizeSpacesDecorator::getText() const {
    std::string text = LabelDecoratorBase::getText();

    if (text.empty())
        throw std::invalid_argument("Text cannot be empty");

    return normalizeSpaces.applyFix(text);
}

DecorateDecorator::DecorateDecorator(LabelImpl *label) : LabelDecoratorBase(label), decorate() {}

std::string DecorateDecorator::getText() const {
    std::string text = LabelDecoratorBase::getText();

    if (text.empty())
        throw std::invalid_argument("Text cannot be empty");

    return decorate.applyFix(text);
}

CensorDecorator::CensorDecorator(LabelImpl *label, const std::string &word) : LabelDecoratorBase(label), censor(word) {}

std::string CensorDecorator::getText() const {
    std::string text = LabelDecoratorBase::getText();

    if (text.empty())
        throw std::invalid_argument("Text cannot be empty");

    return censor.applyFix(text);
}

ReplaceDecorator::ReplaceDecorator(LabelImpl *label, const std::string &word, const std::string &replacement) : LabelDecoratorBase(label), replace(word, replacement) {}

std::string ReplaceDecorator::getText() const {
    std::string text = LabelDecoratorBase::getText();

    if (text.empty())
        throw std::invalid_argument("Text cannot be empty");

    return replace.applyFix(text);
}