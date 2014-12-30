#ifndef WIDGET_H
#define WIDGET_H
#include <QImage>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>
#include <math.h>
#include <stdlib.h>
#include <QMovie>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


private:

    QMovie *points0;
    QMovie *points1;
    QMovie *points2;
    QMovie *points3;
    QMovie *points4;
    QMovie *points5;
    QMovie *points6;
    QMovie *points7;
    QMovie *points8;
    QMovie *points9;
    Ui::Widget *ui;
    QImage *ball;
    QImage *bita;
    QImage * low;
    QImage *mid;
    QImage * high;
    QImage * brick;
    QImage * brick2;
    QImage * brick3;
    QImage * brick4;
    QImage * brick5;
private:
    void paintEvent(QPaintEvent * );

public:

    void BallAngle(void);
    void CountPoints(void);
    const int bitaWidth = 80;
    const int bitaHeight = 15;
    unsigned int paintPointsMid = 0;
    unsigned int paintPointsLeft = 0;
    unsigned int paintPointsRigth = 0;
    const int coordPointsX = 640;
    const int coordPointsY = 500;
    int countLife = 0;
    const int widgetWigth = 1280;
    const int widgetHeight = 720;
    int bitaX = rand() % (widgetWigth - bitaWidth) + bitaWidth;
    float ballX = bitaX;
    float bitaY = 640;
    int ballY;
    float speedBallX = 2;
    float speedBallY = 2;
    const int brickSW = 80;
    const int brickSH = 40;
    int idTimer;
    int blocksArr[9][9];
    const int blackBrick = 5;
    int skipRot = 0;

private slots:
    void on_start_clicked();

    void on_restart_clicked();

private:

    void timerEvent(QTimerEvent *);
    void CheckBorders();
    bool eventFilter(QObject *, QEvent *e);
    int onKeyPressed(int key);

    void genBlocks(int arr[0][9]);


};

#endif // WIDGET_H
