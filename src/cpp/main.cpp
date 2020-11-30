/**
 * \file main.cpp
 * \author Masset Eliot - Correia-Mateus Dorian - Pollet Lucas
 *
 * \brief Programme principal
 *
 */
#include <iostream>

using namespace std;

#include "../hpp/ez-draw++.hpp"
#include "../hpp/MyWindow.hpp"

int main()
{
 EZDraw ezDraw;
 MyWindow myWindow(800,500,"Des formes");

 ezDraw.mainLoop();
 
 return 0;
}
