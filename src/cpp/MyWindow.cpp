/**
 * \file MyWindow.cpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Déclaration de la classe MyWindow
 *
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "../hpp/ez-draw++.hpp"
#include "../hpp/MyWindow.hpp"

#include "../hpp/Formes.hpp"
#include "../hpp/Calque.hpp"

#include "../hpp/Point.hpp"   // Uniquement pour le constructeur qui peuple la fenêtre
#include "../hpp/Ellipse.hpp" // avec quelques formes.
#include "../hpp/Cercle.hpp"
#include "../hpp/Rectangle.hpp"
#include "../hpp/Carre.hpp"
#include "../hpp/Polygone.hpp"
#include "../hpp/Image.hpp"

#ifdef ADVANCED_FACTORY
bool MyWindow::needInitialization=true;
#endif

MyWindow::MyWindow(int w, int h,const char *name)
 : EZWindow(w,h,name),calque(10),formes(nullptr),pforme(nullptr)
{
  formes = new Formes(200);
  calque.ajouter(formes);
  setDoubleBuffer(true);
  startTimer(10);
#ifdef ADVANCED_FACTORY
 if(needInitialization) // Ne faire l'initialisation que la première fois qu'une MyWindow est construite.
  {
   needInitialization=false;
   Forme::register_factory_function<Rectangle>("Rectangle");
   Forme::register_factory_function<Ellipse>("Ellipse");
   Forme::register_factory_function<Carre>("Carre");
   Forme::register_factory_function<Cercle>("Cercle");
   Forme::register_factory_function<Polygone>("Polygone");
   Forme::print_registered_factory_functions(cout);
  }
#endif
}

MyWindow::~MyWindow()
{}

void MyWindow::timerNotify()
{
  sendExpose();
  startTimer(10);
}

void MyWindow::expose()
{
 calque.dessiner(*this);
 if(pforme!=nullptr) pforme->dessiner(*this,true);
 setColor(ez_black);
 drawText(EZAlign::TL,3,3,"h : affiche l'aide sur la console");
}

void MyWindow::buttonPress(int mouse_x,int mouse_y,int button)
{
 if(button==1)  /// Si on clique sur le clic gauche de la souris, alors :
 {
   bool temp=true;
   Polygone *ppolygone = dynamic_cast<Polygone*>(pforme);
   if(ppolygone != nullptr)                                 /// Si la forme est un polygone, alors :
   {
     ppolygone->savePoint();                                  /// Sauvegarde l'emplacement de l'ancre
     if(ppolygone->sommetOver(mouse_x, mouse_y))              /// Si on survol un sommet, alors :
     {
       temp=false;
       ppolygone->setAppuiSurSommet(true);                      /// On indique que l'on appuie sur un sommet à polygone
     }
     else if(ppolygone->AncreIsOnTheMouse(mouse_x, mouse_y)) /// Sinon si on survol l'ancre, alors :
       {  
          temp=true;
          ppolygone->DeplacementForme();                        /// On déplace la forme par rapport à l'ancre
          ppolygone->setAppuiSurAncre(true);
       }
     ppolygone->setSommetSelect(nullptr);                    ///nullptr indique qu'il n'y a pas de sommet
     ppolygone->signalClicked(mouse_x, mouse_y);             /// Ajoute sommet la ou on clique
   }
   if (temp)                                               /// Si on appuie pas sur un sommet
   {
    pforme = formes->isOver(mouse_x,mouse_y);               /// On récupère la forme sélectionnée
    Polygone *ppolygone = dynamic_cast<Polygone*>(pforme);
    if(ppolygone != nullptr)                                /// Si cette forme est un polygone, alors :
    {
      if(ppolygone->AncreIsOnTheMouse(mouse_x, mouse_y))      /// Si la souris est sur l'ancre, alors :
      {
        ppolygone->DeplacementForme();                          /// On déplace la forme
        ppolygone->setAppuiSurAncre(true);
        ppolygone->setAppuiSurSommet(true);
      }
    }
   }
 }
 sendExpose();
}

// Deplacement de la souris :
void MyWindow::motionNotify(int mouse_x,int mouse_y,int button)
{
 if(button == 1 && pforme != nullptr)                     /// Si on clique sur l'ancre d'une forme
 {
   bool temp=true;
   Polygone *ppolygone = dynamic_cast<Polygone*>(pforme);
   if(ppolygone != nullptr)                                 /// Si la forme est un polygone, alors :
   {
     if(ppolygone->getAppuiSurSommet())                       /// Si on appuie sur un sommet
     {
       temp=false;
       if(ppolygone->getAppuiSurAncre())                        /// Si on appuie sur une ancre
       {  
          temp=true;
          ppolygone->DeplacementForme();                          /// on déplace la forme
       }
     }
   }
   if(temp)pforme->setAncre(mouse_x,mouse_y);             /// Si on appui sur l'ancre : on la bouge
   if(ppolygone != nullptr && !ppolygone->getAppuiSurAncre())  /// Si la forme sélectionnée est un polygone et qu'on appuie pas sur l'ancre, alors :
   {
     if (ppolygone->sommetIsSelect()) ppolygone->setXYSommet(mouse_x,mouse_y);   /// Si il ya un sommet, alors : on déplace le sommet sur la souris
   }
 }
 sendExpose();
}

void MyWindow::buttonRelease(int mouse_x,int mouse_y,int button)
{
 if(button == 1 && pforme != nullptr) // Si on lache un clic sur l'ancre d'une forme
 {
   Polygone *ppolygone = dynamic_cast<Polygone*>(pforme);
   if(ppolygone == nullptr)pforme->setAncre(mouse_x,mouse_y);  /// Si la forme sélectionnée n'est pas un polygone, alors : On bouge l'ancre sur la souris
   if(ppolygone != nullptr)                                     /// Si la forme sélectionnée est un polygone, alors :
   {
     if (ppolygone->sommetIsSelect() && !ppolygone->getAppuiSurAncre()) /// Si un sommet est sélectionnée et pas une ancre, alors :
     {
      ppolygone->setXYSommet(mouse_x,mouse_y);                            /// On bouge le sommet sur les coordonnées de la souris
     }
     if(ppolygone->getAppuiSurAncre())                                  /// Si c'est une ancre qui est sélectionnée, alors :
       {  
          ppolygone->DeplacementForme();                                  /// On déplace la forme en fonction de la souris
       }
     ppolygone->setAppuiSurSommet(false);
     ppolygone->setAppuiSurAncre(false);
     
   }
 }
 sendExpose();
}

void MyWindow::keyPress(EZKeySym keysym) // Une touche du clavier a ete enfoncee ou relachee
{
  switch (keysym)
    {
     case EZKeySym::Escape:
     case EZKeySym::q :       EZDraw::quit (); break;
     case EZKeySym::E:
      cout << *formes;
      break;
     case EZKeySym::S:
      {
       ofstream f("formes.txt");
       calque.sauver(f);
      }
      break;
     case EZKeySym::C:
      {
        for(uint i=calque.getnbele();i>0;i--)
          calque.supprimer(i-1);
        ifstream f("formes.txt");
        calque.charger(f);
        formes=calque.getCalques(0);
      }
      break;
     case EZKeySym::_0: if(pforme) pforme->setCouleur(ez_black);   break;
     case EZKeySym::_1: if(pforme) pforme->setCouleur(ez_grey);    break;
     case EZKeySym::_2: if(pforme) pforme->setCouleur(ez_red);     break;
     case EZKeySym::_3: if(pforme) pforme->setCouleur(ez_green);   break;
     case EZKeySym::_4: if(pforme) pforme->setCouleur(ez_blue);    break;
     case EZKeySym::_5: if(pforme) pforme->setCouleur(ez_yellow);  break;
     case EZKeySym::_6: if(pforme) pforme->setCouleur(ez_cyan);    break;
     case EZKeySym::_7: if(pforme) pforme->setCouleur(ez_magenta); break;
     case EZKeySym::h:
      cout << "------------------------Tableau-des-Commandes-------------------------" << endl
           << "|| q : quitter                                                      ||" << endl
           << "|| h : cette aide                                                   ||" << endl
           << "|| V : vide le calque actuel                                        ||" << endl
           << "|| B : vide tous les calques                                        ||" << endl
           << "|| E : ecrit la liste des formes du calque actuel sur la console    ||" << endl
           << "|| S : sauve la liste des formes sur disque                         ||" << endl
           << "|| C : charge la liste des formes depuis le disque                  ||" << endl
           << "|| m : ouvre la palette des couleurs                                ||" << endl
           << "|| n : ouvre la liste des formes                                    ||" << endl
           << "|| a : met une animation                                            ||" << endl
           << "|| g : Ouvrir le gestionnaire de calques                            ||" << endl
           << "|| z : Affiche le périmètre de la forme                             ||" << endl
           << "|| + : augmente l'epaisseur ou l'opacite pour les images            ||" << endl
           << "|| - : diminue l'epaisseur ou l'opacite pour les images             ||" << endl
           << "|| A : change la transparence de l'image                            ||" << endl
           << "|| f : remplie/deremplie la forme                                   ||" << endl
           << "|| o : ajoute un point au polygone                                  ||" << endl
           << "|| l : enleve un point au polygone                                  ||" << endl
           << "|| Suppr : supprimer la forme                                       ||" << endl
           << "|| Up : Agrandi la forme vers le haut                               ||" << endl
           << "|| Down : Agrandi la forme vers le bas                              ||" << endl
           << "|| Right : Agrandi la forme vers la droite                          ||" << endl
           << "|| Left : Agrandi la forme vers la gauche                           ||" << endl
           << "|| alt : Change le sens d'agrandissement d'une forme                ||" << endl
           << "----------------------------------------------------------------------" << endl
           ;
      break;
     case EZKeySym::V: 
        for(uint i=formes->getNbformes();i>0;i--)
          formes->supprimer(formes->getForme(i-1)); 
      break;
     case EZKeySym::B:
        for(uint i=calque.getnbele(); i>0; i--)
        {
          formes=calque.getCalques(i-1);
          for(int i=formes->getNbformes();i>0;i--)
            formes->supprimer(formes->getForme(i-1));
        }
      break;
     case EZKeySym::a:
     if(pforme){
      cout  << "-----------ANIMATIONS----------" << endl
            << "|| Choisir une animation :   ||" << endl
            << "|| n : Pas d'animation       ||" << endl
            << "|| r : Arc-en-ciel           ||" << endl
            << "|| p : Pulsation             ||" << endl
            << "-------------------------------" << endl
            << "|_ Veuillez rentré votre choix :" << endl;
            char c;
            cin >> c;
            pforme->setAnimation(c);}
     break;
     case EZKeySym::m:
      cout  << "-------Palette-des-couleurs-------" << endl
            << "|| 0 : met en noir la forme     ||" << endl
            << "|| 1 : met en gris la forme     ||" << endl
            << "|| 2 : met en rouge la forme    ||" << endl
            << "|| 3 : met en vert la forme     ||" << endl
            << "|| 4 : met en bleu la forme     ||" << endl
            << "|| 5 : met en jaune la forme    ||" << endl
            << "|| 6 : met en cyan la forme     ||" << endl
            << "|| 7 : met en magenta la forme  ||" << endl
            << "----------------------------------" << endl;
     break;
     case EZKeySym::n:
      cout  << "---------Liste-des-formes---------" << endl
            << "|| r : cree un rectangle        ||" << endl
            << "|| e : cree une ellipse         ||" << endl
            << "|| s : cree un carre            ||" << endl
            << "|| c : cree un cercle           ||" << endl
            << "|| p : cree un Polygone         ||" << endl
            << "|| i : cree une image           ||" << endl
            << "----------------------------------" << endl;
     break;
     case EZKeySym::Delete: if(pforme) formes->supprimer(pforme); break;
     case EZKeySym::r: 
      cout << "|_ Donner la largeur et la longueur du rectangle" << endl;
      uint lar, lon;
      cin >> lar >> lon;
      formes->ajouter(new Rectangle(ez_black,getWidth()/2-25,getHeight()/2-25,lon ,lar)); break;
     case EZKeySym::e:
      cout << "|_ Donner la demi-largeur et la demi-hauteur de l'ellipse" << endl;
      uint del, deh;
      cin >> del >> deh;
      formes->ajouter(new Ellipse(ez_black,getWidth()/2-25,getHeight()/2-15,del ,deh)); break;
     case EZKeySym::s:
      cout << "|_ Donner le cote du carre" << endl;
      uint cot;
      cin >> cot;
      formes->ajouter(new Carre(ez_black,getWidth()/2-25,getHeight()/2-25,cot)); break;
     case EZKeySym::c: 
      cout << "|_ Donner le rayon du cercle" << endl;
      uint ray;
      cin >> ray;
      formes->ajouter(new Cercle(ez_black,getWidth()/2-25,getHeight()/2-25,ray)); break;

     case EZKeySym::i: 
      {
      cout << "|_ Donner le chemin d'acces de l'image :" << endl;
      string path;
      cin >> path;
      const char * cpath = path.c_str();;
      FILE * fichier = fopen(cpath, "rb");
      if(fichier != NULL)
        formes->ajouter(new Image(getWidth()/2-25, getHeight()/2-25, cpath)); 
      else
        cout << "|_ Chemin Invalide !" << endl;
      break;
      }
     case EZKeySym::p:
     {
      int nbPoint;
      uint rayon;
      cout << "|_ Combien de Point voulez-vous ?" << endl;
      cin >> nbPoint;
      while(nbPoint<1)
      {
        cout << "|_ Valeur invalide !!" << endl;
        cin >> nbPoint;
      }
      cout << "|_ Quelle rayon voulez vous ?" << endl;
      cin >> rayon;
      while(rayon<=0)
      {
        cout << "|_ Valeur invalide !!" << endl;
        cin >> rayon;
      }
      size_t _nbPoint = nbPoint;
      std::vector<Point> tabPointPolygone;
      for(size_t i=0;i<_nbPoint;i++)
      {
        Point tempPoint(getWidth()/2,getHeight()/2);
        tabPointPolygone.push_back(tempPoint);
      }
      formes->ajouter(new Polygone(ez_black,getWidth()/2+rayon*cos(0),getHeight()/2+rayon*sin(0), tabPointPolygone, rayon));
     }break;
     case EZKeySym::o:
     {
     Polygone *ppolygone = dynamic_cast<Polygone*>(pforme);
     if(ppolygone != nullptr)
     {
       ppolygone->ajouterPoint();
     }
     }break;
     case EZKeySym::l:
     {
     Polygone *ppolygone = dynamic_cast<Polygone*>(pforme);
     if(ppolygone != nullptr)
     {
       ppolygone->enleverPoint();
     }
     }break;
     case EZKeySym::A:{
      Image *image = dynamic_cast<Image*>(pforme);
      if (image != nullptr){
        image->setAlpha(!image->getAlpha());
      }
      break;
     }
     case EZKeySym::f: if(pforme) {pforme->setEstRemplie(!(pforme->getEstRemplie()));} break;
     case EZKeySym::plus:{
        if(pforme) 
        {
          Image * img = dynamic_cast<Image*> (pforme);
          Polygone * poly = dynamic_cast<Polygone*> (pforme);
          pforme->setEpaisseur(pforme->getEpaisseur() + 1);
          if(img != nullptr){
            img->setFactor(img->getFactor() + 0.02);
          }
          else if(pforme->getEpaisseur()>0 && poly == nullptr)
          {
              pforme->setAncre(pforme->getAncre().getTaille()+pforme->getEpaisseur()-1);
          }
        }
        break;
     }
     case EZKeySym::minus:{
        if(pforme)
        {
          Image * img = dynamic_cast<Image*> (pforme);
          Polygone * poly = dynamic_cast<Polygone*> (pforme);
          if(pforme->getEpaisseur()>0)
              pforme->setEpaisseur(pforme->getEpaisseur() - 1);
          if(img != nullptr){
             img->setFactor(img->getFactor() - 0.02);
          }else{
            if(pforme->getEpaisseur()>0 && poly == nullptr){
              pforme->setAncre(pforme->getAncre().getTaille()+pforme->getEpaisseur()-1);
              }
            }
        }
      }
        break;
     case EZKeySym::g:{
      cout << endl;
      calque.afficher();
      char choix='n';
      do {
      cout << "---------------------Gestionnaire-de-calques-----------------------" << endl
           << "|| c : changer de calque                                         ||" << endl
           << "|| a : ajouter un calque                                         ||" << endl
           << "|| f : afficher/desafficher un calque                            ||" << endl
           << "|| s : supprimer un calque                                       ||" << endl
           << "|| d : fusionner deux calques                                    ||" << endl
           << "|| i : intervertir deux calques                                  ||" << endl
           << "|| n : sortir du gestionnaire de calques                         ||" << endl
           << "-------------------------------------------------------------------" << endl
           << "|_ Veuillez rentré votre choix :" << endl;
           cin >> choix;
           if(choix=='c'){
            cout << "|_ Choisir le calque qui va interagir avec les formes (1 a 10)" << endl;
            uint i;
            cin >> i;
            if (calque.getnbele()>i-1)
            {
              formes=calque.getCalques(i-1);
              calque.setSelectionne(i-1);
            }
            else
              cout << "|_ Ce calque n'existe pas" << endl;
           }
           else if(choix=='a'){
            calque.ajouter();
           }
           else if(choix=='f'){
            cout << "|_ Choisir un calque a afficher/desafficher (1 a 10)" << endl;
            uint j;
            cin >> j;
            calque.afficherOuDesafficher(j-1);
           }
           else if(choix=='s')
           {
             cout << "|_ Choisir un calque a supprimer (1 a 10)" << endl;
             uint k;
             cin >> k;
             calque.supprimer(k-1);
             formes=calque.getCalques(0);
             calque.setSelectionne(0);
           }
           else if(choix=='d')
           {
             cout << "|_ Choisir deux calques a fusionner (1 a 10)" << endl;
             uint i1, i2;
             cin >> i1 >> i2;
             calque.fusionner(i1-1, i2-1);
             formes=calque.getCalques(0);
             calque.setSelectionne(0);
           }
           else if(choix=='i')
           {
             cout << "|_ Choisir deux calques a intervertir (1 a 10)" << endl;
             uint i1, i2;
             cin >> i1 >> i2;
             calque.intervertir(i1-1, i2-1);
             if(calque.getSelectionne()==i1-1)
              formes=calque.getCalques(i1-1);
             else if(calque.getSelectionne()==i2-1)
              formes=calque.getCalques(i2-1);
           }
      cout << endl;
      calque.afficher();
      }while(choix != 'n');
      cout << endl;
      }break;
    case EZKeySym::z:
      if(pforme)
      {
        cout << "|_ Le périmètre de la forme est de : " << pforme->perimetre() << " pixels" << endl;
      }
     break;
    case EZKeySym::Up:
    {
      if(pforme) 
        {
          if(pforme->getAugmente())
            pforme->setDecalHaut(pforme->getDecalHaut() + 1);
          else
            pforme->setDecalHaut(pforme->getDecalHaut() - 1);
        }
    }break;
    case EZKeySym::Down:
    {
      if(pforme) 
        {
          if(pforme->getAugmente())
            pforme->setDecalBas(pforme->getDecalBas() + 1);
          else
            pforme->setDecalBas(pforme->getDecalBas() - 1);
        }
    }break;
    case EZKeySym::Left:
    {
      if(pforme) 
        {
          if(pforme->getAugmente())
            pforme->setDecalGauche(pforme->getDecalGauche() + 1);
          else
            pforme->setDecalGauche(pforme->getDecalGauche() - 1);
        }
    }break;
    case EZKeySym::Right:
    {
      if(pforme) 
        {
          if(pforme->getAugmente())
            pforme->setDecalDroite(pforme->getDecalDroite() + 1);
          else
            pforme->setDecalDroite(pforme->getDecalDroite() - 1);
        }
    }break;
    case EZKeySym::Alt_L:
    {
      if(pforme) 
        {
          pforme->setAugmente(!pforme->getAugmente());
        }
    }break;
    case EZKeySym::Alt_R:
    {
      if(pforme) 
        {
          pforme->setAugmente(!pforme->getAugmente());
        }
    }break;
    default:
      break;
    }
 sendExpose();
}
