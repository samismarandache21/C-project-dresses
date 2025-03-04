#include "Repo.h"

Repo::Repo(string file) : path{ file }, all{vector<Domain>()} {
	read();
}

Repo::~Repo() {
}
vector<Domain>& Repo::Rochii() {
	
	return all;
}

void Repo::read() {
	ifstream in(path);
	string line = "";
	int cod = 0;
	int pret = 0;
	bool available = false;
	string denumire = "", marime = "";
	while (getline(in, line)) {
		string cuvant = "";
		int curent_field = 0;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == ',' || i == line.size() - 1) {
				if (i == line.size() - 1)
					cuvant += line[i];

				if (curent_field == 0) {
					cod = stoi(cuvant);
				}
				else if (curent_field == 1) { 
					denumire = cuvant;
				}
				else if (curent_field == 2) {
					marime = cuvant;
				}
				else if (curent_field == 3) {
					pret = stoi(cuvant);
				}
				else if(curent_field == 4){
					if (cuvant == "true")
						available = true;
					else
						available = false;
				}

				cuvant = "";
				curent_field++;
			}
			else
				cuvant += line[i];
		}
		all.push_back(Domain(cod, denumire,marime,pret,available));
	}
	in.close();
}

void Repo::write() {
	ofstream out(path);
	string res = "";
	for (auto rochie : Rochii()) {
		res += rochie.to_str() + '\n';
	}
	out << res;
	out.close();
}

void Repo::change_status(int code) {
	for (auto& rochie : Rochii()) {
		if (rochie.get_cod() == code) {
			rochie.set_disponibilitate();
			break;
		}
	}
	write();
}
