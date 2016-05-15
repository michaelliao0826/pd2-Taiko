#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QPushButton>
#include <QFont>
#include <QBrush>
#include <QImage>
#include "game.h"
#include "button.h"
#include <QLabel>
#include "drum.h"
#include <time.h>
#include <QCoreApplication>
#include <QTime>

#include <QDebug>

Game::Game(QWidget *parent)
{
    //create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,480,320);//make the scene 800x600 instead of infinity by infinity
    setBackgroundBrush(QBrush(QImage(":/image/start.jpg")));

    //make the newly created scene the scene to visualize (Since Game is a QGraphicsView Widget
    //it can be used to visualize scenes
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(480,320);
}

void Game::start()
{
    scene->clear();
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,480,320);
    setBackgroundBrush(QBrush(QImage(":/image/bg.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(480,320);

    //add label to record the score
    QLabel *score = new QLabel();
    score->setText("score : ");
    scene->addWidget(score);
    score->setGeometry(325,18,75,15);
    QFont font("", 14.5, QFont::Bold);
    score->setFont(font);


    getScore->setNum(s);
    scene->addWidget(getScore);
    getScore->setGeometry(395,18,75,15);
    getScore->setFont(font);

    //add label to record time
    QLabel *time = new QLabel();
    time->setText("time : ");
    scene->addWidget(time);
    time->setGeometry(325,40,75,15);
    time->setFont(font);

    timeLeft->setNum(t);
    scene->addWidget(timeLeft);
    timeLeft->setGeometry(385,40,75,15);
    timeLeft->setFont(font);

    //add start button;
    Button *startGameButton = new Button(QString("START!"));
    startGameButton->setPos(210,230);
    scene->addItem(startGameButton);

    //connect startButton/startgame
    connect(startGameButton, SIGNAL(clicked()), this, SLOT(startGame()));

    /*//add main menu button
    Button *MainMenuButton = new Button(QString("Main Menu"));
    MainMenuButton->setPos(135,230);
    scene->addItem(MainMenuButton);

    //connect MainMenu to menu
    connect(MainMenuButton,SIGNAL(clicked()), this, SLOT(returnMainMenu()));*/
}

void Game::displayMainMenu()
{
    //create the title text
    QGraphicsTextItem *titleText = new QGraphicsTextItem(QString("taigu master"));
    QFont titleFont("comic sans", 30);
    titleText->setFont(titleFont);
    titleText->setDefaultTextColor(Qt::black);
    int txPos = 150;
    int tyPos = 80;
    titleText->setPos(txPos,tyPos);

    //create the start button
    Button *startButton = new Button(QString("Start"));
    int bxPos = 265;
    int byPos = 130;
    startButton->setPos(bxPos,byPos);
    connect(startButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(startButton);

    //create the quit button
    Button *quitButton = new Button(QString("Quit"));
    int qxPos = 135;
    int qyPos = 130;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

    if(t == 0)
    {
        delete quitButton;
        delete startButton;
        delete titleText;
    }
}

void Game::startGame()
{
    //make timeLeft -1 every second
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timeChange()));
    timer->start(1000);

    //randomly generates drums
    QTimer *timer2 = new QTimer(this);
    Drum *drum = new Drum();
    scene->addItem(drum);

    srand(time(NULL));
    connect(timer, SIGNAL(timeout()), drum, SLOT(generate()));
    while(1)
    {
        int time = rand()%700;
        timer2->start(time);
        QTime mtime; // sleep minsec
        mtime.start();
        while(mtime.elapsed() < time + 100)
        {
            QCoreApplication::processEvents();
            timer2->stop();
        }
    }

    if(t == 0)
    {
        delete timer;
        delete timer2;
        delete drum;
    }
}

void Game::timeChange()
{
    timeLeft->setNum(t--);
    if(t == 0)
    {
        returnMainMenu();
    }
}

void Game::returnMainMenu()
{
    scene->clear();

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,480,320);
    setBackgroundBrush(QBrush(QImage(":/image/start.jpg")));

    //displayMainMenu();
}

/*void Game::finishPage()
{
    //delete scene;
    //scene = new QGraphicsScene();

    scene->clear();
    scene->setSceneRect(0,0,480,320);
    setBackgroundBrush(QBrush(QImage(":/image/finish.jpg")));

    /*Button *playAgainButton = new Button(QString("Play Again"));
    playAgainButton->setPos(265,130);
    connect(playAgainButton,SIGNAL(clicked()),this,SLOT(returnMainMenu()));
    scene->addItem(playAgainButton);

    Button *quitButton = new Button(QString("Quit"));
    quitButton->setPos(135,130);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}*/
