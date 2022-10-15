#include "gui.h"

Boton::Boton(CImg<unsigned char>* img, CImgDisplay* ventana, int x, int y, int opacidad, int w, int h , \
	const unsigned char color_borde[3], const unsigned char color_relleno[3])
{
	this->canvas = img;
	this->ventana = ventana;
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;

	this->opacidad = opacidad;

	for(int i=0;i<3;i++)
	{
		borde[i] = color_borde[i];
		relleno[i] = color_relleno[i];
	}


	x1 = x - w / 2;
	x2 = x + w / 2;
	y1 = y - h / 2;
	y2 = y + h / 2;

}

void Boton::pintar()
{
	canvas->draw_rectangle(x1 - 1, y1 - 1, x2 + 2, y2 + 2, borde, 1);
	canvas->draw_rectangle(x1, y1, x2, y2, relleno, opacidad);
}

bool Boton::clic()
{
	int click_x = ventana->mouse_x();
	int click_y = ventana->mouse_y();
	if ((click_x>x1 and click_x<x2) and (click_y > y1 and click_y < y2))
	{
		return true;
	}
	return false;
}

bool Boton::refrescar()
{
	pintar();
	return clic();
}

