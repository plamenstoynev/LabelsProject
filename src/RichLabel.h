#pragma once
#include "Label.h"

enum Color {
    RED,
    GREEN,
    BLUE
};

class RichLabel : public Label {
private:
    std::string text;
    Color color;
    size_t sizeOfFont;
    std::string font;
public:
    RichLabel (const std::string& text, Color color, size_t sizeOfFont, const std::string& font);
    std::string getText() const override;
    ~RichLabel() override = default;
};