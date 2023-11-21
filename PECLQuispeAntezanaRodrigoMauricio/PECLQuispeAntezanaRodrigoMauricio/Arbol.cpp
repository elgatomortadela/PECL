#include "Arbol.hpp"

Arbol::Arbol() { raiz = nullptr; }
void Arbol::insertar(Pedido val) { raiz = insertar(raiz, val); }
pnodoAbb Arbol::insertar(pnodoAbb nodo, Pedido val)
{
    if(!nodo)
        return new NodoArbol(val);
    if(val.getNumeroSeguimiento() <= nodo->dato.getNumeroSeguimiento())
        nodo->izq = insertar(nodo->izq, val);
    else
        nodo->der = insertar(nodo->der, val);
    return nodo;
}
void Arbol::pintar()
{
    pintar(raiz);
    cout << '\n';
}
void Arbol::pintar(pnodoAbb nodo)
{
    if(!nodo)
        return;
    pintar(nodo->izq);
    cout << "Es urgente: " << nodo->dato.esUrgente() << " DNI: " << nodo->dato.getDni() << " ID: " << nodo->dato.getId() << " Numero de seguimiento: " << nodo->dato.getNumeroSeguimiento() << endl;
    pintar(nodo->der);
}
int Arbol::altura(pnodoAbb nodo)
{
    if(!nodo)
        return 0;
    return 1 + max(altura(nodo->izq), altura(nodo->der));
}

void Arbol::dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int p,
                        char linkChar)
{
    if(!nodo)
        return;

    int h = output.size();
    string SP = " ";

    if(p < 0) {
        string extra(-p, ' ');
        for(string& s : output)
            if(!s.empty())
                s = extra + s;
        for(string& s : linkAbove)
            if(!s.empty())
                s = extra + s;
    }
    if(nivel < h - 1)
        p = max(p, (int)output[nivel + 1].size());
    if(nivel > 0)
        p = max(p, (int)output[nivel - 1].size());
    p = max(p, (int)output[nivel].size());

    if(nodo->izq) {
        int numeroQueQuieroImprimirEnElArbol =
            nodo->izq->dato.getNumeroSeguimiento();
        string izqdato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
        dibujarNodo(output, linkAbove, nodo->izq, nivel + 1, p - izqdato.size(), 'L');
        p = max(p, (int)output[nivel + 1].size());
    }

    int space = p - output[nivel].size();
    if(space > 0)
        output[nivel] += string(space, ' ');
    int numeroQueQuieroImprimirEnElArbol =
        nodo->dato.getNumeroSeguimiento();
    string nododato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
    output[nivel] += nododato;

    space = p + SP.size() - linkAbove[nivel].size();
    if(space > 0)
        linkAbove[nivel] += string(space, ' ');
    linkAbove[nivel] += linkChar;

    if(nodo->der)
        dibujarNodo(output, linkAbove, nodo->der, nivel + 1, output[nivel].size(), 'R');
}
void Arbol::dibujar()
{
    int h = altura(raiz);
    vector<string> output(h), linkAbove(h);
    dibujarNodo(output, linkAbove, raiz, 0, 5, ' ');

    for(int i = 1; i < h; i++) {
        for(int j = 0; j < linkAbove[i].size(); j++) {
            if(linkAbove[i][j] != ' ') {
                int size = output[i - 1].size();
                if(size < j + 1)
                    output[i - 1] += string(j + 1 - size, ' ');
                int jj = j;
                if(linkAbove[i][j] == 'L') {
                    while(output[i - 1][jj] == ' ')
                        jj++;
                    for(int k = j + 1; k < jj - 1; k++)
                        output[i - 1][k] = '_';
                } else if(linkAbove[i][j] == 'R') {
                    while(output[i - 1][jj] == ' ')
                        jj--;
                    for(int k = j - 1; k > jj + 1; k--)
                        output[i - 1][k] = '_';
                }
                linkAbove[i][j] = '|';
            }
        }
    }

    cout << '\n' << '\n';
    for(int i = 0; i < h; i++) {
        if(i)
            cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
    cout << '\n' << '\n';
}
int Arbol::contarPedidos()
{
    return contarPedidos(raiz);
}
int Arbol::contarPedidos(pnodoAbb nodo)
{
    if (!nodo)
        return 0;
    return 1 + contarPedidos(nodo->izq) + contarPedidos(nodo->der);
}
int Arbol::contarImparesEnNodo(pnodoAbb nodo)
{
    if (!nodo) {
        return 0;
    }
    int imparesEnNodoActual = (nodo->dato.getNumeroSeguimiento() % 2 == 1) ? 1 : 0;
    return imparesEnNodoActual + contarImparesEnNodo(nodo->izq) + contarImparesEnNodo(nodo->der);
}
int Arbol::contarImparesEnABB() 
{
    return contarImparesEnNodo(raiz);
}
void Arbol::mostrarEstandarABB() {
    pintar(raiz->izq);
}
void Arbol::mostrarUrgentesABB() {
    pintar(raiz->der);
}
void Arbol::eliminarArbol()
{
    eliminarArbol(raiz);
    raiz = nullptr;
}
void Arbol::eliminarArbol(pnodoAbb nodo)
{
    if(nodo) {
        eliminarArbol(nodo->izq);
        eliminarArbol(nodo->der);
        delete nodo;
    }
}

Arbol::~Arbol() {}

