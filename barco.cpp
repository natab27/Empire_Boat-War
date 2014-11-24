#include "barco.h"
#include "ui_barco.h"

Barco::Barco(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Barco)
{
    ui->setupUi(this);
}

Barco::~Barco()
{
    delete ui;
}
