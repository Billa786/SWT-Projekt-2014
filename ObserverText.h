#pragma once
#include <qwt_plot.h>
#include "Observer.h"

class QwtPlotMultiBarChart;

class ObserverText: public QwtPlot, public Observer
{
    Q_OBJECT

public:
    ObserverText( QWidget * = NULL );
    void update();

public Q_SLOTS:
    //void setMode( int );
    //void setOrientation( int );
    //void exportChart();

private:
    void populate();


    QwtPlotMultiBarChart *d_barChartItem;
};
