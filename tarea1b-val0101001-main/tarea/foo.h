#include <iostream>

using namespace std;

class Lista{
friend ostream& operator<<(ostream& os, const Lista& l);
friend int len(const Lista& l);
private:
    int length;
    // TODO
public:
    template<typename... Args>
    Lista(Args... args){
        // TODO
    }

    template<typename T>
    void append(T t){
        // TODO
    }

    Lista from_to(int i, int j) const{
        // TODO
    }

    template<typename T>
    T& operator[](T t){
        // TODO
    }

    template<typename T>
    const T& operator[](T t) const{
        // TODO
    }
};