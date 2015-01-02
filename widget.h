#ifndef WIDGET_H
#define WIDGET_H
#include <QImage>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>
#include <math.h>
#include <QMovie>
#include <QVector>


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

    Ui::Widget *ui;
    QImage *ball;
    QImage *bita;
    QImage * low;
    QImage *mid;
    QImage * high;

private:
    void paintEvent(QPaintEvent * );

public:

    int bitaUpdate = 0;
    void BallAngle(void);
    void CountPoints(void);
    const int bitaWidth = 80;
    const int bitaHeight = 15;
    int paintPointsMid = 0;
    int paintPointsLeft = 0;
    int paintPointsRigth = 0;
    const int coordPointsX = 640;
    const int coordPointsY = 500;
    int countLife = 0;
    const int widgetWidth = 1280;
    const int widgetHeight = 720;
    int bitaX = rand() % (widgetWidth - bitaWidth) + bitaWidth;
    float ballX = bitaX;
    float bitaY = 640;
    int ballY;
    float speedBallX = 1;
    float speedBallY = 1;
    const int brickSW = 80;
    const int brickSH = 40;
    int idTimer;
    QVector< QVector<int> > blocksArr;
    QVector< QMovie *> points;
    const int blackBrick = 5;
    int skipRot = 0;
    QVector< QImage *> bricks;

private slots:
    void on_start_clicked();

    void on_restart_clicked();

private:

    void timerEvent(QTimerEvent *);
    void CheckBorders();
    bool eventFilter(QObject *, QEvent *e);
    void onKeyPressed(int key);

    void genBlocks();


};

#endif // WIDGET_H
