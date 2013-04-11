#include "sciaga.h"
#include "ui_sciaga.h"

Sciaga::Sciaga(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sciaga)
{
    ui->setupUi(this);
}

Sciaga::~Sciaga()
{
    delete ui;
}
