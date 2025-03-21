#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <string>
#include <vector>
#include <unordered_map>

// User information
struct User {
    std::string user_id;
    std::string user_name;
    bool suspended;
};

// User-to-Role Mapping
struct UserRole {
    std::string user_id;
    std::string role_id;
};

// Role information
struct Role {
    std::string role_id;
    std::string role_name;
};

// Role Hierarchy (Parent-Child Role Relationship)
struct RoleHierarchy {
    std::string child_role_id;
    std::string parent_role_id;
};

// Privilege to Role Mapping
struct RolePrivilege {
    std::string role_id;
    std::string privilege_id;
};

// Privilege Details
struct Privilege {
    std::string privilege_id;
    std::string name;
};

// Entitlement Details
struct Entitlement {
    std::string access_point_id;
    std::string privilege_id;
};

// Function to store mappings for fast access
struct RBACData {
    std::unordered_map<std::string, std::vector<std::string>> role_to_users;
    std::unordered_map<std::string, std::vector<std::string>> privilege_to_roles;
    std::unordered_map<std::string, std::string> entitlement_to_privilege;
};

#endif // DATA_STRUCTURES_H
