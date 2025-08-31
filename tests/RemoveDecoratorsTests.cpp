#include "Transormation.hpp"
#include "../Decorators/CyclingTransformationsDecorator.h"
#include "catch2/catch_all.hpp"
#include "../src/SimpleLabel.h"
#include "../Decorators/LabelDecoratoBase.h"

TEST_CASE("TestRemoveDecorator") {
    std::vector<std::unique_ptr<Transformation>> transformations;
    transformations.push_back(std::make_unique<Capitalize>());
    transformations.push_back(std::make_unique<LeftTrim>());
    transformations.push_back(std::make_unique<RightTrim>());

    LabelImpl* label = new SimpleLabel("hello");

    CyclingTransformationsDecorator decorator(label, std::move(transformations));
    REQUIRE_NOTHROW(decorator.removeDecorator(typeid(Capitalize)));
}