#include "catch2/catch_all.hpp"
#include "../src/RichLabel.h"

TEST_CASE("RichLabelConstructorGetsText") {
    REQUIRE_NOTHROW(RichLabel("Hello", RED, 12, "Arial"));
    REQUIRE_THROWS(RichLabel("", RED, 12, "Arial"));
    REQUIRE_THROWS(RichLabel("Hello", RED, 0, "Arial"));
    REQUIRE_THROWS(RichLabel("Hello", RED, 12, ""));
}

TEST_CASE("GetTextReturnsTextRichLabel") {
    RichLabel label("Hello", RED, 12, "Arial");
    REQUIRE(label.getText() == "Hello");
}

TEST_CASE("RichLabelHelpText"){
    RichLabel label("Hello", RED, 12, "Arial");
    REQUIRE(label.isHelpTextAvailable() == false);
    REQUIRE(label.getHelpText() == nullptr);
}

