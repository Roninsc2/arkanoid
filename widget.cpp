#include "widget.h"
#include "ui_widget.h"
#include <algorithm>

#define PI 3.14159265;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    QApplication::instance()->installEventFilter(this);
    int i;
    blocksArr.resize(9);
    for(i = 0; i < 9; i++)
    {
        blocksArr[i].resize(9);
    }
    points.resize(10);
    points[1] = new QMovie(":/images/1_point.gif");
    points[0] = new QMovie(":/images/0_point.gif");
    points[2] = new QMovie(":/images/2_point.gif");
    points[3] = new QMovie(":/images/3_point.gif");
    points[4] =new QMovie(":/images/4_point.gif");
    points[5] =new QMovie(":/images/5_point.gif");
    points[6] = new QMovie(":/images/6_point.gif");
    points[7] = new QMovie(":/images/7_point.gif");
    points[8] = new QMovie(":/images/8_point.gif");
    points[9] = new QMovie(":/images/9_point.gif");
    ball= new QImage;
    bita = new QImage;
    brick = new QImage;
    brick2 = new QImage;
    brick3 = new QImage;
    brick4 = new QImage;
    brick5 = new QImage;
    genBlocks();
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
    delete points[0];
    delete points[1];
    delete points[2];
    delete points[3];
    delete points[4];
    delete points[5];
    delete points[6];
    delete points[7];
    delete points[8];
    delete points[9];
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
     if(countLife)
     {
         painter.setRenderHint(QPainter::Antialiasing, true);
         painter.setBrush(Qt::blue);
         painter.setPen(Qt::blue);
         painter.drawImage(ballX - ball->width() / 2, ballY - ball->height() / 2, *ball, 0, 0, ball->width(), ball->height());
         painter.drawRect(bitaX - bitaWidth/2, bitaY-bitaHeight/2, bitaWidth, bitaHeight);
         switch(paintPointsMid)
         {
            case 0:
            {
              painter.drawPixmap(50,640,points[0]->currentPixmap());
              points[0]->start();
              break;

            }
            case 1:
            {
              painter.drawPixmap(50,640,points[1]->currentPixmap());
              points[1]->start();
              break;
            }
            case 2:
            {
              painter.drawPixmap(50,640,points[2]->currentPixmap());
              points[2]->start();
              break;
            }
            case 3:
            {
              painter.drawPixmap(50,640,points[3]->currentPixmap());
              points[3]->start();
              break;
            }
            case 4:
            {
              painter.drawPixmap(50,640,points[4]->currentPixmap());
              points[4]->start();
              break;
            }
            case 5:
            {
              painter.drawPixmap(50,640,points[5]->currentPixmap());
              points[5]->start();
              break;

            }
            case 6:
            {
              painter.drawPixmap(50,640,points[6]->currentPixmap());
              points[6]->start();
              break;

            }
            case 7:
            {
              painter.drawPixmap(50,640,points[7]->currentPixmap());
              points[7]->start();
              break;

            }
            case 8:
            {
              painter.drawPixmap(50,640,points[8]->currentPixmap());
              points[8]->start();
              break;

            }
            case 9:
            {
              painter.drawPixmap(50,640,points[9]->currentPixmap());
              points[9]->start();
              break;

            }
            default:
             break;
         }
         switch(paintPointsLeft)
         {
            case 0:
            {
              painter.drawPixmap(10,640,points[0]->currentPixmap());
              points[0]->start();
              break;

            }
            case 1:
            {
              painter.drawPixmap(10,640,points[1]->currentPixmap());
              points[1]->start();
              break;
            }
            case 2:
            {
              painter.drawPixmap(10,640,points[2]->currentPixmap());
              points[2]->start();
              break;
            }
            case 3:
            {
              painter.drawPixmap(10,640,points[3]->currentPixmap());
              points[3]->start();
              break;
            }
            case 4:
            {
              painter.drawPixmap(10,640,points[4]->currentPixmap());
              points[4]->start();
              break;
            }
            case 5:
            {
              painter.drawPixmap(10,640,points[5]->currentPixmap());
              points[5]->start();
              break;

            }
            case 6:
            {
              painter.drawPixmap(10,640,points[6]->currentPixmap());
              points[6]->start();
              break;

            }
            case 7:
            {
              painter.drawPixmap(10,640,points[7]->currentPixmap());
              points[7]->start();
              break;

            }
            case 8:
            {
              painter.drawPixmap(10,640,points[8]->currentPixmap());
              points[8]->start();
              break;

            }
            case 9:
            {
              painter.drawPixmap(10,640,points[9]->currentPixmap());
              points[9]->start();
              break;

            }
            default:
             break;
         }
         switch(paintPointsRigth)
         {
            case 0:
            {
              painter.drawPixmap(90,640,points[0]->currentPixmap());
              points[0]->start();
              break;

            }
            case 1:
            {
              painter.drawPixmap(90,640,points[1]->currentPixmap());
              points[1]->start();
              break;
            }
            case 2:
            {
              painter.drawPixmap(90,640,points[2]->currentPixmap());
              points[2]->start();
              break;
            }
            case 3:
            {
              painter.drawPixmap(90,640,points[3]->currentPixmap());
              points[3]->start();
              break;
            }
            case 4:
            {
              painter.drawPixmap(90,640,points[4]->currentPixmap());
              points[4]->start();
              break;
            }
            case 5:
            {
              painter.drawPixmap(90,640,points[5]->currentPixmap());
              points[5]->start();
              break;

            }
            case 6:
            {
              painter.drawPixmap(90,640,points[6]->currentPixmap());
              points[6]->start();
              break;

            }
            case 7:
            {
              painter.drawPixmap(90,640,points[7]->currentPixmap());
              points[7]->start();
              break;

            }
            case 8:
            {
              painter.drawPixmap(90,640,points[8]->currentPixmap());
              points[8]->start();
              break;

            }
            case 9:
            {
              painter.drawPixmap(90,640,points[9]->currentPixmap());
              points[9]->start();
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
}

void Widget::timerEvent(QTimerEvent *)
{
   ballX += speedBallX;
   ballY -= speedBallY;
   bitaX = std::min(std::max(bitaX + bitaUpdate, bitaWidth/2), widgetWidth - bitaWidth/2);
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
        bitaX = rand() % widgetWidth - (bitaWidth / 2);
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
    if (skipRot)
    {
        return;
    }
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
                   skipRot = 4;
                   break;
            }
        }
    }
}

void Widget::BallAngle(void)
{
    if(ballX > widgetWidth || ballX < 0)
    {
            speedBallX *= -1;
    }
    if((bitaX - bitaWidth /2 <= (ballX + ball->width()/2)) && (bitaX + bitaWidth/2 >= (ballX - ball->width()/2)) && (bitaY == (ballY + ball->height() / 2)))
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
    if (e->type() == QEvent::KeyRelease)
    {
        bitaUpdate = 0;
        return true;
    }
    return false;
}


void Widget::onKeyPressed(int key)
{
    if (key == Qt::Key_Right)
    {
        bitaUpdate = 3;
    }
    if (key == Qt::Key_Left)
    {
        bitaUpdate = -3;
    }
}

 void Widget::genBlocks()
 {
     int i = 0;
     int j = 0;
     for(i = 0; i < 9;i++)
     {
         for(j = 0; j < 9; j++)
         {
             blocksArr[j][i] = 0;
         }
     }
     for(i = 1; i < 9; i++)
     {
         for(j = 1; j < 9;j++)
         {
             blocksArr[j][i] = 5;
         }
     }
 }

void Widget::on_start_clicked()
{
       countLife = 3;
       genBlocks();
       idTimer = startTimer(10);
       ui->start->hide();
}

void Widget::on_restart_clicked()
{
    bitaX = rand() % widgetWidth - bitaWidth;
    ballX = bitaX;
    ballY = bitaY  - ball->height();
    speedBallY *=-1;
    countLife = 3;
    genBlocks();
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
