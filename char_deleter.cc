/**
 *   @file: char_deleter.cc
 * @author: Jonah Brautigam
 *   @date: 3/4/2021
 *  @brief: Deletes specified character from file and outputs into a new file
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cctype>
using namespace std;

string inputAndOutput (string &input_file, string &output_file);

void newFile (string input_file, string output_file, ifstream &inStream, ofstream &outStream);

int main(int argc, char const *argv[]) {

    string input_file;
    string output_file;
    ifstream inStream;
    ofstream outStream;
    
    inputAndOutput (input_file, output_file);

    newFile (input_file, output_file, inStream, outStream);

    return 0;
} /// main

string inputAndOutput (string &input_file, string &output_file)
{
    cout << "Enter input file name: "; //Asks user for input file
    cin >> input_file;

    cout << "\nEnter output file name: "; //Asks user for output file
    cin >> output_file;

    return input_file;
    return output_file;
}

void newFile (string input_file, string output_file, ifstream &inStream, ofstream &outStream)
{
    inStream.open(input_file); //Opens input file
    if (inStream.fail())
    {
        cout << "\nError: File does not exist or cannot be opened" << endl;
        exit(0);
    }
    
    outStream.open(output_file); //Opens output file
    if (outStream.fail())
    {
        cout << "\nError: File does not exist or cannot be opened" << endl;
        exit(0);
    }

    char user_ch;
    char ch;

    inStream.get(ch);
    while(!inStream.eof())
    {
        if (user_ch == ch)
        {
            inStream.ignore(0,ch);
        }
        else
        {
            outStream << ch;
        }
        inStream.get(ch);
    }


    inStream.close();
    outStream.close();
}
