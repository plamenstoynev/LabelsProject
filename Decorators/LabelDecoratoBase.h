#pragma once
#include "../src/Label.h"
#include "../src/Transormation.hpp"

class LabelDecoratorBase  : public Label {
private:
    Label *label;
public:
    explicit LabelDecoratorBase(Label* label);
    std::string getText() const override;
    Label* removeDecorator(const std::type_info& typeOfDecorator) override;
    Label* removeDecoratorFrom(Label *label, const std::type_info &typeOfDecorator) override;
    ~LabelDecoratorBase() override = default;
};


class CapatilizeDecorator : public LabelDecoratorBase {
private:
    Capitalize capitalize;
public:
    explicit CapatilizeDecorator(Label* label);
    std::string getText() const override;
};

class LeftTrimDecorator : public LabelDecoratorBase {
private:
    LeftTrim leftTrim;
public:
    explicit LeftTrimDecorator(Label* label);
    std::string getText() const override;
};

class RightTrimDecorator: public LabelDecoratorBase {
private:
    RightTrim rightTrim;
public:
    explicit RightTrimDecorator(Label* label);
    std::string getText() const override;
};

class NormalizeSpacesDecorator : public LabelDecoratorBase {
private:
    NormalizeSpaces normalizeSpaces;
public:
    explicit  NormalizeSpacesDecorator(Label* label);
    std::string getText() const override;
};

class DecorateDecorator : public LabelDecoratorBase {
private:
    Decorate decorate;
public:
    explicit  DecorateDecorator(Label* label);
    std::string getText() const override;
};

class CensorDecorator : public LabelDecoratorBase {
private:
    Censor censor;
public:
    explicit CensorDecorator(Label* label, std::string word);
    std::string getText() const override;
};

class ReplaceDecorator : public LabelDecoratorBase {
private:
    Replace replace;
public:
    explicit  ReplaceDecorator(Label* label, std::string from, std::string to);
    std::string getText() const override;
};