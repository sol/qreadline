#include <QtGui>
#include <QReadLine>
#include "mainwindow.h"

MainWindow::MainWindow()
{
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(new QReadLine());
    setLayout(layout);
    setWindowTitle(tr("QReadLine Example"));
}
