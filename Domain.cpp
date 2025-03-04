#include "Domain.h"
Domain::Domain(int code, string name, string size, int price, bool availabilty) {
	cod = code;
	denumire = name;
	marime = size;
	pret = price;
	available = availabilty;
}
Domain::~Domain() {}

int Domain::get_cod() {
	return cod;
}

string Domain::get_denumire() {
	return denumire;
}

string Domain::get_marime() {
	return marime;
}

int Domain::get_pret() {
	return pret;
}

bool Domain::get_disponibilitate() {
	return available;
}

string Domain::to_str() {
	string aux;
	if (available == true)
		aux = "true";
	else
		aux = "false";

	return to_string(cod) + "," + denumire + "," + marime + "," + to_string(pret) + "," + aux;


}

void Domain::set_disponibilitate() {
	available = false;
}