#include "parser.h"
#include "role_lookup.h"
#include "user_lookup.h"
#include "privilege_lookup.h"
#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    std::string privilege_name;
    std::cout << "Enter PRIVILEGE NAME: ";
    std::getline(std::cin, privilege_name); // Accept full privilege name with spaces

    // Find PRIVILEGE_ID from PRIVILEGE NAME
    std::string privilege_id = getPrivilegeID(privilege_name);
    if (privilege_id.empty()) {
        std::cerr << "Error: PRIVILEGE NAME not found.\n";
        return 1;
    }

    // Find ROLE_IDs that have this PRIVILEGE_ID
    std::vector<std::string> role_ids = getRolesForPrivilege(privilege_id);
    if (role_ids.empty()) {
        std::cerr << "No roles found for PRIVILEGE_ID: " << privilege_id << "\n";
        return 1;
    }

    // Find topmost PARENT_ROLE_ID for each ROLE_ID
    std::unordered_set<std::string> top_parent_roles;
    for (const auto& role_id : role_ids) {
        top_parent_roles.insert(getTopParentRole(role_id));
    }

    // Find USER_IDs for the topmost roles (avoiding duplicates)
    std::unordered_set<std::string> user_ids;
    for (const auto& parent_role_id : top_parent_roles) {
        std::vector<std::string> users = getUserIDsForRole(parent_role_id);
        user_ids.insert(users.begin(), users.end());  // Ensures unique user IDs
    }

    if (user_ids.empty()) {
        std::cerr << "No users found for PRIVILEGE_ID: " << privilege_id << "\n";
        return 1;
    }

    // Convert unordered_set to vector for processing
    std::vector<std::string> unique_user_ids(user_ids.begin(), user_ids.end());

    // Retrieve and print unique user details
    getUserDetails(unique_user_ids);

    return 0;
}
