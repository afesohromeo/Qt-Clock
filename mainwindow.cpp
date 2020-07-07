#include "mainwindow.h"
#include "alarm.h"
#include "clock.h"
#include "timerr.h"
#include "stopwatch.h"


#include <QTabWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(500, 600);
    m_wind = new QWidget(this);
    QTabWidget* tab = new QTabWidget(m_wind);
    tab->setTabShape(QTabWidget::Rounded);

    Timerr* page3 = new Timerr(this);
    stopWatch* page4 = new stopWatch(this);
    Alarm* page1 = new Alarm(this);
    Clock* page2 = new Clock(this);





    tab->setGeometry(0, 0, width(), height());
    tab->addTab(page1, "Alarm");
    tab->addTab(page2, "Clock");
    tab->addTab(page3, "Timer");
    tab->addTab(page4, "Stopwatch");

    tab->setTabToolTip(0, "Alarm");
    tab->setTabToolTip(1, "Clock");
    tab->setTabToolTip(2, "Timer");
    tab->setTabToolTip(3, "Stopwatch");

    tab->setTabIcon(0, QIcon(":/new/prefix1/images/alarm.png"));
    tab->setTabIcon(1, QIcon(":/new/prefix1/images/clock.png"));
    tab->setTabIcon(2, QIcon(":/new/prefix1/images/timer.png"));
    tab->setTabIcon(3, QIcon(":/new/prefix1/images/stop.png"));


    setCentralWidget(m_wind);

}

MainWindow::~MainWindow()
{

}




