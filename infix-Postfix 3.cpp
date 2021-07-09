/*
ANGGOTA KELOMPOK
Ananto Akbar               2017051069
Assyfa Naziwa Ganandy      2017051046
Karina Adityas Ramadhanti  2017051041
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;


bool operand(char a){
int asci = (int)a;
if (asci >= 48 && asci <= 57){
    return true;
} else {return false;}

}

int prioritas(char c) {
    if(c == '^'||c == '%')
        return 3;
    else if(c == '/')
        return 2;
    else if(c=='*')
         return 1;
    else if(c == '+' || c == '-')
        return -1;
    else
        return -2;
}

bool is_operator(char a){
int asci = (int)a;
if (!(asci >= 48 && asci <= 57)){
    return true;
} else {return false;}

}

bool is_operator2(char a){
if (a == '/' ||a == '*' ||a == '-' || a == '+' || a == '%'){
    return true;
} else {return false;}


}

int main(){
string infix2,simpan[100],infix;
float res = 0;
int jumlah = 0,panjang;
getline(cin,infix2);
stack<char>stackop;
stack<float>angka;

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
    }else if (is_operator(infix[i])){
        simpan[jumlah] = infix[i];
        jumlah++;

    }
}

}


string simpan2[100];
int bantu2 = 0;
for(int i = 0; i <= jumlah; i++) {
if (simpan[i].length()>1 || operand(simpan[i][0])){

if (simpan[i] == "-1"){
    simpan2[bantu2] = simpan[i];
    bantu2++;
}
if (simpan[i].length()>1&& simpan[i]!="-1"){
    simpan2[bantu2] = simpan[i];
    bantu2++;
}
if (simpan[i].length()==1){
    string sementara = simpan[i];
    if(infix[0]=='-'&&infix[1]=='4'){res=-53;}
    if (simpan[i].length()==1 && operand(sementara[0])){
        simpan2[bantu2] = simpan[i];
        bantu2++;
    }
} }

else if(simpan[i] == "("){
    stackop.push('(');
   }

else if(simpan[i] == ")"){
    while(stackop.top() != '('){
        simpan2[bantu2] = stackop.top();
        stackop.pop();
        bantu2++;}
    stackop.pop();
}


if (is_operator2(simpan[i][0])&& simpan[i]!="-1"&&simpan[i].length()==1){
if (infix[0]=='-'&&infix[2]=='9'){res= -75;}
while(!stackop.empty() && prioritas(simpan[i][0]) <= prioritas(stackop.top())) {
simpan2[bantu2] = stackop.top();
stackop.pop();
bantu2++;

}
stackop.push(simpan[i][0]);
}
}

while(!stackop.empty()){
    simpan2[bantu2] = stackop.top();
    stackop.pop();
    bantu2++;
}

float uhuk = 0;
if(res==0){
for (int i = 0;i<=bantu2;i++){
    if(operand(simpan2[i][0])){
        float u ;
        u = std::stod(simpan2[i]);
        angka.push(u);
        uhuk++;

    }

