# Cub3D 42 Network Project Readme

## Table of Contents
- [Introduction](#introduction)
- [Project Description](#project-description)
- [Parsing The MAP](#Parsing)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
  - [Raycasting Concept](#Raycasting-Concept)
  - [Mathematical Formulas](#Mathematical-Formulas)
- [Usage](#usage)
- [Controls](#controls)

---

## <span style="color:blue">Introduction</span>
Welcome to the Cub3D 42 Network Project! This project is a captivating introduction to the world of raycasting and creating a simple 3D game engine, inspired by the classic game Wolfenstein 3D. Cub3D is a part of the 42 Network's curriculum and is designed to challenge your programming skills while providing an exciting learning experience.


---

## <span style="color:blue">Project Description</span>
Cub3D is a network project that involves creating a raycasting game engine from scratch using the C programming language. The goal of this project is to build a 3D world rendered in a 2D map, where you navigate through a maze, similar to the gameplay of Wolfenstein 3D. You will be responsible for creating a game engine that can render walls, sprites, and handle player movement in a simple 3D environment.

This project covers various fundamental concepts of computer graphics and game development, such as raycasting, texture mapping, and player controls. By completing Cub3D, you will gain a solid understanding of how graphics engines work and develop strong programming skills in C.

---


## <span style="color:blue">Parsing</span>
The first part of the project involves parsing the map file that contains information about the game's configuration, such as the map layout, textures, and colors. The parsing process involves reading the map file, validating its contents, and storing the information in a data structure that can be used by the game engine.

## Getting Started

### <span style="color:blue">Prerequisites</span>
Before you start working on the Cub3D project, ensure you have the following prerequisites installed on your system:
- **C Compiler**: A C compiler like GCC.
- **Make**: The `make` build tool.
- **MinilibX**: The graphical library provided by 42 for this project.

### <span style="color:blue">Installation</span>
1. Clone the Cub3D repository to your local machine:
   ```shell
   git clone https://github.com/emohamedd/cub3D.git
   ```
   ```shell
   cd cub3d 
   ```

   ```shell
   make
   ```
   <span style="color:blue">Usage</span>
    To run the Cub3D game, execute the following command:
   ```shell
   ./cub3D path_to_map.cub
   ```
    Replace path_to_map.cub with the path to your map file. The map file contains information about the game's configuration, such as the map layout, textures, and colors.

    <span style="color:blue">Controls</span>
    W: Move forward
    A: Rotate left
    S: Move backward
    D: Rotate right
    Right Arrow: Rotate camera right
    Left Arrow: Rotate camera left
    Esc: Exit the game



## <span style="color:blue">Project Description</span>
Cub3D is a network project that involves creating a raycasting game engine from scratch using the C programming language. The goal of this project is to build a 3D world rendered in a 2D map, where you navigate through a maze, similar to the gameplay of Wolfenstein 3D. You will be responsible for creating a game engine that can render walls, sprites, and handle player movement in a simple 3D environment.

This project covers various fundamental concepts of computer graphics and game development, such as raycasting, texture mapping, and player controls. By completing Cub3D, you will gain a solid understanding of how graphics engines work and develop strong programming skills in C.

---

## Getting Started

### <span style="color:blue">Prerequisites</span>
Before you start working on the Cub3D project, ensure you have the following prerequisites installed on your system:
- **C Compiler**: A C compiler like GCC.
- **Make**: The `make` build tool.
- **MinilibX**: The graphical library provided by 42 for this project.

### <span style="color:blue">Installation</span>
1. Clone the Cub3D repository to your local machine:
   ```shell
   git clone https://github.com/your-username/cub3d.git
   cd cub3d
Compile the project using the Makefile:
shell
Copy code
make

## <span style="color:blue">Raycasting Concept</span>

Raycasting is a fundamental technique used in computer graphics to simulate 3D environments in a 2D space. In the context of Cub3D, raycasting is used to create the illusion of a 3D world within a 2D map. Here's a brief explanation of how raycasting works and where you can find related images and formulas in your project:

### How Raycasting Works

Raycasting works by simulating the path of light rays from the player's viewpoint to objects in the virtual world. In the context of Cub3D, it involves casting rays from the player's position to determine which parts of the 2D map need to be rendered as 3D.

Here's how it works:

1. **Ray Casting Algorithm**: Rays are cast from the player's viewpoint in various directions. These rays intersect with walls and other objects in the map.

   - [Image: Ray Casting Algorithm - put your image here]

2. **Collision Detection**: When a ray intersects with an object (typically a wall), the point of intersection is determined.

   - [Image: Collision Detection - put your image here]

3. **Texture Mapping**: The texture of the wall at the point of intersection is applied to create the 3D effect.

   - [Image: Texture Mapping - put your image here]

4. **Depth and Distance**: The distance to the intersected object is used to calculate the height and position on the screen, creating the illusion of depth.

   - [Image: Depth and Distance Calculation - put your image here]

5. **Rendering**: The final result is rendered on the screen, giving the appearance of a 3D world.

### Mathematical Formulas

## <span style="color:blue">Mathematical Formulas</span>
In your Cub3D project, you will encounter mathematical formulas that are used for raycasting. Here are some key formulas:

- **Distance to Wall**: The distance from the player to the wall can be calculated using trigonometry and is crucial for rendering the correct perspective. This distance often involves using the Pythagorean theorem.

  - Formula: `distance_to_wall = distance_to_point * cos(player_angle - ray_angle)`

- **Wall Height**: To determine the height of the wall on the screen, you can use the following formula:

  - Formula: `wall_height_on_screen = (wall_height / distance_to_wall) * projection_plane_distance`

- **Texture Mapping**: When applying textures to the walls, you'll use texture coordinates to sample the textures accurately.

  - Formula: `texture_x = (int)(wall_x * texture_width)`

- **Wall Columns**: The screen is divided into columns, and each column corresponds to a ray. The angle of each ray can be calculated using the following formula:

  - Formula: `ray_angle = player_angle - (FOV / 2) + (column / num_columns) * FOV`

In your project, you'll implement these concepts and formulas to achieve the raycasting effect, allowing you to render a 3D environment within the 2D map.


### <span style="color:blue">Usage</span>
2. To run the Cub3D game, execute the following command:

shell
Copy code
./cub3D path_to_map.cub
Replace path_to_map.cub with the path to your map file. The map file contains information about the game's configuration, such as the map layout, textures, and colors.

### <span style="color:blue">Controls</span>
   ## W: Move forward
   ## A: Rotate left
   ## S: Move backward
   ## D: Rotate right
   ## Right Arrow: Rotate camera right
   ## Left Arrow: Rotate camera left
   ## Esc: Exit the game
