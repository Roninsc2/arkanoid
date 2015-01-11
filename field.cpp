#include "field.h"
#include <algorithm>
#include <iostream>

const float PI = 3.14;

TField::TField(TImageManager &_image, TSound &_sound):
    image(_image),
    sound(_sound)
{
    blocksArray.resize(blocksArrayHeight);
    blocksTtl.resize(blocksArrayHeight);
    for(int i = 0; i < blocksArrayHeight; i++) {
        blocksArray[i].resize(blocksArrayWidth);
        blocksTtl[i].resize(blocksArrayWidth);
    }
    bitaX = rand() % (int)(widgetWidth - bitaWidth) + bitaWidth;
    ballX = bitaX;
    ballY = bitaY - bitaHeight / 2  - image.getBall().height() / 2;
}

void TField::updateBallandBita()
{
    ballX += speedBallX;
    ballY -= speedBallY;
    bitaX = std::min(std::max(bitaX + bitaSpeedX, (float)bitaWidth/2), (float)widgetWidth - bitaWidth/2);
}

int TField::checkBorders()
{
    ballAngle();
    if(ballY == widgetHeight) {
        bitaX = rand() % (int)(widgetWidth - bitaWidth) + bitaWidth;
        ballX = bitaX;
        ballY = bitaY - bitaHeight / 2  - image.getBall().height() / 2;
        speedBallY *=-1;
        countLife--;
        return 1;
    }
    int i = 0;
    int j = 0;
    for(i = 0; i < blocksArrayHeight;i++) {
        for(j = 0; j < blocksArrayWidth; j++) {
            if (blocksTtl[j][i] > 0) {
                --blocksTtl[j][i];
                continue;
            }

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
                if(distanceVert <= distanceHoriz) {
                    speedBallY *=-1;
                }
                else {
                    speedBallX *= -1;
                }
                sound.onBlockHit();
                countPoints();
                blocksArray[j][i]--;
                if(blocksArray[i][j] == 0){
                    blocksCount--;
                }
                blocksTtl[j][i] = 5;
                return 0;
            }
        }
    }
    if(blocksCount == 0){

        return 1;
    }
    return 0;
}

float calcFallAngle(float x, float y) {
    if (x > 0) {
        return atan(y / x);
    }
    if (x < 0 && y >= 0) {
        return atan(y / x) + PI;
    }
    if (x < 0 && y < 0) {
        return atan(y / x) - PI;
    }
    if (x == 0 && y > 0) {
        return PI / 2;
    }
    return -PI / 2;
}

void TField::ballAngle(void)
{
    if (bitaHitTtl > 0) {
        --bitaHitTtl;
    }
    if(ballX > widgetWidth || ballX < 0) {
        speedBallX *= -1;
        sound.onBlockHit();
        return;
    } else if((bitaX - bitaWidth /2 <= ballX + image.getBall().width()/2) &&
            (bitaX + bitaWidth/2 >= ballX - image.getBall().width()/2) &&
            (ballY + image.getBall().height() / 2 <= bitaY + bitaHeight / 2) &&
              (ballY + image.getBall().height() / 2 >= bitaY - bitaHeight / 2) && bitaHitTtl == 0)
    {
        // Определяем угол падения
        float fallAngle = calcFallAngle(speedBallX, speedBallY);

        // 1) угол падения равен углу отражения:
        float resAngle = fabs(fallAngle);

        // 2) если бита двигается - поворачиваем угол в сторону движения:
        if (bitaSpeedX > 0) {
            resAngle -= 1.4;
        } else if (bitaSpeedX < 0) {
            resAngle += 1.4;
        } else {
            // 3) если бита стоит - поварачиваем угол в зависимости от части биты:
            resAngle += 1.5 * (bitaX - ballX) / (bitaWidth / 2);
        }

        // Не даем шарику отразится вниз
        if (resAngle < 0.2 && resAngle > -1.57) {
            resAngle = 0.2;
        }
        if (resAngle > 2.65) {
            resAngle = 2.65;
        }

        // Считаем новую скорость биты
        float absBallSpeed = sqrt(speedBallX * speedBallX + speedBallY * speedBallY);

        speedBallX = absBallSpeed * cos(resAngle);
        speedBallY = absBallSpeed * sin(resAngle);

        sound.onBitaHit();
        bitaHitTtl = 15;
    }
    else if(ballY > widgetHeight || ballY < 0) {
        speedBallY *= -1;
        sound.onBlockHit();
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
            if(temp !=  0) {
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
        bitaSpeedX = 3;
    }
    else {
        bitaSpeedX = -3;
    }
}

void TField::stopMoveBita()
{
    bitaSpeedX = 0;
}

