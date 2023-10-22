#include "Lista.hpp"

Lista::Lista()
{
    ultimo = NULL;
    longitud = 0;
}
void Lista::almacenar(Pedido p)
{
    pnodoLista nuevo;
    nuevo = new NodoLista(p);
    if(ultimo)
        ultimo ->siguiente = nuevo;
    ultimo = nuevo;
    if(!primero)
        primero = nuevo;
    longitud++;
    
}
void Lista::mostrar()
{
    pnodoLista aux = primero;
    cout <<"Los pedidos son:"<<endl;
    while(aux) {
        cout <<" Es urgente: " << aux ->pedido.urgencia<<" DNI: "<<aux->pedido.DNI<<" ID: "<<aux->pedido.id<<" Numero de seguimiento: "<<aux->pedido.numeroSeguimiento<<endl;
        aux = aux ->siguiente;
    }
    cout << endl;
}
/*
Pedido Lista::ordenar()
{
    //1 --> prioridad estandar
    //51 --> prioridad urgente
}*/
int Lista::getLongitud()
{
    return this ->longitud;
}

Lista::~Lista()
{
    pnodoLista aux;
    while(ultimo) {
        aux = ultimo;
        ultimo = ultimo ->siguiente;
        delete aux;
    }
}

