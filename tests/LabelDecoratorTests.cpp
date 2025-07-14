#include "../Decorators/CyclingTransformationsDecorator.h"
#include "catch2/catch_all.hpp"
#include "../Decorators/LabelDecoratoBase.h"
#include "../Decorators/RandomTransformationDecorator.h"
#include "../Decorators/TextTransformationDecorator.h"
#include "../src/SimpleLabel.h"
#include "../src/RichLabel.h"

TEST_CASE("LabelDecoratorBaseConstructorGetsLabel") {
    REQUIRE_NOTHROW(LabelDecoratorBase(new SimpleLabel("Hello")));
    REQUIRE_THROWS(LabelDecoratorBase(nullptr));
}

TEST_CASE("GetTextReturnsTextFromLabel") {
    LabelImpl *label = new SimpleLabel("Hello");
    LabelDecoratorBase decorator(label);
    REQUIRE(decorator.getText() == "Hello");
    delete label;
}

TEST_CASE("RandomTransformationConstructor") {
    std::vector<std::unique_ptr<Transformation>> transformations;
    transformations.push_back(std::make_unique<Capitalize>());
    transformations.push_back(std::make_unique<LeftTrim>());
    transformations.push_back(std::make_unique<RightTrim>());

    REQUIRE_NOTHROW(RandomTransformationDecorator(new SimpleLabel("Hello"), std::move(transformations)));

    std::vector<std::unique_ptr<Transformation>> emptyTransformations;
    REQUIRE_THROWS(RandomTransformationDecorator(new SimpleLabel("Hello"), std::move(emptyTransformations)));
}

TEST_CASE("GetTextReturnsTextFromRandomTransformationDecorator") {
    std::vector<std::unique_ptr<Transformation>> transformations;
    transformations.push_back(std::make_unique<Capitalize>());
    transformations.push_back(std::make_unique<LeftTrim>());
    transformations.push_back(std::make_unique<RightTrim>());

    LabelImpl *label = new SimpleLabel("hello");
    RandomTransformationDecorator decorator(label, std::move(transformations));
    REQUIRE((decorator.getText() == "Hello" ||
            decorator.getText() == "hello" ||
            decorator.getText() == "Hello "));
    delete label;
}

TEST_CASE("TextTransformationConstructor") {
    std::unique_ptr<Transformation> transformation = std::make_unique<Capitalize>();
    REQUIRE_NOTHROW(TextTransformationDecorator(new SimpleLabel("Hello"), std::move(transformation)));
    REQUIRE_THROWS(TextTransformationDecorator(nullptr, std::move(transformation)));
    REQUIRE_THROWS(TextTransformationDecorator(new SimpleLabel("Hello"), nullptr));
}

TEST_CASE("GetTextReturnsTextFromTextTransformationDecorator") {
    std::unique_ptr<Transformation> transformation = std::make_unique<Capitalize>();
    LabelImpl *label = new RichLabel("hello", RED, 12, "Arial");
    TextTransformationDecorator decorator(label, std::move(transformation));
    REQUIRE(decorator.getText() == "Hello");
    delete label;
}

TEST_CASE("CyclingTransformationsDecoratorConstructor") {
    std::vector<std::unique_ptr<Transformation>> transformations;
    transformations.push_back(std::make_unique<Capitalize>());
    transformations.push_back(std::make_unique<LeftTrim>());
    transformations.push_back(std::make_unique<RightTrim>());

    REQUIRE_NOTHROW(CyclingTransformationsDecorator(new SimpleLabel("Hello"), std::move(transformations)));

    std::vector<std::unique_ptr<Transformation>> emptyTransformations;
    REQUIRE_THROWS(CyclingTransformationsDecorator(new RichLabel("Hello", RED, 12, "Arial"), std::move(emptyTransformations)));
}

TEST_CASE("GetTextReturnsTextFromCyclingTransformationsDecorator") {
    std::vector<std::unique_ptr<Transformation>> transformations;
    transformations.push_back(std::make_unique<Capitalize>());

    LabelImpl *label = new SimpleLabel("hello");
    CyclingTransformationsDecorator decorator(label, std::move(transformations));
    REQUIRE(decorator.getText() == "Hello");
    delete label;
}