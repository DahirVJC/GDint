# GDint

## Resumen
- GDint es un compilador que busca cerrar la brecha entre la lengua natural y los lenguajes de programación.
GDint busca facilitar el proceso de aprendizaje para jóvenes que tienen interés en la programación y no saben por dónde empezar.
El enfoque principal del lenguaje compilado es el de manejo de llamadas a APIs, sirviendo como acercamiento a tecnologías web.

## Motivación y Problema a Resolver
- **Descripción del problema:** Los lenguajes de programación actuales no son muy intuitivos a la hora de empezar a aprender. Muchos lenguajes son muy técnicos y es necesario la lectura de manual para saber por dónde empezar.
- **Importancia:** Debido a la interpretación que comúnmente se le da a la programación, muchos jóvenes tienen miedo a empezar con la programación porque tienen la creencia de que la programación es difícil. Con herramientas que sean capaces de convertir pseudocódigo a código, pueden aprender cómo funciona un lenguaje de programación ya que tendrán puntos de comparación.
- **Casos de uso:** El mayor caso de uso para nuestro compilador es para el aprendizaje. Otros casos de uso serían para usos más generales, hay casos en donde es necesario un script sencillo en python, pero sin el conocimiento básico es imposible hacerlo. Tener un lenguaje que pueda resolver estos problemas sin conocimiento haría que el flujo de trabajo sea más sencillo. Al mismo tiempo GDint sería capaz de operar con APIs públicas y tener la capacidad de hacer uso de los métodos o verbos de HTTP.

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
  - Python es el lenguaje a donde se va a traducir.
  - C++ es el lenguaje de implementación.
  - 64 bits  es la arquitectura de las máquinas en las que se va a ejecutar.
- **Explicación del flujo de datos:** El compilador recibe un flujo de caracteres en el formato GDint, pasa por los análisis léxico, sintáctico y semántico para crear un flujo de tokens y árboles sintácticos para crear la tabla de símbolos, la cual, es usada para generar código intermedio que es optimizado para producir código en el lenguaje de programación de python. Al final, el código generado es optimizado y se entrega como la salida del compilador.
- **Decisiones de diseño:** Se utiliza la arquitectura típica de un compilador, solo que se especifica que el flujo de caracteres es pseudocódigo GDint y la salida es código python en vez de código máquina. Se elige la arquitectura de 64 bits porque es la correspondiente a las máquinas que se utilizan para desarrollar y ejecutar el compilador. Las pruebas y adaptación del compilador a máquinas de 32 bits, ARM u otras arquitecturas queda fuera del alcance del proyecto.

## Análisis Léxico
[Análisis Léxico](Documents/Lexer.md)

## Análisis Sintáctico
[Análisis Sintáctico](Documents/Parser.md)

## Análisis Semántico
[Análisis Semántico](Documents/Semantics.md)

## Pruebas y Validación

- **Metodología de pruebas:**
  - Primero se planteaba un paso específico a probar.
  - Después, se creaba un código GDInt que plasmaba ese caso.
  - Una vez que se tenía el código, se escribía en el archivo de entrada del compilador.
  - Por último, el compilador se ejecutaba con esa entrada y se analizaba la salida.
  - Adicionalmente y en el caso de las pruebas más importantes, se guardaba la entrada y salida, y se documentaba.
  
  Para obtener información detallada sobre el proceso de compilación, el archivo [Input/Config.txt](Input/Config.txt) puede ser modificado para mostrar el log.

  `LOG=FALSE` oculta la información mientras que `LOG=TRUE` muestra detalles del proceso de ejecución y productos intermedios en consola.
- **Resultados obtenidos:**
  - [Lexer](Documents/Test/LexerValid.md)
  - [Parser](Documents/Test/ParserValid.md)
  - [Semantics](Documents/Test/SemanticsValid.md)
  - [Compilador](Documents/Test/Output.md)
- **Casos de prueba específicos:** se realizaron pruebas en cada etapa del compilador, tanto pruebas de validez como pruebas de errores.
  - Estas pruebas pueden encontrarse en:
    - [Pruebas léxicas](Documents/Lexer.md#ejemplos)
    - [Pruebas sintácticas](Documents/Parser.md#ejemplos)
    - [Pruebas semánticas](Documents/Semantics.md#ejemplos)

## Herramientas y Entorno de Desarrollo
- **Lenguajes de programación utilizados:** C++ y Python
- **Herramientas de desarrollo:** Git, GitHub y CLion
- **Entorno de pruebas y simulación:** Pruebas en CLion en los sistemas operativos Windows 10, Windows 11 y EndeavourOS
- **Otras herramientas:** Draw.io, Google Docs, Google Sheets, JFlap, ChatGPT y Claude

## Demostración
- **Ejemplo de código fuente:**
````
variable a = 0
a = 2 + 3
variable b = 5*a + (0*2 + 4)
variable c = 'c' + 'd'
variable body = 'holaaa' + '4' + c
variable url = 'https://pokeapi.co/api/v2/pokemon/ditto'
obtener url body
publicar url body
#'Intenta: variable id = 1'
variable id = 'alumno1'
cambiar url 3 body body
borrar url 3 body
si a<10||a==-3 entonces
    id = 'pokemon2'
    si id=='pokemon' entonces
        id = 'si'
    finsi
    cambiar 'https://pokeapi.co/api/v2/pokemon/ditto' id body
sino
    id = 'pokemon3'
    cambiar 'https://pokeapi.co/api/v2/pokemon/incineroar' id body
finsi
````
Salida: `Codigo compilado exitosamente.`

- **Proceso de compilación:**
  - El programa lee del archivo fuente el código a compilar y se le aplica un preprocesamiento que adapta los caracteres, ya sea removiendo, modificando o manteniendo estos símbolos.
  - El código leído es pasado al Lexer, el cual, con ayuda de la tabla de transición de un autómata, agrupa los caracteres y los clasifica, creando así un flujo de tokens.
  - La serie de tokens generada por el Lexer es transferida al Parser, en donde se utiliza un algoritmo LL(1) que hace uso de las reglas gramaticales guardadas en un archivo de texto. El parser valida la sintaxis del código en forma de tokens y genera un árbol Parse, al mismo tiempo que se introducen los identificadores a una tabla de símbolos, donde se guarda su información como token y otros datos importantes.
  - Por último, el árbol Parse, junto con la tabla de valores, sirven como entrada al analizador semántico, el cual convierte dicho árbol en un árbol de sintaxis abstracta, cuyos nodos tienen los métodos para validarse y resolverse (resolver es el proceso de decorar o anotar árbol, resolver valores y actualizar la tabla de símbolos, y optimizarlo). Primero, es árbol se valida para detectar errores semánticos y se resuelve para devolver un árbol de sintaxis abstracta anotado. Al final de este análisis se tiene como producto un árbol de sintaxis abstracta decorado y una tabla de símbolos que contiene más datos que la tabla de la fase sintáctica.
- **Ejecución del código compilado:** [salida en consola](Documents/Test/Output.md)

## Desafíos y Soluciones
[Bitácora](Documents/Bitacora.md)
- **Problemas técnicos o de diseño:**
  - Se crearon los analizadores sin tener en cuenta los pasos futuros. Esto causó imprevistos en la creación de analizadores en el posterior.
  - En el proceso de la creación de la gramática para el analizador semántico tuvimos problemas con crear una gramática que hiciera lo que visionamos.
  - La tokenización de espacios y saltos de línea de los lenguajes tipo pseudocódigo resultó desafiante.
- **Estrategias adoptadas para superar desafíos:**
  - Aunque varios problemas relacionados a las salidas de los analizadores anteriores se resolvieron al editarlos, en bastantes ocasiones la estrategia principal fue crear los analizadores actuales de manera que puedan manejar esos inconvenientes.
  - La estrategia de prueba y error fue utilizada para las correcciones de las reglas sintácticas, ya que el análisis de casos particulares resulta muy complejo.
  - Para la tokenización de espacios en blanco necesarios para el lenguaje, se decidió usar el preprocesador para limpiar algunos espacios fácilmente detectables, sin embargo, al ser símbolos sintácticos, la mayor parte de su manejo se hizo en el parser.
- **Lecciones aprendidas:** durante la resolución de estos problemas, y en general en la elaboración del compilador, aprendimos la importancia de entender completamente el funcionamiento de todo un sistema para poder crear módulos con salidas oportunas. Aunque se busca que el desarrollo de software se realice con módulos independientes entre sí, es cierto que se tienen que tomar en cuenta la entrada y salida de cada componente para su correcta implementación. Por lo tanto, en futuros proyectos, se tomará en cuenta y se le dará gran importancia al análisis de lo que recibe y sale de cada componente de un sistema.

## Conclusiones y Trabajo Futuro
- **Resumen de objetivos cumplidos:** se elaboró un compilador capaz de analizar un lenguaje de tipo pseudocódigo que soporta métodos HTTP.  Con el objetivo de ser una herramienta de educación.
- **Evaluación del desempeño:**
las múltiples pruebas realizadas apuntan que el compilador tiene la capacidad de manejar llamadas a endpoints dado un verbo HTTP, y manejar lógica básica y condicional.
Una vez se agregue un módulo de generar código python, los objetivos del compilador se pueden satisfacer.
- **Propuestas para mejoras futuras:**
  el compilador puede mejorar bastante con más tiempo, no solo de cómo está estructurado el código, si no que también en características que soporta.
  - El lenguaje no soporta declaraciones en condicionales por cómo se maneja la declaración de variables en el analizador sintáctico.
  - Tampoco soporta operaciones entre diferentes tipos de datos.
  - Otra característica que se puede soportar es un manejo de tokens de espacio y salto de línea más adecuado y flexible para el usuario.
  - Por otra parte, el sistema de comentarios también puede ser mejorado, haciendo que este sea más flexible e intuitivo, permitiendo usar caracteres como ' y ser planteado de una forma que no sea intrusivo con los símbolos sintácticos del lenguaje.
  - También, se puede añadir el soporte de strings vacíos y validaciones que se pueden hacer con ellos. Actualmente, no permitir strings vacíos son la validación de no tener URLs vacías o cuerpos vacíos.
  - Otra oportunidad es extender el manejo de las API y los objetos que se obtienen, ofreciendo una mayor interacción con las tecnologías web.
  - Por último, el compilador solo realiza la parte del FrontEnd, por lo que agregar el BackEnd sería oportuno.

  En el futuro, estas características se pudieran implementar para hacer este compilador un mejor software.

## Preguntas y Discusión
- Espacio para responder preguntas y discusión sobre el proyecto.

## Referencias
- **Fuentes citadas:** Lista de libros, artículos, papers, y otras fuentes relevantes.
  - Aho, A., Lam, M., Sethi, R., y Ullman, J. (2007). *Compilers: Principles, Techniques, & Tools* (2.a ed.). Pearson.
  - Anthropic. (2024). *Claude* (Claude 3.5 Sonnet) [Modelo de lenguaje de gran tamaño]. https://claude.ai/
  - Anuragvbj79. (2024). *How to Extract a Subvector from a Vector in C++?* GeeksforGeeks. https://www.geeksforgeeks.org/how-to-extract-a-subvector-from-a-vector-in-cpp/
  - Ling, J. (2024). *John-Ling/Pseudocode-Compiler: Basic compiler that turns pseudocode into Python.* GitHub. https://github.com/John-Ling/Pseudocode-Compiler
  - Neso Academy. (2023). *LL(1) Parsing* [Vídeo]. YouTube. https://www.youtube.com/watch?v=clkHOgZUGWU
  - OpenAI. (2024). *ChatGPT* (GPT-4o) [Modelo de lenguaje de gran tamaño]. https://chat.openai.com/chat
  - OpenAI. (2024). *ChatGPT* (GPT-4o mini) [Modelo de lenguaje de gran tamaño]. https://chat.openai.com/chat
  - PSEInt. (s. f.). *PSEInt*. https://pseint.sourceforge.net/
  - PseudoEditor. (s. f.). *Pseudocode Editor online - PseudoEditor*. https://pseudoeditor.com/
  - Riteshjha0002. (2023). *Split String by Space into Vector in C++ STL.* GeeksforGeeks. https://www.geeksforgeeks.org/split-string-by-space-into-vector-in-cpp-stl/
  - Scratch. (s. f.). *Scratch - FAQ*. https://scratch.mit.edu/faq
  - UseTheSource. (s. f.). *Abstract Syntax Tree | The Rascal Meta Programming Language.* The Rascal Meta Programming Language. https://www.rascal-mpl.org/docs/Rascalopedia/AbstractSyntaxTree/
