#include "catch2/catch_all.hpp"
#include "../Composite/CompositeTransformation.h"

TEST_CASE("AddTransformation") {
    std::unique_ptr<Transformation> capatilize = std::make_unique<Capitalize>();
    std::unique_ptr<Transformation> leftTrim = std::make_unique<LeftTrim>();
    std::unique_ptr<Transformation> rightTrim = std::make_unique<RightTrim>();
    CompositeTransformation compositeTransformation;

    REQUIRE_NOTHROW(compositeTransformation.addTransformation(std::move(capatilize)));
    REQUIRE_NOTHROW(compositeTransformation.addTransformation(std::move(leftTrim)));
    REQUIRE_NOTHROW(compositeTransformation.addTransformation(std::move(rightTrim)));
}

TEST_CASE("ApplyFix") {
    std::unique_ptr<Transformation> capitalize = std::make_unique<Capitalize>();
    std::unique_ptr<Transformation> leftTrim = std::make_unique<LeftTrim>();
    std::unique_ptr<Transformation> rightTrim = std::make_unique<RightTrim>();
    CompositeTransformation compositeTransformation;
    compositeTransformation.addTransformation(std::move(capitalize));
    compositeTransformation.addTransformation(std::move(leftTrim));
    compositeTransformation.addTransformation(std::move(rightTrim));

    REQUIRE(compositeTransformation.applyFix(" hello ") == "Hello");
}