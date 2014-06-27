#include <qapplication.h>
#include <qmainwindow.h>
#include <qtoolbar.h>
#include <qtoolbutton.h>
#include <qcombobox.h>
#include "ObserverBar.h"
#include "Controller.h"
#include <qwt_plot_renderer.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_multi_barchart.h>
#include <qwt_column_symbol.h>
#include <qwt_plot_layout.h>
#include <qwt_legend.h>
#include <qwt_scale_draw.h>

class MainWindow: public QMainWindow
{
public:
    MainWindow( QWidget * = NULL );

private:
    ObserverBar *barChart;
};

MainWindow::MainWindow( QWidget *parent ):
    QMainWindow( parent )
{

    QwtPlotMultiBarChart *d_barChartItem;
    d_barChartItem = new QwtPlotMultiBarChart( "Bar Chart " );
    barChart = new ObserverBar( this, d_barChartItem );
    /////////////////////////////////////////////////////
    barChart->setAutoFillBackground( true );

    barChart->setPalette( Qt::white );
    barChart->canvas()->setPalette( QColor( "LemonChiffon" ) );

    barChart->setTitle( "Temperature" );

    barChart->setAxisTitle( QwtPlot::yLeft, "Temperature" );
    barChart->setAxisTitle( QwtPlot::xBottom, "Location" );


    d_barChartItem->setLayoutPolicy( QwtPlotMultiBarChart::AutoAdjustSamples );
    d_barChartItem->setSpacing( 20 );
    d_barChartItem->setMargin( 3 );

    d_barChartItem->attach( barChart );

    barChart->insertLegend( new QwtLegend() );

    barChart->update();
    //setOrientation( 0 );

    barChart->setAutoReplot( true );
    /// ////////////////////////////////////////////////
    setCentralWidget( barChart );

    QToolBar *toolBar = new QToolBar( this );

    QComboBox *typeBox = new QComboBox( toolBar );
    typeBox->addItem( "Bar" );
    typeBox->addItem( "Graph" );
    typeBox->addItem( "Text" );
    typeBox->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );

    /*QComboBox *orientationBox = new QComboBox( toolBar );
    orientationBox->addItem( "Vertical" );
    orientationBox->addItem( "Horizontal" );
    orientationBox->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );

    QToolButton *btnExport = new QToolButton( toolBar );
    btnExport->setText( "Export" );
    btnExport->setToolButtonStyle( Qt::ToolButtonTextUnderIcon );
    connect( btnExport, SIGNAL( clicked() ), barChart, SLOT( exportChart() ) );*/

    toolBar->addWidget( typeBox );
    //toolBar->addWidget( orientationBox );
    //toolBar->addWidget( btnExport );
    addToolBar( toolBar );

    Controller *controller = new Controller();
    controller->subject->attach(barChart);
    controller->applyChanges();


    //barChart->setMode( typeBox->currentIndex() );
    connect( typeBox, SIGNAL( currentIndexChanged( int ) ),
             barChart, SLOT( setMode( int ) ) );

    //barChart->setOrientation( orientationBox->currentIndex() );
    //connect( orientationBox, SIGNAL( currentIndexChanged( int ) ),
    //         barChart, SLOT( setOrientation( int ) ) );
}

int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    MainWindow mainWindow;

    mainWindow.resize( 600, 400 );
    mainWindow.show();

    return a.exec();
}
