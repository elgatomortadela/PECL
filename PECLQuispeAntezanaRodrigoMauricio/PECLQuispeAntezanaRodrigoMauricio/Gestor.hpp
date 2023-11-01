#ifndef GESTOR_HPP
#define GESTOR_HPP
#include <Pedido.hpp>
#include <NodoPila.hpp>
#include <Pila.hpp>
#include <NodoCola.hpp>
#include <Cola.hpp>
#include <NodoLista.hpp>
#include <Lista.hpp>
#include <iostream>
using namespace std;

class Gestor
{
public:
    Gestor();
    ~Gestor();
    void genera12Pedidos();
    void muestraPedidos();
    void buscarPedidos();
    void borraPedidosPila();
    void borraPedidosLista();
    int PedidosEnPila();
    int PedidosEnSalaA();
    int PedidosEnSalaB();
    int PedidosEnSalaC();
    int PedidosEnSalaD();;
    int PedidosEnListaEstandar();
    int PedidosEnListaUrgentes();
    void encolarPedidos();
    void muestraPedidosSalasAyB();
    void muestraPedidosSalasCyD();
    void borraPedidosColas();
    void reiniciar();
    void enlistarPedidos();
    void muestraPedidosEstandar();
    void muestraPedidosUrgentes();

};

#endif // GESTOR_HPP
