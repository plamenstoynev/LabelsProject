#include "LabelPrinterer.h"
#include <iostream>
#include "LabelImp.h"
#include "../Bridge/HelpTextProvider.h"


LabelPrinter::LabelPrinter(std::unique_ptr<Label> label) : label(std::move(label)) {}

void LabelPrinter::print() const {
    std::cout << label->getText() << std::endl;
}

void LabelPrinter::printWithHelpText() {
    std::cout << label->getText() << " " << label->getHelpTextProvider()->getHelpText() << std::endl;
}
