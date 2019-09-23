#include <iostream>
#include <string>

#include "contract.h"
#include "Graph.h"
#include "gui.h"
#include "company_node.h"
#include "company_network.h"



int main()
{

	company_network choice, connection, list, name;

	
	gui g(choice, connection, list, name);

	int auswahl = 0;

	do {

		g.showUserMenu();
		auswahl = g.getUserChoice(1, 4);

		switch (auswahl) {
		case 1:
			g.showUmsatzList();
			break;

		case 2:
			g.company_choice();
			break;

		}

	} while (auswahl != 3);

}