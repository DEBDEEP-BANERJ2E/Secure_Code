#ifndef SOD_CHECKER_H
#define SOD_CHECKER_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "parser.h"  // Include parser.h for RoleAssignment

// Define Hierarchy structure
struct Hierarchy {
    std::unordered_map<std::string, std::vector<std::string>> roleHierarchy;
};

// Define ConflictMatrix structure
struct ConflictMatrix {
    std::unordered_map<std::string, std::vector<std::string>> conflicts;
};

// Function prototypes
Hierarchy buildHierarchy(const std::vector<RoleAssignment>& assignments);
ConflictMatrix detectConflicts(const Hierarchy& hierarchy);

#endif // SOD_CHECKER_H
