#include "drawer.h"

Drawer::Drawer(Field & _field, ImageManager & _image):
    field(_field), image(_image){}

void Drawer::drawField(QPainter & painter)
{
    if(field.countLife)
    {
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setBrush(Qt::blue);
        painter.setPen(Qt::blue);
        painter.drawImage(field.ballX - image.GetBall().width() / 2, field.ballY - image.GetBall().height() / 2, image.GetBall(), 0, 0, image.GetBall().width(), image.GetBall().height());
        painter.drawRect(field.bitaX - field.bitaWidth/2,field.bitaY-field.bitaHeight/2, field.bitaWidth, field.bitaHeight);
        for(int i = 0; i < 10; i++)
        {
            if(field.paintPointsMid == i)
            {
                painter.drawPixmap(50,640,image.GetPoint(i).currentPixmap());
                image.GetPoint(i).start();
            }
            if(field.paintPointsLeft == i)
            {
                painter.drawPixmap(10,640,image.GetPoint(i).currentPixmap());
                image.GetPoint(i).start();
            }
            if(field.paintPointsRigth == i)
            {
                painter.drawPixmap(90,640,image.GetPoint(i).currentPixmap());
                image.GetPoint(i).start();
            }
        }
        for(int i = 1; i <= field.countLife; i++)
        {
            painter.drawImage(i*12, image.GetBall().height(), image.GetBall(), 0, 0, image.GetBall().width(), image.GetBall().height());
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
                            painter.drawImage(i*field.brickSW + gapX*i, j*field.brickSH + gapY*j, image.GetBrick(k-1), 0, 0, field.brickSW,field.brickSH);
                        }
                    }

                }

            }
        }
    }
}
