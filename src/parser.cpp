#include "parser.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Reads a CSV file and returns a vector of rows
std::vector<std::vector<std::string>> parseCSV(const std::string& filename) {
    std::vector<std::vector<std::string>> data;
    std::ifstream file("../csv_input/" + filename);

    if (!file.is_open()) {
        std::cerr << "❌ Error: Cannot open file " << filename << "\n";
        return data;
    }

    std::string line;
    bool firstLine = true;

    while (std::getline(file, line)) {
        if (firstLine) { firstLine = false; continue; }  // Skip header

        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        data.push_back(row);
    }

    file.close();
    return data;
}
