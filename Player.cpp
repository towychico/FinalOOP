//
// Created by lou on 11/24/22.
//

#include "Player.h"
#include "raylib.h"
#include "gameWorldData.h"
#include <cmath>       /* atan */
#include <iostream>
#define PI 3.14159265

Player::~Player() {
    UnloadTexture(texture);
}

Player::Player(gameWorldData data) {
    this-> colition = {(float)data.getScreenWidth()/2-(float(texture.width)/2),(float)data.getScreenHeight()/2 -(float(texture.height)/2),float(texture.width),float(texture.height)};
    this-> position = Vector2  {(float)data.getScreenWidth()/2, (float)data.getScreenHeight()/2};
    this-> rotation = 0;
    this->texture = LoadTexture("Sprites/player_ship_right.png");
    this->health = 100;
    this->texturePosition = {(float)data.getScreenWidth()/2-(float(texture.width)/2),(float)data.getScreenHeight()/2 -(float(texture.height)/2),float(texture.width),float(texture.height)};
    textureTransform.width = float(texture.width);
    textureTransform.height = float(texture.height);
    textureTransform.x = (float)0;
    textureTransform.y = (float)0;
}

Vector2 Player::getPosition() {
    return position;
}

void Player::setPosition(Vector2 newPosition) {
    position = newPosition;
}

float Player::getInitialRotation() {
    return rotation;
}

void Player::setInitialRotation(float o) {
    rotation =o;
}

Texture2D Player::getTexture() {
    return texture;
}

Rectangle Player::getTextureTransform() {
    return textureTransform;
}

Rectangle Player::getTexturePosition() {
    return texturePosition;
}

int Player::getHealth() {
    return 0;
}

void Player::setHealth(int) {

}

float Player::updateRotation(Vector2 mouse) {
    float opposite =  mouse.y -position.y;
    float adjacent = mouse.x -position.x;
    float angle = atan(opposite/adjacent) * (180 / PI);

    //TODO: remove for production version
    //std::cout <<angle<<std::endl;
    //std::cout <<"Mouse \n"<< "x: "<<mouse.x<<" y: "<< mouse.y<<std::endl;
    //std::cout <<"Ship\n"<< "x: "<<position.x<<" y: "<< position.y<<std::endl;
    return angle;
}

Texture2D Player::updateTexture(Vector2 mouse, gameWorldData data) {
    texture = LoadTexture(mouse.x > float(data.getScreenWidth())/2 ? "Sprites/player_ship_right.png":"Sprites/player_ship_left.png" );
    return texture;
}

void Player::Render() {

}

Rectangle Player::getColition() {
    return colition;
}
