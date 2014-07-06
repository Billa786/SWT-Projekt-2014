#pragma once
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "Observer.h"

class QwtPlotMultiBarChart;

class ObserverGraph: public QwtPlot, public Observer
{
    Q_OBJECT

public:
    ObserverGraph( QWidget * = NULL, QwtPlotCurve * = NULL );
    void update();
    QwtPlotCurve *d_curveChartItem;

public Q_SLOTS:

private:

};
