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

/*Implementation of the update function() for Label, gets the new data from the weather class
  and refreshs text(weather data) on the GUI
*/
void ObserverText::update()
{
    string labelText = "";
    for(int i = 0; i < 8 ; i++)
    {
        if(i<2)
        {
            labelText.append(Weather::metaData[i].c_str());
            labelText.append("\n\n");
            continue;
        }
        labelText.append(Weather::arrWeather[i-2].location.c_str());
        if(i<6)
            labelText.append("\t\t");
        else
            labelText.append("\t");
        labelText.append(Weather::arrWeather[i-2].temp.c_str());
        labelText.append(" ºC\n\n");
    }

    this->setText(QString::fromStdString(labelText));
    cout << "ObserverText.update() called" << endl;
}
