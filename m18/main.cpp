#include <iostream>
#include <vector>
#include <stack>

bool is_c_T(char c){
    return ((c >='0' && c <= '9') || (c >='a' && c <= 'z'));
}


class Parser{
    char c;
    void S();
    void A();
    void gc(){std::cin.get(c);}
    std::vector<char> vec;
    std::stack<char> stack;
    bool meet_op;
public:
    void analize();
};

void Parser::analize(){
    try{
        meet_op = false;
        gc();
        S();
        for(auto it=vec.begin(); it!=vec.end(); ++it) std::cout << *it;
        std::cout << std::endl;
    }
    catch(char ex){
        std::cerr << "Error in: " << ex << std::endl; 
    }

}

void Parser::A(){
    if(c == '+'){
        if(!stack.empty()){
            c = stack.top();
            if(c != '(' ){
                stack.pop();
                vec.push_back(c);
                while(!stack.empty()){
                    c = stack.top();
                    if(c == '(') break;
                    stack.pop();
                    vec.push_back(c);
                }
            }
        }
        stack.push('+');
        gc();
        S();
    }
    else if(c == '*'){
        if(!stack.empty()){
            c = stack.top();
            if(c == '+'){
                stack.push('*');
            }
            else if(c == '*'){
                vec.push_back('*');
            }
            else stack.push('*');
        }
        else{
            stack.push(c);
        }
        gc();
        S();
    }
    else if(c == ')'){
        meet_op = false;
        c = stack.top();
        stack.pop();
        while(c != '(' && !stack.empty()){
            vec.push_back(c);
            c = stack.top();
            stack.pop();
        }
        if(stack.empty() && c != '(') throw ')';
        gc();
        A();
    }
    else if(c == '\n'){
        if(meet_op) throw c;
        while(!stack.empty()){
            c = stack.top();
            stack.pop();
            vec.push_back(c);
        }
    }
    else throw c;
}

void Parser::S(){
    if(is_c_T(c)){
        vec.push_back(c);
        gc();
        A();
    }
    else if(c == '('){
        meet_op = true;
        stack.push(c);
        gc();
        S();
    }
    else throw c;
}


int main(){
    Parser A;
    A.analize();
    return 0;
}