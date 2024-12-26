#include "LabelDecoratoBase.h"

LabelDecoratorBase::LabelDecoratorBase(Label *label) : label(label) {
    if (!label) throw std::invalid_argument("Label cannot be null");
}

std::string LabelDecoratorBase::getText() const {
    return label->getText();
}

Label* LabelDecoratorBase::removeDecorator(const std::type_info &typeOfDecorator) {
    if (typeid(*this) == typeOfDecorator) {
        Label* result = label;
        label = nullptr;
        return result;
    }

    if (label)
        return label->removeDecorator(typeOfDecorator);

    return this;
}

Label *LabelDecoratorBase::removeDecoratorFrom(Label *label, const std::type_info &typeOfDecorator) {
    if (!label)
        return nullptr;

    return label->removeDecorator(typeOfDecorator);
}


CapatilizeDecorator::CapatilizeDecorator(Label *label) : LabelDecoratorBase(label), capitalize() {}

std::string CapatilizeDecorator::getText() const {
    std::string text = LabelDecoratorBase::getText();

    if (text.empty())
        throw std::invalid_argument("Text cannot be empty");

    return capitalize.applyFix(text);
}

LeftTrimDecorator::LeftTrimDecorator(Label *label) : LabelDecoratorBase(label), leftTrim() {}

std::string LeftTrimDecorator::getText() const {
    std::string text = LabelDecoratorBase::getText();

    if (text.empty())
        throw std::invalid_argument("Text cannot be empty");

    return leftTrim.applyFix(text);
}

RightTrimDecorator::RightTrimDecorator(Label *label) : LabelDecoratorBase(label), rightTrim() {}

std::string RightTrimDecorator::getText() const {
    std::string text = LabelDecoratorBase::getText();

    if (text.empty())
        throw std::invalid_argument("Text cannot be empty");

    return rightTrim.applyFix(text);
}

NormalizeSpacesDecorator::NormalizeSpacesDecorator(Label *label) : LabelDecoratorBase(label), normalizeSpaces() {}

std::string NormalizeSpacesDecorator::getText() const {
    std::string text = LabelDecoratorBase::getText();

    if (text.empty())
        throw std::invalid_argument("Text cannot be empty");

    return normalizeSpaces.applyFix(text);
}

DecorateDecorator::DecorateDecorator(Label *label) : LabelDecoratorBase(label), decorate() {}

std::string DecorateDecorator::getText() const {
    std::string text = LabelDecoratorBase::getText();

    if (text.empty())
        throw std::invalid_argument("Text cannot be empty");

    return decorate.applyFix(text);
}

CensorDecorator::CensorDecorator(Label *label, std::string word) : LabelDecoratorBase(label), censor(word) {}

std::string CensorDecorator::getText() const {
    std::string text = LabelDecoratorBase::getText();

    if (text.empty())
        throw std::invalid_argument("Text cannot be empty");

    return censor.applyFix(text);
}

ReplaceDecorator::ReplaceDecorator(Label *label, std::string word, std::string replacement) : LabelDecoratorBase(label), replace(word, replacement) {}

std::string ReplaceDecorator::getText() const {
    std::string text = LabelDecoratorBase::getText();

    if (text.empty())
        throw std::invalid_argument("Text cannot be empty");

    return replace.applyFix(text);
}