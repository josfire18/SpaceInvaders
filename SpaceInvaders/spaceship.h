#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QPixmap>
using namespace std;


class spaceship: public QWidget
{
    Q_OBJECT

public:

    spaceship(QWidget *parent=0);
    void drawSpaceship(QPainter& paint);
    void updateCoordinate();
    void setDirection(int direc);
    void setCoords(int newX, int newY);
    int getXCoord();
    int getYCoord();
    void setImage(QPixmap *imagefile);
    void setSpeed(int newSpeed);
    void setIsSaucer();
    void setMonsterType(int mtype);
    int getMonsterType();

private:
    int direction;
    int picX,picY;
    QPixmap* pic1;
    int picHeight, picWidth;
    QWidget* parent;
    QPainter* paint;
    int speed;
    bool isSaucer;
    int monsterType;
};

#endif // SPACESHIP_H
