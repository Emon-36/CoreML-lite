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
        DenseLayer(int in_size, int out_size, std::string act="relu");
       
    };
    
   
    
}





#endif
