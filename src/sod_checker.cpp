#include "sod_checker.h"
#include <unordered_map>
#include <iostream>

// Checks for role conflicts based on predefined rules
void checkConflicts(const std::vector<RoleAssignment>& assignments, 
                    const std::unordered_map<std::string, std::unordered_set<std::string>>& conflictRules) {
    std::unordered_map<std::string, std::unordered_set<std::string>> userRoles;

    for (const auto& assignment : assignments) {
        userRoles[assignment.user].insert(assignment.role);
    }

    for (const auto& [user, roles] : userRoles) {
        for (const auto& role : roles) {
            if (conflictRules.find(role) != conflictRules.end()) {
                for (const auto& conflictingRole : conflictRules.at(role)) {
                    if (roles.count(conflictingRole)) {
                        std::cout << "Conflict detected: User " << user 
                                  << " has conflicting roles: " << role 
                                  << " and " << conflictingRole << std::endl;
                    }
                }
            }
        }
    }
}
