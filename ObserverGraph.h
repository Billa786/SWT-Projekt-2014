#pragma once
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "Observer.h"

class QwtPlotMultiBarChart;

/* Derived class of abstract observer class.
   Implements update function for the plot.
*/
class ObserverGraph: public QwtPlot, public Observer
{
    Q_OBJECT

public:
    ObserverGraph( QWidget * = NULL, QwtPlotCurve * = NULL );
    void update();

private:
    QwtPlotCurve *curveChartItem;
};
