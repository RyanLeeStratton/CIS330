#ifndef SOURCE_H
#define SOURCE_H
#include <image.h>

class source 
{
	public:
	source();
	virtual Image *GetOutput();
	virtual void Update();
	virtual void Execute() = 0;
	virtual char const *SourceName() const {"source";};
	protected:
	Image output; 

};

#endif
