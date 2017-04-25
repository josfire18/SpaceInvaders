#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QPixmap>
using namespace std;


class projectile: public QWidget
{
    Q_OBJECT

public:

    projectile(QWidget *parent=0);
    void drawProjectile(QPainter& paint);
    void updateCoordinate();
    void setDirection(int direc);
    void setCoords(int newX, int newY);
    int getXCoord();
    int getYCoord();
    void setImage(QPixmap *imagefile);
    int getDirection();

private:
    int direction;
    int picX,picY;
    QPixmap* pic1;
    int picHeight, picWidth;
    QWidget* parent;
    QPainter* paint;
};

#endif // PROJECTILE_H
