#include "RichLabel.h"

RichLabel::RichLabel(const std::string &text, Color color, size_t sizeOfFont, const std::string &font) : text(text), color(color), sizeOfFont(sizeOfFont), font(font) {
    if (text.empty()) throw std::invalid_argument("Text cannot be empty");
    if (sizeOfFont == 0) throw std::invalid_argument("Size of font cannot be 0");
    if (font.empty()) throw std::invalid_argument("Font cannot be empty");
}

std::string colorToString(Color color) {
    switch (color) {
        case RED:
            return "RED";
        case GREEN:
            return "GREEN";
        case BLUE:
            return "BLUE";
    }
    return "";
}

std::string RichLabel::getText() const {
    return  text;
}