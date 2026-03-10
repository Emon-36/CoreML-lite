#ifndef COREML_LAYER_H
#define COREML_LAYER_H

#include "../linalg/Matrix.h"
#include<string>
#include<iostream>

namespace Emo {
    class DenseLayer
    {
    private:
        std::string activation;
    public:
        Matrix weights;
        Matrix bias;
        DenseLayer(int in_size, int out_size, std::string act="relu")
        :weights(out_size, in_size), bias(out_size, 1), activation(act) {
            this->weights.fillRandom(-1.0f, 1.0f);
            this->bias.fillRandom(-1.0f, 1.0f);
        }

        Matrix forward(const Matrix& input) {
            Matrix output = this->weights.dot(input);
            output.addBias(this->bias);
            if (activation == "relu") {
                output.relu();
            } else if (activation == "sigmoid") {
                output.sigmoid();
            } else if (activation == "sigmoid") {
                output.sigmoid();
            }

            return output;
        }

        
       
    };
    
   
    
}





#endif
