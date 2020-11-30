/**
 * \file Carre.cpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Déclaration de la classe Carre
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

#include "Carre.hpp"

Carre::Carre(ulong couleur_, uint x_, uint y_, uint cote_)
: Forme(couleur_, x_, y_), cote(cote_)
{}

Carre::Carre( const Carre & orig )
: Carre ( orig.getCouleur(), orig.getAncre().getX(), orig.getAncre().getY(), orig.cote)
{}

Carre::Carre( istream & is)
: Forme(is), cote(0)
{
    is >> cote;
}

Carre::~Carre()
{}

double Carre::perimetre() const
{ 
    int decal = decalDroite+decalBas+decalHaut+decalGauche;
    return ((cote+decal)*4);
}

ostream& Carre::ecrire(ostream& os) const
{
    os << "Carre" << " ";
    Forme::ecrire(os);
    os << " " << cote << endl;
    return os;
  }

  void Carre::dessiner(EZWindow& w,bool isActive) const
{
    Forme::dessiner(w,isActive);
    int decal = decalDroite+decalBas+decalHaut+decalGauche;
    if(Forme::getEstRemplie())
    {
    w.fillRectangle(getAncre().getX()-decal,getAncre().getY()-decal,
                 getAncre().getX()+cote+decal,getAncre().getY()+cote+decal);
    }
    else
    {
    w.drawRectangle(getAncre().getX()-decal,getAncre().getY()-decal,
                 getAncre().getX()+cote+decal,getAncre().getY()+cote+decal);
    }
}