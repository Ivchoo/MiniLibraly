#include <iostream>
#include "Library.h"
#include "Author.h"
#include "Book.h"
#include "Member.h"

int main() {
    Library lib;
    Author a{"Benjaming Graham", 1812};
    Book b1{"The intelgent investor", a, 1850, 17.50, "ISBN-001"};
    Book b2{"Cyber specialist", a, 1845, 123.30, "ISBN-002"};

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addMember(Member{"Ivelin Raynovski", "M001", 2025});

    std::cout << lib.to_string() << "\n";

    if(lib.loanBook("ISBN-001", "M001", "2025-11-03", "2025-11-17"))
        std::cout << "Loan created.\n";

    std::cout << "Available ISBN-001? " << std::boolalpha
              << lib.isBookAvailable("ISBN-001") << "\n";
    lib.returnBook("ISBN-001", "M001");
    std::cout << "Available ISBN-001? " << std::boolalpha
              << lib.isBookAvailable("ISBN-001") << "\n";

    for(const auto& bk : lib.findByAuthor("Graham"))
        std::cout << bk.to_string() << "\n";

    return 0;
}
