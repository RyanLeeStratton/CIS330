#ifndef PNMREADER_H
#define PNMREADER_H 
#include <source.h>

class PNMreader : public source
{

	public:
	   PNMreader();
	   PNMreader(char *filename);
	   //virtual Image *GetOutput();
	   virtual ~PNMreader();
	   virtual void Execute();
	   //virtual const char *getSource() {"PNMreader";};	
	   virtual char const *SourceName() const {"PNMreader";};
	protected:
	
	char *PNM_filename;	
	char magicNum[2];
	int width;
	int height;
	int maxval;

};

#endif
