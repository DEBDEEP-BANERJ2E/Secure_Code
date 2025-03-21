#ifndef ROLE_LOOKUP_H
#define ROLE_LOOKUP_H

#include <string>

std::string getRoleID(const std::string& role_name);
std::string getTopParentRole(const std::string& role_id);

#endif
