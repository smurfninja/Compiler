#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include <iostream>
#include <fstream>
#include "scanner.h"

#define MAXERRORS 10

enum errorkind{ScanE, ParseE, ScopeE, TypeE};

using namespace std;

class Administration{
public:
  Administration(ifstream& in, ofstream &out, Scanner &sc);
  ~Administration(){};
  void NewLine(){lineNo++; correctline = true;};
  void error(string text);
  int scan();
private:
  ifstream *inputfileptr;
  ofstream *outputfileptr;
  //Scanner &scanr;
  int lineNo;
  bool correctline;
  int errorCount;
};

#endif
