#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP
#include <iostream>
#include <Pedido.hpp>
using namespace std;

class NodoCola
{
public:
    NodoCola(Pedido p, NodoCola* sig = NULL);
    ~NodoCola();

private:
    Pedido pedido;
    NodoCola* siguiente;
    
    friend class Cola;
};

typedef NodoCola* pnodoCola;

#endif // NODOCOLA_HPP
