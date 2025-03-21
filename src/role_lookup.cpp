#include "role_lookup.h"
#include "parser.h"
#include <iostream>

// Traverse role hierarchy to find the topmost role
std::string getTopParentRole(const std::string& role_id) {
    auto hierarchy_data = parseCSV("XX_5_ROLE_TO_ROLE_HIER_RPT.csv");
    std::string current_role_id = role_id;

    while (true) {
        bool found = false;
        for (const auto& row : hierarchy_data) {
            if (row.size() > 2 && row[1] == current_role_id) { // CHILD_ROLE_ID
                current_role_id = row[2];  // PARENT_ROLE_ID
                found = true;
                break;
            }
        }
        if (!found) break;
    }
    return current_role_id;
}
