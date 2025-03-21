#ifndef ENTITLEMENT_LOOKUP_H
#define ENTITLEMENT_LOOKUP_H

#include <string>
#include <vector>

// Get ACCESS_POINT_ID from an entitlement
std::string getAccessPointID(const std::string& entitlement_name);

// Get PRIVILEGE_ID from ACCESS_POINT_ID
std::string getPrivilegeIDFromAccessPoint(const std::string& access_point_id);

// Get USER_IDs who have access to an entitlement
std::vector<std::string> getUserIDsForEntitlement(const std::string& entitlement_name);

#endif
