#include "administration.h"


void Administration::error(string text){
   correctline = false;
   lineNo++;
   errorCount++;
   return;
}

int Administration::scan(){
   return -1;
}
