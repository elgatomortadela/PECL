#include "Gestor.hpp"

Gestor::Gestor()
{
}

Pila pila;
Cola colaA; //Cola para estandar
Cola colaB;//Cola para estandar
Cola colaC;//Cola para urgente
Cola colaD;//Cola para urgente
Lista listaEstandar;
Lista listaUrgente;


void Gestor::genera12Pedidos()
{
    int longitudTotal = pila.getLongitud()+colaA.getLongitud()+colaB.getLongitud()+colaC.getLongitud()+colaD.getLongitud()+listaEstandar.getLongitud()+listaUrgente.getLongitud();
    if(longitudTotal!=48)
        for(int i =0; i< 12; i++) {
            Pedido pedido;
            pila.insertar(pedido);
    }
}
void Gestor::muestraPedidos()
{
    pila.mostrar();
}
int Gestor::PedidosEnPila()
{
    return pila.getLongitud();
}
void Gestor::borraPedidosPila()
{
    while(pila.getLongitud() >0) {
        pila.extraer();
    }
}
void Gestor::encolarPedidos()
{
    while (pila.getLongitud() >0) {
        if(pila.cima().urgencia){
            if(colaC.getLongitud() > colaD.getLongitud() or colaC.getLongitud() == colaD.getLongitud()){
                 colaD.insertar(pila.cima());
            }
            else if(colaD.getLongitud() > colaC.getLongitud()){
                colaC.insertar(pila.cima());
            }
        }
        else if(pila.cima().urgencia == false){
            if(colaA.getLongitud() > colaB.getLongitud() or colaA.getLongitud() == colaB.getLongitud()){
                colaB.insertar(pila.cima());
            }
            else if(colaB.getLongitud() > colaA.getLongitud()){
                colaA.insertar(pila.cima());
            }
        }
        pila.extraer();
    }
        
}
void Gestor::muestraPedidosSalasAyB()
{
    cout<<"Cola A: "<< endl;
    colaA.mostrar();
    cout<<"Cola B: "<< endl;
    colaB.mostrar();
}
void Gestor::muestraPedidosSalasCyD()
{
    cout<<"Cola C: "<<endl;
    colaC.mostrar();
    cout<<"Cola D: "<<endl;
    colaD.mostrar();
}
int Gestor::PedidosEnSalaA()
{
    return colaA.getLongitud();
}
int Gestor::PedidosEnSalaB()
{
    return colaB.getLongitud();
}
int Gestor::PedidosEnSalaC()
{
    return colaC.getLongitud();
}
int Gestor::PedidosEnSalaD()
{
    return colaD.getLongitud();
}
void Gestor::borraPedidosColas()
{
    while(colaA.getLongitud() >0) {
        colaA.eliminar();
    }
    while(colaB.getLongitud() >0) {
        colaB.eliminar();
    }
    while(colaC.getLongitud() >0) {
        colaC.eliminar();
    }
    while(colaD.getLongitud() >0) {
        colaD.eliminar();
    }
}
void Gestor::enlistarPedidos()
{
    while(colaA.getLongitud() > 0)
    {
      listaEstandar.almacenar(colaA.verPrimero());
      colaA.eliminar();
    }

    while(colaB.getLongitud() > 0)
    {
      listaEstandar.almacenar(colaB.verPrimero());
      colaB.eliminar();
    }
    
    while(colaC.getLongitud() > 0)
    {
      listaUrgente.almacenar(colaC.verPrimero());
      colaC.eliminar();
    }
    
    while(colaD.getLongitud() > 0)
    {
      listaUrgente.almacenar(colaD.verPrimero());
      colaD.eliminar();
    }
    
}
int Gestor::PedidosEnListaEstandar()
{
    return listaEstandar.getLongitud();
}
int Gestor::PedidosEnListaUrgentes()
{
    return listaUrgente.getLongitud();
}
void Gestor::muestraPedidosUrgentes()
{
    cout<<"Lista Urgente: "<< endl;
    listaUrgente.mostrar();
}
void Gestor::muestraPedidosEstandar()
{
    cout<<"Lista Estandar: "<< endl;
    listaEstandar.mostrar();
}
void Gestor::reiniciar()
{
    borraPedidosColas();
    borraPedidosPila();
}
Gestor::~Gestor()
{
}
