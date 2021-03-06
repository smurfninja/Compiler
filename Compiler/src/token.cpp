#include "token.h"

//overloaded operator outputs token for the filestream
ostream& operator<<(ostream& os, Token& t)
{
  os << "Token: " << spellS(t.getSymbol()) << "\n"
     << "\tAttributes: " << "\n"
     << "\t\tLexeme: " << t.getLexeme() << "\n"
     << "\t\tValue: " << t.getValue() << endl;
}

//Overloaded copy operator
//made for my ease of mind
Token& Token::operator=(const Token& t){
   sname=t.getSymbol();
   svalue = attval(t.getValue(), t.getLexeme());
   return *this;
}

//stupid function used by brute forcing magic numbers
//with smarter minds this function would be replaced
//until then it remains this ugly attrocity
string spellS(Symbol s)
{
   if (s == 0)
      return "ID";
   else if (s == 1)
      return "NUM";
   else if (s == 2)
      return "+";
   else if (s == 3)
      return "-";
   else if (s == 4)
      return ".";
   else if (s == 5)
      return ",";
   else if (s == 6)
      return ";";
   else if (s == 7)
      return "[";
   else if (s == 8)
      return "]";
   else if (s == 9)
      return "&";
   else if (s == 10)
      return "|";
   else if (s == 11)
      return "~";
   else if (s == 12)
      return "<";
   else if (s == 13)
      return "=";
   else if (s == 14)
      return ">";
   else if (s == 15)
      return "*";
   else if (s == 16)
      return "/";
   else if (s == 17)
      return "\\";
   else if (s == 18)
      return "(";
   else if (s == 19)
      return ")";
   else if (s == 20)
      return ":=";
   else if (s == 21)
      return "[]";
   else if (s == 22)
      return "->";
   else if (s == 23)
      return "$";
   else if (s == 24)
      return "BEGIN";
   else if (s == 25)
      return "END";
   else if (s == 26)
      return "CONST";
   else if (s == 27)
      return "ARRAY";
   else if (s == 28)
      return "INTEGER";
   else if (s == 29)
      return "BOOLEAN";
   else if (s == 30)
      return "PROC";
   else if (s == 31)
      return "SKIP";
   else if (s == 32)
      return "READ";
   else if (s == 33)
      return "WRITE";
   else if (s == 34)
      return "CALL";
   else if (s == 35)
      return "IF";
   else if (s == 36)
      return "FI";
   else if (s == 37)
      return "DO";
   else if (s == 38)
      return "OD";
   else if (s == 39)
      return "FALSE";
   else if (s == 40)
      return "TRUE";
   else if (s == 41)
      return "NONAME";
   else if (s == 42)
      return "BADNAME";
   else if (s == 43)
      return "BADNUM";
   else if (s == 44)
      return "ENDOFFILE";
   else if (s == 45)
      return "NEWLINE";
   else 
      return "BADCHAR";
}
