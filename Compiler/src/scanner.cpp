#include "scanner.h"

Scanner::Scanner(ifstream &instream, Symtable &symboltable){
   //symtableptr = &symboltable;
   // inputfileptr = instream;
}

Token Scanner::getToken(){

}

bool Scanner::isWhitespace(char achar){
   if (achar == ' ' ||
       achar == '\t')
      return true;
   return false;
}

bool Scanner::isAlpha(char achar){
   return isalpha(achar);
}

bool Scanner::isNumeric(char achar){
   return isdigit(achar);
}

bool Scanner::isSpecial(char achar){
   if (isPrimaryOp(achar))
      return true;
   else if (isRelationalOp(achar))
      return true;
   else if (isAddingOp(achar))
      return true;
   else if (isMultiplyOp(achar))
      return true;
   else if (isNotOp(achar))
      return true;
   else
      return false;
   return false;
}

bool Scanner::isPrimaryOp(char achar){
   if (achar == '&' ||
       achar == '|')
      return true;
   return false;
}

bool Scanner::isRelationalOp(char achar){
   if (achar == '<' ||
       achar == '=' ||
       achar == '>')
      return true;
   return false;
}

bool Scanner::isAddingOp(char achar){
   if (achar == '+' ||
       achar == '-')
      return true;
   return false;
}

bool Scanner::isMultiplyOp(char achar){
   if (achar == '*' ||
       achar == '\\' ||
       achar == '/')
      return true;
   return false;
}

bool Scanner::isNotOp(char achar){
   if (achar == '~')
      return true;
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
