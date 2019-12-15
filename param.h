#include <bits/stdc++.h>
using namespace std;
#pragma once
class Param {
    private:
        bool doEncode=true;
        string output_name="a.lzm";
        string input_name;
    public:
        void  output_file(char const *arg);
        string  output_file();
        void  input_file(char const *arg);
        string  input_file();
        void  doDecompression();
        void  displayOptions();
};