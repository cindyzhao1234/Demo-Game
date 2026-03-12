#pragma once

#include <string>
#include <raylib.h>    

#include "ECS/Entity.h"
#include "ECS/World.h"
#include "ECS/Components.h"
#include "Input.h" 
// Game-side convenience wrapper for "the player" in an ECS world.
// The actual data still lives in components inside World.
class Player {
public:
    Player() = default;

    // Creates the player entity and adds required components (Transform + Sprite).
    // Call once when entering a game scene.
    void spawn(World& world, const Vector2& startPos, const std::string& textureKey, int layer = 10);

    // Optional cleanup (if you want to remove the player entity).
    void despawn(World& world);

    // Calls your movement system logic (or equivalent) to move the player.
    // Keep this as a thin wrapper so you don't duplicate engine logic.
    void update(World& world, Input& input, float dt);

    // Accessors
    Entity getEntity() const;
    bool isSpawned() const;
    float getSpeed() const;
    void setSpeed(float newSpeed);

    // Convenience helpers (read/write Transform in the World)
    Vector2 getPosition(const World& world) const;
    void setPosition(World& world, const Vector2& newPos);

private:
    Entity entity = 0;     // 0 can mean "invalid" in your setup
    bool spawned = false;
    float speed = 200.0f; // pixels/sec (tweak as you like)
};