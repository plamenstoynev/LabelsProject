#include "catch2/catch_all.hpp"

#include "../src/LabelFactory.h"
#include "../Decorators/DecoratorFactory.h"
#include "../src/TransformationFactory.h"

TEST_CASE("DecoratorFactory_Chaining_LeftTrim_Normalize_Capitalize") {
    auto label = LabelFactory::createSimple("  hello   world");
    REQUIRE(label->getText() == "  hello   world");

    label = DecoratorFactory::addLeftTrim(std::move(label));
    REQUIRE(label->getText() == "hello   world");

    label = DecoratorFactory::addNormalizeSpaces(std::move(label));
    REQUIRE(label->getText() == "hello world");

    label = DecoratorFactory::addCapitalize(std::move(label));
    REQUIRE(label->getText() == "Hello world");
}

TEST_CASE("DecoratorFactory_Replace_Then_Censor") {
    auto label = LabelFactory::createSimple("foo badword foo");
    label = DecoratorFactory::addReplace(std::move(label), "foo", "bar");
    REQUIRE(label->getText() == "bar badword bar");

    label = DecoratorFactory::addCensor(std::move(label), "badword");
    REQUIRE(label->getText() == "bar ******* bar");
}

TEST_CASE("DecoratorFactory_Decorate_and_GenericTransformation") {
    auto label = LabelFactory::createSimple("surprise");
    label = DecoratorFactory::addDecorate(std::move(label));
    REQUIRE(label->getText() == "-={ surprise }=-");

    auto label2 = LabelFactory::createSimple("surprise");
    label2 = DecoratorFactory::addTransformation(std::move(label2), TransformationFactory::createDecorate());
    REQUIRE(label2->getText() == "-={ surprise }=-");
}

TEST_CASE("DecoratorFactory_ThrowsOnNulls") {
    std::unique_ptr<LabelImpl> nullLabel;
    REQUIRE_THROWS_AS(DecoratorFactory::addCapitalize(std::move(nullLabel)), std::invalid_argument);

    auto validLabel = LabelFactory::createSimple("ok");
    std::unique_ptr<Transformation> nullTrans;
    REQUIRE_THROWS_AS(DecoratorFactory::addTransformation(std::move(validLabel), std::move(nullTrans)), std::invalid_argument);
}

