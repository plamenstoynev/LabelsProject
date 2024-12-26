#include "LabelPrinterer.h"
#include <iostream>


LabelPrinter::LabelPrinter(std::unique_ptr<Label> label) : label(std::move(label)) {}

void LabelPrinter::print() const {
    std::cout << label->getText() << std::endl;
}