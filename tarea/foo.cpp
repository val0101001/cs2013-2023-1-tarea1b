#include "foo.h"
#include <iostream>
using namespace std;

returning::returning(){}

void returning::operator=(int n){*(returning2<int>*)this=n;}
void returning::operator=(float n){*(returning2<float>*)this=n;}
void returning::operator=(double n){*(returning2<double>*)this=n;}
void returning::operator=(bool n){*(returning2<bool>*)this=n;}
void returning::operator=(char n){*(returning2<char>*)this=n;}
void returning::operator=(string n){*(returning2<string>*)this=n;}

template <typename T>
returning2<T>::returning2(T &num,const pylist &list, int index, string s){
    n=&num;
    mod=list;
    type=s;
    this->index=index;
}

template<typename T>
template<typename K>
returning2<T>::returning2(const returning2<K> &other){
    this->type=other.type;
    this->pylist=other.pylist;
    this->n=other.n;
    this->index=other.index;
}

template <typename T>
returning2<T>::operator T(){
    return *(T*)n;
}

template <typename T>
template<typename K>
void returning2<T>::operator=(K num){
    n=new T(num);
    mod.modify(index,*(T*)n);
}

void returning::operator=(pylist &p){
    *(returning2<pylist>*)this=p;
}

pylist::pylist(){
    size = 0;
    arr = new pair<string, void*>[size];
}

pylist::pylist(const pylist &other) {
    this->size = other.size;
    this->arr = new pair<string, void*>[size];
    for (int i = 0; i < size; i++) {
        this->arr[i] = other.arr[i];
    }
}

pair<string, int*> pylist::make_pair(int &n){
    return pair<string, int*>("int", &n);
}

pair<string, float*> pylist::make_pair(float &n) {
    return pair<string, float*>("float", &n);
}

pair<string, double*> pylist::make_pair(double &n){
    return pair<string,double*>("double",&n);
}

pair<string, bool*> pylist::make_pair(bool &n){
    return pair<string,bool*>("bool",&n);
}

pair<string, string*> pylist::make_pair(string &n){
    return pair<string,string*>("string",&n);
}

pair<string, char*> pylist::make_pair(char &n){
    return pair<string,char*>("char",&n);
}

pair<string, pylist*> pylist::make_pair(pylist &n){
    return pair<string,pylist*>("pylist",&n);
}

void pylist::append(const char *a){
    string s1=a;
    string *s2=new string(s1);
    size++;
    pair<string,void*> *temp=new pair<string,void*>[size];
    for(int i=0;i<size-1;i++){
        temp[i]=arr[i];
    }
    temp[size-1]=make_pair(*s2);
    delete[] arr;
    arr=temp;
    temp=nullptr;
}

void pylist::append(const pylist l){
    pylist *l2=new pylist(l);
    size++;
    pair<string,void*> *temp=new pair<string,void*>[size];
    for(int i=0;i<size-1;i++){
        temp[i]=arr[i];
    }
    temp[size-1]=make_pair(*l2);
    delete[] arr;
    arr=temp;
    temp=nullptr;
}

pylist pylist::from_to(int i, int j){
    pylist l;
    delete[] l.arr;
    l.size=j-i+1;
    l.arr=new pair<string,void*>[l.size];
    for(int x=0;x<l.size;x++){
        l.arr[x]=this->arr[x+i];
    }
    return l;
}

returning *pylist::operator[](int n){
    if(arr[n].first=="int"){
        return new returning2<int>(*(int*)(arr[n].second),*this,n,"int");
    }
    else if(arr[n].first=="float"){
        return new returning2<float>(*(float*)(arr[n].second),*this,n,"float");
    }
    else if(arr[n].first=="double"){
        return new returning2<double>(*(double*)(arr[n].second),*this,n,"double");
    }
    else if(arr[n].first=="bool"){
        return new returning2<bool>(*(bool*)(arr[n].second),*this,n,"bool");
    }
    else if(arr[n].first=="string"){
        return new returning2<string>(*(string*)(arr[n].second),*this,n,"string");
    }
    else if(arr[n].first=="char"){
        return new returning2<char>(*(char*)(arr[n].second),*this,n,"char");
    }
    else{
        return new returning2<pylist>(*(pylist*)(arr[n].second),*this,n,"pylist");
    }
}

ostream &operator<<(ostream &out,pylist l){
    out<<"[";
    for(int i=0;i<l.size;i++){
        if(l.arr[i].first=="int"){
            out<<*(int*)(l.arr[i].second);
        }
        else if(l.arr[i].first=="float"){
            out<<*(float*)(l.arr[i].second);
        }
        else if(l.arr[i].first=="double"){
            out<<*(double*)(l.arr[i].second);
        }
        else if(l.arr[i].first=="bool"){
            out<<boolalpha<<*(bool*)(l.arr[i].second);
        }
        else if(l.arr[i].first=="string"){
            out<<'"'<<*(string*)(l.arr[i].second)<<'"';
        }
        else if(l.arr[i].first=="char"){
            out<<"'"<<*(char*)(l.arr[i].second)<<"'";
        }
        else{
            out<<*(pylist*)(l.arr[i].second);
        }
        if(i!=l.size-1) out<<",";
    }
    out<<"]";
    return out;
}

int len(pylist l){
    return l.size;
}
