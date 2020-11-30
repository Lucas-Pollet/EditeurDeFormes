/**
 * \file Forme.cpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Déclaration de la classe Forme
 *
 */
#include <iostream>

using namespace std;


#include "../hpp/Forme.hpp"

Forme::Forme(ulong _couleur, uint _x, uint _y)
 : couleur(_couleur),ancre(_x,_y),selected(true) //peutetre pas selected
{}

Forme::Forme(const Forme& orig)
 : Forme(orig.couleur,orig.ancre.getX(),orig.ancre.getY())  
{}

Forme::Forme (istream& is)
:couleur(0),ancre(0,0)
{
    //Première solution simple à comprendre mais utilisant des variables locales :
    uint x, y, taille;
    is >> couleur >> x >> y >> taille >> epaisseur >> estRemplie >> animation >> decalDroite >> decalGauche >> decalHaut >> decalBas;
    ancre.setXY(x,y);
   //autres solution, plus élégante : 
    //is >> couleur >> ancre ;
}

Forme::~Forme()
{}

void Forme::dessiner(EZWindow &w, bool active) const
{
    ancre.dessiner(w, active);
    w.setThick(epaisseur);
    w.setColor(couleur);
    if(getAnimation()=='r') //Animation de l'ac-en-ciel
    {
        w.setColor(w.getRGB(EZDraw::random(255), EZDraw::random(255), EZDraw::random(255)));
    }
    else if(getAnimation()=='p') //Animation de pulsation
    {
        int aleatoire = EZDraw::random(5);
        w.setThick(epaisseur+aleatoire);
    }
}

// fonction non membre
ostream& operator<<(ostream& os, Forme& f)
{
    f.ecrire(os);
    return os;
}

ostream& Forme::ecrire(ostream& os) const
{
    os << couleur << " " << ancre << " " << epaisseur << " " << estRemplie << " " << animation << " " << decalDroite << " " << decalGauche << " " << decalHaut << " " << decalBas;
    return os;
}

#include "../hpp/Rectangle.hpp"
#include "../hpp/Cercle.hpp"
#include "../hpp/Carre.hpp"
#include "../hpp/Ellipse.hpp"
#include "../hpp/Polygone.hpp"
#include "../hpp/Image.hpp"

Forme* Forme::charger(istream& is)
{
	string mot;
	is>>mot;

	if(mot=="Rectangle")
		return new Rectangle(is);
	else if(mot=="Ellipse")
		return new Ellipse(is);
    else if(mot=="Cercle")
		return new Cercle(is);
    else if(mot=="Carre")
		return new Carre(is);
    else if(mot=="Polygone")
		return new Polygone(is);
    else if(mot=="Image")
        return new Image(is);    
    else
        throw runtime_error("Type de forme inconnue rencontré lors du chargement !");
}
