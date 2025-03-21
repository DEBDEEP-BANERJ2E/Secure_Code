#ifndef SOD_VIOLATIONS_H
#define SOD_VIOLATIONS_H

#include <string>
#include <vector>

// Get entitlements (ENT_LEG1, ENT_LEG2) for a given SOD_POLICY_CODE
std::pair<std::string, std::string> getEntitlementsForSOD(const std::string& sod_policy_code);

// Find common users between two entitlement lists
std::vector<std::string> findCommonUsers(const std::vector<std::string>& users1, const std::vector<std::string>& users2);

#endif
