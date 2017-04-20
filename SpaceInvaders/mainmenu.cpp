#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "gamewindow.h"
#include <QDir>
#include <QCoreApplication>
#include <QDebug>
#include <QDesktopWidget>

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

#ifdef __APPLE__
    QDir bin(QCoreApplication::applicationDirPath());
    bin.cdUp();
    bin.cdUp();
    bin.cdUp();
    QDir::setCurrent(bin.absolutePath());
#endif

    //Lock window size
    //this->setMaximumSize();
    QRect rec = QApplication::desktop()->screenGeometry();
    int height = rec.height();
    int width = rec.width();
    qDebug() << height << ", " << width;
    this->resize(width, height);

    //Set Main Menu Background
    QPixmap bkgnd("./images/MainMenu.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    ui->cmdStartGame->move(800,819);

    //Set transparent Start button bg
    //ui->cmdStartGame->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->cmdStartGame->setStyleSheet("background-color: black; color: white;");
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_cmdStartGame_clicked()
{
    ui->cmdStartGame->setStyleSheet("background-color: black; color: rgba(0, 255, 29, 1);");
    gameWindow* newGameWindow = new gameWindow();
    newGameWindow->show();
}
