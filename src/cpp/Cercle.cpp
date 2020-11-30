/**
 * \file Cercle.hpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Déclaration de la classe cercle
 *
 */

#ifndef pi 
#define pi 3.14159265358979323846
#include <iostream>
#include <cmath>

using namespace std;

#include "../hpp/Cercle.hpp"

Cercle::Cercle(ulong couleur_, ulong x_, ulong y_, ulong rayon_)
	:Forme(couleur_,x_,y_),rayon(rayon_)
{}
Cercle::Cercle(Cercle& orig)
	:Cercle( orig.getCouleur(), orig.getAncre().getX(), orig.getAncre().getY(), orig.rayon)
{}
Cercle::Cercle(istream& is)
: Forme(is), rayon(0)
{
	is >> rayon;
}
Cercle::~Cercle()
{}
double Cercle::perimetre() const
{
	int decal = decalDroite+decalBas+decalHaut+decalGauche;
	return (2 * pi*(rayon+decal));
}
void Cercle::dessiner(EZWindow& w, bool isActive) const
{
	Forme::dessiner(w,isActive);
	int decal = decalDroite+decalBas+decalHaut+decalGauche;
	if(Forme::getEstRemplie())
    {
    w.fillCircle(getAncre().getX()-decal,getAncre().getY()-decal,
                 getAncre().getX()+(rayon*2)+decal,getAncre().getY()+(rayon*2)+decal);
    }
    else
    {
    w.drawCircle(getAncre().getX()-decal,getAncre().getY()-decal,
                 getAncre().getX()+(rayon*2)+decal,getAncre().getY()+(rayon*2)+decal);
    }
}
ostream& Cercle::ecrire(ostream& os) const
{
	os << "Cercle" << " ";
	Forme::ecrire(os);
	os << " " << rayon << endl;
	return os;
}
#endif
