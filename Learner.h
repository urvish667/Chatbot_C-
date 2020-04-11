#include <iostream>
#include <fstream>
#include "Voice.h"

using namespace std;

class Learner {
public:
    void respond(string phrase);
    void say(string phrase);

    Voice voice;
};

void Learner::respond(string phrase){
    fstream memory;
    memory.open("E:/chatbot c++/memory/memory.txt", ios::in);

    while( !memory.eof() ){
        string identifier;
        getline(memory,identifier);

        if(identifier == phrase){
            string response;
            getline(memory,response);
            voice.say(response);
            return;
        }
    }

    memory.close();
    memory.open("E:/chatbot c++/memory/memory.txt", ios::out | ios::app);
    memory << phrase << endl;

    voice.say(phrase);
    string userResponse;
    cout << "YOU: ";
    getline(cin, userResponse);
    memory << userResponse << endl;
    memory.close();
}


void Learner::say(string phrase){
    this->voice.say(phrase);
}
