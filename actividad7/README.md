# Completely Fair Scheduler (CFS) de Linux

El Completely Fair Scheduler (CFS) es el algoritmo de planificación de procesos que utiliza el kernel de Linux por defecto. Fue introducido en la versión 2.6.23 del kernel de Linux.

## Características Principales

1. **Equidad**: Como su nombre indica, el objetivo principal del CFS es proporcionar una planificación justa para todos los procesos en el sistema. Esto significa que cada proceso debe obtener una porción de tiempo de CPU proporcional a su prioridad.

2. **Balanceo de carga**: El CFS también se encarga de distribuir los procesos de manera equitativa entre los diferentes núcleos de la CPU.

3. **Planificación de tiempo compartido**: El CFS utiliza un modelo de planificación de tiempo compartido, lo que significa que divide el tiempo de CPU en pequeñas porciones y las asigna a cada proceso por turnos.

## Funcionamiento

El CFS utiliza un árbol rojo-negro para almacenar los procesos en función de su tiempo de ejecución. El proceso con el menor tiempo de ejecución se encuentra en la raíz del árbol y es el próximo en ser ejecutado.

Cuando un proceso se ejecuta, su tiempo de ejecución se incrementa. Cuando su tiempo de ejecución supera al del siguiente proceso en el árbol, el proceso se mueve hacia abajo en el árbol y el siguiente proceso se mueve a la raíz y se ejecuta.

De esta manera, el CFS garantiza que todos los procesos obtengan una porción justa de tiempo de CPU.
