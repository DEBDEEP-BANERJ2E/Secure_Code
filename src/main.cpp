#include "parser.h"
#include "user_lookup.h"
#include "entitlement_lookup.h"
#include "sod_violations.h"
#include <iostream>

int main() {
    // Parse the SOD_MASTER.csv file to get all policy codes
    auto sod_data = parseCSV("SOD_MASTER.csv");
    
    if (sod_data.empty()) {
        std::cerr << "❌ Error: Failed to read SOD_MASTER.csv or it's empty." << std::endl;
        return 1;
    }

    // Iterate through all policy codes
    for (const auto& row : sod_data) {
        if (row.size() < 3) continue; // Ensure at least SOD_POLICY_CODE, ENT_LEG1, and ENT_LEG2 exist

        std::string sod_policy_code = row[0]; // Column 0 = SOD_POLICY_CODE
        
        // Detect violations for this policy
        std::vector<std::string> violating_users = detectSODViolations(sod_policy_code);

        // Display results if violations exist
        if (!violating_users.empty()) {
            std::cout << "\n🚨 SOD Violation Detected for Policy: " << sod_policy_code << " 🚨\n";
            getUserDetails(violating_users);
        } else {
            std::cout << "\n✅ No SoD Violations found for policy: " << sod_policy_code << "\n";
        }
    }

    return 0;
}
