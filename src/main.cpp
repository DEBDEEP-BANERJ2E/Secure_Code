#include "parser.h"
#include <iostream>
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    
    std::string inputFile = "csv_input/data.csv";  // Use CSV file instead of XLSX
    std::vector<RoleAssignment> assignments = parseCSV(inputFile);
    
    std::cout << "Loaded " << assignments.size() << " role assignments." << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Process completed in " << duration.count() << " seconds." << std::endl;
    
    return 0;
}
