#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QStyleOption>
#include <QPainter>

namespace Ui {
class stopWatch;
}

class stopWatch : public QWidget
{
    Q_OBJECT

public:
    explicit stopWatch(QWidget *parent = nullptr);
    void start();
    void pause();
    void resume();
    void reset();
    qint64 getTime();
    bool isRunning();
    void setRunning(bool running);

    ~stopWatch();

private slots:
    void update();
    void on_startStopButton_clicked();
    void on_resetButton_clicked();

private:
    Ui::stopWatch *ui;
    bool mRunning;
    qint64 mTotalTime;
    qint64 mTempTime;
    QTime mTime;
    QTimer *timer;

protected:
    void paintEvent(QPaintEvent *event);

};

#endif // STOPWATCH_H
