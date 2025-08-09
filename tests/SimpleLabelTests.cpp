#include "catch2/catch_all.hpp"
#include "../src/SimpleLabel.h"


TEST_CASE("SimpleLabelConstructorGetsText") {
    REQUIRE_NOTHROW(SimpleLabel("Hello"));
    REQUIRE_THROWS(SimpleLabel(""));
}

TEST_CASE("GetTextReturnsTextSimpleLabel") {
    SimpleLabel label("Hello");
    REQUIRE(label.getText() == "Hello");
}

TEST_CASE("HelpTextInSimpleLabel"){
    SimpleLabel label("Hello");
    REQUIRE(label.isHelpTextAvailable() == false);
    REQUIRE(label.getHelpText() == nullptr);
}