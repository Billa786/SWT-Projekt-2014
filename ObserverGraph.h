#pragma once
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "Observer.h"

class QwtPlotMultiBarChart;

class ObserverGraph: public QwtPlot, public Observer
{
    Q_OBJECT

public:
    ObserverGraph( QWidget * = NULL );
    void update();

public Q_SLOTS:
    //void setMode( int );
    //void setOrientation( int );
    //void exportChart();

private:
    void populate();


    QwtPlotCurve *d_curveChartItem;
};
