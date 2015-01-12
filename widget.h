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

public:
    int idTimer;
    Ui::Widget *ui;
    TImageManager Image;
    TSound Sound;
    TField MyField;
    TDrawer Draw;

private slots:
    void on_nextLevel_clicked();

    void on_start_clicked();

    void on_restart_clicked();
};

#endif // WIDGET_H
