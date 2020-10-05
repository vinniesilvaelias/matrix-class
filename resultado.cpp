#include "resultado.h"
#include "ui_resultado.h"
#include <iostream>
#include <QLabel>
using namespace  std;
Resultado::Resultado(QWidget *parent) :QDialog(parent),ui(new Ui::Resultado)
{
    ui->setupUi(this);
    setFixedSize(480,640);
}

Resultado::~Resultado() { delete ui; }

void Resultado::set_resultado(bool op, QString msg, bool r)
{
    ui->lblImg->setVisible(true);
    ui->lblMsg->setVisible(true);
    int index = rand()%3;
    QMovie* movie;
    if (op)
    {
        if (r)
            movie = new QMovie("sim"+QString::number(index) + ".gif");
        else
            movie = new QMovie("no" +QString::number(index) + ".gif");
    }
    else
        movie = new QMovie("erro"+QString::number(index) + ".gif");
    cout << index << endl;
    movie->scaledSize();
    ui->lblImg->setMovie(movie);
    ui->lblMsg->setText(msg);
    movie->start();
}
