#include "widget.h"
#include "ui_widget.h"

#define PI 3.14159265;

Widget::Widget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget),
    MyField(Image),
    Draw(MyField, Image)
{
    QApplication::instance()->installEventFilter(this);
    ui->setupUi(this);
    ui->restart->hide();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    Draw.drawField(painter);
}

void Widget::timerEvent(QTimerEvent *)
{
    MyField.UpdateBallandBita();
    if(MyField.CheckBorders())
    {
        killTimer(idTimer);
        if(MyField.countLife)
        {
            idTimer = startTimer(10);
        }
        else
        {
            ui->restart->show();
        }
    }
    update();
}

bool Widget::eventFilter(QObject *, QEvent *e)
{
    if (e->type() == QEvent::KeyPress)
    {
        onKeyPressed(((QKeyEvent*)e)->key());
        return true;
    }
    if (e->type() == QEvent::KeyRelease)
    {
        MyField.StopMoveBita();
        return true;
    }
    return false;
}


void  Widget::onKeyPressed(int key)
{
    if (key == Qt::Key_Right)
    {
        MyField.MoveBita(true);
    }
    if (key == Qt::Key_Left)
    {
        MyField.MoveBita(false);
    }
}

void Widget::on_start_clicked()
{
    MyField.countLife = 3;
    MyField.genBlocks();
    idTimer = startTimer(10);
    ui->start->hide();
}

void Widget::on_restart_clicked()
{
    MyField.bitaX = rand() % (MyField.widgetWidth - MyField.bitaWidth) + MyField.bitaWidth;
    MyField.ballX = MyField.bitaX;
    MyField.ballY = MyField.bitaY  - Image.GetBall().height();
    MyField.speedBallY *=-1;
    MyField.paintPointsMid = 0;
    MyField.paintPointsLeft = 0;
    MyField.paintPointsRigth = 0;
    MyField.countLife = 3;
    MyField.genBlocks();
    idTimer = startTimer(10);
    ui->restart->hide();
}
