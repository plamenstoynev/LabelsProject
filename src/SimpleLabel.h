#pragma once
#include "Label.h"

class SimpleLabel : public Label {
private:
    std::string text;

public:
    explicit SimpleLabel(const std::string& text);
    std::string getText() const override;
    ~SimpleLabel() override = default;
};
