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
*(Pro-tip: Upload that awesome amber torch light screenshot you showed me here!)*
![Raycasting Demo](link_to_your_screenshot_image.png)
