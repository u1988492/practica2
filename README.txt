#ESTRUCTURAS DE DADES I ALGORÍTMICA
##PRACTICA 2
Claudia Rebeca Hodoroga (u1988492)

En esta práctica, se gestiona la generación de horarios de exámenes para unas asignaturas introducidas, según una configuración establecida.

###ARCHIVOS
Los archivos en la carpeta son los siguientes:

* DOCUMENTACIÓN: 
	- README.txt: es este archivo, explica el funcionamiento del programa.
	- informe.pdf: contiene un breve informe explicando las estructuras de datos utilizadas.
	. doxygen: documentación HTML de la práctica
* PROGRAMA: carpeta con todos los archivos de código; contiene también los archivos en lenguaje objeto, el ejecutable de la práctica, y el script de bash para ejecutar las pruebas, que se encuentran también en la carpeta eda/p2 en el bas.
	- exec: ejecuta una serie de líneas de comando para probar los diferentes juegos de prueba, y guarda el output de cada uno en un archivo "P2out.txt".


###MENÚ
-h --help: muestra el menú de opciones indicando cómo utilizar el programa.
-v: utiliza el algoritmo voraz para los cálculos. Este simplemente busca una solución rápida que cumpla los requisitos mínimos.
-m: utiliza el algoritmo de backtracking para encontrar la mejor opción. Este busca la solución que, según la configuración, encuentre el horario que maximice la desviación normal.
-backtracking por defecto: busca una solución válida que cumpla los requisitos.
-gc: número de aulas de gran capacidad disponibles.
-cr: número de aulas de capacidad reducida disponibles.
-s: número del semestre sobre el que se quiere trabajar.
-d: límite de días que utilizar; si no se establece, su valor es -1, y el programa lo trata como ilimitado.
-fichero: archivo de entrada con los datos sobre las asignaturas.

Para compilar el porgrama, solo hay que ejecutar "./exec". Después, se mostrarán los archivos de salida uno detrás de otro.