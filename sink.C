#include <stdio.h>
#include <sink.h>
#include <image.h>

sink::sink()
{
	Input1 = NULL;
	Input2 = NULL;
}

void
sink::SetInput(Image *SetInput1)
{
	Input1 = SetInput1;
}

void
sink::SetInput2(Image *SetInput2)
{
	Input2 = SetInput2;
}
