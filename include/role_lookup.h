#ifndef ROLE_LOOKUP_H
#define ROLE_LOOKUP_H

#include <string>

// Function to get ROLE_ID from ROLE_NAME
std::string getRoleID(const std::string& role_name);

// Function to find the topmost parent ROLE_ID from the hierarchy
std::string getTopParentRole(const std::string& role_id);

#endif // ROLE_LOOKUP_H
