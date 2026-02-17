#pragma once
#include "GameObject.h"
#include <vector>

class MemoryPool {
private:
    std::vector<GameObject> pool;

public:
    MemoryPool(int size) {
        //here we pre-allocate memory to prevent lag during gameplay
        pool.resize(size);
    }

    //here we find an inactive object and recycle it
    GameObject* acquireObject() {
        for (auto& obj : pool) {
            if (!obj.active) {
                return &obj;
            }
        }
        std::cout << "[Warning] Memory Pool Exhausted!" << std::endl;
        return nullptr;
    }

    //here we "Destroy" an object by deactivating it (saves memory)
    void releaseObject(GameObject* obj) {
        if (obj) {
            obj->active = false;
        }
    }
};