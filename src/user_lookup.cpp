#include "user_lookup.h"
#include "parser.h"
#include <iostream>
#include <vector>

// Get USER_IDs for a given ROLE_ID
std::vector<std::string> getUserIDsForRole(const std::string& role_id) {
    std::vector<std::string> user_ids;
    auto user_role_data = parseCSV("XX_3_USER_ROLE_MAPPING_RPT.csv");

    for (const auto& row : user_role_data) {
        if (row.size() > 2 && row[0] == role_id) { // Column 0 = ROLE_ID
            user_ids.push_back(row[2]);  // Column 2 = USER_ID
        }
    }

    return user_ids;
}

// Retrieve USER details and print them
void getUserDetails(const std::vector<std::string>& user_ids) {
    auto user_data = parseCSV("XX_2_USER_DETAILS_RPT.csv");

    for (const auto& user_id : user_ids) {
        for (const auto& row : user_data) {
            if (row.size() > 10 && row[5] == user_id) { // Column 5 = USER_ID
                std::cout << "User Details: ";
                for (const auto& field : row) std::cout << field << " | ";
                std::cout << std::endl;
                break;
            }
        }
    }
}
