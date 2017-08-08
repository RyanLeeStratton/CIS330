#include <string>
#include <source.h>
#ifndef IMAGE_H
#define IMAGE_H

class source;

typedef struct
{

	unsigned char red;
	unsigned char green;
	unsigned char blue;
} Pixel;

class Image
{
    public:
	Image();
	void Update();
	Image(int w, int h, Pixel &buffer);
	Image(const Image &copy);
	void setWidth(int w);
	void setHeight(int h);
	void setPixel(Pixel *pixelInput);
	void setSource(source *input); 
	int getWidth();
	int getHeight();
        Pixel getPixel(int location);
	Pixel *getPixelBuffer();
	//void readData(FILE *f);
	//void setData(FILE *outfile);
	//void shrink(Image &img1);
	//void LRCat(Image &img1, Image &img2);
	//void TBCat(Image &img1, Image &img2);
	//void blend(Image &img7, Image &img1, float k);

	//GetOutput();

    protected:	
	source *sourcePointer;

    //private:
	Pixel *buffer;
	int width;
	int height;
	
};

#endif
