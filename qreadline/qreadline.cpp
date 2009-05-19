#include <QShortcut>
#include <QKeyEvent>

#include "qreadline.h"



/** Construct a line edit with no text
 *
 *  The argument \a parent is passed to the QLineEdit constructor.
 */
QReadLine::QReadLine(QWidget * parent)
    : QLineEdit(parent)
{
    setup();
}

/** Construct a line edit containing the text \a contents
 *
 *  The arguments \a contents and \a parent are passed to the QLineEdit
 *  constructor.
 */
QReadLine::QReadLine(const QString & contents, QWidget * parent)
    : QLineEdit(contents, parent)
{
    setup();
}

/** Map given \a action to coresponding SLOT */
const char* QReadLine::actionToSlot(QReadLine::Action action)
{
    /* we need to keep this in sync with enum Action */
    static const char* actionMap[] = 
            {
                SLOT(beginningOfLine()),
                SLOT(endOfLine()),
                SLOT(forwardChar()),
                SLOT(backwardChar()),
                SLOT(forwardWord()),
                SLOT(backwardWord())
            };
    return actionMap[action];
}

/** Add keyboard shortcut for given \a action */
void QReadLine::addKeyBinding(QKeySequence keys, Action action)
{
    QShortcut* shortcut = new QShortcut(keys, this);
    connect(shortcut, SIGNAL(activated()), this, actionToSlot(action));

    /* remember the shortcut, so we can delete it when ever we feel to do so */
    m_shortcuts.insert(action, shortcut);
}

/** Create default key bindings */
void QReadLine::setup()
{

    addKeyBinding(Qt::CTRL | Qt::Key_A, BeginningOfLine);
    /* CTRL+E is already bound, at least on X11.
     * This seems to be an undocumented feature, see:
     * http://doc.qtsoftware.com/4.5/qlineedit.html#details
     */
    // addKeyBinding(Qt::CTRL | Qt::Key_E, EndOfLine);
    addKeyBinding(Qt::CTRL | Qt::Key_F, ForwardChar);
    addKeyBinding(Qt::CTRL | Qt::Key_B, BackwardChar);
    addKeyBinding(Qt::ALT  | Qt::Key_F, ForwardWord);
    addKeyBinding(Qt::ALT  | Qt::Key_B, BackwardWord);
}

bool QReadLine::event (QEvent * event)
{
    /* We want to give user bound key bindings precedence over certain
     * StandardKey bindings. The following works, but it is by no means a
     * clean solutions. If you are aware of something more sane, please let me
     * know.
     */
    if (event->type() == QEvent::ShortcutOverride)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        /* SelectAll is bound to CTRL+A on all platforms, so we want to hold
         * it back
         */
        if (keyEvent == QKeySequence::SelectAll)
        {
            event->ignore();
            return false;
        }
    }
    return QLineEdit::event(event);
}
