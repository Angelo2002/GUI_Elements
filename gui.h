#pragma once
#include "CImg.h"

using  namespace cimg_library;
const int default_width = 50;
const int default_height = 20;
const unsigned char negro[] = { 0,0,0 };
const unsigned char blanco[] = { 255,255,255};

class Boton
{
	int x,x1,x2;
	int y,y1,y2;
	int w;
	int h;
	int opacidad;
	unsigned char borde[3];
	unsigned char relleno[3];

	char text[150];
	CImg<unsigned char>* canvas;
	CImgDisplay* ventana;
public:
	Boton(CImg<unsigned char>*, CImgDisplay*,int,int,int opacidad=1,int w=default_width,int h=default_height,\
		 const unsigned char color_borde[3] = negro, const unsigned char color_relleno[3] = blanco);
	void pintar();
	bool clic();
	bool refrescar();
};