/**
 * \file Calque.cpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Implémentation de la classe Calque
 *
 */

#include <iostream>
using namespace std;

#include "Calque.hpp"

Calque::Calque(unsigned int taille)
:maxele(taille),nbele(0),selectionne(0), calques(nullptr)
{
    calques = new Formes*[taille];
    for(unsigned int i=0; i<taille; i++)
        calques[i]=nullptr;
}

Calque::~Calque()
{
    delete [] calques;
}

Formes* Calque::getCalques(uint i) const
{
    if(i<nbele) 
        return calques[i];
    else 
        throw runtime_error("Ce calque n'existe pas !");
}

void Calque::dessiner(EZWindow& w) const
{
    for(uint i=0; i<nbele; i++)
    {
        calques[i]->dessiner(w);
    }
}

void Calque::afficher() const
{
    cout << "--------------------------Calques--------------------------" << endl;
    for(uint i=0;i<nbele;i++)
    {
        cout << "|| Calque " << i+1;
        if(calques[i]->getEstAfficher())
            cout << " : Afficher     ";
        else
            cout << " : Non afficher ";
        if(i==selectionne)
            cout << "(Actuel) ";
        else
            cout << "         ";
        if(calques[i]->getNbformes()==0)
            cout << "  (vide)             ||" << endl;
        else
            cout << "  (Nb forme(s) : " << calques[i]->getNbformes() << " ) ||" << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
}

void Calque::intervertir(uint i, uint j)
{
    if (i<nbele && j<nbele && i!=j)
    {
        Formes * f=calques[i];
        calques[i]=calques[j];
        calques[j]=f;
    }
    else if (j==i)
        cout << "On ne peut pas intervertir un calque avec lui même !";
    else if (i>=nbele)
        cout << "Le calque " << i << " n'existe pas !" << endl;
    else
        cout << "Le calque " << j << " n'existe pas !" << endl;
}

void Calque::ajouter(Formes * f)
{
    if(nbele>=maxele)
        cout << "Le nombre maximum de calque a déjà était atteint !" << endl;
    else
        calques[nbele++]=f;
}

void Calque::supprimer(uint k)
{
    if(k>nbele-1)
        cout << "Ce calque n'existe pas !" << endl;
    else if(nbele==1)
    {
        for(int i=calques[k]->getNbformes();i>0;i--)
          calques[k]->supprimer(calques[k]->getForme(i-1)); 
    }
    else if(nbele>1)
    {
        uint j=0;
        Formes **temp = new Formes*[maxele];
        for (uint i=0; i<nbele; i++)
        {
            if(i!=k)
                temp[j++]=calques[i];
        }
        calques[k]->~Formes();
        delete [] calques;
        calques=temp;
        nbele--;
    }
}

void Calque::fusionner(uint i, uint j)
{
    if (i<nbele && j<nbele && i!=j)
    {
        Forme * f=nullptr;
        for(uint k=calques[j]->getNbformes(); k > 0; k--)
        {
            calques[i]->ajouter(calques[j]->getForme(k-1));
            calques[j]->setForme(f, k-1);
        }
        supprimer(j);
    }
    else if (j==i)
        cout << "On ne peut pas fusionner un calque avec lui même !";
    else if (i>=nbele)
        cout << "Le calque " << i << " n'existe pas !" << endl;
    else
        cout << "Le calque " << j << " n'existe pas !" << endl;
    
}

void Calque::afficherOuDesafficher(uint i)
{
    if(i<nbele)
        calques[i]->setEstAfficher(!calques[i]->getEstAfficher());
}

void Calque::sauver(ostream& os) const
{
    os << nbele << endl;
    for(uint i=0; i<nbele; i++)
    {
        os << "Calque " << i << endl;
        calques[i]->sauver(os);
    }
}

void Calque::charger(istream& is)
{
    uint j;
    is >> j; // Nombre de calques
    string mot;
    for(uint i=0; i<j; i++)
    {
	    is >> mot;
        if(mot=="Calque")
        {
            is >> selectionne;
            if(selectionne!=0)
            {
                ajouter();
            }
            calques[selectionne]->charger(is);
        }
        
    }
    selectionne=0;
}