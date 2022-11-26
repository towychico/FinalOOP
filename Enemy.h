//
// Created by lou on 11/25/22.
//

#ifndef FINALOOP_ENEMY_H
#define FINALOOP_ENEMY_H
#include "raylib.h"
#include <string>
#include "gameWorldData.h"

class Enemy {
private:
    int enemyType;
    const char *filePath;

    float rotation;
    Texture2D texture;
    Rectangle textureTransform;
    //int id;
    bool hasColided;
    float speed;
    float xSpeed;
    float ySpeed;
    float distanceMagnitude;
    float getMagnitude(gameWorldData);
    float calculateXDisplacement(float);
    float calculateYDisplacement(float);
public:
    Vector2 position;
    Rectangle texturePosition;
    //Enemy(gameWorldData, Vector2,Texture2D, int);
    Enemy(gameWorldData, Vector2);
    ~Enemy();
    Vector2 getPosition();
    void setPosition(Vector2);

    float getInitialRotation();
    void setInitialRotation(float);
    Texture2D getTexture();
    Rectangle getTextureTransform();
    Rectangle getTexturePosition();

    float updateRotation(Vector2);
    Texture2D updateTexture(gameWorldData);
    void updatePosition(gameWorldData);



};


#endif //FINALOOP_ENEMY_H
