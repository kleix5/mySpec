#include "filegen.h"
#include "process.h"
#include <regex>
#include <filesystem>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>



int main() 
{
    int amount_of_files;

    std::cout << "Type the amount of files 'data_n.txt' to generate: ";
    std::cin>>amount_of_files; 

    i_generate_sample_files("source.txt", amount_of_files);


    // Регулярное выражение для поиска файлов data_n.txt
    std::regex data_pattern("data_(\\d+)\\.txt");
    std::vector<std::pair<int, std::string>> data_files;
    
    // Поиск файлов в текущей директории
    for (const auto& entry : fs::directory_iterator(".")) {
        std::string filename = entry.path().filename().string();
        int num = extract_number(filename, data_pattern);
        if (num != -1) {
            data_files.push_back({num, filename});
        }
    }
    
    // Сортировка файлов по номеру
    std::sort(data_files.begin(), data_files.end());
    
    // Обработка каждого найденного файла
    for (const auto& [number, filename] : data_files) {
        // Чтение файла
        std::ifstream input_file(filename);
        if (!input_file.is_open()) {
            std::cerr << "File open ERROR: " << filename << std::endl;
            continue;
        }
        
        std::string content((std::istreambuf_iterator<char>(input_file)),
                            std::istreambuf_iterator<char>());
        input_file.close();
        
        // Подсчет слов
        auto word_count = count_words(content);
        
        // Генерация имени для файла результата
        std::string result_filename = generate_result_name(number);
        
        // Запись результатов
        std::ofstream output_file(result_filename);
        if (!output_file.is_open()) {
            std::cerr << "File creating ERROR: " << result_filename << std::endl;
            continue;
        }
        
        for (const auto& [word, count] : word_count) {
            output_file << word << ":" << count << std::endl;
        }
        output_file.close();
        
        std::cout << "File was processed: " << filename 
                  << ". RESULT was saved in: " << result_filename << std::endl;
    }
    
    return 0;
}
