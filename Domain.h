#pragma once
#include <string>
using std::string;
using std::to_string;

class Domain
{
private:
	int cod;
	string denumire;
	string marime;
	int pret;
	bool available;
public:
	Domain(int, string, string, int, bool);
	~Domain();

	int get_cod();
	string get_denumire();
	string get_marime();
	int get_pret();
	bool get_disponibilitate();
	void set_disponibilitate();

	string to_str();
	
};

