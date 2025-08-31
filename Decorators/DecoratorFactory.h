#pragma once
#include <memory>
#include <string>
#include "../src/LabelImp.h"
#include "LabelDecoratoBase.h"
#include "../src/Transormation.hpp"

namespace DecoratorFactory {
    std::unique_ptr<LabelImpl> addCapitalize(std::unique_ptr<LabelImpl> label);
    std::unique_ptr<LabelImpl> addLeftTrim(std::unique_ptr<LabelImpl> label);
    std::unique_ptr<LabelImpl> addRightTrim(std::unique_ptr<LabelImpl> label);
    std::unique_ptr<LabelImpl> addNormalizeSpaces(std::unique_ptr<LabelImpl> label);
    std::unique_ptr<LabelImpl> addDecorate(std::unique_ptr<LabelImpl> label);
    std::unique_ptr<LabelImpl> addCensor(std::unique_ptr<LabelImpl> label, const std::string& word);
    std::unique_ptr<LabelImpl> addReplace(std::unique_ptr<LabelImpl> label, const std::string& from, const std::string& to);


    std::unique_ptr<LabelImpl> addTransformation(std::unique_ptr<LabelImpl> label, std::unique_ptr<Transformation> transformation);
}

