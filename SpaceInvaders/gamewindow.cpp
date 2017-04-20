#include "gamewindow.h"
#include <QDir>
#include <QCoreApplication>
#include <QPainter>
#include <QPixmap>

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

   // QPixmap *ship = new QPixmap("./images/spaceship.png");
   // QPainter painter(this);
  //  painter.drawPixmap(20, 20, 20, 20, *ship);
}

