#include <image.h>
#include <fstream>
#include <stdio.h>
#include <source.h>
#include <iostream>

using namespace std;

Image::Image()
{
	sourcePointer = NULL;
}

void
Image::Update()
{
	//if (sourcePointer != NULL)
		sourcePointer->Update();
	//else cerr << "shouldn't happen" << endl;
}
void
Image::setSource(source *setinput)
{
	sourcePointer = setinput;
}
Image::Image(int W, int H, Pixel &buff)
{
	width = W;
	height = H;
	buffer = new Pixel[width*height];
	buffer = &buff;
}

Image::Image(const Image &copy)
{
	sourcePointer = copy.sourcePointer;

	buffer = new Pixel[width*height];
	*buffer = *copy.buffer;
}
void Image::setWidth(int w)
{
	width = w;
}

void Image::setHeight(int h)
{
	height = h;
}

void Image::setPixel(Pixel *pixelInput)
{
	buffer = pixelInput;		
}

int	
Image::getWidth()
{
	return width;
}

int
Image::getHeight()
{
	return height;
}

Pixel Image::getPixel(int location)
{
	return buffer[location];
}

Pixel *Image::getPixelBuffer()
{
	
	return buffer;
}

/*void Image::readData(FILE *f)
{
	
	char magicNum[2];
	char maxval;
	
	fscanf(f, " %s\n%d\n%d\n%d\n",magicNum, &width, &height, &maxval);
	buffer = new Pixel[width*height];
	fread(buffer, sizeof(char)*3, width*height, f);
}

void Image::setData(FILE *outfile)
{
        int outMaxVal = 255;

        fprintf(outfile, "P6\n%d\n%d\n%d\n", width, height, outMaxVal);
        fwrite(buffer,sizeof(unsigned char)*3,width*height,outfile);
}
*/
/*void Image::shrink(Image &img1)
{
	Pixel *temp;
	temp = new Pixel[(width)*(height)];
	int count, j = 0;

	for(int i = 0; i < (width)*(height); i++)
	{
		temp[i] = img1.buffer[(i*2)+(j*width*2)];
		count++;
		
		if( count == ((width) -1))
		{
			count = 0;
			j++;
		}	
	
	}
	buffer = temp;
	
}

void Image::LRCat(Image &img1, Image &img2)
{
	width = img1.getWidth()+img2.getWidth();
	height = img1.getHeight();

	Pixel *temp2 = new Pixel[(width)*height];	

	for(int h = 0; h < img1.getHeight(); h++)
	{
		for(int w = 0; w < img1.getWidth(); w++)
		{
                        int outIndex = h*width+w;
                        int inIndex =  h*img1.getWidth()+w;
                        temp2[outIndex] = img2.getPixel(inIndex);
		}
	}
		
			
	for(int w2 = 0; w2 < img2.getWidth(); w2++)
	{
		for(int h2 = 0; h2< img2.getHeight(); h2++)
		{
			int Out = h2*width+w2+img2.getWidth();
			int In =  h2*img1.getWidth()+w2;
			temp2[Out] = img1.getPixel(In);
		}
		
	}
	buffer = temp2;
}

void Image::TBCat(Image &img1, Image &img2)
{
	
	int TBi, val = 0;
	int first,second = 0;
	Pixel *temp3 = NULL;

	width = img1.getWidth();
	height = img1.getHeight()+img2.getHeight();
	
	temp3 = new Pixel[width*height];

	for(TBi = 0; TBi < width*height; TBi++)
	{
		if(val < (width*height*0.5))
		{
			temp3[TBi] = img1.getPixel(first);
			first++;
			val++;
		}

		else
		{
			temp3[TBi] = img2.getPixel(second);
			second++;
		}
	
	}

	buffer = temp3;
}

void Image::blend(Image &img7, Image &img1, float k)
{
	Pixel *temp4;

	width = img7.getWidth();
	height = img7.getHeight();
	
	temp4 = new Pixel[width*height];

	for(int loop = 0; loop < width*height; loop++)
	{
		temp4[loop].red = ( (img7.getPixel(loop).red*k)+( (img1.getPixel(loop).red*(1-k))));

		temp4[loop].green = ( (img7.getPixel(loop).green*k)+( (img1.getPixel(loop).green*(1-k))));

		temp4[loop].blue = ( (img7.getPixel(loop).blue*k)+( (img1.getPixel(loop).blue*(1-k))));

	}
	
	buffer = temp4;
}


Image::GetOutput()
{
}
*/
