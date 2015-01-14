#include "ImageManager.h"

TImageManager::TImageManager()
{
    int i;
    QString adress;
    for(i = 0; i < 10; i++) {
        adress = ":/images/"+QString::number(i)+"_point.gif";
        points.push_back(new QMovie(adress));
    }
    ball= new QImage;
    ball->load(":/images/ball.png");
    for(i = 0; i < 5; i++) {
        bricks.push_back(new QImage);
        adress = ":/images/"+QString::number(4-i) + "_brick.png";
        bricks[i]->load(adress);
    }
}

TImageManager::~TImageManager()
{
    int i;
    for(i = 0; i < points.size(); i++) {
        delete points[i];
    }
    delete ball;
    for(i = 0; i < bricks.size(); i++) {
        delete bricks[i];
    }
}
QMovie & TImageManager::getPoint(int pointNum)
{
    return *points[pointNum];
}

const QImage & TImageManager::getBrick(int brickNum)
{
    return *bricks[brickNum];
}

const QImage & TImageManager::getBall()
{
    return *ball;
}
