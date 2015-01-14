#include "widget.h"
#include "ui_widget.h"

#define PI 3.14159265;

TWidget::TWidget(QWidget *parent):
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

TWidget::~TWidget()
{
    delete ui;
}

void TWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    Draw.drawField(painter);
}

void TWidget::timerEvent(QTimerEvent *)
{
    MyField.updateBallandBita();
    if( MyField.checkBorders() ) {
        killTimer( idTimer );
        if( MyField.countLife && MyField.blocksCount ) {
            idTimer = startTimer(10);
        }
        else {
            if(MyField.blocksCount == 0) {
                ui->nextLevel->show();
            }
            else {
                if(MyField.countLife) {
                    idTimer = startTimer(10);
                }
                else {
                    Sound.onGameOver();
                    ui->restart->show();
                }
            }
        }
    }
    update();
}

bool TWidget::eventFilter(QObject *, QEvent *e)
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


void  TWidget::onKeyPressed(int key)
{
    if (key == Qt::Key_Right) {
        MyField.moveBita(true);
    }
    if (key == Qt::Key_Left) {
        MyField.moveBita(false);
    }
    if(key == Qt::Key_Space)
    {
        if(ui->start->isVisible())
        {
            startGame();
        }
        if(ui->nextLevel->isVisible())
        {
            nextLevel();
        }
        if(ui->restart->isVisible())
        {
            restartGame();
        }
    }
}

void TWidget::startGame()
{
    MyField.level = -1;
    MyField.countLife = 3;
    MyField.generationBlocks();
    idTimer = startTimer(10);
    ui->start->hide();
}

void TWidget::restartGame()
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
    idTimer = startTimer(10);
    ui->restart->hide();
}

void TWidget::nextLevel()
{
    MyField.bitaX = rand() % (int)(MyField.widgetWidth - MyField.bitaWidth) + MyField.bitaWidth;
    MyField.ballX = MyField.bitaX;
    MyField.ballY = MyField.bitaY  - Image.getBall().height();
    MyField.level += 1;
    MyField.generationBlocks();
    idTimer = startTimer(10);
    ui->nextLevel->hide();
}
