#include <iostream>
#include <string>
using namespace std;

bool operand(char a){
int asci = (int)a;
if (asci >= 48 && asci <= 57){
    return true;
} else {return false;}

}

bool is_operator(char a){
int asci = (int)a;
if (!(asci >= 48 && asci <= 57)){
    return true;
} else {return false;}

}
    
int main(){
string infix2,simpan[100],infix;
int jumlah = 0,panjang;
getline(cin,infix2);

panjang = infix2.length();
for(int i = 0; i<panjang;i++){
    if (infix2[i] != ' '){
        infix += infix2[i];
    }
}
    
if (is_operator(infix[i])){
    if(is_operator(infix[i]) && infix[i+1] == '-' && infix[i+2] == '('){
        simpan[jumlah+1] = infix[i+1];
        simpan[jumlah+2] = '*';
        simpan[jumlah] = infix[i];
        simpan[jumlah+1] += "1";
        jumlah+=3;
        i++;
    }else if (is_operator(infix[i])&& infix[i+1] == '-' && operand(infix[i+2])&&infix[i]!= ')'){
        simpan[jumlah+1] = infix[i+1];
        simpan[jumlah] = infix[i];
        simpan[jumlah+1]+= "1";
        simpan[jumlah+2] = '*';
        jumlah+=3;
        i++;

    }
    
    else if (infix[i] == '-' &&infix[i+1]=='(' && i == 0){
        simpan[jumlah] = infix[i];
        simpan[jumlah] += '1';
        simpan[jumlah+1] = '*';
        jumlah+=2;

    }else if (infix[i]=='-'&& operand(infix[i+1])&& !operand(infix[i+2]) && i == 0){
        simpan[jumlah] = infix[i];
        simpan[jumlah] += infix[i+1];
        jumlah+=2;
        i++;

    }
