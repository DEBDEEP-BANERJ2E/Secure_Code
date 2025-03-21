#include "parser.h"
#include "sod_checker.h"
#include "utils.h"
#include <iostream>
#include <unordered_map>

int main() {
    // Load data
    auto user_role_data = parseCSV("csv_input/XX_3_USER_ROLE_MAPPING_RPT.csv");
    auto role_data = parseCSV("csv_input/XX_4_ROLE_MASTER_DETAILS_RPT.csv");
    auto role_hierarchy_data = parseCSV("csv_input/XX_5_ROLE_TO_ROLE_HIER_RPT.csv");
    auto role_privilege_data = parseCSV("csv_input/XX_6_PVLG_TO_ROLE_RELATION_RPT.csv");
    auto privilege_data = parseCSV("csv_input/XX_7_PVLGS_MASTER_RPT.csv");
    auto entitlement_data = parseCSV("csv_input/ENTITLEMENT_MST.csv");

    // Mapping structures
    std::unordered_map<std::string, std::vector<std::string>> role_to_users;
    std::unordered_map<std::string, std::vector<std::string>> privilege_to_roles;
    std::unordered_map<std::string, std::string> entitlement_to_privilege;

    // Populate role-to-users mapping
    for (const auto& row : user_role_data) {
        role_to_users[row[1]].push_back(row[0]);  // Role_ID -> User_ID
    }

    // Populate privilege-to-roles mapping
    for (const auto& row : role_privilege_data) {
        privilege_to_roles[row[1]].push_back(row[2]);  // Privilege_ID -> Role_ID
    }

    // Populate entitlement-to-privilege mapping
    for (const auto& row : entitlement_data) {
        entitlement_to_privilege[row[2]] = row[0];  // ACCESS_POINT_ID -> Privilege_ID
    }

    // User input
    std::string access_point_id;
    std::cout << "Enter ACCESS_POINT_ID: ";
    std::cin >> access_point_id;

    // Find users with access
    std::unordered_set<std::string> users = getUsersWithAccess(
        access_point_id, entitlement_to_privilege, privilege_to_roles, role_to_users
    );

    // Print results
    printUsers(users);

    return 0;
}
