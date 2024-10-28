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

- **Explicación del flujo de datos:** El compilador recibe un flujo de caracteres en el formato GDint, pasa por los análisis léxico, sintáctico y semántico para crear un flujo de tokens y árboles sintácticos para crear la tabla de símbolos, la cual, es usada para generar código intermedio que es optimizado para producir código en el lenguaje de programación de python. Al final, el código generado es optimizado y se entrega como la salida del compilador.
- **Decisiones de diseño:** Se utiliza la arquitectura típica de un compilador, solo que se especifica que el flujo de caracteres es pseudocódigo GDint y la salida es código python en vez de código máquina.

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
  - **Gramatica:**
    - CODIGO->BLOQUE CODIGO'
    - CODIGO'->BLOQUE CODIGO'|ε
    - BLOQUE->ACCION BLOQUE'
    - BLOQUE'->salto ACCION BLOQUE'|ε
    - ACCION->CONDICIONAL|INSTRUCCION|COMENTARIO
    - CONDICIONAL->si ESPACIO CONDICION ESPACIO entonces salto BLOQUE salto SINO finsi salto
    - SINO->sino salto BLOQUE salto|ε
    - CONDICION->COMPARACION CONDICION'
    - CONDICION'->&& COMPARACION CONDICION'|or COMPARACION CONDICION'|ε
    - COMPARACION->BOOL COMPARACION'
    - COMPARACION'->== BOOL COMPARACION'|< BOOL COMPARACION'|> BOOL COMPARACION'|ε
    - BOOL->identificador|! identificador|CONSTANTE
    - COMENTARIO-># INSTRUCCION
    - INSTRUCCION->DECLARACION|ASIGNACION|LLAMADA
    - LLAMADA->FUNCION ESPACIO PARAMETROS
    - PARAMETROS->CONSTANTE PARAMETROS'
    - PARAMETROS'->ESPACIO CONSTANTE PARAMETROS'|ε
    - FUNCION->obtener|publicar|cambiar|borrar
    - DECLARACION->variable ESPACIO identificador
    - ASIGNACION->identificador ESPACIO = ESPACIO EXP
    - EXP->TERM EXP'
    - EXP'->+ ESPACIO TERM EXP'|- ESPACIO TERM EXP'|ε
    - TERM->FACTOR TERM'
    - TERM'->* FACTOR TERM'|/ FACTOR TERM'|ε
    - FACTOR->identificador|CONSTANTE|( EXP )
    - ESPACIO->space ESPACIO'
    - ESPACIO'->space ESPACIO'|ε
    - CONSTANTE->constante|' CADENA '
    - CADENA->∈Σ-' CADENA'
    - CADENA'->∈Σ-' CADENA'|ε
  - **Análisis first:**
    - CODIGO=si variable identificador obtener publicar cambiar borrar #
    - CODIGO'=si variable identificador obtener publicar cambiar borrar # ε
    - BLOQUE=si variable identificador obtener publicar cambiar borrar #
    - BLOQUE'=\n ε
    - ACCION=si variable identificador obtener publicar cambiar borrar #
    - CONDICIONAL=si
    - SINO=sino ╬╡
    - CONDICION=identificador ! constante '
    - CONDICION'=&& || ε
    - COMPARACION=identificador ! constante '
    - COMPARACION'=== < > ε
    - BOOL=identificador ! constante '
    - COMENTARIO=#
    - INSTRUCCION=variable identificador obtener publicar cambiar borrar
    - LLAMADA=obtener publicar cambiar borrar
    - PARAMETROS=constante '
    - PARAMETROS'=space ε
    - FUNCION=obtener publicar cambiar borrar
    - DECLARACION=variable
    - ASIGNACION=identificador
    - EXP=identificador constante ' (
    - EXP'=+ - ε
    - TERM=identificador constante ' (
    - TERM'=* / ε
    - FACTOR=identificador constante ' (
    - ESPACIO=space
    - ESPACIO'=space ε
    - CONSTANTE=constante '
    - CADENA=∈Σ-'
    - CADENA'=∈Σ-' ε
  - **Análisis Follow:**
    - CODIGO = EOF
    - CODIGO' = EOF
    - BLOQUE = \n # EOF borrar cambiar identificador obtener publicar si variable
    - BLOQUE' = \n # EOF borrar cambiar identificador obtener publicar si variable
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
    - FUNCION = space
    - DECLARACION = \n # EOF borrar cambiar identificador obtener publicar si variable
    - ASIGNACION = \n # EOF borrar cambiar identificador obtener publicar si variable
    - EXP = \n # ) EOF borrar cambiar identificador obtener publicar si variable
    - EXP' = \n # ) EOF borrar cambiar identificador obtener publicar si variable
    - TERM = \n # ) + - EOF borrar cambiar identificador obtener publicar si variable
    - TERM' = \n # ) + - EOF borrar cambiar identificador obtener publicar si variable
    - FACTOR = \n # ) * + - / EOF borrar cambiar identificador obtener publicar si variable
    - ESPACIO = ! ' ( = constante entonces identificador
    - ESPACIO' = ! ' ( = constante entonces identificador
    - CONSTANTE = \n space # && ) * + - / < == > EOF borrar cambiar identificador obtener publicar si variable ||
    - CADENA = '
    - CADENA' = '

- **Ejemplos:**
  - variable a
  - a = 3+ 2
  - obtener 'https://pokeapi.co/api/v2/pokemon/ditto'
  - obtener 'https://pokeapi.co/api/v2/pokemon/incineroar'
  - #obtener 'https://pokeapi.co/api/v2/pokemon/ditto'
  - variable body
  - body = '
  - doe: "a deer, a female deer"
  - ray: "a drop of golden sun"
  - pi: 3.14159
  - xmas: true
  - french-hens: 3
  - calling-birds:
  - huey
  - dewey
  - louie
  - fred
  - xmas-fifth-day:
  - calling-birds: four
  - french-hens: 3
  - golden-rings: 5
  - partridges:
  - count: 1
  - location: "a pear tree"
  - turtle-doves: two
  - '
  - publicar 'https://pokeapi.co/api/v2/pokemon/ditto'


## Análisis Semántico

- **Análisis sintáctico:**
    

- **Ejemplos:**

## Pruebas y Validación

- **Metodología de pruebas:**
- **Resultados obtenidos:**
- **Casos de prueba específicos:**

## Herramientas y Entorno de Desarrollo
- **Lenguajes de programación utilizados:** Python
- **Herramientas de desarrollo:** GitHub
- **Entorno de pruebas y simulación:**
- **Otras herramientas:** Draw.io, Google Docs

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
  - PSEInt. (s. f.). *PSEInt*. https://pseint.sourceforge.net/
  - PseudoEditor. (s. f.). *Pseudocode Editor online - PseudoEditor*. https://pseudoeditor.com/
  - Scratch. (s. f.). *Scratch - FAQ*. https://scratch.mit.edu/faq

