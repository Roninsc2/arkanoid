#include "drawer.h"

TDrawer::TDrawer(TField &_field, TImageManager &_image):
    field(_field), image(_image){}

void TDrawer::drawField(QPainter &painter)
{
    if(field.countLife) {
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setBrush(Qt::blue);
        painter.setPen(Qt::blue);
        painter.drawImage((field.ballX - image.getBall().width() / 2),
                          (field.ballY - image.getBall().height() / 2),
                          image.getBall(), 0, 0, image.getBall().width(), image.getBall().height());
        painter.drawRect((field.bitaX - field.bitaWidth/2),
                         (field.bitaY-field.bitaHeight/2),
                         field.bitaWidth, field.bitaHeight);
        for(int i = 0; i < 10; i++) {
            if(field.pointsMid == i) {
                painter.drawPixmap(50,640,image.getPoint(i).currentPixmap());
                image.getPoint(i).start();
            }
            if(field.pointsLeft == i) {
                painter.drawPixmap(10,640,image.getPoint(i).currentPixmap());
                image.getPoint(i).start();
            }
            if(field.pointsRigth == i) {
                painter.drawPixmap(90,640,image.getPoint(i).currentPixmap());
                image.getPoint(i).start();
            }
        }
        for(int i = 1; i <= field.countLife; i++) {
            painter.drawImage(i*12, image.getBall().height(), image.getBall(),
                              0, 0, image.getBall().width(), image.getBall().height());
        }
        for(int i = 0; i < field.blocksArrayHeight; i++) {
            for(int j = 0; j < field.blocksArrayWidth; j++) {
                if( field.blocksArray[j][i] ) {
                    for(int k = 5; k >= 1; k--) {
                        if(field.blocksArray[j][i] == k) {
                            painter.drawImage((j*field.brickWidth), (i*field.brickHeight),
                                              image.getBrick(k-1), 0, 0, field.brickWidth,field.brickHeight);
                        }
                    }

                }

            }
        }
    }
}
