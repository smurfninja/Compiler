#include "scanner.h"

//getToken() will return the next Token in the
//filestream. First we check to see if their is a comment
//If so we call the recognizeComment() to remove the line
//The next three conditionals will determine which token will
//be created based on the first character and the lookahead character
Token Scanner::getToken(){
   char curr;
   inputfileptr->get(curr);
   laChar = inputfileptr->peek();
   if (curr == '$'){
      inputfileptr->unget();
      recognizeComment();
   }
   if (isNumeric(curr)){
      inputfileptr->unget();
      return recognizeNumeral();
   }
   else if (isSpecial(curr)){
      inputfileptr->unget();
      return recognizeSpecial();
   }
   else if (isAlpha(curr) && (isAlpha(laChar) ||
			      isNumeric(laChar) ||
			      laChar == '_' ||
			      laChar == ' ')){
      inputfileptr->unget();
      return recognizeName();
   }
}

//A simple boolean returns true if the param achar
//is an empty space, a new line, or a tab character
//Defaults to return false
bool Scanner::isWhitespace(char achar){
   if (achar == ' ' ||
       achar == '\t' ||
       achar == '\n')
      return true;
   return false;
}

//A simple boolean returns true if the param achar
//is an alphabetical character
//Defaults to return false
bool Scanner::isAlpha(char achar){
   return isalpha(achar);
}

//A simple boolean returns true if the param achar
//is a numerical character
//Defaults to return false
bool Scanner::isNumeric(char achar){
   return isdigit(achar);
}

//A simple boolean returns true if the param achar
//is a special character. It does this by calling
//helper functions. The purpose of this is to group
//the special characters into categories for later use
//Defaults to return false
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

//A simple boolean returns true if the param achar
//is one of the two primary operators & or |
//Defaults to return false
bool Scanner::isPrimaryOp(char achar){
   if (achar == '&' ||
       achar == '|')
      return true;
   return false;
}

//A simple boolean returns true if the param achar
//Is one of the relational operators < = >
//Defaults to return false
bool Scanner::isRelationalOp(char achar){
   if (achar == '<' ||
       achar == '=' ||
       achar == '>')
      return true;
   return false;
}

//A simple boolean returns true if the param achar
//is one of the adding operators + -
//Defaults to return false
bool Scanner::isAddingOp(char achar){
   if (achar == '+' ||
       achar == '-')
      return true;
   return false;
}

//A simple boolean returns true if the param achar
//is one of the multiply operators * \ /
//Defaults to return false
bool Scanner::isMultiplyOp(char achar){
   if (achar == '*' ||
       achar == '\\' ||
       achar == '/')
      return true;
   return false;
}

//A simple boolean returns true if the param achar
//is the negation operator ~
//Defaults to return false
bool Scanner::isNotOp(char achar){
   if (achar == '~')
      return true;
   return false;
}

//A simple boolean returns true if the param achar
//is the remaining special characters not listed
//in PL to be an operator
//Could be ported into two aditional functions
//isPunctuation() isParan() but am lazy
//Defaults to return false
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

//Called by getToken() to recognize a token
//that is either an ID or a reserved word
//first the buffer loads the rest of the line
//until a white space is encountered
//Next we search the symbol table to see if
//the word already exists. If it exists then it
//is simply returned. If it needs to be created,
//we assign the symbol ID and the lexeme is the
//buffer string
//Default is badchar returned
Token Scanner::recognizeName(){
   char* buffer;
   char delim = ' ';
   Symbol sname = NONAME;
   Symbol temp;
   inputfileptr->getline(buffer, 256, delim);
   int index = symtableptr->search(buffer);
   if (index > -1){
      Token x = symtableptr->index(index);
      return x;
   }
   else if (index < 0){
      Token x = Token(ID, 0, buffer);
      return x;
   }
   Token x = Token(BADCHAR, 0, spellS(BADCHAR));
   return x;
}

//First we determine if the special character
//is an ASSIGNMENT SQUARE or ARROW because those
//special tokens use two special symbols
//Then we iterate through the list of symbols and find the appropriate
//symbol to assign to the token
//FIND OUT HOW MANY CHARACTERS ARE GETTING STRIPPED OFF INPUT
Token Scanner::recognizeSpecial(){
   char c;
   Symbol sname;
   Symbol temp;
   string buffer;
   inputfileptr->get(c);
   buffer = c+laChar;
   if (buffer == ":="){
      sname = ASSIGNMENT;
   }
   else if (buffer == "[]"){
      sname = SQUARE;
   }
   else if (buffer == "->"){
      
      sname = ARROW;
   }
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

//Recopgnize numeral reads a character and adds the numeral
//to the running total labelled value
//buffer concatenates the character to its string
//returns the completed token with NUM assigned as symbol
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


//Recognize comment is called when a $ is seen
//the rest of the line is removed and passed back
//to gettoken
void Scanner::recognizeComment(){
   char* buffer;
   inputfileptr->getline(buffer, 256);
   return;
}
