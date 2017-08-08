#include <source.h>
#include <PNMreader.h>
#include <stdio.h>
#include <image.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#ifndef PNMREADER_C
#define PNMREADER_C

PNMreader::PNMreader()
{
}

PNMreader::~PNMreader()
{

}


PNMreader::PNMreader(char *filename)
{
	
	char *name;
	name = new char[20];

	name = filename;

	PNM_filename = name;
	//PNM_filename = new char[strlen(name)+1];
}

void
PNMreader::Execute()
{
	//cerr << "This should be happening!!!!!!!!!!!!" << endl;
	FILE *input;
	Pixel *buffer;

	//Image img;

	input = fopen(PNM_filename, "rb");

	fscanf(input, " %s\n%d\n%d\n%d\n", magicNum, &width, &height, &maxval);
	buffer = new Pixel [width*height];
	fread(buffer, sizeof(char)*3, width*height, input);
	
	//printf("READ IN PNM %d\n", width);

	output.setPixel(buffer);	
	output.setWidth(width);
	output.setHeight(height);
	
	//output = img;
	
	//printf("SOURCE in PNM %d\n", output.getWidth());

}


//Image *PNMreader::GetOutput()
//{
//	return &output;
//}
#endif
