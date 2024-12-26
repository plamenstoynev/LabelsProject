#include "TextTransformationDecorator.h"

TextTransformationDecorator::TextTransformationDecorator(Label *label, std::unique_ptr<Transformation> transformation_) : LabelDecoratorBase(label), transformation(std::move(transformation_)) {
    if (!transformation) throw std::invalid_argument("Transformation cannot be null");
}

std::string TextTransformationDecorator::getText() const {
    return transformation->applyFix(LabelDecoratorBase::getText());
}
