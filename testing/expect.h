#pragma once

#include <iostream>
#include <string>
#include <sstream>

namespace Testing {
    template <class T>
    class Expect {
        std::string context;
        T actual;

        void printFailure(std::string hint = "");
        void printSuccess(std::string details = "");

    public:
        Expect(T actual, std::string context);
        void to(std::string description, T expected);
    };

    template <class T>
    Expect<T>::Expect(T actual, std::string context) {
        this->context = context;
        this->actual = actual;
    }

    template <class T>
    void Expect<T>::to(std::string description, T expected) {
        if (this->actual == expected) {
            this->printSuccess(description);
            return;
        }

        std::stringstream hint;
        hint << description << " ! Expected: " << expected << " Actual: " << this->actual;

        printFailure(hint.str());
    }

    template <class T>
    void Expect<T>::printFailure(std::string hint) {
        std::stringstream failureMessage;
        failureMessage << "✗ - " << this->context << " " << hint;
        std::cout << failureMessage.str() << "\n";
    }

    template <class T>
    void Expect<T>::printSuccess(std::string details) {
        std::stringstream successMessage;
        successMessage << "✓ - " << this-> context << " " << details;
        std::cout << successMessage.str() << "\n";
    }
}