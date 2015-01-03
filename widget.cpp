#include "widget.h"
#include "ui_widget.h"

#define PI 3.14159265;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
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
    draw.drawField(countLife,painter);
}

void Widget::timerEvent(QTimerEvent *)
{
   draw.field.UpdateBallandBita();
   if(draw.field.CheckBorders())
   {
       killTimer(idTimer);
       countLife--;
       if(countLife)
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
         draw.field.bitaUpdate = 0;
        return true;
    }
    return false;
}


void  Widget::onKeyPressed(int key)
{
    if (key == Qt::Key_Right)
    {
        draw.field.bitaUpdate = 3;
    }
    if (key == Qt::Key_Left)
    {
         draw.field.bitaUpdate = -3;
    }
}

void Widget::on_start_clicked()
{
       countLife = 3;
       draw.field.genBlocks();
       idTimer = startTimer(10);
       ui->start->hide();
}

void Widget::on_restart_clicked()
{
    draw.field.bitaX = rand() % (draw.field.widgetWidth - draw.field.bitaWidth) + draw.field.bitaWidth;
    draw.field.ballX = draw.field.bitaX;
    draw.field.ballY =draw.field.bitaY  - draw.field.Image.ball->height();
    draw.field.speedBallY *=-1;
    draw.field.paintPointsMid = 0;
    draw.field.paintPointsLeft = 0;
    draw.field.paintPointsRigth = 0;
    countLife = 3;
    draw.field.genBlocks();
    idTimer = startTimer(10);
    ui->restart->hide();
}
