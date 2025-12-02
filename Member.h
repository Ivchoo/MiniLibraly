#pragma once
#include <string>

class Member {
private:
    std::string name;
    std::string memberId;
    int yearJoined;

public:
    Member() : name("Unknown"), memberId(""), yearJoined(2000) {}
    Member(const std::string& n, const std::string& id, int y)
        : name(n), memberId(id), yearJoined(y) {}

    bool isValid() const { return !memberId.empty(); }

    std::string getId() const { return memberId; }

    std::string to_string() const {
        return name + " (" + memberId + ") joined " + std::to_string(yearJoined);
    }
};
