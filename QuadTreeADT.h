#pragma once
#include <bits/stdc++.h>
using namespace std;
#include "Structs.h"
class Quadtree{
public:
    virtual int totalPoints()=0;    // Retorna la cantidad de puntos almacenados en el QuadTree
    virtual int totalNodes()=0;     //Retorna la cantidad de nodos, tanto blancos como negros, en el QuadTree
    virtual void insert(Point p, int data)=0;   //Inserta un nuevo punto p en el QuadTree, asociando a dicho punto la información disponible en data (ej. la población de una ciudad con coordenadas p).
    virtual vector<Node*> list()=0;     //Retorna un contenedor con todos los puntos en el QuadTree. Por cada punto retorna coordenadas y su valor data(usar preorder o otros para mostrar)
    virtual int countRegion(Point p, int d)=0;  //Retorna la cantidad de puntos en una región del plano, tomando como centro el punto p y una distancia d.
    virtual long long AggregateRegion(Point p, int d)=0;  //Retorna la población estimada dentro de una región del plano, tomando como centro el punto p y una distancia d.
};
