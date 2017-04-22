#include "projectile.h"
#include <QDir>
#include <QCoreApplication>

projectile::projectile(QWidget *parent):parent(parent)
{
#ifdef __APPLE__
    QDir bin(QCoreApplication::applicationDirPath());
    bin.cdUp();
    bin.cdUp();
    bin.cdUp();
    QDir::setCurrent(bin.absolutePath());
#endif
    pic1 = new QPixmap("./images/projectile.png");
    picX=(10);
    picY=(10);
    picHeight = 15;
    picWidth = 10;
    direction=0;
    paint = new QPainter();
}

void projectile::drawProjectile(QPainter &paint)
{
    paint.drawPixmap(picX,picY,picWidth,picHeight,*pic1);
}

void projectile::updateCoordinate()
{
    //UP: User Fires
    if(direction == 3)
    {
        if(picY<(parent->height()-picHeight-5))
        {
            picY+=10;
        }
    }
    //Down: Enemy Fires
    else if(direction == 4)
    {
        if(picY<(parent->height()-picHeight-5))
        {
            picY-=10;
        }
    }
}

void projectile::setDirection(int direc)
{
    direction = direc;
}

void projectile::setCoords(int newX, int newY)
{
    picX = newX;
    picY = newY;
}

int projectile::getXCoord()
{
    return this->picX;
}

int projectile::getYCoord()
{
    return this->picY;
}

void projectile::setImage(string filepath)
{

}

