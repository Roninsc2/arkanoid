#include "drawer.h"


void Drawer::drawField(int countLife, QPainter & painter)
{
    if(countLife)
    {
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setBrush(Qt::blue);
        painter.setPen(Qt::blue);
        painter.drawImage(field.ballX - field.Image.ball->width() / 2, field.ballY - field.Image.ball->height() / 2, *field.Image.ball, 0, 0, field.Image.ball->width(), field.Image.ball->height());
        painter.drawRect(field.bitaX - field.bitaWidth/2,field.bitaY-field.bitaHeight/2, field.bitaWidth, field.bitaHeight);
        for(int i = 0; i < 10; i++)
        {
            if(field.paintPointsMid == i)
            {
                painter.drawPixmap(50,640,field.Image.points[i]->currentPixmap());
                field.Image.points[i]->start();
            }
            if(field.paintPointsLeft == i)
            {
                painter.drawPixmap(10,640,field.Image.points[i]->currentPixmap());
               field.Image.points[i]->start();
            }
            if(field.paintPointsRigth == i)
            {
                painter.drawPixmap(90,640,field.Image.points[i]->currentPixmap());
                field.Image.points[i]->start();
            }
        }
        for(int i = 1; i <= countLife; i++)
        {
            painter.drawImage(i*12, field.Image.ball->height(), *field.Image.ball, 0, 0, field.Image.ball->width(), field.Image.ball->height());
        }
        int gapX = 40;
        int gapY  = 0;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(field.blocksArr[i][j] != 0)
                {
                    for(int k = 5; k >= 1; k--)
                    {
                        if(field.blocksArr[i][j] == k)
                        {
                             painter.drawImage(i*field.brickSW + gapX*i, j*field.brickSH + gapY*j, *field.Image.bricks[k-1], 0, 0, field.brickSW,field.brickSH);
                        }
                    }

                }

            }
        }
    }
}
