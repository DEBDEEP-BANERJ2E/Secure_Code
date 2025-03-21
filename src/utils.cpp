#include "utils.h"
#include <iostream>

void printUsers(const std::vector<std::string>& users) {
    if (users.empty()) {
        std::cout << "No users found." << std::endl;
        return;
    }

    std::cout << "Users:" << std::endl;
    for (const auto& user : users) {
        std::cout << "- " << user << std::endl;
    }
}
