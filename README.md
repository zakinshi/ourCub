# cub3D Project README

## Table of Contents
- 🎯 [Introduction](#introduction)  
- 🗺️ [Map Parsing](#map-parsing)  
- 🎥 [Raycasting](#raycasting)  
- 🧱 [Walls](#walls)  
- 🎨 [Textures](#textures)   
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
## Raycasting
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

### Textures
Once we have hit a wall and know its position and distance to the player, we must check which side was hit and choose the correct texture for that side of the wall. With the correct texture file and the proper height of the wall at hand it we can read pixels from the texture file at a given width and copy them to the screen, following this formula:
```c
/* Get the color from image i at the given x and y pixel */
color = my_mlx_pixel_get(i, (int)(i->width * (g->x + g->y)) % i->width, z);
```
Note: in some cases the sprite's height is smaller than the height of the sprite we have to draw. We have an algorithm that effectively 'stretches' the sprite to fit the proper height

## Installation
### Clone The Repositories
```bash
gcl https://github.com/zakinshi/cub3d.git
cd cub3d
make all
```

> ### ⚠️ **You Should Have MinilibX Installed ^_^ [Install MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)

## References
* [vinibiavatti1 - RayCastingTutoria](https://github.com/vinibiavatti1/RayCastingTutorial/wiki)
* [Lode's Tutorial Part 1](https://lodev.org/cgtutor/raycasting.html)
* [Lode's Tutorial Part 2](https://lodev.org/cgtutor/raycasting2.html)
* [Lode's Tutorial Part 3](https://lodev.org/cgtutor/raycasting3.html)
* [42docs - miniLibX](https://harm-smits.github.io/42docs/libs/minilibx)

## Summary
We built a simple 3D game in C using raycasting, just like the old Wolfenstein shooter.
With only a 2D map, [MyMate](https://github.com/Mehdi-Naam) made walls, textures,
for me I did the RayCasting Calculationd and player movement come to life in first-person.
Using MiniLibX, I rendered every frame by hand, pixel by pixel.
[Mehdi](https://github.com/Mehdi-Naam) handled parsing Map, also I Handled Wall Collisions and Math , all without external engines.
It was one of the most challenging and wonderful projects I’ve ever done.
We didn’t just code a game..
We created a world 🎮 🧱
