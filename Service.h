#pragma once

#include "Repo.h"
class Service
{
private:
	Repo& repo;
public:
	Service(Repo&);
	~Service();

	const vector<Domain>& Rochii();
	vector<Domain> Rochii_pret();
	vector<Domain> Rochii_marime();

	void change_status(int);
};

