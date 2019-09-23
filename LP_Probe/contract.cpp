#include <iostream>	
#include "contract.h"

int contract::platinen = 0;


//Preiskalkulation mit static int -Variable
int contract::getPrice() {
	
	int preis_eins, preis_hundert, preis_tausend;
	
	if (platinen < 100) {
		preis_eins = platinen * m_p1;

		return preis_eins;
	}
	else if (platinen > 100 && platinen < 1000) {
		preis_hundert = platinen * m_p2;

		return preis_hundert;
	}

	else {
		preis_tausend = platinen * m_p3;

		return preis_tausend;
	}	
}