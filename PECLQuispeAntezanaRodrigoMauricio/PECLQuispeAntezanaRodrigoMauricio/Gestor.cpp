#include "Gestor.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>
#include <random>
#include <algorithm>

Gestor::Gestor()
{
}

Pila pila;
Cola colaA; //Cola para estandar
Cola colaB;//Cola para estandar
Cola colaC;//Cola para urgente
Cola colaD;//Cola para urgente
Lista listaUrgente;
Lista listaEstandar;


void Gestor::genera12Pedidos()
{
    
    if(pila.getLongitud()+colaB.getLongitud()+colaD.getLongitud()+colaC.getLongitud()+colaA.getLongitud()+listaEstandar.getLongitud()+listaUrgente.getLongitud()<48)
        for(int i =0; i< 12; i++) {
            Pedido pedido;
            pila.insertar(pedido);
        }
}
void Gestor::muestraPedidos()
{
    if (pila.getLongitud() > 0) {
        pila.mostrar();
    } 
    else {
        cout<<"Pila vacia." << endl;
    }
    
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
        else if(!pila.cima().urgencia){
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
    if (colaA.getLongitud() > 0) {
        cout<<"Cola A: "<< endl;
        colaA.mostrar();
        cout<<"Cola B: "<< endl;
        colaB.mostrar();
    } 
    else {
        cout<<"Cola vacia." << endl;
    }
}
void Gestor::muestraPedidosSalasCyD()
{
    if (colaC.getLongitud() > 0) {
        cout<<"Cola C: "<<endl;
        colaC.mostrar();
        cout<<"Cola D: "<<endl;
        colaD.mostrar();
    } 
    else {
        cout<<"Cola vacia." << endl;
    }
    
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
void Gestor::borraPedidosLista()
{
    while(listaEstandar.getLongitud() >0) {
        listaEstandar.eliminar();
    }
    while(listaUrgente.getLongitud() >0) {
        listaUrgente.eliminar();
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
    if (listaUrgente.getLongitud() > 0) {
        cout<<"Lista Urgente: "<< endl;
        listaUrgente.mostrar();
    } 
    else {
        cout<<"No hay pedidos urgentes." << endl;
    }
    
}
void Gestor::muestraPedidosEstandar()
{
    if (listaEstandar.getLongitud() > 0) {
        cout<<"Lista Estandar: "<< endl;
        listaEstandar.mostrar();
    } 
    else {
        cout<<"No hay pedidos estandar." << endl;
    }
    
}
void Gestor::buscarPedidos()
{
    if (listaUrgente.getLongitud() > 0) {
        cout<<"Pedido prioritario Urgente: "<<endl;
        listaUrgente.verPrimero().mostrar();
    } 
    else {
        cout<<"No hay pedidos urgentes." << endl;
    }

    if (listaEstandar.getLongitud() > 0) {
        cout<<"Pedido prioritario Estandar: "<<endl;
        listaEstandar.verPrimero().mostrar();
    } 
    else {
        cout<<"No hay pedidos estandar." << endl;
    }
}
void Gestor::reiniciar()
{
    borraPedidosColas();
    borraPedidosPila();
    borraPedidosLista();
}
Gestor::~Gestor(){
    
}