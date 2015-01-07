#include "ImageManager.h"
#include "field.h"
#include <algorithm>

Field::Field(ImageManager & _image):
    image(_image)
{
    blocksArr.resize(9);
    for(int i = 0; i < 9; i++)
    {
        blocksArr[i].resize(9);
    }
    bitaX = rand() % (widgetWidth - bitaWidth) + bitaWidth;
    ballX = bitaX;
    ballY = bitaY - image.GetBall().height();
}

void Field::UpdateBallandBita()
{
    ballX += speedBallX;
    ballY -= speedBallY;
    bitaX = std::min(std::max(bitaX + bitaUpdate, bitaWidth/2), widgetWidth - bitaWidth/2);
}

int Field::CheckBorders()
{
    if(skipRot > 0)
    {
        skipRot--;
    }
    BallAngle();
    if(ballY == widgetHeight)
    {
        bitaX = rand() % (widgetWidth - bitaWidth) + bitaWidth;
        ballX = bitaX;
        ballY = bitaY  - image.GetBall().height();
        speedBallY *=-1;
        countLife--;
        return 1;
    }
    if (skipRot)
    {
        return 0;
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

            if ((ballX - image.GetBall().width()/2) < (brickRight + gapX*i) && (ballX + image.GetBall().width()/2 >= brickLeft + gapX*i) && (brickBottom + gapY*j > ballY - image.GetBall().height()/2 && ballY + image.GetBall().height()/2>= brickTop + gapY*j))
            {
                int distanceVert = std::min(abs(ballY + image.GetBall().height()/2 - (brickTop + gapY*j)), abs(ballY - image.GetBall().height()/2 - (brickBottom + gapY*j)));
                int distanceHoriz = std::min(abs (ballX + image.GetBall().width()/2- (brickLeft + gapX*i)), abs(ballX- image.GetBall().width()/2- (brickRight + gapX*i)));
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
    return 0;
}

void Field::BallAngle(void)
{
    if(ballX > widgetWidth || ballX < 0)
    {
        speedBallX *= -1;
    }
    if((bitaX - bitaWidth /2 <= (ballX + image.GetBall().width()/2)) && (bitaX + bitaWidth/2 >= (ballX - image.GetBall().width()/2)) && (bitaY == (ballY + image.GetBall().height() / 2)))
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

void Field::genBlocks()
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

void Field::CountPoints(void)
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

void Field::MoveBita(bool move)
{
    if(move == true)
    {
        bitaUpdate = 3;
    }
    else
    {
        bitaUpdate = -3;
    }
}

void Field::StopMoveBita()
{
    bitaUpdate = 0;
}

