#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>
#include <cctype>


std::string normalize(const std::string& word) {
    std::string normalized;
    for (char ch : word) {
        if (std::isalpha(ch)) {
            normalized += std::tolower(ch);
        }
    }
    return normalized;
}

int main() {
    std::ifstream file("harry_potter.txt"); 
    std::string word;
    std::vector<std::string> uniqueWordsVector;
    std::set<std::string> uniqueWordsSet;


    if (!file.is_open()) {
        std::cerr << "Could not open the file!" << "\n";
        return 1;
    }


    while (file >> word) {
        std::string normalizedWord = normalize(word);


        if (!normalizedWord.empty()) {
            uniqueWordsSet.insert(normalizedWord);
        }
    }

    uniqueWordsVector.assign(uniqueWordsSet.begin(), uniqueWordsSet.end());

    std::cout << "Unique words in the set (count: " << uniqueWordsSet.size() << "):" << "\n";
    for (const auto& w : uniqueWordsSet) {
        std::cout << w << "\n";
    }

    std::cout << "\nUnique words in the vector (count: " << uniqueWordsVector.size() << "):" << "\n";
    for (const auto& w : uniqueWordsVector) {
        std::cout << w << "\n";
    }

    file.close(); 
    return 0;
}