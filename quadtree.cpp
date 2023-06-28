// Original code: https://www.geeksforgeeks.org/quad-tree/ (May 24, 2023)

#include "quadtree.h"
using namespace std;

void Quad::insert(Point p, int data) 
{
	Node* node = new Node(p,data);
        if (node == NULL)
		return;

	// Current quad cannot contain it
	if (!inBoundary(node->pos))
		return;

	// We are at a quad of unit area
	// We cannot subdivide this quad further
	if (abs(topLeft.x - botRight.x) <= 1
		&& abs(topLeft.y - botRight.y) <= 1) {
	  if (n == NULL){
		n = node;
		ocupado = true;

	  }
			

	    return;
	}

	if ((topLeft.x + botRight.x) / 2 > node->pos.x) {
		// Indicates topLeftTree
		if ((topLeft.y + botRight.y) / 2 > node->pos.y) {
		  if (topLeftTree == NULL) 
				topLeftTree = new Quad(
					Point(topLeft.x, topLeft.y),
					Point((topLeft.x + botRight.x) / 2,
						(topLeft.y + botRight.y) / 2));

		  topLeftTree->insert(p,data);
		}

		// Indicates botLeftTree
		else {
		  if (botLeftTree == NULL) 
				botLeftTree = new Quad(
					Point(topLeft.x,
						(topLeft.y + botRight.y) / 2),
					Point((topLeft.x + botRight.x) / 2,
					      botRight.y));

		  botLeftTree->insert(p,data);
		}
	}
	else {
		// Indicates topRightTree
		if ((topLeft.y + botRight.y) / 2 > node->pos.y) {
		  if (topRightTree == NULL) 
				topRightTree = new Quad(
					Point((topLeft.x + botRight.x) / 2,
						topLeft.y),
					Point(botRight.x,
						(topLeft.y + botRight.y) / 2));

		  topRightTree->insert(p,data);
		}

		// Indicates botRightTree
		else {
		  if (botRightTree == NULL)
				botRightTree = new Quad(
					Point((topLeft.x + botRight.x) / 2,
						(topLeft.y + botRight.y) / 2),
					Point(botRight.x, botRight.y));
		  
		  botRightTree->insert(p,data);
		}
	}
}

// Find a node in a quadtree
Node* Quad::search(Point p)
{
	// Current quad cannot contain it
	if (!inBoundary(p))
		return NULL;

	// We are at a quad of unit length
	// We cannot subdivide this quad further
	if (n != NULL)
		return n;

	if ((topLeft.x + botRight.x) / 2 > p.x) {
		// Indicates topLeftTree
		if ((topLeft.y + botRight.y) / 2 > p.y) {
			if (topLeftTree == NULL)
				return NULL;
			return topLeftTree->search(p);
		}

		// Indicates botLeftTree
		else {
			if (botLeftTree == NULL)
				return NULL;
			return botLeftTree->search(p);
		}
	}
	else {
		// Indicates topRightTree
		if ((topLeft.y + botRight.y) / 2 > p.y) {
			if (topRightTree == NULL)
				return NULL;
			return topRightTree->search(p);
		}

		// Indicates botRightTree
		else {
			if (botRightTree == NULL)
				return NULL;
			return botRightTree->search(p);
		}
	}
};

// Check if current quadtree contains the point
bool Quad::inBoundary(Point p)
{
	return (p.x >= topLeft.x && p.x <= botRight.x
			&& p.y >= topLeft.y && p.y <= botRight.y);
}

void Quad::_printQuadTree(Quad* t, int indent)
{
  for(int i=0; i < indent; i++)
    std::cout << "--";

  if(t != NULL && t->n != NULL)
    std::cout << " " << t->n->data << std::endl;
  else if(t == NULL)
    std::cout << " NULL" << std::endl;
  else {
    std::cout << " X " << std::endl;
  
    _printQuadTree(t->topLeftTree, indent+1);
    _printQuadTree(t->topRightTree, indent+1);
    _printQuadTree(t->botLeftTree, indent+1);
    _printQuadTree(t->botRightTree, indent+1);
  }
}

void Quad::printQuadTree()
{
  _printQuadTree(this->topLeftTree, 1);
  _printQuadTree(this->topRightTree, 1);
  _printQuadTree(this->botLeftTree, 1);
  _printQuadTree(this->botRightTree, 1);
};

int Quad::totalPoints(){
    int count= 0;
    _countPoints(this, count);
    return count;
}
void Quad::_countPoints(Quad* quad, int& count){
    if (quad == NULL) return;
    if (quad->n != NULL) {
        count++;
        return;
    }
    _countPoints(quad->topLeftTree, count);
    _countPoints(quad->topRightTree, count);
    _countPoints(quad->botLeftTree, count);
    _countPoints(quad->botRightTree, count);
}

int Quad::totalNodes(){
    int count= 0;
    _countNodes(this, count);
    return count;
}
void Quad::_countNodes(Quad* quad, int& count){ //solo cuenta nodos negros (revisar insert)
    if (quad == NULL) return;
	count++;
    _countNodes(quad->topLeftTree, count);
    _countNodes(quad->topRightTree, count);
    _countNodes(quad->botLeftTree, count);
    _countNodes(quad->botRightTree, count);
	
}
vector<Point> Quad::list(){
	Point p(0,0);
	vector<Point> puntos;
	puntos.push_back(p);
	return puntos;
}

int Quad::countRegion(Point p, int d){
    int minX = p.x - d;
    int maxX = p.x + d;
    int minY = p.y - d;
    int maxY = p.y + d;
    int count = 0;
    _countRegion(this, minX, maxX, minY, maxY, count);

    return count;
}

void Quad::_countRegion(Quad* quad, int minX, int maxX, int minY, int maxY, int& count){
    if (quad == NULL)
        return;
    if (quad->n != NULL) {
        if (quad->n->pos.x >= minX && quad->n->pos.x <= maxX && quad->n->pos.y >= minY && quad->n->pos.y <= maxY) {
            count++;
        }
        return;
    }
    _countRegion(quad->topLeftTree, minX, maxX, minY, maxY, count);
    _countRegion(quad->topRightTree, minX, maxX, minY, maxY, count);
    _countRegion(quad->botLeftTree, minX, maxX, minY, maxY, count);
    _countRegion(quad->botRightTree, minX, maxX, minY, maxY, count);
}

int Quad::AggregateRegion(Point p, int d){
    int minX = p.x - d;
    int maxX = p.x + d;
    int minY = p.y - d;
    int maxY = p.y + d;
    int count = 0;
    _AggregateRegion(this, minX, maxX, minY, maxY, count);

    return count;
}

void Quad::_AggregateRegion(Quad* quad, int minX, int maxX, int minY, int maxY, int& count){
    if (quad == NULL)
        return;
    if (quad->n != NULL) {
        if (quad->n->pos.x >= minX && quad->n->pos.x <= maxX && quad->n->pos.y >= minY && quad->n->pos.y <= maxY) {
            count=count+quad->n->data;
        }
        return;
    }
    _AggregateRegion(quad->topLeftTree, minX, maxX, minY, maxY, count);
    _AggregateRegion(quad->topRightTree, minX, maxX, minY, maxY, count);
    _AggregateRegion(quad->botLeftTree, minX, maxX, minY, maxY, count);
    _AggregateRegion(quad->botRightTree, minX, maxX, minY, maxY, count);
}