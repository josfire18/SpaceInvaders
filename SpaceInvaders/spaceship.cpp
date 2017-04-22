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
    picX=(parent->width()/2-10);
    picY=(parent->height()-50);
    picHeight = 20;
    picWidth = 30;
    direction=0;
    paint = new QPainter();
}

void spaceship::drawSpaceship(QPainter &paint)
{
    paint.drawPixmap(picX,picY,picWidth,picHeight,*pic1);
}

void spaceship::updateCoordinate()
{
    if (direction==1){
        if(picX<(parent->width()-picWidth-5)){
            picX+=10;
        }
    }
    else if (direction==2){
        if(picX>4){
           picX-=10;
        }
    }
}

void spaceship::setDirection(int direc)
{
    direction=direc;
}

void spaceship::setY(int newY)
{
    if (newY < parent->height()-this->picY){
       // picY = newY;
    }
    else{
       // picY = 0;
    }
}
