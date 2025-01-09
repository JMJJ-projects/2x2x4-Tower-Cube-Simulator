# 3D Tower Simulation

> **A simulation of a 2x2x4 Tower Cube, with spatial and pattern modes to visualize and manipulate a 3D object.**

---

## 🌟 Highlights

- Simulates a 3D Tower Cube.
- Allows rotation of planes along different axes.
- Provides both spatial and pattern modes for visualization.
- Easy-to-understand representation of how rotations affect the tower.

---

## ℹ️ Overview

This project simulates a 3D Tower Cube, specifically a 2x2x4 Tower, and allows the user to rotate planes along the x, y, or z axes. I created this because I noticed not many people have tried capturing the actual complexity of a shapeshifting Rubik's Cube. Most programs that simulate the 2x2x4 Tower Cube disallow users from making half-turns on the side faces. It includes two modes: **Spatial Mode** to show the positions of blocks in the space, and **Pattern Mode** to show how the stickers on each block change during rotations. This project is useful for visualizing and manipulating 3D objects with a Rubik’s Cube-like rotation system.

### ✍️ Author
**John-Michael JENY JEYARAJ**
- [GitHub Profile](https://github.com/JMJJ-projects)
- [LinkedIn Profile](https://www.linkedin.com/in/jmjj/)

---

## 🚀 Usage

1. Compile and run the program.
2. Choose between **Spatial Mode** and **Pattern Mode** to visualize and rotate the cube.
3. In each mode, you can rotate the cube along the x, y, or z axis, and on any of the four planes.
4. You can switch between modes or quit the program at any time.

```bash
gcc -o tower_simulation tower_simulation.c
./tower_simulation
```

---

## ⬇️ Installation

This program requires a C compiler (e.g., GCC) to build and run. Here are the installation steps:

1. Clone the repository or download the source code.
2. Compile the C file:

```bash
gcc -o tower_simulation tower_simulation.c
```

3. Run the program:

```bash
./tower_simulation
```

---

## 💭 Feedback

Feedback is welcome! Please open issues for bugs, feature requests, or any questions. If you'd like to contribute, feel free to fork the repository and create pull requests.

- **Discussions**: [Link to Discussions](https://github.com/2x2x4-Tower-Cube-Simulator/discussions)

---

## 🎮 Modes

### Spatial Mode

- Shows the positions of the blocks in the 4x4x4 space.
- Visualizes the blocks as coordinate points.
- Rotates planes along the x, y, or z axes and displays the changes in the space.

### Pattern Mode

- Displays the stickers on each side of the blocks, showing how the stickers are oriented.
- Ideal for visualizing how the cube's patterns change when rotating.

---

## 🔄 Rotation Controls

In both modes, you can perform rotations on any plane of the cube:

- **Axis**: Choose 'x', 'y', or 'z' to specify the axis of rotation.
- **Plane**: Choose a plane number (0, 1, 2, or 3) to rotate.
