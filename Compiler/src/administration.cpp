#include "administration.h"

//The error function is not being used yet
//When utilized, it will take in a string
//That string will represent the error
//encountered. Which will be added to the
//errors already accounted for and the linenumber
void Administration::error(string text){
   correctline = false;
   errorCount++;
   NewLine();
   return;
}

//Scan is running a loop which it only escapes when
//the eof() flag return true
//will implement errors soon
//The loop just calls get next token until the eof is seen
int Administration::scan(){
   char curr;
   char la;
   while (!inputfileptr->eof()){
      Token t = scanr.getToken();
      t.insert(*outputfileptr);
      *inputfileptr >> skipws >> curr;
      if (inputfileptr->eof())
	 return 1;
   }
   return -1;
}
