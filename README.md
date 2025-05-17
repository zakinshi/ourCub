# cub3D Project README

## Table of Contents
- 🎯 [Introduction](#introduction)  
- 🗺️ [Map Parsing](#map-parsing)  
- 🎥 [Raycasting](#raycasting)  
- 🧱 [Walls](#walls)  
- 🎨 [Textures](#textures)  
- 🎮 [Controls](#controls)  
- ✨ [Bonus](#bonus)  
- 🚀 [Extras](#extras)  
- 🕹️ [Gameplay](#gameplay)  
- 📦 [Installation](#installation)  
- 📚 [References](#references)  
- 📝 [Summary](#summary)  

---

## Introduction
🎯 cub3D is a 3D game built with **raycasting** (Wolfenstein 3D style), done as a group project with @mbueno-g.

## Map Parsing
🗺️ Executable takes a single `.cub` file.  
Rules:
- Headers: **NO**, **SO**, **EA**, **WE** + valid `.xpm` paths  
- **F** (floor) / **C** (ceiling) colors in `R,G,B`  
- Map chars: space, `1` (wall), `0` (floor), `N/S/E/W` (player start)  
- Must be enclosed by walls; spaces allowed but must be walled in  
- Exactly one player position  

**Example:**
```text
NO textures/wall_1.xpm
SO textures/wall_2.xpm
WE textures/wall_3.xpm
EA textures/wall.xpm

F 184,113,39
C 51,198,227

     111111111  111111111111111111
     100000001  100000000000000001
     10110000111100000001111111111
11111111110000000000000000011111
10000000111100010000N00001001
100000001  100110101110000001
10000000111110000001 10100001
11111111111111111111 11111111
     
1111 111111111111111111111111
1111 1000000cococococ00000001
1111 111111111111111111111111
```
## Raycasting 🎥
Raycasting renders a 3D perspective from a 2D map by “casting” rays from the player’s viewpoint and measuring the distance to the nearest wall. That distance determines the height of each vertical slice drawn on screen.

| Attribute            | Description                                     | Value                      |
|----------------------|-------------------------------------------------|----------------------------|
| **FOV**              | Field of view of the player                     | 60º                        |
| **HFOV**             | Half of the player’s FOV                        | 30º                        |
| **Ray angle**        | Direction of player view (N=270º, S=90º, W=180º, E=0º) | Variable per ray          |
| **Ray increment**    | Angle between successive rays                   | `2 * HFOV / window_width`  |
| **Precision**        | Granularity of ray steps                        | 50                         |
| **Limit**            | Maximum view distance                           | 11                         |
| **Player’s position**| Starting point of rays (center of player square)| `(int)(x+0.5), (int)(y+0.5)` |

### Algorithm Steps
1. **Initialize** all attributes (FOV, HFOV, ray angle, increment, precision, limit, player pos).  
2. **For each ray** across the screen (window_width rays):
   - Compute direction:  
     ```c
     ray_cos = cos(deg_to_rad(ray_angle)) / precision;
     ray_sin = sin(deg_to_rad(ray_angle)) / precision;
     ```
   - **Step** forward until hitting a wall or reaching limit:  
     ```c
     ray.x += ray_cos;
     ray.y += ray_sin;
     ```
3. **Compute distance** from player to hit point: 
```c
   distance = sqrt((ray.x - player.x - 0.5)² + (ray.y - player.y - 0.5)²);
```

4. **Fix fisheye** distortion: 
```c
  distance *= cos(deg_to_rad(ray_angle - player_view_angle));
```

5. **Calculate wall height** for rendering:
```c
  wall_height = window_height / (1.5 * distance);
```
