/**
 * \file Ellipse.cpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Implémentation de la classe Ellipse
 *
 */

#ifndef pi 
#define pi 3.14159265358979323846
#include <iostream>
#include <cmath>

using namespace std;

#include "../hpp/Ellipse.hpp"

Ellipse::Ellipse(ulong couleur_, ulong x_, ulong y_, ulong demilargeur_, ulong demihauteur_)
	:Forme(couleur_,x_,y_),demilargeur(demilargeur_),demihauteur(demihauteur_)
{}
Ellipse::Ellipse(Ellipse& orig)
	:Ellipse( orig.getCouleur(), orig.getAncre().getX(), orig.getAncre().getY(), orig.demilargeur, orig.demihauteur)
{}
Ellipse::Ellipse(istream& is)
: Forme(is), demilargeur(0),demihauteur(0)
{
	is >> demilargeur >> demihauteur;
}
Ellipse::~Ellipse()
{}
double Ellipse::perimetre() const
{
	return (pi*(3*((demilargeur+decalDroite+decalGauche
	)+(demihauteur+decalHaut+decalBas))-sqrt((3*(demilargeur+decalDroite+decalGauche)+demihauteur)*((demilargeur+decalDroite+decalGauche)+3*(demihauteur+decalHaut+decalBas)))));
}
void Ellipse::dessiner(EZWindow& w, bool isActive) const
{
	Forme::dessiner(w,isActive);
	if(Forme::getEstRemplie())
    {
    w.fillCircle(getAncre().getX()-decalGauche-decalDroite,getAncre().getY()-decalHaut-decalBas,
                 getAncre().getX()+(demilargeur*2)+decalDroite+decalGauche,getAncre().getY()+(demihauteur*2)+decalBas+decalHaut);
    }
    else
    {
    w.drawCircle(getAncre().getX()-decalGauche-decalDroite,getAncre().getY()-decalHaut-decalBas,
                 getAncre().getX()+(demilargeur*2)+decalDroite+decalGauche,getAncre().getY()+(demihauteur*2)+decalBas+decalHaut);
    }
}
ostream& Ellipse::ecrire(ostream& os) const
{
	os << "Ellipse" << " ";
	Forme::ecrire(os);
	os << " " << demilargeur << " " << demihauteur << endl;
	return os;
}
#endif
