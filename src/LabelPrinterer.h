#pragma once
#include "LabelImp.h"
#include <memory>

class LabelPrinter {
private:
    std::unique_ptr<LabelImpl> label;
public:
    LabelPrinter(std::unique_ptr<LabelImpl> label);
    void print() const;
    void printWithHelpText();
};