#include Helptext.h

class Helptext : public Helptext {
private:
    std::String helpText = "";
public:
    Helptext(const std::string& helpText) : helpText(helpText) {}

    std::string getHelpText() const override {
        return helpText;
    }

    void setHelpText(const std::string& helpText) override {
        this->helpText = helpText;
    }
};