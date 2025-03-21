#ifndef PRIVILEGE_LOOKUP_H
#define PRIVILEGE_LOOKUP_H

#include <string>
#include <vector>

// Finds PRIVILEGE_IDs for given ACCESS_POINT_IDs
std::vector<std::string> getPrivilegeIDsFromAccessPoints(const std::vector<std::string>& access_points);

// Finds ROLE_IDs for given PRIVILEGE_IDs
std::vector<std::string> getRolesForPrivileges(const std::vector<std::string>& privilege_ids);

#endif // PRIVILEGE_LOOKUP_H
