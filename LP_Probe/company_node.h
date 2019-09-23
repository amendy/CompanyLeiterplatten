#ifndef COMPANY_NODE_H
#define COMPANY_NODE_H

#include "Node.h"


//Abgeleitete Node-Klasse zum bearbeiten der Nodes
class company_node : public Node
{
public:

	company_node(std::string id)
		: Node(id) {}

//private:
	//für evt. Membervariablen
};



#endif
