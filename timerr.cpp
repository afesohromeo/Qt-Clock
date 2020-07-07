#include "timerr.h"
#include "ui_timerr.h"
#include <QObject>
#include <iostream>
#include <QStyleOption>
#include <QPainter>
#include "mainwindow.h"

Timerr::Timerr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Timerr)
{
    ui->setupUi(this);


    this->setStyleSheet("QWidget { background-color : black; color : gainsboro; }");
    ui->hour->setText("0");
    ui->minute->setText("00");
    ui->second->setText("00");

    ui->backButton->setIcon(QIcon(":/new/prefix1/images/del.png"));
    QObject::connect(ui->toolButton0, &QToolButton::clicked, this, &Timerr::toolButton_clicked);
    QObject::connect(ui->toolButton1, &QToolButton::clicked, this, &Timerr::toolButton_clicked);
    QObject::connect(ui->toolButton2, &QToolButton::clicked, this, &Timerr::toolButton_clicked);
    QObject::connect(ui->toolButton3, &QToolButton::clicked, this, &Timerr::toolButton_clicked);
    QObject::connect(ui->toolButton4, &QToolButton::clicked, this, &Timerr::toolButton_clicked);
    QObject::connect(ui->toolButton5, &QToolButton::clicked, this, &Timerr::toolButton_clicked);
    QObject::connect(ui->toolButton6, &QToolButton::clicked, this, &Timerr::toolButton_clicked);
    QObject::connect(ui->toolButton7, &QToolButton::clicked, this, &Timerr::toolButton_clicked);
    QObject::connect(ui->toolButton8, &QToolButton::clicked, this, &Timerr::toolButton_clicked);
    QObject::connect(ui->toolButton9, &QToolButton::clicked, this, &Timerr::toolButton_clicked);
}

Timerr::~Timerr()
{
    delete ui;
}

QString Timerr::getSec()
{
    return  ui->second->text();
}

QString Timerr::getMin()
{
    return ui->minute->text();
}

QString Timerr::getHour()
{
    return ui->hour->text();
}

void Timerr::toolButton_clicked()
{
    QToolButton *clickedButton = qobject_cast<QToolButton*>(sender());
    int digitValue = clickedButton->text().toInt();
    QString text,text1;
    if (ui->hour->text() == "0")
    {
        text = ui->minute->text();
        text = text.at(0);
        ui->hour->setText(text);
        text = ui->minute->text();
        text1 = ui->second->text();
        text = text.at(1);
        text = text + text1.at(0);
        ui->minute->setText(text);

        text = ui->second->text();
        text = text[1] + QString::number(digitValue);
        ui->second->setText(text);
    }
    else
    {
        return;
    }
}

void Timerr::on_backButton_clicked()
{
    QString text, text1;
    text = ui->second->text();
    text1 = ui->minute->text();

    text1 = text1.at(1);
    text1 = text1 + text.at(0);
    ui->second->setText(text1);

    text = ui->hour->text();
    text1 = ui->minute->text();
    text = text + text1.at(0);
    ui->minute->setText(text);
    ui->hour->setText("0");
}

void Timerr::on_startButton_clicked()
{
    if(ui->hour->text() == "0" && ui->second->text() == "00" && ui->minute->text() == "00")
    {

    }
    else
    {
        dl = new Dialog(ui->second->text(), ui->minute->text(), ui->hour->text(), this);
        dl->exec();
        ui->second->setText("00");
        ui->minute->setText("00");
        ui->hour->setText("0");
    }

}

void Timerr::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}
