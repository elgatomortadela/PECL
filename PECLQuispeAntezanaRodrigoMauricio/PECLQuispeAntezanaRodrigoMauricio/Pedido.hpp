#ifndef PEDIDO_HPP
#define PEDIDO_HPP
#include <iostream>
#include <iomanip>
using namespace std;

class Pedido
{
public:
    Pedido();
    bool esUrgente();
    void mostrar();
    void setId(int id);
    void setNumeroSeguimiento(int numeroSeguimiento);
    int getId();
    int getNumeroSeguimiento();
    char* getDni();
    ~Pedido();
private:
    int id;
    int numeroSeguimiento;
    bool urgencia;
    char DNI[10];
    
    void generarDNI();

};

typedef Pedido* pPedido;
#endif // PEDIDO_HPP
