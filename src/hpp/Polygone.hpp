/**
 * \file Polygone.hpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Programme permettant l'implémentation de la classe Polygone
 *
 */

#ifndef POLYGONE_HPP
#define POLYGONE_HPP

#include <vector>
#include <cmath>

#include "Forme.hpp"
#include "Point.hpp"
#define PI 3.14159265358979323846264338327950288419716939937510582

/*! \class Polygone
   * \brief classe permettant la création d'un polygone
   *
   */
class Polygone : public Forme {
	
    private :
      std::vector<Point> tabPoint; /*!< std::vector<Point> tableau de points*/
	  Point * sommetSelect;        /*!< Point* Sommet sélectionnée*/
	  uint rayon;                  /*!< uint rayon*/
	  int AncreXPrecedent;         /*!< int sauvegarde de la coordonnée x de l'ancre*/
	  int AncreYPrecedent;         /*!< int sauvegarde de la coordonnée y de l'ancre*/
	  bool AppuiSurSommet=false;   /*!< bool appuye sur le sommet*/
	  bool AppuiSurAncre=false;    /*!< bool appuye sur l'ancre*/

	public:

		/**
 		* \fn Polygone(ulong _couleur, int _x, int _y, std::vector<Point> _tabPoint, uint _rayon)
 		* \brief Fonction de création d'une nouvelle instance d'un polygone.
 		*
 		* \param _couleur ulong qui stock la couleur du polygone.
 		* \param _x int qui stock la coordonnée x de la forme.
 		* \param _y int qui stock la coordonnée y de la forme.
 		* \param _tabPoint std::vector<Point> qui stock la couleur du polygone.
 		* \param _rayon uint qui stock le rayon de la forme
 		*/
		Polygone(ulong _couleur, int _x, int _y, std::vector<Point> _tabPoint, uint _rayon);
		/**
 		* \fn Polygone(const Polygone& orig)
 		* \brief Fonction de copie d'une instance de polygone.
 		*
 		* \param orig const Polygone& qui stock l'instance de polygone à copier.
 		*/
		Polygone(const Polygone& orig);
		/**
 		* \fn Polygone(istream& is)
 		* \brief Constructeur d'une instance de polygone sur le flux istream.
 		*
 		* \param is istream& qui stock un flux.
 		*/
		Polygone(istream& is);
		/**
 		* \fn ~Polygone()
 		* \brief Destructeur d'une instance de polygone.
 		*
 		*/
		~Polygone();

		/**
		* \fn void dessiner(EZWindow &w, bool isActive)
		* \brief Fonction de dessin d'un polygone à l'écran.
		*
		* \param w EZWindow& qui stock l'instance d'une fenetre.
		* \param isActive bool qui stock un booléen.
		*/
		void dessiner(EZWindow &w, bool isActive) const override;
		/**
		* \fn double perimetre() const
		* \brief Fonction de calcul du périmètre d'un polygone.
		*
		* \return double qui stock le perimètre
		*/
		double perimetre() const;
		/**
		* \fn inline size_t getNbPoint() const
		* \brief Fonction qui renvoie le nombre de points
		*
		* \return size_t qui contient le nombre de points
		*/
		inline size_t getNbPoint() const {return tabPoint.size();};
		/**
 		* \fn void DeplacementForme()
 		* \brief Fonction qui déplace une forme par rapport au déplacement de son ancre.
 		*
 		*/
		void DeplacementForme();
		/**
 		* \fn void signalClicked(int x, int y)
 		* \brief Fonction qui, lorsqu'elle est appellé, indique qu'un sommet est sélectionnée si il se trouve aux coordonnées x y.
 		*
 		* \param int qui stock la coordonnée x
 		* \param int qui renvoie la coordonnée y
 		*/
		void signalClicked(int x, int y);
		/**
		* \fn inline void setSommetSelect(Point * ppoint)
		* \brief Fonction qui renvoie si l'utilisateur sélectionne un sommet.
		*
		* \return bool qui renvoie si l'utilisateur sélectionne un sommet.
		*/
		inline void setSommetSelect(Point * ppoint){sommetSelect = ppoint;};
		/**
 		* \fn void setXYSommet(int x, int y)
 		* \brief Fonction qui met à jour le sommet sélectionné.
 		*
 		* \param int qui stock la coordonnée x
 		* \param int qui renvoie la coordonnée y
 		*/
		void setXYSommet(int x, int y);
		/**
 		* \fn bool sommetIsSelect() const
 		* \brief Fonction qui indique si un sommet est sélectionnée ou pas.
 		*
 		* \return bool qui indique si un sommet est sélectionnée ou pas.
 		*/
		bool sommetIsSelect() const;
		/**
 		* \fn bool sommetOver(int x, int y) const
 		* \brief Fonction qui indique si un sommet est sélectionnée ou pas.
 		*
	    * \param int qui stock la coordonnée x
 		* \param int qui renvoie la coordonnée y
		*
 		* \return bool qui indique si un sommet est survollée par les données x et y ou pas.
 		*/
		bool sommetOver(int x, int y) const;
		/**
		* \fn inline bool getAppuiSurSommet() const 
		* \brief Fonction qui renvoie si l'utilisateur appuie sur un sommet.
		*
		* \return bool qui renvoie si l'utilisateur appuie sur un sommet.
		*/
		inline bool getAppuiSurSommet() const {return AppuiSurSommet;};
		/**
		* \fn inline void setAppuiSurSommet(bool _AppuiSurSommet)
		* \brief Fonction qui renvoie si l'utilisateur sélectionne un sommet.
		*
		* \param bool qui stock l'information si sommet est sélectionnée.
		*
		* \return bool qui renvoie si l'utilisateur sélectionne un sommet.
		*/
		inline void setAppuiSurSommet(bool _AppuiSurSommet){AppuiSurSommet=_AppuiSurSommet;};
		/**
		* \fn inline bool getAppuiSurAncre() const 
		* \brief Fonction qui renvoie si l'utilisateur appuie sur une ancre.
		*
		* \return bool qui renvoie si l'utilisateur appuie sur une ancre.
		*/
		inline bool getAppuiSurAncre() const {return AppuiSurAncre;};
		/**
		* \fn inline void setAppuiSurAncre(bool _AppuiSurAncre)
		* \brief Fonction qui renvoie si l'utilisateur sélectionne une ancre.
		*
		* \param bool qui stock l'information si l'ancre est sélectionnée.
		*
		* \return bool qui renvoie si l'utilisateur sélectionne une ancre.
		*/
		inline void setAppuiSurAncre(bool _AppuiSurAncre){AppuiSurAncre=_AppuiSurAncre;};
		/**
		* \fn inline bool AncreIsOnTheMouse(int x, int y) const
		* \brief Fonction qui renvoie si l'utilisateur survole une ancre sélectionnée.
		*
	    * \param int qui stock la coordonnée x
 		* \param int qui renvoie la coordonnée y
		*
		* \return bool qui renvoie si l'utilisateur survole une ancre sélectionnée.
		*/
		inline bool AncreIsOnTheMouse(int x, int y) const {return getAncre().isOver(x,y);};
		/**
	 	* \fn void savePoint()
 		* \brief Sauvergarde les emplacements des points du polygone.
 		*
 		*/
		void savePoint();
		/**
 		* \fn void ajouterPoint()
 		* \brief Ajoute un point au polygone.
 		*
 		*/
		void ajouterPoint();
		/**
 		* \fn void enleverPoint()
 		* \brief Enlève un point au polygone.
 		*
 		*/
		void enleverPoint();
		

	protected:
		/**
 		* \fn Ecris le polygone
 		* \brief Fonction d'écriture d'un polygone à l'écran.
 		*
 		* \param os ostream& qui stock un flux
 		* \return ostream& qui renvoie un flux
 		*/
		virtual ostream& ecrire(ostream& os) const;
};

#endif