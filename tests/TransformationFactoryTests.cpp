#include "catch2/catch_all.hpp"

#include "../src/TransformationFactory.h"
#include "../src/Transormation.hpp"

TEST_CASE("TransformationFactory_Capitalize") {
    auto t = TransformationFactory::createCapitalize();
    REQUIRE(t);
    REQUIRE(t->applyFix("hello") == "Hello");
    REQUIRE(t->applyFix("123abc") == "123Abc");
}

TEST_CASE("TransformationFactory_Trims") {
    auto l = TransformationFactory::createLeftTrim();
    REQUIRE(l);
    REQUIRE(l->applyFix("  a b") == "a b");

    auto r = TransformationFactory::createRightTrim();
    REQUIRE(r);
    REQUIRE(r->applyFix("a b  ") == "a b");
}

TEST_CASE("TransformationFactory_NormalizeSpaces_And_Decorate") {
    auto n = TransformationFactory::createNormalizeSpaces();
    REQUIRE(n);
    REQUIRE(n->applyFix("a   b\n\t c") == "a b c");

    auto d = TransformationFactory::createDecorate();
    REQUIRE(d);
    REQUIRE(d->applyFix("surprise") == "-={ surprise }=-");
}

TEST_CASE("TransformationFactory_Censor_And_Replace") {
    auto c = TransformationFactory::createCensor("bad");
    REQUIRE(c);
    REQUIRE(c->applyFix("bad and very bad") == "*** and very ***");

    auto r = TransformationFactory::createReplace("foo", "bar");
    REQUIRE(r);
    REQUIRE(r->applyFix("foo foo foo") == "bar bar bar");
}

