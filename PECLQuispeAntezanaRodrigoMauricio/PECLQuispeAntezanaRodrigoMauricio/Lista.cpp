#include "Lista.hpp"

Lista::Lista()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

void Lista::almacenar(Pedido p)
{
    pnodoLista nuevo = new NodoLista(p);

    if (!primero || p.getId() <= primero->pedido.getId()) {
        nuevo->siguiente = primero;
        primero = nuevo;
    } else {
        pnodoLista anterior = primero;
        pnodoLista actual = primero->siguiente;

        while (actual && p.getId() > actual->pedido.getId()) {
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
        cout<<"Es urgente: "<<aux ->pedido.esUrgente()<<" DNI: "<<aux->pedido.getDni()<<" ID: "<<aux->pedido.getId()<<" Numero de seguimiento: "<<aux->pedido.getNumeroSeguimiento()<<endl;
        aux = aux ->siguiente;
    }
    cout << endl;
}
Pedido Lista::eliminar()
{
    pnodoLista nodo;
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

int Lista::getLongitud()
{
    return this ->longitud;
}
Pedido Lista::verPrimero()
{
    return primero->pedido;
}
Pedido Lista::verUltimo()
{
    pnodoLista aux = primero;
    while (aux && aux->siguiente) {
        aux = aux->siguiente;
    }
    if (aux) {
        return aux->pedido;
    } else {
        return Pedido();
    }
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

