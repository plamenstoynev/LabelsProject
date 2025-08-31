#pragma once
#include "../src/LabelImp.h"
#include "../src/Transormation.hpp"

class LabelDecoratorBase  : public LabelImpl {
private:
    LabelImpl *label;
public:
    explicit LabelDecoratorBase(LabelImpl* label);
    std::string getText() const override;
    LabelImpl* removeDecorator(const std::type_info& typeOfDecorator) override;
    LabelImpl* removeDecoratorFrom(LabelImpl* label, const std::type_info& typeOfDecorator) override;
    ~LabelDecoratorBase() override;
};


class CapatilizeDecorator : public LabelDecoratorBase {
private:
    Capitalize capitalize;
public:
    explicit CapatilizeDecorator(LabelImpl* label);
    std::string getText() const override;
};

class LeftTrimDecorator : public LabelDecoratorBase {
private:
    LeftTrim leftTrim;
public:
    explicit LeftTrimDecorator(LabelImpl* label);
    std::string getText() const override;
};

class RightTrimDecorator: public LabelDecoratorBase {
private:
    RightTrim rightTrim;
public:
    explicit RightTrimDecorator(LabelImpl* label);
    std::string getText() const override;
};

class NormalizeSpacesDecorator : public LabelDecoratorBase {
private:
    NormalizeSpaces normalizeSpaces;
public:
    explicit  NormalizeSpacesDecorator(LabelImpl* label);
    std::string getText() const override;
};

class DecorateDecorator : public LabelDecoratorBase {
private:
    Decorate decorate;
public:
    explicit  DecorateDecorator(LabelImpl* label);
    std::string getText() const override;
};

class CensorDecorator : public LabelDecoratorBase {
private:
    Censor censor;
public:
    explicit CensorDecorator(LabelImpl* label, const std::string& word);
    std::string getText() const override;
};

class ReplaceDecorator : public LabelDecoratorBase {
private:
    Replace replace;
public:
    explicit ReplaceDecorator(LabelImpl* label, const std::string& from, const std::string& to);
    std::string getText() const override;
};