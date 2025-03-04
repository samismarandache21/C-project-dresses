#include "Service.h"
#include <algorithm>

using std::sort;
Service::Service(Repo& r): repo{r} {}

Service::~Service() {}

const vector<Domain>& Service::Rochii() {
	return repo.Rochii();
}

vector<Domain> Service::Rochii_pret() {
	vector<Domain> res = Rochii();
	sort(res.begin(), res.end(), [](Domain& d1, Domain& d2) { return d1.get_pret() > d2.get_pret(); });
	return res;
}

vector<Domain> Service::Rochii_marime() {
	vector<Domain> res = Rochii();
	sort(res.begin(), res.end(), [](Domain& d1, Domain& d2) { return d1.get_marime() > d2.get_marime(); });
	return res;
}
void Service::change_status(int code) {
	repo.change_status(code);
}