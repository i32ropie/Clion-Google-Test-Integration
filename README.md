# Integración de Google Test con CLion
---
Ejemplo de integración de [Google Test](https://github.com/google/googletest) junto al IDE [CLion](https://www.jetbrains.com/clion/)

---
## Prerequisitos
- [Clion](https://www.jetbrains.com/clion/)
---
## Cómo integrar los tests con nuestro proyecto
1. Creamos un archivo llamado `CMakeLists.txt.in` en la raiz de nuestro proyecto con el siguiente contenido:
```
cmake_minimum_required(VERSION 2.8.2)
project(googletest-download NONE)
include(ExternalProject)
ExternalProject_Add(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG master
    SOURCE_DIR "${CMAKE_BINARY_DIR}/googletest-src"
    BINARY_DIR "${CMAKE_BINARY_DIR}/googletest-build"
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    TEST_COMMAND ""
)
```
2. Creamos un directorio dentro de la raiz del proyecto llamado `src` donde moveremos el archivo autogenerado `main.cpp`.
3. Creamos un directior dentro de la raiz del proyecto llamado `test` que será donde guardaremos el código de nuestros tests.
4. Editamos el contenido de nuestro archivo `CMakeLists.txt` y debajo del set que hay tras el nombre del proyecto (En el caso del proyecto de prueba de este repositorio sería justo debajo de la línea `set(CMAKE_CXX_STANDARD 11)`) ponemos el siguiente código:
```
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
        "${CMAKE_BINARY_DIR}/googletest-build")
if(CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include")
endif()

include_directories(cmake-build-debug/googletest-src/googlemock/include)
include_directories(cmake-build-debug/googletest-src/googletest/include)
```
5. Borramos la línea que dice `add_executable`  y escribimos las siguientes líneas:
```
set(SOURCE_TEST_FILES test/main.cpp)
set(SOURCE_FILES src/main.cpp)
# Cambiar Prueba por el nombre del ejecutable que queráis que tenga el programa principal
add_executable(Prueba ${SOURCE_FILES})
# Cambiar Tests por el nombre del ejecutable que queráis que tenga el programa que ejecuta los tests
add_executable(Tests ${SOURCE_TEST_FILES})
```
6. Añadimos como última línea la siguiente:
```
# Cambiar Tests por el nombre del ejecutable que queráis que tenga el programa que ejecuta los tests
target_link_libraries(Tests gtest gtest_main)
```


Tras seguir estos pasos, nuestro proyecto ya está listo para funcionar. Lo siguiente será ir añadiendo en el directorio `src` nuestro código y en `test` los tests.

Cuando creemos un nuevo test y queramos incluir ficheros del directorio `src` podríamos hacerlo así:
```
#include "../src/archivo.h"
```
---
# Ejemplo
![Imagen de ejemplo](https://i.imgur.com/ujgOBj4.png)
