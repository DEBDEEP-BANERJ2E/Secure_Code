#ifndef PRIVILEGE_LOOKUP_H
#define PRIVILEGE_LOOKUP_H

#include <string>
#include <vector>

// Get PRIVILEGE_ID for a given PRIVILEGE NAME
std::string getPrivilegeID(const std::string& privilege_name);

// Get ROLE_IDs for a given PRIVILEGE_ID
std::vector<std::string> getRolesForPrivilege(const std::string& privilege_id);

#endif
