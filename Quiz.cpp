#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;


// QUESTION CLASS
// Abstract Base Class
class Question {
protected:
    string questionText;
    int correctAnswer;
    string category;

public:

    Question(string q, int answer, string cat) {
        questionText = q;
        correctAnswer = answer;
        category = cat;
    }

    // Pure virtual function - Abstraction
    virtual void display() = 0;

    // Check answer
    bool checkAnswer(int answer) {
        return answer == correctAnswer;
    }

    // Get category
    string getCategory() {
        return category;
    }

    virtual ~Question() {}
};
// MCQ CLASS
class MCQ : public Question {
private:
    vector<string> options;

public:

    MCQ(string q, vector<string> opt, int answer, string cat)
        : Question(q, answer, cat) {

        options = opt;
    }

    // Polymorphism
    void display() override {

        cout << "\n" << questionText << endl;

        for (int i = 0; i < options.size(); i++) {
            cout << i + 1 << ". " << options[i] << endl;
        }
    }
};


            

            

