#ifndef BUNKER_H
#define BUNKER_H
#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QPixmap>
using namespace std;


class Bunker: public QWidget
{
    Q_OBJECT

public:
    Bunker(QWidget *parent=0);
    void drawBunker(QPainter& paint);
    void setCoords(int newX, int newY);
    int getXCoord();
    int getYCoord();
    void setImage(QPixmap *imagefile);
    void decrementHP();
    int getHP();

private:
    int picX,picY;
    QPixmap* pic1;
    int picHeight, picWidth;
    QWidget* parent;
    QPainter* paint;
    int HP;
};

#endif // BUNKER_H
