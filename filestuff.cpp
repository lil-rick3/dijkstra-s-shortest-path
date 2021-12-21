#include <list>
#include <map>
#include <iostream>
#include <string>
#include <vector>

#include <fstream>
#include "filestuff.hpp"
#include <cassert>
#include <istream>
#include <sstream>

namespace filereading {


    void read_in_file(char** argv, int argc, std::vector<std::string>* nodes, std::vector<Arc>* edges) {

        std::ifstream fp;
        std::istream& input = get_input_handle(argc, fp, argv[1]);
        std::string inp;

        std::string N1;
        std::string N2;
        unsigned int weight;
        std::string n1;
        std::string n2;
        bool isFirst = true;
        Arc tempArc;
        bool n1_unique = false;
        bool n2_unique = false;
        while (std::getline(input, inp)) {
            std::istringstream iss(inp);
            iss >> n1 >> n2 >> weight;
        
        
            
             //scans line by line

                tempArc.sourceID = n1;
                tempArc.targetID = n2;
                tempArc.cost = weight;
                edges->push_back(tempArc);

                if (isFirst) {
                    nodes->push_back(n1);
                    isFirst = false;
                }
                for (unsigned int i = 0; i < nodes->size(); i++) {//runs through to find all unique nodes
                    if (nodes->at(i).compare(n1) == 0) {
                        n1_unique = false;
                        break;

                    }
                    n1_unique = true;
                }
                if (n1_unique) {
                    nodes->push_back(n1);
                }
                for (unsigned int i = 0; i < nodes->size(); i++) {
                    if (nodes->at(i).compare(n2) == 0) {
                        n2_unique = false;
                        break;

                    }
                    n2_unique = true;
                }
                if (n2_unique) {
                    nodes->push_back(n2);
                }



            }
        }
       


    

std::istream& get_input_handle(int ac, std::ifstream& fhandle, const char* fname) {
    if (ac == 4) {
        fhandle.open(fname);
        assert(fhandle.is_open());
        return fhandle;
    }
    else {
        return std::cin;
    }
}
}