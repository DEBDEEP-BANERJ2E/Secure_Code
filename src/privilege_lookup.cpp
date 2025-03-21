#include "privilege_lookup.h"
#include "parser.h"
#include <iostream>

// Finds PRIVILEGE_ID for a given PRIVILEGE NAME
std::string getPrivilegeID(const std::string& privilege_name) {
    auto privilege_data = parseCSV("XX_7_PVLGS_MASTER_RPT.csv");
    for (const auto& row : privilege_data) {
        if (row.size() > 1 && row[1] == privilege_name) {  // Column 1 = NAME
            return row[2];  // Column 2 = PRIVILEGE_ID
        }
    }
    return "";
}

// Finds ROLE_IDs that have the given PRIVILEGE_ID
std::vector<std::string> getRolesForPrivilege(const std::string& privilege_id) {
    std::vector<std::string> role_ids;
    auto role_privilege_data = parseCSV("XX_6_PVLG_TO_ROLE_RELATION_RPT.csv");

    for (const auto& row : role_privilege_data) {
        if (row.size() > 2 && row[1] == privilege_id) { // Column 1 = PRIVILEGE_ID
            role_ids.push_back(row[2]);  // Column 2 = ROLE_ID
        }
    }
    return role_ids;
}
