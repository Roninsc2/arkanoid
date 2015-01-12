#ifndef FIELD_H
#define FIELD_H

#include <QKeyEvent>
#include <math.h>
#include "ImageManager.h"
#include "sound.h"
#include <fstream>

class TField
{

public:
    TField(TImageManager &_image, TSound& _sound);
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
    TSound &sound;
    float bitaSpeedX = 0;
    const float bitaWidth = 80;
    const float bitaHeight = 15;
    int pointsMid = 0;
    int pointsLeft = 0;
    int pointsRigth = 0;
    const int coordPointsX = 640;
    const int coordPointsY = 500;
    const float widgetWidth = 1280;
    const float widgetHeight = 720;
    float bitaX;
    float ballX;
    float bitaY = 640;
    float ballY;
    float speedBallX = 1.4;
    float speedBallY = 1.4;
    const int brickWidth = 80;
    const int brickHeight = 40;
    int ballWidth = 12;
    int ballHeight = 12;
    QVector< QVector<int> > blocksArray;
    QVector< QVector<int> > blocksTtl;
    const int blocksArrayHeight = 15;
    const int blocksArrayWidth = 15;
    int skipRot = 0;
    int bitaHitTtl = 0;

};

#endif // FIELD_H
