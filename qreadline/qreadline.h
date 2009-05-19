#ifndef QREADLINE_H
#define QREADLINE_H

#include <QLineEdit>

#include <QMultiHash>
class QShortcut;

/** A drop-in replacement for QLineEdit, with emacs-like key bindings
 *
 *  So far only basic movement command are implemented.
 */
class QReadLine : public QLineEdit
{
    Q_OBJECT;

public:
    enum Action
        {
            /** Move cursor to the beginning of line */
            BeginningOfLine,

            /** Move cursor to the end of line */
            EndOfLine,

            /** Move cursor forward a character */
            ForwardChar,

            /** Move cursor back a character */
            BackwardChar,

            /** Move cursor forward a word */
            ForwardWord,

            /** Move cursor backward a word */
            BackwardWord
        };

    QReadLine(QWidget * parent = 0);
    QReadLine(const QString & contents, QWidget * parent = 0);

    void addKeyBinding(QKeySequence keys, Action action);

private slots:
    void beginningOfLine()      { home(false); }
    void endOfLine()            { end(false); }
    void forwardChar()          { cursorForward(false); }
    void backwardChar()         { cursorBackward(false); }
    void forwardWord()          { cursorWordForward(false); }
    void backwardWord()         { cursorWordBackward(false); }

private:
    void setup();
    virtual bool event(QEvent* event);
    static const char* actionToSlot(Action action);

    QMultiHash<Action,QShortcut*> m_shortcuts;
};

#endif
