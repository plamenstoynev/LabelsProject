#include "LabelPrinterer.h"
#include <iostream>
#include "LabelImp.h"


LabelPrinter::LabelPrinter(std::unique_ptr<LabelImpl> label) : label(std::move(label)) {}

void LabelPrinter::print() const {
    std::cout << label->getText() << std::endl;
}