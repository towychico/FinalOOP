//
// Created by lou on 11/25/22.
//

#include "Enemy.h"
#include "raylib.h"
#include "gameWorldData.h"
#include <math.h>
#include <string>
#include <time.h>
#include <iostream>

const char* ENEMY_TYPES[3][2] ={{"Sprites/enemy_1_left.png","Sprites/enemy_1_right.png"}, {"Sprites/enemy_2_left.png","Sprites/enemy_2_right.png"}, {"Sprites/enemy_3_left.png","Sprites/enemy_3_right.png"}};
Enemy::Enemy(gameWorldData data ,Vector2 position ) {
    srand (time(NULL));
    this->enemyType = rand() % 2 + 0;
    this->filePath =ENEMY_TYPES[enemyType][0];
    this-> position = position;
    this-> rotation = updateRotation({float(data.getScreenWidth()/2),float(data.getScreenHeight()/2)});
    this-> texture = LoadTexture(filePath);
    //this-> id = enemyId;
    this-> hasColided = false;
    this-> speed = 10;
    this->xSpeed = calculateXDisplacement(speed);
    this->ySpeed = calculateYDisplacement(speed);
    this->distanceMagnitude = getMagnitude(data);
    this-> texturePosition = {float(position.x),float(position.y),float(texture.width),float(texture.height)};
    textureTransform.width = float(texture.width);
    textureTransform.height = float(texture.height);
    textureTransform.x = float(0);
    textureTransform.y = float(0);

}

Enemy::~Enemy() {

    UnloadTexture(texture);
}

Vector2 Enemy::getPosition() {
    return position;
}

void Enemy::setPosition(Vector2 newPosition) {
    position = newPosition;
}

float Enemy::getInitialRotation() {

    return rotation;
}

void Enemy::setInitialRotation(float newRotation) {
    rotation = newRotation;
}

Texture2D Enemy::getTexture() {
    return texture;
}

Rectangle Enemy::getTextureTransform() {
    return textureTransform;
}

Rectangle Enemy::getTexturePosition() {
    return texturePosition;
}

float Enemy::updateRotation(Vector2 player) {
    float opposite = player.y - position.y;
    float adjacent = player.x - position.x;
    float angle = atan(opposite/adjacent) * (180 / PI);
    //rotation = angle;
    return angle;
}

Texture2D Enemy::updateTexture(gameWorldData data) {
    //TODO: Update texture based on enemy type
    //TODO: Update texture based on side of the screen
    texture = LoadTexture( position.x > float(data.getScreenWidth())/2 ? ENEMY_TYPES[enemyType][1]:ENEMY_TYPES[enemyType][0]);
    return texture;
}



float Enemy::getMagnitude(gameWorldData data) {

   return sqrt(pow(( (float(data.getScreenWidth())/2) -position.x),2) + pow(( (float(data.getScreenHeight())/2) -position.y),2));
}

float Enemy::calculateXDisplacement(float M) {
    float displacement = (M)*(cos(rotation) * (180 / PI));
    return displacement;
}

float Enemy::calculateYDisplacement(float M) {
    float displacement = (M)*(sin(rotation) * (180 / PI));
    return displacement;
}

void Enemy::updatePosition(gameWorldData data) {
    if (position.x > float(data.getScreenWidth()) / 2 && position.y > float(data.getScreenHeight()) / 2) {
        position.x = position.x - speed;
        position.y = position.y - speed;
    }
    if (position.x < float(data.getScreenWidth()) / 2 && position.y < float(data.getScreenHeight()) / 2) {
        position.x = position.x + speed;
        position.y = position.y + speed;
    }
    if (position.x > float(data.getScreenWidth()) / 2 && position.y < float(data.getScreenHeight()) / 2){
        position.x = position.x - speed;
        position.y = position.y + speed;
    }
    if (position.x < float(data.getScreenWidth()) / 2 && position.y > float(data.getScreenHeight()) / 2){
        position.x = position.x + speed;
        position.y = position.y - speed;
    }
   // position.y = position.y + speed;

    //float currentX = getPosition().x;
    //float currentY = getPosition().y;
    //Vector2 newPosition = {currentX +xSpeed, currentX +ySpeed};
    //setPosition(newPosition);
    //position.x = position.x + calculateYDisplacement(speed);
    //position.y = position.y + calculateYDisplacement(speed);
    texturePosition ={float(position.x),float(position.y),float(texture.width),float(texture.height)};
    //float tempX = position.x + xSpeed;
    //float tempY = position.y + ySpeed;
    //std::cout << xSpeed<< std::endl;
    //std::cout << ySpeed<< std::endl;
    //texturePosition.x = tempX;
    //position.x = tempX;
    //texturePosition.y = texturePosition.y - ySpeed;
    //position.y = tempY;
}//

