#include "widget.h"
#include "ui_widget.h"
#include <algorithm>

#define PI 3.14159265;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    QApplication::instance()->installEventFilter(this);

    points1 = new QMovie("/home/viktor/Documents/Games/arkanoid/1_point.gif");
    points0 = new QMovie("/home/viktor/Documents/Games/arkanoid/0_point.gif");
    points2 = new QMovie("/home/viktor/Documents/Games/arkanoid/2_point.gif");
    points3 = new QMovie("/home/viktor/Documents/Games/arkanoid/3_point.gif");
    points4 =new QMovie("/home/viktor/Documents/Games/arkanoid/4_point.gif");
    points5 =new QMovie("/home/viktor/Documents/Games/arkanoid/5_point.gif");
    points6 = new QMovie("/home/viktor/Documents/Games/arkanoid/6_point.gif");
    points7 = new QMovie("/home/viktor/Documents/Games/arkanoid/7_point.gif");
    points8 = new QMovie("/home/viktor/Documents/Games/arkanoid/8_point.gif");
    points9 = new QMovie("/home/viktor/Documents/Games/arkanoid/9_point.gif");
    ball= new QImage;
    bita = new QImage;
    brick = new QImage;
    brick2 = new QImage;
    brick3 = new QImage;
    brick4 = new QImage;
    brick5 = new QImage;
    genBlocks(blocksArr);
    ui->setupUi(this);
    ui->restart->hide();
    ball->load("/home/viktor/Documents/Games/arkanoid/ball.png");
    bita->load("/home/viktor/Documents/Games/arkanoid/Bita.bmp");
    brick->load("/home/viktor/Documents/Games/arkanoid/brick.png");
    brick2->load("/home/viktor/Documents/Games/arkanoid/brick_2.png");
    brick3->load("/home/viktor/Documents/Games/arkanoid/brick_3.png");
    brick4->load("/home/viktor/Documents/Games/arkanoid/brick_4.png");
    brick5->load("/home/viktor/Documents/Games/arkanoid/brick_5.png");
    ballY = bitaY - ball->height() / 2;
}

Widget::~Widget()
{
    delete points0;
    delete points1;
    delete ball;
    delete bita;
    delete brick;
    delete brick2;
    delete brick3;
    delete brick4;
    delete brick5;
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
     QPainter painter(this);
     painter.setRenderHint(QPainter::Antialiasing, true);
     painter.drawImage(ballX - ball->width() / 2, ballY - ball->height() / 2, *ball, 0, 0, ball->width(), ball->height());
     painter.drawImage(bitaX - bita->width() / 2, bitaY - bita->height() / 2, *bita, 0, 0, bita->width(), bita->height());
     switch(paintPointsMid)
     {
        case 0:
        {
          painter.drawPixmap(50,640,points0->currentPixmap());
          points0->start();
          break;

        }
        case 1:
        {
          painter.drawPixmap(50,640,points1->currentPixmap());
          points1->start();
          break;
        }
        case 2:
        {
          painter.drawPixmap(50,640,points2->currentPixmap());
          points2->start();
          break;
        }
        case 3:
        {
          painter.drawPixmap(50,640,points3->currentPixmap());
          points3->start();
          break;
        }
        case 4:
        {
          painter.drawPixmap(50,640,points4->currentPixmap());
          points4->start();
          break;
        }
        case 5:
        {
          painter.drawPixmap(50,640,points5->currentPixmap());
          points5->start();
          break;

        }
        case 6:
        {
          painter.drawPixmap(50,640,points6->currentPixmap());
          points6->start();
          break;

        }
        case 7:
        {
          painter.drawPixmap(50,640,points7->currentPixmap());
          points7->start();
          break;

        }
        case 8:
        {
          painter.drawPixmap(50,640,points8->currentPixmap());
          points8->start();
          break;

        }
        case 9:
        {
          painter.drawPixmap(50,640,points9->currentPixmap());
          points9->start();
          break;

        }
        default:
         break;
     }
     switch(paintPointsLeft)
     {
        case 0:
        {
          painter.drawPixmap(10,640,points0->currentPixmap());
          points0->start();
          break;

        }
        case 1:
        {
          painter.drawPixmap(10,640,points1->currentPixmap());
          points1->start();
          break;
        }
        case 2:
        {
          painter.drawPixmap(10,640,points2->currentPixmap());
          points2->start();
          break;
        }
        case 3:
        {
          painter.drawPixmap(10,640,points3->currentPixmap());
          points3->start();
          break;
        }
        case 4:
        {
          painter.drawPixmap(10,640,points4->currentPixmap());
          points4->start();
          break;
        }
        case 5:
        {
          painter.drawPixmap(10,640,points5->currentPixmap());
          points5->start();
          break;

        }
        case 6:
        {
          painter.drawPixmap(10,640,points6->currentPixmap());
          points6->start();
          break;

        }
        case 7:
        {
          painter.drawPixmap(10,640,points7->currentPixmap());
          points7->start();
          break;

        }
        case 8:
        {
          painter.drawPixmap(10,640,points8->currentPixmap());
          points8->start();
          break;

        }
        case 9:
        {
          painter.drawPixmap(10,640,points9->currentPixmap());
          points9->start();
          break;

        }
        default:
         break;
     }
     switch(paintPointsRigth)
     {
        case 0:
        {
          painter.drawPixmap(90,640,points0->currentPixmap());
          points0->start();
          break;

        }
        case 1:
        {
          painter.drawPixmap(90,640,points1->currentPixmap());
          points1->start();
          break;
        }
        case 2:
        {
          painter.drawPixmap(90,640,points2->currentPixmap());
          points2->start();
          break;
        }
        case 3:
        {
          painter.drawPixmap(90,640,points3->currentPixmap());
          points3->start();
          break;
        }
        case 4:
        {
          painter.drawPixmap(90,640,points4->currentPixmap());
          points4->start();
          break;
        }
        case 5:
        {
          painter.drawPixmap(90,640,points5->currentPixmap());
          points5->start();
          break;

        }
        case 6:
        {
          painter.drawPixmap(90,640,points6->currentPixmap());
          points6->start();
          break;

        }
        case 7:
        {
          painter.drawPixmap(90,640,points7->currentPixmap());
          points7->start();
          break;

        }
        case 8:
        {
          painter.drawPixmap(90,640,points8->currentPixmap());
          points8->start();
          break;

        }
        case 9:
        {
          painter.drawPixmap(90,640,points9->currentPixmap());
          points9->start();
          break;

        }
        default:
         break;
     }
     for(int i = 1; i <= countLife; i++)
     {
         painter.drawImage(i*12, ball->height(), *ball, 0, 0, ball->width(), ball->height());
     }
     int gapX = 40;
     int gapY = 0;
     for(int i = 0; i < 9; i++)
     {
         for(int j = 0; j < 9; j++)
         {
             if(blocksArr[i][j] != 0)
             {
                 switch(blocksArr[i][j])
                 {
                    case 5:
                    {
                        painter.drawImage(i*brickSW + gapX, j*brickSH + gapY, *brick, 0, 0, brickSW,brickSH);
                        break;
                    }
                    case 4:
                    {
                        painter.drawImage(i*brickSW + gapX, j*brickSH+ gapY, *brick2, 0, 0, brickSW,brickSH);
                        break;
                    }
                    case 3:
                    {
                        painter.drawImage(i*brickSW+ gapX, j*brickSH + gapY, *brick3, 0, 0, brickSW,brickSH);
                        break;
                    }
                    case 2:
                    {
                        painter.drawImage(i*brickSW + gapX, j*brickSH + gapY, *brick4, 0, 0, brickSW,brickSH);
                        break;
                    }
                     case 1:
                    {
                        painter.drawImage(i*brickSW + gapX, j*brickSH + gapY, *brick5, 0, 0, brickSW,brickSH);
                        break;
                    }

                 }
             }

         }
         gapX+= 40;
     }
}

void Widget::timerEvent(QTimerEvent *event)
{
   ballX += speedBallX;
   ballY -= speedBallY;
   CheckBorders();
   update();
}

void Widget::CheckBorders()
{
    if(skipRot > 0)
    {
        skipRot--;
    }
    BallAngle();
    if(ballY == widgetHeight)
    {
        countLife--;
        killTimer(idTimer);
        bitaX = rand() % widgetWigth - (bita->width() / 2);
        ballX = bitaX;
        ballY = bitaY  - ball->height();
        speedBallY *=-1;
        if(countLife != 0)
        {
            startTimer(20);
        }
        else
        {
            ui->restart->show();
        }
    }
    if (skipRot) return;
    int i = 0;
    int j = 0;
    int gapX = 40;
    int gapY = 0;
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            int brickLeft = i*brickSW;
            int brickTop = j * brickSH;
            int brickRight = brickLeft + brickSW;
            int brickBottom = brickTop + brickSH;

            if (!blocksArr[i][j]) {
                continue;
            }

            if ((ballX < (brickRight + gapX) && ballX >= brickLeft + gapX) && (brickBottom + gapY > ballY && ballY >= brickTop + gapY))
            {
                int distanceVert = std::min(abs(ballY - (brickTop + gapY)), abs(ballY - (brickBottom + gapY)));
                int distanceHoriz = std::min(abs (ballX - (brickLeft + gapX)), abs(ballX - (brickRight + gapX)));
                if(distanceVert < distanceHoriz)
                {
                    speedBallY *=-1;
                }
                else
                {
                    if(distanceVert > distanceHoriz)
                    {
                     speedBallX *= -1;
                    }
                    else
                    {
                        speedBallX *=-1;
                        speedBallY *=-1;
                    }
                }
                CountPoints();
                   blocksArr[i][j]--;
                   skipRot = 3;
                   break;
            }
        }
        gapX+= 40;
    }
}

void Widget::BallAngle(void)
{
    if(ballX > widgetWigth || ballX < 0)
    {
            speedBallX *= -1;
    }
    if(abs((bitaX - bita->width()/2) - (ballX - ball->width()/2)) <= (bita->width() -ball->width()) && abs(bitaY - bita->height()/2) - (ballY - ball->height()/2) <= (ball->height() - bita->height()))
    {
        if((bitaX <= (ballX - ball->width()/2) && bitaX+3 >= (ballX - ball->width()/2)) || ((bitaX + bita->width() - 3) <= (ballX - ball->width()/2) <=  (ballX) && (bitaX + bita->width()) >=  (ballX - ball->width()/2)))
        {
            speedBallX *= -1;
        }
        speedBallY *= -1;
    }
    else
    {
        if(ballY > widgetHeight || ballY < 0)
        {
            speedBallY *= -1;
        }
    }
}

bool Widget::eventFilter(QObject *, QEvent *e)
{
    if (e->type() == QEvent::KeyPress)
    {
        onKeyPressed(((QKeyEvent*)e)->key());
        return true;
    }
    return false;
}

void Widget::onKeyPressed(int key)
{
    if (key == Qt::Key_Right)
    {
        if(bitaX < widgetWigth- (bita->width() / 2))
        {
            bitaX += speedBita;
        }
    }
    if (key == Qt::Key_Left)
    {
        if(bitaX > 0)
        {
            bitaX -= speedBita;
        }
    }
}

 void Widget::genBlocks(int arr[0][9])
 {
     int i = 0;
     int j = 0;
     for(i = 0; i < 9;i++)
     {
         for(j = 0; j < 9; j++)
         {
             arr[j][i] = 0;
         }
     }
     for(i = 1; i < 9; i++)
     {
         for(j = 1; j < 9;j++)
         {
             arr[j][i] = 5;
         }
     }
 }

void Widget::on_start_clicked()
{
       countLife = 3;
       genBlocks(blocksArr);
       idTimer = startTimer(20);
       ui->start->hide();
}

void Widget::on_restart_clicked()
{
    bitaX = rand() % widgetWigth - (bita->width() / 2);
    ballX = bitaX;
    ballY = bitaY  - ball->height();
    speedBallY *=-1;
    countLife = 3;
    genBlocks(blocksArr);
    idTimer = startTimer(20);
    ui->restart->hide();
}

void Widget::CountPoints(void)
{
    if(paintPointsRigth == 9)
    {
        if(paintPointsMid == 9)
        {
            paintPointsMid = 0;
            paintPointsRigth = 0;
            paintPointsLeft++;

        }
        else
        {
            paintPointsMid++;
            paintPointsRigth = 0;
        }
    }
    else
    {
        paintPointsRigth++;
    }
}
