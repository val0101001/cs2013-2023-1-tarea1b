// No modifique este archivo. Este es el archivo de pruebas que se usara para corregir 
// su tarea. Cualquier cambio realizado sera penalizado con una nota de CERO.

#include "test.hpp"
#include "../tarea/foo.h"


TEST_CASE("parte1", "[Constructor]"){
    SECTION("s1"){
        PyList l1;
        REQUIRE(len(l1) == 0);
    }
    SECTION("s2"){
        PyList l2(1,1.3);
        REQUIRE(len(l2) == 2);
    }
    SECTION("s3"){
        PyList l3(1,"hola",1.3,true,0,10,"mundo",'a');
        REQUIRE(len(l3) == 8);
    }
}


TEST_CASE("parte2","[metodos]"){
    SECTION("s1"){
        PyList l1;
        l1.append(1.3);
        REQUIRE(len(l1) == 1);
    }
    SECTION("s2"){
        PyList l2("hola");
        l2.append(1.3);
        l2.append(2.3);
        REQUIRE(len(l2) == 3);
    }
    SECTION("s3"){
        PyList l3(1,"hola");
        l3.append(PyList(2,"mundo"));
        REQUIRE(len(l3) == 3);
    }
}


TEST_CASE("parte3","[indice]"){
    SECTION("s1"){
        PyList l("hola",1,1.3,true,0,10,"mundo",'a');
        REQUIRE(is_equal(l[2], 1.3));
        REQUIRE(l[1] == 1);
        REQUIRE(l[7] == 'a');
    }
    SECTION("s2"){
        PyList l(1,"hola",1.3,true,0,10,"mundo",'a');
        l[2] = 'x';
        l[1] = 5;
        l[7] = false;
        REQUIRE(l[2] == 'x');
        REQUIRE(l[1] == 5);
        REQUIRE(l[7] == false);
    }
    SECTION("s3"){
        PyList l1(1,"hola",1.3,true,0,10,"mundo",'a');
        PyList l2 = l1;
        PyList l3 = l2.from_to(3,5);

        REQUIRE(l3[1] == l1[4]);
    }
}

TEST_CASE("parte4", "[print]"){
    SECTION("s1"){
        PyList l;
        stringstream ss;
        ss << l;
        REQUIRE(strcmp(ss.str().c_str(),"[]") == 0);
    }
    SECTION("s2"){
        PyList l(1,"hola",1.3,true,0,10,"mundo",'a');
        stringstream ss;
        ss << l;
        REQUIRE(strcmp(ss.str().c_str(),"[1,hola,1.3,true,0,10,mundo,a]") == 0);
    }
    SECTION("s3"){
        PyList l(1,"hola");
        l.append(2);
        stringstream ss;
        ss << l;
        REQUIRE(strcmp(ss.str().c_str(),"[1,hola,2]") == 0);
    }
}