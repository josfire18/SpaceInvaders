#include "spaceship.h"
#include <QDir>
#include <QCoreApplication>

spaceship::spaceship(QWidget *parent):parent(parent)
{
#ifdef __APPLE__
    QDir bin(QCoreApplication::applicationDirPath());
    bin.cdUp();
    bin.cdUp();
    bin.cdUp();
    QDir::setCurrent(bin.absolutePath());
#endif
    pic1 = new QPixmap("./images/spaceship.png");
    picX=(10);
    picY=(10);
    picHeight = 20;
    picWidth = 30;
    direction=0;
    speed=3;
    paint = new QPainter();
}

void spaceship::drawSpaceship(QPainter &paint)
{
    paint.drawPixmap(picX,picY,picWidth,picHeight,*pic1);
}

void spaceship::updateCoordinate()
{
    if (direction==1){
        if(picX<(parent->width()-picWidth-4)){
            picX+=speed;
        }
    }
    else if (direction==2){
        if(picX>4){
           picX-=speed;
        }
    }
}

void spaceship::setDirection(int direc)
{
    direction=direc;
}

void spaceship::setCoords(int newX, int newY)
{
    picX=newX;
    picY=newY;
}

int spaceship::getXCoord()
{
    return this->picX;
}

int spaceship::getYCoord()
{
    return this->picY;
}

void spaceship::setImage(QPixmap *imagefile)
{
    pic1=imagefile;
}

void spaceship::setSpeed(int newSpeed)
{
    this->speed=newSpeed;
}
