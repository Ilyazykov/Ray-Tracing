#pragma once

#include "opencv2/highgui/highgui.hpp"

#include "display.h"

using namespace cv;

class DisplayWithOpenCV : public Display
{
	Mat A;
public:
	DisplayWithOpenCV(int width = 640, int height = 480)
	{
		this->width = width;
		this->height = height;

		A.create(height, width, CV_8UC3);
	}
	virtual ~DisplayWithOpenCV(void) {}

	virtual void setPixel(int x, int y, Colour colour)
	{
		uchar* p;
		p = A.ptr<uchar>(x);
		p[y*3] = colour.getBlue();
		p[y*3 + 1] = colour.getGreen();
		p[y*3 + 2] = colour.getRed();
	}

	virtual void show()
	{
		imshow("Window", A);
		waitKey();
	}
};