/**
 * \file Point.cpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Déclaration de la classe Point
 *
 */

#include "../hpp/Point.hpp"


Point::Point (uint _x,uint _y)
:x(_x),y(_y)
{}

Point::Point(const Point& orig)
:Point(orig.x,orig.y)  // /!\ Délégation de construction ! ;)
{}

Point::Point(istream &is)
:x(0),y(0)
{
    is >> x >> y >> taille; //>> taille;
}

Point::~Point()
{}

void Point::dessiner(EZWindow& w, bool isActive=false) const
{
    if (isActive)
       w.setColor(ez_red);
    else
       w.setColor(ez_black);
    w.setThick(1);
    w.drawRectangle(x-taille, y-taille, x+taille, y+taille);
}

ostream& operator<<(ostream& os, const Point& p)
{
    os << p.x <<" " <<  p.y << " " << p.taille <<endl;
    return os;
}

istream& operator>>(istream& is, Point p)
{
    is >> p.x >> p.y >> p.taille; // >> p.taille;
    return is;
}


