#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>

class QLineEdit;

/** A simple QReadLine example */
class MainWindow : public QWidget
{
    Q_OBJECT;

public:
    MainWindow();


private slots:
    void acceptInput();

private:
    QLineEdit* m_input;
    QLabel*    m_label;

#ifdef TESTING
    /* we give TestMainWindow access to private data for testing */
    friend class TestMainWindow;
#endif
};

#endif
