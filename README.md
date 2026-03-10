#  CoreML-lite: High-Performance C++ Neural Engine

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-11%2F14%2F17-blue.svg?style=for-the-badge&logo=c%2B%2B" />
  <img src="https://img.shields.io/badge/Platform-Embedded%20%7C%20Linux%20%7C%20Windows-lightgrey?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Milestone-50%25%20Completed-green?style=for-the-badge" />
</p>

---

### 📖 Overview
**CoreML-lite** is a specialized, header-only C++ library built from the ground up for **Edge AI** and **Embedded Intelligence**. It bridges the gap between raw electrical signals (Voltage, Current, RPM) and real-time decision-making in **EEE (Electrical Engineering)** systems like Smart Grids and Drones.

---

### 🛠️ Core Architecture

| Module | Component | Description |
| :--- | :--- | :--- |
| **Linear Algebra** | `linalg/Matrix.h` | Optimized Matrix engine for dot products & weight initialization. |
| **Data Processing** | `processing/DataFrame.h` | Fast CSV parsing and Feature Scaling (Min-Max Normalization). |
| **Neural Ops** | `Activation Functions` | Implementation of ReLU, Sigmoid, and Numerically Stable Softmax. |

---

### 🧩 Key Features (50% Milestone)

> [!IMPORTANT]
> **Optimized for Embedded Hardware:** Designed to run on resource-constrained devices like **STM32, ESP32, and Allwinner H313**.

#### 1️⃣ Intelligent Data Ingestion
- **EmoPandas:** A custom CSV loader that handles sensor logs with high efficiency.
- **Normalization:** Converts raw signals (e.g., 230V) into a [0, 1] range for stable training.



#### 2️⃣ Robust Matrix Engine
- Contiguous memory allocation for **cache-friendly** performance.
- Built-in **Weight Randomization** using `<random>` for better convergence.



#### 3️⃣ Activation Layer
- **Sigmoid:** For binary decision-making (e.g., Fault Detection).
- **ReLU:** For high-speed hidden layer processing.
- **Softmax:** Multi-class classification with overflow protection.

---

### 💻 Live Demo Output

```bash
# Running the 50% Milestone Test
[Step 1] Loading CSV Data... Done (6 rows)
[Step 2] Normalizing 'voltage'... Success [0, 1]
[Step 3] Converting to Matrix... Done
[Step 4] Initializing Weights... Random (-1.0 to 1.0)
[Step 5] Sigmoid Activation... Operational!

```
---

## 🗺️ Development Roadmap to v1.0.0

| Phase | Milestone | Features | Status |
| :--- | :--- | :--- | :---: |
| **Phase 1** | **Foundation (50%)** | Matrix Core, CSV Ingestion, Activation Hub | ✅ Done |
| **Phase 2** | **Neural Layers (70%)** | Dense Layers & Forward Propagation | 🚧 WIP |
| **Phase 3** | **Training Logic (90%)** | Backpropagation & Loss Functions (MSE/Cross-Entropy) | 📅 Planned |
| **Phase 4** | **Edge Optimized (100%)** | Quantization & STM32/Embedded Integration | 🚀 Future |



---

## 🔌 Hardware Compatibility & Ecosystem

CoreML-lite is engineered for cross-platform efficiency, with a special focus on ARM-based SBCs and Microcontrollers.

> [!TIP]
> **Optimized Performance:** Best performance is observed on ARM Cortex-A7 series (Allwinner H313/H616) using `g++` with `-O3` optimization.

### 🖥️ Desktop Support
- **Windows:** Supported via MinGW-w64 / MSYS2
- **Linux:** Native support for GCC/Clang (Tested on Ubuntu/Debian)

### 🛸 Edge Devices (Fully Supported)
- **Allwinner H313/H616:** (e.g., TV Boxes, Orange Pi Zero 2)
- **Raspberry Pi:** 3, 4, and Zero 2W
- **Armbian-based systems:** Optimized for lightweight Linux distros.

### ⚙️ Microcontrollers (MCUs) - *In Development*
- **ESP32:** Support for ESP-IDF C++ compiler.
- **STM32:** Future integration with CMSIS-DSP for hardware acceleration.



---

## 🤝 Contributing & Community

Whether you are an **Electrical Engineer** or a **Software Developer**, your contributions can make CoreML-lite better!

1. **Fork** the repository.
2. Create a **Feature Branch** (`git checkout -b feature/NewFeature`).
3. **Commit** your changes (`git commit -m 'Add some NewFeature'`).
4. **Push** to the branch (`git push origin feature/NewFeature`).
5. Open a **Pull Request**.

---

## 👤 Author
**Md Shahariar Khan Emon**
*Undergraduate Student in Electrical & Electronic Engineering (EEE)*
*University of Chittagong*

<p align="left">
  <a href="https://linkedin.com/in/md-shahariar-khan-emon-8758a3327" target="_blank">
    <img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" />
  </a>
  <a href="mailto:emon23702036@gmail.com">
    <img src="https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white" />
  </a>
</p>

---
