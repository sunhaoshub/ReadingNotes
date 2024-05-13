#include "mouseselectionrectwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MouseSelectionRectWidget w;
    w.show();

    return a.exec();
}
