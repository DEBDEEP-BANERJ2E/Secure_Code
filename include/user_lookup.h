#ifndef USER_LOOKUP_H
#define USER_LOOKUP_H

#include <vector>
#include <string>

// Function to get all USER_IDs associated with a ROLE_ID
std::vector<std::string> getUserIDsForRole(const std::string& role_id);

// Function to retrieve and print user details based on USER_IDs
void getUserDetails(const std::vector<std::string>& user_ids);

#endif // USER_LOOKUP_H
