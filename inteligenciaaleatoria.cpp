#include "inteligenciaaleatoria.h"

InteligenciaAleatoria::InteligenciaAleatoria()
{

}


Carta *InteligenciaAleatoria::SeleccionarCarta()
{
    return Mano[QRandomGenerator::global()->bounded(Mano.size())];
}
