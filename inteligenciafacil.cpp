#include "inteligenciafacil.h"

InteligenciaFacil::InteligenciaFacil()
{

}


Carta *InteligenciaFacil::SeleccionarCarta()
{
    return CartaMasBaja();
}
