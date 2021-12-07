#include <QCoreApplication>
#include "qstd.h"
#include "reseautri.h"
using namespace qstd;

int main()
{
    ReseauTri rt(4);
    rt.toString();
    rt.ajouteConnecteur(3,2,3);
    rt.ajouteConnecteur(1,0,2);
    //rt.ajouteConnecteur(2,1,3);
    rt.ajouteConnecteur(3,0,1);
    //rt.ajouteConnecteur(3,2,3);
    rt.ajouteConnecteur(4,1,2);
    rt.ajouteConnecteur(2,1,3);

    cout<<"===== Algorythme de reseau de tri ===== \n"<<endl;
    QList<int> entree;
    entree << 5 << 1 << 3 << 2;
    QList<int> sortie = rt.injecte(entree);
}

