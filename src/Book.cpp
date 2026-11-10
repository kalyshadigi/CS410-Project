#include "Book.h"
#include <iostream>
#include <string>

void Book::create_item() {
    std::cout << "Title: ";
    std::getline(std::cin, title);
    std::cout << "Author: ";
    std::getline(std::cin, author);
    std::cout << "Pages: ";
    std::cin >> pages;
    std::cin.ignore();

    
}

std::string Book::display_item() const {
    std::string pagesStr = std::to_string(pages);
    return "Book: " + title + " by " + author + "; Total Pages: " + pagesStr; 
}