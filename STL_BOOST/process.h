#ifndef _PROCESS_H_
#define _PROCESS_H_


#include <iostream>
#include <fstream>
#include <regex>
#include <filesystem>
#include <map>
#include <algorithm>

namespace fs = std::filesystem;

// retrieving number from filename
int extract_number(const std::string& filename, const std::regex& pattern) {
    std::smatch match;
    if (std::regex_search(filename, match, pattern)) {
        return std::stoi(match[1]);
    }
    return -1;
}

// words counting from text
std::map<std::string, int> count_words(const std::string& text) {
    std::map<std::string, int> word_count;
    std::regex word_regex("[a-zA-Z]+");
    
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
    auto words_end = std::sregex_iterator();
    
    for (auto it = words_begin; it != words_end; ++it) {
        std::string word = it->str();
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        word_count[word]++;
    }
    
    return word_count;
}

// result name generating
std::string generate_result_name(int n) {
    std::string base_name = "result_" + std::to_string(n) + ".txt";
    if (!fs::exists(base_name)) {
        return base_name;
    }
    
    int new_number = n + 1;
    while (fs::exists("result_" + std::to_string(new_number) + ".txt")) {
        new_number++;
    }
    return "result_" + std::to_string(new_number) + ".txt";
}

#endif