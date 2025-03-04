#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlayout.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qmessagebox.h>
#include "Service.h";

class GUI : public QWidget
{
private:
	Service& service;

	QListWidget* view = new QListWidget();
	vector<QPushButton*> buttons;
	void initComps();
	void initConnects();

	void loadView(const vector<Domain>&);
public:
	GUI(Service&);
	~GUI();
};

