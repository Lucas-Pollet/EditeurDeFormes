/**
 * \file Cercle.hpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Déclaration de la classe cercle
 *
 */

#ifndef CERCLE_HPP
#define CERCLE_HPP
#include "../hpp/Forme.hpp"

/*! \class Cercle
   * \brief Classe permettant de créer des cercles
   *
   */
class Cercle : public Forme {

	private:
		uint rayon; /*!< uint rayon du cercle*/

	public:
		/**
 		* \fn Cercle(ulong couleur, ulong x, ulong y, ulong rayon)
 		* \brief Fonction de création d'une nouvelle instance d'un cercle.
 		*
 		* \param couleur ulong qui stock la couleur du cercle.
 		* \param x ulong qui stock la coordonnée x de la forme.
 		* \param y ulong qui stock la coordonnée y de la forme.
		* \param rayon ulong qui stock le rayon.
 		*/
		Cercle(ulong couleur, ulong x, ulong y, ulong rayon);
		/**
 		* \fn Cercle(Cercle& orig)
 		* \brief Fonction de création d'une copie de l'instance d'un cercle.
 		*
 		* \param orig const Cercle& qui stock l'instance d'un cercle.
 		*/
		Cercle(Cercle& orig);
		/**
 		* \fn Cercle(istream& is)
 		* \brief Fonction de création par lecture d'une instance d'un cercle.
 		*
 		* \param is istream& qui stock un flux.
 		*/
		Cercle(istream& is);
		/**
 		* \fn ~Cercle()
 		* \brief Fonction de destruction de l'instance d'un cercle.
 		*/
		~Cercle();
		/**
 		* \fn inline uint getRayon() const
 		* \brief Fonction qui renvoie le rayon
 		*
 		* \return uint qui contient le rayon à renvoyée.
 		*/
		inline uint getRayon() const { return rayon; }
		/**
 		* \fn inline void setRayon(uint rayon_)
 		* \brief Fonction qui change le rayon
 		*
 		* \param rayon_ uint qui contient le rayon
 		*/
		inline void setRayon(uint rayon_) { rayon = rayon_; }
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
		/**
 		* \fn ostream& ecrire(ostream& os) const
 		* \brief Fonction qui ecrie la forme
 		*
 		* \param os ostream& qui contient un flux.
		* \return ostream& qui renvoie le flux.
 		*/
		ostream& ecrire(ostream& os) const;
};
#endif 	