#include "privilege_lookup.h"
#include "parser.h"
#include <iostream>

// Finds PRIVILEGE_IDs from ACCESS_POINT_IDs
std::vector<std::string> getPrivilegeIDsFromAccessPoints(const std::vector<std::string>& access_points) {
    std::vector<std::string> privilege_ids;
    auto privilege_data = parseCSV("XX_7_PVLGS_MASTER_RPT.csv");

    for (const auto& row : privilege_data) {
        if (row.size() > 3) {  // Ensure row has CODE and PRIVILEGE_ID
            for (const auto& access_point_id : access_points) {
                if (row[3] == access_point_id) {  // Column 3 = CODE
                    privilege_ids.push_back(row[2]);  // Column 2 = PRIVILEGE_ID
                }
            }
        }
    }
    return privilege_ids;
}

// Finds ROLE_IDs for a list of PRIVILEGE_IDs
std::vector<std::string> getRolesForPrivileges(const std::vector<std::string>& privilege_ids) {
    std::vector<std::string> role_ids;
    auto role_privilege_data = parseCSV("XX_6_PVLG_TO_ROLE_RELATION_RPT.csv");

    for (const auto& row : role_privilege_data) {
        if (row.size() > 2) {  // Ensure row has PRIVILEGE_ID and ROLE_ID
            for (const auto& privilege_id : privilege_ids) {
                if (row[1] == privilege_id) {  // Column 1 = PRIVILEGE_ID
                    role_ids.push_back(row[2]);  // Column 2 = ROLE_ID
                }
            }
        }
    }
    return role_ids;
}
