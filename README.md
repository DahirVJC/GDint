# GDint

## Resumen
- GDint es un compilador que busca cerrar la brecha entre la lengua natural y los lenguajes de programación. GDint busca facilitar el proceso de aprendizaje para jóvenes que tienen interés en la programación y no saben por dónde empezar. 

## Motivación y Problema a Resolver
- **Descripción del problema:** Los lenguajes de programación actuales no son muy intuitivos a la hora de empezar a aprender. Muchos lenguajes son muy técnicos y es necesario la lectura de manual para saber por dónde empezar.
- **Importancia:** Debido a la interpretación que comúnmente se le da a la programación, muchos jóvenes tienen miedo a empezar con la programación porque tienen la creencia de que la programación es difícil. Con herramientas que sean capaces de convertir pseudocódigo a código, pueden aprender cómo funciona un lenguaje de programación ya que tendrán puntos de comparación.
- **Casos de uso:** El mayor caso de uso para nuestro compilador es para el aprendizaje. Otros casos de uso serían para usos más generales, hay casos en donde es necesario un script sencillo en python, pero sin el conocimiento básico es imposible hacerlo. Tener un lenguaje que pueda resolver estos problemas sin conocimiento haría que el flujo de trabajo sea más sencillo. Al mismo tiempo GDint sería capaz de operar con APIs públicas y tener la capacidad de hacer uso de los métodos verbos de HTML.

## Objetivos del Proyecto
- **Objetivo 1:** Ser una herramienta central para la enseñanza de jóvenes interesados en la programación.
- **Objetivo 2:** Hacer la programación más interactivas, actualmente es muy difícil de enseñar a jóvenes como los diagramas y pseudocódigo son traducidos a código.
- **Objetivo 3:** Simplificar la programación para tareas más sencillas sin la necesidad de conocimiento profundos de la programación.
- **Objetivo 4:** Simplificar las llamadas de API públicas para que todos sean capaces de hacer cambios simples a un API.

## Revisión del Estado del Arte
- **Compiladores similares:** PSeInt (PSEInt, s. f.), Scratch (Scratch, s. f.), Pseudocode Online Editor (PseudoEditor, s. f.)
- **Limitaciones de soluciones actuales:** Todos esos compiladores están limitados a un entorno virtual, por lo que no pueden realizar llamadas a API. Los lenguajes pseudocódigos están limitados a un área, que es la enseñanza de programación básica.
- **Justificación del nuevo compilador:** El compilador se creará para plantear una propuesta de lenguaje pseudocódigo más cercano al lenguaje natural. Además, el nuevo compilador ofrecerá una manera en la que el programador realice llamadas a API y expandiendo su potencial para ofrecer un acercamiento a las tecnologías web.

## Arquitectura y Diseño del Compilador
- **Diagrama de bloques:** ![Diagrama de bloques](/resources/GDint.drawio.png)
- **Diagrama T:** ![T-Diagram](/resources/NotacionT.png)
Donde:
  - GDInt es el lenguaje nuevo a compilar.
  - Python es al lenguaje donde se va a traducir.
  - C++ es el lenguaje de implementación.
  - 64 bits  es la arquitectura de las máquinas en las que se va a ejecutar.
- **Explicación del flujo de datos:** El compilador recibe un flujo de caracteres en el formato GDint, pasa por los análisis léxico, sintáctico y semántico para crear un flujo de tokens y árboles sintácticos para crear la tabla de símbolos, la cual, es usada para generar código intermedio que es optimizado para producir código en el lenguaje de programación de python. Al final, el código generado es optimizado y se entrega como la salida del compilador.
- **Decisiones de diseño:** Se utiliza la arquitectura típica de un compilador, solo que se especifica que el flujo de caracteres es pseudocódigo GDint y la salida es código python en vez de código máquina. Se elige la arquitectura de 64 bits porque es la correspondiente a las máquinas que se utilizan para desarrollar y ejecutar el compilador. Las pruebas y adaptación del compilador a máquinas de 32 bits, ARM u otras arquitecturas queda fuera del alcance del proyecto.

## Análisis Léxico
- **Análisis léxico:**
[Tabla NFA a DFA](https://docs.google.com/spreadsheets/d/1d-Ae-Xse4y_mCXiTdAH2pxOPNWBGBultBXIrC_2EEV8/edit?usp=sharing)

![Automata](/resources/analizador_Lexico.jpg)
  - Tokenización, identificación de palabras clave, operadores, etc.
    - Identificador: ```[a-z|A-Z|_][a-z|A-Z|_]*```
    - Constante: ```[+|-]?\d+```
    - Keyword: ```(si|variable|entonces|sino|finsi|publicar|obtener|cambiar|borrar)```
    - Whitespace: ```[\t\r\f\v]+```
    - Puntuacion: ```[\n| |"|(|)|,|#]```
    - Operadores: ```[+|-|=|*|/|==|**||**|&&|<|>|!|?]```
- **Ejemplos:**
- a -> Identificador
- +98 -> Constante
- variable -> Keyword
-    -> Whitespace
- || -> Operador
  
![Ejemplo de éxito](/resources/lexerCorrect.jpg)

## Análisis Sintáctico

- **Análisis sintáctico:**
  **Nota**: Por cuestiones de implementación, " " se escribe como space en las reglas, y \n como salto únicamente en el archivo de gramática (LL1Grammar.txt), esto para ser interpretado correctamente por el lector de gramática.
  - **Gramatica:**
    - CODIGO -> BLOQUE CODIGO'
    - CODIGO' -> BLOQUE CODIGO' | ε
    - BLOQUE -> ACCION BLOQUE'
    - BLOQUE' -> \n ACCION BLOQUE' | ε
    - ANIDADO -> ACCION \n ANIDADO'
    - ANIDADO' -> ACCION \n ANIDADO' | ε
    - ACCION -> CONDICIONAL | INSTRUCCION | COMENTARIO
    - CONDICIONAL -> si ESPACIO CONDICION ESPACIO entonces \n ANIDADO SINO finsi
    - SINO -> sino \n ANIDADO | ε
    - CONDICION -> COMPARACION CONDICION'
    - CONDICION' -> && COMPARACION CONDICION' | || COMPARACION CONDICION' | ε
    - COMPARACION -> BOOL COMPARACION'
    - COMPARACION' -> == BOOL COMPARACION' | < BOOL COMPARACION' | > BOOL COMPARACION' | ε
    - BOOL -> identificador | ! identificador | CONSTANTE
    - COMENTARIO -> # INSTRUCCION
    - INSTRUCCION -> DECLARACION | ASIGNACION | LLAMADA
    - LLAMADA -> FUNCION ESPACIO PARAMETROS
    - PARAMETROS -> VALOR PARAMETROS'
    - PARAMETROS' -> ESPACIO VALOR PARAMETROS' | ε
    - VALOR -> identificador | CONSTANTE
    - FUNCION -> obtener | publicar | cambiar | borrar
    - DECLARACION -> variable ESPACIO identificador ESPACIO = ESPACIO EXP
    - ASIGNACION -> identificador ESPACIO = ESPACIO EXP
    - EXP -> FACTOR EXP'
    - EXP' -> ESPACIO OPSIMP FACTOR EXP' | ε
    - OPSIMP -> + ESPACIO | - ESPACIO | * ESPACIO | / ESPACIO
    - FACTOR -> identificador | CONSTANTE | ( EXP )
    - ESPACIO -> space ESPACIO'
    - ESPACIO' -> space ESPACIO' | ε
    - CONSTANTE -> constante | ' CADENA '
    - CADENA -> ∈Σ-' CADENA'
    - CADENA' -> ∈Σ-' CADENA' | ε
  - **Análisis first:**
    - CODIGO=si variable identificador obtener publicar cambiar borrar #
    - CODIGO'=si variable identificador obtener publicar cambiar borrar # ε
    - BLOQUE=si variable identificador obtener publicar cambiar borrar #
    - BLOQUE'=\n ε
    - ANIDADO=si variable identificador obtener publicar cambiar borrar #
    - ANIDADO'=si variable identificador obtener publicar cambiar borrar # ε
    - ACCION=si variable identificador obtener publicar cambiar borrar #
    - CONDICIONAL=si
    - SINO=sino ε
    - CONDICION=identificador ! constante '
    - CONDICION'=&& || ε
    - COMPARACION=identificador ! constante '
    - COMPARACION'=== < > ε
    - BOOL=identificador ! constante '
    - COMENTARIO=#
    - INSTRUCCION=variable identificador obtener publicar cambiar borrar
    - LLAMADA=obtener publicar cambiar borrar
    - PARAMETROS=identificador constante '
    - PARAMETROS'=space ε
    - VALOR=identificador constante '
    - FUNCION=obtener publicar cambiar borrar
    - DECLARACION=variable
    - ASIGNACION=identificador
    - EXP=identificador constante ' (
    - EXP'=space ε
    - OPSIMP=+ - * /
    - FACTOR=identificador constante ' (
    - ESPACIO=space
    - ESPACIO'=space ε
    - CONSTANTE=constante '
    - CADENA=∈Σ-'
    - CADENA'=∈Σ-' ε
  - **Análisis Follow:**
    - CODIGO = EOF
    - CODIGO' = EOF
    - BLOQUE = # EOF borrar cambiar identificador obtener publicar si variable
    - BLOQUE' = # EOF borrar cambiar identificador obtener publicar si variable
    - ANIDADO = \n # EOF borrar cambiar finsi identificador obtener publicar si sino variable
    - ANIDADO' = \n # EOF borrar cambiar finsi identificador obtener publicar si sino variable
    - ACCION = \n # EOF borrar cambiar identificador obtener publicar si variable
    - CONDICIONAL = \n # EOF borrar cambiar identificador obtener publicar si variable
    - SINO = finsi
    - CONDICION = space
    - CONDICION' = space
    - COMPARACION = space && ||
    - COMPARACION' = space && ||
    - BOOL = space && < == > ||
    - COMENTARIO = \n # EOF borrar cambiar identificador obtener publicar si variable
    - INSTRUCCION = \n # EOF borrar cambiar identificador obtener publicar si variable
    - LLAMADA = \n # EOF borrar cambiar identificador obtener publicar si variable
    - PARAMETROS = \n # EOF borrar cambiar identificador obtener publicar si variable
    - PARAMETROS' = \n # EOF borrar cambiar identificador obtener publicar si variable
    - VALOR = \n space # EOF borrar cambiar identificador obtener publicar si variable
    - FUNCION = space
    - DECLARACION = \n # EOF borrar cambiar identificador obtener publicar si variable
    - ASIGNACION = \n # EOF borrar cambiar identificador obtener publicar si variable
    - EXP = \n # ) EOF borrar cambiar identificador obtener publicar si variable
    - EXP' = \n # ) EOF borrar cambiar identificador obtener publicar si variable
    - OPSIMP = ' ( constante identificador
    - FACTOR = \n space # ) EOF borrar cambiar identificador obtener publicar si variable
    - ESPACIO = ! ' ( * + - / = constante entonces identificador
    - ESPACIO' = ! ' ( * + - / = constante entonces identificador
    - CONSTANTE = \n space # && ) < == > EOF borrar cambiar identificador obtener publicar si variable ||
    - CADENA = '
    - CADENA' = '
  - **Reglas de parseo (Parsing Table):**
    - [Tabla de parseo](https://docs.google.com/spreadsheets/d/1QxdhRR3tCjMBeSxMir3cwsD7_051wFhnC_6Y7lOdV9g/edit?usp=sharing)
    - En \<ACCION> dado [#] produce: COMENTARIO
    - En \<ACCION> dado [borrar] produce: INSTRUCCION
    - En \<ACCION> dado [cambiar] produce: INSTRUCCION
    - En \<ACCION> dado [identificador] produce: INSTRUCCION
    - En \<ACCION> dado [obtener] produce: INSTRUCCION
    - En \<ACCION> dado [publicar] produce: INSTRUCCION
    - En \<ACCION> dado [si] produce: CONDICIONAL
    - En \<ACCION> dado [variable] produce: INSTRUCCION
    - En \<ANIDADO> dado [#] produce: ACCION \n ANIDADO'
    - En \<ANIDADO> dado [borrar] produce: ACCION \n ANIDADO'
    - En \<ANIDADO> dado [cambiar] produce: ACCION \n ANIDADO'
    - En \<ANIDADO> dado [identificador] produce: ACCION \n ANIDADO'
    - En \<ANIDADO> dado [obtener] produce: ACCION \n ANIDADO'
    - En \<ANIDADO> dado [publicar] produce: ACCION \n ANIDADO'
    - En \<ANIDADO> dado [si] produce: ACCION \n ANIDADO'
    - En \<ANIDADO> dado [variable] produce: ACCION \n ANIDADO'
    - En \<ANIDADO'> dado [\n] produce: ε
    - En \<ANIDADO'> dado [#] produce: ACCION \n ANIDADO'
    - En \<ANIDADO'> dado [EOF] produce: ε
    - En \<ANIDADO'> dado [borrar] produce: ACCION \n ANIDADO'
    - En \<ANIDADO'> dado [cambiar] produce: ACCION \n ANIDADO'
    - En \<ANIDADO'> dado [finsi] produce: ε
    - En \<ANIDADO'> dado [identificador] produce: ACCION \n ANIDADO'
    - En \<ANIDADO'> dado [obtener] produce: ACCION \n ANIDADO'
    - En \<ANIDADO'> dado [publicar] produce: ACCION \n ANIDADO'
    - En \<ANIDADO'> dado [si] produce: ACCION \n ANIDADO'
    - En \<ANIDADO'> dado [sino] produce: ε
    - En \<ANIDADO'> dado [variable] produce: ACCION \n ANIDADO'
    - En \<ANIDADO'> dado [ε] produce: ε
    - En \<ASIGNACION> dado [identificador] produce: identificador ESPACIO = ESPACIO EXP
    - En \<BLOQUE> dado [#] produce: ACCION BLOQUE'
    - En \<BLOQUE> dado [borrar] produce: ACCION BLOQUE'
    - En \<BLOQUE> dado [cambiar] produce: ACCION BLOQUE'
    - En \<BLOQUE> dado [identificador] produce: ACCION BLOQUE'
    - En \<BLOQUE> dado [obtener] produce: ACCION BLOQUE'
    - En \<BLOQUE> dado [publicar] produce: ACCION BLOQUE'
    - En \<BLOQUE> dado [si] produce: ACCION BLOQUE'
    - En \<BLOQUE> dado [variable] produce: ACCION BLOQUE'
    - En \<BLOQUE'> dado [\n] produce: \n ACCION BLOQUE'
    - En \<BLOQUE'> dado [#] produce: ε
    - En \<BLOQUE'> dado [EOF] produce: ε
    - En \<BLOQUE'> dado [borrar] produce: ε
    - En \<BLOQUE'> dado [cambiar] produce: ε
    - En \<BLOQUE'> dado [identificador] produce: ε
    - En \<BLOQUE'> dado [obtener] produce: ε
    - En \<BLOQUE'> dado [publicar] produce: ε
    - En \<BLOQUE'> dado [si] produce: ε
    - En \<BLOQUE'> dado [variable] produce: ε
    - En \<BLOQUE'> dado [ε] produce: ε
    - En \<BOOL> dado [!] produce: ! identificador
    - En \<BOOL> dado ['] produce: CONSTANTE
    - En \<BOOL> dado [constante] produce: CONSTANTE
    - En \<BOOL> dado [identificador] produce: identificador
    - En \<CADENA> dado [\n] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [space] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [!] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado ["] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [#] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [$] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [%] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [&] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [&&] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [(] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [)] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [*] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [+] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [,] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [-] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [.] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [/] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [0] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [1] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [2] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [3] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [4] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [5] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [6] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [7] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [8] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [9] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [:] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [;] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [<] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [=] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [==] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [>] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [?] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [@] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [A] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [B] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [C] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [D] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [E] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [F] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [G] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [H] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [I] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [J] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [K] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [L] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [M] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [N] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [O] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [P] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [Q] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [R] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [S] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [T] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [U] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [V] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [W] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [X] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [Y] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [Z] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [[] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [\] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado []] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [^] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [_] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [`] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [a] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [b] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [borrar] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [c] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [cambiar] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [constante] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [d] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [e] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [entonces] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [f] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [finsi] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [g] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [h] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [i] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [identificador] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [j] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [k] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [l] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [m] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [n] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [o] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [obtener] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [p] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [publicar] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [q] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [r] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [s] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [si] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [sino] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [t] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [u] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [v] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [variable] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [w] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [x] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [y] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [z] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [{] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [|] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [||] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [}] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [~] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [ε] produce: ∈Σ-' CADENA'
    - En \<CADENA> dado [∈Σ-'] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [\n] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [space] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [!] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado ["] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [#] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [$] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [%] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [&] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [&&] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado ['] produce: ε
    - En \<CADENA'> dado [(] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [)] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [*] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [+] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [,] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [-] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [.] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [/] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [0] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [1] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [2] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [3] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [4] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [5] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [6] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [7] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [8] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [9] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [:] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [;] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [<] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [=] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [==] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [>] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [?] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [@] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [A] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [B] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [C] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [D] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [E] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [F] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [G] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [H] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [I] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [J] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [K] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [L] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [M] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [N] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [O] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [P] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [Q] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [R] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [S] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [T] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [U] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [V] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [W] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [X] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [Y] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [Z] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [[] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [\] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado []] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [^] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [_] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [`] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [a] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [b] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [borrar] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [c] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [cambiar] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [constante] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [d] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [e] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [entonces] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [f] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [finsi] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [g] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [h] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [i] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [identificador] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [j] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [k] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [l] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [m] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [n] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [o] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [obtener] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [p] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [publicar] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [q] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [r] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [s] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [si] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [sino] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [t] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [u] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [v] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [variable] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [w] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [x] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [y] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [z] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [{] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [|] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [||] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [}] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [~] produce: ∈Σ-' CADENA'
    - En \<CADENA'> dado [ε] produce: ε
    - En \<CADENA'> dado [∈Σ-'] produce: ∈Σ-' CADENA'
    - En \<CODIGO> dado [#] produce: BLOQUE CODIGO'
    - En \<CODIGO> dado [borrar] produce: BLOQUE CODIGO'
    - En \<CODIGO> dado [cambiar] produce: BLOQUE CODIGO'
    - En \<CODIGO> dado [identificador] produce: BLOQUE CODIGO'
    - En \<CODIGO> dado [obtener] produce: BLOQUE CODIGO'
    - En \<CODIGO> dado [publicar] produce: BLOQUE CODIGO'
    - En \<CODIGO> dado [si] produce: BLOQUE CODIGO'
    - En \<CODIGO> dado [variable] produce: BLOQUE CODIGO'
    - En \<CODIGO'> dado [#] produce: BLOQUE CODIGO'
    - En \<CODIGO'> dado [EOF] produce: ε
    - En \<CODIGO'> dado [borrar] produce: BLOQUE CODIGO'
    - En \<CODIGO'> dado [cambiar] produce: BLOQUE CODIGO'
    - En \<CODIGO'> dado [identificador] produce: BLOQUE CODIGO'
    - En \<CODIGO'> dado [obtener] produce: BLOQUE CODIGO'
    - En \<CODIGO'> dado [publicar] produce: BLOQUE CODIGO'
    - En \<CODIGO'> dado [si] produce: BLOQUE CODIGO'
    - En \<CODIGO'> dado [variable] produce: BLOQUE CODIGO'
    - En \<CODIGO'> dado [ε] produce: ε
    - En \<COMENTARIO> dado [#] produce: # INSTRUCCION
    - En \<COMPARACION> dado [!] produce: BOOL COMPARACION'
    - En \<COMPARACION> dado ['] produce: BOOL COMPARACION'
    - En \<COMPARACION> dado [constante] produce: BOOL COMPARACION'
    - En \<COMPARACION> dado [identificador] produce: BOOL COMPARACION'
    - En \<COMPARACION'> dado [space] produce: ε
    - En \<COMPARACION'> dado [&&] produce: ε
    - En \<COMPARACION'> dado [<] produce: < BOOL COMPARACION'
    - En \<COMPARACION'> dado [==] produce: == BOOL COMPARACION'
    - En \<COMPARACION'> dado [>] produce: > BOOL COMPARACION'
    - En \<COMPARACION'> dado [||] produce: ε
    - En \<COMPARACION'> dado [ε] produce: ε
    - En \<CONDICION> dado [!] produce: COMPARACION CONDICION'
    - En \<CONDICION> dado ['] produce: COMPARACION CONDICION'
    - En \<CONDICION> dado [constante] produce: COMPARACION CONDICION'
    - En \<CONDICION> dado [identificador] produce: COMPARACION CONDICION'
    - En \<CONDICION'> dado [space] produce: ε
    - En \<CONDICION'> dado [&&] produce: && COMPARACION CONDICION'
    - En \<CONDICION'> dado [||] produce: || COMPARACION CONDICION'
    - En \<CONDICION'> dado [ε] produce: ε
    - En \<CONDICIONAL> dado [si] produce: si ESPACIO CONDICION ESPACIO entonces \n ANIDADO SINO finsi
    - En \<CONSTANTE> dado ['] produce: ' CADENA '
    - En \<CONSTANTE> dado [constante] produce: constante
    - En \<DECLARACION> dado [variable] produce: variable ESPACIO identificador ESPACIO = ESPACIO EXP
    - En \<ESPACIO> dado [space] produce: space ESPACIO'
    - En \<ESPACIO'> dado [space] produce: space ESPACIO'
    - En \<ESPACIO'> dado [!] produce: ε
    - En \<ESPACIO'> dado ['] produce: ε
    - En \<ESPACIO'> dado [(] produce: ε
    - En \<ESPACIO'> dado [*] produce: ε
    - En \<ESPACIO'> dado [+] produce: ε
    - En \<ESPACIO'> dado [-] produce: ε
    - En \<ESPACIO'> dado [/] produce: ε
    - En \<ESPACIO'> dado [=] produce: ε
    - En \<ESPACIO'> dado [constante] produce: ε
    - En \<ESPACIO'> dado [entonces] produce: ε
    - En \<ESPACIO'> dado [identificador] produce: ε
    - En \<ESPACIO'> dado [ε] produce: ε
    - En \<EXP> dado ['] produce: FACTOR EXP'
    - En \<EXP> dado [(] produce: FACTOR EXP'
    - En \<EXP> dado [constante] produce: FACTOR EXP'
    - En \<EXP> dado [identificador] produce: FACTOR EXP'
    - En \<EXP'> dado [\n] produce: ε
    - En \<EXP'> dado [space] produce: ESPACIO OPSIMP FACTOR EXP'
    - En \<EXP'> dado [#] produce: ε
    - En \<EXP'> dado [)] produce: ε
    - En \<EXP'> dado [EOF] produce: ε
    - En \<EXP'> dado [borrar] produce: ε
    - En \<EXP'> dado [cambiar] produce: ε
    - En \<EXP'> dado [identificador] produce: ε
    - En \<EXP'> dado [obtener] produce: ε
    - En \<EXP'> dado [publicar] produce: ε
    - En \<EXP'> dado [si] produce: ε
    - En \<EXP'> dado [variable] produce: ε
    - En \<EXP'> dado [ε] produce: ε
    - En \<FACTOR> dado ['] produce: CONSTANTE
    - En \<FACTOR> dado [(] produce: ( EXP )
    - En \<FACTOR> dado [constante] produce: CONSTANTE
    - En \<FACTOR> dado [identificador] produce: identificador
    - En \<FUNCION> dado [borrar] produce: borrar
    - En \<FUNCION> dado [cambiar] produce: cambiar
    - En \<FUNCION> dado [obtener] produce: obtener
    - En \<FUNCION> dado [publicar] produce: publicar
    - En \<INSTRUCCION> dado [borrar] produce: LLAMADA
    - En \<INSTRUCCION> dado [cambiar] produce: LLAMADA
    - En \<INSTRUCCION> dado [identificador] produce: ASIGNACION
    - En \<INSTRUCCION> dado [obtener] produce: LLAMADA
    - En \<INSTRUCCION> dado [publicar] produce: LLAMADA
    - En \<INSTRUCCION> dado [variable] produce: DECLARACION
    - En \<LLAMADA> dado [borrar] produce: FUNCION ESPACIO PARAMETROS
    - En \<LLAMADA> dado [cambiar] produce: FUNCION ESPACIO PARAMETROS
    - En \<LLAMADA> dado [obtener] produce: FUNCION ESPACIO PARAMETROS
    - En \<LLAMADA> dado [publicar] produce: FUNCION ESPACIO PARAMETROS
    - En \<OPSIMP> dado [*] produce: * ESPACIO
    - En \<OPSIMP> dado [+] produce: + ESPACIO
    - En \<OPSIMP> dado [-] produce: - ESPACIO
    - En \<OPSIMP> dado [/] produce: / ESPACIO
    - En \<PARAMETROS> dado ['] produce: VALOR PARAMETROS'
    - En \<PARAMETROS> dado [constante] produce: VALOR PARAMETROS'
    - En \<PARAMETROS> dado [identificador] produce: VALOR PARAMETROS'
    - En \<PARAMETROS'> dado [\n] produce: ε
    - En \<PARAMETROS'> dado [space] produce: ESPACIO VALOR PARAMETROS'
    - En \<PARAMETROS'> dado [#] produce: ε
    - En \<PARAMETROS'> dado [EOF] produce: ε
    - En \<PARAMETROS'> dado [borrar] produce: ε
    - En \<PARAMETROS'> dado [cambiar] produce: ε
    - En \<PARAMETROS'> dado [identificador] produce: ε
    - En \<PARAMETROS'> dado [obtener] produce: ε
    - En \<PARAMETROS'> dado [publicar] produce: ε
    - En \<PARAMETROS'> dado [si] produce: ε
    - En \<PARAMETROS'> dado [variable] produce: ε
    - En \<PARAMETROS'> dado [ε] produce: ε
    - En \<SINO> dado [finsi] produce: ε
    - En \<SINO> dado [sino] produce: sino \n ANIDADO
    - En \<SINO> dado [ε] produce: ε
    - En \<VALOR> dado ['] produce: CONSTANTE
    - En \<VALOR> dado [constante] produce: CONSTANTE
    - En \<VALOR> dado [identificador] produce: identificador
- **Ejemplos:**
````
variable a = 0
a = 3 + 2
variable b = a * 9
variable c = 'a' + 'b'
variable d = 4 + 'b'
si a<4&&a==-3 entonces
obtener 'https://pokeapi.co/api/v2/pokemon/ditto'
obtener 'https://pokeapi.co/api/v2/pokemon/incineroar'
sino
obtener 'https://pokeapi.co/api/v2/pokemon/incineroar'
finsi
#obtener 'https://pokeapi.co/api/v2/pokemon/ditto'
variable body = '
doe: "a deer, a female deer"
 ray: "a drop of golden sun"
 pi: 3.14159
 xmas: true
 french-hens: 3
 calling-birds:
   - huey
   - dewey
   - louie
   - fred
 xmas-fifth-day:
   calling-birds: four
   french-hens: 3
   golden-rings: 5
   partridges:
     count: 1
     location: "a pear tree"
   turtle-doves: two
'
publicar 'https://pokeapi.co/api/v2/pokemon/ditto' body
variable f = 'h'
````
Salida: `Valido`
````
variable a
a = 3 +
variable b = a * 9
variable c = 'a' + 'b'
variable d = 4 + 'b'
si a<4&&a==-3
obtener 'https://pokeapi.co/api/v2/pokemon/ditto'
obtener 'https://pokeapi.co/api/v2/pokemon/incineroar'
sino
obtener 'https://pokeapi.co/api/v2/pokemon/incineroar'
finsi
publicar
variable f = 'h'
````
Salida: `Error de sintaxis`
````
variable a = 0
a = 3 + 2
variable a = 'a'
````
Salida: `La variable 'a' ya fue declarada previamente`
````
variable a = 0
a = 3 + 2
variable b = a + u
````
Salida: `Uso de una variable no declarada: u`
````
a = 3 + 2
````
Salida: `Uso de una variable no declarada: a`
## Análisis Semántico

- **Análisis sintáctico:**
    

- **Ejemplos:**

## Pruebas y Validación

- **Metodología de pruebas:**
- **Resultados obtenidos:**
- **Casos de prueba específicos:**

## Herramientas y Entorno de Desarrollo
- **Lenguajes de programación utilizados:** C++ y Python
- **Herramientas de desarrollo:** Git, GitHub y CLion
- **Entorno de pruebas y simulación:** Pruebas en CLion en los sistemas operativos Windows 10, Windows 11 y EndeavourOS
- **Otras herramientas:** Draw.io, Google Docs, ChatGPT y Claude

## Demostración
- **Ejemplo de código fuente:**
- **Proceso de compilación:**
- **Ejecución del código compilado:**

## Desafíos y Soluciones
- **Problemas técnicos o de diseño:**
- **Estrategias adoptadas para superar desafíos:**
- **Lecciones aprendidas:**

## Conclusiones y Trabajo Futuro
- **Resumen de objetivos cumplidos:**
- **Evaluación del desempeño:**
- **Propuestas para mejoras futuras:**

## Preguntas y Discusión
- Espacio para responder preguntas y discusión sobre el proyecto.

## Referencias
- **Fuentes citadas:** Lista de libros, artículos, papers, y otras fuentes relevantes.
  - Anthropic. (2024). *Claude* (Claude 3.5 Sonnet) [Modelo de lenguaje de gran tamaño]. https://claude.ai/
  - Anuragvbj79. (2024). *How to Extract a Subvector from a Vector in C++?* GeeksforGeeks. https://www.geeksforgeeks.org/how-to-extract-a-subvector-from-a-vector-in-cpp/
  - Neso Academy. (2023). *LL(1) Parsing* [Vídeo]. YouTube. https://www.youtube.com/watch?v=clkHOgZUGWU
  - OpenAI. (2024). *ChatGPT* (GPT-4o) [Modelo de lenguaje de gran tamaño]. https://chat.openai.com/chat
  - OpenAI. (2024). *ChatGPT* (GPT-4o mini) [Modelo de lenguaje de gran tamaño]. https://chat.openai.com/chat
  - PSEInt. (s. f.). *PSEInt*. https://pseint.sourceforge.net/
  - PseudoEditor. (s. f.). *Pseudocode Editor online - PseudoEditor*. https://pseudoeditor.com/
  - Riteshjha0002. (2023). *Split String by Space into Vector in C++ STL.* GeeksforGeeks. https://www.geeksforgeeks.org/split-string-by-space-into-vector-in-cpp-stl/
  - Scratch. (s. f.). *Scratch - FAQ*. https://scratch.mit.edu/faq

