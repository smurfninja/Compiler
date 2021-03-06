#include "symbolTable.h"


//This code uses a stupid magic number in order to make it work quickly
//I just use inherent knowledge that the reserved words lie between 24 and 40
//in the enum Symbol. So I static cast those ints to symbols.
//I then use the spellS(Symbol) function to convert that symbol to a string
//That string is used in the hashfn() to determine the index of the keyword
void Symtable::loadResvd(){
   for (int j = 0; j < SYMTABLESIZE; j++){
      string non = "noname";
      Token noname = Token(NONAME, 0, non);
      insert(non, noname);
   }
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

//using the hashfn() the index is determined
//using that index we find the associated lexeme
//for that token and confirm it matches the
//param s if it does we return the index
//else return -1 denoting failure to locate the
//lexeme provided
int Symtable::search(string s){
   int x = hashfn(s);
   if (htable[x].getLexeme() == s){
      return x;
   }
   return -1;
}

//insert takes in a string and a token
//the string is the token's lexeme
//the hashfn() is used to determine the index where
//The token should be inserted
//********************Doesn't handle collisions*****************
//updates the occupied count
int Symtable::insert(string s, Token &t){
   int x = hashfn(s);
   htable[x] = t;
   occupied++;
   return x;
}

const Token& Symtable::index(int i){
   return htable[i];
}

void Symtable::printTable(){

  return;
}
