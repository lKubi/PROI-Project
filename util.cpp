/*
	Le cadeas e numeros por teclado
*/

# include <iostream>

# include "util.h"

using namespace std;

void lerCadea (char mensaxe[ ], char cad []) {

	cout << mensaxe;
	cin.getline (cad, MAXCAD);
}

int lerEnteiro (char mensaxe []) {

	char cad [MAXCAD];

	lerCadea (mensaxe, cad);
	return atoi (cad);
}
