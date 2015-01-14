#include "sound.h"

TSound::TSound()
{
    sounds.resize(ST_Count);
    sounds[ST_BitaHit] = new QSound("sounds/bita.wav");
    sounds[ST_BlockHit] = new QSound("sounds/block.wav");
    sounds[ST_GameOver] = new QSound("sounds/gameover.wav");
    sounds[ST_NewLevel] = new QSound("sounds/nextlevel.wav");
    sounds[ST_GameWin] = new QSound("sounds/gamewin.wav");
}

void TSound::onBlockHit()
{
    sounds[ST_BlockHit]->play();
}

void TSound::onBitaHit()
{
    sounds[ST_BitaHit]->play();
}

void TSound::onGameOver()
{
    sounds[ST_GameOver]->play();
}

void TSound::onNewLevel()
{
    sounds[ST_NewLevel]->play();
}

void TSound::onGameWin()
{
    sounds[ST_GameWin]->play();
}
