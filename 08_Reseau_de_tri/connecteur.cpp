#include "connecteur.h"

int Connecteur::pos() const
{
    return m_pos;
}

int Connecteur::dep() const
{
    return m_dep;
}

int Connecteur::arr() const
{
    return m_arr;
}

Connecteur::Connecteur(int position, int depart, int arrivee):
    m_pos(position), m_dep(depart), m_arr(arrivee)
{

}

QString Connecteur::toString()
{
    QString res;
    res.sprintf("Position %d : connecteur du fil %d au fil %d.", m_pos, m_dep, m_arr);
    return res;
}
