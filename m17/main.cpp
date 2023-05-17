#include <iostream>
#include <stack>

int opearation(int a, int b, char c){
    switch(c){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            throw c;
    }
}

int cal_Poliz(){
    std::stack<int> st;
    int num, op1, op2;
    char c;
    std::cin.get(c);
    while(c != '\n'){
        if(c >= '0' && c <= '9'){
            num = 0;
            while(c >= '0' && c <= '9'){
                num = 10 * num + (int)(c - '0');
                std::cin.get(c);
            }
            st.push(num);
        }
        else if(c == '@'){
            op1 = st.top();
            st.pop();
            st.push(-op1);
            std::cin.get(c);
        }
        else if(c == ' ') {
            std::cin.get(c);
            continue;
        }
        else{
            op1 = st.top();
            st.pop();
            op2 = st.top();
            st.pop();
            st.push(opearation(op2, op1, c));
            std::cin.get(c);
        }
    }
    return st.top();
}

int main(){
    try{
        std::cout << cal_Poliz();
    }
    catch(char c){
        std::cout << "Wrong sombol: " << c << std::endl;
    }
    return 0;
}