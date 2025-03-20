#include "utils.h"
#include <iostream>

// Loads predefined SoD conflict rules
std::unordered_map<std::string, std::unordered_set<std::string>> loadConflictRules() {
    std::unordered_map<std::string, std::unordered_set<std::string>> conflicts;

    // Define conflicting roles manually or load from a file
    conflicts["Admin"].insert("Auditor");
    conflicts["Finance"].insert("Purchasing");
    
    return conflicts;
}
