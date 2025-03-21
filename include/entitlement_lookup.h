#ifndef ENTITLEMENT_LOOKUP_H
#define ENTITLEMENT_LOOKUP_H

#include <vector>
#include <string>

// Function to get ACCESS_POINT_IDs from an Entitlement Name
std::vector<std::string> getAccessPointIDs(const std::string& entitlement_name);

// Function to get all USER_IDs associated with an Entitlement
std::vector<std::string> getUserIDsForEntitlement(const std::string& entitlement_name);

#endif // ENTITLEMENT_LOOKUP_H
