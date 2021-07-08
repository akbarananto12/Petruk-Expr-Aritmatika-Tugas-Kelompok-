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

#ASSYIFA 1



