#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>

// Function to parse CSV files and return data as a vector of vectors
std::vector<std::vector<std::string>> parseCSV(const std::string& filename);

#endif // PARSER_H
