#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QWidget>
#include "spaceship.h"
#include <QTimer>
#include <QTime>
#include <QVector>
#include <QDir>
#include <QCoreApplication>
#include <QPainter>
#include <QPixmap>
#include <QKeyEvent>
#include <ctime>
#include <QMessageBox>
using namespace std;


class gameWindow: public QWidget
{
    Q_OBJECT


private:
    QTimer* timer;
    QTime* clock;
    spaceship *player;
    QPainter* paint;
    int score;
    vector<spaceship*>enemies;
    int enemyDirec;

public:
    explicit gameWindow(QWidget *parent = 0);
    ~gameWindow();
    void  paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *evt);
    void stopTimer();
    void checkCollisions();

private slots:
    void updateCoordinates();
    void updateDirection(int direc);
};

#endif // GAMEWINDOW_H
