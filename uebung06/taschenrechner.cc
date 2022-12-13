#include "fcpp.hh"
#include <string.h>
#include <iostream>

// Definiton and implementation of Stack----------------------------------------------------------------------
struct Stack {
    int counter;
    int stack[100];

    Stack(){   //Constructor that sets counter to 0 and initializes the array
        counter = 0;
        for (int i = 0; i < 100; ++i) {
            stack[i] = 0;
        }
    }

    bool empty(){
        if (counter == 0) return true;
        else return false;
    }

    int pop(){  //returns top item of stack
        if (!empty()){
            counter--;
            return stack[counter];
        }
        else throw std::runtime_error("tried to pop from an empty Stack");  //bitte kein Punktabzug wegen dem throw :) wir hier nur benutzt um Fehlermeldungen zu generieren und das Programm anzuhalten (wird nicht gecatched)
    }

    void push(int dataToPush){  //put data on Stack
        if (counter >= 100) throw std::runtime_error("exceeded maximum of stack");
        stack[counter] = dataToPush;
        counter++;
    }

    void printStack(){  //prints contents of stack to console
        for (int i = 0; i < counter; ++i) {
            std::cout << stack[i] << ", ";
        }
        std::cout << std::endl;
    }
};

Stack mystack;  //global instance of Stack

//functions of taschenrechner---------------------------------------------------------------------------------
unsigned int buildInt(char* buffer, int buffercount){    //builds int from array of char by accumulating a_i*10^b_j
    unsigned int sum = 0;
    for (int i = 0; i < buffercount; ++i) {
        sum += (buffer[i]-48) * std::pow(10, buffercount-1-i);
    }
    return sum;
}

int parseInput(char* arg){  //interprets input and does the necessary calculations
    char buffer[10];           //10 digits is enough since the max an uint holds is 4,294,967,295
    int buffercounter = 0;     //represents elements in buffer


    for (int i = 0; i <= strlen(arg); i = i+1)  //iterates over every char in string
    {
        char currentChar = arg[i];

        switch (currentChar) {

            case 42:                                                                    //'*'
                //check if there are 2 elements on stack to perform calc on
                if (mystack.counter < 2) throw std::runtime_error("Syntax Error!");
                mystack.push(mystack.pop() * mystack.pop());
                break;


            case 43:                                                                    //'+'
                if (mystack.counter < 2) throw std::runtime_error("Syntax Error!");
                mystack.push(mystack.pop() + mystack.pop());
                break;


            case 45:                                                                    //'-'
                if (mystack.counter < 2) throw std::runtime_error("Syntax Error!");
                {   //order of Elements matters
                    int last = mystack.pop();
                    int beforelast = mystack.pop();
                    mystack.push(beforelast - last);
                }
                break;


            case 47:                                                                    //'/'
                if (mystack.counter < 2) throw std::runtime_error("Syntax Error!");
                {   //order of Elements matters
                    int last = mystack.pop();
                    int beforelast = mystack.pop();
                    mystack.push(beforelast / last);
                }
                break;


            default:
                if (currentChar >= 48 && currentChar <= 57){    //digit '0'-'9'
                    if (buffercounter >= 10) throw std::runtime_error("The biggest supported number (4,294,967,295) was exceeded"); //only roughly correct
                    buffer[buffercounter] = currentChar;    //put digit in buffer
                    buffercounter++;
                }

                else{                                                                       //if it's any other char check if there are digits in buffer, if not ignore, else
                    if (buffercounter > 0){
                        mystack.push(buildInt(buffer, buffercounter));  //build int from chars and push on stack
                        buffercounter = 0;
                    }
                }

        }
    }

    //if more than 1 element is on the stack after every character of the string has been read -> error
    if (mystack.counter > 1) throw std::runtime_error("Syntax Error!");
    //else the element is the result
    return mystack.pop();
}

int main(int argc, char* argv[])
{
  // fange kein Kommandozeilenargument ab
  if (argc < 2)  throw std::runtime_error("expected arguments but none were given");

  // arg enthaelt die als Eingabe von der Kommandozeile uebergebene Zeichenfolge
  char* arg = argv[1];
  std::cout << parseInput(arg) << std::endl;


  //delete
  char buf2[] = "67 55 - 54 6 / + 2 *";
  char buf3[] = "123456789987654321";
  char buf4[] = "2 7 * - 4 +";
  char buf5[] = "16 2 2 4 2 /*Dies ist (k?)ein Kommentar*/ 4 2 / *";

//  std::cout << parseInput(buf2) << std::endl;
//  //std::cout << parseInput(buf3) << std::endl;
//  //std::cout << parseInput(buf4) << std::endl;
//  std::cout << parseInput(buf5) << std::endl;

  return 0;
}
