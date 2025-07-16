#pragma once
#include <string>

class LabelImpl;
class HelpTextProvider;

class Label {
protected:
    LabelImpl* impl;
    HelpTextProvider* helpTextProvider;
public:
    Label(LabelImpl* impl, HelpTextProvider* helpTextProvider = nullptr);
    virtual std::string getText() const;
    virtual HelpTextProvider* getHelpTextProvider() const;
    virtual void setText(const std::string& text);
    virtual bool checkTimeout() const;
    virtual bool isHelpTextAvailable() const;
    virtual ~Label() = default;
};