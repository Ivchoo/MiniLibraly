#pragma once
#include <string>

class Author {
private:
    std::string name;
    int birthYear;

public:
    Author() : name("Unknown"), birthYear(1900) {}
    explicit Author(const std::string& n, int y) : name(n) {
        setBirthYear(y);
    }

    std::string to_string() const {
        return name + " (" + std::to_string(birthYear) + ")";
    }

    std::string getName() const { return name; }
    int getBirthYear() const { return birthYear; }

    void setBirthYear(int y) {
        if(y < 1850) y = 1850;
        if(y > 2025) y = 2025;
        birthYear = y;
    }
};
