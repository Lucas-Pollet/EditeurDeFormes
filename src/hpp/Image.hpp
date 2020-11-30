/**
 * \file Image.hpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Déclaration de la classe Image
 *
 */

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "../hpp/Forme.hpp"

/*! \class Image
   * \brief Classe permettant de créer une image
   *
   */
class Image : public Forme {
    private:
        const char * path; /*!< uint largeur du rectangle*/
        string savepath; /*!< uint largeur du rectangle*/
        EZImage * image; /*!< uint largeur du rectangle*/
        bool alpha = true; /*!< uint largeur du rectangle*/
        double factor = 1; /*!< uint largeur du rectangle*/
    public:
        /*!
         * \fn Image(uint x, uint y, const char * path)
         * \brief Constructeur de l'image
         * \param x uint contenant la coordonnée x
         * \param y uint contenant la coordonnée y
         * \param path const char * contenant le chemin de l'image
         */
        Image(uint x, uint y, const char * path);
       /*! 
         * \fn Image(const Image &orig)
         * \brief Constructeur de copie d'une image
         * \param orig const Image& que l'on copie
         */
        Image(const Image &orig);
        /*! 
         * \fn Image(istream& is)
         * \brief Constructeur sur flux d'une image
         * \param is Input
         */
        Image(istream& is);
        /*!
         * \fn ~Image()
         * \brief Destructeur d'une image
         * 
         */ 
        ~Image();

        /*!
         * \fn inline bool getAlpha() const
         * \brief Fonction permettant de récupérer l'état de transparence de l'image
         * 
         * \return double contenant l'information si la forme est transparente
         */ 
        inline bool getAlpha() const { return alpha; }
        /*!
         * \fn inline void setAlpha(bool _alpha)
         * \brief Fonction permettant de changer la transparence de l'image
         * 
         * \param _alpha booleen si transparent
         */ 
        inline void setAlpha(bool _alpha) { alpha=_alpha; }
        /*!
         * \fn inline double getFactor() const
         * \brief Fonction permettant de récupérer le facteur de taille de l'image
         * 
         * \return double contenant le facteur
         */ 
        inline double getFactor() const { return factor; }
        /*!
         * \fn inline void setFactor(double _factor)
         * \brief Fonction permettant de changer le facteur de taille de l'image
         * 
         * \param _factor double contenant le facteur
         */ 
        inline void setFactor(double _factor) { if(_factor > 0){factor=_factor; changeFactor();}}

        /*! 
         * \fn void dessiner(EZWindow &w, bool isActive)
         * \brief Fonction permettant de dessiner une image
         * \param w La fenêtre où l'on dessine
         * \param isActive Indique si l'image est sélectionnée ou non
         */
        void dessiner(EZWindow &w, bool isActive) const override;

         /*!
          * \fn double perimetre() const
          * \brief Fonction permettant de récupérer le périmètre d'une image
          * 
          * \return double contenant le perimetre
         */       
        double perimetre() const;
        /*!
         * \fn void changeFactor()
         * \brief Fonction permettant de mettre à jour le facteur de taille de l'image sur la fenêtre
         * 
         */ 
        void changeFactor();
    protected:
       /*!
 		* \fn Ecris une image
 		* \brief Fonction d'écriture d'une image pour la stocker.
 		*
 		* \param os ostream& qui stocke un flux
 		* \return ostream& qui renvoie un flux
 		*/
        ostream& ecrire (ostream &) const;     
};
#endif