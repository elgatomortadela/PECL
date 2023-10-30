#include "Pedido.hpp"

Pedido::Pedido()
{
    this->urgencia = (rand()%2);
    this->generarDNI();
    this->id = 0;
    this->numeroSeguimiento = 0;
    //this->id = id;
    //this->numeroSeguimiento = numeroSeguimiento;
}
bool Pedido::esUrgente()
{
    return this->urgencia; // 1: urgente, 0: estandar
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
void Pedido::setId(int id)
{
    this->id = id;
}
void Pedido::setNumeroSeguimiento(int numeroSeguimiento)
{
    this->numeroSeguimiento = numeroSeguimiento;
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

