#include "qwboton.h"
#include "ui_qwboton.h"

QWBoton::QWBoton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QWBoton)
{
    ui->setupUi(this);
}

QWBoton::~QWBoton()
{
    delete ui;
}
