#ifndef COREML_MATRIX_H
#define COREML_MATRIX_H
#include <vector>
#include<iostream>
#include <cmath>
#include <random>

namespace Emo
{
    class Matrix
    {
     public:
     int rows, cols;
     std::vector<float> data;

        Matrix(int r, int c) : rows(r), cols(c), data(r * c, 0.0f) {
            data.resize(rows * cols);
        };
            float& operator()(int r, int c) {
            return data[r * cols + c];
        }
        void print() {
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    std::cout << (*this)(i, j) << " ";
                }
                std::cout << std::endl;
            }
        }

       

        Matrix dot(const Matrix& other) const {
              if (this->cols != other.rows) {
        throw std::invalid_argument("Matrix dimensions mismatch for dot product!");
        }

           Matrix result(this->rows, other.cols);
               for (int i = 0; i < this->rows; ++i) {
                    for (int k = 0; k < this->cols; ++k) { 
                       float temp = data[i * cols + k];
                             for (int j = 0; j < other.cols; ++j) {
                                 result.data[i * result.cols + j] += temp * other.data[k * other.cols + j];
                         }
                    }
                 }
                return result;
        }


        Matrix transpose() const {
             Matrix result(cols, rows);
                 for (int i = 0; i < rows; ++i) {
                     for (int j = 0; j < cols; ++j) {
                         result(j, i) = data[i * cols + j];
                      }
                 }
             return result;
        }

       
        void addBias(const Matrix& biasMat) {
             if (this->rows != biasMat.rows || biasMat.cols != 1) {
             throw std::invalid_argument("Bias dimensions must match output rows!");
             }
            for (int i = 0; i < rows; ++i) {
                 for (int j = 0; j < cols; ++j) {
                     data[i * cols + j] += biasMat.data[i];
                }
            }
        }

        void relu() {
            for (float& val : data) {
             val = (val > 0) ? val : 0;
            }
        }

        void sigmoid() {
            for (float& val : data) {
            val = 1.0f / (1.0f + std::exp(-val));
         }
        }

        void softmax() {
            std::vector<float> expData(data.size());
            float sumExp = 0.0f;
            for (size_t i = 0; i < data.size(); ++i) {
                expData[i] = std::exp(data[i]);
                sumExp += expData[i];
            }
            for (size_t i = 0; i < data.size(); ++i) {
                data[i] = expData[i] / sumExp;
            }
        }

        void fillRandom(float min = -1.0f, float max = 1.0f) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<float> dis(min, max);

    
            for (float& val : data) {
              val = dis(gen);
           }
        }


    };
    
   
    
} // namespace Emo




#endif