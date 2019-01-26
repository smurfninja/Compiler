#include "symbolTable.h"


//This code uses a stupid magic number in order to make it work quickly
//I just use inherent knowledge that the reserved words lie between 24 and 40
//in the enum Symbol. So I static cast those ints to symbols.
//I then use the spellS(Symbol) function to convert that symbol to a string
//That string is used in the hashfn() to determine the index of the keyword
void Symtable::loadResvd(){
   for (int i = 24; i < 41; i++){
      Symbol word = static_cast<Symbol>(i);
      string lexeme = spellS(word);
      int index = hashfn(lexeme);
      Token t = Token(word, 0, lexeme);
      insert(lexeme, t);
   }
   return;
}

//This function casts each character of the string to an integer
//Then multiplies the integer by the position in the cstring
//Each iteration is added to the running total
//Finally we modulo the size of the array to make sure it fits into the array
int Symtable::hashfn(string s){
  int x = 0;
  for(int i = 0; i < s.size()+1; i++){
    int t = static_cast<int>(s[i]);
    x += t*(i+1);
  }
  return x%SYMTABLESIZE;
}

int Symtable::search(string s){
   int x = hashfn(s);
   if (htable[x].getLexeme() == s){
      occupied++;
      return x;
   }
   return -1;
}

int Symtable::insert(string s, Token &t){
   int x = hashfn(s);
   htable[x] = t;
   occupied++;
   return x;
}

void Symtable::printTable(){

  return;
}
