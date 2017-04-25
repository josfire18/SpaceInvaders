#include "gamewindow.h"
#include <QDebug>

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
    lives = 3;
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
    shotCooldown=0;

    srand(time(0));

    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            Bunker *bunk = new Bunker(this);
            bunk->setCoords((((this->width()/4)*i)+50),(this->height()-70-(15*j)));
            bunkers.push_back(bunk);
        }
        Bunker *bunk1 = new Bunker(this);
        bunk1->setCoords((((this->width()/4)*i)+65),this->height()-100);
        bunkers.push_back(bunk1);

        Bunker *bunk2 = new Bunker(this);
        bunk2->setCoords((((this->width()/4)*i)+80),this->height()-100);
        bunkers.push_back(bunk2);

        for(int j=0;j<3;j++){
            Bunker *bunk = new Bunker(this);
            bunk->setCoords((((this->width()/4)*i)+95),(this->height()-70-(15*j)));
            bunkers.push_back(bunk);
        }
    }
    this->setEnemies();
}

gameWindow::~gameWindow()
{
    delete timer;
}

void gameWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    player->drawSpaceship(painter);
    painter.drawText(10,20, QString::number(score));
    painter.drawText(10,620, QString::number(lives));
    painter.setFont(QFont("Franklin Gothic Demi", 14));
    for(int i=0;i<enemies.size();i++){
        enemies.at(i)->setDirection(enemyDirec);
        enemies.at(i)->updateCoordinate();
        enemies.at(i)->drawSpaceship(painter);
    }
    for(int i=0;i<projectiles.size();i++){
        projectiles.at(i)->updateCoordinate();
        projectiles.at(i)->drawProjectile(painter);
    }
    for(int i=0;i<bunkers.size();i++){
        bunkers.at(i)->drawBunker(painter);
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
    else if (evt->key()==Qt::Key_Space){
        if(0==shotCooldown){
            projectile *newProjectile= new projectile(this);
            QPixmap *proj1=new QPixmap("./images/projectileUP.png");
            newProjectile->setDirection(3);
            newProjectile->setImage(proj1);
            newProjectile->setCoords(player->getXCoord()+15,player->getYCoord());
            projectiles.push_back(newProjectile);
            shotCooldown=2;
        }
    }
}

void gameWindow::stopTimer()
{
    timer->stop();
}

void gameWindow::checkCollisions()
{
    //qDebug()<<"check collisions";
    bool collision=false;
    for(int i=enemies.size()-1;i>=0;i--){
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
        //qDebug()<<"fire!";
        int randval=rand()%1000;
        if(randval==1){
            projectile *newProjectile= new projectile(this);
            newProjectile->setDirection(4);
            newProjectile->setCoords(enemies.at(i)->getXCoord()+15,enemies.at(i)->getYCoord()-20);
            projectiles.push_back(newProjectile);
        }

        //qDebug()<<"enemy death";
        QRect enemyRect(enemies.at(i)->getXCoord(),enemies.at(i)->getYCoord(),30,20);
        for(int j=projectiles.size()-1;j>=0;j--){
            //qDebug()<<"j"<<j<<"i"<<i;
            QRect projRect(projectiles.at(j)->getXCoord(),projectiles.at(j)->getYCoord(),10,15);
            if((3==projectiles.at(j)->getDirection())&&(projRect.intersects(enemyRect))){
                //qDebug()<<"         death";
                enemies.erase(enemies.begin()+i);
                projectiles.erase(projectiles.begin()+j);
                break;
            }
        }

        //qDebug()<<"kill wall";
        if((enemies.size()>i)&&(enemies.at(i)->getYCoord()>(player->getYCoord()-20))){
            this->stopTimer();
            QMessageBox mbox;
            mbox.setText("Game Over");
            mbox.exec();
            this->close();
            break;
        }

        //qDebug()<<"end kill wall";
    }

    //qDebug()<<"collision handler";
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

    //qDebug()<<"player death";
    QRect playerRect(player->getXCoord(),player->getYCoord(),30,20);
    for(int j=projectiles.size()-1;j>=0;j--){
        QRect projRect(projectiles.at(j)->getXCoord(),projectiles.at(j)->getYCoord(),10,15);
        if((4==projectiles.at(j)->getDirection())&&(projRect.intersects(playerRect))){
            this->stopTimer();
            QMessageBox mbox;
            mbox.setText("Game Over");
            mbox.exec();
            this->close();
            break;
        }
    }

    for(int i=bunkers.size()-1;i>=0;i--){
        QRect bunkRect(bunkers.at(i)->getXCoord(),bunkers.at(i)->getYCoord(),15,15);
        for(int j=projectiles.size()-1;j>=0;j--){
            QRect projRect(projectiles.at(j)->getXCoord(),projectiles.at(j)->getYCoord(),10,15);
            if(projRect.intersects(bunkRect)){
                bunkers.at(i)->decrementHP();
                if(bunkers.at(i)->getHP()==0){
                    bunkers.erase(bunkers.begin()+i);
                }
                projectiles.erase(projectiles.begin()+j);
            }
        }
    }

    //qDebug()<<"projectile deletion";
    for(int j=projectiles.size()-1;j>=0;j--){
        if((projectiles.at(j)->getYCoord()<5)||(projectiles.at(j)->getYCoord()>this->height()-30)){
            projectiles.erase(projectiles.begin()+j);
        }
    }

    //qDebug()<<"reset enemies";
    if(enemies.size()==0){
        this->setEnemies();
    }
}

void gameWindow::setEnemies()
{
    enemyDirec=1;
    QPixmap *enemy1=new QPixmap("./images/invader1.png");
    QPixmap *enemy2=new QPixmap("./images/invader2.png");
    for(int i=0;i<5;i++){
        for(int j=0;j<11;j++){
            spaceship *enemy=new spaceship(this);
            enemy->setCoords(40*j+100,30*i);
            if(i>2){
                enemy->setImage(enemy1);
            }
            else{
                enemy->setImage(enemy2);
            }
            enemies.push_back(enemy);
        }
    }
}

void gameWindow::updateCoordinates()
{
    this->checkCollisions();
    this->update();
    if(0<shotCooldown){
        shotCooldown--;
    }
}

void gameWindow::updateDirection(int direc)
{
    player->setDirection(direc);
}

