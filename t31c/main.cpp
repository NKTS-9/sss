#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <array>
using namespace std;

struct Design
{
    int id;
    string nd;
    string st;
    int pr;
};

int i;
char ch;

int Menu()
{
    system("cls");
    cout<< "1: Read"<< endl
    << "2: Display"<< endl
    << "3: Edit"<< endl
    << "4: Search"<< endl
    << "5: Save"<< endl
    << "6: Exit"<< endl << endl << "Input your code. ";
    return ch;
}

void Read(Design arr[]){
    ifstream input;
    input.open("t31c");

    if(!input)
    {
    cout<< "Read: Error" << endl << "Press any key"<< endl;
    }
    else
    {
    for(int i=0; i<=5; i++)
    {arr[i].id = i+1;
    input>> arr[i].id>> arr[i].nd >> arr[i].st >> arr[i].pr;}
    }
    input.close();
    cout<< "Read: Success!" << endl << "Press any key.";
    }

void Display(Design arr[]) {
    cout << "\nStructure: \n" << endl;
    cout.setf(std::ios::left);
    cout.fill(' '); cout.width(5); cout<< "1.ID";
    cout.fill(' '); cout.width(15); cout<< "2.Name";
    cout.fill(' '); cout.width(15); cout<< "3.Style";
    cout.fill(' '); cout.width(15); cout<< "4.Price" << endl;

    for(i=0; i<=5; i++)
    {cout.fill(' '); cout.width(5); cout<< arr[i].id;
    cout.fill(' '); cout.width(15); cout<< arr[i].nd;
    cout.fill(' '); cout.width(15); cout<< arr[i].st;
    cout.fill(' '); cout.width(15); cout<< arr[i].pr << endl;}
    cout << "\nPress any key.";
}

void Edit(Design arr[]) {
    int line;
    do {
    cout<< "\n Enter a line id";
    cin >> line;
    line = line - 1;
    } while (line<0 || line >=5);
    int i=1;
    while(i==1) {
    cout << "\nEnter a column in";
    int column;
    cin >> column;
    cout << "Change" ;
    switch(column) {
    case 1: {cout<< arr[line].nd << ": "; cin >> arr[line].nd; i =0;} break;
    case 2: {cout << arr[line].st << ": "; cin >> arr[line].st; i = 0;}break;
    case 3: {cout<< arr[line].pr << ": "; cin >> arr[line].pr; i = 0;} break;
    default: cout << "Error!";
}}}

void Save(Design arr[], int maxpr) {
    string outputfilename;
    cout<< "\nOut.txt?" << "\n\ty - Yeep\n\t0.Nope\n";
    char ch;
    if (ch == 'y') outputfilename = "Out.txt";
    if (ch != 'y'){
    cout << "Enter a output file name\n";
    cin >> outputfilename;}
    ofstream Output;
    Output.open(outputfilename);
    Output.setf(std::ios::left);
    Output.fill(' '); Output.width(3); Output<< "1.ID";
    Output.fill(' '); Output.width(10); Output<< "2.Name";
    Output.fill(' '); Output.width(10); Output<< "3.Style";
    Output.fill(' '); Output.width(10); Output<< "4.Price" << endl;

    for(i=0; i<=2; i++)
    {Output.fill(' '); Output.width(3); Output<< arr[i].id;
    Output.fill(' '); Output.width(10); Output<< arr[i].nd;
    Output.fill(' '); Output.width(10); Output<< arr[i].st;
    Output.fill(' '); Output.width(10); Output<< arr[i].pr << endl;}
    Output << "\nLatest person: "<< endl;
    Output.fill(' '); Output.width(3); Output << arr[maxpr].id;
    Output.fill(' '); Output.width(10); Output << arr[maxpr].nd;
    Output.fill(' '); Output.width(10); Output << arr[maxpr].st;
    Output.fill(' '); Output.width(10); Output << arr[maxpr].pr;
    Output.close();
     cout<< "Save: Success!" << "\nPress any key.";
}

 int Search(Design arr[]) {
     int maxpr = 0;
     int Z = arr[0].pr;

     for(i = 1; i<=3; i++){
     if(Z <= arr[i].pr){
     Z = arr[i].pr;
     maxpr = i;
     }
}
     cout<< "\n\tExpensive: " << endl;
     cout << arr[maxpr].id << " "<< arr[maxpr].nd << " "<< arr[maxpr].st << " "<< arr[maxpr].pr << endl;

     return maxpr;
 }

int main()
{
    Design *Arr = new Design[20];
    i = 1;
    int maxpr = 0;
    do {
     ch = Menu(); cin >> ch;
    switch(ch) {
    case '1': Read(Arr); break;
    case '2': Display(Arr); break;
    case '3': Edit(Arr); break;
    case '4': maxpr = Search(Arr); break;
    case '5': Save(Arr, maxpr); break;
    case '6': { delete[]Arr; Arr = NULL; exit(1);} break;
}
}
while (ch != 7);
    return 0;
}
