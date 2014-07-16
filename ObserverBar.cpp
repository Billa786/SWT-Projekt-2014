#include "ObserverBar.h"
#include <qwt_plot_renderer.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_multi_barchart.h>
#include <qwt_column_symbol.h>
#include <qwt_plot_layout.h>
#include <qwt_legend.h>
#include <qwt_scale_draw.h>
#include <iostream>
using namespace std;
#include <qwt_plot_curve.h>
#include "Weather.h"

ObserverBar::ObserverBar( QWidget *parent, QwtPlotMultiBarChart* barChartItem):
    QwtPlot( parent )
{
    this->barChartItem = barChartItem;
}

/*Implementation of the update function() for barChart, gets the new data from the weather class
  and refreshs and scales the barChart
*/
void ObserverBar::update()
{
    const int numSamples = 6;
    const int numBars = 1;

    QList<QwtText> titles;

    /* Description of the legend */
    for ( int i = 0; i < numSamples; i++ )
    {
        QString num;
        num = QString::number(i) + ". " + QString::fromStdString(Weather::arrWeather[i].location);
        titles += num;
    }
    barChartItem->setBarTitles( titles );
    barChartItem->setLegendIconSize( QSize( 10, 14 ) );

    QVector< QVector<double> > series;
    for ( int i = 0; i < numSamples; i++ )
    {
        QVector<double> values;
        for ( int j = 0; j < numBars; j++ )
            values += atof(Weather::arrWeather[i].temp.c_str());
            series += values;
    }

    barChartItem->setSamples( series );
    cout << "ObserverBar.update() called" << endl;
    for(int i=0; i < 6 ; i++)
        cout << Weather::arrWeather[i].location << " " << Weather::arrWeather[i].temp << endl;
}

