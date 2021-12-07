#include "reseautri.h"
#include "connecteur.h"
#include <QList>
#include "qstd.h"

using namespace qstd;

int ReseauTri::getPosMin()
{
    int posMin = m_connecteurs[0]->pos();

    for(int i = 1; i< m_connecteurs.size(); i++)
    {
        if(m_connecteurs[i]->pos()<posMin)
        {
            posMin = m_connecteurs[i]->pos();
        }
    }
    return posMin;
}

int ReseauTri::getPosMax()
{
    int posMax = m_connecteurs[0]->pos();

    for(int i = 1; i< m_connecteurs.size(); i++)
    {
        if(m_connecteurs[i]->pos()>posMax)
        {
            posMax = m_connecteurs[i]->pos();
        }
    }
    return posMax;
}

ReseauTri::ReseauTri(int fil):
    m_nbFils(fil)
{

}

QString ReseauTri::toString()
{
    QString res;
    res.sprintf("");
    return res;
}

void ReseauTri::ajouteConnecteur(int position, int fil_depart, int fil_arrivee)
{
    // add new connecteur into m_connecteurs QList
    m_connecteurs.append(new Connecteur(position, fil_depart, fil_arrivee));
}

QList<int> ReseauTri::injecte(QList<int> list)
{
    int temp;

    cout<<"Before sort : \n";
    for (int i = 0; i < m_connecteurs.size(); i++){
        cout<<m_connecteurs[i]->toString()<<endl;
    }

    std::sort(m_connecteurs.begin(), m_connecteurs.end(), Connecteur::positionInfA);

    cout<<"\nAfter sort : \n";
    // display all position with their start - end connection
    for (int i = 0; i < m_connecteurs.size(); i++){
        cout<<m_connecteurs[i]->toString()<<endl;
    }

    cout<<"\nTableau initial : ";
    for (int i = 0; i < list.size(); i++){
        cout<<list[i];
    }

    cout<<"\nMin pos : "<<getPosMin();
    cout<<"\nMax pos : "<<getPosMax()<<endl;

    // while condition to browse the entire list : 5 << 1 << 3 << 2
    int i = 0;

    while(i < m_connecteurs.size())
    //for(int i = getPosMin(); i<=getPosMax(); i++)
    {
        cout<<"\nProposition "<<m_connecteurs[i]->pos()<<" : "<<endl;
        cout<<" i : "<<i<<endl;

        // if the value at the beginning of the connection is lower than the value at the end of the connection
        if(list[m_connecteurs[i]->dep()]>list[m_connecteurs[i]->arr()]){
            cout<<"     depart  : "<<list[m_connecteurs[i]->dep()]<<" (temp)"<<endl;
            cout<<"     arrivee : "<<list[m_connecteurs[i]->arr()]<<endl;
            temp = list[m_connecteurs[i]->dep()];
            list[m_connecteurs[i]->dep()] = list[m_connecteurs[i]->arr()];
            list[m_connecteurs[i]->arr()] = temp;
        }
        cout<<"Tableau intermediaire : ";
        for (int i = 0; i < list.size(); i++){
            cout<<list[i];
        }
        cout<<endl;
        i++;
    }

    cout<<"\nTableau final : ";
    for (int i = 0; i < list.size(); i++){
        cout<<list[i];
    }
    cout<<endl;
    return list;
}
