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
    
    if(pila.getLongitud()!=48)
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
    int tamano = 49; // Generador de ids urgentes
    int numeros[tamano];
    // Rellenar el array con números del 51 al 99
    for (int i = 0; i < tamano; i++) {
        numeros[i] = i + 51;
    }
    // Generador de números aleatorios
    random_device rd;
    mt19937 g(rd());
    // Mezclar aleatoriamente los elementos del array
    shuffle(numeros, numeros + tamano, g);
    int contador = 0;
    
    int tamano2 = 49; // Generador de ids estandar 
    int numeros2[tamano2];
    // Rellenar el array con números del 1 al 49
    for (int i = 0; i < tamano2; i++) {
        numeros2[i] = i + 1;
    }
    random_device rd2;
    mt19937 g2(rd2());
    // Mezclar aleatoriamente los elementos del array
    shuffle(numeros2, numeros2 + tamano2, g2);
    int contador2 = 0;
    
    while (pila.getLongitud() >0) {
        if(pila.cima().urgencia){
            pila.cima().setId(numeros[contador]);
            if(colaC.getLongitud() > colaD.getLongitud() or colaC.getLongitud() == colaD.getLongitud()){
                 colaD.insertar(pila.cima());
            }
            else if(colaD.getLongitud() > colaC.getLongitud()){
                colaC.insertar(pila.cima());
            }
            contador = (contador + 1) % tamano;
        }
        else if(pila.cima().urgencia == false){
            pila.cima().setId(numeros2[contador2]);
            if(colaA.getLongitud() > colaB.getLongitud() or colaA.getLongitud() == colaB.getLongitud()){
                colaB.insertar(pila.cima());
            }
            else if(colaB.getLongitud() > colaA.getLongitud()){
                colaA.insertar(pila.cima());
            }
            contador2 = (contador2 + 1) % tamano2;
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
