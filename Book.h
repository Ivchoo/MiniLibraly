#pragma once
#include <string>
#include "Author.h"

class Book {
private:
    std::string title;
    Author author;
    int year;
    double price;
    std::string isbn;

public:
    static int totalBooks;

    Book() : title("Untitled"), author(), year(1900), price(0.0), isbn("NONE") {
        totalBooks++;
    }

    Book(const std::string& t, const Author& a, int y, double p, const std::string& i)
        : title(t), author(a), isbn(i) {
        if(y < 1450) y = 1450;
        if(y > 2025) y = 2025;
        year = y;
        if(p < 0) p = 0;
        price = p;
        totalBooks++;
    }

    Book(const Book& other)
        : title(other.title), author(other.author), year(other.year),
          price(other.price), isbn(other.isbn) {
        totalBooks++;
    }

    Book(Book&& other) noexcept
        : title(std::move(other.title)), author(std::move(other.author)),
          year(other.year), price(other.price), isbn(std::move(other.isbn)) {
        totalBooks++;
    }

    Book& operator=(const Book& other) {
        if(this != &other) {
            title = other.title;
            author = other.author;
            year = other.year;
            price = other.price;
            isbn = other.isbn;
        }
        return *this;
    }

    Book& operator=(Book&& other) noexcept {
        if(this != &other) {
            title = std::move(other.title);
            author = std::move(other.author);
            year = other.year;
            price = other.price;
            isbn = std::move(other.isbn);
        }
        return *this;
    }

    ~Book() { totalBooks--; }

    std::string to_string() const {
        return title + " | " + author.to_string() + " | " +
               std::to_string(year) + " | " + std::to_string(price) + " BGN | " + isbn;
    }

    std::string getISBN() const { return isbn; }
    std::string getAuthorName() const { return author.getName(); }
};

int Book::totalBooks = 0;
