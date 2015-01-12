#ifndef WIDGET_
#define WIDGET_H
#include <QWidget>
#include <QTimer>
#include "drawer.h"
#include "sound.h"


namespace Ui {
class Widget;
}

class TWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TWidget(QWidget *parent = 0);
    ~TWidget();
    void timerEvent(QTimerEvent *);
    void paintEvent(QPaintEvent *);
    bool eventFilter(QObject *, QEvent *e);
    void onKeyPressed(int key);
    void onShiftPressed();
    void onSpacePressed();
    void startGame();
    void restartGame();
    void nextLevel();

public:
    int idTimer;
    Ui::Widget *ui;
    TImageManager Image;
    TSound Sound;
    TField MyField;
    TDrawer Draw;
};

#endif // WIDGET_H
