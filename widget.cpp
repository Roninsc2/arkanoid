#include "widget.h"
#include "ui_widget.h"
#include <algorithm>

#define PI 3.14159265;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    QApplication::instance()->installEventFilter(this);

    points1 = new QMovie(":/images/1_point.gif");
    points0 = new QMovie(":/images/0_point.gif");
    points2 = new QMovie(":/images/2_point.gif");
    points3 = new QMovie(":/images/3_point.gif");
    points4 =new QMovie(":/images/4_point.gif");
    points5 =new QMovie(":/images/5_point.gif");
    points6 = new QMovie(":/images/6_point.gif");
    points7 = new QMovie(":/images/7_point.gif");
    points8 = new QMovie(":/images/8_point.gif");
    points9 = new QMovie(":/images/9_point.gif");
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
    ball->load(":/images/ball.png");
    bita->load(":/images/Bita.bmp");
    brick->load(":/images/brick.png");
    brick2->load(":/images/brick_2.png");
    brick3->load(":/images/brick_3.png");
    brick4->load(":/images/brick_4.png");
    brick5->load(":/images/brick_5.png");
    ballY = bitaY - ball->height();
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

void Widget::paintEvent(QPaintEvent*)
{
     QPainter painter(this);

     painter.setRenderHint(QPainter::Antialiasing, true);
     painter.setBrush(Qt::blue);
     painter.setPen(Qt::blue);
     painter.drawImage(ballX - ball->width() / 2, ballY - ball->height() / 2, *ball, 0, 0, ball->width(), ball->height());
     painter.drawRect(bitaX - bitaWidth/2, bitaY-bitaHeight/2, bitaWidth, bitaHeight);
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
     int gapY  = 0;
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
                        painter.drawImage(i*brickSW + gapX*i, j*brickSH + gapY*j, *brick, 0, 0, brickSW,brickSH);
                        break;
                    }
                    case 4:
                    {
                        painter.drawImage(i*brickSW + gapX*i, j*brickSH+ gapY*j, *brick2, 0, 0, brickSW,brickSH);
                        break;
                    }
                    case 3:
                    {
                        painter.drawImage(i*brickSW+ gapX*i, j*brickSH + gapY*j, *brick3, 0, 0, brickSW,brickSH);
                        break;
                    }
                    case 2:
                    {
                        painter.drawImage(i*brickSW + gapX*i, j*brickSH + gapY*j, *brick4, 0, 0, brickSW,brickSH);
                        break;
                    }
                     case 1:
                    {
                        painter.drawImage(i*brickSW + gapX*i, j*brickSH + gapY*j, *brick5, 0, 0, brickSW,brickSH);
                        break;
                    }

                 }
             }

         }
     }
}

void Widget::timerEvent(QTimerEvent *)
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
        bitaX = rand() % widgetWigth - (bitaWidth / 2);
        ballX = bitaX;
        ballY = bitaY  - ball->height();
        speedBallY *=-1;
        if(countLife != 0)
        {
            startTimer(10);
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
    int gapY  = 0;
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

            if ((ballX - ball->width()/2) < (brickRight + gapX*i) && (ballX + ball->width()/2 >= brickLeft + gapX*i) && (brickBottom + gapY*j > ballY - ball->height()/2 && ballY + ball->height()/2>= brickTop + gapY*j))
            {
                int distanceVert = std::min(abs(ballY + ball->height()/2 - (brickTop + gapY*j)), abs(ballY - ball->height()/2 - (brickBottom + gapY*j)));
                int distanceHoriz = std::min(abs (ballX + ball->width()/2- (brickLeft + gapX*i)), abs(ballX- ball->width()/2- (brickRight + gapX*i)));
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
                   skipRot = 5;
                   break;
            }
        }
    }
}

void Widget::BallAngle(void)
{
    if(ballX > widgetWigth || ballX < 0)
    {
            speedBallX *= -1;
    }
    if((bitaX - bitaWidth /2 <= (ballX - ball->width()/2)) && (bitaX + bitaWidth/2 >= (ballX - ball->width()/2)) && (bitaY-bitaHeight/2 <= (ballY - ball->height()/2)) && (bitaY+bitaHeight/2 > (ballY - ball->height())))
    {
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
        if(bitaX < widgetWigth- (bitaWidth / 2))
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
       idTimer = startTimer(10);
       ui->start->hide();
}

void Widget::on_restart_clicked()
{
    bitaX = rand() % widgetWigth - bitaWidth;
    ballX = bitaX;
    ballY = bitaY  - ball->height();
    speedBallY *=-1;
    countLife = 3;
    genBlocks(blocksArr);
    idTimer = startTimer(10);
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
