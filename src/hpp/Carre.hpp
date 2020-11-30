/**
 * \file Carre.hpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Déclaration de la classe Carre
 *
 */

#ifndef CARRE_HPP
#define CARRE_HPP

#include "../hpp/Forme.hpp"

/*! \class Carre
   * \brief Classe permettant de créer des carrés
   *
   */
class Carre : public Forme {

    private :
		uint cote; /*!< uint taille du cote du carre*/

	public :
		/**
 		* \fn Carre (ulong couleur, uint x, uint y, uint cote)
 		* \brief Fonction de création d'une nouvelle instance d'un carre.
 		*
 		* \param couleur ulong qui stock la couleur du carre.
 		* \param x uint qui stock la coordonnée x de la forme.
 		* \param y uint qui stock la coordonnée y de la forme.
		* \param cote uint qui stock la taille du cote du carre.
 		*/
		Carre (ulong couleur, uint x, uint y, uint cote);
		/**
 		* \fn Carre (const Carre& orig)
 		* \brief Fonction de création d'une copie de l'instance d'un carre.
 		*
 		* \param orig const Carre& qui stock l'instance d'un carre.
 		*/
		Carre (const Carre& orig);
		/**
 		* \fn Carre ( istream& is)
 		* \brief Fonction de création par lecture d'une instance d'un carre.
 		*
 		* \param is istream& qui stock un flux.
 		*/
		Carre ( istream& is);
		/**
 		* \fn ~Carre()
 		* \brief Fonction de destruction de l'instance d'un carre.
 		*/
		~Carre();

		/**
 		* \fn inline uint getCote() const
 		* \brief Fonction qui renvoie la taille du cote
 		*
 		* \return uint qui contient la taille du cote à renvoyée.
 		*/

		inline uint getCote() const { return cote; }
		/**
 		* \fn inline void setCote (uint _cote) 
 		* \brief Fonction qui change la taille du cote
 		*
 		* \param _cote uint qui contient la taille du cote.
 		*/
		inline void setCote (uint _cote) { cote = _cote; }
		/**
 		* \fn double perimetre() const 
 		* \brief Fonction qui renvoie le perimetre
 		*
 		* \return double qui contient le perimetre.
 		*/
		double perimetre() const ;
		/**
 		* \fn void dessiner(EZWindow&,bool isActive=false)
 		* \brief Fonction qui dessine la forme
 		*
 		* \param w EZWindow& qui contient la fenetre sur laquelle on va dessiner.
		* \param isActive bool qui indique si la forme est sélectionnée
 		*/
		void dessiner(EZWindow&,bool isActive=false) const override;
        
	protected :
		/**
 		* \fn ostream& ecrire (ostream &) const
 		* \brief Fonction qui ecrie la forme
 		*
 		* \param os ostream& qui contient un flux.
		* \return ostream& qui renvoie le flux.
 		*/
		ostream& ecrire (ostream &) const;
};
#endif