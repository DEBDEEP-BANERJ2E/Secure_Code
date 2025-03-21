#ifndef USER_LOOKUP_H
#define USER_LOOKUP_H

#include <vector>
#include <string>

std::vector<std::string> getUserIDsForRole(const std::string& role_id);
void getUserDetails(const std::vector<std::string>& user_ids);

#endif
