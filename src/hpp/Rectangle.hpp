/**
 * \file rectangle.hpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Déclaration de la classe Rectangle
 *
 */

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Forme.hpp"

/*! \class Rectangle
   * \brief classe permettant la création d'un rectangle
   *
   */
class Rectangle : public Forme {
	
      private :
        uint largeur; /*!< uint largeur du rectangle*/
        uint hauteur; /*!< uint hauteur du rectangle*/

	public:
		/**
 		* \fn Rectangle(ulong _couleur, uint _x, uint _y, uint _largeur, uint _hauteur)
 		* \brief Fonction de création d'une nouvelle instance d'un rectangle.
 		*
 		* \param _couleur ulong qui stock la couleur du rectangle.
 		* \param _x uint qui stock la coordonnée x de la forme.
 		* \param _y uint qui stock la coordonnée y de la forme.
		* \param _largeur uint qui stock la largeur du rectangle.
		* \param _hauteur uint qui stock la hauteur du rectangle.
 		*/
		Rectangle(ulong _couleur, uint _x, uint _y, uint _largeur, uint _hauteur);
		/**
 		* \fn Rectangle(const Rectangle& orig)
 		* \brief Fonction de création d'une copie de l'instance d'un rectangle.
 		*
 		* \param orig const Rectangle& qui stock l'instance d'un rectangle.
 		*/
		Rectangle(const Rectangle& orig);
		/**
 		* \fn Rectangle(istream& is)
 		* \brief Fonction de création par lecture d'une instance d'un rectangle.
 		*
 		* \param is istream& qui stock un flux.
 		*/
		Rectangle(istream& is);
		/**
 		* \fn ~Rectangle()
 		* \brief Fonction de destruction de l'instance d'un rectangle.
 		*/
		~Rectangle();

		/**
 		* \fn inline uint getLargeur() const 
 		* \brief Fonction qui renvoie la largeur
 		*
 		* \return uint qui contient la largeur à renvoyée.
 		*/
		inline uint getLargeur() const { return largeur; }
		/**
 		* \fn inline uint getHauteur() const
 		* \brief Fonction qui renvoie la hauteur
 		*
 		* \return uint qui contient la hauteur à renvoyée.
 		*/
		inline uint getHauteur() const { return hauteur; }

		/**
 		* \fn inline void setLargeur(uint _largeur) 
 		* \brief Fonction qui change la largeur
 		*
 		* \param _largeur uint qui contient la largeur.
 		*/
		inline void setLargeur(uint _largeur) { largeur=_largeur; }
		/**
 		* \fn inline void setHauteur(uint _hauteur)
 		* \brief Fonction qui change la hauteur
 		*
 		* \param _hauteur uint qui contient la hauteur.
 		*/
		inline void setHauteur(uint _hauteur) { hauteur = _hauteur; }
		/**
 		* \fn void dessiner(EZWindow &w, bool isActive)
 		* \brief Fonction qui dessine la forme
 		*
 		* \param w EZWindow& qui contient la fenetre sur laquelle on va dessiner.
		* \param isActive bool qui indique si la forme est sélectionnée
 		*/
		void dessiner(EZWindow &w, bool isActive) const override;
		/**
 		* \fn double perimetre() const
 		* \brief Fonction qui renvoie le perimetre
 		*
 		* \return double qui contient le perimetre.
 		*/
		double perimetre() const;

	protected:
		/**
 		* \fn virtual ostream& ecrire(ostream& os) const
 		* \brief Fonction qui ecrie la forme
 		*
 		* \param os ostream& qui contient un flux.
		* \return ostream& qui renvoie le flux.
 		*/
		virtual ostream& ecrire(ostream& os) const;
};

#endif