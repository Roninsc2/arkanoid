#include "widget.h"
#include "ui_widget.h"

#define PI 3.14159265;

Widget::Widget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget),
    MyField(Image, Sound),
    Draw(MyField, Image)
{
    QApplication::instance()->installEventFilter(this);
    ui->setupUi(this);
    ui->restart->hide();
    ui->nextLevel->hide();
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
    MyField.updateBallandBita();
    if( MyField.checkBorders() ) {
        killTimer( idTimer );
        if( MyField.countLife && MyField.blocksCount ) {
            idTimer = startTimer(15);
        }
        else {
            if(MyField.blocksCount == 0) {
                ui->nextLevel->show();
            }
            else {
                if(MyField.countLife) {
                    idTimer = startTimer(15);
                }
                else {
                    ui->restart->show();
                }
            }
        }
    }
    update();
}

bool Widget::eventFilter(QObject *, QEvent *e)
{
    if (e->type() == QEvent::KeyPress) {
        onKeyPressed(((QKeyEvent*)e)->key());
        return true;
    }
    if (e->type() == QEvent::KeyRelease) {
        MyField.stopMoveBita();
        return true;
    }
    return false;
}


void  Widget::onKeyPressed(int key)
{
    if (key == Qt::Key_Right) {
        MyField.moveBita(true);
    }
    if (key == Qt::Key_Left) {
        MyField.moveBita(false);
    }
}

void Widget::on_start_clicked()
{
    MyField.level = -1;
    MyField.countLife = 3;
    MyField.generationBlocks();
    idTimer = startTimer(15);
    ui->start->hide();
}

void Widget::on_restart_clicked()
{
    MyField.level = 0;
    MyField.bitaX = rand() % (int)(MyField.widgetWidth - MyField.bitaWidth) + MyField.bitaWidth;
    MyField.ballX = MyField.bitaX;
    MyField.ballY = MyField.bitaY  - Image.getBall().height();
    MyField.speedBallY *=-1;
    MyField.pointsMid = 0;
    MyField.pointsLeft = 0;
    MyField.pointsRigth = 0;
    MyField.countLife = 3;
    MyField.generationBlocks();
    idTimer = startTimer(15);
    ui->restart->hide();
}

void Widget::on_nextLevel_clicked()
{
    MyField.level += 1;
    MyField.generationBlocks();
    idTimer = startTimer(10);
    ui->nextLevel->hide();
}
