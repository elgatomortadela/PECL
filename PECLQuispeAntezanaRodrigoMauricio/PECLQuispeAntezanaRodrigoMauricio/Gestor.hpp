#ifndef GESTOR_HPP
#define GESTOR_HPP
#include <Pedido.hpp>
#include <NodoPila.hpp>
#include <Pila.hpp>
#include <NodoCola.hpp>
#include <Cola.hpp>
#include <iostream>
using namespace std;

class Gestor
{
public:
    Gestor();
    ~Gestor();
    void genera12Pedidos();
    void muestraPedidos();
    void borraPedidosPila();
    int PedidosEnPila();
    int PedidosEnSalaA();
    int PedidosEnSalaB();
    int PedidosEnSalaC();
    int PedidosEnSalaD();
    void encolarPedidos();
    void muestraPedidosSalasAyB();
    void muestraPedidosSalasCyD();
    void borraPedidosColas();

};

#endif // GESTOR_HPP
