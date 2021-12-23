#include "node.hpp"

#include "filestuff.hpp"
#include <vector>
#include <string>

class map {
public:
	std::vector <node> all_nodes;

	map(std::vector<std::string>, std::vector < Arc>,
		std::string, std::string);//compiles a map

	std::vector<std::string>nameNodes;//can be used to transfer from int to node
	void printMap();

	std::string begin;
	int beginLocation;
	std::string end;
	int endLocation;

	int findNode(std::string);//finds the location of a string
	bool findPath();
	void setStart();//takes the beginning and makes it available to play
	void printPath(bool);
	void testMap();

};

