#include "widget.h"
#include "ui_widget.h"
#include <algorithm>
#include <string>

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
    bricks.resize(5);
    std::string adress;
    for(i = 0; i < 10; i++)
    {
        adress = ":/images/"+std::to_string(i)+"_point.gif";
        points[i] = new QMovie(adress.c_str());
    }
    ball= new QImage;
    bita = new QImage;
    genBlocks();
    ui->setupUi(this);
    ui->restart->hide();
    ball->load(":/images/ball.png");
    bita->load(":/images/Bita.bmp");
    int j = 0;
    for(i = 4; i >= 0; i--, j++)
    {

        bricks[i] = new QImage;
        adress = ":/images/"+std::to_string(j) + "_brick.png";
        bricks[i]->load(adress.c_str());
    }
    ballY = bitaY - ball->height();
}

Widget::~Widget()
{
    int i;
    for(i = 0; i < 10; i++)
    {
        delete points[i];
    }
    delete ball;
    delete bita;
    for(i = 0; i < 5; i++)
    {
        delete bricks[i];
    }
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
         for(int i = 0; i < 10; i++)
         {
             if(paintPointsMid == i)
             {
                 painter.drawPixmap(50,640,points[i]->currentPixmap());
                 points[i]->start();
             }
             if(paintPointsLeft == i)
             {
                 painter.drawPixmap(10,640,points[i]->currentPixmap());
                 points[i]->start();
             }
             if(paintPointsRigth == i)
             {
                 painter.drawPixmap(90,640,points[i]->currentPixmap());
                 points[i]->start();
             }
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
                     for(int k = 5; k >= 1; k--)
                     {
                         if(blocksArr[i][j] == k)
                         {
                              painter.drawImage(i*brickSW + gapX*i, j*brickSH + gapY*j, *bricks[k-1], 0, 0, brickSW,brickSH);
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
