/**
 * \file rectangle.cpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Déclaration de la classe Rectangle
 *
 */


#include <iostream>

using namespace std;

#include "../hpp/Rectangle.hpp"

Rectangle::Rectangle(ulong _couleur, uint _x, uint _y, uint _largeur, uint _hauteur)
 : Forme(_couleur,_x,_y), largeur(_largeur), hauteur(_hauteur)
{}

Rectangle::Rectangle(const Rectangle& orig)
 : Forme(orig),largeur(orig.largeur), hauteur(orig.hauteur)
{}

Rectangle::Rectangle( istream & is)
:Forme(is), largeur(0),hauteur(0)
{
    is >> largeur >> hauteur; //ERREUR couleur, x et y pas accessibles ici
}

Rectangle::~Rectangle()
{}

void Rectangle::dessiner(EZWindow &w, bool isActive) const
{
    Forme::dessiner(w, isActive);
    if(Forme::getEstRemplie())
    {
    w.fillRectangle(
        getAncre().getX()-decalGauche,
        getAncre().getY()-decalHaut,
        getAncre().getX()+largeur+decalDroite,
        getAncre().getY()+hauteur+decalBas);
    }
    else
    {
    w.drawRectangle(
        getAncre().getX()-decalGauche,
        getAncre().getY()-decalHaut,
        getAncre().getX()+largeur+decalDroite,
        getAncre().getY()+hauteur+decalBas);
    }
}

double Rectangle::perimetre() const
{ return 2*(largeur+decalDroite+decalGauche)+2*(hauteur+decalHaut+decalBas); }

ostream& Rectangle::ecrire(ostream& os) const
{
    os<<"Rectangle ";
    Forme::ecrire(os);
	os << " " << largeur << " " << hauteur << endl;
    return os;
}
