#include "catch2/catch_all.hpp"

#include "../src/LabelFactory.h"
#include "../src/SimpleLabel.h"
#include "../src/RichLabel.h"
#include "../src/ProxyLabel.h"

TEST_CASE("FactoryCreatesSimpleLabel") {
    auto label = LabelFactory::createSimple("simple text");
    REQUIRE(label != nullptr);
    REQUIRE(label->getText() == "simple text");
}

TEST_CASE("FactoryCreatesRichLabel") {
    auto label = LabelFactory::createRich("rich text", RED, 14, "Arial");
    REQUIRE(label != nullptr);

    auto rich = dynamic_cast<RichLabel*>(label.get());
    REQUIRE(rich != nullptr);
    REQUIRE(rich->getText() == "rich text");
}

TEST_CASE("FactoryCreatesProxyLabelWithInitialText") {
    auto label = LabelFactory::createProxy("initial text");
    REQUIRE(label != nullptr);

    auto proxy = dynamic_cast<ProxyLabel*>(label.get());
    REQUIRE(proxy != nullptr);
    REQUIRE(proxy->getText() == "initial text");
}

TEST_CASE("FactoryCreatesEmptyProxyLabelAndAllowsSettingText") {
    auto label = LabelFactory::createProxy();
    REQUIRE(label != nullptr);

    auto proxy = dynamic_cast<ProxyLabel*>(label.get());
    REQUIRE(proxy != nullptr);

    proxy->setText("now set");
    REQUIRE(proxy->getText() == "now set");
}

