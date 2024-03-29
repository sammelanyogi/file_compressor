#include <bits/stdc++.h>
#include <fstream>

#include "lzm.h"
#include "param.h"

using namespace std;

void displayHelp(){
	cout << "Usage:"<< endl << endl 
	<< "./a.out [inputfile] [options] [outputfile]" << endl<<
	"options:" << endl <<
	"-o     output" << endl <<
	"-d     decompress (give filename to be decompressed and name of required file)" << endl <<
	"-h     help" << endl ;
}
int main(int argc, char const *argv[])
{
	Param options;
	if(strcmp(argv[1], "-h")==0){
		displayHelp();
	}
	else{
		options.input_file(argv[1]);
	}
	for (unsigned i = 1; i< argc; i++){
		if ( strcmp(argv[i],"-o") == 0 || strcmp(argv[i],"-O") == 0 ){
			if(i+1==argc){
				cout<< "output filename not given." << endl;
			}
			else {
				options.output_file(argv[i+1]);
			}
			
		}
		if (strcmp(argv[i],"-d") == 0 || strcmp(argv[i],"-D") == 0){
			options.doDecompression();
			if (i+1==argc){
				cout << "Arguements not given properly." << endl;
			}
			options.input_file(argv[i+1]);
			if(argc<=i+2){
				options.output_file("nah");
			}
			else {
				options.output_file(argv[i+2]);
			}

		}
	}
	ifstream in;
	in.open(options.input_file());

	in.seekg(0, in.end);
	int length = in.tellg();
	in.seekg(0, in.beg);

	char* buffer = new char [length];
	
	in.read (buffer , length);
	in.close();
	Lzm lzm;
	lzm.encode(buffer, length);
	delete[] buffer;
	return 0;
}

