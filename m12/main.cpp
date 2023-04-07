#include <iostream>
#include <list>

template <typename T>
void af(std::list<T>& lst, T x){
    lst.push_front(x);
}

template <typename T>
void ae(std::list<T>& lst, T x){
    lst.push_back(x);
}

template <typename T>
void ib(std::list<T>& lst, T first_par, T sec_par){
    for(auto it=lst.begin(); it!=lst.end(); ++it){
        if(*it == sec_par) {
            lst.insert(it, first_par);
            return;
        }
    }
}

template <typename T>
void ia(std::list<T>& lst, T first_par, T sec_par){
    for(auto it=lst.begin(); it!=lst.end(); ++it){
        if(*it == sec_par) {
            ++it;
            lst.insert(it, first_par);
            return;
        }
    }
}

template <typename T>
void d(std::list<T>& lst, T x){
    for(auto it=lst.begin(); it!=lst.end(); ++it){
        if(*it == x){
            lst.erase(it);
            return;
        }
    }
}

template <typename T>
void sa(std::list<T>& lst){
    lst.sort();
}

template <typename T>
void sd(std::list<T>& lst){
    lst.sort();
    lst.reverse();
}

template <typename T>
T find_max(const std::list<T>& lst){
    auto it=lst.begin();
    T max = *it;
    for(it=lst.begin(); it!=lst.end(); ++it){
        if(max < *it){
            max = *it;
        }
    }
    return max;
}

template <typename T>
void mf(std::list<T>& lst){
    T max = find_max(lst);
    d(lst, max);
    lst.push_front(max);
}

template <typename T>
void me(std::list<T>& lst){
    T max = find_max(lst);
    d(lst, max);
    lst.push_back(max);
}

template <typename T>
void print(const std::list<T> lst){
    auto it=lst.begin();
    if(it != lst.end()){
        for(it=lst.begin(); it!=lst.end(); ++it){
            if(it == lst.begin()) std::cout << *it;
            else std::cout << ' ' << *it;
        }
        std::cout << std::endl;
    }
}

void parser(int const& argc, char** const argv){
    std::list<int> lst;
    int tmp, first_par, sec_par;
    while(1){
        std::cin >> tmp;
        if(std::cin.eof()) break;
        lst.push_back(tmp);
    }
    
    if((argc <= 1) || (argc > 4)){
        print(lst);
        return;//error
    }
    if(argv[1][0] != '-'){
        print(lst);
        return;//error
    }

    if(argc > 2) first_par = atoi(argv[2]);
    if(argc > 3) sec_par = atoi(argv[3]);
    
    if(argv[1][1] == 'a'){
        if (!(argc == 3)){
            print(lst);
            return;//error
        }
        if(argv[1][2] == 'f'){
            if(argv[1][3] != '\0'){
                print(lst);
                return;//error
            }
            af(lst, first_par);
        }
        else if(argv[1][2] == 'e'){
            if(argv[1][3] != '\0'){
                print(lst);
                return;//error
            }
            ae(lst, first_par);
        }
    }

    if(argv[1][1] == 'i'){
        if (!(argc == 4)){
            print(lst);
            return;//error
        }
        if(argv[1][2] == 'b'){
            if(argv[1][3] != '\0'){
                print(lst);
                return;//error
            }
            ib(lst, first_par, sec_par);
        }
        else if(argv[1][2] == 'a'){
            if(argv[1][3] != '\0'){
                print(lst);
                return;//error
            }
            ia(lst, first_par, sec_par);
        }
    }

    if(argv[1][1] == 'd'){
        if (!(argc == 3)) {
            print(lst);
            return;//error
        }
        if (argv[1][2] != '\0'){
            print(lst);
            return;//error
        }
        d(lst, first_par);
    }

    if(argv[1][1] == 's'){
        if (!(argc == 2)){
            print(lst);
            return;//error
        }
        if(argv[1][2] == 'a'){
            if(argv[1][3] != '\0'){
                print(lst);
                return;//error
            }
            sa(lst);
        }
        else if(argv[1][2] == 'd'){
            if(argv[1][3] != '\0'){
                print(lst);
                return;//error
            }
            sd(lst);
        }
    }

    if(argv[1][1] == 'm'){
        if (!(argc == 2)){
            print(lst);
            return;//error
        }
        if(argv[1][2] == 'f'){
            if(argv[1][3] != '\0'){
                print(lst);
                return;//error
            }
            mf(lst);
        }
        else if(argv[1][2] == 'e'){
            if(argv[1][3] != '\0'){
                print(lst);
                return;//error
            }
            me(lst);
        }
    }

    print(lst);
}



int main(int argc, char**argv){

    parser(argc, argv);

    return 0;
}