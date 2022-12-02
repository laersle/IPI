#include "fcpp.hh"

//in der fcpp.hh wurde in der print-template funktion das std::endl in ein std::flush geändert damit der Output schöner formatiert werden kann

void printarr(int arr[], int size){         //prints an array formatted (not used here)
    print('[');
    for (int i = 0; i < size; ++i) {
        print(arr[i]);
        print(", ");
    }
    print("]\n");
}

void reset_deck(int deck[], int size){      //fills an array from 1 to n-1 ascending
    for (int i = 0; i < size; ++i) {
        deck[i] = i+1;
    }
}

bool check_deck(const int deck[], int size){    //true when elements in array are ascending, false else
    for (int i = 0; i < size - 1; ++i) {
        if (deck[i] > deck[i+1]) return false;
    }
    return true;
}

void shuffle_deck_in(int deck[], int size){             //shuffels the array
    if (size%2 != 0){                                   //1. check if even, since program might produce unexpected output otherwise
        print("size must be an even number!\n");
        return;
    }
    //split deck                                        //2. make 2 arrays with half the size
    int firstHalf[size/2];
    int secondHalf[size/2];
    for (int i = 0; i < size/2; ++i) {                  //write first half of deck to 1
       firstHalf[i] = deck[i];
    }
    for (int i = size/2; i < size; ++i) {               //second half of deck to the other
        secondHalf[i-size/2] = deck[i];
    }
    //shuffle deck
    int j = 0;
    for (int i = 0; i < size; i+=2) {                   //put elements of two halfs alternating in deck
        deck[i] = firstHalf[j];
        deck[i+1] = secondHalf[j];
        j++;
    }
}

void shuffle_deck_out(int deck[], int size){    //similar to shuffel_deck_in
    if (size%2 != 0){
        print("size must be an even number!\n");
        return;
    }
    //split deck
    int firstHalf[size/2];
    int secondHalf[size/2];
    for (int i = 0; i < size/2; ++i) {
        firstHalf[i] = deck[i];
    }
    for (int i = size/2; i < size; ++i) {
        secondHalf[i-size/2] = deck[i];
    }
    //shuffle deck
    int j = 0;
    for (int i = 0; i < size; i+=2) {
        deck[i+1] = firstHalf[j];
        deck[i] = secondHalf[j];
        j++;
    }
}

int main(){
    int mydeck[32];

    //shuffel-in Test
    print("Shuffle-In-Test:\nThe Deck is back in its original order after ");
    reset_deck(mydeck, 32);
    shuffle_deck_in(mydeck, 32);
    int counter1 = 1;                                 //counts number of shuffels
    while (!check_deck(mydeck, 32)){        //reshuffle until deck is back to its original order
        shuffle_deck_in(mydeck, 32);
        counter1++;
    }
    print(counter1, "Perfect In-Shuffles\n", 0);

    //shuffel-out Test
    print("Shuffle-Out-Test:\nThe Deck is back in its original order after ");
    reset_deck(mydeck, 32);
    shuffle_deck_out(mydeck, 32);
    int counter2 = 1;
    while (!check_deck(mydeck, 32)){
        shuffle_deck_out(mydeck, 32);
        counter2++;
    }
    print(counter2, "Perfect Out-Shuffles\n", 0);
    return 0;
}