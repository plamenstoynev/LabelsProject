#include "catch2/catch_all.hpp"
#include <thread>
#include <chrono>
#include<iostream>
#include "../src/ProxyLabel.h"

TEST_CASE("ProxyLabelConstructorGetsText") {
    REQUIRE_NOTHROW(ProxyLabel());
}

TEST_CASE("ProxyLabelSetText") {
    ProxyLabel label;
    label.setText("Hello");
    REQUIRE(label.getText() == "Hello");
}

TEST_CASE("ProxyLabelTimeoutText") {
    ProxyLabel label;
    label.setText("Hello");

    std::this_thread::sleep_for(std::chrono::seconds(1)); // simulate 1 seconds passed get from AI

    std::istringstream stream("y\nUpdated after timeout\n");
    std::cin.rdbuf(stream.rdbuf());

    label.checkTimeout();

    REQUIRE(label.getText() == "Updated after timeout");
}

TEST_CASE("ProxyLabelNoTimeoutText") {
    ProxyLabel label;
    label.setText("Hello");

    //std::this_thread::sleep_for(std::chrono::seconds(1)); // simulate 1 seconds passed get from AI

    std::istringstream stream("n\n");
    std::cin.rdbuf(stream.rdbuf());

    label.checkTimeout();

    REQUIRE(label.getText() == "Hello");
}

