#ifndef NODOPILA_HPP
#define NODOPILA_HPP
#include "Pedido.hpp"
#include <iostream>
using namespace std;

class NodoPila
{
public:
    NodoPila(Pedido p, NodoPila* sig = NULL);
    ~NodoPila();

private:
    Pedido pedido;
    NodoPila* siguiente;
    friend class Pila;

};

typedef NodoPila* pnodoPila;

#endif // NODOPILA_HPP
