#ifndef FIELD_H
#define FIELD_H

#include <QKeyEvent>
#include <math.h>
#include "ImageManager.h"
#include <fstream>

class TField
{

public:
    TField(TImageManager &_image);
    void moveBita(bool move);
    void stopMoveBita(void);
    void ballAngle(void);
    void countPoints(void);
    int checkBorders(void);
    void updateBallandBita(void);
    void generationBlocks();


public:

    int blocksCount = 0;
    int level = 1;
    int countLife = 0;
    TImageManager &image;
    int bitaUpdate = 0;
    const int bitaWidth = 80;
    const int bitaHeight = 15;
    int pointsMid = 0;
    int pointsLeft = 0;
    int pointsRigth = 0;
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
    const int brickWidth = 80;
    const int brickHeight = 40;
    QVector< QVector<int> > blocksArray;
    const int blocksArrayHeight = 15;
    const int blocksArrayWidth = 15;
    int skipRot = 0;

};

#endif // FIELD_H
