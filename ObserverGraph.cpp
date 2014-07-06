#include "ObserverGraph.h"
#include <qwt_plot_renderer.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_multi_barchart.h>
#include <qwt_column_symbol.h>
#include <qwt_plot_layout.h>
#include <qwt_legend.h>
#include <qwt_scale_draw.h>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "Weather.h"

ObserverGraph::ObserverGraph( QWidget *parent, QwtPlotCurve* curveChartItem ):
    QwtPlot( parent )
{
    d_curveChartItem = new QwtPlotCurve(NULL);
    d_curveChartItem = curveChartItem;
}

void ObserverGraph::update()
{
    QPolygonF points;
    for(int i = 0; i < 6 ; i++)
        points << QPointF(i, atof(Weather::arrWeather[i].temp.c_str()));
    d_curveChartItem->setSamples( points );

    QString titles;
    for(int i=0; i < 6 ; i++)
    {
        titles.append(QString::number(i) + ". " + QString::fromStdString(Weather::arrWeather[i].location) + "\n");
    }
    d_curveChartItem->setTitle(titles);

    cout << "ObserverGraph.Update() called" << endl;
}
