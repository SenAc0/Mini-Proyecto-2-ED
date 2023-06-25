#include "raiz.h"
int main(){
    
   QuadArbol plano(Point(0, 0), Point(8, 8));
    plano.insert(Point(0, 0), 5);
    plano.insert(Point(0, 1), 4);
    plano.insert(Point(1, 0), 2);
    plano.insert(Point(1, 1), 1);
    plano.insert(Point(2, 1), 1);
    plano.insert(Point(5, 1), 3);
    plano.insert(Point(6, 2), 10);
    plano.insert(Point(7, 7), 8);
    plano.insert(Point(7, 7), 8);


    //Preorder para recorrer
    plano.preorder(plano.getraiz());
    cout <<endl;
    
    cout << "Cantidad de nodos: "<<plano.totalNodes() << endl; //ejemplo en canvas
    cout <<endl;





    cout << "Contenido en la coordenada (5,1): ";
    Node * p = plano.search(Point(5, 1));
    if(p != NULL) cout << p->data << endl;
    else cout << "No existe el punto." << endl;
    // Contenido en la coordenada (5,1): 3

    cout << "Contenido en la coordenada (1,5): ";
    p = plano.search(Point(1, 5));
    if(p != NULL) cout << p->data << endl;
    else cout << "No existe el punto." << endl;
    // Contenido en la coordenada (1,5): No existe el punto.
   

    cout << "Cantidad de puntos a una distancia 2 de las coordenadas (4,2): "<<plano.countRegion(Point(4,2), 2) << endl; //ejemplo en canvas
    cout << "Poblacion estimada a una distancia 2 de las coordenadas (4,2): "<< plano.AggregateRegion(Point(4,2), 2) << endl; //ejemplo en canvas

    cout << "Cantidad de puntos a una distancia 2 de las coordenadas (3,2): "<<plano.countRegion(Point(3,2), 2) << endl; //ejemplo en canvas
    cout << "Poblacion estimada a una distancia 2 de las coordenadas (3,2): "<< plano.AggregateRegion(Point(3,2), 2) << endl; //ejemplo en canvas
    

    return 0;
}