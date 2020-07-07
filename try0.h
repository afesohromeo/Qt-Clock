#ifndef TRY0_H
#define TRY0_H

#include <QMainWindow>

namespace Ui {
class try0;
}

class try0 : public QMainWindow
{
    Q_OBJECT

public:
    explicit try0(QWidget *parent = nullptr);
    ~try0();

private:
    Ui::try0 *ui;
};

#endif // TRY0_H
