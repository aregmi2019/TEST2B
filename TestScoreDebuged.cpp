// Test Scores Debug
// Debugged by Abhishek Regmi.
// Program Debugged.

#include <iostream>
#include <iomanip>
#include <fstream>            //Debug-1: Missed to declare fstream


using namespace std;
 
void readData(ifstream& inputFile, int list[], int size);
void holdscrn( );    // void function to hold screen open before exit
void print(int List[], int size);             //Debug-2: Missed to declare the print function



int main()
{
    int scores[8] = {0};

    ifstream infile;

    infile.open("TestScoresData.txt");

    if (!infile)                                //Debug-4: wrong condition. missed '!'.
    {
        cout << "Cannot open the input file. Program terminates!"
             << endl;
        holdscrn( );   // Hold screen before exit
        return 1;
    }

    readData(infile, scores, 8);
    print(scores, 8);
    cout << endl;

    infile.close();
    
    holdscrn( );   // Hold screen before exit
    return 0;
}

void readData(ifstream& inputFile, int list[], int size)
{
    int score;
    int index;

    //cin >> score;               //Debug;5- Not a necessary input.

    while (inputFile)
    {
        index = score / 25;

        if (index == size)
            index--;
        if (index < size)
            list[index]++;

        inputFile >> score;
    }
    return;                            //Debug:3: returned an integer when the function is void
}

void print(int list[], int size)
{
    int range;
    int lowRange = 0;
    int upperRange = 24;

    cout << "   Range       # of Students" << endl;

    for (range = 0; range < size; range++)
    {
        cout << setw(3) << lowRange << " - " <<setw(3)        //Debug:6- missed to set width to 3.
             << upperRange << setw(15)
             << list[range] << endl;
        lowRange = upperRange + 1;
        upperRange = upperRange + 25;
        if (range == size - 2)
            upperRange++;
    }
    cout << endl;
    return;
}

void holdscrn( )   // void function to hold screen open before exit
{
    char holdscreen;
    cout << "\n\n\tEnter one character and press return to exit program:  ";
    cin >> holdscreen;

    return;
}
