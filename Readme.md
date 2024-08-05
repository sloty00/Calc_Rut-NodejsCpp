# Calculador de Dígito Verificador de RUT Chileno

Este proyecto es un calculador del dígito verificador para el RUT chileno, implementado en C++ y expuesto a través de un módulo Node.js usando `node-gyp`. 

## Descripción

Este repositorio contiene un módulo Node.js que calcula el dígito verificador (DV) para un número de RUT chileno. Utiliza C++ para la lógica del cálculo y se integra con Node.js para proporcionar una interfaz accesible a través de HTTP.

## Estructura del Proyecto

- `src/`
  - `rut_calculator.cpp`: Código fuente en C++ para el cálculo del dígito verificador.
- `server.js`: Servidor Express que expone la funcionalidad del cálculo a través de una API HTTP.
- `binding.gyp`: Archivo de configuración para `node-gyp`.
- `package.json`: Archivo de configuración del proyecto Node.js.
- `README.md`: Este archivo.

## Instalación

### Prerequisitos

Asegúrate de tener instalados los siguientes programas en tu sistema:
- [Node.js](https://nodejs.org/) (incluye npm)
- [node-gyp](https://github.com/nodejs/node-gyp)
- [Microsoft Visual Studio Build Tools](https://visualstudio.microsoft.com/visual-cpp-build-tools/) (para Windows) o herramientas similares en otros sistemas operativos

### Pasos para la Instalación

1. **Clona el repositorio:**

   ```bash
   git clone https://github.com/tu_usuario/tu_repositorio.git
   cd tu_repositorio

2. **Instala Dependencias:**

    ```bash
    npm install

3. **Configura y construye el modulo C++:**

    ```bash
    node-gyp configure
    node-gyp build    
Este comando compilará el código C++ y generará el módulo de Node.js.

4. **Inicia el Servidor**

    ```bash
    node server.js

5. **Utiliza las rutas API:**

    - POST /calculate:<br/>

        Descripción: Calcula el dígito verificador para un número de RUT usando Postman.

    ```bash
    {
        "rut": 12345678
    }
    - Respuesta:

    ```bash
    {
        "rut": 12345678,
        "dv": "3"
    }