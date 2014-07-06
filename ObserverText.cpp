#include "ObserverText.h"
#include <qwt_plot_renderer.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_multi_barchart.h>
#include <qwt_column_symbol.h>
#include <qwt_plot_layout.h>
#include <qwt_legend.h>
#include <qwt_scale_draw.h>
#include "Weather.h"

ObserverText::ObserverText( QWidget *parent):
    QLabel( parent )
{
    label = new QLabel(NULL);
    label = this;
}

void ObserverText::update()
{
    string labelText = "";
    for(int i = 0; i < 6 ; i++)
    {
        //labelText = Weather::arrWeather[i].location.c_str() + "  " + Weather::arrWeather[i].temp.c_str() + "\n";
        labelText.append(Weather::arrWeather[i].location.c_str());
        if(i<4)
            labelText.append("\t\t");
        else
            labelText.append("\t");
        labelText.append(Weather::arrWeather[i].temp.c_str());
        labelText.append(" ºC\n\n");
    }

    this->setText(QString::fromStdString(labelText));
    cout << "ObserverText.update() called" << endl;
}
