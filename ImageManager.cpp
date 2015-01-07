#include "ImageManager.h"
#include <string>

ImageManager::ImageManager()
{
    int i;
    std::string adress;
    for(i = 0; i < 10; i++)
    {
        adress = ":/images/"+std::to_string(i)+"_point.gif";
        points.push_back(new QMovie(adress.c_str()));
    }
    ball= new QImage;
    ball->load(":/images/ball.png");
    for(i = 0; i < 5; i++)
    {
        bricks.push_back(new QImage);
        adress = ":/images/"+std::to_string(4-i) + "_brick.png";
        bricks[i]->load(adress.c_str());
    }
}

ImageManager::~ImageManager()
{
    int i;
    for(i = 0; i < points.size(); i++)
    {
        delete points[i];
    }
    delete ball;
    for(i = 0; i < bricks.size(); i++)
    {
        delete bricks[i];
    }
}
QMovie & ImageManager::GetPoint(int pointNum)
{
    return *points[pointNum];
}

const QImage & ImageManager::GetBrick(int brickNum)
{
    return *bricks[brickNum];
}

const QImage & ImageManager::GetBall()
{
    return *ball;
}
