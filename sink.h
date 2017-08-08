
#include <image.h> 
#ifndef SINK_H
#define SINK_H
#include <iostream>

class sink
{
	public:
	sink();
	virtual void SetInput(Image *Input1);
	virtual void SetInput2(Image *Input2);
	protected:
	Image *Input1;
	Image *Input2;
};

#endif
