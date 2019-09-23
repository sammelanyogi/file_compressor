#include <iostream>
#include<cstring>
using namespace std;

class Param {
private:
	bool doEncode = true;
	string output_name = "a.lzm";
	string input_name = "";
public:
	void output_file(char const *arg){
		this->output_name = (string) arg;
	}
	void input_file(char const *arg){
		this->input_name = (string) arg;
	}
	void doDecompression(){
		doEncode = false;
	}
	void displayOptions(){
		cout << doEncode << " " << input_name<<" "<< output_name << endl;
	}


};
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
	options.displayOptions();

	return 0;
}