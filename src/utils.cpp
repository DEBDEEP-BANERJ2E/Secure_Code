#include "utils.h"
#include <iostream>

void printUsers(const std::unordered_set<std::string>& users) {
    if (users.empty()) {
        std::cout << "No users found with access to the given ACCESS_POINT_ID." << std::endl;
        return;
    }

    std::cout << "Users with access:" << std::endl;
    for (const auto& user : users) {
        std::cout << "- " << user << std::endl;
    }
}
