#pragma once

#include "opencv2/highgui/highgui.hpp"

#include "display.h"

using namespace cv;

class DisplayWithOpenCV : public Display
{
	Mat A;
public:
	DisplayWithOpenCV(int width = 640, int height = 480);
	virtual ~DisplayWithOpenCV(void);

	virtual void setPixel(int x, int y, Colour colour);
	virtual void show();
};