#ifndef BOTON_H
#define BOTON_H



#include <QColor>
#include <QString>

class Boton
{
public:

    Boton(QString newCaption , QColor c);

    virtual ~Boton();

    QString getCaption();

    QColor getColor();

private:

    QColor Color;
    QString Caption ;

};

#endif // BOTON_H
