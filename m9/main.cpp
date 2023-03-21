#include<iostream>
#include<cstring>


template <typename T>
T maxn(T* arr, int len){
    T max = arr[0];
    for(int i=1; i<len; ++i){
        if(max < arr[i]) max = arr[i];
    }
    return max;
}

template<>
const char* maxn(const char** arr, int len){
    int max_len = -1, j = 0;
    for(int i=0; i<len; ++i){
        if(max_len < (int)strlen(arr[i])){
            max_len = strlen(arr[i]);
            j = i;
        }
    }
    return arr[j];
}

/*int main(){

    using namespace std;
    int arri[6] = {1, 2, 5, 3, 1, -1};
    double arrd[4] = {2.3, -1.3, 8.7, 4.5};
    const char * arrc[5] = {"first", "second", "third", "long string", "another string"};

    cout << "max of integer = " << maxn(arri, 6) << endl;
    cout << "max of double = " << maxn(arrd, 4) << endl;
    cout << "max string is " << maxn(arrc, 5) << endl;


    return 0;
}*/