#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "invalid_command_exception.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,game(new Game)
{
    ui->setupUi(this);
    //game handling
    buttonSetup(ui->North_btn);
    buttonSetup(ui->South_btn);
    buttonSetup(ui->East_btn);
    buttonSetup(ui->West_btn);
    buttonSetup(ui->Use_btn);
    buttonSetup(ui->Investigate_btn);
    buttonSetup(ui->Take_btn);

    connect(ui->Investigate_btn, &QPushButton::pressed, this, &MainWindow::investigate);

    ui->plainTextEdit->appendPlainText(game->getCurrentRoomDescription());
}

void MainWindow::buttonSetup(QPushButton *btn){
    connect(btn, &QPushButton::pressed, this, &MainWindow::handleButton);
    // this connects the button to the function handle button so whenever the button is pressed handle button is  called
}

void MainWindow::handleButton(){
    QString buttonPressed = qobject_cast<QPushButton*>(sender())->objectName();
    // returns the name of the button pressed
    QString command;

    if (buttonPressed == "North_btn") {
        command = "north";
    } else if (buttonPressed == "South_btn") {
        command = "south";
    } else if (buttonPressed == "East_btn") {
        command = "east";
    } else if (buttonPressed == "West_btn") {
        command = "west";
    } else if (buttonPressed == "Use_btn") {
        command = "use";
    } else if (buttonPressed == "Take_btn") {
        command = "take";
    }

    if (!command.isEmpty()){
        processCommand(command);
    }
}

void MainWindow::processCommand(const QString& command){
    QString result = game->processCommand(command);
    ui->plainTextEdit->appendPlainText(result);
    qDebug() << command;
}

void MainWindow::investigate(){
    QString items = game->getCurrentRoomItems();
    ui->plainTextEdit->appendPlainText("You investigate the room and find the following:\n" + items);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete game;
}
