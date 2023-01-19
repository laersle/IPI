#include <iostream>

struct IntListElem {
    IntListElem* next;  // Zeiger auf nächstes Element
    int value;          // Daten zu diesem Element
} ;

class IntList {
public:
// Konstruktor, erzeugt eine leere Liste
    IntList();

// Copy-Konstruktor
    IntList(const IntList &l);

// Destruktor, loescht gesamten Listeninhalt
    ~IntList();

// Gibt Anzahl der Elemente zurueck
    int getCount();

// Gibt zurueck, ob die Liste leer ist
    bool isEmpty();

// Gibt die Liste aus
    void print();

// Fuegt die Zahl 'element' an der (beliebigen) Position 'position' ein
    void insert(int element, int position);

// Fuegt die Zahl am Ende der Liste ein (wenn kein Positionsargument übergeben wird, durch Überladen der Methode insert)
    void insert(int element);

// Loescht das Element an der Position 'position'
    void remove(int position);

// Gibt den Wert des Elements an der Position 'position' zurueck
    int getElement(int position);

// Zuweisung
    IntList& operator=(const IntList &l);

private:
    int count;              // Anzahl Elemente in der Liste
    IntListElem* first;     // Zeiger auf erstes Element der Liste

    IntListElem* findElementAtNthPosition(int n) const;   //gets the Pointer to Element at nth position

};

//Implementierung-------------------------------------------------------------------------------------
IntList::IntList() {
    count = 0;
    first = 0;
}

IntList::IntList(const IntList &l) {
    count = 0;
    first = 0;
    for (int i = 1; i <= l.count; ++i) {    //copy elements from l
        insert(l.findElementAtNthPosition(i)->value);
    }
}

IntList::~IntList() {
    for (int i = count-1; i >= 0 ; --i) {  //remove all Elements and thus release memory
        remove(i);
    }
}

int IntList::getCount() { return count; }

bool IntList::isEmpty() {
    if (count == 0) return true;
    return false;
}

void IntList::print() {

    std::cout << "Inhalt von OBJ " << this << ": [ ";
    for (IntListElem* p = first; p != 0; p = p->next) {
        std::cout << p->value << ", ";
    }
    std::cout << "]" << std::endl;
}

void IntList::insert(int element, int position) {

    IntListElem *newElement = new IntListElem;
    newElement->value = element;

    if (position==0) // fuege am Anfang ein
    {
        newElement->next = first;
        first = newElement;
    }

    else {
        IntListElem* ElementAtPosition = findElementAtNthPosition(position);
        newElement->next = ElementAtPosition->next;
        ElementAtPosition->next = newElement;
    }
    count += 1;
}

void IntList::insert(int element) {
    IntList::insert(element, count);
}

void IntList::remove(int position) {
    if (position >= count){
        std::cout << "Element doesn't exist" << std::endl;
        return;
    }
    if (position == 0){
        if(first == 0) return;  //if first == 0 list is empty and there's nothing to remove
        IntListElem* p = first; //save Pointer, so it can be properly deleted and is not lost
        first = first->next;
        delete p;
    }
    else{
        IntListElem* ElementAtPosition = findElementAtNthPosition(position);
        IntListElem* p = ElementAtPosition->next;   //save Pointer, so it can be properly deleted and is not lost
        ElementAtPosition->next = p->next;
        delete p;
    }
    count--;
}

int IntList::getElement(int position) {
    return findElementAtNthPosition(position)->value;
}

IntList& IntList::operator=(const IntList &l) {
    //remove all Elements of existing list
    for (int i = count-1; i >= 0 ; --i) {  //remove all Elements and thus release memory
        remove(i);
    }

    //copy new Elements into list
    for (int i = 1; i <= l.count; ++i) {    //copy elements from l
        insert(l.findElementAtNthPosition(i)->value);
    }
}

IntListElem* IntList::findElementAtNthPosition(int n) const {
    IntListElem* ElementAtPosition = first;
    for (int i = 1; i < n; ++i) {
        ElementAtPosition = ElementAtPosition->next;
    }
    return ElementAtPosition;
}

int main()
{
    IntList list;
    list.insert(30);
    list.insert(20);
    list.insert(10);
    list.print();

    list.remove(2);
    list.print();

    list.insert(30,2);
    list.print();

    list.insert(40,3);
    list.print();

    IntList copy(list);
    copy.print();

    copy.remove(0);
    copy.print();
    list.print();

    copy = list;
    copy.print();

    return 0;
}
