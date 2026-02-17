#pragma once
#include "GameObject.h"

class PhysicsEngine {
public:
    //here is used the AABB Collision Detection Algorithm
    static bool checkCollision(const GameObject& a, const GameObject& b) {
        if (!a.active || !b.active) return false;

        //here is the Math behind it: here we check if bounding boxes overlap
        bool collisionX = a.x + a.width >= b.x && b.x + b.width >= a.x;
        bool collisionY = a.y + a.height >= b.y && b.y + b.height >= a.y;

        return collisionX && collisionY;
    }
};