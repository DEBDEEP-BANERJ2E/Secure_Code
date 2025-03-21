#include "role_lookup.h"
#include "parser.h"
#include <iostream>

// Finds ROLE_ID for a given ROLE_NAME
std::string getRoleID(const std::string& role_name) {
    auto role_data = parseCSV("XX_4_ROLE_MASTER_DETAILS_RPT.csv");
    for (const auto& row : role_data) {
        if (row.size() > 1 && row[1] == role_name) {  // Column 1 = ROLE_NAME
            return row[0];  // Column 0 = ROLE_ID
        }
    }
    return "";
}

// Traces hierarchy to find the topmost parent ROLE_ID
std::string getTopParentRole(const std::string& role_id) {
    auto hierarchy_data = parseCSV("XX_5_ROLE_TO_ROLE_HIER_RPT.csv");
    std::string current_role_id = role_id;

    while (true) {
        bool found = false;
        for (const auto& row : hierarchy_data) {
            if (row.size() > 2 && row[1] == current_role_id) { // Column 1 = CHILD_ROLE_ID
                current_role_id = row[2];  // Column 2 = PARENT_ROLE_ID
                found = true;
                break;
            }
        }
        if (!found) break;
    }
    return current_role_id;
}
