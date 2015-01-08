#include "ImageManager.h"
#include "field.h"
#include <algorithm>

Field::Field(ImageManager &_image):
    image(_image)
{
    blocksArray.resize(9);
    for(int i = 0; i < 9; i++)
    {
        blocksArray[i].resize(9);
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
            int brickLeft = i*brickWidth;
            int brickTop = j * brickHeight;
            int brickRight = brickLeft + brickWidth;
            int brickBottom = brickTop + brickHeight;

            if (!blocksArray[i][j]) {
                continue;
            }

            if (((ballX - image.GetBall().width()/2) < (brickRight + gapX*i)) &&
                    ((ballX + image.GetBall().width()/2) >= (brickLeft + gapX*i)) &&
                    ((brickBottom + gapY*j) > (ballY - image.GetBall().height()/2)) &&
                     ((ballY + image.GetBall().height()/2)>= (brickTop + gapY*j)))
            {
                int distanceVert = std::min(abs(ballY + image.GetBall().height()/2 - (brickTop + gapY*j)),
                                            abs(ballY - image.GetBall().height()/2 - (brickBottom + gapY*j)));
                int distanceHoriz = std::min(abs (ballX + image.GetBall().width()/2- (brickLeft + gapX*i)),
                                             abs(ballX- image.GetBall().width()/2- (brickRight + gapX*i)));
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
                blocksArray[i][j]--;
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
    if(((bitaX - bitaWidth /2) <= (ballX + image.GetBall().width()/2)) &&
            ((bitaX + bitaWidth/2) >= (ballX - image.GetBall().width()/2)) &&
            (bitaY == (ballY + image.GetBall().height() / 2)))
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

void Field::GenerationBlocks(void)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < 9;i++)
    {
        for(j = 0; j < 9; j++)
        {
            blocksArray[j][i] = 0;
        }
    }
    for(i = 1; i < 9; i++)
    {
        for(j = 1; j < 9;j++)
        {
            blocksArray[j][i] = 5;
        }
    }
}

void Field::CountPoints (void)
{
    if(pointsRigth == 9)
    {
        if(pointsMid == 9)
        {
            pointsMid = 0;
            pointsRigth = 0;
            pointsLeft++;

        }
        else
        {
            pointsMid++;
            pointsRigth = 0;
        }
    }
    else
    {
        pointsRigth++;
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

