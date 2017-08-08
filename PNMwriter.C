#include <PNMwriter.h>
#include <image.h>
#include <sink.h>
#include <stdio.h>
#include <stdio.h>

PNMwriter::PNMwriter()
{
}
void
PNMwriter::Write(char *filename2)
{
	FILE *output;
	int outMaxVal = 255;
	int width = Input1->getWidth();
	int height = Input1->getHeight();

	Pixel *WritePixel;

	
	fprintf(stderr, "writing\n");
		
	output = fopen(filename2, "wb");

	WritePixel = Input1->getPixelBuffer();
	//printf("WRITE %d\n", width);

	fprintf(output, "P6\n%d %d\n%d\n", width, height, outMaxVal);
	fwrite(WritePixel, sizeof(unsigned char)*3, width*height, output);
}
