#include <filters.h>
#include <source.h>
#include <stdio.h>
#include <iostream>

using namespace std;

Blender::Blender()
{

}

void 
Blender::Execute()
{

	//fprintf(stderr, "blender\n");

	Pixel *temp4;
	

        int Blend_Width = Input1->getWidth();
        int Blend_Height = Input1->getHeight();

        temp4 = new Pixel[Blend_Width*Blend_Height];

	output.setWidth(Blend_Width);
	output.setHeight(Blend_Height);

        for(int loop = 0; loop < Blend_Width*Blend_Height; loop++)
        {
                temp4[loop].red = ( (Input1->getPixel(loop).red*Blend_Factor)+( (Input2->getPixel(loop).red*(1-Blend_Factor))));

                temp4[loop].green = ( (Input1->getPixel(loop).green*Blend_Factor)+( (Input2->getPixel(loop).green*(1-Blend_Factor))));

                temp4[loop].blue = ( (Input1->getPixel(loop).blue*Blend_Factor)+( (Input2->getPixel(loop).blue*(1-Blend_Factor))));

        }

        output.setPixel(temp4);
	
	//output = BlenderImg;	
			
}
void
Blender::SetFactor(float BlendFactor)
{
	
	Blend_Factor = BlendFactor;
}

//Image *Blender::GetOutput()
//{
//	return &BlenderImg;
//}

Shrinker::Shrinker()
{

}

void
Shrinker::Execute()
{

	//fprintf(stderr, "shrinker\n");

	Pixel *temp = NULL;
	
	int shrink_Width = Input1->getWidth()/2;
	int shrink_Height = Input1->getHeight()/2;
	temp = new Pixel [shrink_Width*shrink_Height];


	//printf("SHRINK WIDTH %d\n", shrink_Width);
	//printf("SHRINK HEIGHT %d\n", shrink_Height);
	
	output.setWidth(shrink_Width);
	output.setHeight(shrink_Height);
	output.setPixel(Input1->getPixelBuffer());

	int i = 0; 
	int count = 0;
	int j = 0;

	for(i = 0; i < (shrink_Width*shrink_Height); i++)
	{
		temp[i] = output.getPixel((i*2)+(j*shrink_Width*2));
		count++;

		if( count == ((shrink_Width) - 1))
		{
			count = 0;
			j++;
		}

	}

	//cerr << shrink_Width << endl;
	//cerr << shrink_Height << endl;
	
	output.setPixel(temp);
	
	//output = shrinkImg;
	//fprintf(stderr,"done shrinking\n");
	
}

//Image *Shrinker::GetOutput()
//{	
//	return &shrinkImg;
//}

TBConcat::TBConcat()
{
}

void
TBConcat::Execute()
{

	//fprintf(stderr,"tbconcat\n");
	
	int TBi, val = 0;
        int first,second = 0;
        Pixel *temp3 = NULL;

        int TB_Width = Input1->getWidth();
        int TB_Height = Input1->getHeight()+Input2->getHeight();

        temp3 = new Pixel[TB_Width*TB_Height];

	output.setWidth(TB_Width);
	output.setHeight(TB_Height);

        for(TBi = 0; TBi < TB_Width*TB_Height; TBi++)
        {
                if(val < (TB_Width*TB_Height*0.5))
                {
                        temp3[TBi] = Input1->getPixel(first);
                        first++;
                        val++;
                }

                else
                {
                        temp3[TBi] = Input2->getPixel(second);
                        second++;
                }

        }

        output.setPixel(temp3);

	//output = TBConcatImg;
}

//Image *TBConcat::GetOutput()
//{
//	return &TBConcatImg;
//}

LRConcat::LRConcat()
{
}

void
LRConcat::Execute()
{

	//fprintf(stderr,"lrconcat\n");

	int LR_Width = Input1->getWidth()+Input2->getWidth();
        int LR_Height = Input1->getHeight();

        Pixel *temp2 = new Pixel[(LR_Width)*LR_Height];

	output.setWidth(LR_Width);
	output.setHeight(LR_Height);

        for(int h = 0; h < Input1->getHeight(); h++)
        {
                for(int w = 0; w < Input1->getWidth(); w++)
                {
                        int outIndex = h*LR_Width+w;
                        int inIndex =  h*Input1->getWidth()+w;
                        temp2[outIndex] = Input2->getPixel(inIndex);
                }
        }


        for(int w2 = 0; w2 < Input2->getWidth(); w2++)
        {
                for(int h2 = 0; h2< Input2->getHeight(); h2++)
                {
                        int Out = h2*LR_Width+w2+Input2->getWidth();
                        int In =  h2*Input1->getWidth()+w2;
                        temp2[Out] = Input1->getPixel(In);
                }

        }

        output.setPixel(temp2);
	
	//output = LRConcatImg;
}

//Image *LRConcat::GetOutput()
//{
//	return &LRConcatImg;
//}

//filters::filters()
//{
//
//
