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
    Ui::Widget *ui;
    ImageManager Image;
    Field MyField;
    Drawer Draw;



public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public:
    int idTimer;

public slots:
    void on_start_clicked();

    void on_restart_clicked();

public:
    void timerEvent(QTimerEvent *);
    void paintEvent(QPaintEvent * );
    bool eventFilter(QObject *, QEvent *e);
    void onKeyPressed(int key);


};

#endif // WIDGET_H
