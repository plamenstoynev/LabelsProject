#pragma once
#include <string>
#include "Label.h"

class ProxyLabel : public Label {
private:
    mutable std::string text;
    mutable bool isLoaded = false;
    mutable std::chrono::steady_clock::time_point lastAccess;
    size_t timeout = 0;

    void lastAccessUpdate() const;
public:
    std::string getText() const override;
    void setText(const std::string& text);
    void checkTimeout() const;
};