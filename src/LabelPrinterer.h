#pragma once
#include "Label.h"

class LabelPrinter {
private:
    std::unique_ptr<Label> label;
public:
    LabelPrinter(std::unique_ptr<Label> label);
    void print() const;
};