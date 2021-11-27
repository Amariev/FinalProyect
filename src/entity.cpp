#include "../include/basic.h"

Entity::Entity(){}
Entity::~Entity(){}

bool Entity::isStable(){}
bool Entity::isMoveable(){}
bool Entity::isDead(){}
bool Entity::destroy(){}

bool Entity::checkCollision(Entity *){}
bool Entity::collision(Entity *){}
void Entity::update(float _dt){}