#include <source.h>
#include <iostream>
#include <stdio.h>
#include <iostream>

using namespace std;

source::source()
{
	//cerr << "setting source\n" << endl;
	output.setSource(this);
}


Image *source::GetOutput()
{
	return &output;
}
void
source::Update()
{
	Execute();
}
