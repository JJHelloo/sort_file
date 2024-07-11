#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <algorithm>

// Function to extract the number at the end of the string
int extractNumber(const std::string& name) {
    std::regex re("(\\d+)$");
    std::smatch match;
    if (std::regex_search(name, match, re)) {
        return std::stoi(match.str(1));
    }
    return INT_MAX; // If no number is found, return a large number
}

// Comparator function for sorting
bool compareNames(const std::string& a, const std::string& b) {
    int numA = extractNumber(a);
    int numB = extractNumber(b);
    if (numA == numB) {
        return a < b; // If numbers are the same, sort lexicographically
    }
    return numA < numB;
}

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("sorted_output.txt");

    if (!inputFile) {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }

    if (!outputFile) {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }

    std::vector<std::string> names;
    std::string line;

    // Read names from the input file
    while (std::getline(inputFile, line)) {
        names.push_back(line);
    }

    // Sort the names based on the number at the end
    std::sort(names.begin(), names.end(), compareNames);

    // Write the sorted names to the output file
    for (const auto& name : names) {
        outputFile << name << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Sorting completed. Check 'sorted_output.txt' for the sorted names." << std::endl;

    return 0;
}
