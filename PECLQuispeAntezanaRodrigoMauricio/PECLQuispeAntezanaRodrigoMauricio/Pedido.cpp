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
    cout<<"\t"<<setw(8)<<tipo<</*" ID "<<id<<" numeroSeguimiento "<<numeroSeguimiento<<*/" DNI "<<DNI<<endl;
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
    if(urgencia)
        id = (rand()%49)+51; // Numero entre 51 y 99
    else if(!urgencia)
        id = (rand()%49)+1;  // Numero entre 1 y 49
}
void Pedido::generarNumeroSeguimiento()
{
    if(urgencia)
        numeroSeguimiento = (rand()%499)+501; // Numero entre 501 y 999
    else if(!urgencia)
        numeroSeguimiento = (rand()%499)+1;  // Numero entre 1 y 499
}
void Pedido::setId(int id)
{
    this -> id = id;
}
void Pedido::setNumeroSeguimiento(int numeroSeguimiento)
{
    this ->numeroSeguimiento = numeroSeguimiento;
}
int Pedido::getId()
{
    return this->id;
}
int Pedido::getNumeroSeguimiento()
{
    return this->numeroSeguimiento;
}
Pedido::~Pedido()
{
}

