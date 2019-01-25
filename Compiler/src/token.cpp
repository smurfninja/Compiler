#include "token.h"

ostream& operator<<(ostream& os, Token& t)
{
  os << "Token: " << spellS(t.getSymbol()) << "\n"
     << "\tAttributes: " << "\n"
     << "\t\tLexeme: " << t.getLexeme() << "\n"
     << "\t\tValue: " << t.getValue() << endl;
   }

string spellS(Symbol s)
{
  if (s == 256)
    return "ID";
}
