#include "GUI.h"

GUI::GUI(Service& serv) : service{ serv }, buttons{ vector<QPushButton*>() } {
	initComps();
	initConnects();
}

GUI::~GUI() {}

void GUI::initComps() {
    auto main_ly = new QVBoxLayout();
    setLayout(main_ly);

    tableView = new QTableWidget(this); // Create the table widget
    tableView->setColumnCount(4); // Set the number of columns
    QStringList headers = { "Cod", "Denumire", "Marime", "Pret", "Disponibilitate" };
    tableView->setHorizontalHeaderLabels(headers);
    main_ly->addWidget(tableView);

    loadView(service.Rochii()); // Load data into the table

    auto btn_ly = new QHBoxLayout();
    string text[4] = { "Inchiriere", "Nesortata", "Sortare dupa pret", "Sortare dupa marime" };
    for (int i = 0; i < 4; i++) {
        buttons.push_back(new QPushButton{ QString::fromStdString(text[i]) });
        btn_ly->addWidget(buttons[i]);
    }
    main_ly->addLayout(btn_ly);
}

void GUI::loadView(const vector<Domain>& Rochii) {
    tableView->setRowCount(0); // Clear the table

    for (const auto& rochie : Rochii) {
        int row = tableView->rowCount();
        tableView->insertRow(row);

        tableView->setItem(row, 0, new QTableWidgetItem(QString::number(rochie.get_cod())));
        tableView->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(rochie.get_denumire())));
        tableView->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(rochie.get_marime()))); void GUI::initConnects() {
            QObject::connect(buttons[0], &QPushButton::clicked, [&]() {
                auto selectedItems = tableView->selectedItems();
                if (selectedItems.size() != tableView->columnCount()) {
                    QMessageBox::warning(nullptr, "Warning", "Selectati o rochie");
                }
                else {
                    int row = selectedItems[0]->row();
                    QTableWidgetItem* availabilityItem = tableView->item(row, 4);
                    if (availabilityItem->text() == "Indisponibil") {
                        QMessageBox::warning(nullptr, "Warning", "Rochia este deja inchiriata");
                    }
                    else {
                        int id = tableView->item(row, 0)->text().toInt();
                        for (int col = 0; col < tableView->columnCount(); ++col) {
                            tableView->item(row, col)->setBackground(QBrush(Qt::red));
                        }
                        availabilityItem->setText("Indisponibil");
                        service.change_status(id);
                        tableView->clearSelection();
                        tableView->setFocus();
                    }
                }
                });

            QObject::connect(buttons[1], &QPushButton::clicked, [&]() {
                loadView(service.Rochii());
                });

            QObject::connect(buttons[2], &QPushButton::clicked, [&]() {
                loadView(service.Rochii_pret());
                });

            QObject::connect(buttons[3], &QPushButton::clicked, [&]() {
                loadView(service.Rochii_marime());
                });
        }

        tableView->setItem(row, 3, new QTableWidgetItem(QString::number(rochie.get_pret())));
        QTableWidgetItem* availabilityItem = new QTableWidgetItem(rochie.get_disponibilitate() ? "Disponibil" : "Indisponibil");
        tableView->setItem(row, 4, availabilityItem);

        // Set background color based on availability
        QColor bgColor = rochie.get_disponibilitate() ? Qt::green : Qt::red;
        for (int col = 0; col < tableView->columnCount(); ++col) {
            tableView->item(row, col)->setBackground(QBrush(bgColor));
        }
    }
}






