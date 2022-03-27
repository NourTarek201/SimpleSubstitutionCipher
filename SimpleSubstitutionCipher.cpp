// Program Name: SimpleSubstitutionCipher.cpp
// Program Description:Simple substitution cipher
// Last Modification Date: 24/3/2022
// Author : Nour Tarek Sayed
// Contact: Nourtarrek.2@gmail.com
// Purpose: Simple substitution cipher where the user enters a key of 5 letters to substitute the first 5 letters in alphabets and remove any repeated letter to cipher a message and to decipher a code

#include <iostream>
#include "sstream"
#include "string"
#include "map"
#include<bits/stdc++.h>

using namespace std;
string key, message,answer;
//Array of alphabets
char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                     'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char i;

//function to remove the letters in the key from the array to avoid repeating
void removerepeat(int j){
    for (i = 5; i < 31; i++) {
        if (alphabet[i] == key[j]) {
            alphabet[i] = alphabet[i + 1]; //substitute common letters between key and array with the next char in array
            if (alphabet[i] == alphabet[i + 1]) {
                for (i = i; i < 31; i++)
                    alphabet[i] = alphabet[i + 1];//shift the array backward to remove repeated letters
            }}}}


//map to cipher the message with the updated array
map<char, char> cipher{
        {'a', alphabet[0]},
        {'b', alphabet[1]},
        {'c', alphabet[2]},
        {'d', alphabet[3]},
        {'e', alphabet[4]},
        {'f', alphabet[5]},
        {'g', alphabet[6]},
        {'h', alphabet[7]},
        {'i', alphabet[8]},
        {'j', alphabet[9]},
        {'k', alphabet[10]},
        {'l', alphabet[11]},
        {'m', alphabet[12]},
        {'n', alphabet[13]},
        {'o', alphabet[14]},
        {'p', alphabet[15]},
        {'q', alphabet[16]},
        {'r', alphabet[17]},
        {'s', alphabet[18]},
        {'t', alphabet[19]},
        {'u', alphabet[20]},
        {'v', alphabet[21]},
        {'w', alphabet[22]},
        {'x', alphabet[23]},
        {'y', alphabet[24]},
        {'z', alphabet[25]}
};

int main () {
    istringstream ascin("");//string similar to cin function
    cout << "Enter the key that you will use..please notice that only the first 5 letters that will be taken to begin  " << endl;
    getline(cin, key);

    cout<<"Please choose;\n1)Cipher a message\n2)Descipher a message"<<endl;
    getline(cin,answer);


    //shifting array forward to add letters in the key
    for (i = 31; i >= 0; i--) {
        alphabet[i] = alphabet[i - 5];
    }
    cout << endl;

    //make the key letters the first 5 letters of array
    for (i = 0; i < 5; i++)
        alphabet[i] = key[i];


    //check repeated letters between array and key and remove it
    while (true) {
        removerepeat(0);
        removerepeat(1);
        removerepeat(2);
        removerepeat(3);
        removerepeat(4);
        break;
    }
//map to cipher the message with the updated array
    map<char, char> cipher{
            {'a', alphabet[0]},
            {'b', alphabet[1]},
            {'c', alphabet[2]},
            {'d', alphabet[3]},
            {'e', alphabet[4]},
            {'f', alphabet[5]},
            {'g', alphabet[6]},
            {'h', alphabet[7]},
            {'i', alphabet[8]},
            {'j', alphabet[9]},
            {'k', alphabet[10]},
            {'l', alphabet[11]},
            {'m', alphabet[12]},
            {'n', alphabet[13]},
            {'o', alphabet[14]},
            {'p', alphabet[15]},
            {'q', alphabet[16]},
            {'r', alphabet[17]},
            {'s', alphabet[18]},
            {'t', alphabet[19]},
            {'u', alphabet[20]},
            {'v', alphabet[21]},
            {'w', alphabet[22]},
            {'x', alphabet[23]},
            {'y', alphabet[24]},
            {'z', alphabet[25]}
    };
    while(true){
        if (answer == "1") {
            //begin to cipher
            cout << "Please enter the message to cipher " << endl;
            getline(cin, message);
            transform(message.begin(), message.end(), message.begin(), ::tolower);


            for (char i: message)
                cout << cipher[i] << "";
            break;
        }
        if (answer == "2" ) {
            cout << "Please enter the message to dicipher " << endl;
            string code;
            getline(cin, code);


            char token;
            ascin.str(code); //make ascin function to read the input
            ascin >> token; //store input into a variable
            int i;
            while (ascin)//if there is a value in ascin function it will consider as true
            {
                for (char i = 97; i < 123; i++) {
                    if (cipher[i] == token) {
                        cout << i;
                    }

                }
                ascin >> token;

            }
            cout << endl;
            break;
        }
        else {
            cout << "Please choose 1 or 2 ...try again " << endl;
            continue;}
    }}






