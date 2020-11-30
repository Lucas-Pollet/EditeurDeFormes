/**
 * \file Point.hpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Déclaration de la classe Point
 *
 */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

#include "../hpp/ez-draw++.hpp"

using namespace std;

typedef unsigned int uint;
typedef unsigned long int ulong;

/*! \class Point
   * \brief Classe permettant de créer un point
   *
   */
class Point {
private :
       uint x,y;        /*!< uint coordonnées x et y*/
       uint taille = 3; /*!< uint taille de sélection du point*/
public :
       /*! \fn Point(uint x, uint y)
         * \brief Constructeur de Point à deux paramètres
         * 
         * \param x Coordonnée x
         * \param y Coordonnée y
         */
       Point(uint x, uint y);
       /*! \fn Point(const Point& orig)
         * \brief Constructeur de copie de Point
         * 
         * \param orig Le point que l'on copie
         */
       Point(const Point& orig);
       /*! \fn Point(istream& is)
         * \brief Constructeur sur flux de Point
         * 
         * \param is Input
         */
       Point(istream& is);
       /*! \fn ~Point()
         * \brief Destructeur
         *
         */
       ~Point();
       /*! \fn inline uint getX() const
         * \brief Getteur pour la coordonée x
         * 
         * \return x
         */
       inline uint getX() const{ return x; }
       /*! \fn inline uint getY() const 
         * \brief Getteur pour la coordonée y
         * 
         * \return y
         */
       inline uint getY() const { return y; }
       /*! \fn inline void setTaille(uint _taille)
         * \brief Setter de taille
         * 
         * \param _taille la nouvelle taille
         */
       inline void setTaille(uint _taille){taille=_taille;}
       /*! \fn inline uint getTaille() const 
         * \brief Getter de taille
         * 
         * \return uint de taille
         */
       inline uint getTaille() const {return taille;}
       /*! \fn inline void setXY(uint _x, uint _y)
         * \brief Setter pour les coordonnées
         * 
         * \param _x Le nouveau x
         * \param _y Le nouveau y
         */
       inline void setXY(uint _x, uint _y) {x=_x; y=_y;}
       /*! \fn inline bool isOver(uint _x, uint _y) const
         * \brief Fonction qui indique si les coordonnées indiquées correspondent à celles du point
         * 
         * \param _x Coordonnée x
         * \param _y Coordonnée y
         * \return bool
         */
       inline bool isOver(uint _x, uint _y) const { return ( x-taille <= _x && _x <= x+taille )&& (y-taille <= _y && _y <= y+taille ); }
       /*! \fn void dessiner(EZWindow& w, bool isActive) const
         * \brief Fonction permettant de dessiner un point
         * 
         * \param w La fenêtre où l'on dessine
         * \param isActive Indique si le point est sélectionné ou non
         */
       void dessiner(EZWindow& w, bool isActive) const;
       /*! \fn friend ostream& operator<<(ostream& os, const Point& p)
         * \brief Fonction permettant de d'écrire un point
         * 
         * \param os Output
	  * \param p Le point à écrire
         * \return ostream& contenant le flux
         */
       friend ostream& operator<<(ostream& os, const Point& p);
       /*! \fn friend istream& operator>>(istream& is, Point p)
         * \brief Fonction permettant de lire un point
         * 
         * \param is Input
	  * \param p Le point à lire
         * \return istream& contenant le flux
         */
       friend istream& operator>>(istream& is, Point p);
};

#endif
