#pragma once
#include <vector>
#include <string>
#include "../src/Transormation.hpp"

class CompositeTransformation : public Transformation {
private:
    std::vector<std::unique_ptr<Transformation>> transformations;
public:
    CompositeTransformation() = default;

    void addTransformation(std::unique_ptr<Transformation> transformation);
    std::string applyFix(const std::string &text) const override;

    ~CompositeTransformation() override = default;
};