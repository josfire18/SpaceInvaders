#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QWidget>
#include "spaceship.h"
#include <QTimer>
#include <QTime>


class gameWindow: public QWidget
{
    Q_OBJECT


private:
    QTimer* timer;
    QTime* clock;
    spaceship *player;
    QPainter* paint;
    int score;

public:
    explicit gameWindow(QWidget *parent = 0);
    ~gameWindow();
    void  paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *evt);
    void stopTimer();

private slots:
    void updateCoordinates();
    void updateDirection(int direc);
};

#endif // GAMEWINDOW_H
