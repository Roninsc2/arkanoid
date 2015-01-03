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
    bita = new QImage;
    ball->load(":/images/ball.png");
    bita->load(":/images/Bita.bmp");
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
    delete bita;
    for(i = 0; i < bricks.size(); i++)
    {
        delete bricks[i];
    }
}
