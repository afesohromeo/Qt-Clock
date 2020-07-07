#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include <QTime>
#include <QSound>
#include <QSoundEffect>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QString sec, QString min, QString hour, QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *di;
    QTimer* timer;
    QTime startTime;
    qint64 end;
    qint64 pause;
    QSound *beep;

private slots:
    void update();
    void on_pauseResume_clicked();
    void on_Reset_clicked();
    void on_Stop_clicked();

};

#endif // DIALOG_H
