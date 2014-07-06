#include <qapplication.h>
#include <qmainwindow.h>
#include <qtoolbar.h>
#include <qtoolbutton.h>
#include <qcombobox.h>
#include "ObserverBar.h"
#include "ObserverGraph.h"
#include "ObserverText.h"
#include "Controller.h"
#include <qwt_plot_renderer.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_multi_barchart.h>
#include <qwt_column_symbol.h>
#include <qwt_plot_layout.h>
#include <qwt_legend.h>
#include <qwt_scale_draw.h>
#include <qwt_plot_grid.h>
#include <qwt_symbol.h>
#include <QtWidgets/QLabel>
#include <QTimer>
#include <qwt_plot_barchart.h>

class MainWindow: public QMainWindow
{
public:
    MainWindow( QWidget * = NULL );

private:
    ObserverBar *barChart;
    ObserverGraph *plot;
    ObserverText *label;
};

MainWindow::MainWindow( QWidget *parent ):
    QMainWindow( parent )
{
    /////////////////////////////////////////// BarChart //////////////////////////////////////////////////

    QwtPlotMultiBarChart *d_barChartItem;
    d_barChartItem = new QwtPlotMultiBarChart( "Bar Chart " );
    barChart = new ObserverBar( this, d_barChartItem );

    barChart->setAutoFillBackground( true );
    barChart->canvas()->setPalette( QColor( "White" ) );
    //barChart->setTitle( "Temperature" );
    barChart->setAxisTitle( QwtPlot::yLeft, "Temperature in ºC" );
    barChart->setAxisTitle( QwtPlot::xBottom, "Location" );
    barChart->insertLegend( new QwtLegend() );

    QwtPlotGrid *grid1 = new QwtPlotGrid();
    //grid->attach( &plot );
    grid1->attach( (QwtPlot*)barChart );

    d_barChartItem->setLayoutPolicy( QwtPlotMultiBarChart::AutoAdjustSamples );
    d_barChartItem->setSpacing( 20 );
    d_barChartItem->setMargin( 3 );

    d_barChartItem->attach( barChart );

    barChart->setAutoReplot( true );
    barChart->setGeometry(30, 30, 400, 400);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////// CurveChart /////////////////////////////////////////////////

    QwtPlotCurve *curve = new QwtPlotCurve();
    plot = new ObserverGraph(this, curve);
    plot->setCanvasBackground( Qt::white );
    plot->insertLegend( new QwtLegend() );

    plot->setAxisTitle( QwtPlot::yLeft, "Temperature in ºC" );
    plot->setAxisTitle( QwtPlot::xBottom, "Location" );

    QwtPlotGrid *grid2 = new QwtPlotGrid();
    grid2->attach( (QwtPlot*)plot );

    curve->setPen( Qt::gray, 4 ),
    curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );

    QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
    QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 6, 6 ) );
    curve->setSymbol( symbol );
    curve->attach( (QwtPlot*)plot );

    plot->setAutoReplot( true );
    plot->setGeometry(450,30,400,400);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////// Label ////////////////////////////////////////////////////

    label = new ObserverText(this);
    label->setObjectName(QStringLiteral("label"));
    label->setGeometry(925, 60, 200, 200);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////// Controller ////////////////////////////////////////////////

    Controller *controller = new Controller();
    controller->subject->attach(barChart);
    controller->subject->attach(plot);
    controller->subject->attach(label);
    controller->applyChanges();

    ///////////////////////////////////////////////////////////////////////////////////////////////////////

}
    /////////////////////////////////////////// Main //////////////////////////////////////////////////////

int main( int argc, char **argv )
{
    QApplication a( argc, argv );
    MainWindow mainWindow;

    mainWindow.resize( 1300, 450 );
    mainWindow.show();
    mainWindow.setWindowTitle("Temperature Display");

    return a.exec();
}

    //////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
