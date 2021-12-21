#include <string>
#include <iostream>
#include "filestuff.hpp"
#include <vector>
#include "makemap.hpp"

int main(int argc, char** argv) {


    std::vector<std::string>myNodes;
    std::vector<Arc> myEdges;
    
    std::string beginning;
    std::string end;
    

    if (argc == 4) {
        beginning = *(argv + 2);
        end = *(argv + 3);
        

    }
    else {
        
        beginning = *(argv + 1);
        end = *(argv + 2);
    }

    filereading::read_in_file(argv,argc, &myNodes, &myEdges);//takes in input and compiles it into arguments



    Arc tempArc;
    /* (unsigned int i = 0; i < myEdges.size(); i++) {
        tempArc = myEdges.at(i);
        std::cout << tempArc.sourceID << " " << tempArc.targetID << " " << tempArc.cost << std::endl;
    }
    for (unsigned int i = 0; i < myNodes.size(); i++) {
        std::cout << i << ": " << myNodes.at(i) << std::endl;
    }
    */
    map test(myNodes, myEdges, beginning, end);

   // test.printMap();

    bool outcome = test.findPath();


    //test.testMap();
    test.printPath(outcome);

}