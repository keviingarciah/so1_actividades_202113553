# Sistemas Operativos

## Script

```bash
#!/bin/bash

# Crear la variable GITHUB_USER

GITHUB_USER=""

# Leer la variable GITHUB_USER

read -p "Ingrese el nombre de usuario de GitHub: " GITHUB_USER

# Consultar la URL de GitHub API

URL="https://api.github.com/users/$GITHUB_USER"
DATA=$(curl -s $URL)

# Verificar si se obtuvo una respuesta exitosa

if [ "$(echo $DATA | jq -r '.message')" != "null" ]; then
echo "Error: No se pudo obtener información del usuario. Asegúrese de que el nombre de usuario sea válido."
exit 1
fi

# Extraer información del JSON

USER_ID=$(echo $DATA | jq -r '.id')
CREATED_AT=$(echo $DATA | jq -r '.created_at')

# Crear el mensaje

MESSAGE="Hola $GITHUB_USER. El user ID es: $USER_ID. La cuenta fue creada el: $CREATED_AT."

# Obtener la fecha actual

DATE=$(date +%Y%m%d)

# Crear el directorio de logs

LOG_DIR="/tmp/$DATE"
mkdir -p $LOG_DIR

# Crear el archivo de log

LOG_FILE="$LOG_DIR/saludos.log"
echo $MESSAGE > $LOG_FILE

# Imprimir el mensaje

echo $MESSAGE

# Imprimir la ruta del archivo de log

echo "Log guardado en: $LOG_FILE"
```

## Ejecutar Script

Dar permisos al script para que este pueda ser ejecutado:

```bash
chmod +x actividad2.sh
```

Ejecutarlo con:

```bash
./actividad2.sh
```

## Crear Cronjob

Abre una terminal y ejecuta el siguiente comando para editar el crontab del usuario actual:

```bash
crontab -e
```

Añade la siguiente línea al crontab para ejecutar el script cada 5 minutos:

```bash
*/5 * * * * /media/keviin/Almacenamiento/2023 PRIMER SEMESTRE/MAGISTRALES/SOPES 1/so1_actividades_202113553/actividad 2/actividad2.sh
```
