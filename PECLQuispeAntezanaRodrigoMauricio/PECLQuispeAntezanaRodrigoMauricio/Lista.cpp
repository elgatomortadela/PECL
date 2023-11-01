#include "Lista.hpp"

Lista::Lista()
{
    ultimo = NULL;
    longitud = 0;
}
void Lista::almacenar(Pedido p)
{
    pnodoLista nuevo = new NodoLista(p);

    if (!primero || p.id <= primero->pedido.id) {
        nuevo->siguiente = primero;
        primero = nuevo;
    } else {
        pnodoLista anterior = primero;
        pnodoLista actual = primero->siguiente;

        while (actual && p.id > actual->pedido.id) {
            anterior = actual;
            actual = actual->siguiente;
        }

        anterior->siguiente = nuevo;
        nuevo->siguiente = actual;
    }

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

