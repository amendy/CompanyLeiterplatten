#include <limits>
#include <string>
#include <iostream>
#include <deque>

#include "gui.h"
#include "contract.h"
#include "company_node.h"

void gui::showUserMenu()
{
	std::cout
		<< "\nBitte w\204hlen Sie eine der folgenden Optionen \n"
		<< "1 - Liste der Firmen mit bisherigem Umsatz\n"
		<< "2 - Preisauskunft\n"
		<< "3 - Programm verlassen\n"
		<< std::endl;
}


//Abfrage der Usermenu-Eingabe
int gui::getUserChoice(int min, int max)
{
	int user_input = 0;

	do {
		std::cout << "Ihre Eingabe: ";
		std::cin >> user_input;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "\n\n" << std::endl;

		if (user_input < min || user_input > max) {
			std::cout << "Falsche eingabe!" << std::endl;
		}

	} while (user_input < min || user_input > max);

	return user_input;
}


//Hier wird die Anzahl abgefragt und in contract (Unterklasse Edge) gespeichert, via static-Variable
void gui::getAnzahl() {

	int anzahl;

	do{
	std::cout << "Bitte geben Sie die Anzahl ein: " << std::endl;
	std::cin >> anzahl;

	if (anzahl < 1 ) {
		std::cout << "Die Mindestmenge betr\204gt 1!" << std::endl;
	}

	} while (anzahl < 1);

	contract::platinen = anzahl;

}


//Dykstra + Auflistung der Firmen
void gui::company_choice()
{
	getAnzahl();

	std::deque<Edge*> path;

	Node* pSrcNode = m_connection.findNode("SysEng");
	Node* pDstNode = m_connection.findNode("HWTesting");

	do {

		std::cout << "\n---------------------------------------\n" << std::endl;

		m_choice.findShortestPathDijkstra(path, *pSrcNode, *pDstNode);

		//Fehler, wenn Route nicht vorhanden ist
		if (path.empty()) {
			std::cout << "Kein Preisvorschlag vorhanden\n\n";
		}

	} while (path.empty());

	Umsatz u;

	int endpreis = 0;
	int gesamtUmsatz = 0;

	for (std::deque<Edge*>::iterator it = path.begin(); it != path.end(); it++)
	{
		contract* con = dynamic_cast<contract*>(*it);
		std::cout << "Auflistung: " << con->toString() << " | " << con->getPrice() << " Euro" << std::endl;

		endpreis += con->getPrice();


		//Hier kommt man an die Node von einer Edge: Edge-Objekt->getSrc/DstNode()
		u.m_contract = &con->getDstNode();
		u.m_price = con->getPrice();
		m_umsatz.push_back(u);
	}
	std::cout << std::endl;

	std::cout << "Der billigste Gesamtpreis betr\204gt " << endpreis << " Euro" << std::endl;

	std::cout << "\n---------------------------------------\n" << std::endl;
}

//Hier kommt man an die Node////////////////////////////////////////////////
void gui::getName() {

	Node* Node = NULL;

	Node = m_name.findNode("Frankfurter Tor");

	if (Node != NULL) {
		//nur Node liefert Speicheradresse, Node -> den Namen (string)
		std::cout << "Vorhanden! Station: " << Node->getID() << std::endl;
	}


}



void gui::showList() {

	m_list.getNodeList();

}

//////////////////////////////////////////////////////////////////////////
void gui::showUmsatzList()
{
	std::cout << "\n--------------------------------------------------------------" << std::endl;
	
	if (m_umsatz.empty()) {
		std::cout << "Es wurde noch keine Buchung gespeichert!" << std::endl;
	}

	for (std::list<Umsatz>::iterator it = m_umsatz.begin(); it != m_umsatz.end(); it++)
	{

		if (it->m_contract != NULL)
		{
			std::cout << "Firma: " << it->m_contract->getID() << std::endl;
			std::cout << "Umsatz: " << it->m_price << " Euro" << std::endl;

			std::cout << "\n--------------------------------------------------------------" << std::endl;
		}

		else throw "Firmenliste ist leer!";
	}
}




