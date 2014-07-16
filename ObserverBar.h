#pragma once
#include <qwt_plot.h>
#include "Observer.h"


class QwtPlotMultiBarChart;

/* Derived class of abstract observer class.
   Implements update function for the barChart.
*/
class ObserverBar: public QwtPlot, public Observer
{
    Q_OBJECT

public:
    ObserverBar( QWidget * = NULL, QwtPlotMultiBarChart * = NULL);
    void update();

private:
    QwtPlotMultiBarChart *barChartItem;
};
