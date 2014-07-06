#pragma once
#include "Subject.h"
#include <windows.h>
#include "ObserverBar.h"
#include <QtCore>

class Controller : public QObject
{
    Q_OBJECT

public:
    Subject *subject;

    Controller();
    ~Controller();

    QTimer *timer;

    Q_SLOT void applyChanges();

};
