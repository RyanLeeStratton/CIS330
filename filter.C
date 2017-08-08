#include <source.h>
#include <filter.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void
filter::Update()
{
		//fprintf(stderr, "filter update input1\n");
	
	const char *name = SourceName();

	//printf("%s\n", SourceName());
	//sprintf(name, "enter %s ", SourceName());
	printf("%s\n", &name);

		Input1->Update();
	if(Input2 != NULL){
		//fprintf(stderr, "filter update input2\n");
		Input2->Update();
	}

	//fprintf(stderr, "going to execute\n");
	Execute();

}


//const char
//*filter::SinkName() {return FilterName();};
