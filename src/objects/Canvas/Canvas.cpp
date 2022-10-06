#include "Canvas.h"

#include <string>
#include <math.h>
#include <fstream>
void Canvas::createDimensions(const float& w, const float& h)
{
	can.height = h;
	can.width = w;
	Color col;
	std::vector<color> v(w, col.createColor(0, 0, 0));
	for (int i = 0; i <= h; i++)
	{
		can.pixelMap.resize(h, v);
	}

}

std::string Canvas::canvas_to_ppm()
{
	int width, height;
	width = (int)can.width;
	height = (int)can.height;
	std::string ppmH = "P3\n" + std::to_string(width) + " " + std::to_string(height) + "\n255";
	//make_all_pixels(1, 0.8, 0.6);
	write_ppm();
	ppmH = ppmH + pixelMap + "\n";
	return ppmH;
}
int Canvas::convert_color_scale(float rgb) 
{
	int color = round(rgb * 255.0);
	if (color > 255)
	{
		color = 255;
	}
	if (color < 0)
	{
		color = 0;
	}
	return color;
}

void Canvas::write_ppm()
{
	for (const auto& str : can.pixelMap)
	{
		for (const auto& h : str)
		{
			pixelMapString = pixelMapString + std::to_string(convert_color_scale(h.red));
			append_lines();
			pixelMapString = pixelMapString + std::to_string(convert_color_scale(h.blue));
			append_lines();
			pixelMapString = pixelMapString + std::to_string(convert_color_scale(h.green));
			append_lines();
		}
		pixelMap = pixelMap + "\n" + pixelMapString;
		pixelMapString = "";
	}
}

void Canvas::write_to_ppm()
{
	std::ofstream ppm("image.ppm");
	ppm << canvas_to_ppm();
	ppm.close();
}

void Canvas::append_lines()
{
	if (pixelMapString.length() >= 67)
	{		
		pixelMap = pixelMap +  "\n" + pixelMapString;
		pixelMapString = "";
	}
	else {
		pixelMapString = pixelMapString + " ";
	}
}

void Canvas::pixel_at( const float& w, const float& h) 
{
	const color c1 = can.pixelMap[h][w];
	std::cout << c1.red << ":" << c1.blue << ":" << c1.green << std::endl;
}

void Canvas::write_pixel(const color& c1, const float& w, const float& h)
{
	can.pixelMap[h][w] = c1;
}


void Canvas::make_all_pixels(const float& r, const float& b, const float& g) {
	Color col;
	for (int i = 0; i <= can.height-1; i++) {
		for (int j = 0; j <= can.width-1; j++)
		{
			write_pixel(col.createColor(1, 0.8, 0.6),j, i);
		}
	}
}