#pragma once
#include "LabelImp.h"

class SimpleLabel : public LabelImpl {
private:
    std::string text;

public:
    explicit SimpleLabel(const std::string& text);
    std::string getText() const override;
    ~SimpleLabel() override = default;
};
