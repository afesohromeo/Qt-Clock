#ifndef ALARM_H
#define ALARM_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>

namespace Ui {
class Alarm;
}

class Alarm : public QWidget
{
    Q_OBJECT

public:
    explicit Alarm(QWidget *parent = nullptr);
    ~Alarm();

private:
    Ui::Alarm *ui;

protected:
    void paintEvent(QPaintEvent *event);

};

#endif // ALARM_H
