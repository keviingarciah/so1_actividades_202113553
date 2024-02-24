# Servicio de Saludo

Este servicio imprime un saludo y la fecha actual cada segundo.

## Creación del script

Crea un archivo llamado `saludo.sh` en `/usr/local/bin` con el siguiente contenido:

```bash
#!/bin/bash
while true
do
  echo "¡Hola! La fecha y hora actual es: $(date)"
  sleep 1
done
```

## Permisos

Hay que asegurarse de que el archivo tenga permisos de ejecución.

```bash
sudo chmod +x /usr/local/bin/saludo.sh
```

## Creación del servicio

Crea un archivo llamado `saludo.service` en `/etc/systemd/system` con el siguiente contenido:

```bash
[Unit]
Description=Un servicio que imprime un saludo y la fecha actual cada segundo

[Service]
ExecStart=/usr/local/bin/saludo.sh

[Install]
WantedBy=multi-user.target
```

## Habilitar el servicio

Habilita el servicio para que se inicie automáticamente al arrancar el sistema.

```bash
sudo systemctl enable saludo.service
```

## Iniciar el servicio

Inicia el servicio.

```bash
sudo systemctl start saludo.service
```

## Verificar el servicio

Verifica que el servicio esté corriendo.

```bash
sudo systemctl status saludo.service
```

## Detener el servicio

Para detener el servicio, ejecuta:

```bash
sudo systemctl stop saludo.service
```

## Deshabilitar el servicio

Para deshabilitar el servicio, ejecuta:

```bash
sudo systemctl disable saludo.service
```

## Eliminar el servicio

Para eliminar el servicio, ejecuta:

```bash
sudo systemctl stop saludo

sudo rm /etc/systemd/system/saludo.service
sudo rm /usr/local/bin/saludo.sh
sudo systemctl daemon-reload
```

# Logs

Para ver los logs del servicio, ejecuta:

```bash
journalctl -u saludo.service
```

Este comando mostrará los logs del servicio desde el inicio del sistema. Si quieres seguir los logs en tiempo real, puedes usar:

```bash
journalctl -u saludo.service -f
```
