#include "scanner.h"

Scanner::Scanner(ifstream &instream, Symtable &symboltable){
inputfileptr = instream;
symtableptr = symboltable
}

Token Scanner:getToken(){

}

bool Scanner::isWhiteSpace(char achar){
  if (achar == ' ' || achar == '\t')
    return true;
  return false;
}

bool Scanner:isAlpha(char achar){

  return false;
}

bool Scanner::isNumeric(char achar){
  return false;
}

bool Scanner::isSpecial(char achar){
  return false;
}

Token Scanner::recognizeName(){
  Token x = Token();
  return x;
}

Token Scanner::recognizeSpecial(){
  Token x = Token();
  return x;
}

Token Scanner::recognizeNumeral(){
  Token x = Token();
  return x;
}

void Scanner::recognizeComment(){
  return;
}
