#include "headers.h"
#include <vector>
#include <iostream>
using namespace std;



int main()
{
    cout << "Welcome to the Game of Life!" << endl;
    int Width, Height, Type, again;
    long Steps;
    m:
    again = 0;
    cout << endl <<"Enter the field options:" << endl << endl <<  "Width - ";
    cin >> Width;//¬вод ширины пол€
    cout << endl << "Height - ";
    cin >> Height;//¬вод высоты пол€
    cout << endl << "Type (Limited - 0, Endless - 1) - ";
    cin >> Type;//¬вод типа пол€
    cout << endl;
    Field GoL(Height,Width,Type);//»нициализаци€ пол€
    GoL.setField();//¬вод пол€ с клавиатуры
    cout << endl;
    cout << "How many steps? " ;
    cin >> Steps;//¬вод числа шагов
    cout << endl;
    GoL.Show();
    cout << endl;
    for (int i = 0; i < Steps; i++){
        cout << "Step number " << i + 1 << endl << endl;
        GoL.Step();
        GoL.Show();
        cout <<endl <<endl;
        //GoL.ShowAll();
    }
    cout <<endl<< "Play again? (1 -yes, 0 - no) ";
    cin >> again;
    if (again == 1)
        goto m;
    //GoL.ShowAll();
    return 0;
}
