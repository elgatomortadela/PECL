#include "Cola.hpp"

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}
Pedido pedido;
void Cola::insertar(Pedido p)
{
    
    pnodoCola nuevo;
    nuevo = new NodoCola(p);
    if(ultimo)
        ultimo ->siguiente = nuevo;
    ultimo = nuevo;
    if(!primero)
        primero = nuevo;
    longitud++;
}
void Cola::mostrar()
{
    pnodoCola aux = primero;
    cout <<"Los pedidos son:"<<endl;
    while(aux) {

        cout <<" Es urgente: " << aux ->pedido.esUrgente()<<" DNI: "<<aux->pedido.getDni()<<" ID: "<<aux->pedido.getId()<<endl;

        aux = aux ->siguiente;
    }
    cout << endl;
}
Pedido Cola::eliminar()
{
    pnodoCola nodo;
    Pedido p;
    nodo = primero;
    if(!nodo)
        return Pedido();
    primero = nodo ->siguiente;
    p = nodo ->pedido;
    delete nodo;
    if(!primero)
        ultimo = NULL;
    longitud--;
    return p;
}
Pedido Cola::verPrimero()
{
    return primero ->pedido;
}
int Cola::getLongitud()
{
    return this ->longitud;
}
Cola::~Cola()
{
    while(primero)
        eliminar();
}

