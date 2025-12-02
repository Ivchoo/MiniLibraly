#pragma once
#include <string>

class Loan {
private:
    std::string isbn;
    std::string memberId;
    std::string startDate;
    std::string dueDate;
    bool returned;

public:
    Loan(const std::string& i, const std::string& m, const std::string& start, const std::string& due)
        : isbn(i), memberId(m), startDate(start), dueDate(due), returned(false) {
        if(dueDate < startDate) dueDate = startDate;
    }

    void markReturned() { returned = true; }
    bool isReturned() const { return returned; }

    bool isOverdue(const std::string& today) const {
        return !returned && today > dueDate;
    }

    std::string to_string() const {
        return isbn + " to " + memberId + ", returned: " + (returned ? "yes" : "no");
    }

    std::string getISBN() const { return isbn; }
    std::string getMemberID() const { return memberId; }
};
