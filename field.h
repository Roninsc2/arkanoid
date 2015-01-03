#ifndef FIELD_H
#define FIELD_H

#include <QKeyEvent>
#include <math.h>
#include "ImageManager.h"

class Field
{

public:
    Field();


public:

    ImageManager Image;
    int bitaUpdate = 0;
    void BallAngle(void);
    void CountPoints(void);
    const int bitaWidth = 80;
    const int bitaHeight = 15;
    int paintPointsMid = 0;
    int paintPointsLeft = 0;
    int paintPointsRigth = 0;
    const int coordPointsX = 640;
    const int coordPointsY = 500;
    const int widgetWidth = 1280;
    const int widgetHeight = 720;
    int bitaX;
    float ballX;
    float bitaY = 640;
    int ballY;
    float speedBallX = 1;
    float speedBallY = 1;
    const int brickSW = 80;
    const int brickSH = 40;
    QVector< QVector<int> > blocksArr;
    int skipRot = 0;

public:

    int CheckBorders();
    void UpdateBallandBita();
    void genBlocks();

};

#endif // FIELD_H
