#include <iostream>
#include "gui.h"
using namespace cimg_library;
int main()
{
    CImgDisplay window_foto;
	CImg<unsigned char> img(300,200);
    const unsigned char azul[] = { 0, 0, 255 };
    img.draw_arrow(3, 5, 20, 50,azul);
    window_foto.display(img);
    Boton b1(&img, &window_foto, 40, 30);
    while(!window_foto.is_closed())
    {
        window_foto.wait(100);
        if(window_foto.button()==1)
        {
	        std::cout<<b1.refrescar();
        }
        window_foto.display(img);
    }
    std::cout << "Hello World!\n";
}

