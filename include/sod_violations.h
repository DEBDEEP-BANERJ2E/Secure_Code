#ifndef SOD_VIOLATIONS_H
#define SOD_VIOLATIONS_H

#include <vector>
#include <string>

// Function to retrieve entitlements (ENT_LEG1, ENT_LEG2) from SOD_POLICY_CODE
std::pair<std::string, std::string> getEntitlementsForSOD(const std::string& sod_policy_code);

// Function to detect SoD violations and return conflicting users
std::vector<std::string> detectSODViolations(const std::string& sod_policy_code);

#endif // SOD_VIOLATIONS_H
