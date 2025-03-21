#include "entitlement_lookup.h"
#include "privilege_lookup.h"
#include "parser.h"
#include <iostream>
#include <unordered_set>

// Get ACCESS_POINT_ID from ENTITLEMENT NAME
std::string getAccessPointID(const std::string& entitlement_name) {
    auto entitlement_data = parseCSV("ENTITLEMENT_MST.csv");
    for (const auto& row : entitlement_data) {
        if (row.size() > 2 && row[0] == entitlement_name) {  // Column 0 = ACCESS_ENTITLEMENT
            return row[2];  // Column 2 = ACCESS_POINT_ID
        }
    }
    return "";
}

// Get PRIVILEGE_ID from ACCESS_POINT_ID
std::string getPrivilegeIDFromAccessPoint(const std::string& access_point_id) {
    auto privilege_data = parseCSV("XX_7_PVLGS_MASTER_RPT.csv");
    for (const auto& row : privilege_data) {
        if (row.size() > 2 && row[1] == access_point_id) {  // Column 1 = NAME
            return row[2];  // Column 2 = PRIVILEGE_ID
        }
    }
    return "";
}

// Get USER_IDs for an Entitlement
std::vector<std::string> getUserIDsForEntitlement(const std::string& entitlement_name) {
    std::string access_point_id = getAccessPointID(entitlement_name);
    if (access_point_id.empty()) return {};

    std::string privilege_id = getPrivilegeIDFromAccessPoint(access_point_id);
    if (privilege_id.empty()) return {};

    std::vector<std::string> role_ids = getRolesForPrivilege(privilege_id);
    if (role_ids.empty()) return {};

    std::unordered_set<std::string> user_ids;
    auto user_role_data = parseCSV("XX_3_USER_ROLE_MAPPING_RPT.csv");

    for (const auto& role_id : role_ids) {
        for (const auto& row : user_role_data) {
            if (row.size() > 2 && row[0] == role_id) { // Column 0 = ROLE_ID
                user_ids.insert(row[2]);  // Column 2 = USER_ID
            }
        }
    }

    return std::vector<std::string>(user_ids.begin(), user_ids.end());
}
