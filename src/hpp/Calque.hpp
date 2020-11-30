/**
 * \file Calque.hpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Déclaration de la classe Calque
 *
 */

#ifndef CALQUE_HPP
#define CALQUE_HPP

#include "../hpp/Formes.hpp"

/*! \class Calque
   * \brief Classe permettant la gestion de calques
   *
   */
class Calque {
    private:
        uint maxele;      /*!< uint nombre maximum d'éléments*/
        uint nbele;       /*!< uint nombre d'éléments*/
        uint selectionne; /*!< uint élément sélectionnée*/
        Formes **calques; /*!< Formes** tableau de pointeur sur formes*/
    public:
        /*! \fn Constructeur de Classe
            * \param taille Paramètre pour spécifier le nombre de calques
            */
        Calque(uint taille=10);
        /*! \fn Destructeur de Classe
            */
        ~Calque();

        /*! \fn getnbele()
            * \brief Getteur pour le nombre de calques
            * \return nbele
            */
        inline uint getnbele() const { return nbele; }
        /*!   \fn Fonction getTable()
            * \brief Getteur pour un calque de la liste
            * \param k Index du calque
            * \return Formes *
            */
        Formes *    getCalques(uint k) const;
        /*! \fn Fonction getSelectionne
            * \brief Getteur pour la variable indiquant quel calque est actuellement actif
            * \return selectionne
            */
        inline uint getSelectionne() { return selectionne; }
        /*! \brief Setteur pour mettre une instance de Formes dans la liste, à l'index désigné par i
            * \param i Index du calque
            * \param f Le pointeur sur l'instance de Formes
            */
        inline void setCalques(uint i, Formes * f) { calques[i]=f; }
        /*! \fn Fonction setSelectionne
            * \brief Setteur pour indique quel calque est sélectionné
            * \param i Index du calque
            * \param f Le pointeur sur l'instance de Formes
            */
        inline void setSelectionne(uint i) { selectionne=i; }

        /*! \fn Fonction dessiner
            * \brief Fonction permettant de dessiner les formes
            * \param w La fenêtre où l'on dessine les formes
            */
        void dessiner(EZWindow& w) const;
        /*! \fn Fonction afficher
            * \brief Fonction écrivant les informations des différents calques (le calque actuel, les calques affichés et les calques vides)
            *
            */
        void afficher() const;
        /*! \fn Fonction intervertir
            * \brief Fonction permettant d'intervertir deux calques
            * \param i Index du premier calque
            * \param j Index du deuxième calque
            */
        void intervertir(uint i, uint j);
        /*! \fn Fonction ajouter
            * \brief Fonction permettant d'ajouter une instance de Formes dans la liste
            * \param f Le pointeur sur l'instance de Formes
            */
        void ajouter(Formes * f=new Formes());
        /*! \fn Fonction supprimer
            * \brief Fonction supprimant un calque de la liste
            * \param i Index du calque
            */
        void supprimer(uint i);
        /*! \fn Fonction fusionner
            * \brief Fonction permettant de transférer les formes du calque j vers le calque i et supprime ensuite le calque j
            * \param i Index du calque vers lequel on transfert les formes
            * \param j Index du calque à supprimer
            */
        void fusionner(uint i, uint j);
        /*! \fn Fonction afficherOuDesafficher
            * \brief Fonction permettant de désafficher un calque (ou d'afficher si elle ne l'est pas déjà)
            * \param i Index du calque
            */
        void afficherOuDesafficher(uint i);
        /*! \fn Fonction sauver
            *  \brief Fonction permettant de sauvegarder les différents calques avec leurs formes
            * \param os Output
            */
        void sauver(ostream& os) const;
           /*!   
            * \fn Fonction charger
            * \brief Fonction permettant de charger des calques avec leurs formes à partir de la lecture d'un fichier .txt
            * \param is Input
            */ 
	    void charger(istream& is);
};
#endif