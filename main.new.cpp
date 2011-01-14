#include <QtGui/QApplication>
#include "GOCXMLEditor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GOCXMLEditor w;
    w.show();

    return a.exec();
}
