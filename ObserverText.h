#pragma once
#include <QLabel>
#include "Observer.h"

class QwtPlotMultiBarChart;

/* Derived class of abstract observer class.
   Implements update function for the label.
*/
class ObserverText: public QLabel, public Observer
{
    Q_OBJECT

public:
    ObserverText( QWidget * = NULL);
    void update();

private:
    QLabel *label;
};
