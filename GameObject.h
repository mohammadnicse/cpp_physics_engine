#pragma once
#include <iostream>
#include <string>

class GameObject {
public:
    std::string name;
    float x, y;       //this is the position
    float vx, vy;     //this is the velocity
    float width, height; //this is for collision boundaries
    bool active;      // Used by our Memory Pool

    GameObject() : x(0), y(0), vx(0), vy(0), width(1), height(1), active(false) {}

    void init(std::string n, float startX, float startY, float w, float h) {
        name = n;
        x = startX; y = startY;
        width = w; height = h;
        active = true;
    }

    //here it updates position based on velocity (Simulating Physics)
    void update(float deltaTime) {
        if (!active) return;
        x += vx * deltaTime;
        y += vy * deltaTime;
    }
};