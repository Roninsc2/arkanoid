#ifndef WIDGET_
#define WIDGET_H
#include <QWidget>
#include <QTimer>
#include "drawer.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void timerEvent(QTimerEvent *);
    void paintEvent(QPaintEvent *);
    bool eventFilter(QObject *, QEvent *e);
    void onKeyPressed(int key);

public slots:
    void on_start_clicked();

    void on_restart_clicked();

public:
    int idTimer;
    Ui::Widget *ui;
    TImageManager Image;
    TField MyField;
    TDrawer Draw;


private slots:
    void on_nextLevel_clicked();
};

#endif // WIDGET_H
