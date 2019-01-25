#include "symbolTable.h"

void Symtable::loadResvd(){

  return;
}

//This function casts each character of the string to an integer
//Then multiplies the integer by the position in the cstring
//Each iteration is added to the running total
//Finally we modulo the size of the array to make sure it fits into the array
int hashfn(string s){
  int x = 0;
  for(int i = 0; i < s.size()+1; i++){
    int t = static_cast<int>(s[i]);
    x += t*(i+1);
  }
  return x%SYMTABLESIZE;
}

int Symtable::search(string s){

  return -1;
}

int Symtable::insert(string s){

  return x;
}

void Symtable::printTable(){

  return;
}
