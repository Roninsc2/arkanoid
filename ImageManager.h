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

private:

    QVector< QMovie *> points;
    QVector< QImage *> bricks;
    QImage *ball;

public:

    QMovie & GetPoint(int pointNum);
    const QImage & GetBrick(int brickNum);
    const QImage & GetBall();

};

#endif // IMAGEMANAGER_H
