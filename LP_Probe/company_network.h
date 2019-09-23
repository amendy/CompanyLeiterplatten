#ifndef COMPANY_NETWORK_H
#define COMPANY_NETWORK_H

#include "Graph.h"
#include <iostream>

using namespace std;

class company_network : public Graph
{
public:

	company_network();

	void create_contract(Node& rSrc, Node& rDst, int p1, int p2, int p3);

	//Node* getNodeById(const std::string& rNodeId);

	Node* getNodeList();

};


#endif