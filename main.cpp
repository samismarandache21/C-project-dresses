#include "GUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repo r{ "Rochii.txt" };
    Service serv{ r };
    GUI gui{ serv };
    gui.show();

    return a.exec();
}
