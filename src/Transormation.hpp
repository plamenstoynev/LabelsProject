#pragma once
#include <locale>
#include <regex>
#include <utility>

class Transformation {
public:
    virtual std::string applyFix(const std::string &text) const = 0;
    virtual ~Transformation() = default;
};

class Capitalize : public Transformation {
public:
    std::string applyFix(const std::string &text) const override {
        if (text.empty()) return text;

        std::string result = text;
        size_t index = 0;
        while (!isalpha(result[index])) {
            index++;
        }

        result[index] = std::toupper(result[index]);

        return result;
    }
};

class LeftTrim : public Transformation {
public:
    std::string applyFix(const std::string &text) const override {
        std::string result = text;
        result.erase(0, result.find_first_not_of(' '));
        return result;
    }
};

class RightTrim : public Transformation {
public:
    std::string applyFix(const std::string &text) const override {
        std::string result = text;
        result.erase(result.find_last_not_of(' ') + 1);
        return result;
    }
};

class NormalizeSpaces : public Transformation {
public:
    std::string applyFix(const std::string &text) const override {
        return std::regex_replace(text, std::regex("\\s+"), " ");
    }
};

class Decorate : public Transformation {
public:
    std::string applyFix(const std::string &text) const override {
        return "-={ " + text + " }=-";
    }
};

class Censor : public Transformation {
private:
    std::string word;
public:
    explicit Censor(std::string word) : word(std::move(word)) {}
    std::string applyFix(const std::string &text) const override {
        std::string result = text;
        size_t index;

        while (index = result.find(word), index !=std::string::npos)
            result.replace(index, word.length(), std::string(word.length(), '*'));

        return result;
    }
};

class Replace : public Transformation {
private:
    std::string from, to;
public:
    Replace(std::string from, std::string to) : from(std::move(from)), to(std::move(to)) {}
    std::string applyFix(const std::string &text) const override {
        std::string result = text;
        size_t index;
        while (index = result.find(from), index != std::string::npos)
            result.replace(index, from.length(), to);

        return result;
    }
};