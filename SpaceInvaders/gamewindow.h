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
#include "projectile.h"
#include "bunker.h"
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
    int lives;
    vector<spaceship*>enemies;
    vector<projectile*>projectiles;
    vector<Bunker*>bunkers;
    int enemyDirec;
    int shotCooldown;

public:
    explicit gameWindow(QWidget *parent = 0);
    ~gameWindow();
    void  paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *evt);
    void stopTimer();
    void checkCollisions();
    void setEnemies();

private slots:
    void updateCoordinates();
};

#endif // GAMEWINDOW_H
