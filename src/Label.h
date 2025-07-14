#pragma once
#include "Label.h"
#include <string>
class LabelImpl;

class Label {
protected:
    LabelImpl* impl;
public:
    Label(LabelImpl* impl);
    virtual std::string getText() const;
    virtual void setText(const std::string& text);
    virtual void checkTimeout() const;
    virtual ~Label() = default;
};