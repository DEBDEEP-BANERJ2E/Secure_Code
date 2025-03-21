#include "entitlement_lookup.h"
#include "privilege_lookup.h"
#include "parser.h"
#include "role_lookup.h"
#include "user_lookup.h"
#include <iostream>
#include <unordered_set>

// Get ACCESS_POINT_IDs for a given entitlement
std::vector<std::string> getAccessPointIDs(const std::string& entitlement_name) {
    std::vector<std::string> access_point_ids;
    auto entitlement_data = parseCSV("ENTITLEMENT_MST.csv");

    for (const auto& row : entitlement_data) {
        if (row.size() > 2 && row[0] == entitlement_name) {  // Column 0 = ACCESS_ENTITLEMENT
            access_point_ids.push_back(row[2]);  // Column 2 = ACCESS_POINT_ID
        }
    }
    return access_point_ids;
}

// Get USERS for a given entitlement
std::vector<std::string> getUserIDsForEntitlement(const std::string& entitlement_name) {
    std::vector<std::string> user_ids;
    
    // Step 1: Get ACCESS_POINT_IDs
    std::vector<std::string> access_points = getAccessPointIDs(entitlement_name);
    if (access_points.empty()) return {};

    // Step 2: Get PRIVILEGE_IDs (Use function from privilege_lookup)
    std::vector<std::string> privilege_ids = getPrivilegeIDsFromAccessPoints(access_points);
    if (privilege_ids.empty()) return {};

    // Step 3: Get ROLE_IDs (Use function from privilege_lookup)
    std::vector<std::string> role_ids = getRolesForPrivileges(privilege_ids);
    if (role_ids.empty()) return {};

    // Step 4: Traverse role hierarchy
    std::unordered_set<std::string> final_roles;
    for (const auto& role_id : role_ids) {
        final_roles.insert(getTopParentRole(role_id));
    }

    // Step 5: Get USER_IDs from roles
    for (const auto& parent_role_id : final_roles) {
        std::vector<std::string> users = getUserIDsForRole(parent_role_id);
        user_ids.insert(user_ids.end(), users.begin(), users.end());
    }

    return user_ids;
}
