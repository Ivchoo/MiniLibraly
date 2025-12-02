# Проект: Мини „Библиотечна система" (Library System)

## Описание

Проектът „Библиотечна система" представлява малка C++ система, която моделира работа с книги, автори, читатели и заеми чрез пет взаимосвързани класа — Author, Book, Member, Loan и Library.
Този README е създаден заедно с main.cpp, който демонстрира основните функционалности на системата.

Системата показва:

* добавяне на книги и членове;
* създаване на заем и проверка за наличност;
* връщане на книги;
* търсене на книги по автор;
* използване на статични членове, const методи и валидация на данни.

---

## Структура на проекта

```
library_homework/
├── Author.h
├── Book.h
├── Member.h
├── Loan.h
├── Library.h
├── main.cpp
└── README.md
```

---

## Компилация и изпълнение

Отворете терминал в директорията `library_homework/` и изпълнете:

```bash
 g++ -std=gnu++17 -Wall -Wextra -O2 -o library main.cpp
```

След това стартирайте програмата:

```bash
./library      # Linux / macOS
```

---

## main.cpp

```cpp
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
```

---

## Примерен изход

```
Books: 2, Members: 1, Loans: 1
Loan created.
Available ISBN-001? false
Available ISBN-001? true
The intelgent investor | Benjaming Graham (1812) | 1850 | 17.500000 BGN | ISBN-001
Cyber specialist | Benjaming Graham (1812) | 1845 | 123.300000 BGN | ISBN-002
```

---

## Класове

### Клас Author

Представя автор с основни характеристики.

**Членове:**

* `std::string name`
* `int birthYear`

**Методи:**

* Конструктори (по подразбиране и параметризиран)
* `std::string to_string() const`
* Getters и setter с валидация (1850–2025)

---

### Клас Book

Представя книга.

**Членове:**

* `std::string title`
* `Author author`
* `int year`
* `double price`
* `std::string isbn`
* `static int totalBooks`

**Методи:**

* Конструктори (по подразбиране, параметризиран, копиращ и преместващ)
* Деструктор
* `std::string to_string() const`
* Getters
* `static int getTotalBooks()`

**Валидации:**

* `year` 1450–2025
* `price >= 0`

---

### Клас Member

Представя читател.

**Членове:**

* `std::string name`
* `std::string memberId`
* `int yearJoined`

**Методи:**

* `bool isValid() const`
* `std::string to_string() const`

---

### Клас Loan

Представя заем на книга.

**Членове:**

* `std::string isbn`
* `std::string memberId`
* `std::string startDate`
* `std::string dueDate`
* `bool returned`

**Методи:**

* `void markReturned()`
* `bool isReturned() const`
* `bool isOverdue(const std::string& today) const`
* `std::string to_string() const`

---

### Клас Library

Представя библиотека с книги и членове.

**Членове:**

* `std::vector<Book> books`
* `std::vector<Member> members`
* `std::vector<Loan> loans`

**Методи:**

* `void addBook(const Book& b)`
* `void addMember(const Member& m)`
* `bool hasBook(const std::string& isbn) const`
* `bool isBookAvailable(const std::string& isbn) const`
* `bool loanBook(const std::string& isbn, const std::string& memberId, const std::string& start, const std::string& due)`
* `bool returnBook(const std::string& isbn, const std::string& memberId)`
* `std::vector<Book> findByAuthor(const std::string& authorName) const`
* `std::string to_string() const`

---

ЕКРАННА СНИМКА:
<img width="1911" height="1012" alt="output" src="https://github.com/user-attachments/assets/986c3b0c-a0db-44b8-ba8c-f65d94f1d285" />


## Автор

* Име: ИВЕЛИН БОРИСЛАВОВ РАЙНОВСКИ
* Номер: 22315
* Курс: Обектно-ориентирано програмиране (C++)
* Дата: 12/2/2025

