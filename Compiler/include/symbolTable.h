#ifndef SYMTABLE_H
#define SYMTABLE_H

#include <string>
#include <vector>
#include "token.h"
#define SYMTABLESIZE 307

using namespace std;

class Symtable {
public:
  Symtable():occupied(0), htable(SYMTABLESIZE){}
  void loadResvd();
  ~Symtable(){}
  int search(string s);
  int insert(string s);
  bool full(){return occupied == SYMTABLESIZE;};
  int getOC(){return occupied;};
  void printTable();
private:
  vector<Token> htable;
  int occupied;
  int hashfn(string s);
};

#endif
