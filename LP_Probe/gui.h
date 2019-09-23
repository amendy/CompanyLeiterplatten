#ifndef GUI_H
#define GUI_H

#include "company_network.h"
#include "contract.h"
#include "umsatz.h"

class gui
{

public:

	gui(company_network& choice, company_network& connection, company_network& list, company_network& name ) : m_choice(choice), m_connection(connection),
		m_list(list), m_name(name) {}

	void showUserMenu();

	int getUserChoice(int min, int max);

	void getAnzahl();

	void company_choice();

	void getName();

	void showList();

	void showUmsatzList();

private:
	
	int m_p;

	company_network& m_choice;
	company_network& m_connection;
	company_network& m_list;
	company_network& m_name;

	std::list<Umsatz> m_umsatz;
};
#endif