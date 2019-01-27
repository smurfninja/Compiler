#ifndef TOKENTEST_CPP
#define TOKENTEST_CPP

#include "token.h"
#include "gtest/gtest.h"

namespace{
   class TokenTest : public ::testing::Test{
   protected:
      TokenTest(){
	 Token *t = new Token();
	 Token u = Token();
	 Token
      }
      ~TokenTest(){
	 delete t;
      }
   };
TEST(TokenTest, TokenDefaultConstructor){
   Token *t = new Token();
   Symbol stest = NONAME;
   int negOne = -1;
   string empty = "";
   EXPECT_EQ(stest, t->getSymbol());
   EXPECT_EQ(negOne, t->getValue());
   EXPECT_EQ(empty, t->getLexeme());
}

TEST(TokenTest, TokenExplicitConstructor){
   int thirty = 30;
   int zero = 0;
   Symbol num = NUM;
   Symbol id = ID;
   Symbol begin = BEGIN;
}

TEST(TokenTest, TokenDestructor){

}

TEST(TokenTest, TokenCopyOperator){

}

TEST(TokenTest, TokenGetSymbol){

}

TEST(TokenTest, TokenGetValue){

}

TEST(TokenTest, TokenGetLexeme){

}

TEST(TokenTest, TokenInsert){

}

TEST(TokenTest, TokenOstreamOperator){
   
}

TEST(TokenTest, TokenSpellSymbol){

}

}
#endif
