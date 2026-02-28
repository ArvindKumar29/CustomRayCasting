# 🔦 Custom 2D Raycasting & Shadow Engine

A custom-built 2D Raycasting and dynamic shadow-casting engine developed completely from scratch using **C++** and **SFML**. 

Instead of relying on pre-built physics or lighting engines, this project demonstrates core math, geometry intersection, and rendering algorithms to create real-time dynamic lighting, similar to the foundational mechanics of classic games like *Amnesia* or early stealth titles.

## ✨ Key Features
* **Custom Mathematics:** Implemented raw Pythagorean distance calculations and Trigonometry (`std::atan2`, `cos`, `sin`) for accurate ray projections.
* **The "Corner Peek" Algorithm:** Optimized shadow casting by shooting rays precisely at geometry vertices with a `±0.0001f` radian offset to generate infinite, sharp hard-shadows behind obstacles.
* **Dynamic Polygon Rendering:** Utilized `sf::TriangleFan` and angle-based sorting to generate smooth, filled light cones without overlapping artifacts.
* **Level Parsing:** Reads environmental data (walls and boundaries) dynamically from a custom `Level.txt` file format.

## 🛠️ Tech Stack
* **Language:** C++
* **Graphics Library:** SFML (Simple and Fast Multimedia Library)
* **Architecture:** Custom Entity & Physics logic (No external game engines used)

## 🎮 How to Run
1. Clone this repository to your local machine.
2. Ensure you have **Visual Studio** and **SFML** properly configured.
3. Open the `.sln` file and build the project in `Debug` or `Release` mode (x64).
4. Run the executable. 
5. Move your mouse to control the light source and observe the dynamic shadows!

## 📸 Screenshots
<img width="1913" height="1080" alt="image" src="https://github.com/user-attachments/assets/b7010ffa-21c0-48aa-9552-e7674ce478bf" />

A screenshot and video of an instance in the raycasting system with rays emmitting from the cursor...

[Uploading DEMO.mp4…](https://github.com/user-attachments/assets/5699a82d-d2d8-4cff-8748-fd1f68e82cbe)
