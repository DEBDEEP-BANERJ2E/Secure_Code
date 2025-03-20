#include "parser.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<RoleAssignment> parseCSV(const std::string& filename) {
    std::vector<RoleAssignment> assignments;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return assignments;
    }

    std::string line;
    bool firstLine = true; // To skip the header

    while (std::getline(file, line)) {
        if (firstLine) {
            firstLine = false;
            continue;  // Skip the header row
        }

        std::stringstream ss(line);
        std::string user, role;

        std::getline(ss, user, ',');  // Read first column
        std::getline(ss, role, ',');  // Read second column

        assignments.push_back({user, role});
    }

    file.close();
    return assignments;
}
