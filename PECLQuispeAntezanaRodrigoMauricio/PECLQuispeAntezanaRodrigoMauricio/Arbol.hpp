#ifndef ARBOL_HPP
#define ARBOL_HPP
#include "NodoArbol.hpp"
#include <vector>
using namespace std;

class Arbol
{
public:
    Arbol();
    void insertar(Pedido val);
    void pintar();
    void dibujar();
    int contarImparesEnABB();
    void mostrarEstandarABB();
    void mostrarUrgentesABB();
    void eliminarArbol();
    int contarPedidos();
    ~Arbol();
private:
    pnodoAbb raiz;
    pnodoAbb insertar(pnodoAbb, Pedido);
    int contarImparesEnNodo(pnodoAbb nodo);
    int contarPedidos(pnodoAbb nodo);
    void eliminarArbol(pnodoAbb nodo);
    void pintar(pnodoAbb);
    int altura(pnodoAbb);
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int minPos,
                     char linkChar);
};

#endif // ARBOL_HPP
