CXX=g++
#CXX=clang++
CXXFLAGS=-g -Wall -O0 -D_WIN32
#CXXFLAGS=-O3

prog.exe : main.o MyWindow.o Point.o Forme.o Formes.o Rectangle.o ez-draw++.o Cercle.o Carre.o Ellipse.o Polygone.o Image.o Calque.o
	$(CXX) -o $@ $^ -lgdi32 -lmsimg32

main.o : main.cpp ez-draw++.hpp MyWindow.hpp Formes.hpp Forme.hpp Point.hpp
	$(CXX) $(CXXFLAGS) -c $<

MyWindow.o : MyWindow.cpp ez-draw++.hpp MyWindow.hpp Formes.hpp Forme.hpp \
 Point.hpp Ellipse.hpp forme.hpp Cercle.hpp Rectangle.hpp Carre.hpp \
 Polygone.hpp Image.hpp Calque.hpp
	$(CXX) $(CXXFLAGS) -c $<
	
Point.o : Point.cpp Point.hpp ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<
	
Forme.o : Forme.cpp Forme.hpp Point.hpp ez-draw++.hpp Rectangle.hpp Ellipse.hpp Polygone.hpp Carre.hpp Cercle.hpp Image.o Calque.o
	$(CXX) $(CXXFLAGS) -c $<
	
Formes.o : Formes.cpp ez-draw++.hpp Formes.hpp Forme.hpp Point.hpp
	$(CXX) $(CXXFLAGS) -c $<
	
Rectangle.o : Rectangle.cpp Rectangle.hpp Forme.hpp Point.hpp ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<
	
ez-draw++.o : ez-draw++.cpp ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<

Carre.o : Carre.cpp Carre.hpp Forme.hpp Point.hpp ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<

Cercle.o : Cercle.cpp Cercle.hpp forme.hpp Point.hpp ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<

Ellipse.o : Ellipse.cpp Ellipse.hpp forme.hpp Point.hpp ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<

Polygone.o : Polygone.cpp Polygone.hpp Forme.hpp Point.hpp ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<

Image.o : Image.cpp Image.hpp Forme.hpp Point.hpp ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<
	
Calque.o : Calque.cpp Calque.hpp Forme.hpp Point.hpp ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<

