#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>
#include <fstream>
#include <string>
#include "token.h"
#include "symbolTable.h"

class Scanner {
public:
  Scanner(){};
  Scanner(ifstream &instream, Symtable &symboltable);
  ~Scanner();
  Token getToken();
private:
  ifstream *inputfileptr;
  Symtable *symtableptr;
  char laChar;
  bool isWhitespace(char achar);
  bool isAlpha(char achar);
  bool isNumeric(char achar);
  bool isSpecial(char achar);
  bool isPrimaryOp(char achar);
  bool isRelationalOp(char achar);
  bool isAddingOp(char achar);
  bool isMultiplyOp(char achar);
  bool isNotOp(char achar);
  Token recognizeName();
  Token recognizeSpecial();
  Token recognizeNumeral();
  void recognizeComment();
};

#endif
