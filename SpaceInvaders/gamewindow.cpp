#include "gamewindow.h"

gameWindow::gameWindow(QWidget *parent) :
    QWidget(parent)
{
#ifdef __APPLE__
    QDir bin(QCoreApplication::applicationDirPath());
    bin.cdUp();
    bin.cdUp();
    bin.cdUp();
    QDir::setCurrent(bin.absolutePath());
#endif
    this->setStyleSheet("background-color: black;");

    score =0;
    clock = new QTime();
    clock->start();
    timer = new QTimer();
    timer->setInterval(50);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateCoordinates()));
    timer->start();
    player = new spaceship(this);
    player->setCoords(this->width()/2-10,this->height()-50);
    player->setDirection(1);
    player->setSpeed(10);

    enemyDirec=1;
    QPixmap *enemy1=new QPixmap("./images/invader1.png");
    for(int i=0;i<5;i++){
        for(int j=0;j<11;j++){
            spaceship *enemy=new spaceship(this);
            enemy->setCoords(40*j+100,30*i);
            enemy->setImage(enemy1);
            enemies.push_back(enemy);
        }
    }
}

gameWindow::~gameWindow()
{
    delete timer;
}

void gameWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    player->drawSpaceship(painter);
    painter.drawText(10,10, QString::number(score));
    for(int i=0;i<enemies.size();i++){
        enemies.at(i)->setDirection(enemyDirec);
        enemies.at(i)->updateCoordinate();
        enemies.at(i)->drawSpaceship(painter);
    }
}

void gameWindow::keyPressEvent(QKeyEvent *evt)
{
    if (evt->key()==Qt::Key_Left){
        updateDirection(2);
        player->updateCoordinate();
    }
    else if (evt->key()==Qt::Key_Right){
        updateDirection(1);
        player->updateCoordinate();
    }
}

void gameWindow::stopTimer()
{
    timer->stop();
}

void gameWindow::checkCollisions()
{
    bool collision=false;
    for(int i=0;i<enemies.size();i++){
        if(1==enemyDirec){
            if(enemies.at(i)->getXCoord()>(this->width()-35)){
                collision=true;
            }
        }
        else if(2==enemyDirec){
            if(enemies.at(i)->getXCoord()<5){
                collision=true;
            }
        }
//        int enemyY=enemies.at(i)->getYCoord()-20;
//        int enemyXLeft=enemies.at(i)->getXCoord();
//        int enemyXRight=enemies.at(i)->getXCoord()+30;
//        for(int j=0;j<projectile.size();j++){
//            if((projectile.at(j).getYCoord()>enemyY)&&(projectile.at(j).getXCoord()>enemyXLeft)&&(projectile.at(j).getXCoord()<enemyXRight)){
//                enemies.erase(enemies.begin()+i);
//                projectile.erase(projectile.begin()+j);
//            }
//        }

//        int playerY=player->getYCoord()-20;
//        int playerXLeft=player->getXCoord();
//        int playerXRight=player->getXCoord()+30;
//        for(int j=0;j<projectile.size();j++){
//            if((projectile.at(j).getYCoord()>playerY)&&(projectile.at(j).getXCoord()>playerXLeft)&&(projectile.at(j).getXCoord()<playerXRight)){
//
//                this->stopTimer();
//        QMessageBox mbox;
//        mbox.setText("Game Over");
//        mbox.exec();
//        this->close();
//        break;
//            }
//        }
        if(enemies.at(i)->getYCoord()>(player->getYCoord()-20)){
            this->stopTimer();
            QMessageBox mbox;
            mbox.setText("Game Over");
            mbox.exec();
            this->close();
            break;
        }
    }
    if(true==collision){
        if(1==enemyDirec){
            enemyDirec=2;
        }
        else if(2==enemyDirec){
            enemyDirec=1;
        }
        for(int i=0;i<enemies.size();i++){
            enemies.at(i)->setDirection(enemyDirec);
            enemies.at(i)->setCoords(enemies.at(i)->getXCoord(),enemies.at(i)->getYCoord()+30 );
        }
    }
}

void gameWindow::updateCoordinates()
{
    this->checkCollisions();
    this->update();
}

void gameWindow::updateDirection(int direc)
{
    player->setDirection(direc);
    this->update();
}

