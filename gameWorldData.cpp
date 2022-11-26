//
// Created by lou on 11/24/22.
//

#include "gameWorldData.h"

gameWorldData::gameWorldData() {
    this->screenWidth = 1920;
    this->screenHeight = 1080;

}

gameWorldData::~gameWorldData() {

}

int gameWorldData::getScreenWidth() {

    return screenWidth;
}

int gameWorldData::getScreenHeight() {
    return screenHeight;
}

void gameWorldData::setScreenWidth(float) {

}

void gameWorldData::setScreenHeight(float) {

}
