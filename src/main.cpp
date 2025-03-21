#include "parser.h"
#include "role_lookup.h"
#include "user_lookup.h"
#include "privilege_lookup.h"
#include "entitlement_lookup.h"
#include "sod_violations.h"
#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    std::string sod_policy_code;
    std::cout << "Enter SOD POLICY CODE: ";
    std::getline(std::cin, sod_policy_code); // Accept full SoD policy code

    // Find the entitlements linked to this SOD_POLICY_CODE
    std::pair<std::string, std::string> entitlements = getEntitlementsForSOD(sod_policy_code);
    if (entitlements.first.empty() || entitlements.second.empty()) {
        std::cerr << "Error: No entitlements found for SOD_POLICY_CODE: " << sod_policy_code << "\n";
        return 1;
    }

    // Get users for each entitlement
    std::vector<std::string> users1 = getUserIDsForEntitlement(entitlements.first);
    std::vector<std::string> users2 = getUserIDsForEntitlement(entitlements.second);

    if (users1.empty() || users2.empty()) {
        std::cerr << "No users found for the given SoD policy.\n";
        return 1;
    }

    // Find common users between both entitlements (violations)
    std::vector<std::string> violating_users = findCommonUsers(users1, users2);

    // Display results
    if (!violating_users.empty()) {
        std::cout << "🚨 SOD Violation Detected for Policy: " << sod_policy_code << " 🚨\n";
        getUserDetails(violating_users);
    } else {
        std::cout << "✅ No SoD Violations found for policy: " << sod_policy_code << "\n";
    }

    return 0;
}
