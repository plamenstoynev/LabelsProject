#include "ProxyLabel.h"
#include <iostream>

std::string ProxyLabel::getText() const {
    if (!isLoaded) {
        std::cout << "Enter text: ";
        std::getline(std::cin, text);
        isLoaded = true;
    }
    return text;
}

void ProxyLabel::setText(const std::string &text) {
    this->text = text;
    isLoaded = true;
    lastAccessUpdate();
}

void ProxyLabel::lastAccessUpdate() const {
    lastAccess = std::chrono::steady_clock::now();
}

void ProxyLabel::checkTimeout() const {
    if (isLoaded) {
        auto timeNow = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(timeNow - lastAccess).count();

        if (elapsed > timeout) {
            std::cout << "Do you want update text ? (y/n) " << std::endl;
            char choice;
            std::cin >> choice;
            std::cin.ignore();

            if (choice == 'y' || choice == 'Y') {
                std::cout << "Enter text: ";
                std::getline(std::cin, text);
            }

            lastAccessUpdate();
        }
    }
}

