#include<iostream>
#include "Learner.h"

using namespace std;

main(){
    Learner AI;

    for(;;){
        cout << "\nYOU: ";
        string phrase;
        getline(cin, phrase);

        cout << "JARVIS: ";
        AI.respond(phrase);
    }
}
