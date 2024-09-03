#include <iostream>
#include <algorithm>
#include <string>
#include "lowlist.h"
#include "e.h"
#define string std::string

string letters = "abcdefghijklmnopqrstuvwxyz";
string walloftext[26];

string caeserdecrypt(string original, int key, bool recursive=true)
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
        else
        {
            result += symbol;
        }
    }
    if (recursive)
    {
        walloftext[key-1] = result; 
        if (key < 26)
        {
            caeserdecrypt(original, (key+1));
        }
    }
    else
    {
        return result;
    }
    return "";
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
    int bestkey;
    string endresult = "";
    std::transform(message.begin(), message.end(), message.begin(), ::tolower);
    string messageforprocessing = "";
    for (int i=0; i<50; i++)
    {
        messageforprocessing += message[i];
    }
    caeserdecrypt(messageforprocessing, 0);
    for (int i=0; i<26; i++)
    {
        int score = checktext(walloftext[i]);
        if (score == bestscore)
        {
            endresult += "\n" + walloftext[i];
        }
        else if  (score > bestscore)
        {
            endresult = walloftext[i];
            bestscore = score;
            bestkey = i+1;
            if (score >= 10)
            {
                break;
            }
        }
    }
    //std::cout << "most matches (" << bestscore << ") in word(s):  " << caeserdecrypt(message, bestkey, false);
}