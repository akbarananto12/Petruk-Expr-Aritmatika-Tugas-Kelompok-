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
