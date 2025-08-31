#pragma once
#include <memory>
#include <string>
#include "Transormation.hpp"

namespace TransformationFactory {
    std::unique_ptr<Transformation> createCapitalize();
    std::unique_ptr<Transformation> createLeftTrim();
    std::unique_ptr<Transformation> createRightTrim();
    std::unique_ptr<Transformation> createNormalizeSpaces();
    std::unique_ptr<Transformation> createDecorate();
    std::unique_ptr<Transformation> createCensor(const std::string& word);
    std::unique_ptr<Transformation> createReplace(const std::string& from, const std::string& to);
}

