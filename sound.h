#ifndef SOUND_H
#define SOUND_H

#include <QSound>
#include <QVector>

enum ESoundType {
    ST_BlockHit,
    ST_BitaHit,
    ST_GameOver,
    ST_NewLevel,
    ST_GameWin,

    ST_Count
};

class TSound
{
public:
    TSound();
    void onBlockHit();
    void onBitaHit();
    void onGameOver();
    void onNewLevel();
    void onGameWin();
private:
    QVector<QSound*> sounds;
};

#endif // SOUND_H
