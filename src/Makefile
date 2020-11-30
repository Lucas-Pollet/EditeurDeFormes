CXX=g++
#CXX=clang++
CXXFLAGS=-g -Wall -O3
#CXXFLAGS=-O3

prog : main.o MyWindow.o Point.o Forme.o Formes.o Rectangle.o ez-draw++.o Cercle.o Carre.o Ellipse.o Polygone.o Image.o Calque.o
	$(CXX) -o $@ $^ -L/usr/X11R6/lib -lX11 -lXext 

main.o : cpp/main.cpp hpp/ez-draw++.hpp hpp/MyWindow.hpp hpp/Formes.hpp hpp/Forme.hpp hpp/Point.hpp
	$(CXX) $(CXXFLAGS) -c $<

MyWindow.o : cpp/MyWindow.cpp hpp/ez-draw++.hpp hpp/MyWindow.hpp hpp/Formes.hpp hpp/Forme.hpp \
 hpp/Point.hpp hpp/Ellipse.hpp hpp/Forme.hpp hpp/Cercle.hpp hpp/Rectangle.hpp hpp/Carre.hpp \
 hpp/Polygone.hpp hpp/Image.hpp hpp/Calque.hpp
	$(CXX) $(CXXFLAGS) -c $<
	
Point.o : cpp/Point.cpp hpp/Point.hpp hpp/ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<
	
Forme.o : cpp/Forme.cpp hpp/Forme.hpp hpp/Point.hpp hpp/ez-draw++.hpp hpp/Rectangle.hpp hpp/Ellipse.hpp hpp/Polygone.hpp hpp/Carre.hpp hpp/Cercle.hpp Image.o Calque.o
	$(CXX) $(CXXFLAGS) -c $<
	
Formes.o : cpp/Formes.cpp hpp/ez-draw++.hpp hpp/Formes.hpp hpp/Forme.hpp hpp/Point.hpp
	$(CXX) $(CXXFLAGS) -c $<
	
Rectangle.o : cpp/Rectangle.cpp hpp/Rectangle.hpp hpp/Forme.hpp hpp/Point.hpp hpp/ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<
	
ez-draw++.o : cpp/ez-draw++.cpp hpp/ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<

Carre.o : cpp/Carre.cpp hpp/Carre.hpp hpp/Forme.hpp hpp/Point.hpp hpp/ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<

Cercle.o : cpp/Cercle.cpp hpp/Cercle.hpp hpp/Forme.hpp hpp/Point.hpp hpp/ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<

Ellipse.o : cpp/Ellipse.cpp hpp/Ellipse.hpp hpp/Forme.hpp hpp/Point.hpp hpp/ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<

Polygone.o : cpp/Polygone.cpp hpp/Polygone.hpp hpp/Forme.hpp hpp/Point.hpp hpp/ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<

Image.o : cpp/Image.cpp hpp/Image.hpp hpp/Forme.hpp hpp/Point.hpp hpp/ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<
	
Calque.o : cpp/Calque.cpp hpp/Calque.hpp hpp/Forme.hpp hpp/Point.hpp hpp/ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<

