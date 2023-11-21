#ifndef GESTOR_HPP
#define GESTOR_HPP
#include <Pedido.hpp>
#include <Pila.hpp>
#include <Cola.hpp>
#include <Lista.hpp>
#include <Arbol.hpp>
#include <random>
#include <algorithm>

class Gestor
{
public:
    Gestor();
    ~Gestor();
    
    void genera12Pedidos();
    void muestraPedidos();
    int PedidosEnPila();
    void borraPedidosPila();
    
    void encolarPedidos();
    void muestraPedidosSalasAyB();
    void muestraPedidosSalasCyD();
    int PedidosEnSalaA();
    int PedidosEnSalaB();
    int PedidosEnSalaC();
    int PedidosEnSalaD();;
    void borraPedidosColas();
    
    void enlistarPedidos();
    void borraPedidosLista();
    int PedidosEnListaEstandar();
    int PedidosEnListaUrgentes();
    void muestraPedidosUrgentes();
    void muestraPedidosEstandar();
    void buscarPedidos();
    
    void reiniciar();
    
    void dibujarArbol();
    void mostrarEstandarArbol();
    void mostrarUrgentesArbol();
    void mostrarInorder();
    void mostrar4Pedidos();
    void cantidadImpares();
    void mostrarNodoHoja();
    void eliminarPedido();
    int PedidosEnArbol();
    
private:
    int arrayIdUrgente[49];
    int arrayIdEstandar[49];
    int arrayNumeroSeguimientoUrgente[499];
    int arrayNumeroSeguimientoEstandar[499];
    Pila pila;
    Cola colaA;
    Cola colaB;
    Cola colaC;
    Cola colaD;
    Lista listaUrgente;
    Lista listaEstandar;
    Pedido ficticio;
    Arbol abb;
    int contadorIdUrgente;
    int contadorIdEstandar;
    int contadorNumeroSeguimientoUrgente;
    int contadorNumeroSeguimientoEstandar;
    
    void generarArrayIdUrgente();
    void generarArrayIdEstandar();
    void generarArrayNumeroSeguimientoUrgente();
    void generarArrayNumeroSeguimientoEstandar();
};

#endif // GESTOR_HPP
