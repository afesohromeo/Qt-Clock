#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QStyleOption>
#include <QPainter>

namespace Ui {
class Clock;
}

class Clock : public QWidget
{
    Q_OBJECT

public:
    explicit Clock(QWidget *parent = nullptr);
    ~Clock();

private:
    Ui::Clock *ui;

public slots:
    void sTime();

protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

};

#endif // CLOCK_H
