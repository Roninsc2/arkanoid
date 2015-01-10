#include "field.h"
#include <algorithm>
#include <iostream>

TField::TField(TImageManager &_image):
    image(_image)
{
    blocksArray.resize(blocksArrayHeight);
    for(int i = 0; i < blocksArrayHeight; i++) {
        blocksArray[i].resize(blocksArrayWidth);
    }
    bitaX = rand() % (widgetWidth - bitaWidth) + bitaWidth;
    ballX = bitaX;
    ballY = bitaY - image.getBall().height();
}

void TField::updateBallandBita()
{
    ballX += speedBallX;
    ballY -= speedBallY;
    bitaX = std::min(std::max(bitaX + bitaUpdate, bitaWidth/2), widgetWidth - bitaWidth/2);
}

int TField::checkBorders()
{
    ballAngle();
    if(ballY == widgetHeight) {
        bitaX = rand() % (widgetWidth - bitaWidth) + bitaWidth;
        ballX = bitaX;
        ballY = bitaY  - image.getBall().height();
        speedBallY *=-1;
        countLife--;
        return 1;
    }
    int i = 0;
    int j = 0;
    for(i = 0; i < blocksArrayHeight;i++) {
        for(j = 0; j < blocksArrayWidth; j++) {
            int brickLeft = j*brickWidth;
            int brickTop =  i* brickHeight;
            int brickRight = brickLeft + brickWidth;
            int brickBottom = brickTop + brickHeight;

            if(!blocksArray[j][i]) {
                continue;
            }
            if (((ballX - image.getBall().width()/2) < (brickRight)) &&
                    ((ballX + image.getBall().width()/2) >= (brickLeft)) &&
                    ((brickBottom) > (ballY - image.getBall().height()/2)) &&
                     ((ballY + image.getBall().height()/2)>= (brickTop)))
            {
                float distanceVert = std::min(abs(ballY + image.getBall().height()/2 - (brickTop)),
                                            abs(ballY - image.getBall().height()/2 - (brickBottom)));
                float distanceHoriz = std::min(abs (ballX + image.getBall().width()/2- (brickLeft)),
                                             abs(ballX- image.getBall().width()/2- (brickRight)));
                if(distanceVert < distanceHoriz) {
                    speedBallY *=-1;
                }
                else {
                    if(distanceVert > distanceHoriz) {
                        speedBallX *= -1;
                    }
                    else {
                        speedBallX *=-1;
                        speedBallY *=-1;
                    }
                }
                countPoints();
                blocksArray[j][i]--;
                if(blocksArray[i][j] == 0)
                {
                    blocksCount--;
                }
                return 0;
            }
        }
    }
    if(blocksCount == 0)
    {

        return 1;
    }
    return 0;
}

void TField::ballAngle(void)
{
    if(ballX > widgetWidth || ballX < 0) {
        speedBallX *= -1;
    }
    if(((bitaX - bitaWidth /2) <= (ballX + image.getBall().width()/2)) &&
            ((bitaX + bitaWidth/2) >= (ballX - image.getBall().width()/2)) &&
            (bitaY == (ballY + image.getBall().height() / 2)))
    {
        speedBallY *= -1;
    }
    else {
        if(ballY > widgetHeight || ballY < 0) {
            speedBallY *= -1;
        }
    }
}

void TField::generationBlocks()
{
    std::string adress = "levels/"+std::to_string(level) + "_level.txt";
    std::ifstream field;
    field.open(adress);
    int i = 0;
    int j = 0;
    int temp = 0;
    for(i = 0; i <  blocksArrayHeight; i++) {
        for(j = 0; j < blocksArrayWidth; j++) {
            field >> temp;
            if(temp !=  0)
            {
                blocksCount++;
            }
            blocksArray[j][i] = temp;
        }
    }
    field.close();
}

void TField::countPoints (void)
{
    if(pointsRigth == 9) {
        if(pointsMid == 9) {
            pointsMid = 0;
            pointsRigth = 0;
            pointsLeft++;

        }
        else {
            pointsMid++;
            pointsRigth = 0;
        }
    }
    else {
        pointsRigth++;
    }
}

void TField::moveBita(bool move)
{
    if(move == true) {
        bitaUpdate = 3;
    }
    else {
        bitaUpdate = -3;
    }
}

void TField::stopMoveBita()
{
    bitaUpdate = 0;
}

