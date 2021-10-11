#include <iostream>
#include <cmath>
#include<ctime>
#include <string>
using namespace std;

int main ()
{
	string name;
	char letter;
	int wrongGuesses=0;
	string word;
	string words[] =
	{
		"piano",
		"petunia",
		"music",
		"chess",
		"mongolia",
		"curtains",
		"printer",
		"ephemeral",
		"software",
		"pencil",
		"computer",
		"macarons",
		"peaches",
	};

	srand(time(NULL));
	int n=rand()% 10;
	word=words[n];
    
    const int MAX=5;
    int letterFill (char, string, string&);
	
	string unknown(word.length(),'*');
	
	cout<<"What's your name?\n";
	cin>>name;

	cout<<"\n\nWelcome, "<<name<<" to";
	cout<<"\n\n------٩(＾◡＾)۶---GUESS THE WORD!---(＾▽＾)-------";
	cout<<"\n\nEach letter is represented by this star *";
	cout<<"\n\nYou can only type one letter in one try";
	cout<<"\n\nYou have "<<MAX<<" tries";
	cout<<"\n\nRemember, all letters of your guess should be lowercase!";
	cout<<"\n-----------------------------------------------------";
    
	
	while (wrongGuesses < MAX)
	{
		cout<<"\n\n"<<unknown;
		cout<<"\n\nGuess a letter: ";
		cin>>letter;
		if(letterFill(letter, word, unknown)==0)
		{
			cout<<endl<<"Oof! That letter isn't in there! (ノ﹏ヽ)\nTry again!"<<endl;
			wrongGuesses++;
		}
		else
		{
			cout<<endl<<"Hurray! You found a letter! （‐＾▽＾‐）"<<endl;
		}
		
		cout<<"You have "<<MAX - wrongGuesses;
		cout<<" guesses left."<<endl;
		
		if (word==unknown)
		{
			cout<<word<<endl;
			cout<<"WOOOOO! You got it! ☆.+:^ヽ(∇￣*)o♪Congratulations!♪ｏ(*￣∇)ﾉ^;+.☆.";
			break;
			return 0;
		}
	}
	if(wrongGuesses==MAX)
	{
		cout<<"\nSorry, you've used up all your guesses. ╥﹏╥"<<endl;
		cout<<"The word was : "<<word<<endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}


int letterFill (char guess, string secretword, string &guessword)
{
	int x;
	int matches=0;
	int len=secretword.length();
	for(x=0;x< len;x++)
	{
		if(guess==guessword[x])
			return 0;
		if(guess==secretword[x])
		{
			guessword[x] = guess;
			matches++;
		}
	}
	return matches;
	return 0;
}

