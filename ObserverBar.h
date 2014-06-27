#pragma once
#include <qwt_plot.h>
#include "Observer.h"


class QwtPlotMultiBarChart;

class ObserverBar: public QwtPlot, public Observer
{
    Q_OBJECT

public:
    ObserverBar( QWidget * = NULL, QwtPlotMultiBarChart * = NULL);
    void update();
    QwtPlotMultiBarChart *d_barChartItem;

public Q_SLOTS:
    //void setMode( int );
    //void setOrientation( int );
    //void exportChart();

private:




};
