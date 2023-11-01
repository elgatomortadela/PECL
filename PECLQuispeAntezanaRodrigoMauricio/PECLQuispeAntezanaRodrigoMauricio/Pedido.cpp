#include "Pedido.hpp"

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
    string tipo = "Estándar";
    if(urgencia)
        tipo = "Urgente";
    cout<<"\t"<<setw(8)<<tipo<<" ID "<<id<<" numeroSeguimiento "<<numeroSeguimiento<<" DNI "<<DNI<<endl;
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
    if(urgencia){
        int tamano = 49;
        int numeros[tamano];
        for (int i = 0; i < tamano; i++) {
        numeros[i] = i + 51;
    }
    random_device rd;
    mt19937 g(rd());
    shuffle(numeros, numeros + tamano, g);
    id = numeros[0];
    }
    else if(!urgencia){
        int tamano2 = 49; // Generador de ids estandar 
        int numeros2[tamano2];
        for (int i = 0; i < tamano2; i++) {
        numeros2[i] = i + 1;
    }
    random_device rd2;
    mt19937 g2(rd2());
    shuffle(numeros2, numeros2 + tamano2, g2);
    id = numeros2[0];
    }
}
void Pedido::generarNumeroSeguimiento()
{
    if(urgencia){
        int tamano = 499;
        int numeros[tamano];
        for (int i = 0; i < tamano; i++) {
        numeros[i] = i + 501;
    }
    random_device rd;
    mt19937 g(rd());
    shuffle(numeros, numeros + tamano, g);
    numeroSeguimiento = numeros[0];
    }
    else if(!urgencia){
        int tamano2 = 499; // Generador de ids estandar 
        int numeros2[tamano2];
        for (int i = 0; i < tamano2; i++) {
        numeros2[i] = i + 1;
    }
    random_device rd2;
    mt19937 g2(rd2());
    shuffle(numeros2, numeros2 + tamano2, g2);
    numeroSeguimiento = numeros2[0];
    }
}
Pedido::~Pedido()
{
}

