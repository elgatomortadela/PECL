#include "Gestor.hpp"

Gestor::Gestor()
{
    this->generarArrayIdUrgente();
    this->generarArrayIdEstandar();
    this->generarArrayNumeroSeguimientoUrgente();
    this->generarArrayNumeroSeguimientoEstandar();
    this->contadorIdUrgente = 0;
    this->contadorIdEstandar = 0;
    this->contadorNumeroSeguimientoUrgente = 0;
    this->contadorNumeroSeguimientoEstandar = 0;
}
void Gestor::generarArrayIdUrgente()
{
    int tamano = 49; 
    for (int i = 0; i < tamano; i++) {
        arrayIdUrgente[i] = i + 51;
    }
    random_device rd;
    mt19937 g(rd());
    shuffle(arrayIdUrgente, arrayIdUrgente + tamano, g);
}
void Gestor::generarArrayIdEstandar()
{
    int tamano = 49; 
    for (int i = 0; i < tamano; i++) {
            arrayIdEstandar[i] = i + 1;
    }
    random_device rd;
    mt19937 g(rd());
    shuffle(arrayIdEstandar, arrayIdEstandar + tamano, g);
}
void Gestor::generarArrayNumeroSeguimientoUrgente()
{
    int tamano2 = 499;
    for (int i = 0; i < tamano2; i++) {
            arrayNumeroSeguimientoUrgente[i] = i + 501;
    }
    random_device rd2;
    mt19937 g2(rd2());
    shuffle(arrayNumeroSeguimientoUrgente, arrayNumeroSeguimientoUrgente + tamano2, g2);
}
void Gestor::generarArrayNumeroSeguimientoEstandar()
{
    int tamano = 499;
    for (int i = 0; i < tamano; i++) {
            arrayNumeroSeguimientoEstandar[i] = i + 1;
    }
    random_device rd3;
    mt19937 g3(rd3());
    shuffle(arrayNumeroSeguimientoEstandar, arrayNumeroSeguimientoEstandar + tamano, g3);
}
void Gestor::genera12Pedidos()
{
    if(pila.getLongitud()+colaB.getLongitud()+colaD.getLongitud()+colaC.getLongitud()+colaA.getLongitud()+listaEstandar.getLongitud()+listaUrgente.getLongitud()+abb.contarPedidos()<48)
        for(int i =0; i< 12; i++) {
            Pedido pedido;
            pila.insertar(pedido);
        }
}
void Gestor::muestraPedidos()
{
    if (pila.getLongitud() > 0) {
        pila.mostrar();
    } 
    else {
        cout<<"Pila vacia." << endl;
    }
    
}
int Gestor::PedidosEnPila()
{
    return pila.getLongitud();
}
void Gestor::borraPedidosPila()
{
    while(pila.getLongitud() >0) {
        pila.extraer();
    }
}
void Gestor::encolarPedidos()
{
    while (pila.getLongitud() >0) {
        if(pila.cima().esUrgente()){
            if(colaC.getLongitud() > colaD.getLongitud() or colaC.getLongitud() == colaD.getLongitud()){
                Pedido p = pila.cima();
                p.setId(arrayIdUrgente[contadorIdUrgente]);
                 colaD.insertar(p);
            }
            else if(colaD.getLongitud() > colaC.getLongitud()){
                Pedido p = pila.cima();
                p.setId(arrayIdUrgente[contadorIdUrgente]);
                colaC.insertar(p);
            }
            contadorIdUrgente = contadorIdUrgente + 1;
        }
        else if(!pila.cima().esUrgente()){
            if(colaA.getLongitud() > colaB.getLongitud() or colaA.getLongitud() == colaB.getLongitud()){
                Pedido p = pila.cima();
                p.setId(arrayIdEstandar[contadorIdEstandar]);
                colaB.insertar(p);
            }
            else if(colaB.getLongitud() > colaA.getLongitud()){
                Pedido p = pila.cima();
                p.setId(arrayIdEstandar[contadorIdEstandar]);
                colaA.insertar(p);
            }
            contadorIdEstandar = contadorIdEstandar + 1;
        }
        pila.extraer();
    }
    
}
void Gestor::muestraPedidosSalasAyB()
{
    if (colaA.getLongitud() > 0) {
        cout<<"Cola A: "<< endl;
        colaA.mostrar();
        cout<<"Cola B: "<< endl;
        colaB.mostrar();
    } 
    else {
        cout<<"Cola vacia." << endl;
    }
}
void Gestor::muestraPedidosSalasCyD()
{
    if (colaC.getLongitud() > 0) {
        cout<<"Cola C: "<<endl;
        colaC.mostrar();
        cout<<"Cola D: "<<endl;
        colaD.mostrar();
    } 
    else {
        cout<<"Cola vacia." << endl;
    }
    
}
int Gestor::PedidosEnSalaA()
{
    return colaA.getLongitud();
}
int Gestor::PedidosEnSalaB()
{
    return colaB.getLongitud();
}
int Gestor::PedidosEnSalaC()
{
    return colaC.getLongitud();
}
int Gestor::PedidosEnSalaD()
{
    return colaD.getLongitud();
}
void Gestor::borraPedidosColas()
{
    while(colaA.getLongitud() >0) {
        colaA.eliminar();
    }
    while(colaB.getLongitud() >0) {
        colaB.eliminar();
    }
    while(colaC.getLongitud() >0) {
        colaC.eliminar();
    }
    while(colaD.getLongitud() >0) {
        colaD.eliminar();
    }
}
void Gestor::enlistarPedidos()
{
    while(colaA.getLongitud() > 0)
    {
        Pedido p = colaA.verPrimero();
        p.setNumeroSeguimiento(arrayNumeroSeguimientoEstandar[contadorNumeroSeguimientoEstandar]);
        listaEstandar.almacenar(p);
        colaA.eliminar();
        contadorNumeroSeguimientoEstandar = contadorNumeroSeguimientoEstandar + 1;
    }

    while(colaB.getLongitud() > 0)
    {
        Pedido p = colaB.verPrimero();
        p.setNumeroSeguimiento(arrayNumeroSeguimientoEstandar[contadorNumeroSeguimientoEstandar]);
        listaEstandar.almacenar(p);
        colaB.eliminar();
        contadorNumeroSeguimientoEstandar = contadorNumeroSeguimientoEstandar + 1;
    }
    while(colaC.getLongitud() > 0)
    {
        Pedido p = colaC.verPrimero();
        p.setNumeroSeguimiento(arrayNumeroSeguimientoUrgente[contadorNumeroSeguimientoUrgente]);
        listaUrgente.almacenar(p);
        colaC.eliminar();
        contadorNumeroSeguimientoUrgente = contadorNumeroSeguimientoUrgente + 1;
    }
    while(colaD.getLongitud() > 0)
    {
        Pedido p = colaD.verPrimero();
        p.setNumeroSeguimiento(arrayNumeroSeguimientoUrgente[contadorNumeroSeguimientoUrgente]);
        listaUrgente.almacenar(p);
        colaD.eliminar();
        contadorNumeroSeguimientoUrgente = contadorNumeroSeguimientoUrgente + 1;

    }

}
void Gestor::borraPedidosLista()
{
    while(listaEstandar.getLongitud() >0) {
        listaEstandar.eliminar();
    }
    while(listaUrgente.getLongitud() >0) {
        listaUrgente.eliminar();
    }
}
int Gestor::PedidosEnListaEstandar()
{
    return listaEstandar.getLongitud();
}
int Gestor::PedidosEnListaUrgentes()
{
    return listaUrgente.getLongitud();
}
void Gestor::muestraPedidosUrgentes()
{
    if (listaUrgente.getLongitud() > 0) {
        cout<<"Lista Urgente: "<< endl;
        listaUrgente.mostrar();
    } 
    else {
        cout<<"No hay pedidos urgentes." << endl;
    }
    
}
void Gestor::muestraPedidosEstandar()
{
    if (listaEstandar.getLongitud() > 0) {
        cout<<"Lista Estandar: "<< endl;
        listaEstandar.mostrar();
    } 
    else {
        cout<<"No hay pedidos estandar." << endl;
    }
    
}
void Gestor::buscarPedidos()
{
    if (listaUrgente.getLongitud() > 0) {
        cout<<"Pedido menos prioritario Urgente: "<<endl;
        listaUrgente.verUltimo().mostrar();
    } 
    else {
        cout<<"No hay pedidos urgentes." << endl;
    }

    if (listaEstandar.getLongitud() > 0) {
        cout<<"Pedido mas prioritario Estandar: "<<endl;
        listaEstandar.verPrimero().mostrar();
    } 
    else {
        cout<<"No hay pedidos estandar." << endl;
    }
}
void Gestor::reiniciar()
{
    borraPedidosColas();
    borraPedidosPila();
    borraPedidosLista();
    abb.eliminarArbol();
    generarArrayIdUrgente();
    generarArrayIdEstandar();
    generarArrayNumeroSeguimientoUrgente();
    generarArrayNumeroSeguimientoEstandar();
    contadorIdEstandar = 0;
    contadorIdUrgente = 0;
    contadorNumeroSeguimientoEstandar = 0;
    contadorNumeroSeguimientoUrgente = 0;
}
void Gestor::dibujarArbol()
{
    ficticio.setId(50);
    ficticio.setNumeroSeguimiento(500);
    abb.insertar(ficticio);
    while (listaEstandar.getLongitud() > 0 )
    {
        abb.insertar(listaEstandar.verPrimero());
        listaEstandar.eliminar();
    }
    while (listaUrgente.getLongitud() > 0)
    {
        abb.insertar(listaUrgente.verPrimero());
        listaUrgente.eliminar();
    }
    cout <<endl << "\nMi Abb: ";
    abb.dibujar();
}
void Gestor::mostrarEstandarArbol()
{
    abb.mostrarEstandarABB();
}
void Gestor::mostrarUrgentesArbol()
{
    abb.mostrarUrgentesABB();
}
void Gestor::cantidadImpares()
{
    cout << "Pedidos con numeros de seguimiento impares en Abb: " << abb.contarImparesEnABB();
}
void Gestor::mostrarInorder()
{
    abb.pintar();
}
int Gestor::PedidosEnArbol()
{
    return abb.contarPedidos();
}

Gestor::~Gestor(){
    
}