/**
 * \file Ellipse.hpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Implémentation de la classe Ellipse
 *
 */


#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "forme.hpp"

/*! \class Ellipse
   * \brief Classe permettant de créer une ellipse
   *
   */
class Ellipse : public Forme {

	private:

		uint demilargeur; /*!< uint Demi-largeur de l'ellipse */
		uint demihauteur; /*!< uint Demi-hauteur de l'ellipse */
	public:
		/**
 		* \fn Ellipse(ulong couleur, ulong x, ulong y, ulong demilargeur, ulong demihauteur)
 		* \brief Fonction de création d'une nouvelle instance d'une ellipse.
 		*
 		* \param couleur ulong qui stock la couleur du cercle.
 		* \param x ulong qui stock la coordonnée x de la forme.
 		* \param y ulong qui stock la coordonnée y de la forme.
		* \param demilargeur ulong qui stock la demi-largeur.
		* \param demihauteur ulong qui stock la demi-hauteur.
 		*/
		Ellipse(ulong couleur, ulong x, ulong y, ulong demilargeur, ulong demihauteur);
		/**
 		* \fn Ellipse(Ellipse& orig)
 		* \brief Fonction de création d'une copie de l'instance d'une ellipse.
 		*
 		* \param orig const Ellipse& qui stock l'instance d'une ellipse.
 		*/
		Ellipse(Ellipse& orig);
		/**
 		* \fn Ellipse(istream& is)
 		* \brief Fonction de création par lecture d'une instance d'une ellipse.
 		*
 		* \param is istream& qui stock un flux.
 		*/
		Ellipse(istream& is);
		/**
 		* \fn ~Ellipse()
 		* \brief Fonction de destruction de l'instance d'une ellipse.
 		*/
		~Ellipse();
		/**
 		* \fn inline uint getDemilargeur() const
 		* \brief Fonction qui renvoie la demi-largeur
 		*
 		* \return uint qui contient la demi-largeur à renvoyée.
 		*/
		inline uint getDemilargeur() const { return demilargeur; }
		/**
 		* \fn inline uint getDemihauteur() const
 		* \brief Fonction qui renvoie la demi-hauteur
 		*
 		* \return uint qui contient la demi-hauteur à renvoyée.
 		*/
		inline uint getDemihauteur() const { return demihauteur; }
		/**
 		* \fn inline void setDemilargeur(uint _demilargeur)
 		* \brief Fonction qui change la demi-largeur
 		*
 		* \param _demilargeur uint qui contient la demi-largeur
 		*/
		inline void setDemilargeur(uint _demilargeur) { demilargeur = _demilargeur; }
		/**
 		* \fn inline void setDemihauteur(uint _demihauteur)
 		* \brief Fonction qui change la demi-hauteur
 		*
 		* \param _demihauteur uint qui contient la demi-hauteur
 		*/
		inline void setDemihauteur(uint _demihauteur) { demihauteur = _demihauteur; }
		/**
 		* \fn void dessiner(EZWindow& win, bool isActive = false) const
 		* \brief Fonction qui dessine la forme
 		*
 		* \param win EZWindow& qui contient la fenetre sur laquelle on va dessiner.
		* \param isActive bool qui indique si la forme est sélectionnée
 		*/
	 	void dessiner(EZWindow& win, bool isActive = false) const;
		/**
 		* \fn double perimetre() const
 		* \brief Fonction qui renvoie le perimetre
 		*
 		* \return double qui contient le perimetre.
 		*/
		double perimetre() const;

	protected:
		ostream& ecrire(ostream& os) const;
};
#endif