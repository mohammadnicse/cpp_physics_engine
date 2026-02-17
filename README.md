# ⚙️ C++ Physics-Logic Engine (2D)

A custom-built 2D physics and logic framework developed in C++. Designed to demonstrate the underlying architecture of high-fidelity simulators, bypassing commercial engines to focus on raw mathematical processing and memory efficiency. 

## 🏗️ Technical Architecture
* **Core Simulation Loop:** A continuous game loop processing state updates, physics calculations, and simulated rendering.
* **Collision Detection (AABB):** Custom mathematical implementation of Axis-Aligned Bounding Box algorithms to calculate object intersection.
* **High-Performance Memory Pool:** A custom memory allocator designed to recycle object memory, preventing heap fragmentation and frame-rate drops during rapid entity generation.
* **Strict OOP Design:** Modular architecture allowing for scalable simulation rules.