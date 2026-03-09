#include <iostream>
#include "CoreML-lite.h" // আপনার মাস্টার হেডার

int main() {
    try {
        std::cout << "=== CoreML-lite 50% Milestone Test ===" << std::endl;

        // ধাপ ১: EmoPandas দিয়ে ডাটা লোড করা
        Emo::DataFrame df;
        std::cout << "\n[Step 1] Loading CSV Data..." << std::endl;
        df.read_csv("../sensor_data.csv"); // আপনার ফাইল পাথ চেক করুন
        
        std::cout << "Original Data (First 3 rows):" << std::endl;
        df.head(3);

        // ধাপ ২: Data Normalization (০ থেকে ১ এর মধ্যে আনা)
        std::cout << "\n[Step 2] Normalizing 'voltage' column..." << std::endl;
        df.normalize("voltage");
        
        std::cout << "Normalized Data (First 3 rows):" << std::endl;
        df.head(3);

        // ধাপ ৩: কলাম থেকে Matrix এ রূপান্তর
        std::cout << "\n[Step 3] Converting normalized voltage to Matrix..." << std::endl;
        Emo::Matrix v_mat = df.to_matrix("voltage");
        v_mat.print();

        // ধাপ ৪: Weight Initialization (র‍্যান্ডম ওয়েট তৈরি)
        std::cout << "\n[Step 4] Creating a 3x1 Weight Matrix with Random Values..." << std::endl;
        Emo::Matrix weights(3, 1);
        weights.fillRandom(-1.0f, 1.0f); // -১ থেকে ১ এর মধ্যে র‍্যান্ডম ভ্যালু
        weights.print();

        // ধাপ ৫: Activation Function Test (Sigmoid)
        std::cout << "\n[Step 5] Testing Sigmoid Activation on Weights..." << std::endl;
        weights.sigmoid(); // আপনার লেখা সিগময়েড ফাংশন
        weights.print();

        std::cout << "\n[SUCCESS] All systems are operational! Ready for Repo Upload." << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Test Failed! Error: " << e.what() << std::endl;
    }

    return 0;
}