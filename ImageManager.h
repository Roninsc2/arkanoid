#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H
#include <QImage>
#include <QMovie>
#include <QVector>
#include <string>


class TImageManager
{
public:
    TImageManager();
    ~TImageManager();
    QMovie &getPoint(int pointNum);
    const QImage &getBrick(int brickNum);
    const QImage &getBall();

private:

    QVector< QMovie *> points;
    QVector< QImage *> bricks;
    QImage *ball;

};

#endif // IMAGEMANAGER_H
