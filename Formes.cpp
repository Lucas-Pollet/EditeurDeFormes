/**
 * \file Formes.cpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Déclaration de la classe Formes
 *
 */
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;

#include "ez-draw++.hpp"

#include "Formes.hpp"

Formes::Formes(unsigned int taille)
:maxformes(taille),nbformes(0),formes(nullptr)
{
    formes = new Forme*[taille];
}

Formes::~Formes()
{
	for(uint i=0;i<nbformes;i++)
		delete formes[i];
	delete [] formes;
}

void Formes::setForme(Forme *f, uint i)
{
    if(i<nbformes)
        formes[i]=f;
    else
        throw runtime_error("Le nombre de formes est trop petit");
    
}

void Formes::ajouter(Forme *f)
{
    if(nbformes>=maxformes)
        cout << "Impossible d'ajouter une forme, le nombre maximum de formes est atteint" << endl;
    else
        formes[nbformes++]=f;
}

void Formes::supprimer(Forme *f)
{
    uint y=0;
    bool trouve=false;
    for (uint i=0; i<nbformes; i++) //cherche quel forme correspond dans la liste
    {
        if (formes[i]==f)
        {
            y=i;
            trouve=true;
        }
    }
    if (trouve)
    {
        Forme ** temp = new Forme*[maxformes];
        uint j=0;
        for (uint i=0; i<nbformes; i++)
        {
            if (i!=y)
                temp[j++]=formes[i];
        }
        formes[y]->~Forme();
        delete [] formes;
        formes=temp;
        nbformes--;
    }
}

// Rappel : « a->f() » est la même chose que « (*a).f() ».

void Formes::dessiner(EZWindow& w) const
{
    if(estAfficher)
    {
        for(uint i=0; i<nbformes; ++i)
            formes[i]->dessiner(w); // ou de manière équivalente : (*formes[i]).dessiner(w);
    }
}

Forme* Formes::isOver(uint _x,uint _y)
{
    for (uint i=0; i<nbformes; ++i)
        if( formes[i]->isOver(_x, _y))
            return formes[i];
    return nullptr;
}

/* Rappel :
a->operateur<<(os) // Faux
operator<<(os,*a); // Juste et compliqué
os << *a // Juste et simple
*/

ostream& operator<<(ostream& os, const Formes& formes)
{
    for(uint i=0; i<formes.nbformes;++i)
		os << *(formes.formes[i]);
	return os;
}

void Formes::sauver(ostream& os) const
{
    os << nbformes << endl;
	os << *this << endl;
}

void Formes::charger(istream& is)
{
    uint nbf;
    is >>  nbf;
    for(uint i=0; i<nbf; i++)
		ajouter(Forme::charger(is));
}
