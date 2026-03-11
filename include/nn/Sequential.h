#ifndef COREML_SEQUENTIAL_H
#define COREML_SEQUENTIAL_H
#include "Layer.h"
#include <vector>
#include <iostream>

namespace Emo
{
    class Sequential{
        private:
        std::vector<DenseLayer*> layers;
        public:
        void addLayer(DenseLayer* layer) {
            layers.push_back(layer);
        }
        Matrix predict(const Matrix& input) {
            Matrix output = input;
            for (DenseLayer* layer : layers) {
                output = layer->forward(output);
            }
            return output;
        }
        void summary() const {
            std::cout << "Model Summary [Sequential]" << std::endl;
            std::cout << "Total Layers: " << layers.size() << std::endl;
            std::cout << "------------------------------------" << std::endl;
            for (size_t i = 0; i < layers.size(); ++i) {
                std::cout << "Layer " << i + 1 << ":" << std::endl;
                layers[i]->summary();
            }
        }
            ~Sequential() {
                for (DenseLayer* layer : layers) {
                    delete layer;
                }
            }
    };
} // namespace Emo


#endif // COREML_SEQUENTIAL_H