#ifndef NODE_STUFF
#define NODE_STUFF


#include "filestuff.hpp"
#include <string>



class node {

public:

	node(std::string);
	unsigned int cost = 0;//cost is infinite, but overflow errors aren't fun
	bool isInfinite = true;
	bool isVisited = false;//checks it the node has been finished
	bool isPlayable();//checks if the node can be examined
	//i.e. there is a cost there, and it isn't visited

	std::string name;
	//vectors of everything that is linked
	//std::vector<node*> inNodes;
	//std::vector<unsigned int> inCost;
	//nodes coming in these are parallel vectors, I'm too lazy to find a better solution
	std::vector<node*> outNodes;
	std::vector<unsigned int> outCost;
	//nodes going out
	node* parent;//path to the lowest cost node

};


#endif