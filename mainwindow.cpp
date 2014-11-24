#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Empire Boat-War"));
    ui->label->setText("EMPIRE BOAT-WAR");
}

MainWindow::~MainWindow()
{
    delete ui;
}
