#ifndef PARSER_H
#define PARSER_H

#include "data_structures.h"
#include <vector>
#include <string>

// Parses CSV and returns a vector of rows
std::vector<std::vector<std::string>> parseCSV(const std::string& filename);

// Loads RBAC data from CSV files
RBACData loadRBACData();

#endif // PARSER_H
