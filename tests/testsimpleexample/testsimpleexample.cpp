#include <QtTest/QtTest>

#include <mainwindow.h>
#include <QReadLine>

/** Unit tests for QReadLine
 *
 *  Testing is done through MainWindow
 */
class TestMainWindow: public QObject
{
    Q_OBJECT;

private:
    MainWindow* m_mainwindow;

    void keyClick(  Qt::Key key,
                    Qt::KeyboardModifiers modifier = Qt::NoModifier,
                    int delay = -1 )
    {
        QTest::keyClick(m_mainwindow->m_input, key, modifier, delay);
    }

    void keyClick(  char key,
                    Qt::KeyboardModifiers modifier = Qt::NoModifier,
                    int delay = -1 )
    {
        QTest::keyClick(m_mainwindow->m_input, key, modifier, delay);
    }

    void keyClicks( const QString & sequence,
                    Qt::KeyboardModifiers modifier = Qt::NoModifier,
                    int delay = -1 )
    {
        QTest::keyClicks(m_mainwindow->m_input, sequence, modifier, delay);
    }

    /** Return cursor position */
    int getPosition()
    {
        return m_mainwindow->m_input->cursorPosition();
    }

    /** Return last input line */
    QString getLastInput()
    {
        return m_mainwindow->m_label->text();
    }

    /** Return current input line */
    QString getInput()
    {
        return m_mainwindow->m_input->text();
    }


private slots:
    void init()
    {
        m_mainwindow = new MainWindow;
        m_mainwindow->show();
    }

    void cleanup()
    {
        delete m_mainwindow;
    }

    /** Test basic input */
    void test_input()
    {
        keyClicks("foobarbaz");
        QCOMPARE(getInput(),    QString("foobarbaz"));
        QCOMPARE(getPosition(), 9);

        keyClick(Qt::Key_Return);
        QCOMPARE(getInput(), QString(""));
        QCOMPARE(getPosition(), 0);
        QCOMPARE(getLastInput(), QString("foobarbaz"));
    }

    /** Test CTRL-A, CTRL-E, CTRL-B and CTRL-F */
    void test_movement()
    {
        keyClicks("foobarbaz");
        QCOMPARE(getPosition(), 9);

        keyClicks("b", Qt::ControlModifier, 1);
        QCOMPARE(getPosition(), 8);

        keyClicks("bbb", Qt::ControlModifier, 1);
        QCOMPARE(getPosition(), 5);

        keyClicks("a", Qt::ControlModifier, 1);
        QCOMPARE(getPosition(), 0);

        keyClicks("f", Qt::ControlModifier, 1);
        QCOMPARE(getPosition(), 1);

        keyClicks("ffff", Qt::ControlModifier, 1);
        QCOMPARE(getPosition(), 5);

        keyClicks("e", Qt::ControlModifier, 1);
        QCOMPARE(getPosition(), 9);
    }

    /** Test ALT-B and ALT-F */
    void test_wordMovement()
    {
        /*         012345678901234 */
        keyClicks("  foo bar   baz");
        QCOMPARE(getPosition(), 15);

        keyClicks("b", Qt::AltModifier, 1);
        QCOMPARE(getPosition(), 12);

        keyClicks("b", Qt::AltModifier, 1);
        QCOMPARE(getPosition(), 6);

        keyClicks("b", Qt::AltModifier, 1);
        QCOMPARE(getPosition(), 2);

        keyClicks("b", Qt::AltModifier, 1);
        QCOMPARE(getPosition(), 0);

        keyClicks("f", Qt::AltModifier, 1);
        QCOMPARE(getPosition(), 2);

        keyClicks("f", Qt::AltModifier, 1);
        QCOMPARE(getPosition(), 6);

        keyClicks("f", Qt::AltModifier, 1);
        QCOMPARE(getPosition(), 12);

        keyClicks("f", Qt::AltModifier, 1);
        QCOMPARE(getPosition(), 15);
    }
};


QTEST_MAIN(TestMainWindow)
#include "testsimpleexample.moc"
