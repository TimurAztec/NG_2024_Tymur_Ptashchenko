#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << "Tymur" << std::endl << "Ptashchenko" << std::endl;

    return a.exec();
}
