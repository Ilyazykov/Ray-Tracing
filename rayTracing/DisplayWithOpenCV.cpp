#include "DisplayWithOpenCV.h"

DisplayWithOpenCV::DisplayWithOpenCV( int width /*= 640*/, int height /*= 480*/ )
{
	this->width = width;
	this->height = height;

	A.create(height, width, CV_8UC3);
}

DisplayWithOpenCV::~DisplayWithOpenCV( void )
{

}

void DisplayWithOpenCV::setPixel( int x, int y, Colour colour )
{
	uchar* p;
	p = A.ptr<uchar>(y);
	p[x*3] = colour.getBlue();
	p[x*3 + 1] = colour.getGreen();
	p[x*3 + 2] = colour.getRed();
}

void DisplayWithOpenCV::show()
{
	imshow("Window", A);
	waitKey();
}
