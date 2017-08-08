
#include <source.h>
#include <sink.h>
#ifndef FILTERS_H
#define FILTERS_H
#include <filter.h>


//class filters : public filter 
//{

  //      public:
    //    filters();
//};


class Shrinker : public filter
{
	public:
	Shrinker();
	//virtual Image *GetOutput();
	virtual void Execute();
	virtual char const *SourceName() const {"Shrinker";};	

	protected:
	//Image  shrinkImg;
	//int shrink_Width;
	//int shrink_Height;
};

class LRConcat : public filter
{
	public:
	LRConcat();
	//virtual Image *GetOutput();
	virtual void Execute();
	virtual char const *SourceName() const {"LRConcat";};	

	protected:
	//Image LRConcatImg;
	//int LR_Width;
	//int LR_Height;

};

class TBConcat : public filter
{
	public:
	TBConcat();
	virtual void Execute();
	virtual char const *SourceName() const {"TBConcat";};
	//virtual Image *GetOutput();

	protected:
	//Image TBConcatImg;
	//int TB_Width;
	//int TB_Height;
};

class Blender : public filter
{
	public:
	Blender();
	//virtual Image *GetOutput();
	virtual void Execute();
	void SetFactor(float factor);
	virtual char const *SourceName() const {"Blender";};

	protected:
	//Image BlenderImg;
	//int Blend_Width;
	//int Blend_Height;
	float Blend_Factor;

};

#endif
