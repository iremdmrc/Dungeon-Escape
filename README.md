# Dungeon Escape

Dungeon Escape is a first-person puzzle game developed with **Unreal Engine 5 and C++**.

The player explores a dungeon environment, collects items, interacts with objects, unlocks doors, and solves environmental puzzles to escape.

## Gameplay

Players must explore the dungeon and interact with their surroundings to progress through the level. The game includes collectible objects, locks, pressure plates, moving objects, and environmental interactions.

## Features

- First-person exploration
- C++ interaction system
- Collectable item system
- Lock and key mechanics
- Pressure plate interactions
- Moving doors and platforms
- Collision and overlap detection
- Actor tags and object detection
- Custom Actor Components
- C++ and Blueprint integration

## Technologies

- Unreal Engine 5
- C++
- Blueprint Visual Scripting
- Visual Studio
- Git & GitHub
- Git LFS

## Technical Implementation

The project uses custom Unreal Engine C++ components and actors to create reusable gameplay systems.

### Interaction System
The player can detect and interact with nearby objects using Unreal Engine collision queries and sphere sweeps.

### Collectable Items
Collectable actors can be detected through actor tags and C++ casting, allowing the player to interact with objects throughout the environment.

### Lock & Key System
Locks can require specific collectible items, creating puzzle-based progression through the dungeon.

### Moving Objects
Reusable Actor Components control moving doors and platforms using interpolated movement.

### Pressure Plates
Collision overlap events trigger environmental objects such as doors and moving platforms.

## Screenshots

Gameplay screenshots coming soon.

## Gameplay Demo

Gameplay video coming soon.

## Play the Game

A playable Windows build will be available through GitHub Releases.

## Running the Project

1. Clone the repository.
2. Install Unreal Engine 5.
3. Open `DungeonEscape.uproject`.
4. Allow Unreal Engine to compile the required C++ modules if prompted.
5. Open the main level and press Play.

## Developer

**Tugba Irem Demirci**

Computer Science student interested in software engineering, game development, and interactive systems.
