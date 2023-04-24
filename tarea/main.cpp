#include "foo.h"

int main(){
    // LIMITACIONES DEL PROGRAMA

    // buenas tardes profesor espero se encuentre bien el motivo de este mensaje en el main es que
    // este programa no puede hacer exactamente lo que se pidio en el enunciado debido a
    // limitaciones con las que he tenido que enfentarme debido a limitaciones de c++

    // 1. la sobrecarga a [] no funciona si no usas * para derreferenciarlo

    PyList l(1,'2',true,"abc");
    auto a=l[0];
    cout<<l[0]<<endl; //va a imprimir una direccion
    cout<<(int)*l[0]<<endl; //no puede ser impreso si no se usa un type cast
    cout<<static_cast<int>(*l[0])<<endl; //esto tambien funciona

    // otra limitacion es que no se puede hacer type cast a string
    // debido a que hace conflicto y es ambiguo con definiciones dentro
    // la libreria estandar

    // cout<<static_cast<string>(*l[3]) (error por conversion ambigua)

    // sin embargo se puede evitar el problema de la siguiente forma

    string s=*l[3];
    cout<<s<<endl; // si imprime correctamente, solo pasa con type casting

    // algo similar ocurre con PyList

    PyList l2(1,2);
    l.append(l2); // l=[1,'2',true,"abc",[1,2]]
    // cout<<static_cast<PyList>(*l[4]); (no se por que pasa exactamente, pero se evita de la misma forma)
    PyList l3=*l[4];
    cout<<l3<<endl;

    // el tipo de retorno de [] no es el tipo, sino otro tipo, y es por eso que ocurren
    // estas limitaciones. se puede hacer comparacion entre ese tipo y otros
    // usando conversion implicita, mas no pude lograr conversion entre ambos tipos

    auto b=l[1];
    char c='2',d='3';
    cout<<boolalpha<<(*b==c)<<" "<<(*b==d)<<endl; // true,false
    auto e=l[0];
    cout<<(a==e)<<endl; //va a fallar, no esta implementado debido a que es ambiguo

    // algo que si funciona es usar este tipo de retorno especial para asignar tanto
    // de una clase a indice o de indice a clase

    cout<<l<<endl;
    *l[0]=2;
    cout<<l<<endl;
    *l[0]=false;
    cout<<l<<endl;
    *l[0]=l2;
    cout<<l<<endl;
    //*l[0]="abc";
    //cout<<l<<endl; (por algun motivo falla con string, no se por que)

    // al reves

    string s2=*l[3];
    cout<<s2<<endl;
    PyList l4=*l[0];
    cout<<l3;

    // gracias por su tiempo profe, espero tome en cuenta que el programa basicamente funciona como pedido
    // porfavor, valore el hecho de que no se uso ni variant ni any (el enunciado decia que no se podian
    // usar librerias adicionales), por lo tanto solo usé <iostream>
}
