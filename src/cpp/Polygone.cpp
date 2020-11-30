/**
 * \file Polygone.cpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Programme permettant l'implémentation de la classe Polygone
 *
 */

#include <iostream>

using namespace std;

#include "../hpp/Polygone.hpp"


Polygone::Polygone(ulong _couleur, int _x, int _y, std::vector<Point> _tabPoint, uint _rayon)
 : Forme(_couleur,_x,_y), tabPoint(_tabPoint), rayon(_rayon)
{
    for(size_t i=0;i<tabPoint.size();i++)
    {
        tabPoint[i].setXY(rayon*cos((i+1)*((360/tabPoint.size())* PI / 180.0))+getAncre().getX()-rayon*cos(0)+rayon,rayon*sin((i+1)*((360/tabPoint.size())* PI / 180.0))+getAncre().getY()-rayon*sin(0));
    }
    getAncre().setXY(getAncre().getX()+rayon,getAncre().getY()+rayon);
    AncreXPrecedent = getAncre().getX();
	AncreYPrecedent = getAncre().getY();
}

Polygone::Polygone(const Polygone& orig)
 : Forme(orig)
{}

Polygone::Polygone( istream & is)
:Forme(is)
{
	is >> rayon;
    uint nbp;
    is >> nbp;
    uint x, y;
    std::vector<Point> tabP;
    for(uint i=0; i<nbp; i++)
    {
        is >> x >> y;
        Point tempp(x, y);
        tabP.push_back(tempp);
    }
    tabPoint=tabP;
    getAncre().setXY(getAncre().getX()+rayon,getAncre().getY()+rayon);
    AncreXPrecedent = getAncre().getX();
	AncreYPrecedent = getAncre().getY();
}

Polygone::~Polygone()
{
    delete sommetSelect;
}

void Polygone::dessiner(EZWindow &w, bool isActive) const
{
    Forme::dessiner(w, isActive);
    for(size_t i=0;i<tabPoint.size();i++)
    {
        w.drawLine(tabPoint[i].getX(),tabPoint[i].getY(),tabPoint[(i+1)%tabPoint.size()].getX(),tabPoint[(i+1)%tabPoint.size()].getY());
    }
    getAncre().setXY(getAncre().getX()-rayon,getAncre().getY()-rayon);
}

double Polygone::perimetre() const
{ 
    double perimetre=0;
    for(size_t i=0;i<tabPoint.size();i++)
    {
    if(tabPoint[(i+1)%tabPoint.size()].getX()>tabPoint[i].getX() && tabPoint[(i+1)%tabPoint.size()].getY() > tabPoint[i].getY())
        perimetre += sqrt(pow(tabPoint[(i+1)%tabPoint.size()].getX()-tabPoint[i].getX(),2)+pow(tabPoint[(i+1)%tabPoint.size()].getY()-tabPoint[i].getY(),2));
    else if ((tabPoint[(i+1)%tabPoint.size()].getX()>tabPoint[i].getX() && tabPoint[i].getY() > tabPoint[(i+1)%tabPoint.size()].getY()))
        perimetre += sqrt(pow(tabPoint[(i+1)%tabPoint.size()].getX()-tabPoint[i].getX(),2)+pow(tabPoint[i].getY()-tabPoint[(i+1)%tabPoint.size()].getY(),2));
    else if (tabPoint[i].getX()>tabPoint[(i+1)%tabPoint.size()].getX() && tabPoint[(i+1)%tabPoint.size()].getY() > tabPoint[i].getY())
        perimetre += sqrt(pow(tabPoint[i].getX()-tabPoint[(i+1)%tabPoint.size()].getX(),2)+pow(tabPoint[(i+1)%tabPoint.size()].getY()-tabPoint[i].getY(),2));
    else if (tabPoint[i].getX()>tabPoint[(i+1)%tabPoint.size()].getX() && tabPoint[i].getY() > tabPoint[(i+1)%tabPoint.size()].getY())
        perimetre += sqrt(pow(tabPoint[i].getX()-tabPoint[(i+1)%tabPoint.size()].getX(),2)+pow(tabPoint[i].getY()-tabPoint[(i+1)%tabPoint.size()].getY(),2));
    }
    return perimetre;
}

ostream& Polygone::ecrire(ostream& os) const
{
    os << "Polygone " ;
    Forme::ecrire(os);
    os << " " << rayon << " " << tabPoint.size() << " " << endl;
    for(uint i=0; i<tabPoint.size(); i++)
    {
        os << tabPoint[i].getX() << " " << tabPoint[i].getY() << " ";
    }
    os << endl;
    return os;
}

void Polygone::DeplacementForme()
{
    for(size_t i=0;i<tabPoint.size();i++)
    {
        tabPoint[i].setXY(tabPoint[i].getX()+(getAncre().getX()-AncreXPrecedent),tabPoint[i].getY()+(getAncre().getY()-AncreYPrecedent));
    }
    savePoint();
}

void Polygone::signalClicked(int x, int y)
{
    for(size_t i=0;i<tabPoint.size();i++)
    {
        if(tabPoint[i].isOver(x,y))
        {
            setSommetSelect(&tabPoint[i]);
        }
    }
}

void Polygone::setXYSommet(int x, int y)
{
    if(sommetSelect != nullptr)
    {
        sommetSelect->setXY(x,y);
    }
}

bool Polygone::sommetIsSelect() const
{
    if(sommetSelect != nullptr)
        return (sommetSelect != nullptr);
    else
        return (false);
}

bool Polygone::sommetOver(int x, int y) const
{
    bool isOver=false;
    for(size_t i=0;i<tabPoint.size();i++)
    {
        if(tabPoint[i].isOver(x,y))
        {
            isOver=true;
        }
    }
    return isOver;
    
}

void Polygone::savePoint()
{
    AncreXPrecedent = getAncre().getX();
    AncreYPrecedent = getAncre().getY();
}

void Polygone::ajouterPoint()
{
   
    Point tempPoint(0,0);
    try
    {
        tabPoint.push_back(tempPoint);
    }
    catch(std::exception const& e)
    {
        cerr << "Erreur : " << e.what();
    }
    getAncre().setXY(getAncre().getX()+rayon,getAncre().getY()+rayon);
    tabPoint[tabPoint.size()-1].setXY(rayon+getAncre().getX(),getAncre().getY()-rayon);
    AncreXPrecedent = getAncre().getX();
    AncreYPrecedent = getAncre().getY();

}

void Polygone::enleverPoint()
{
    if(tabPoint.size() > 0)
    {
        tabPoint.pop_back();
        getAncre().setXY(getAncre().getX()+rayon,getAncre().getY()+rayon);
        AncreXPrecedent = getAncre().getX();
	    AncreYPrecedent = getAncre().getY();
    }
}
