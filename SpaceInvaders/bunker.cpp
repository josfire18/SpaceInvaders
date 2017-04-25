#include "bunker.h"
#include <QDir>
#include <QCoreApplication>

Bunker::Bunker(QWidget *parent):parent(parent)
{
#ifdef __APPLE__
    QDir bin(QCoreApplication::applicationDirPath());
    bin.cdUp();
    bin.cdUp();
    bin.cdUp();
    QDir::setCurrent(bin.absolutePath());
#endif
    pic1 = new QPixmap("./images/bunker.png");
    picX=(10);
    picY=(10);
    picHeight = 15;
    picWidth = 15;
    HP=4;
    paint = new QPainter();
}

void Bunker::drawBunker(QPainter &paint)
{
    paint.drawPixmap(picX,picY,picWidth,picHeight,*pic1);
}

void Bunker::setCoords(int newX, int newY)
{
    picX = newX;
    picY = newY;
}

int Bunker::getXCoord()
{
    return this->picX;
}

int Bunker::getYCoord()
{
    return this->picY;
}

void Bunker::setImage(QPixmap *imagefile)
{
    pic1=imagefile;
}

void Bunker::decrementHP()
{
    if(HP>0){
        HP--;
    }
}

int Bunker::getHP()
{
    return HP;
}
