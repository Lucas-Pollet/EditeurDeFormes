/**
 * \file MyWindow.hpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Déclaration de la classe MyWindow
 *
 */

#ifndef MYWINDOW_HPP
#define MYWINDOW_HPP

#include <cmath>
#include <cstring>
#include <string>

#include "../hpp/Formes.hpp"
#include "../hpp/Calque.hpp"
#define PI 3.14159265358979323846264338327950288419716939937510582

/*! \class MyWindow
   * \brief Classe permettant d'afficher une fenêtre avec des formes
   *
   */
class MyWindow : public EZWindow {
  Calque calque; /*!< Calque instance de Calque*/
  Formes *formes; /*!< Formes* instance de Formes*/
  Forme  *pforme; /*!< Forme* instance de Forme*/
 public:
 /*!  \fn Constructeur de MyWindow
    * \param w Largeur de la fenêtre
    * \param h Hauteur de la fenêtre
    * \param name Nom de la fenêtre
    */
  MyWindow(int w, int h,const char *name);
  /*! \fn Destructeur
    * \brief Destructeur de mywindow
    *
    */
  ~MyWindow();
  /*!
    * \fn expose
    * \brief Fonction dessinant la fenêtre à chaque fois qu'elle est appelée
    *
    */
  void expose();
  /*!
    * \fn bouton appuyé
    * \brief Fonction détectant l'appuie d'une touche particulière
    *
    * \param keysym EZKeysym contenant une instance de EZKeysym
    */
  void keyPress(EZKeySym keysym);
  /*!
    * \fn bouton presser
    * \brief Fonction détectant un clique gauche de souris
    *
    * \param mouse_x coordonnée x de la souris
    * \param mouse_y coordonnée y de la souris
    * \param button int avec l'info sur qu'elle bouton ont appuye
    */
  void buttonPress(int mouse_x,int mouse_y,int button);
  /*!
    * \fn bouton appuyé puis bougé
    * \brief Fonction détectant un mouvement de souris
    *
    * \param mouse_x coordonnée x de la souris
    * \param mouse_y coordonnée y de la souris
    * \param button int avec l'info sur qu'elle bouton ont appuye
    */
  void motionNotify(int mouse_x,int mouse_y,int button);
  /*!
    * \fn bouton désappuyé
    * \brief Fonction détectant un relachement du clique
    *
    * \param mouse_x coordonnée x de la souris
    * \param mouse_y coordonnée y de la souris
    * \param button int avec l'info sur qu'elle bouton ont appuye
    */
  void buttonRelease(int mouse_x,int mouse_y,int button);
  /*!
    * \fn timer qui change
    * \brief Fonction qui se déclenche à chaque fois que le timer arrive à terme
    *
    */
  void timerNotify();

#ifdef ADVANCED_FACTORY
 private:
  static bool needInitialization;
#endif
};

#endif
