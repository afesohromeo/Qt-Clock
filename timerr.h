#ifndef TIMERR_H
#define TIMERR_H

#include <QWidget>
#include "dialog.h"
#include <QWidget>
#include <QToolButton>
#include <QAbstractButton>
#include <QLineEdit>
#include <QTime>
#include <QTimer>
#include <QPixmap>
#include <QIcon>


namespace Ui {
class Timerr;
}

class Timerr : public QWidget
{
    Q_OBJECT

public:
    explicit Timerr(QWidget *parent = nullptr);
    ~Timerr();
    QString getSec();
    QString getMin();
    QString getHour();

private slots:

    void toolButton_clicked();

    void on_backButton_clicked();

    void on_startButton_clicked();

private:
    Ui::Timerr *ui;
    Dialog* dl;

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // TIMERR_H
