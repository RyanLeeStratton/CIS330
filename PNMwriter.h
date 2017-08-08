#ifndef PNMWRITER_H
#define PNMWRITER_H

#include <sink.h>

class PNMwriter : public sink
{
	public:
	PNMwriter();
	void Write(char *filename2);
	
	protected:
	Image imgWrite;	

	
};

#endif
