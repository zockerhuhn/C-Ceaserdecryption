#include <iostream>
#include <algorithm>
#include <string>
#include "lowlist.h"
#define string std::string

string letters = "abcdefghijklmnopqrstuvwxyz";
string walloftext[26];

void caeserdecrypt(string original, int key)
{
    string letterswithkey = "";
    for (int i=0; i<26; i++)
        {
        letterswithkey += letters[(i+key)%26];
        }
    string result = "";
    for (char symbol : original)
    {
        if (letters.find(symbol) != string::npos)
        {
            result += letterswithkey[letters.find(symbol)];
        }
    }
    walloftext[key-1] = result;
    if (key < 26)
    {
        caeserdecrypt(original, (key+1));
    }
}

int checktext(string texttocheck)
{
    int amount = 0;
    for (string word : listofwords)
    {
        if (texttocheck.find(word) != string::npos)
        {
            amount++;
        }
    }
    return amount;
}

int main() 
{
    int bestscore = 1;
    string endresult = "";
    string message = "Diesisteinbeispielsatzfuerdiecaeserverschluesselung";
    std::transform(message.begin(), message.end(), message.begin(), ::tolower);
    caeserdecrypt(message, 1);
    for (string sentence : walloftext)
    {
        int score = checktext(sentence);
        if (score == bestscore)
        {
            endresult += "\n" + sentence;
        }
        else if  (score > bestscore)
        {
            endresult = sentence;
            bestscore = score;
        }
    }
    std::cout << "most matches (" << bestscore << ") in word(s):  " << endresult;
}