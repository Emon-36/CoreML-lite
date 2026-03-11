#include <iostream>
#include "CoreML-lite.h"

int main() {
    std::cout << "--- CoreML-lite: Deep Neural Network Test ---" << std::endl;

    // ১. একটি Sequential মডেল তৈরি (The Brain Cabinet)
    Emo::Sequential model;

    // ২. লেয়ার যোগ করা (Stacking the Layers)
    // Input(3) -> Hidden1(8) -> Hidden2(4) -> Output(1)
    model.addLayer(new Emo::DenseLayer(3, 8, "relu"));
    model.addLayer(new Emo::DenseLayer(8, 4, "relu"));
    model.addLayer(new Emo::DenseLayer(4, 1, "sigmoid")); // আউটপুট হবে ০ থেকে ১ এর মধ্যে

    // ৩. মডেলের সামারি দেখা
    model.summary();

    // ৪. ইনপুট সিগন্যাল (যেমন: ৩টি সেন্সর ডাটা)
    Emo::Matrix input(3, 1);
    input.fillNormal(0.5f, 0.2f); // আপনার তৈরি করা বেল কার্ভ ফাংশন

    std::cout << "\n[Input Sensors]:" << std::endl;
    input.print();

    // ৫. প্রসেসিং (Forward Pass through all layers)
    Emo::Matrix prediction = model.predict(input);

    // ৬. ফাইনাল রেজাল্ট
    std::cout << "\n[Final Brain Prediction (0 to 1)]:" << std::endl;
    prediction.print();

    return 0;
}