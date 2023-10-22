#ifndef PILA_HPP
#define PILA_HPP
#include "NodoPila.hpp"
#include "Pedido.hpp"

class Pila
{
public:
    Pila();
    ~Pila();
    void insertar(Pedido p);
    Pedido extraer();
    Pedido cima();
    void mostrar();
    int getLongitud();
    
private:
    pnodoPila ultimo;
    int longitud;

};

#endif // PILA_HPP
