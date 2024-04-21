#include "gamepanel.h"
#include "ui_gamepane.h"

GamePane::GamePane(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GamePane)
{
    ui->setupUi(this);
}

GamePane::~GamePane()
{
    delete ui;
}
