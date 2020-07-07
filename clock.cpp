#include "clock.h"
#include "ui_clock.h"

Clock::Clock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Clock)
{
    ui->setupUi(this);
    startTimer(1000);
    this->setStyleSheet("QWidget { background-color : black; color : gainsboro; }");
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(sTime()));
    timer->start(1000);
    sTime();
}

Clock::~Clock()
{
    delete ui;
}

void Clock::sTime()
{
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    QString text = time.toString("h:m ap");
    QString text2 = time.toString("ap");
    QString text1 = date.toString("ddd:MMMM:d");
    ui->clock->setText(text);
    ui->date->setText(text1);
   // ui->am_pm->setText(text2);
}

void Clock::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

void Clock::timerEvent(QTimerEvent * event)
{
    setWindowTitle(QTime::currentTime().toString("hh:mm:ss"));
}

