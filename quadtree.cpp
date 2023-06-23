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
	  if (n == NULL)
			n = node;

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
	return cantPoints;
}
int Quad::totalNodes(){
	return cantNodes;
}
vector<Point> Quad::list(){
	Point p(0,0);
	vector<Point> puntos;
	puntos.push_back(p);
	return puntos;
}
int Quad::countRegion(Point p, int d){
	return 0;
}
int Quad::AggregateRegion(Point p, int d){
	return 0;
}