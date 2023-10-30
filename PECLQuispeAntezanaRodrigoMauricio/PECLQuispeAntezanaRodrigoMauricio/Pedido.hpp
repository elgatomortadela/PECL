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
    int getId();
    void setNumeroSeguimiento(int numeroSeguimiento);
    int getNumeroSeguimiento();
    ~Pedido();
private:
    int id;
    int numeroSeguimiento;
    bool urgencia;
    char DNI[10];
    
    void generarDNI();
    //void generarID();
    //void generarNumeroSeguimiento();
    
    friend class NodoPila;
    friend class Pila;
    friend class NodoCola;
    friend class Cola;
    friend class Gestor;
    friend class Lista;
    friend class NodoLista;

};

typedef Pedido* pPedido;
#endif // PEDIDO_HPP
