#ifndef _FILEGEN_H_
#define _FILEGEN_H_


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

// simple textfile generating
void generate_sample_files() 
{
    std::ofstream f1("data_1.txt");
    f1 << "Hello world! Hello C++!";
    f1.close();
    
    std::ofstream f2("data_2.txt");
    f2 << "Test text. Another test.";
    f2.close();
}


// textfile generating
void i_generate_sample_files(const std::string& path_to_file, int number_of_files) {
    // reading text from file
    std::ifstream source_file(path_to_file);
    if (!source_file.is_open()) {
        std::cerr << "File open ERROR: " << path_to_file << std::endl;
        return;
    }
    
    std::string content((std::istreambuf_iterator<char>(source_file)),
                       std::istreambuf_iterator<char>());
    source_file.close();
    
    if (content.empty()) {
        std::cerr << "File is EMPTY or doesn't contains text" << std::endl;
        return;
    }
    
    // dividing into words
    std::vector<std::string> words;
    std::string word;
    for (char c : content) {
        if (std::isalpha(c) || c == '\'') {
            word += c;
        } else {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
            if (c != ' ' && c != '\n' && c != '\t') {
                words.push_back(std::string(1, c));
            }
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    
    if (words.empty()) {
        std::cerr << "Problem to retrieve words from FILE" << std::endl;
        return;
    }
    
    // random numbers generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(10, 50);
    
    std::uniform_int_distribution<> word_dis(0, words.size() - 1);
    
    // files generation
    for (int i = 1; i <= number_of_files; ++i) {
        std::string filename = "data_" + std::to_string(i) + ".txt";
        std::ofstream out_file(filename);
        
        if (!out_file.is_open()) {
            std::cerr << "File creating ERROR: " << filename << std::endl;
            continue;
        }
        
        // random text generation
        int word_count = dis(gen);
        for (int j = 0; j < word_count; ++j) {
            int random_index = word_dis(gen);
            out_file << words[random_index];
            
            if (j < word_count - 1) {
                std::uniform_int_distribution<> punct_dis(1, 8);
                int punct_chance = punct_dis(gen);
                
                if (punct_chance == 1) out_file << ".\n";
                else if (punct_chance <= 3) out_file << ", ";
                else out_file << " ";
            }
        }
        
        out_file << ".";
        out_file.close();
        
        std::cout << "File was created: " << filename 
                  << " (words: " << word_count << ")" << std::endl;
    }
    
    std::cout << "Creating succses " << number_of_files 
              << " files from text: " << path_to_file << std::endl;
}


#endif