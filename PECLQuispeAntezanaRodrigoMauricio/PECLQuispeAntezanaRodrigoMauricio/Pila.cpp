#include "Pila.hpp"

Pila::Pila()
{
    ultimo = NULL;
    longitud = 0;
}
void Pila::insertar(Pedido p)
{
    pnodoPila nuevo;
    nuevo = new NodoPila(p, ultimo);
    ultimo = nuevo;
    longitud++;
}
Pedido Pila::extraer()
{
    pnodoPila nodo;
    Pedido p;
    if(!ultimo)
        return Pedido();
    nodo = ultimo;
    ultimo = nodo ->siguiente;
    p = nodo ->pedido;
    longitud--;
    delete nodo;
    return p;
}
Pedido Pila::cima()
{
    //pnodoPila nodo;
    if(!ultimo)
        return Pedido();
    return ultimo ->pedido;
}
void Pila::mostrar()
{
    pnodoPila aux = ultimo;
    cout <<" Los datos de los pedidos son:"<<endl;
    while(aux) {
        cout <<" Es urgente:" << aux ->pedido.esUrgente()<<" DNI: " << aux->pedido.getDni()<<endl;
        aux = aux ->siguiente;
    }
    cout << endl;
}
int Pila::getLongitud()
{
    return this ->longitud;
}
Pila::~Pila()
{
    pnodoPila aux;
    while(ultimo) {
        aux = ultimo;
        ultimo = ultimo ->siguiente;
        delete aux;
    }
}

