#pragma once
#include "QuadTreeADT.h"
using namespace std;


class Quad: public Quadtree{

    bool ocupado; //false blanco, true negro
    // Hold details of the boundary of this node
    Point topLeft;
    Point botRight;
    public:
    // Contains details of node
    Node* n;
    
    // Children of this tree
    Quad* topLeftTree;
    Quad* topRightTree;
    Quad* botLeftTree;
    Quad* botRightTree;
    
    
    Quad()
    {
        topLeft = Point(0, 0);
        botRight = Point(0, 0);
        n = NULL;
        topLeftTree = NULL;
        topRightTree = NULL;
        botLeftTree = NULL;
        botRightTree = NULL;
    }
    Quad(Point topL, Point botR)
    {
        n = NULL;
        topLeftTree = NULL;
        topRightTree = NULL;
        botLeftTree = NULL;
        botRightTree = NULL;
        topLeft = topL;
        botRight = botR;
    }
    
    Node* search(Point p);
    bool inBoundary(Point p);
    void _printQuadTree(Quad* t, int indent);
    void printQuadTree();
    void insert(Point p, int data);
    
    int totalPoints();
    void _countPoints(Quad* quad, int& count);
    int totalNodes();
    void _countNodes(Quad* quad, int& count);
    vector<Node*> list();
    void _list(Quad* quad, vector<Node*>& lista);
    int countRegion(Point p, int d);
    void _countRegion(Quad* quad, int minX, int maxX, int minY, int maxY, int& count);
    int AggregateRegion(Point p, int d);
    void _AggregateRegion(Quad* quad, int minX, int maxX, int minY, int maxY, int& count);

};
