#include <iostream>
#include <string>
#include <vector>
#include <cmath>


using namespace std;


class calculator {
    private: string input;
    private: vector<float> numbers; // every number in input
    private: vector<int> rating;  // every operation in input
    private: vector<int> symbols; // order of execution of respective operation in input
    // after getReady function input gets transformed into numbers and symbols vectors, where symbols[i] 
    // was between numbers[i] and numbers[i+1]. Also every symbol gets its order of execution
    
    // constructor
    public: calculator(string input) {
        this->input = input;
        getReady();
    }

    // input new expression
    public: void refresh(string input) {
        this->input = input;
        getReady();
    }

    // mostly for debugging. Firstly sends all numbers, then sends operations and their order of execution
    public: void sendToConsole() {
        for (int i = 0; i < numbers.size(); i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < symbols.size(); i++) {
            cout << symbols[i] << " " << rating[i] << endl;
        }
    }

    // main function, gives just int. Complexity O(n^2)
    public: float calculate() {
        if (numbers.size() == 0)
            return 0;
        while (symbols.size() > 0) {
            int maxRatingSymbol = 0;
            for (int i = 1; i < symbols.size(); i++) {
                if (rating[i] > rating[maxRatingSymbol])
                    maxRatingSymbol = i;
            }
            switch (symbols[maxRatingSymbol]){ // add here respective operations
            case 1:
                numbers[maxRatingSymbol] = numbers[maxRatingSymbol] + numbers[maxRatingSymbol + 1];
                break;
            case 2:
                numbers[maxRatingSymbol] = numbers[maxRatingSymbol] - numbers[maxRatingSymbol + 1];
                break;
            case 3:
                numbers[maxRatingSymbol] = numbers[maxRatingSymbol] * numbers[maxRatingSymbol + 1];
                break;
            case 4:
                numbers[maxRatingSymbol] = numbers[maxRatingSymbol] / numbers[maxRatingSymbol + 1];
                break;
            case 5:
                numbers[maxRatingSymbol] = pow(numbers[maxRatingSymbol], numbers[maxRatingSymbol + 1]);
                break;
            }
            numbers.erase(numbers.begin() + maxRatingSymbol + 1);
            symbols.erase(symbols.begin() + maxRatingSymbol);
            rating.erase(rating.begin() + maxRatingSymbol);
        }
        float buf = numbers[0];
        numbers.clear();
        symbols.clear();
        rating.clear();
        return buf;
    }

    // gives string solution step-by-step. Not so important, but let it be
    public: string calculateWithExplanations() {
        string explanations = "\n Explanations:";
        if (numbers.size() == 0)
            return 0;
        while (symbols.size() > 0) {
            explanations += "\n";
            int maxRatingSymbol = 0;
            for (int i = 1; i < symbols.size(); i++) {
                if (rating[i] > rating[maxRatingSymbol])
                    maxRatingSymbol = i;
            }
            switch (symbols[maxRatingSymbol]) {
            case 1:
                explanations = explanations + to_string(numbers[maxRatingSymbol]) + " + "
                    + to_string(numbers[maxRatingSymbol + 1]) + " = " + to_string(numbers[maxRatingSymbol] +
                        numbers[maxRatingSymbol + 1]);
                numbers[maxRatingSymbol] = numbers[maxRatingSymbol] + numbers[maxRatingSymbol + 1];
                break;
            case 2:
                explanations = explanations + to_string(numbers[maxRatingSymbol]) + " - "
                    + to_string(numbers[maxRatingSymbol + 1]) + " = " + to_string(numbers[maxRatingSymbol] -
                        numbers[maxRatingSymbol + 1]);
                numbers[maxRatingSymbol] = numbers[maxRatingSymbol] - numbers[maxRatingSymbol + 1];
                break;
            case 3:
                explanations = explanations + to_string(numbers[maxRatingSymbol]) + " * "
                    + to_string(numbers[maxRatingSymbol + 1]) + " = " + to_string(numbers[maxRatingSymbol] *
                        numbers[maxRatingSymbol + 1]);
                numbers[maxRatingSymbol] = numbers[maxRatingSymbol] * numbers[maxRatingSymbol + 1];
                break;
            case 4:
                explanations = explanations + to_string(numbers[maxRatingSymbol]) + " / "
                    + to_string(numbers[maxRatingSymbol + 1]) + " = " + to_string(numbers[maxRatingSymbol] /
                        numbers[maxRatingSymbol + 1]);
                numbers[maxRatingSymbol] = numbers[maxRatingSymbol] / numbers[maxRatingSymbol + 1];
                break;
            case 5:
                explanations = explanations + to_string(numbers[maxRatingSymbol]) + " ^ "
                    + to_string(numbers[maxRatingSymbol + 1]) + " = " + to_string(pow(numbers[maxRatingSymbol], 
                        numbers[maxRatingSymbol + 1]));
                numbers[maxRatingSymbol] = pow(numbers[maxRatingSymbol], numbers[maxRatingSymbol + 1]);
                break;
            }
            numbers.erase(numbers.begin() + maxRatingSymbol + 1);
            symbols.erase(symbols.begin() + maxRatingSymbol);
            rating.erase(rating.begin() + maxRatingSymbol);
        }
        string buf = to_string(numbers[0]);
        numbers.clear();
        symbols.clear();
        rating.clear();
        return buf + explanations;
    }

    //list of valid operations. You can add new, but dont forget to add them to calculate functions as well.
    private: int isSymbol(char chr)
    {
        if (chr == '1')
            return 0;
        else if (chr == '2')
            return 0;
        else if (chr == '3')
            return 0;
        else if (chr == '4')
            return 0;
        else if (chr == '5')
            return 0;
        else if (chr == '6')
            return 0;
        else if (chr == '7')
            return 0;
        else if (chr == '8')
            return 0;
        else if (chr == '9')
            return 0;
        else if (chr == '0')
            return 0;
        else if (chr == '+')
            return 1;
        else if (chr == '-')
            return 2;
        else if (chr == '*')
            return 3;
        else if (chr == '\\')
            return 4;
        else if (chr == '/')
            return 4;
        else if (chr == '^')
            return 5;
        else if (chr == '(')
            return -1;
        else if (chr == ')')
            return -2;
        else if (chr == '.')
            return -3;
        else if (chr == ',')
            return -3;
        else
            return -4;
    }

    //used for ordering of operations. Should be bigger then the amount of available operations
    const int amountOfSymbols = 15;

    //technical staff
    // puts new number into numbers vector
    private: void push(bool* isNegative, string buf. bool* isFloat) {
        if (*isNegative)
            numbers.push_back(-stof(buf));
        else
            numbers.push_back(stof(buf));
        *isNegative = false;
        *isFloat = false;
        
    }
    // used for adding multiplication near breackets when needed
    private: void check(int curRating) {
        if (numbers.size() > symbols.size() + 1) {
            rating.push_back(curRating * amountOfSymbols + 3);
            symbols.push_back(3);
        }
    }
    // used to separate input into numbers, symbols and symbol rating vectors
    private: void getReady() {
               string buf = "";
               int curRating = 0;
               bool isNegative = false;
               bool isFloat = 0;
               for (int i = 0; i < input.length(); i++) {
                   int result = isSymbol(input[i]);
                   if (result == 0) {
                       if (buf == "brkt") {
                           buf = "";
                       }
                       buf += input[i];
                   }
                   else if (result == -3) {
                       if (buf == "brkt") {
                           buf = "";
                       }
                       if (!ifFloat) {
                           if (buf == "") {
                               buf += "0";
                           }
                           buf += ".";
                           isFloat = true;
                       }
                   }
                   else if (result == -1) {
                       if (buf != "") {
                           if (buf != "brkt")
                                push(&isNegative, buf, &isFloat);
                           check(curRating);
                           rating.push_back(curRating * amountOfSymbols + 3);
                           symbols.push_back(3);
                           buf = "";
                       }
                       curRating += 1;
                   }
                   else if (result == -2) {
                       if (buf != "" && buf != "brkt")
                           push(&isNegative, buf, &isFloat);
                       check(curRating);
                       curRating -= 1;
                       buf = "brkt";
                   }
                   else if (result != -4) {
                       if (buf != "") {
                           if (buf != "brkt")
                               push(&isNegative, buf, &isFloat);
                           check(curRating);
                           rating.push_back(curRating * amountOfSymbols + result);
                           symbols.push_back(result);
                       }
                       else if (result == 2) {
                           isNegative ^= true;
                       }
                       buf = "";
                   }
               }
               if (buf != "" && buf != "brkt") {
                       push(&isNegative, buf, &isFloat);
                       check(curRating);
               }
               if (numbers.size() <= symbols.size()) {
                   symbols.erase(symbols.end() - numbers.size() + symbols.size()-1, symbols.end());
                   rating.erase(rating.end() - numbers.size() + rating.size()-1, rating.end());
               }
    }
};






int main()
{
    string input = "";
    string mode = "";
   while (mode != "1" && mode != "2") {
        cout << "Write 1 if you chose no explanations mode.\nWrite 2 if you chose mode with explanations!\n";
        //getline(cin, mode);
        mode = 1;
    }

    if (mode == "1")
        cout << "You are in no explanation mode!\n";
    else
        cout << "You are in mode with explanations!\n";

    for (;;) {
        cout << "Write your expression!\nWrite stop to stop the program!\n";
        
        //getline(cin, input);
        input = "10(12-10)-(2*5+4)";
        if (input == "stop")
            return 0;
        cout << endl;
        calculator calc = calculator(input);
        //ready.sendToConsole(); //turn it on for debugging
        if (mode == "1")
            cout << "Answer is " << calc.calculate() << endl;
        else
            cout << "Answer is " << calc.calculateWithExplanations() << endl;
    }
}
