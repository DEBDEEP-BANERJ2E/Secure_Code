#include "sod_violations.h"
#include "entitlement_lookup.h"
#include "parser.h"
#include "user_lookup.h"
#include <iostream>
#include <unordered_set>

// Get entitlements for a given SOD_POLICY_CODE
std::pair<std::string, std::string> getEntitlementsForSOD(const std::string& sod_policy_code) {
    auto sod_data = parseCSV("SOD_MASTER.csv");
    for (const auto& row : sod_data) {
        if (row.size() > 2 && row[0] == sod_policy_code) { // Column 0 = SOD_POLICY_CODE
            return {row[1], row[2]}; // ENT_LEG1, ENT_LEG2
        }
    }
    return {"", ""}; // Return empty if not found
}

// Find common users between two entitlements
std::vector<std::string> findCommonUsers(const std::vector<std::string>& users1, const std::vector<std::string>& users2) {
    std::unordered_set<std::string> users2_set(users2.begin(), users2.end());
    std::vector<std::string> violating_users;

    for (const auto& user : users1) {
        if (users2_set.find(user) != users2_set.end()) {
            violating_users.push_back(user);
        }
    }
    return violating_users;
}
