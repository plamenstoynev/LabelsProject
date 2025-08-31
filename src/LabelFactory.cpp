#include "LabelFactory.h"
#include "SimpleLabel.h"
#include "ProxyLabel.h"
#include <memory>
#include "RichLabel.h"

std::unique_ptr<LabelImpl> LabelFactory::createSimple(const std::string &text) {
    return std::make_unique<SimpleLabel>(text);
}

std::unique_ptr<LabelImpl> LabelFactory::createRich(const std::string &text, Color color, size_t fontSize, const std::string &font) {
    return std::make_unique<RichLabel>(text, color, fontSize, font);
}

std::unique_ptr<LabelImpl> LabelFactory::createProxy(const std::string &initialText) {
    auto p = std::make_unique<ProxyLabel>();
    if (!initialText.empty()) {
        p->setText(initialText);
    }
    return p;
}

