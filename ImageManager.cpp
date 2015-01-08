#include "ImageManager.h"
#include <string>

TImageManager::TImageManager() {
    int i;
    std::string adress;
    for(i = 0; i < 10; i++) {
        adress = ":/images/"+std::to_string(i)+"_point.gif";
        points.push_back(new QMovie(adress.c_str()));
    }
    ball= new QImage;
    ball->load(":/images/ball.png");
    for(i = 0; i < 5; i++) {
        bricks.push_back(new QImage);
        adress = ":/images/"+std::to_string(4-i) + "_brick.png";
        bricks[i]->load(adress.c_str());
    }
}

TImageManager::~TImageManager() {
    int i;
    for(i = 0; i < points.size(); i++) {
        delete points[i];
    }
    delete ball;
    for(i = 0; i < bricks.size(); i++) {
        delete bricks[i];
    }
}
QMovie & TImageManager::getPoint(int pointNum) {
    return *points[pointNum];
}

const QImage & TImageManager::getBrick(int brickNum) {
    return *bricks[brickNum];
}

const QImage & TImageManager::getBall() {
    return *ball;
}
