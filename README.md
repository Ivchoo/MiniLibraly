# Мини „Библиотечна система“

## Цел
Да се създаде малка система от пет свързани класа (Author, Book, Member, Loan, Library), чрез която се упражняват основните концепции за класове в C++, включително:

- Конструктори и деструктори  
- Списък за инициализация  
- Getters и setters с валидация  
- `to_string()` методи  
- Статични членове и const методи  
- Добри практики (explicit, const-коректност, = default, Rule of 3/5)  

---

## Изисквания към класовете

### 1) Клас Author
**Членове:**  
- `string name` – име на автора  
- `int birthYear` – година на раждане  

**Конструктори:**  
- Конструктор по подразбиране: `name = "Unknown"`, `birthYear = 1900`  
- Параметризиран конструктор със списък за инициализация  

**Методи:**  
- `string to_string() const` – връща името и годината на автора  
- Getters за всички полета  
- Setter `setBirthYear(int)` с валидация (1850–2025)  

---

### 2) Клас Book
**Членове:**  
- `string title`  
- `Author author`  
- `int year`  
- `double price`  
- `string isbn`  
- `static int totalBooks` – брояч на всички създадени книги  

**Конструктори и оператори (Rule of 5):**  
- Конструктор по подразбиране  
- Параметризиран конструктор  
- Копиращ и преместващ конструктор  
- Копиращ и преместващ оператор  
- Деструктор (`~Book()`)  

**Методи:**  
- `string to_string() const` – текстово представяне  
- Getters  
- Статичен метод `getTotalBooks()`  

**Валидации:**  
- `year` – разумен диапазон (1450–2025)  
- `price` – ≥ 0  

---

### 3) Клас Member
**Членове:**  
- `string name`  
- `string memberId`  
- `int yearJoined`  

**Конструктори:**  
- По подразбиране и параметризиран  

**Методи:**  
- `bool isValid() const` – memberId не е празен  
- `string to_string() const`  

---

### 4) Клас Loan
**Членове:**  
- `string isbn`  
- `string memberId`  
- `string startDate`  
- `string dueDate`  
- `bool returned`  

**Конструктор:**  
- Параметризиран, с валидация `dueDate >= startDate`  

**Методи:**  
- `void markReturned()`  
- `bool isReturned() const`  
- `bool isOverdue(const string& today) const`  
- `string to_string() const`  

---

### 5) Клас Library
**Членове:**  
- `vector<Book> books`  
- `vector<Member> members`  
- `vector<Loan> loans`  

**Методи:**  
- `void addBook(const Book& b)`  
- `void addMember(const Member& m)`  
- `bool hasBook(const string& isbn) const`  
- `bool isBookAvailable(const string& isbn) const`  
- `bool loanBook(const string& isbn, const string& memberId, const string& start, const string& due)`  
- `bool returnBook(const string& isbn, const string& memberId)`  
- `vector<Book> findByAuthor(const string& authorName) const`  
- `string to_string() const` – обобщена информация  

**Добри практики:**  
- Const-коректност  
- Без „голи“ указатели  
- Ясни инварианти  

---

## Примерен код за тестване
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
## Примерен изход
Books: 2, Members: 1, Loans: 0
Loan created.
Available ISBN-001? false
Available ISBN-001? true
The intelgent investor | Benjaming Graham (1850) | 1850 | 17.500000 BGN | ISBN-001
Cyber specialist | Benjaming Graham (1850) | 1845 | 123.300000 BGN | ISBN-002


 ## Компилация
 -g++ -std=gnu++17 -Wall -Wextra -O2 -o library main.cpp
 -.\library
