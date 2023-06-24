#include "quadtree.h"

int main(){
    Quad plane2D(Point(0, 0), Point(8, 8));

    Node p1(Point(0, 0), 5);
    Node p2(Point(0, 1), 4);
    Node p3(Point(1, 0), 2);
    Node p4(Point(1, 1), 2);
    Node p5(Point(2, 1), 1);
    Node p6(Point(5, 1), 3);
    Node p7(Point(6, 2), 10);
    Node p8(Point(7, 7), 8);
  
    plane2D.insert(Point(0, 0), 5);
    plane2D.insert(Point(0, 1), 4);
    plane2D.insert(Point(1, 0), 2);
    plane2D.insert(Point(1, 1), 2);
    plane2D.insert(Point(2, 1), 1);
    plane2D.insert(Point(5, 1), 3);
    plane2D.insert(Point(6, 2), 10);
    plane2D.insert(Point(7, 7), 8);
    plane2D.insert(Point(7, 7), 8);
  
    cout << "Contenido en la coordenada (5,1): ";
    Node * p = plane2D.search(Point(5, 1));
    if(p != NULL) cout << p->data << endl;
    else cout << "No existe el punto." << endl;
    // Contenido en la coordenada (5,1): 3

    cout << "Contenido en la coordenada (1,5): ";
    p = plane2D.search(Point(1, 5));
    if(p != NULL) cout << p->data << endl;
    else cout << "No existe el punto." << endl;
    // Contenido en la coordenada (1,5): No existe el punto.
    cout << "Cantidad de puntos a una distancia 2 de las coordenadas (4,2): "<<plane2D.countRegion(Point(4,2), 2) << endl; //ejemplo en canvas
    cout << "Poblacion estimada a una distancia 2 de las coordenadas (4,2): "<< plane2D.AggregateRegion(Point(4,2), 2) << endl; //ejemplo en canvas

    return 0;
}