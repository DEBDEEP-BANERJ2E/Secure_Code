#ifndef SOD_CHECKER_H
#define SOD_CHECKER_H

#include "data_structures.h"
#include <unordered_set>

// Finds users who have access to a given ACCESS_POINT_ID
std::unordered_set<std::string> getUsersWithAccess(
    const std::string& access_point_id,
    const RBACData& rbac_data
);

#endif // SOD_CHECKER_H
