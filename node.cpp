#include "node.hpp"


node::node(std::string theName) {//sets the name of the string
	name = theName;
}

bool node::isPlayable() {
	if (!(isInfinite) && (!isVisited)) {
		return true;
	}
	else {
		return false;
	}
}