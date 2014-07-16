#pragma once
#include "Subject.h"
#include <windows.h>
#include "ObserverBar.h"
#include <QtCore>

/* Connection between algorithm and GUI according to MVC-Pattern */
class Controller : public QObject
{
    Q_OBJECT

public:
    Subject *subject;

    Controller();
    ~Controller();

    QTimer *timer;
    /* Needed for timer */
    Q_SLOT void applyChanges();

};
