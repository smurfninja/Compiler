#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <string>
#include "symbol.h"

using namespace std;

string spellS(Symbol);

class Token {
public:
  Token():sname(NONAME),svalue(attval(-1,string(""))){};
  Token(Symbol s, int v, string l ):sname(s),svalue(attval(v,l)){};
  ~Token(){};
  Symbol getSymbol()const {return sname;};
  int getValue()const {return svalue.value;};
  string getLexeme()const {return svalue.lexeme;};
  void insert(ostream &os) {os << "Token: " << spellS(sname) << "\n"
                              << "\tAttributes: " << "\n"
                              << "\t\tLexeme: " << getLexeme() << "\n"
                              << "\t\tValue: " << getValue() << endl;}
private:
  struct attval{
    attval(int i, string s):value(i),lexeme(s){}
    int value;
    string lexeme;
  };
  attval svalue;
  Symbol sname;
};

ostream& operator<<(ostream&, Token&);

#endif
