#include "stopwatch.h"
#include "ui_stopwatch.h"
#include <QDebug>

stopWatch::stopWatch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stopWatch),
    mRunning(false),
    mTotalTime(0),
    mTempTime(0)
{

    ui->setupUi(this);
    this->setStyleSheet("QWidget { background-color : black; color : gainsboro; }");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);

}

// Starts the stopwatch.
// Instantiates the start time and declares the watch to be running.
void stopWatch::start()
{
    mTime = QTime::currentTime();
    mRunning = true;
}

// Pauses the stopwatch.
// Saves the current time and declares the watch to not be running.
void stopWatch::pause()
{
    mTotalTime += mTempTime;
    mRunning = false;
}

// Resumes the stopwatch.
// Declares the watch to be running again.
void stopWatch::resume()
{
    mRunning = true;
}

// Resets the stopwatch.
// Resets the saved time and declares the watch to not be running.
void stopWatch::reset()
{
    mTotalTime = 0;
    mRunning = false;
}

// Returns whether the stopwatch is running.
bool stopWatch::isRunning()
{
    return mRunning;
}

// Sets the state of the stopwatch (running/not running)
void stopWatch::setRunning(bool running)
{
    mRunning = running;
}

// Returns the current time of the running stopwatch
qint64 stopWatch::getTime()
{
    mTempTime = mTime.msecsTo(QTime::currentTime());
    qint64 time = mTotalTime + mTempTime;
    return time;
}

void stopWatch::update()
{
    if(isRunning())
    {
        qint64 time = getTime();
        int h = time / 1000 / 60 / 60;
        int m = (time / 1000 / 60) - (h * 60);
        int s = (time / 1000) - (m * 60);
        int ms = time - ( s + ( m + ( h * 60)) * 60) * 1000;
        int ms_dis = ms / 10;
        if(ms_dis < 10) {
            ui->label_3->setText(QStringLiteral("0%1").arg(ms_dis));
        }
        else {
             ui->label_3->setText(QStringLiteral("%1").arg(ms_dis));
        }
        if(s < 10) {
            ui->label_2->setText(QStringLiteral("0%1").arg(s));
        }
        else {
            ui->label_2->setText(QStringLiteral("%1").arg(s));
        }
        if(m < 10) {
            ui->label_1->setText(QStringLiteral("0%1").arg(m));
        }
        else {
            ui->label_1->setText(QStringLiteral("%1").arg(m));
        }
    }

}

stopWatch::~stopWatch()
{
    delete ui;
}

void stopWatch::on_startStopButton_clicked()
{

    if(isRunning()) {
        ui->startStopButton->setText("Resume");
        this->pause();
    }
    else {
        ui->startStopButton->setText("Pause");
        this->start();
    }
}

void stopWatch::on_resetButton_clicked()
{
    ui->startStopButton->setText("Start");
    ui->label_3->setText("00");
    ui->label_2->setText("00");
    ui->label_1->setText("00");
    reset();
}

void stopWatch::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

