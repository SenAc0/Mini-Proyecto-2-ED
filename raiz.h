#include "quadtree.h"

class QuadArbol: public Quad{

    Quad *root;
    int puntos;
    int nodos;

    public:

    QuadArbol();
    QuadArbol(Point topL, Point botR);
    int totalPoints();
    int totalNodes();
    void insert(Point p, int data);
    int countRegion(Point p, int d);
    long long AggregateRegion(Point p, int d);
    Node* search(Point p);

  
    void preorder(Quad *root);
    Quad* getraiz();
    
};