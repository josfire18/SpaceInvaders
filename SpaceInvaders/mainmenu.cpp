#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "gamewindow.h"
#include <QDir>
#include <QCoreApplication>

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
    this->setFixedSize(1000,500);
    ui->cmdStartGame->move(400,419);

    //Set Main Menu Background
    QPixmap bkgnd("./images/MainMenu.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

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
