/**
 * \file Formes.hpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Déclaration de la classe Formes
 *
 */

#ifndef FORMES_HPP
#define FORMES_HPP

#include "../hpp/Forme.hpp"

/*! \class Formes
   * \brief Classe permettant la gestion de formes
   *
   */
class Formes {
	
private:
	uint maxformes; /*!< uint nombre maximal de formes*/
	uint nbformes; /*!< uint nombre de formes*/
	Forme** formes; /*!< Forme** tableau de formes*/
	bool estAfficher = true; /*!< bool est afficher*/

public:
	/*! \fn Formes(uint taille=200)
	    * \brief Constructeur de Formes
        * \param taille Paramètre pour spécifier le nombre de Forme
        */
	Formes(uint taille=200);
	/*! \fn ~Formes()
	    * \brief Destructeur de Formes
        */
	~Formes();

	/*! \fn inline uint getNbformes()  
	    * \brief Getteur pour le nombre de Forme
        * \return nbele
        */
	inline uint getNbformes()   { return nbformes; }
	/*! \fn inline Forme* getForme(uint i)
	    * \brief Getteur pour une Forme
		* \param i Index de la forme
        * \return Forme*
        */
	inline Forme* getForme(uint i) { return formes[i]; }
	/*! \fn inline bool getEstAfficher()
	    * \brief Getteur pour le booléen qui indique si les formes sont affichées ou non
        * \return bool
        */
	inline bool getEstAfficher()  { return estAfficher; }
	/*! \fn inline void setEstAfficher(bool b) 
	    * \brief Setteur pour indique si les formes sont affichées ou non
        * \param b Le booléen
        */
	inline void setEstAfficher(bool b) { estAfficher=b; }
	/*! \fn void setForme(Forme* f, uint i)
	    * \brief Setteur pour mettre une forme dans l'index correspondante
        * \param i Index du calque
        * \param f Le pointeur sur l'instance de Forme
		*/
	void setForme(Forme* f, uint i);

	/*! \fn void ajouter(Forme *forme)
	    * \brief  Fonction pour ajouter une forme
		* \param forme La forme à ajouter
		*/
	void ajouter(Forme *forme);
	/*! \fn void supprimer(Forme *f)
	    * \brief Fonction pour supprimer une forme
		* \param forme La forme à supprimer
		*/
	void supprimer(Forme *f);
	/*! \fn Forme *isOver(uint _x,uint _y)
	    * \brief Fonction pour indiquer la forme indiquée par les coordonnées
		* \param _x
		* \param _y
		* \return Forme*
		*/
	Forme *isOver(uint _x,uint _y);
	/*! \fn void dessiner(EZWindow& w) const
	    * \brief Fonction permettant de dessiner les formes
        * \param w La fenêtre où l'on dessine les formes
        */
	void dessiner(EZWindow& w) const;
	/*! \fn friend ostream& operator<<(ostream&  os, const Formes& formes)
	    * \brief Fonction permettant d'écrire les formes
        * \param os La sortie où l'on écrit
		* \param formes Le tableau de formes à écrire
        */
	friend ostream& operator<<(ostream&  os, const Formes& formes);
	/*! \fn void sauver(ostream& os) const
	    * \brief Fonction permettant de sauvegarder les formes
        * \param os Output
        */
	void sauver(ostream& os) const;
	/*! \fn void charger(istream& is)
	    * \brief Fonction permettant de recharger les formes
        * \param is Input
        */
	void charger(istream& is);
};
#endif
