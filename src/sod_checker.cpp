#include "sod_checker.h"
#include <iostream>
#include <unordered_set>

std::unordered_set<std::string> getUsersWithAccess(
    const std::string& access_point_id,
    const std::unordered_map<std::string, std::string>& entitlement_to_privilege,
    const std::unordered_map<std::string, std::vector<std::string>>& privilege_to_roles,
    const std::unordered_map<std::string, std::vector<std::string>>& role_to_users) 
{
    std::unordered_set<std::string> users_with_access;

    // Find the privilege associated with the given ACCESS_POINT_ID
    if (entitlement_to_privilege.find(access_point_id) == entitlement_to_privilege.end()) {
        std::cerr << "No privileges found for ACCESS_POINT_ID: " << access_point_id << std::endl;
        return users_with_access;
    }

    std::string privilege_id = entitlement_to_privilege.at(access_point_id);

    // Find all roles that have this privilege
    if (privilege_to_roles.find(privilege_id) == privilege_to_roles.end()) {
        return users_with_access;
    }

    std::vector<std::string> roles = privilege_to_roles.at(privilege_id);

    // Find all users assigned to these roles
    for (const std::string& role : roles) {
        if (role_to_users.find(role) != role_to_users.end()) {
            users_with_access.insert(role_to_users.at(role).begin(), role_to_users.at(role).end());
        }
    }

    return users_with_access;
}
