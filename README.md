[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/zsrNG9IU)
# :wave: PROGRAMACION III: TAREA 1B

- Apellidos: *Completar*
- Nombres: *Completar*
- Sección: *Completar*

En la presente tarea usted debe **modificar/completar** los archivos dentro de la carpeta <tt>tarea</tt>.

## Requerimientos

### 1. Constructores

```
PyList l1;
cout << len(l1); // 0
```

```
PyList l2(1,1.3);
cout << len(l2); // 2
```

```
PyList l3(1,"hola",1.3,true,0,10,"mundo",'a');
cout << len(l3); // 8
```

### 2. Métodos

```
PyList l1;
l1.append(1.3);
cout << len(l1); // 1
```

```
PyList l2("hola");
l2.append(1.3);
l2.append(2.3);
cout << len(l2); // 3
```

```
PyList l3(1,"hola");
l3.append(PyList(2,"mundo"));
cout << len(l3); // 3
```

### 3. Índices

```
PyList l("hola",1,1.3,true,0,10,"mundo",'a')
cout << l[1] == 1; // 1 (true)
cout << l[7] == 'a'; // 1 (true)
```

```
l[2] = 'x';
cout << l[2] == 'x'; // 1 (true)
```

```
PyList l2 = l1;
PyList l3 = l2.from_to(3,5);
cout << l3[1] == l1[4]; // 1 (true)
```

### 4. Visualización
```
PyList l1;
cout << l1; // []
```

```
PyList l2(1,"hola",1.3,true,0,10,"mundo",'a')
cout << l2; // [1,hola,1.3,true,0,10,mundo,a]
```

```
PyList l1(1,2);
PyList l2(3,4);
l1.append(l2);
l1.append(5);
cout << l1; // [1,2,[3,4],5]
```



## Importante
No modificar, por ningún motivo, los archivos dentro de la carpeta <tt>test</tt>.