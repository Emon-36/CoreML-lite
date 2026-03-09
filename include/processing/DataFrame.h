#ifndef COREML_DATAFRAME_H
#define COREML_DATAFRAME_H

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "../linalg/Matrix.h" 

namespace Emo {
    class DataFrame {
    public:
       
        std::map<std::string, std::vector<float>> columns;
        std::vector<std::string> header;

        
        void read_csv(const std::string& filename) {
            std::ifstream file(filename);
            if (!file.is_open()) {
                std::cerr << "Error: Could not open " << filename << ". Check file path!" << std::endl;
                return;
            }

            std::string line, word;
            header.clear();
            columns.clear();

            
            if (std::getline(file, line)) {
                std::stringstream ss(line);
                while (std::getline(ss, word, ',')) {
                   
                    word.erase(std::remove(word.begin(), word.end(), '\r'), word.end());
                    word.erase(std::remove(word.begin(), word.end(), '\n'), word.end());
                    
                    header.push_back(word);
                    columns[word] = std::vector<float>();
                }
            }

         
            while (std::getline(file, line)) {
                std::stringstream ss(line);
                int col_idx = 0;
                while (std::getline(ss, word, ',')) {
                    if (col_idx < header.size()) {
                        try {
                            columns[header[col_idx]].push_back(std::stof(word));
                        } catch (...) {
                            columns[header[col_idx]].push_back(0.0f); 
                        }
                    }
                    col_idx++;
                }
            }
            file.close();
            std::cout << "Successfully loaded " << columns[header[0]].size() << " rows into EmoPandas." << std::endl;
        }

       
        void head(int n = 5) {
            if (header.empty()) {
                std::cout << "DataFrame is empty!" << std::endl;
                return;
            }
            for (const auto& h : header) std::cout << h << "\t";
            std::cout << "\n------------------------------------------" << std::endl;
            
            int rows_to_show = std::min((int)columns[header[0]].size(), n);
            for (int i = 0; i < rows_to_show; ++i) {
                for (const auto& h : header) {
                    std::cout << columns[h][i] << "\t";
                }
                std::cout << std::endl;
            }
        }

        
        Matrix to_matrix(const std::string& col_name) {
            if (columns.find(col_name) == columns.end()) {
                throw std::runtime_error("Column '" + col_name + "' not found!");
            }
            int num_rows = columns[col_name].size();
            Matrix mat(num_rows, 1);
            for (int i = 0; i < num_rows; ++i) {
                mat(i, 0) = columns[col_name][i];
            }
            return mat;
        }

       
       void normalize(const std::string& col_name) {
   
            if (columns.find(col_name) == columns.end() || columns[col_name].empty()) {
                 std::cerr << "Column '" << col_name << "' not found or empty!" << std::endl;
                 return;
            }

    
            auto min_it = std::min_element(columns[col_name].begin(), columns[col_name].end());
            auto max_it = std::max_element(columns[col_name].begin(), columns[col_name].end());
    
            float min_val = *min_it;
            float max_val = *max_it;

            float range = max_val - min_val;
            if (range == 0) return;

    
            for (float& val : columns[col_name]) {
                 val = (val - min_val) / range;
            }
    
            std::cout << "Column '" << col_name << "' normalized to [0, 1] range." << std::endl;
        }
    };
}

#endif