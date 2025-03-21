#include "parser.h"
#include "role_lookup.h"
#include "user_lookup.h"
#include <iostream>

int main() {
    std::string role_name;
    std::cout << "Enter ROLE_NAME: ";
    std::getline(std::cin, role_name); // Accept full role name with spaces

    // Find ROLE_ID from ROLE_NAME
    std::string role_id = getRoleID(role_name);
    if (role_id.empty()) {
        std::cerr << "Error: ROLE_NAME not found.\n";
        return 1;
    }

    // Find topmost PARENT_ROLE_ID
    std::string top_parent_role_id = getTopParentRole(role_id);

    // Find USER_IDs for the topmost role
    std::vector<std::string> user_ids = getUserIDsForRole(top_parent_role_id);
    if (user_ids.empty()) {
        std::cerr << "No users found for ROLE_ID: " << top_parent_role_id << "\n";
        return 1;
    }

    // Retrieve and print user details
    getUserDetails(user_ids);

    return 0;
}
