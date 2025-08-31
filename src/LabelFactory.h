#pragma once
#include <memory>
#include <string>
#include "LabelImp.h"
#include "RichLabel.h"

class LabelFactory {
public:
    static std::unique_ptr<LabelImpl> createSimple(const std::string& text);
    static std::unique_ptr<LabelImpl> createRich(const std::string& text, Color color, size_t fontSize, const std::string& font);
    static std::unique_ptr<LabelImpl> createProxy(const std::string& initialText = "");
};
