#ifndef LISTA_HPP
#define LISTA_HPP
#include "NodoLista.hpp"

class Lista
{
public:
    Lista();
    ~Lista();
    void almacenar(Pedido p);
    void mostrar();
    //Pedido ordenar();
    int getLongitud();
    Pedido verPrimero();
    Pedido eliminar();
    Pedido verUltimo();
private:
    pnodoLista primero, ultimo;
    int longitud;

};

#endif // LISTA_HPP
