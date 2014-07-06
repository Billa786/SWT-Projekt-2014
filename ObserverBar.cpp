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
    d_barChartItem = new QwtPlotMultiBarChart(NULL);
    d_barChartItem = barChartItem;
}

void ObserverBar::update()
{
    //static const char *colors[] = { "DarkOrchid", "SteelBlue", "Gold" };

    const int numSamples = 6;
    //const int numBars = sizeof( colors ) / sizeof( colors[0] );
    const int numBars = 1;

    QList<QwtText> titles;
    /* Description of the legend */
    //for ( int i = 0; i < numBars; i++ )
    for ( int i = 0; i < numSamples; i++ )
    {
        QString num;
        num = QString::number(i) + ". " + QString::fromStdString(Weather::arrWeather[i].location);
        //QString title("Bar %1");
        QString title(num);
        titles += title.arg( i );
    }
    d_barChartItem->setBarTitles( titles );
    d_barChartItem->setLegendIconSize( QSize( 10, 14 ) );

    //for ( int i = 0; i < numBars; i++ )
    /*
    for ( int i = 0; i < numSamples; i++ )
    {
        QwtColumnSymbol *symbol = new QwtColumnSymbol( QwtColumnSymbol::Box );
        symbol->setLineWidth( 2 );
        symbol->setFrameStyle( QwtColumnSymbol::Raised );
        symbol->setPalette( QPalette( colors[i] ) );

        d_barChartItem->setSymbol( i, symbol );
    }*/
    
    QVector< QVector<double> > series;
    for ( int i = 0; i < numSamples; i++ )
    {
        QVector<double> values;
        for ( int j = 0; j < numBars; j++ )
            values += atof(Weather::arrWeather[i].temp.c_str());


        series += values;
    }

    d_barChartItem->setSamples( series );
    cout << "ObserverBar.update() called" << endl;
    for(int i=0; i < 6 ; i++)
        cout << Weather::arrWeather[i].location << " " << Weather::arrWeather[i].temp << endl;
}
