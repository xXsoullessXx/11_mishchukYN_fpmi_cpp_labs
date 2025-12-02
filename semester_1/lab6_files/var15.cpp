#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

std::set<char> getCharacterSet(const std::string& word) {
    std::set<char> chars;
    for (char c : word) {
        chars.insert(c);
    }
    return chars;
}


int main() {
    const std::string inputFile = "input.txt";

    std::ifstream input(inputFile);
    if (!input.is_open()) {
        std::cerr << "Error: Could not open file " << inputFile << std::endl;
        return 1;
    }

    std::string word;

    std::set< std::set<char> >wordSet;

    while (input >> word) {
        std::set<char> chars = getCharacterSet(word);
        wordSet.insert(chars);
    }

    std::cout << "Number of unique character sets: " << wordSet.size() << std::endl;



    return 0;
}