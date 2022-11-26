//
// Created by lou on 11/24/22.
//

#ifndef FINALOOP_GAMEWORLDDATA_H
#define FINALOOP_GAMEWORLDDATA_H


class gameWorldData {
private:
    int screenWidth;
    int screenHeight;
public:
    gameWorldData();

    ~gameWorldData();

    int getScreenWidth();

    int getScreenHeight();

    void setScreenWidth(float);

    void setScreenHeight(float);


};
#endif //FINALOOP_GAMEWORLDDATA_H
