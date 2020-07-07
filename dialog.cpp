#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QString sec, QString min, QString hour, QWidget *parent) :
    QDialog(parent),
   di(new Ui::Dialog)
{
    di->setupUi(this);
    timer = new QTimer(this);

    QSoundEffect alarm(this);
    alarm.setSource(QUrl::fromLocalFile(":/new/prefix1/sound/ringe.mp3v"));
    //alarm.setLoopCount(2);
    //alarm.setVolume(0.5f);


    startTime = QTime::currentTime();
    pause = 0;
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start();
    end = ((sec.toInt()) + (min.toInt() * 60) + (hour.toInt() * 60 * 60)) * 1000;
}

Dialog::~Dialog()
{
    delete di;
}

void Dialog::update()
{
    qint64 time = startTime.msecsTo(QTime::currentTime()) + pause;
    if(di->pauseResume->text() == "Pause")
    {
        int h = time / 1000 / 60 / 60;
        int m = (time / 1000 / 60) - (h * 60);
        int s = (time / 1000) - (m * 60);

        if(s < 10) {
            di->secEdit->setText(QStringLiteral("0%1").arg(s));
        }
        else {
            di->secEdit->setText(QStringLiteral("%1").arg(s));
        }
        if(m < 10) {
            di->minEdit->setText(QStringLiteral("0%1").arg(m));
        }
        else {
            di->minEdit->setText(QStringLiteral("%1").arg(m));
        }

        di->hourEdit->setText(QStringLiteral("%1").arg(h));
    }

    if(end == time)
    {
        QSound::play(":/new/prefix1/sound/beep_alarm.mp3");
        di->pauseResume->setText("Start");
        pause = 0;
        timer->stop();
    }
}

void Dialog::on_pauseResume_clicked()
{
    if(di->pauseResume->text() == "Start")
    {
        timer->start();
        startTime = QTime::currentTime();
        di->pauseResume->setText("Pause");
        pause = 0;
    }
    else if(di->pauseResume->text() == "Pause")
    {
        timer->stop();
        pause += startTime.msecsTo(QTime::currentTime());
        di->pauseResume->setText("Resume");
    }
    else if(di->pauseResume->text() == "Resume")
    {
        timer->start();
        startTime = QTime::currentTime();
        di->pauseResume->setText("Pause");
    }
}

void Dialog::on_Reset_clicked()
{
    timer->stop();
    di->pauseResume->setText("Start");
    di->secEdit->setText("00");
    di->minEdit->setText("00");
    di->hourEdit->setText("0");
}

void Dialog::on_Stop_clicked()
{
    this->close();
}


