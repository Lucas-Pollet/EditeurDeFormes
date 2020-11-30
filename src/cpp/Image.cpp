/**
 * \file Image.cpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Déclaration de la classe Image
 *
 */

using namespace std;

#include "Image.hpp"

Image::Image(uint x_, uint y_, const char * path_)
: Forme(ez_white, x_, y_), path(path_), image(nullptr){
    EZImage tempimage(path);
    image = new EZImage(tempimage);
    savepath = std::string(path);
}

Image::Image(const Image & orig) 
: Image(orig.getAncre().getX(), orig.getAncre().getY(), orig.path)
{}

Image::Image(istream& is)
: Forme(is), path(nullptr), image(nullptr), alpha(true), factor(1){
    is >> savepath >> alpha >> factor;
    path = savepath.c_str();
    EZImage tempimage(path);
    image = tempimage.scale(factor);
    path = savepath.c_str();
}

Image::~Image()
{ 
    delete image;
}

void Image::dessiner(EZWindow &w, bool isActive) const{
    Forme::dessiner(w, isActive);
    image->setAlpha(getAlpha());
    image->paint(w, getAncre().getX(), getAncre().getY());
}

void Image::changeFactor(){
    path = savepath.c_str();
    EZImage tempimage(path);
    delete image;
    image = tempimage.scale(factor);
    path=savepath.c_str();
}

double Image::perimetre() const
{ 
    return image->getHeight()*2+image->getWidth()*2; 
}

ostream& Image::ecrire(ostream &os) const{
    os << "Image" << " ";
    Forme::ecrire(os);
    os << " " << savepath << " " << alpha << " " << factor << endl;
    return os;
}
