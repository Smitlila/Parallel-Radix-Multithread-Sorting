// Smit Lila
// Class (CECS 325-02)
// Project Name (Prog 5 - Threads)
// Due Date (11/02/2023)
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        cout << "Please enter 3 parameters:\n";
        cout << "    Parameter 1: total count of numbers you want.\n";
        cout << "    Parameter 2: min value.\n";
        cout << "    Parameter 3: max value.\n";
        cout << "Example: %generate 10000000 100000 999999\n";
        exit(EXIT_SUCCESS);
    }

    for(int i=0; i<argc; i++)
    {
        cout << "argv["<<i<<"]:" << argv[i]<<endl;
    }

    int COUT = stoi(argv[1]);
    int MIN = stoi(argv[2]);
    int MAX = stoi(argv[3]);

    ofstream fout;
    fout.open("numbers.dat", ios::out|ios::trunc );
    for (int i = 0; i<COUT; i++)
    {
        fout<< (rand() % (MAX-MIN+1) + MIN) << endl;
    }
    fout.close();
    return 0;
}