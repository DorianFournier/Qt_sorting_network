#ifndef CONNECTEUR_H
#define CONNECTEUR_H

#include <QString>

class Connecteur
{
private:
    int m_pos;
    int m_dep;
    int m_arr;

public:
    Connecteur(int position, int depart, int arrivee);
    QString toString();
    int pos() const;
    int dep() const;
    int arr() const;
    static bool positionInfA(const Connecteur  *c1,
                             const Connecteur *c2){
        return c1->pos()<c2->pos();
    }
};

#endif // CONNECTEUR_H
