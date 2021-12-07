#ifndef RESEAUTRI_H
#define RESEAUTRI_H

#include <QString>
#include "connecteur.h"
#include <QList>

class ReseauTri
{
private:
    int m_nbFils = 4;
    QList<Connecteur *> m_connecteurs;
    QList<Connecteur *> getAtPos(int pos);
    int getPosMin();
    int getPosMax();

public:
    ReseauTri(int nfil);
    QString toString();
    void ajouteConnecteur(int position, int fil_depart, int fil_arrivee);
    QList<int> injecte(QList<int> list);
};

#endif // RESEAUTRI_H
