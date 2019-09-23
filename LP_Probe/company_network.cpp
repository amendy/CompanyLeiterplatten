#include <iostream>	
#include <fstream>

#include "company_network.h"
#include "company_node.h"
#include "contract.h"

company_network::company_network()
{	
	//Erstellen der Nodes
	Node& sysEng = addNode(new company_node("SysEng"));
	Node& endos = addNode(new company_node("Endos"));
	Node& lightOff = addNode(new company_node("LightOff"));
	Node& lpBes = addNode(new company_node("LPBes"));
	Node& bp = addNode(new company_node("BP"));
	Node& hwTesting = addNode(new company_node("HWTesting"));

	//Erstellen der Edges
	create_contract(sysEng, endos, 200, 80, 20);
	create_contract(sysEng, lightOff, 160, 120, 70);
	create_contract(endos, lpBes, 180, 100, 30);
	create_contract(lightOff, lpBes, 160, 80, 20);
	create_contract(lightOff, bp, 170, 120, 20);
	create_contract(lpBes, hwTesting, 300, 260, 210);
	create_contract(bp, hwTesting, 290, 280, 200);

}


//Funktionsdefinition der Edge-Erstellung
void company_network::create_contract(Node& rSrc, Node& rDst, int p1, int p2, int p3) {

	addEdge(new contract(rSrc, rDst, p1, p2, p3));
}


//Listenausgabe der Nodes
Node* company_network::getNodeList()			
{
	for (std::list<Node*>::iterator it = m_nodes.begin(); it != m_nodes.end(); it++) {
		cout << (*it)->getID() << endl;
	}
	return NULL;
}

