#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H
#include <QImage>
#include <QMovie>
#include <QVector>


class ImageManager
{
public:
   ImageManager();
   ~ImageManager();

public:

    QVector< QMovie *> points;
    QVector< QImage *> bricks;
    QImage *ball;
    QImage *bita;

};

#endif // IMAGEMANAGER_H
