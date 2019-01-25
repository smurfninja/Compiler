#include "administration.h"

Administration::Administration(ifstream& in, ofstream &out, Scanner &sc){
  outputfileptr = &out;
  scanr = *sc;
  inputfileptr = *in;
}

void Administration::error(string text){
  return;
}

int Administration::scan(){
  return -1;
}
