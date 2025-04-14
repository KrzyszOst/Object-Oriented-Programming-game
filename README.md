# 🌍 2D Virtual World Simulator (OOP Project - C++ version) 🧬

This is a C++ project created for the **Object-Oriented Programming** course.  
The goal was to implement a turn-based simulation of a 2D virtual world filled with diverse life forms, each following unique rules of behavior.

## 🧠 Key Concepts

- ✅ Object-oriented architecture
- 🐾 Animals & 🌱 Plants inherit from abstract base class `Organism`
- 🎮 Player-controlled `Human` with a **special ability**
- ⏱️ Turn-based simulation with **initiative & age-based** action order
- 💥 Collision logic between organisms (fight, reproduction, reflection, etc.)
- 💾 Save & Load system (optional for higher score)
- 🖥️ ASCII-based console rendering of the world

## 🦁 Implemented Life Forms

### 🐾 Animals:
- **Wolf** — strong and aggressive  
- **Sheep** — basic passive creature  
- **Fox** — avoids stronger opponents  
- **Turtle** — moves rarely, reflects weak attacks  
- **Antelope** — moves 2 cells, can flee fights  
- **Cyber-sheep** — seeks out and destroys Sosnowsky's hogweed  

### 🌱 Plants:
- **Grass** — default behavior  
- **Sow Thistle** — tries to spread 3 times per turn  
- **Guarana** — boosts strength of the eater  
- **Belladonna** — instantly kills any animal that eats it  
- **Sosnowsky's Hogweed** — kills adjacent animals except cyber-sheep  

## 🧍 Human Features

- Controlled with **arrow keys**
- Has a **special ability** (e.g. immortality, magical potion, speed boost, etc.)
- Ability lasts **5 turns**, cooldown: **5 turns**
- Only one human can exist on the map

## 🎮 Gameplay Summary

- Simulation runs in **turns**
- Each organism acts in order based on **initiative and age**
- Organisms may move, fight, reproduce, or interact with plants
- Results are printed to the console after each turn

## 🧱 Installation & Run

Make sure you have a working **C++ environment** (like g++, Visual Studio, or Code::Blocks).

```bash
git clone https://github.com/yourusername/oop-world-simulator.git
cd oop-world-simulator
g++ *.cpp -o simulator -std=c++11
./simulator
