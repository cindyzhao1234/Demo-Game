#include "player.h"
#include "ECS/Systems.h"

    // Creates the player entity and adds required components (Transform + Sprite).
    // Call once when entering a game scene.
void Player::spawn(World& world, const Vector2& startPos, const std::string& textureKey, int layer){
    Entity newPlayer = world.createEntity();
    entity = newPlayer;
    world.addTransform(entity, {startPos, 0.0f, {1.0f, 1.0f}});
    world.addSprite(entity, {textureKey, layer});
    spawned = true;
}

    // Optional cleanup (if you want to remove the player entity).
void Player::despawn(World& world){
    
    world.destroyEntity(entity);
    entity = 0;
    spawned = false;
}

    // Calls your movement system logic (or equivalent) to move the player.
    // Keep this as a thin wrapper so you don't duplicate engine logic.
void Player::update(World& world, Input& input, float dt){
    if(entity == 0){
        return;
    }
    movementSystem(world, entity, input, dt, speed);
}

    // Accessors
Entity Player::getEntity() const{
    return entity;
}
bool Player::isSpawned() const{
    return spawned;
}
float Player::getSpeed() const{
    return speed;
}
void Player::setSpeed(float newSpeed){
    speed = newSpeed;
}

    // Convenience helpers (read/write Transform in the World)
Vector2 Player::getPosition(const World& world) const{
    return world.getTransform(entity).pos;
}

void Player::setPosition(World& world, const Vector2& newPos){
    world.getTransform(entity).pos = newPos;
}