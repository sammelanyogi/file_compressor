#include "param.h"

void Param::output_file(char const *arg){
    this->output_name = (string) arg;
}
string Param::output_file(){
    return this->output_name;
}
void Param::input_file(char const *arg){
    this->input_name = (string) arg;
}
string Param::input_file(){
    return this->input_name;
}
void Param::doDecompression(){
    doEncode = false;
}
void Param::displayOptions(){
    cout << doEncode << " " << input_name<<" "<< output_name << endl;
}

