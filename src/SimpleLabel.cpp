#include "SimpleLabel.h"

SimpleLabel::SimpleLabel(const std::string &text) : text(text) {
    if (text.empty()) throw std::invalid_argument("Text cannot be empty");
}

std::string SimpleLabel::getText() const {
    return text;
}