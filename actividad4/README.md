# Chat Básico con Named Pipes y Bash

Este proyecto implementa un chat básico que utiliza Named Pipes y bash en Linux. El chat permite la comunicación entre dos participantes.

## Creación de los Named Pipes

Para la comunicación bidireccional, se deben crear dos Named Pipes, uno para cada dirección de la comunicación. Esto se puede hacer con el comando `mkfifo`:

```bash
mkfifo pipe1
mkfifo pipe2
```

## Scripts de Chat

Cada participante en el chat necesita un script bash para enviar mensajes.

El script para el primer participante puede ser el siguiente:

```bash
#!/bin/bash
echo "Participante 1: "
while true
do
  read message
  echo "Participante 1: $message" > pipe1
done
```

Y el script para el segundo participante puede ser el siguiente:

```bash
#!/bin/bash
echo "Participante 2: "
while true
do
  read message
  echo "Participante 2: $message" > pipe2
done
```

## Ejecución

Para ejecutar el chat, se deben abrir dos terminales y ejecutar cada script en una terminal diferente. En una tercera terminal, se pueden leer los mensajes de ambos participantes con el comando cat:

```bash
cat pipe1 pipe2
```
