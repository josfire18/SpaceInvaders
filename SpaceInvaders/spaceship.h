#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QPixmap>


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

private:
    int direction;
    int picX,picY;
    QPixmap* pic1;
    int picHeight, picWidth;
    QWidget* parent;
    QPainter* paint;
};

#endif // SPACESHIP_H
