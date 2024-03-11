# Hilos y Procesos

El programa crea procesos y hilos utilizando la función fork() y la función thread_create(), respectivamente.

La función fork() crea un nuevo proceso duplicando el proceso actual. El nuevo proceso, llamado proceso hijo, es una copia exacta del proceso actual, llamado proceso padre, excepto por algunos valores que se cambian, como el PID (ID del proceso). Si fork() se ejecuta con éxito, devuelve el PID del proceso hijo al proceso padre, y devuelve 0 al proceso hijo.

La función thread_create() crea un nuevo hilo en el proceso actual. Los hilos comparten el mismo espacio de memoria que el proceso que los creó, por lo que pueden acceder a las mismas variables y estructuras de datos. Esto es diferente de los procesos, que tienen su propio espacio de memoria.

En el programa, se llama a fork() tres veces y a thread_create() una vez. Aquí está el detalle:

En la línea 19, se llama a fork(). Esto crea un nuevo proceso. Ahora hay dos procesos en total: el proceso padre y el proceso hijo.

En la línea 22, dentro del bloque if (pid == 0), se llama a fork() de nuevo, pero solo en el proceso hijo. Esto crea otro proceso hijo. Ahora hay tres procesos en total: el proceso padre y dos procesos hijos.

En la línea 24, todavía dentro del bloque if (pid == 0), se llama a thread_create(), pero solo en uno de los procesos hijos. Esto crea un nuevo hilo en ese proceso hijo. Ahora hay tres procesos y un hilo en total.

En la línea 26, fuera del bloque if (pid == 0), se llama a fork() de nuevo. Esto se ejecuta en todos los procesos existentes (el proceso padre y los dos procesos hijos), creando tres nuevos procesos. Ahora hay seis procesos y un hilo en total.

## ¿Cuántos procesos se crean en total?

Basado en lo anterior y al ejecutar el programa, se crean **6 procesos en total**.

## ¿Cuántos hilos se crean en total?

Basado en lo anterior y al ejecutar el programa, se crea **1 hilo en total**.
