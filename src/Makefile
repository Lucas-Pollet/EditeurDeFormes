CXX=g++
#CXX=clang++
CXXFLAGS=-g -Wall -O0
#CXXFLAGS=-O3

prog.exe : main.o MyWindow.o Point.o Forme.o Formes.o Rectangle.o ez-draw++.o Cercle.o Carre.o Ellipse.o Polygone.o Image.o Calque.o
	$(CXX) -o $@ $^ -lgdi32 -lmsimg32

main.o : main.cpp hpp/ez-draw++.hpp hpp/MyWindow.hpp hpp/Formes.hpp hpp/Forme.hpp hpp/Point.hpp
	$(CXX) $(CXXFLAGS) -c $<

MyWindow.o : MyWindow.cpp hpp/ez-draw++.hpp hpp/MyWindow.hpp hpp/Formes.hpp hpp/Forme.hpp \
 hpp/Point.hpp hpp/Ellipse.hpp hpp/Forme.hpp hpp/Cercle.hpp hpp/Rectangle.hpp hpp/Carre.hpp \
 hpp/Polygone.hpp hpp/Image.hpp hpp/Calque.hpp
	$(CXX) $(CXXFLAGS) -c $<
	
Point.o : Point.cpp hpp/Point.hpp hpp/ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<
	
Forme.o : Forme.cpp hpp/Forme.hpp hpp/Point.hpp hpp/ez-draw++.hpp hpp/Rectangle.hpp hpp/Ellipse.hpp hpp/Polygone.hpp hpp/Carre.hpp hpp/Cercle.hpp Image.o Calque.o
	$(CXX) $(CXXFLAGS) -c $<
	
Formes.o : Formes.cpp hpp/ez-draw++.hpp hpp/Formes.hpp hpp/Forme.hpp hpp/Point.hpp
	$(CXX) $(CXXFLAGS) -c $<
	
Rectangle.o : Rectangle.cpp hpp/Rectangle.hpp hpp/Forme.hpp hpp/Point.hpp hpp/ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<
	
ez-draw++.o : ez-draw++.cpp hpp/ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<

Carre.o : Carre.cpp hpp/Carre.hpp hpp/Forme.hpp hpp/Point.hpp hpp/ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<

Cercle.o : Cercle.cpp hpp/Cercle.hpp hpp/Forme.hpp hpp/Point.hpp hpp/ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<

Ellipse.o : Ellipse.cpp hpp/Ellipse.hpp hpp/Forme.hpp hpp/Point.hpp hpp/ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<

Polygone.o : Polygone.cpp hpp/Polygone.hpp hpp/Forme.hpp hpp/Point.hpp hpp/ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<

Image.o : Image.cpp hpp/Image.hpp hpp/Forme.hpp hpp/Point.hpp hpp/ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<
	
Calque.o : Calque.cpp hpp/Calque.hpp hpp/Forme.hpp hpp/Point.hpp hpp/ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<

