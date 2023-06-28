#include "raiz.h"

 QuadArbol::QuadArbol(Point topL, Point botR){
    root = new Quad(topL,botR);
    puntos = 0;
    nodos = 0;
 }

 
 void QuadArbol::preorder(Quad *root){
   
   if (root != nullptr) {
        cout << root->totalPoints() << " ";
        nodos++;
        preorder(root->topLeftTree);
        preorder(root->topRightTree);
        preorder(root->botLeftTree);
        preorder(root->botRightTree);
    }
    
 }
 Quad* QuadArbol::getraiz(){
   return root;
 }
 int QuadArbol::totalPoints(){
   return puntos;
 }
 int QuadArbol::totalNodes(){
   return nodos;
 }
int QuadArbol::countRegion(Point p, int d){
   return root->countRegion(p,d);
}
long long QuadArbol::AggregateRegion(Point p, int d){
   return root->AggregateRegion(p,d);
}
void QuadArbol::insert(Point p, int data){
   root->insert(p,data);
}
Node* QuadArbol::search(Point p){
   return root->search(p);
}