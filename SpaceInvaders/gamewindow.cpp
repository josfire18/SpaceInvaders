#include "gamewindow.h"
#include <QDir>
#include <QCoreApplication>
#include <QPainter>
#include <QPixmap>
#include <QKeyEvent>
#include <QTimer>
#include <ctime>
#include <QTime>

gameWindow::gameWindow(QWidget *parent) :
    QWidget(parent)
{
#ifdef __APPLE__
    QDir bin(QCoreApplication::applicationDirPath());
    bin.cdUp();
    bin.cdUp();
    bin.cdUp();
    QDir::setCurrent(bin.absolutePath());
#endif
    this->setStyleSheet("background-color: black;");

    score =0;
    clock = new QTime();
    clock->start();
    timer = new QTimer();
    timer->setInterval(50);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateCoordinates()));
    timer->start();
    player = new spaceship(this);
    player->setY(50);
    player->setDirection(1);
}

gameWindow::~gameWindow()
{
    delete timer;
}

void gameWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    player->drawSpaceship(painter);
    painter.drawText(10,10, QString::number(score));
}

void gameWindow::keyPressEvent(QKeyEvent *evt)
{
    if (evt->key()==Qt::Key_Left){
        updateDirection(2);
    }
    else if (evt->key()==Qt::Key_Right){
        updateDirection(1);
    }
    player->updateCoordinate();
}

void gameWindow::stopTimer()
{
    timer->stop();
}

void gameWindow::updateCoordinates()
{
    score++;
    this->update();
}

void gameWindow::updateDirection(int direc)
{
    player->setDirection(direc);
    this->update();
}

