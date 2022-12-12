#include "fcpp.hh"

//in der fcpp.hh wurde in der print-template funktion das std::endl in ein std::flush geändert damit der Output schöner formatiert werden kann

int arr[10];

void printarr(){
    print('[');
    for (int i = 0; i < 10 ; ++i) {
        print(arr[i]);
        print(", ");
    }
    print("]\n");
}

void sortarray(int lastplace){   //bubble sort up to the lastplace -> 0s will stay last
    int temp;
    for (int i = 0; i < lastplace; i++)
    {
        for (int j = 0; j + 1 < lastplace - i; j++)
        {
            // Swaping the elements if first one
            // is greater than second one.
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            }
        }
    }
}

void insertArray(int input){
    for (int k = 0; k < 10; ++k) {
        if(arr[k] == 0){
            arr[k] = input;
            sortarray(k);
            break;
        }
    }
}

int main(){
    for (int i = 0; i < 10; ++i){
        int input = enter_int();
        if (input == -1) return 0;
        if (input < -1){
            print("Unerlaubte Eingabe!\n");
                break;
        }
        else if (input == 0) printarr();
        else insertArray(input);
    }
    printarr();
    return 0;
}