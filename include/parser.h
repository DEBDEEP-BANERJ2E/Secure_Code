#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>

// Structure to hold user-role mappings
struct RoleAssignment {
    std::string user;
    std::string role;
};

// Function to parse a CSV file
std::vector<RoleAssignment> parseCSV(const std::string& filename);

#endif // PARSER_H
