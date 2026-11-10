#include "Game.h"
#include <iostream>

void Game::create_item() {
    std::cout << "Title: ";
    std::getline(std::cin, title);
    std::cout << "Rating: ";
    std::getline(std::cin, rating);
    std::cin.ignore();
}

std::string Game::display_item() const {
    return "Game Title: " + title + " Rated:  " + rating + " by the ESRB"; 
}