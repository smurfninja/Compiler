#include "scanner.h"

Token Scanner::getToken(){
   char curr;
   inputfileptr->get(curr);
   laChar = inputfileptr->peek();
   if (curr == '$'){
      inputfileptr->unget();
      recognizeComment();
   }
   else if (isNumeric(curr)){
      inputfileptr->unget();
      return recognizeNumeral();
   }
   else if (isSpecial(curr)){
      inputfileptr->unget();
      return recognizeSpecial();
   }
   else if (isAlpha(curr) && (isAlpha(laChar) || isNumeric(laChar) || laChar == '_')){
      inputfileptr->unget();
      return recognizeName();
   }
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

//special symbols not yet covered := [] -> $
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
   else if (isOtherSpecial(achar))
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

bool Scanner::isOtherSpecial(char achar){
   if (achar == '.' ||
       achar == ',' ||
       achar == ';' ||
       achar == ':' )
      return true;
   else if (achar == '[' ||
	    achar == ']' ||
	    achar == '(' ||
	    achar == ')')
      return true;
   else
      return false;
   return false;
}
Token Scanner::recognizeName(){
   char* buffer;
   char delim = ' ';
   inputfileptr->getline(buffer, 256, delim);
   Token x = Token();
   return x;
}

//FIND OUT HOW MANY CHARACTERS ARE GETTING STRIPPED OFF INPUT
Token Scanner::recognizeSpecial(){
   char c;
   Symbol sname;
   Symbol temp;
   string buffer;
   inputfileptr->get(c);
   buffer = c+laChar;
   if (buffer == ":=")
      sname = ASSIGNMENT;
   else if (buffer == "[]")
      sname = SQUARE;
   else if (buffer == "->")
      sname = ARROW;
   else
      buffer = c;
      for (int i = 2; i < 19; i++){
	 temp = static_cast<Symbol>(i);
	 if (spellS(temp) == buffer)
	    sname = temp;
      }
 
   Token x = Token(sname, 0, buffer);
   return x;
}

Token Scanner::recognizeNumeral(){
   char c;
   int value = 0;
   Symbol sname = NUM;
   string buffer = " ";
   inputfileptr->get(c);
   while (isNumeric(c)){
      value = value*10 + c - '0';
      buffer = buffer + c;
      inputfileptr->get(c);
   }
   Token x = Token(NUM, value, buffer);
   return x;
}

void Scanner::recognizeComment(){
   char* buffer;
   inputfileptr->getline(buffer, 256);
   return;
}
