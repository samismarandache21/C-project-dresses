#pragma once

#include "Domain.h"
#include <vector>
#include <fstream>

using std::vector;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::to_string;


class Repo
{
private:
	string path;
	vector<Domain> all;

	void read();
	void write();
public:
	Repo(string);
	~Repo();

	vector<Domain>& Rochii();

	void change_status(int);

};

