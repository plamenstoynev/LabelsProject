#include "LabelPrinterer.h"
#include <iostream>
#include "LabelImp.h"


LabelPrinter::LabelPrinter(std::unique_ptr<LabelImpl> label) : label(std::move(label)) {}

void LabelPrinter::print() const {
    std::cout << label->getText() << std::endl;
}

void LabelPrinter::printWithHelpText() {
    if (label->isHelpTextAvailable())
        std::cout << label->getText() << " " << label->getHelpText()->getHelpText() << std::endl;
    else
        throw std::runtime_error("Help text is not available for this label");
}
