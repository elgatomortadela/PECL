#include "Pedido.hpp"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>
#include <random>
#include <algorithm>
using namespace std;


Pedido::Pedido()
{
    this->urgencia = (rand()%2);
    this->generarDNI();
    this->generarID();
    this->generarNumeroSeguimiento();
}
bool Pedido::esUrgente()
{
    return this->urgencia; // 1: urgente, 0: estandar
}
void Pedido::mostrar()
{
    cout<<"Es urgente: "<<urgencia<<" DNI: "<<DNI<<endl;
}
void Pedido::generarDNI()
{
    char letras[]="TRWAGMYFPDXBNJZSQVHLCKE";
    int numDNI = 0, aux = 1E7;
    for(int i = 0; i < 8; i++) {
        int num = rand()%10;
        this->DNI[i]='0'+num;
        numDNI = numDNI+num*aux;
        aux /=10;
    }
    this->DNI[8] = letras[numDNI%23];
    this->DNI[9] = '\0';
}
void Pedido::generarID()
{
    int tamano = 49; // Generador de ids urgentes
    int numeros[tamano];
    
    if(urgencia){
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
        id=numeros[0];
    }
        
    else if(!urgencia){
        // Rellenar el array con números del 1 al 49
        for (int i = 0; i < tamano; i++) {
            numeros[i] = i + 1;
        }
        random_device rd2;
        mt19937 g(rd2());
        // Mezclar aleatoriamente los elementos del array
        shuffle(numeros, numeros + tamano, g);
        int contador = 0;
        id=numeros[0];
        
    }
}
void Pedido::generarNumeroSeguimiento()
{
    int tamano = 448; // Generador de ids urgentes
    int numeros[tamano];
    
    if(urgencia){
        // Rellenar el array con números del 501 y 999
        for (int i = 0; i < tamano; i++) {
            numeros[i] = i + 501;
        }
        random_device rd2;
        mt19937 g(rd2());
        // Mezclar aleatoriamente los elementos del array
        shuffle(numeros, numeros + tamano, g);
        int contador = 0;
        numeroSeguimiento = numeros[contador];
        
    }
    else if(!urgencia){
        // Rellenar el array con números del 1 al 449
        for (int i = 0; i < tamano; i++) {
            numeros[i] = i + 1;
        }
        random_device rd2;
        mt19937 g(rd2());
        // Mezclar aleatoriamente los elementos del array
        shuffle(numeros, numeros + tamano, g);
        int contador = 0;
        numeroSeguimiento = numeros[contador];
        
    }
}

Pedido::~Pedido()
{
}
