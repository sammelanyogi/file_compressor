#include "lzm.h"
void Lzm::encode(char * buffer, int length){
    unsigned short code = 256;
    vector<unsigned short> output_code; 
    // string k = "a";
    // cout << k + *buffer << endl;
    unordered_map<string, int> table; 
    for (int i = 0; i <= 255; i++) { 
        string ch = ""; 
        ch += char(i); 
        table[ch] = i; 
    } 
    string income = "", joined = "";
    income = income + buffer[0];
    for(int i=0; i<length; i++){
        
        if (i != length - 1) 
            joined =joined + buffer[i+1];
        string temp = income+joined;
        if (table.find(temp) != table.end()) { 
            income = temp; 
        } 
        else {
            output_code.push_back(table[income]); 
            table[temp] = code; 
            code++; 
            income = joined; 
        } 
        joined="";
    }
    output_code.push_back(table[income]); 
    for (int i = 0; i < output_code.size(); i++) { 
        cout << output_code[i] << " "; 
    } 
}
