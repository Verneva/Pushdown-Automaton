#include <iostream>
#include <string>
#include <stack>
using namespace std;

//Create PDA class
class PDA{

private:
    enum State {Start, alpha, blank, openParen, closedParen, openBrack, closedBrack, retT, retF};
    //Rename stack variable to avoid naming conflict with stack
    stack<string> stk;

public: 
    State currentState = Start;

    bool ProcessChar(char c) {
        //Only add $ if the stack is new and empty
        if (stk.empty()) {
            stk.push("$");
        }

        switch (currentState){
            case Start:
                if (c >= 'a' && c <= 'z'){
                    currentState = alpha;
                } else if (c == ' '){
                    currentState = blank;
                } else if (c == '('){
                    stk.push("(");
                    currentState = openParen;
                }  else if (c == ')' && stk.top() == "(") {
                    stk.pop();
                    currentState = closedParen;
                } else if (c == '['){
                    stk.push("[");
                    currentState = openBrack;
                } else if (c == ']' && stk.top() == "["){
                    stk.pop();
                    currentState = closedBrack;
                } else if (c == '.' && stk.top() == "$"){
                    stk.pop();
                    currentState = retT;
                } else{
                    currentState = retF;
                }
                break;

            case alpha:
                if (c >= 'a' && c <= 'z'){
                    currentState = alpha;
                } else if (c == ' '){
                    currentState = blank;
                } else if (c == '('){
                    stk.push("(");
                    currentState = openParen;
                } else if (c == ')' && stk.top() == "(") {
                    stk.pop();
                    currentState = closedParen;
                } else if (c == '['){
                    stk.push("[");
                    currentState = openBrack;
                } else if (c == ']' && stk.top() == "[") {
                    stk.pop();
                    currentState = closedBrack;
                } else if (c == '.' && stk.top() == "$"){
                    currentState = retT;
                } else{
                    currentState = retF;
                }
                break;

            case blank:
                if (c >= 'a' && c <= 'z'){
                    currentState = alpha;
                } else if (c == ' '){
                    currentState = blank;
                } else if (c == '('){
                    stk.push("(");
                    currentState = openParen;
                } else if (c == ')' && stk.top() == "(") {
                    stk.pop();
                    currentState = closedParen;
                } else if (c == '['){
                    stk.push("[");
                    currentState = openBrack;
                } else if (c == ']' && stk.top() == "["){
                    stk.pop();
                    currentState = closedBrack;
                } else if (c == '.'){
                    currentState = retT;
                } else{
                    currentState = retF;
                }
                break;

            case openParen:
                if (c >= 'a' && c <= 'z'){
                    currentState = alpha;
                } else if (c == ' '){
                    currentState = blank;
                } else if (c == '('){
                    stk.push("(");
                    currentState = openParen;
                } else if (c == ')' && stk.top() == "("){
                    stk.pop();
                    currentState = closedParen;
                } else if (c == '['){
                    stk.push("[");
                    currentState = openBrack;
                } else if (c == ']' && stk.top() == "["){
                    stk.pop();
                    currentState = closedBrack;
                } else if (c == '.'){
                    currentState = retF;
                } else{
                    currentState = retF;
                }
                break;

            case closedParen:
                if (c >= 'a' && c <= 'z'){
                    currentState = alpha;
                } else if (c == ' '){
                    currentState = blank;
                } else if (c == '('){
                    stk.push("(");
                    currentState = openParen;
                } else if (c == ')' && stk.top() == "(") {
                    stk.pop();
                    currentState = closedParen;
                } else if (c == '['){
                    stk.push("[");
                    currentState = openBrack;
                } else if (c == ']' && stk.top() == "["){
                    stk.pop();
                    currentState = closedBrack;
                } else if (c == '.' && stk.top() == "$"){
                    stk.pop();
                    currentState = retT;
                } else{
                    currentState = retF;
                }
                break;

            case openBrack:
                if (c >= 'a' && c <= 'z'){
                    currentState = alpha;
                } else if (c == ' '){
                    currentState = blank;
                } else if (c == '('){
                    stk.push("(");
                    currentState = openParen;
                } else if (c == ')' && stk.top() == "(") {
                    stk.pop();
                    currentState = closedParen;
                } else if (c == '['){
                    stk.push("[");
                    currentState = openBrack;
                } else if (c == ']' && stk.top() == "["){
                    stk.pop();
                    currentState = closedBrack;
                } else if (c == '.'){
                    currentState = retF;
                } else{
                    currentState = retF;
                }
                break;

            case closedBrack:
                if (c >= 'a' && c <= 'z'){
                    currentState = alpha;
                } else if (c == ' '){
                    currentState = blank;
                } else if (c == '('){
                    stk.push("(");
                    currentState = openParen;
                } else if (c == ')' && stk.top() == "(") {
                    stk.pop();
                    currentState = closedParen;
                } else if (c == '['){
                    stk.push("[");
                    currentState = openBrack;
                } else if (c == ']' && stk.top() == "["){
                    stk.pop();
                    currentState = closedBrack;
                } else if (c == '.'){
                    currentState = retT;
                } else{
                    currentState = retF;
                }
                break;       
        }
        return (currentState == retT) || (currentState == retF);
    }

    bool IsAccepted() const {
        return currentState == retT;
    }
};

int main(){
    //Create PDA object
    PDA pda;
    
    string input;

    cout <<"Enter a string (Σ = { a-z, ␢, (, ), [, ] }) followed by '.' ";
    getline(cin, input);

    //Loop through each character and call ProcessChar()
    for (char c : input)
        if (pda.ProcessChar(c)){
            if (pda.IsAccepted())
                cout << "String accepted!" << endl;
            else
                cout << "String not accepted!" << endl;
            break;
        }
    return 0;
}
