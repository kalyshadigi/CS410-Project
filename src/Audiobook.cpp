#include "Audiobook.h"
#include <iostream>

void Audiobook::create_item() {
    std::cout << "Title: ";
    std::getline(std::cin, title);
    std::cout << "Author: ";
    std::getline(std::cin, author);
    std::cout << "Narrator: ";
    std::getline(std::cin, narrator);
    std::cout << "Total Minutes: ";
    std::cin >> duration;
    std::cin.ignore();
}

std::string Audiobook::display_item() const {
    std::string durationStr = std::to_string(duration);
    return "Title: " + title + " by " + author + "; Narrated by: " + narrator + "\nTotal Duration: " + durationStr + "(mins)";
}