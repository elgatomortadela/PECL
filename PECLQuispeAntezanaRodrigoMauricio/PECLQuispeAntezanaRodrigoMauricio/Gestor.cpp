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
    while (pila.getLongitud() > 0) {
        if(pila.cima().urgencia){
            if(colaC.getLongitud() > colaD.getLongitud() or colaC.getLongitud() == colaD.getLongitud()){
                 colaD.insertar(pila.cima());
            }
            else if(colaD.getLongitud() > colaC.getLongitud()){
                colaC.insertar(pila.cima());
            }
            /*
            int tamano = 49; // Generador de ids??
            int numeros[tamano];

            // Rellenar el array con números del 1 al 49
            for (int i = 0; i < tamano; i++) {
                numeros[i] = i + 1;
            }

            // Crear un generador de números aleatorios
            random_device rd;
            mt19937 g(rd());

            // Mezclar aleatoriamente los elementos del array
            shuffle(numeros, numeros + tamano, g);

            // Imprimir el array mezclado
            for (int i = 0; i < tamano; i++) {
                cout << numeros[i] << ' ';
            }*/

        }
        else if(pila.cima().urgencia == false){
            if(colaA.getLongitud() > colaB.getLongitud() or colaA.getLongitud() == colaB.getLongitud()){
                colaB.insertar(pila.cima());
            }
            else if(colaB.getLongitud() > colaA.getLongitud()){
                colaA.insertar(pila.cima());
            }/*
            int tamano = 49; // Generador de ids??
            int numeros[tamano];

            // Rellenar el array con números del 51 al 99
            for (int i = 0; i < tamano; i++) {
                numeros[i] = i + 51;
            }

            // Crear un generador de números aleatorios
            random_device rd;
            mt19937 g(rd());

            // Mezclar aleatoriamente los elementos del array
            shuffle(numeros, numeros + tamano, g);

            // Imprimir el array mezclado
            for (int i = 0; i < tamano; i++) {
                cout << numeros[i] << ' ';
            }*/
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
    }/*
    int tamano2 = 499;
    int numeros2[tamano2];
    
    // Rellenar el array con números del 1 al 499
    for (int i = 0; i < tamano2; i++) {
        numeros2[i] = i + 1;
    }

    // Crear un generador de números aleatorios
    random_device rd2;
    mt19937 g2(rd2());

    // Mezclar aleatoriamente los elementos del array
    shuffle(numeros2, numeros2 + tamano2, g2);

    // Imprimir el array mezclado
    for (int i = 0; i < tamano2; i++) {
        cout << numeros2[i] << ' ';
    }*/
    while(colaB.getLongitud() > 0)
    {
      listaEstandar.almacenar(colaB.verPrimero());
      colaB.eliminar();
    }/*
    int tamano = 499;
    int numeros[tamano];

    // Rellenar el array con números del 501 al 999
    for (int i = 0; i < tamano; i++) {
        numeros[i] = i + 1;
    }

    // Crear un generador de números aleatorios
    random_device rd;
    mt19937 g(rd());

    // Mezclar aleatoriamente los elementos del array
    shuffle(numeros, numeros + tamano, g);

    // Imprimir el array mezclado
    for (int i = 0; i < tamano; i++) {
        cout << numeros[i] << ' ';
    }*/
    while(colaC.getLongitud() > 0)
    {
      listaUrgente.almacenar(colaC.verPrimero());
      colaC.eliminar();
    }/*
    int tamano3 = 499;
    int numeros3[tamano3];

    // Rellenar el array con números del 501 al 999
    for (int i = 0; i < tamano3; i++) {
        numeros3[i] = i + 501;
    }

    // Crear un generador de números aleatorios
    random_device rd3;
    mt19937 g3(rd3());

    // Mezclar aleatoriamente los elementos del array
    shuffle(numeros3, numeros3 + tamano3, g3);

    // Imprimir el array mezclado
    for (int i = 0; i < tamano3; i++) {
        cout << numeros3[i] << ' ';
    }*/
    while(colaD.getLongitud() > 0)
    {
      listaUrgente.almacenar(colaD.verPrimero());
      colaD.eliminar();
    }/*
    int tamano4 = 499;
    int numeros4[tamano4];

    // Rellenar el array con números del 501 al 999
    for (int i = 0; i < tamano4; i++) {
        numeros4[i] = i + 501;
    }

    // Crear un generador de números aleatorios
    random_device rd4;
    mt19937 g4(rd4());

    // Mezclar aleatoriamente los elementos del array
    shuffle(numeros4, numeros4 + tamano4, g4);

    // Imprimir el array mezclado
    for (int i = 0; i < tamano4; i++) {
        cout << numeros4[i] << ' ';
    }*/
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
void Gestor::buscarPedidos()
{
    if (listaUrgente.getLongitud() > 0) {
        cout<<"Pedido prioritario Urgente: "<<endl;
        listaUrgente.verPrimero().mostrar();
    } else {
        cout<<"No hay pedidos urgentes." << endl;
    }

    if (listaEstandar.getLongitud() > 0) {
        cout<<"Pedido prioritario Estandar: "<<endl;
        listaEstandar.verPrimero().mostrar();
    } else {
        cout<<"No hay pedidos estandar." << endl;
    }
}
void Gestor::reiniciar()
{
    borraPedidosColas();
    borraPedidosPila();
}
Gestor::~Gestor()
{
}
