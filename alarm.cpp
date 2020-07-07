#include "alarm.h"
#include "ui_alarm.h"
#include <QSize>

Alarm::Alarm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Alarm)
{
    ui->setupUi(this);
    this->setStyleSheet("QWidget { background-color : black; color : gainsboro; }");
    QPixmap pix1("C:/Users/afeso/Desktop/Cpp_Exam/images/allme.png");
    //QSize size(100,100);
    //pix1.scaled(size, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    int w = ui->alarm->width();
    int h = ui->alarm->height();
    ui->alarm->setPixmap(pix1.scaled(w,h,Qt::KeepAspectRatioByExpanding));

    w = ui->addButton->width();
    h = ui->addButton->height();
    //QPixmap pix2("C:/Users/afeso/Desktop/Cpp_Exam/images/add.png");
    //QIcon icon(pix2);
    ui->addButton->setIcon(QIcon(":/new/prefix1/images/add.png"));
    ui->addButton->setIconSize(QSize(50, 50));
    ui->addButton->setToolTip("Add Alarm");

}

Alarm::~Alarm()
{
    delete ui;
}

void Alarm::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

