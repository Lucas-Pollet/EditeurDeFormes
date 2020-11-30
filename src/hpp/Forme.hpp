/**
 * \file Forme.hpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Déclaration de la classe Formes
 *
 */

#ifndef FORME_HPP
#define FORME_HPP

#include "../hpp/Point.hpp"

/*! \class Forme
   * \brief Classe permettant de créer des formes
   *
   */
class Forme {
    
private :
     ulong couleur; /*!< ulong Couleur du trait */
     Point ancre; /*!< Point Ancre de la forme */
     bool selected; /*!< bool Indique si la forme est sélectionnée */
     uint epaisseur = 1; /*!< uint Epaisseur du trait */
     bool estRemplie = false; /*!< bool Indique si la forme est remplie */
     char animation = 'n'; /*!< char Indique quel animation est appliquée à la forme */

public :
    /**
 		* \fn Constructeur
 		* \brief Fonction de création d'une nouvelle instance d'une forme.
 		*
 		* \param couleur ulong qui stock la couleur de la forme.
 		* \param x ulong qui stock la coordonnée x de la forme.
 		* \param y ulong qui stock la coordonnée y de la forme.
 		*/
    Forme(ulong couleur, uint x, uint y);
    /**
 		* \fn Constructeur de copie
 		* \brief Fonction de création d'une copie de l'instance d'une forme.
 		*
 		* \param orig const Forme& qui stock l'instance d'une forme.
 		*/
    Forme(const Forme& orig);
    /**
 		* \fn Constructeur par lecture de flux
 		* \brief Fonction de création par lecture d'une instance d'une forme.
 		*
 		* \param is istream& qui stock un flux.
 		*/
    Forme(istream& is);
    /**
 		* \fn Destructeur
 		* \brief Fonction de destruction de l'instance d'une forme.
 		*/
    virtual ~Forme();

    /**
 		* \fn Getter de couleur
 		* \brief Fonction qui renvoie la couleur
 		*
 		* \return ulong qui contient la couleur à renvoyée.
 		*/
    inline ulong getCouleur() const{ return couleur; }
    /**
 		* \fn Getter de ancre
 		* \brief Fonction qui renvoie l'ancre'
 		*
 		* \return Point qui contient l'ancre' à renvoyée.
 		*/
    inline Point getAncre() const { return ancre; }
    /**
 		* \fn Getter de epaisseur
 		* \brief Fonction qui renvoie l'épaisseur'
 		*
 		* \return uint qui contient l'épaisseur' à renvoyée.
 		*/
    inline uint getEpaisseur() const { return epaisseur; }
    /**
 		* \fn Getter de estRemplie
 		* \brief Fonction qui renvoie estRemplie
 		*
 		* \return bool qui contient estRemplie à renvoyée.
 		*/
    inline bool getEstRemplie() const{return estRemplie; }
    /**
 		* \fn Getter de animation
 		* \brief Fonction qui renvoie l'animation
 		*
 		* \return char qui contient l'animation à renvoyée.
 		*/
    inline char getAnimation() const { return animation; }
    
    /**
 		* \fn Setter de decalDroite
 		* \brief Fonction qui change le décalage de droite
 		*
 		* \param _decalDroite int qui contient decalDroite
 		*/
    inline void setDecalDroite(int _decalDroite){decalDroite=_decalDroite;}
    /**
 		* \fn Setter de decalGauche
 		* \brief Fonction qui change le décalage de gauche
 		*
 		* \param _decalGauche int qui contient decalGauche
 		*/
	inline void setDecalGauche(int _decalGauche){decalGauche=_decalGauche;}
    /**
 		* \fn Setter de decalHaut
 		* \brief Fonction qui change le décalage du haut
 		*
 		* \param _decalHaut int qui contient la demi-hauteur
 		*/
	inline void setDecalHaut(int _decalHaut){decalHaut=_decalHaut;}
    /**
 		* \fn Setter de decalBas
 		* \brief Fonction qui change le décalage du bas
 		*
 		* \param _decalBas int qui contient la demi-hauteur
 		*/
	inline void setDecalBas(int _decalBas){decalBas=_decalBas;}
    /**
 		* \fn Setter de augmente
 		* \brief Fonction qui change augmente
 		*
 		* \param _augmente bool qui contient augmente
 		*/
    inline void setAugmente(bool _augmente){augmente=_augmente;}
    /**
 		* \fn Getter de decalDroite
 		* \brief Fonction qui renvoie decalDroite
 		*
 		* \return int qui contient decalDroite à renvoyée.
 		*/
	inline int getDecalDroite(){return decalDroite;}
    /**
 		* \fn Getter de decalGauche
 		* \brief Fonction qui renvoie decalGauche
 		*
 		* \return int qui contient decalGauche à renvoyée.
 		*/
	inline int getDecalGauche(){return decalGauche;}
    /**
 		* \fn Getter de decalHaut
 		* \brief Fonction qui renvoie decalHaut
 		*
 		* \return int qui contient decalHaut à renvoyée.
 		*/
	inline int getDecalHaut(){return decalHaut;}
    /**
 		* \fn Getter de decalBas
 		* \brief Fonction qui renvoie decalBas
 		*
 		* \return int qui contient decalBas à renvoyée.
 		*/
	inline int getDecalBas(){return decalBas;}
    /**
 		* \fn Getter de augmente
 		* \brief Fonction qui renvoie augmente
 		*
 		* \return bool qui contient augmente à renvoyée.
 		*/
    inline bool getAugmente(){return augmente;}

    /**
 		* \fn Setter de couleur
 		* \brief Fonction qui change la couleur
 		*
 		* \param _couleur ulong qui contient la couleur
 		*/
    inline void setCouleur(ulong _couleur) { couleur=_couleur; }
    /**
 		* \fn Setter de x et de y de l'ancre
 		* \brief Fonction qui change les coordonnées de l'ancre
 		*
 		* \param x uint qui le nouveau x
        * \param y uint qui le nouveau y
 		*/
    inline void setAncre(uint x,uint y) { ancre.setXY(x,y) ; }
    /**
 		* \fn Setter de la taille de l'ancre
 		* \brief Fonction qui change la taille de l'ancre
 		*
 		* \param taille uint qui contient la nouvelle taille
 		*/
    inline void setAncre(uint taille) {ancre.setTaille(taille);}
    /**
 		* \fn Setter d'épaisseur
 		* \brief Fonction qui change l'épaisseur'
 		*
 		* \param _epaisseur uint qui contient la nouvelle épaisseur
 		*/
    inline void setEpaisseur(uint _epaisseur) { epaisseur=_epaisseur; }
    /**
 		* \fn Setter de estRemplie
 		* \brief Fonction qui change estRemplie
 		*
 		* \param _estRemplie uint qui contient la nouvelle valeur de estRemplie
 		*/
    inline void setEstRemplie(bool _estRemplie) {estRemplie=_estRemplie; }
    /**
 		* \fn Setter de animation
 		* \brief Fonction qui change l'animation'
 		*
 		* \param _animation uint qui contient l'animation
 		*/
    inline void setAnimation(char _animation) { animation=_animation; }
    /**
 		* \fn isOver
 		* \brief Fonction qui indique si les coordonnées x et y corresponde à celles de l'ancre
 		*
 		* \param x Coordonée x
        * \param y Coordonée y
 		*/
    inline bool isOver(uint x, uint y) const { return ancre.isOver(x,y); }
    /**
 		* \fn Dessine la forme
 		* \brief Fonction qui dessine la forme
 		*
 		* \param win EZWindow& qui contient la fenetre sur laquelle on va dessiner.
		* \param isActive bool qui indique si la forme est sélectionnée
 		*/
    virtual void dessiner(EZWindow& w, bool active=false) const ;
    /**
 		* \fn Perimetre
 		* \brief Fonction qui renvoie le perimetre
 		*
 		* \return double qui contient le perimetre.
 		*/
    virtual double perimetre()const = 0;
    /*! \fn Fonction permettant d'écrire la forme sur un flux
        * \param os La sortie où l'on écrit
		* \param f La forme à écrire
        */
    friend ostream& operator<<(ostream& os, Forme& f);
    /*! \fn Fonction permettant de charger la forme
        * \param is Input
        */
    static Forme* charger(istream& is);

protected :
    /*! \fn Fonction virtuelle permettant d'écrire la fomre
        * \param os Output
        */
    virtual ostream& ecrire(ostream& os) const;
	bool augmente = true; /*!< bool Indique si l'augmentation est positive ou négative */
    int decalDroite=0; /*!< int Indique le décalage de droite */
	int decalGauche=0; /*!< int Indique le décalage de gauche */
	int decalHaut=0; /*!< int Indique le décalage du haut */
	int decalBas=0; /*!< int Indique le décalage du bas */

    
};

#endif