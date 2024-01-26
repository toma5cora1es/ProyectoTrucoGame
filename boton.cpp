#include "boton.h"



Boton::Boton(QString newCaption, QColor c)
{
   Color = c;
   Caption = newCaption;
}


Boton::~Boton()
{

}

QString Boton::getCaption()
{
    return Caption;
}

QColor Boton::getColor()
{
    return Color;
}






