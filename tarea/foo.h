#include <iostream>
using namespace std;

class PyList;

template<typename T>
class returning2;

class returning {
public:
    string type="";
    returning();
    template <typename T>
    operator T() const;
    virtual void operator=(int n);
    virtual void operator=(float n);
    virtual void operator=(double n);
    virtual void operator=(bool n);
    virtual void operator=(char n);
    virtual void operator=(string n);
    void operator=(PyList &p);
};

class PyList{
private:
    pair<string,void*> *arr=nullptr;
    int size;
    pair<string,int*> make_pair(int &n);
    pair<string,float*> make_pair(float &n);
    pair<string,double*> make_pair(double &n);
    pair<string,bool*> make_pair(bool &n);
    pair<string,string*> make_pair(string &n);
    pair<string,char*> make_pair(char &n);
    pair<string,PyList*> make_pair(PyList &n);
    template<typename ...Args>
    void append_many(Args ...args){
        (append(args),...);
    }
public:
    PyList();
    template<typename ...Args>
    explicit PyList(Args... args){
        size=0;
        append_many(args...);
    }
    PyList(const PyList &other);
    void append(const char *a);
    void append(const PyList l);
    template<typename T>
    void append(T &a);
    template<typename T>
    void append(const T &&a);
    returning *operator[](int n);
    friend ostream &operator<<(ostream&,PyList);
    friend int len(PyList);
    template<typename T>
    void modify(int index,T &val);
    PyList from_to(int i,int j);
};

ostream &operator<<(ostream &out,PyList l);
int len(PyList l);

template <typename T>
class returning2 : public returning {
public:
    string type="";
    PyList mod;
    void *n;
    int index;
    returning2(T &num,const PyList &list,int index,string s);
    operator T();
    template<typename K>
    void operator=(K num);
    template<typename K>
    returning2(const returning2<K> &other);
};

template <typename T>
returning::operator T() const{
    return *(T*)(static_cast<returning2<T>*>(const_cast<returning*>(this))->n);
}

template<typename T>
void PyList::append(T &a){
    T *t=new T(a);
    size++;
    pair<string,void*> *temp=new pair<string,void*>[size];
    for(int i=0;i<size-1;i++){
        temp[i]=arr[i];
    }
    temp[size-1]=make_pair(*t);
    delete[] arr;
    arr=temp;
    temp=nullptr;
}

template<typename T>
void PyList::append(const T &&a){
    T *t=new T(a);
    size++;
    pair<string,void*> *temp=new pair<string,void*>[size];
    for(int i=0;i<size-1;i++){
        temp[i]=arr[i];
    }
    temp[size-1]=make_pair(*t);
    delete[] arr;
    arr=temp;
    temp=nullptr;
}

template<typename T>
T no_ptr(T *n){
    return *n;
}

template <typename T>
void PyList::modify(int index,T &val){
    arr[index]=make_pair(val);
}

template<typename T>
bool operator==(returning &n1,T n2){
    return ((T)n1==(T)n2);
}

template<typename T>
bool operator==(T n1,returning &n2){
    return ((T)n1==(T)n2);
}

template<typename T,typename K>
bool operator!=(T n1,K n2){
    return !((T)n1==(K)n2);
}
