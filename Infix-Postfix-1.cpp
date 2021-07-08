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

panjang = infix.length();
for (int i = 0;i<panjang;i++){

if (operand(infix[i])){
    if (operand(infix[i])&&operand(infix[i+1])){
        simpan[jumlah] = infix[i];
        simpan[jumlah] += infix[i+1];
        jumlah++;
        i++;
    } else if (operand(infix[i])&& !(operand(infix[i+1]))){
        simpan[jumlah] = infix[i];
        jumlah++;
    }
}
