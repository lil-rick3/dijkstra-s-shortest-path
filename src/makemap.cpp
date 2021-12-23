#include "filestuff.hpp"
#include "makemap.hpp"
#include "node.hpp"
#include <string>
#include <iostream>

map::map(std::vector<std::string>nodeList, std::vector < Arc> edgeList,
	std::string startString, std::string endString) {



	nameNodes = nodeList;
	for (unsigned int i = 0; i < nameNodes.size(); i++) {//gets the nodes setup
		all_nodes.push_back(node(nameNodes.at(i)));
	}//sets the nodes with names
	begin = startString;
	beginLocation = findNode(begin);

	end = endString;
	endLocation = findNode(end);

	int sourceLoc;

	int destinationLoc;
	
	node* goingOut;
	unsigned int pathCost;

	for (unsigned int i = 0; i < edgeList.size(); i++) {
		//takes in the arcs vector and puts it all into the map
		sourceLoc = findNode(edgeList.at(i).sourceID);
		destinationLoc = findNode(edgeList.at(i).targetID);
		pathCost = edgeList.at(i).cost;



		
		goingOut = &all_nodes.at(destinationLoc);

		all_nodes.at(sourceLoc).outNodes.push_back(goingOut);
		all_nodes.at(sourceLoc).outCost.push_back(pathCost);

		//all_nodes.at(destinationLoc).inNodes.push_back(comingIn);
		//all_nodes.at(destinationLoc).inCost.push_back(pathCost);
	}


}

void map::printMap() {//for testing purposes

	for (unsigned int i = 0; i < all_nodes.size(); i++) {
		std::cout << "node: " << i << " " << all_nodes.at(i).name << std::endl;
		std::cout << "outnodes:" << std::endl;
		for (unsigned int j = 0; j < all_nodes.at(i).outNodes.size(); j++) {
			std::cout << all_nodes.at(i).outNodes.at(j)->name << " "
				<< all_nodes.at(i).outCost.at(j) << std::endl;
		}
		

	}

	std::cout << "start: " << begin << " " << beginLocation << "end: " << end << " " << endLocation << std::endl;

}

int map::findNode(std::string nodeString) {

	for (unsigned int i = 0; i < nameNodes.size(); i++) {
		if (nodeString.compare(nameNodes.at(i)) == 0) {
			return i;
		}
	}
	return -1;//error if the string isn't found
}

void map::setStart() {
	all_nodes.at(beginLocation).isInfinite = false;
	all_nodes.at(beginLocation).parent = &all_nodes.at(beginLocation);//sets the start parent to null, must check for this at end
}

void map::testMap() {
	for (unsigned int i = 0; i < all_nodes.size(); i++) {
		if (!(all_nodes.at(i).isInfinite)) {
			std::cout << "Node: " << all_nodes.at(i).name << std::endl;
			std::cout << "Parent: " << all_nodes.at(i).parent->name << std::endl;
			std::cout << "Cost: " << all_nodes.at(i).cost << std::endl;
		}
	}
}



bool map::findPath() {
	unsigned int lowestCost;
	
	int lowestPlayableLocation;//current node
	bool needInitialization = true;//doing a min loop
	unsigned int counter = 0;
	setStart();//initializes the first node
	while(true) {
		for (unsigned int i = 0; i < all_nodes.size(); i++) {
			if (all_nodes.at(i).isPlayable()) {
				if (needInitialization) {
					lowestCost = all_nodes.at(i).cost;
					lowestPlayableLocation = i;
					needInitialization = false;
				}
				else {
					if (all_nodes.at(i).cost < lowestCost) {
						lowestCost = all_nodes.at(i).cost;
						lowestPlayableLocation = i;
					}
				}
			}
		}
		if (needInitialization) {//there are no more potential nodes and there is no path
			return false;
		}
		needInitialization = true;//resets this for next evaluation
		if (lowestPlayableLocation == endLocation) {//if the current node is the end node, then it is finished
			//std::cout<<"end node : "<< all_nodes.at(endLocation).name<<"    found"<<std::endl;
			return true;
		}
		node* current = &all_nodes.at(lowestPlayableLocation);
		unsigned int potentialCost;

		for (unsigned int i = 0; i < current->outNodes.size(); i++) {//look at all outpaths from node
			potentialCost = current->outCost.at(i) + current->cost;
			std::string test = current->outNodes.at(i)->name;
			
			if (current->outNodes.at(i)->isInfinite) {//checks if there is an infinite distance
				
				current->outNodes.at(i)->cost = potentialCost;//if there is then this is the first edge of the node
				current->outNodes.at(i)->isInfinite = false;
				current->outNodes.at(i)->parent = current;


			}
			else {//compare the cost to the potential cost if the distance is not infinite
				if (current->outNodes.at(i)->cost > potentialCost) {
					current->outNodes.at(i)->cost = potentialCost;
					current->outNodes.at(i)->parent = current;
				}
			}

		}
		//std::cout << "iteration: \t" << counter << "chosen Node: " << current->name << std::endl;
		current->isVisited = true;
		
		//this->testMap();
		counter++;
	}

}
void map::printPath(bool searchOutcome) {
	node* tempNode;
	std::string printString;
	std::string flippedString;
	if (begin.compare(end) == 0){
		std::cout << 0 << ": " << begin;
		return;
	}
	if (searchOutcome) {
		std::cout << all_nodes.at(endLocation).cost << ": ";

		printString.append(all_nodes.at(endLocation).name);

		tempNode = all_nodes.at(endLocation).parent;
		while (tempNode->name.compare(tempNode->parent->name) != 0) {
			printString.append(" ");
			printString.append(tempNode->name);
			tempNode = tempNode->parent;
		}
		printString.append(" ");
		printString.append(tempNode->name);



		for (int i = printString.length() - 1; i >= 0; i--) {
			flippedString.push_back(printString[i]);
		}


		std::cout << flippedString;
	}
	else {
		std::cout << "No path exists from " << begin << " to " << end;
	}
}

