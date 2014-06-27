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

ObserverGraph::ObserverGraph( QWidget *parent ):
    QwtPlot( parent )
{
    setAutoFillBackground( true );

    setPalette( Qt::white );
    canvas()->setPalette( QColor( "LemonChiffon" ) );

    setTitle( "Curve Chart" );

    setAxisTitle( QwtPlot::yLeft, "Whatever" );
    setAxisTitle( QwtPlot::xBottom, "Whatever" );

    d_curveChartItem = new QwtPlotCurve( "Curve Chart " );


}
/*
void ObserverGraph::populate()
{
    static const char *colors[] = { "DarkOrchid", "SteelBlue", "Gold" };

    const int numSamples = 5;
    const int numBars = sizeof( colors ) / sizeof( colors[0] );

    QList<QwtText> titles;
    for ( int i = 0; i < numBars; i++ )
    {
        QString title("Bar %1");
        titles += title.arg( i );
    }
    d_curveChartItem->setBarTitles( titles );
    d_curveChartItem->setLegendIconSize( QSize( 10, 14 ) );

    for ( int i = 0; i < numBars; i++ )
    {
        QwtColumnSymbol *symbol = new QwtColumnSymbol( QwtColumnSymbol::Box );
        symbol->setLineWidth( 2 );
        symbol->setFrameStyle( QwtColumnSymbol::Raised );
        symbol->setPalette( QPalette( colors[i] ) );

        d_curveChartItem->setSymbol( i, symbol );
    }
    
    QVector< QVector<double> > series;
    for ( int i = 0; i < numSamples; i++ )
    {
        QVector<double> values;
        for ( int j = 0; j < numBars; j++ )
            values += ( 2 + qrand() % 8 );

        series += values;
    }

    d_curveChartItem->setSamples( series );
}*/

void ObserverGraph::update()
{
    // update chart Balken
}

/*void BarChart::setMode( int mode )
{
    if ( mode == 0 )
    {
        d_curveChartItem->setStyle( QwtPlotMultiBarChart::Grouped );
    }
    else
    {
        d_curveChartItem->setStyle( QwtPlotMultiBarChart::Stacked );
    }
}*/

/*void BarChart::setOrientation( int orientation )
{
    QwtPlot::Axis axis1, axis2;

    if ( orientation == 0 )
    {
        axis1 = QwtPlot::xBottom;
        axis2 = QwtPlot::yLeft;

        d_curveChartItem->setOrientation( Qt::Vertical );
    }
    else
    {
        axis1 = QwtPlot::yLeft;
        axis2 = QwtPlot::xBottom;

        d_curveChartItem->setOrientation( Qt::Horizontal );
    }

    setAxisScale( axis1, 0, d_curveChartItem->dataSize() - 1, 1.0 );
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
