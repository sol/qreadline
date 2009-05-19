#include <QtGui>
#include <QReadLine>
#include "mainwindow.h"

/** Create main window */
MainWindow::MainWindow()
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    m_label = new QLabel(this);
    m_input = new QReadLine(this);

    layout->addWidget(m_label);
    layout->addWidget(m_input);
    setLayout(layout);

    setWindowTitle(tr("Simple QReadLine Example"));

    /* we accept input when RETURN or ENTER is pressed */
    connect(m_input, SIGNAL(returnPressed()), SLOT(acceptInput()));
}

/** Accept the entered text
 *
 *  The entered text is displayed and the input field is cleared.
 */
void MainWindow::acceptInput()
{
    m_label->setText(m_input->text());
    m_input->clear();
}
