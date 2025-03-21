#include "sod_violations.h"
#include "entitlement_lookup.h"
#include "parser.h"
#include "user_lookup.h"
#include <iostream>
#include <unordered_set>

// Detect SoD Violations for a given SOD policy
std::vector<std::string> detectSODViolations(const std::string& sod_policy_code) {
    auto sod_data = parseCSV("SOD_MASTER.csv");

    for (const auto& row : sod_data) {
        if (row.size() < 3 || row[0] != sod_policy_code) continue; // Skip invalid rows or non-matching policy codes

        std::string ent_leg1 = row[1]; // Column 1 = ENT_LEG1
        std::string ent_leg2 = row[2]; // Column 2 = ENT_LEG2

        if (ent_leg1.empty() || ent_leg2.empty()) continue; // Skip if either entitlement is missing

        // Get users for each entitlement
        std::vector<std::string> users1 = getUserIDsForEntitlement(ent_leg1);
        std::vector<std::string> users2 = getUserIDsForEntitlement(ent_leg2);

        if (users1.empty() || users2.empty()) continue; // No users found, skip this policy

        // Find common users (conflicts)
        std::unordered_set<std::string> users2_set(users2.begin(), users2.end());
        std::vector<std::string> violating_users;

        for (const auto& user : users1) {
            if (users2_set.find(user) != users2_set.end()) {
                violating_users.push_back(user);
            }
        }

        return violating_users;
    }

    return {}; // No violations found
}
