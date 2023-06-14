#include <clocale>
#include <cstdio>
#include <exception>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <random>
#include <thread>
#include <chrono>
#include <algorithm>
#include <stdlib.h>
#include <locale>
using namespace std;
int called()
{
	system("clear");
  int hand_ace = 0;
  int score = 0;
  int bot_score = 0;
  bool ace = false;
  bool bot_ace = false;
  bool loopy = false;
  bool bot_call = false;
  std::vector<string> handcards = {""};
  std::vector<string> bot_handcards = {""};
  std::vector<string> Aces = {"A \xE2\x99\xA0", "A \xE2\x99\xA5", "A \xE2\x99\xA6", "A \xE2\x99\xA3"};
  std::vector<string> Kings = {"K \xE2\x99\xA0","K \xE2\x99\xA5","K \xE2\x99\xA6","K \xE2\x99\xA3"};
  std::vector<string> Queens = {"Q \xE2\x99\xA0","Q \xE2\x99\xA5","Q \xE2\x99\xA6","Q \xE2\x99\xA3"};
  std::vector<string> Jacks = {"J \xE2\x99\xA0","J \xE2\x99\xA5","J \xE2\x99\xA6","J \xE2\x99\xA3"};
  std::vector<string> tens = {"10\xE2\x99\xA0","10\xE2\x99\xA5","10\xE2\x99\xA6","10\xE2\x99\xA3"};
  std::vector<string> nines = {"9 \xE2\x99\xA0","9 \xE2\x99\xA5","9 \xE2\x99\xA6","9 \xE2\x99\xA3"};
  std::vector<string> eights = {"8 \xE2\x99\xA0","8 \xE2\x99\xA5","8 \xE2\x99\xA6","8 \xE2\x99\xA3"};
  std::vector<string> sevens = {"7 \xE2\x99\xA0","7 \xE2\x99\xA5","7 \xE2\x99\xA6","7 \xE2\x99\xA3"};
  std::vector<string> sixes = {"6 \xE2\x99\xA0","6 \xE2\x99\xA5","6 \xE2\x99\xA6","6 \xE2\x99\xA3"};
  std::vector<string> fives = {"5 \xE2\x99\xA0","5 \xE2\x99\xA5","5 \xE2\x99\xA6","5 \xE2\x99\xA3"};
  std::vector<string> fours = {"4 \xE2\x99\xA0","4 \xE2\x99\xA5","4 \xE2\x99\xA6","4 \xE2\x99\xA3"};
  std::vector<string> threes = {"3 \xE2\x99\xA0","3 \xE2\x99\xA5","3 \xE2\x99\xA6","3 \xE2\x99\xA3"};
  std::vector<string> twos = {"2 \xE2\x99\xA0","2 \xE2\x99\xA5","2 \xE2\x99\xA6","2 \xE2\x99\xA3"};
  std::string aceans;
  std::string botaceans;
  string spd = "\xE2\x99\xA0";
  string hrt = "\xE2\x99\xA5";
  string dim = "\xE2\x99\xA6";
  string clb = "\xE2\x99\xA3";
  std::string ans;
  std::vector<string> cards = {"A \xE2\x99\xA0", "A \xE2\x99\xA5", "A \xE2\x99\xA6", "A \xE2\x99\xA3","K \xE2\x99\xA0","K \xE2\x99\xA5","K \xE2\x99\xA6","K \xE2\x99\xA3","Q \xE2\x99\xA0","Q \xE2\x99\xA5","Q \xE2\x99\xA6","Q \xE2\x99\xA3","J \xE2\x99\xA0","J \xE2\x99\xA5","J \xE2\x99\xA6","J \xE2\x99\xA3","10\xE2\x99\xA0","10\xE2\x99\xA5","10\xE2\x99\xA6","10\xE2\x99\xA3","9 \xE2\x99\xA0","9 \xE2\x99\xA5","9 \xE2\x99\xA6","9 \xE2\x99\xA3","8 \xE2\x99\xA0","8 \xE2\x99\xA5","8 \xE2\x99\xA6","8 \xE2\x99\xA3","7 \xE2\x99\xA0","7 \xE2\x99\xA5","7 \xE2\x99\xA6","7 \xE2\x99\xA3","6 \xE2\x99\xA0","6 \xE2\x99\xA5","6 \xE2\x99\xA6","6 \xE2\x99\xA3","5 \xE2\x99\xA0","5 \xE2\x99\xA5","5 \xE2\x99\xA6","5 \xE2\x99\xA3","4 \xE2\x99\xA0","4 \xE2\x99\xA5","4 \xE2\x99\xA6","4 \xE2\x99\xA3","3 \xE2\x99\xA0","3 \xE2\x99\xA5","3 \xE2\x99\xA6","3 \xE2\x99\xA3","2 \xE2\x99\xA0","2 \xE2\x99\xA5","2 \xE2\x99\xA6","2 \xE2\x99\xA3"};

  srand(time(0));
  for(int i = 0; i < 2; i++){
  int r = std::rand() % cards.size();
  string value = cards[r];
  this_thread::sleep_for(chrono::milliseconds(1000));
  bot_handcards.insert(bot_handcards.begin()+1,value);
  bot_handcards.erase(std::remove(bot_handcards.begin(), bot_handcards.end(), ""), bot_handcards.end());
  cards.erase(std::remove(cards.begin(), cards.end(), value), cards.end());
  for (auto& i: Kings) {
   if (value == i)
        bot_score += 10;
   }
   for (auto& i: Queens) {
   if (value == i)
        bot_score += 10;
   }
   for (auto& i: Jacks) {
   if (value == i)
        bot_score += 10;
   }
   for (auto& i: tens) {
   if (value == i)
        bot_score += 10;
   }
   for (auto& i: nines) {
   if (value == i)
        bot_score += 9;
   }
   for (auto& i: eights) {
   if (value == i)
        bot_score += 8;
   }
   for (auto& i: sevens) {
   if (value == i)
        bot_score += 7;
   }
   for (auto& i: sixes) {
   if (value == i)
        bot_score += 6;
   }
   for (auto& i: fives) {
   if (value == i)
        bot_score += 5;
   }
   for (auto& i: fours) {
   if (value == i)
        bot_score += 4;
   }
   for (auto& i: threes) {
   if (value == i)
        bot_score += 3;
   }
   for (auto& i: twos) {
   if (value == i)
        bot_score += 2;
   }
   for (auto& i: Aces) {
   if (value == i)
        bot_ace = true;
  }
  if(bot_ace == true){
    int cs = bot_score + 11;
     if (cs < 21) {
     bot_score += 11;
     }
	if (cs == 21){
	 bot_score += 11;
	}
    if (cs > 21) {
     bot_score += 1;
     }
   bot_ace = false;

  }
  }
  
  
  
  if(bot_ace == false){
    bot_call = false;
  }
  
  while(bot_call == false){
  if (bot_score < 17){
	
  
    int r = std::rand() % cards.size();
  string valuef = cards[r];
  this_thread::sleep_for(chrono::milliseconds(1000));
  bot_handcards.insert(bot_handcards.begin()+1,valuef);
  bot_handcards.erase(std::remove(bot_handcards.begin(), bot_handcards.end(), ""), bot_handcards.end());
  cards.erase(std::remove(cards.begin(), cards.end(), valuef), cards.end());
  
  for (auto& i: Kings) {
   if (valuef == i)
        bot_score += 10;
   }
   for (auto& i: Queens) {
   if (valuef == i)
        bot_score += 10;
   }
   for (auto& i: Jacks) {
   if (valuef == i)
        bot_score += 10;
   }
   for (auto& i: tens) {
   if (valuef == i)
        bot_score += 10;
   }
   for (auto& i: nines) {
   if (valuef == i)
        bot_score += 9;
   }
   for (auto& i: eights) {
   if (valuef == i)
        bot_score += 8;
   }
   for (auto& i: sevens) {
   if (valuef == i)
        bot_score += 7;
   }
   for (auto& i: sixes) {
   if (valuef == i)
        bot_score += 6;
   }
   for (auto& i: fives) {
   if (valuef == i)
        bot_score += 5;
   }
   for (auto& i: fours) {
   if (valuef == i)
        bot_score += 4;
   }
   for (auto& i: threes) {
   if (valuef == i)
        bot_score += 3;
   }
   for (auto& i: twos) {
   if (valuef == i)
        bot_score += 2;
   }
   for (auto& i: Aces) {
   if (valuef == i)
        bot_ace = true;
   }
   if(bot_ace == true){
    int cs = bot_score + 11;
     if (cs < 21) {
     bot_score += 11;
     }
	 if (cs == 21) {
     bot_score += 11;
     }
    if (cs > 21) {
     bot_score += 1;
  }
  bot_ace = false;
  }
  if(bot_ace == false){
	  bot_call = false;
  }

  }
  
 
   if(bot_score > 17){
	  bot_call = true;
  }
  if(bot_score == 17){
	  bot_call = true;
  }
  
  

  }
  
  std::cout << "\nPCs cards: \n";
  
  std::cout <<  "\xE2\x98\xA3----";
  std::cout <<  "\xE2\x98\xA3-------\xE2\x98\xA3\n";
  
  std::cout <<  "|" << bot_handcards.front() << " ";
  std::cout <<  "|///////|\n";
  
  std::cout <<  "|    ";
  std::cout <<  "|/#---#/|\n";
  
  std::cout <<  "|   \xE2\x98\xA2";
  std::cout <<  "|/|B#J|/|\n";
  
  std::cout <<  "|    ";
  std::cout <<  "|/#---#/|\n";
  
  std::cout <<  "|    ";
  std::cout <<  "|///////|\n";
  
  std::cout <<  "\xE2\x98\xA3----";
  std::cout <<  "\xE2\x98\xA3-------\xE2\x98\xA3\n";
  
  
  for(int i = 0; i < 2; i++){
   srand(time(0));
   int r = std::rand() % cards.size();
   string value = cards[r];
   this_thread::sleep_for(chrono::milliseconds(1000));
   handcards.insert(handcards.begin()+1,value);
   handcards.erase(std::remove(handcards.begin(), handcards.end(), ""), handcards.end());
   cards.erase(std::remove(cards.begin(), cards.end(), value), cards.end());
   for (auto& i: Aces){
   if (value == i)
	   hand_ace += 1;
	   }
   for (auto& i: Kings) {
   if (value == i)
        score += 10;
   }
   for (auto& i: Queens) {
   if (value == i)
        score += 10;
   }
   for (auto& i: Jacks) {
   if (value == i)
        score += 10;
   }
   for (auto& i: tens) {
   if (value == i)
        score += 10;
   }
   for (auto& i: nines) {
   if (value == i)
        score += 9;
   }
   for (auto& i: eights) {
   if (value == i)
        score += 8;
   }
   for (auto& i: sevens) {
   if (value == i)
        score += 7;
   }
   for (auto& i: sixes) {
   if (value == i)
        score += 6;
   }
   for (auto& i: fives) {
   if (value == i)
        score += 5;
   }
   for (auto& i: fours) {
   if (value == i)
        score += 4;
   }
   for (auto& i: threes) {
   if (value == i)
        score += 3;
   }
   for (auto& i: twos) {
   if (value == i)
        score += 2;
   }
   for (auto& i: Aces) {
   if (value == i)
        ace = true;
		
   }
    }

std::cout << "\nYour cards: \n";

 for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
 std::cout <<  "\xE2\x98\xA3----";
 std::cout <<  "---\xE2\x98\xA3\n";
 for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
 std::cout <<  "|" << *i << " ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
 std::cout <<  "|   \xE2\x98\xA2";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  handcards.back() << "|\n";
 for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
 std::cout <<  "\xE2\x98\xA3----";
 std::cout <<  "---\xE2\x98\xA3\n";
 
 std::cout << "\nYour score: " << score << "\n";

 if(hand_ace == 1){
  if(ace == true){
    std::cout << "\nDo you want your Ace as 1 or 11?\n";
     getline(cin, aceans);
     if (aceans == "1") {
     score += 1;
     }
    else if (aceans == "11") {
     score += 11;
     }else{
	  std::cout << "Wrong answer, ADIOS!";
	  this_thread::sleep_for(chrono::milliseconds(1000));
	  exit(0);
	  }
   ace = false;

 }}
  if(hand_ace == 2){
  if(ace == true){
    std::cout << "\nDo you want your Ace as 1 or 11?\n";
     getline(cin, aceans);
     if (aceans == "1") {
     score += 1;
     }
    else if (aceans == "11") {
     score += 11;
  }
  else{
	  std::cout << "Wrong answer, ADIOS!";
	  this_thread::sleep_for(chrono::milliseconds(1000));
	  exit(0);
	  }
  }
  if(ace == true){
    std::cout << "\nDo you want your second Ace as 1 or 11?\n";
     getline(cin, aceans);
     if (aceans == "1") {
     score += 1;
     }
    else if (aceans == "11") {
     score += 11;
     } else{
	  std::cout << "Wrong answer, ADIOS!";
	  this_thread::sleep_for(chrono::milliseconds(1000));
	  exit(0);}
   ace = false;

 }
 }
  if(score > 21){
	  system("clear");
	  std::cout << "\nPCs cards: \n";
	for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "\xE2\x98\xA3----";
 std::cout <<  "---\xE2\x98\xA3\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|" << *i << " ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|   \xE2\x98\xA2";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  bot_handcards.back() << "|\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "\xE2\x98\xA3----";
 std::cout <<  "---\xE2\x98\xA3\n";
 std::cout << "\nPCs score: " << bot_score << "\n";
    std::cout <<  "\nYour cards: \n";
    handcards.erase(std::remove(handcards.begin(), handcards.end(), ""), handcards.end());
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "\xE2\x98\xA3----";
    std::cout <<  "---\xE2\x98\xA3\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "|" << *i << " ";
    std::cout <<  "   |\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "|    ";
    std::cout <<  "   |\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "|   \xE2\x98\xA2";
    std::cout <<  "   |\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "|    ";
    std::cout <<  "   |\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "|    ";
    std::cout <<  handcards.back() << "|\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "\xE2\x98\xA3----";
    std::cout <<  "---\xE2\x98\xA3\n";
	std::cout << "\nYour score: " << score << "\n";
	if(bot_score > 21){
		std::cout << "\nDraw!";
		return(0);
	}
	if(bot_score < 21){
		std::cout << "\nYou lost!";
		return(0);
	}
	if(bot_score == 21){
		std::cout << "\nYou lost!";
		return(0);
	}
	  }

 

  std::cout <<  "\nhit[1] or stand[2] ? ";
  getline(cin, ans);
  if (ans == "1") {
	  system("clear");
   loopy = false;
  }
  else if (ans == "hit") {
	  system("clear");
   loopy = false;
  }
    else if (ans == "stand") {
    loopy = true;
	system("clear");
	std::cout << "Bots cards: \n";
	for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "\xE2\x98\xA3----";
 std::cout <<  "---\xE2\x98\xA3\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|" << *i << " ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|   \xE2\x98\xA2";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  bot_handcards.back() << "|\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "\xE2\x98\xA3----";
 std::cout <<  "---\xE2\x98\xA3\n";
std::cout << "\nPCs score: " << bot_score << "\n";
    std::cout <<  "Your cards: \n";
    handcards.erase(std::remove(handcards.begin(), handcards.end(), ""), handcards.end());
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "\xE2\x98\xA3----";
    std::cout <<  "---\xE2\x98\xA3\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "|" << *i << " ";
    std::cout <<  "   |\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "|    ";
    std::cout <<  "   |\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "|   \xE2\x98\xA2";
    std::cout <<  "   |\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "|    ";
    std::cout <<  "   |\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "|    ";
    std::cout <<  handcards.back() << "|\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "\xE2\x98\xA3----";
    std::cout <<  "---\xE2\x98\xA3\n";
    std::cout << "\nYour score: " << score << "\n";
	if(bot_score > 21){
		if(score > 21){
			std::cout << "\nDraw!";
			return(0);
		}
		if(score < 21){
			std::cout << "\nYou win!";
			return(0);
		}
		if(score == 21){
			std::cout << "\nYou win!";
			return(0);
		}
	}
	if(bot_score < 21){
	if(score < 21){
	if(score > bot_score){
		std::cout << "\nYou win!";
		return(0);
	}
    if(score < bot_score){
		std::cout << "\nYou lost!";
		return(0);
	}
	}
	if(score > 21){
		std::cout << "\nYou lost!";
		return(0);
	}
	}
	if(score == 21){
		if(bot_score == 21){
			std::cout << "\nDraw!";
			return(0);
		}
		if(bot_score > 21){
			std::cout << "\nYou win!";
			return(0);
		}
		if(bot_score < 21){
			std::cout << "\nYou win!";
			return(0);
		}
	}
	if(bot_score == 21){
		if(score == 21){
			std::cout << "\nDraw!";
			return(0);
		}
		if(score > 21){
			std::cout << "\nYou lost!";
			return(0);
		}
		if(score < 21){
			std::cout << "\nYou lost!";
			return(0);
		}
	}
  }
  else if (ans == "2") {
    loopy = true;
	system("clear");
	std::cout << "\nPCs cards: \n";
	for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "\xE2\x98\xA3----";
 std::cout <<  "---\xE2\x98\xA3\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|" << *i << " ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|   \xE2\x98\xA2";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  bot_handcards.back() << "|\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "\xE2\x98\xA3----";
 std::cout <<  "---\xE2\x98\xA3\n";
 std::cout << "\nPCs score: " << bot_score << "\n";
    std::cout <<  "\nYour cards: \n";
    handcards.erase(std::remove(handcards.begin(), handcards.end(), ""), handcards.end());
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "\xE2\x98\xA3----";
    std::cout <<  "---\xE2\x98\xA3\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "|" << *i << " ";
    std::cout <<  "   |\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "|    ";
    std::cout <<  "   |\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "|   \xE2\x98\xA2";
    std::cout <<  "   |\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "|    ";
    std::cout <<  "   |\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "|    ";
    std::cout <<  handcards.back() << "|\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "\xE2\x98\xA3----";
    std::cout <<  "---\xE2\x98\xA3\n";
    std::cout << "\nYour score: " << score << "\n";
	if(bot_score > 21){
		if(score > 21){
			std::cout << "\nDraw!";
			return(0);
		}
		if(score < 21){
			std::cout << "\nYou win!";
			return(0);
		}
		if(score == 21){
			std::cout << "\nYou win!";
			return(0);
		}
	}
	if(bot_score < 21){
	if(score < 21){
	if(score > bot_score){
		std::cout << "\nYou win!";
		return(0);
	}
    if(score < bot_score){
		std::cout << "\nYou lost!";
		return(0);
	}
	}
	if(score > 21){
		std::cout << "\nYou lost!";
		return(0);
	}
	}
	if(score == 21){
		if(bot_score == 21){
			std::cout << "\nDraw!";
			return(0);
		}
		if(bot_score > 21){
			std::cout << "\nYou win!";
			return(0);
		}
		if(bot_score < 21){
			std::cout << "\nYou win!";
			return(0);
		}
	}
	if(bot_score == 21){
		if(score == 21){
			std::cout << "\nDraw!";
			return(0);
		}
		if(score > 21){
			std::cout << "\nYou lost!";
			return(0);
		}
		if(score < 21){
			std::cout << "\nYou lost!";
			return(0);
		}
	}
	
  }
  else{
	  exit(0);}
  while (loopy == false)
  {
   srand(time(0));
   int r = std::rand() % cards.size();
   string value = cards[r];
   this_thread::sleep_for(chrono::milliseconds(1000));
   handcards.insert(handcards.begin()+1,value);
   handcards.erase(std::remove(handcards.begin(), handcards.end(), ""), handcards.end());
   cards.erase(std::remove(cards.begin(), cards.end(), value), cards.end());
   for (auto& i: Kings) {
   if (value == i)
        score += 10;
   }
   for (auto& i: Queens) {
   if (value == i)
        score += 10;
   }
   for (auto& i: Jacks) {
   if (value == i)
        score += 10;
   }
   for (auto& i: tens) {
   if (value == i)
        score += 10;
   }
   for (auto& i: nines) {
   if (value == i)
        score += 9;
   }
   for (auto& i: eights) {
   if (value == i)
        score += 8;
   }
   for (auto& i: sevens) {
   if (value == i)
        score += 7;
   }
   for (auto& i: sixes) {
   if (value == i)
        score += 6;
   }
   for (auto& i: fives) {
   if (value == i)
        score += 5;
   }
   for (auto& i: fours) {
   if (value == i)
        score += 4;
   }
   for (auto& i: threes) {
   if (value == i)
        score += 3;
   }
   for (auto& i: twos) {
   if (value == i)
        score += 2;
   }
   for (auto& i: Aces) {
   if (value == i)
        ace = true;
   }
   
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout <<  "\xE2\x98\xA3----";
   std::cout <<  "---\xE2\x98\xA3\n";
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout <<  "|" << *i << " ";
   std::cout <<  "   |\n";
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout <<  "|    ";
   std::cout <<  "   |\n";
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout <<  "|   \xE2\x98\xA2";
   std::cout <<  "   |\n";
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout <<  "|    ";
   std::cout <<  "   |\n";
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout <<  "|    ";
   std::cout <<  handcards.back() << "|\n";
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout <<  "\xE2\x98\xA3----";
   std::cout <<  "---\xE2\x98\xA3\n";
   std::cout << "\nYour score: " << score << "\n";
   if(ace == true){
    std::cout << "Do you want yout Ace as 1 or 11?\n";
    getline(cin, aceans);
    if (aceans == "1") {
    score += 1;
    }
    else if (aceans == "11") {
    score += 11;
    } else{
		std::cout << "Wrong answer, ADIOS!";
	  this_thread::sleep_for(chrono::milliseconds(1000));
		exit(0);}
    ace = false;
  }
   
   
   if(score > 21){
	   system("clear");
	  std::cout << "\nPCs cards: \n";
	for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "\xE2\x98\xA3----";
 std::cout <<  "---\xE2\x98\xA3\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|" << *i << " ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|   \xE2\x98\xA2";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  bot_handcards.back() << "|\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "\xE2\x98\xA3----";
 std::cout <<  "---\xE2\x98\xA3\n";
 std::cout << "\nPCs score: " << bot_score << "\n";
    std::cout <<  "\nYour cards: \n";
    handcards.erase(std::remove(handcards.begin(), handcards.end(), ""), handcards.end());
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "\xE2\x98\xA3----";
    std::cout <<  "---\xE2\x98\xA3\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "|" << *i << " ";
    std::cout <<  "   |\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "|    ";
    std::cout <<  "   |\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "|   \xE2\x98\xA2";
    std::cout <<  "   |\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "|    ";
    std::cout <<  "   |\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "|    ";
    std::cout <<  handcards.back() << "|\n";
    for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
    std::cout <<  "\xE2\x98\xA3----";
    std::cout <<  "---\xE2\x98\xA3\n";
	std::cout << "\nYour score: " << score << "\n";
	if(bot_score > 21){
		std::cout << "\nDraw!";
		return(0);
	}
	if(bot_score < 21){
		std::cout << "\nYou lost!";
		return(0);
	}
	if(bot_score == 21){
		std::cout << "\nYou lost!";
		return(0);
	}
	  }
   std::cout <<  "\nhit[1] or stand[2] ? ";
   getline(cin, ans);
   if (ans == "1") {
	   system("clear");
   loopy = false;
   }
   else if (ans == "hit") {
	   system("clear");
   loopy = false;
   }
   else if (ans == "2"){
   loopy = true;
   system("clear");
   std::cout << "\nPCs cards: \n";
	for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "\xE2\x98\xA3----";
 std::cout <<  "---\xE2\x98\xA3\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|" << *i << " ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|   \xE2\x98\xA2";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  bot_handcards.back() << "|\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "\xE2\x98\xA3----";
 std::cout <<  "---\xE2\x98\xA3\n";
 std::cout << "\nPCs score: " << bot_score << "\n";
   std::cout <<  "\nYour cards: \n";
   handcards.erase(std::remove(handcards.begin(), handcards.end(), ""), handcards.end());
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout <<  "\xE2\x98\xA3----";
   std::cout <<  "---\xE2\x98\xA3\n";
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout  << "|" << *i << " ";
   std::cout  << "   |\n";
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout  << "|    ";
   std::cout  << "   |\n";
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout  << "|   \xE2\x98\xA2";
   std::cout  << "   |\n";
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout  << "|    ";
   std::cout  << "   |\n";
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout <<  "|    ";
   std::cout <<  handcards.back() << "|\n";
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout <<  "\xE2\x98\xA3----";
   std::cout <<  "---\xE2\x98\xA3\n";
   std::cout << "\nYour score: " << score << "\n";
   if(bot_score > 21){
		if(score > 21){
			std::cout << "\nDraw!";
			return(0);
		}
		if(score < 21){
			std::cout << "\nYou win!";
			return(0);
		}
		if(score == 21){
			std::cout << "\nYou win!";
			return(0);
		}
	}
	if(bot_score < 21){
	if(score < 21){
	if(score > bot_score){
		std::cout << "\nYou win!";
		return(0);
	}
    if(score < bot_score){
		std::cout << "\nYou lost!";
		return(0);
	}
	}
	if(score > 21){
		std::cout << "\nYou lost!";
		return(0);
	}
	}
	if(score == 21){
		if(bot_score == 21){
			std::cout << "\nDraw!";
			return(0);
		}
		if(bot_score > 21){
			std::cout << "\nYou win!";
			return(0);
		}
		if(bot_score < 21){
			std::cout << "\nYou win!";
			return(0);
		}
	}
	if(bot_score == 21){
		if(score == 21){
			std::cout << "\nDraw!";
			return(0);
		}
		if(score > 21){
			std::cout << "\nYou lost!";
			return(0);
		}
		if(score < 21){
			std::cout << "\nYou lost!";
			return(0);
		}
	}
       }
  
  else if (ans == "stand"){
   loopy = true;
   system("clear");
   std::cout << "\nPCs cards: \n";
	for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "\xE2\x98\xA3----";
 std::cout <<  "---\xE2\x98\xA3\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|" << *i << " ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|   \xE2\x98\xA2";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  "   |\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "|    ";
 std::cout <<  bot_handcards.back() << "|\n";
 for (std::vector<string>::const_iterator i = bot_handcards.begin(); i !=bot_handcards.end(); ++i)
 std::cout <<  "\xE2\x98\xA3----";
 std::cout <<  "---\xE2\x98\xA3\n";
 std::cout << "\nPCs score: " << bot_score << "\n";
   std::cout <<  "\nYour cards: \n";
   handcards.erase(std::remove(handcards.begin(), handcards.end(), ""), handcards.end());
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout <<  "\xE2\x98\xA3----";
   std::cout <<  "---\xE2\x98\xA3\n";
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout  << "|" << *i << " ";
   std::cout  << "   |\n";
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout  << "|    ";
   std::cout  << "   |\n";
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout  << "|   \xE2\x98\xA2";
   std::cout  << "   |\n";
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout  << "|    ";
   std::cout  << "   |\n";
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout <<  "|    ";
   std::cout <<  handcards.back() << "|\n";
   for (std::vector<string>::const_iterator i = handcards.begin(); i !=handcards.end(); ++i)
   std::cout <<  "\xE2\x98\xA3----";
   std::cout <<  "---\xE2\x98\xA3\n";
   std::cout << "\nYour score: " << score << "\n";
   if(bot_score > 21){
		if(score > 21){
			std::cout << "\nDraw!";
			return(0);
		}
		if(score < 21){
			std::cout << "\nYou win!";
			return(0);
		}
		if(score == 21){
			std::cout << "\nYou win!";
			return(0);
		}
	}
	if(bot_score < 21){
	if(score < 21){
	if(score > bot_score){
		std::cout << "\nYou win!";
		return(0);
	}
    if(score < bot_score){
		std::cout << "\nYou lost!";
		return(0);
	}
	}
	if(score > 21){
		std::cout << "\nYou lost!";
		return(0);
	}
	}
	if(score == 21){
		if(bot_score == 21){
			std::cout << "\nDraw!";
			return(0);
		}
		if(bot_score > 21){
			std::cout << "\nYou win!";
			return(0);
		}
		if(bot_score < 21){
			std::cout << "\nYou win!";
			return(0);
		}
	}
	if(bot_score == 21){
		if(score == 21){
			std::cout << "\nDraw!";
			return(0);
		}
		if(score > 21){
			std::cout << "\nYou lost!";
			return(0);
		}
		if(score < 21){
			std::cout << "\nYou lost!";
			return(0);
		}
	}
       
  } else{
	  std::cout << "Wrong answer, ADIOS!";
	  this_thread::sleep_for(chrono::milliseconds(1000));
	  exit(0);}
  }
  return 0;
}



int main()
{
	bool again = true;
	string againans;
	system("clear");
    setlocale(LC_ALL, "en_US.utf8");
    called();
	while(again = true){
	std::cout << "\n\nDo you want to play again? yes[1] or no[2]\n";
    getline(cin, againans);
	if(againans == "1"){
		called();
	}
	if(againans == "yes"){
		called();
	}
	if(againans == "2"){
		exit(0);
	}
	if(againans == "no"){
		exit(0);
	}
	}
    return 0;
}
