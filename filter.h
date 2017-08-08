#include <sink.h>
#include <source.h>

#ifndef FILTER_H
#define	FILTER_H


class filter : public sink, public source
{
	public:
	virtual void Update();
	//virtual char *SourceName() {"h";};
};

#endif
