#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP
#include <iostream>
#include "Pedido.hpp"
class NodoArbol
{
public:
    NodoArbol(Pedido dato);
    ~NodoArbol();

private:
    Pedido dato;
    NodoArbol* izq;
    NodoArbol* der;

    friend class Arbol;
};
typedef NodoArbol* pnodoAbb;
#endif // NODOARBOL_HPP