//
// Created by lou on 11/24/22.
//

#ifndef FINALOOP_PLAYER_H
#define FINALOOP_PLAYER_H
#include "raylib.h"
#include <string>
#include "gameWorldData.h"

class Player {
private:
    Rectangle colition;

    float rotation;
    Texture2D texture;



    int health;
public:
    Rectangle getColition();
    Rectangle textureTransform;
    Rectangle texturePosition;
    Vector2 position;
    Player(gameWorldData);
    ~Player();
    Vector2 getPosition();
    void setPosition(Vector2);

    float getInitialRotation();
    void setInitialRotation(float);
    Texture2D getTexture();
    Rectangle getTextureTransform();
    Rectangle getTexturePosition();
    int getHealth();
    void setHealth(int);
    float updateRotation(Vector2);
    Texture2D updateTexture(Vector2, gameWorldData);

    void Render();

};



#endif //FINALOOP_PLAYER_H
