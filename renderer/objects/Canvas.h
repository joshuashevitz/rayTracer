#pragma once

#include "core/Color.h"

#include <iostream>
#include <vector>


struct canvas {
	float width;
	float height;
	std::vector<std::vector<color>> pixelMap;
};

class Canvas
{
public: 
	Canvas(const float& w, const float& h) {
		createDimensions(w, h);
	};
	~Canvas() = default;
	std::string canvas_to_ppm();
	void createDimensions(const float& w, const float& h);
	void write_pixel(const color& c1, const float& w, const float& h);
	void pixel_at(const float& w, const float& h);
	void write_ppm();
	void append_lines();
	void make_all_pixels(const float& r,const float& b,const float& g);
	void write_to_ppm();
	void printPixelMapSize() {
		
		std::cout << can.pixelMap[0].size() << " by " << can.pixelMap.size() << std::endl;
		
	}
	float _get_height() {
		return can.height;
	}
	float _get_width() {
		return can.width;
	}
	int convert_color_scale(float rgb);
private:
	canvas can;
	std::string pixelMapString, pixelMap;
};