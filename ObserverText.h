#pragma once
#include <QLabel>
#include "Observer.h"

class QwtPlotMultiBarChart;

class ObserverText: public QLabel, public Observer
{
    Q_OBJECT

public:
    ObserverText( QWidget * = NULL);
    void update();
    QLabel *label;

public Q_SLOTS:

private:
    QwtPlotMultiBarChart *d_barChartItem;
};
