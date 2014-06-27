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
    static const char *colors[] = { "DarkOrchid", "SteelBlue", "Gold" };

    const int numSamples = 6;
    //const int numBars = sizeof( colors ) / sizeof( colors[0] );
    const int numBars = 1;

    QList<QwtText> titles;
    /* Description of the legend */
    for ( int i = 0; i < numBars; i++ )
    {
        //QString title("Bar %1");
        QString title(QString::fromStdString(Weather::arrWeather[i].location));
        titles += title.arg( i );
    }
    d_barChartItem->setBarTitles( titles );
    d_barChartItem->setLegendIconSize( QSize( 10, 14 ) );

    for ( int i = 0; i < numBars; i++ )
    {
        QwtColumnSymbol *symbol = new QwtColumnSymbol( QwtColumnSymbol::Box );
        symbol->setLineWidth( 2 );
        symbol->setFrameStyle( QwtColumnSymbol::Raised );
        symbol->setPalette( QPalette( colors[i] ) );

        d_barChartItem->setSymbol( i, symbol );
    }
    
    QVector< QVector<double> > series;
    for ( int i = 0; i < numSamples; i++ )
    {
        QVector<double> values;
        for ( int j = 0; j < numBars; j++ )
            values += ( 2 + qrand() % 8 );

        series += values;
    }

    d_barChartItem->setSamples( series );
    cout << "ObserverBar.update() called" << endl;
    for(int i=0; i < 6 ; i++)
        cout << Weather::arrWeather[i].location << " " << Weather::arrWeather[i].temp << endl;
}

/*
void ObserverBar::setMode( int mode )
{
    if ( mode == 0 )
    {
        d_barChartItem->setStyle( QwtPlotMultiBarChart::Grouped );
    }
    else
    {
        d_barChartItem->setStyle( QwtPlotMultiBarChart::Stacked );
    }
}*/

/*void BarChart::setOrientation( int orientation )
{
    QwtPlot::Axis axis1, axis2;

    if ( orientation == 0 )
    {
        axis1 = QwtPlot::xBottom;
        axis2 = QwtPlot::yLeft;

        d_barChartItem->setOrientation( Qt::Vertical );
    }
    else
    {
        axis1 = QwtPlot::yLeft;
        axis2 = QwtPlot::xBottom;

        d_barChartItem->setOrientation( Qt::Horizontal );
    }

    setAxisScale( axis1, 0, d_barChartItem->dataSize() - 1, 1.0 );
    setAxisAutoScale( axis2 );

    QwtScaleDraw *scaleDraw1 = axisScaleDraw( axis1 );
    scaleDraw1->enableComponent( QwtScaleDraw::Backbone, false );
    scaleDraw1->enableComponent( QwtScaleDraw::Ticks, false );

    QwtScaleDraw *scaleDraw2 = axisScaleDraw( axis2 );
    scaleDraw2->enableComponent( QwtScaleDraw::Backbone, true );
    scaleDraw2->enableComponent( QwtScaleDraw::Ticks, true );

    plotLayout()->setAlignCanvasToScale( axis1, true );
    plotLayout()->setAlignCanvasToScale( axis2, false );

    plotLayout()->setCanvasMargin( 0 );
    updateCanvasMargins();

    replot();
}*/
/*
void BarChart::exportChart()
{
    QwtPlotRenderer renderer;
    renderer.exportTo( this, "barchart.pdf" );
}*/
