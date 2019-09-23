#ifndef CONTRACT_H
#define CONTRACT_H

#include "Edge.h"
#include "Node.h"



class contract : public Edge
{
public:

	static int platinen;

	contract(Node& rSrc, Node& rDst, int p1, int p2, int p3) :
		Edge(rSrc, rDst), m_p1(p1), m_p2(p2), m_p3(p3) {}

	int getPrice();

	virtual double getWeight() { return getPrice(); }


private:

	int m_p1,m_p2,m_p3;
	int m_preis;
};

#endif