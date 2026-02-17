#include <iostream>
#include <thread>
#include <chrono>
#include "GameObject.h"
#include "MemoryPool.h"
#include "Physics.h"

int main() {
    std::cout << "--- Initializing 2D Physics Engine ---" << std::endl;

    //first we initialize Memory Pool (Max 100 objects)
    MemoryPool objectPool(100);
    std::cout << "Memory Pool Allocated: 100 Entities." << std::endl;

    //second we spawn Objects using the Pool
    GameObject* player = objectPool.acquireObject();
    player->init("Police_Cruiser", 0.0f, 0.0f, 2.0f, 2.0f);
    player->vx = 1.0f;

    GameObject* obstacle = objectPool.acquireObject();
    obstacle->init("Roadblock", 5.0f, 0.0f, 2.0f, 2.0f);
    obstacle->vx = 0.0f;

    //third the Core Simulation Loop (Game Loop)
    float deltaTime = 1.0f;
    int frameCount = 0;
    bool running = true;

    while (running && frameCount < 10) {
        std::cout << "\n[Frame " << frameCount << "]" << std::endl;

        // here we process Physics / Update Positions
        player->update(deltaTime);
        obstacle->update(deltaTime);

        std::cout << player->name << " Position: X=" << player->x << std::endl;
        std::cout << obstacle->name << " Position: X=" << obstacle->x << std::endl;

        //here is the collision Detection Phase
        if (PhysicsEngine::checkCollision(*player, *obstacle)) {
            std::cout << ">>> COLLISION DETECTED! <<<" << std::endl;
            std::cout << "Triggering event: Stopping " << player->name << std::endl;
            
            player->vx = 0.0f;
            running = false;
        }

        //here we simulate frame pacing (e.g., 60 FPS constraint)
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
        frameCount++;
    }

    std::cout << "\n--- Engine Shutting Down ---" << std::endl;
    return 0;
}