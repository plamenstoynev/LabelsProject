#pragma once
#include "Label.h"

class LabelPrinter {
private:
    std::unique_ptr<LabelImpl> label;
public:
    LabelPrinter(std::unique_ptr<LabelImpl> label);
    void print() const;
};