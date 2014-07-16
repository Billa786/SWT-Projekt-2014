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
#include <qcolor.h>
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
    /* ---------------- BarChart --------------------------- */

    /*Create barChart and set its attributes and finally set its position on GUI*/
    QwtPlotMultiBarChart *barChartItem;
    barChartItem = new QwtPlotMultiBarChart( "Bar Chart " );
    barChart = new ObserverBar( this, barChartItem );

    barChart->setAutoFillBackground( true );
    barChart->canvas()->setPalette( QColor( "White" ) );
    //barChart->setTitle( "Temperature" );
    barChart->setAxisTitle( QwtPlot::yLeft, "Temperature in ºC" );
    barChart->setAxisTitle( QwtPlot::xBottom, "Location" );
    barChart->insertLegend( new QwtLegend() );

    QwtPlotGrid *gridBar = new QwtPlotGrid();
    gridBar->attach( (QwtPlot*)barChart );

    barChartItem->setLayoutPolicy( QwtPlotMultiBarChart::AutoAdjustSamples );
    barChartItem->setSpacing( 20 );
    barChartItem->setMargin( 3 );

    barChartItem->attach( barChart );

    barChart->setAutoReplot( true );
    barChart->setGeometry(30, 30, 400, 400);


    /* ---------------------- CurveChart ---------------------- */

    /*Create plot and set its attributes and finally set its position on GUI*/
    QwtPlotCurve *curve = new QwtPlotCurve();
    plot = new ObserverGraph(this, curve);
    plot->setCanvasBackground( Qt::white );
    plot->insertLegend( new QwtLegend() );

    plot->setAxisTitle( QwtPlot::yLeft, "Temperature in ºC" );
    plot->setAxisTitle( QwtPlot::xBottom, "Location" );

    QwtPlotGrid *gridPlot = new QwtPlotGrid();
    gridPlot->attach( (QwtPlot*)plot );

    curve->setPen( Qt::gray, 4 ),
    curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );

    QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
    QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 6, 6 ) );
    curve->setSymbol( symbol );
    curve->attach( (QwtPlot*)plot );

    plot->setAutoReplot( true );
    plot->setGeometry(450,30,400,400);



    /* ---------------- Label ------------------- */

    /*Create label and set its position on GUI*/
    label = new ObserverText(this);
    label->setObjectName(QStringLiteral("label"));
    label->setGeometry(925, 60, 200, 250);



    /* ----------- Controller ----------- */

    /*Create controller and add observers to list
      and call the applyChanges function once to initialize*/
    Controller *controller = new Controller();
    controller->subject->attach(barChart);
    controller->subject->attach(plot);
    controller->subject->attach(label);
    controller->applyChanges();

}

int main( int argc, char **argv )
{
    QApplication a( argc, argv );
    MainWindow mainWindow;

    mainWindow.resize( 1300, 450 );
    mainWindow.show();
    mainWindow.setWindowTitle("Temperature Display");

    return a.exec();
}
