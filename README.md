# GDint

## Resumen
- GDint es un compilador que busca cerrar la brecha entre la lengua natural y los lenguajes de programación. GDint busca facilitar el proceso de aprendizaje para jóvenes que tienen interés en la programación y no saben por dónde empezar. 

## Motivación y Problema a Resolver
- **Descripción del problema: Los lenguajes de programación actuales no son muy intuitivos a la hora de empezar a aprender. Muchos lenguajes son muy técnicos y es necesario la lectura de manual para saber por dónde empezar. **
- **Importancia: Debido a la interpretación que comúnmente se le da a la programación, muchos jóvenes tienen miedo a empezar con la programación porque tienen la creencia de que la programación es difícil. Con herramientas que sean capaces de convertir pseudocódigo a código, pueden aprender cómo funciona un lenguaje de programación ya que tendrán puntos de comparación.**
- **Casos de uso:El mayor caso de uso para nuestro compilador es para el aprendizaje. Otros casos de uso serían para usos más generales, hay casos en donde es necesario un script sencillo en python, pero sin el conocimiento básico es imposible hacerlo. Tener un lenguaje que pueda resolver estos problemas sin conocimiento haría que el flujo de trabajo sea más sencillo. Al mismo tiempo GDint sería capaz de operar con APIs públicas y tener la capacidad de hacer uso de los métodos verbos de HTML**

## Objetivos del Proyecto
- **Objetivo 1: Ser una herramienta central para la enseñanza de jóvenes interesados en la programación. **
- **Objetivo 2: Hacer la programación más interactivas, actualmente es muy difícil de enseñar a jóvenes como los diagramas y pseudocódigo son traducidos a código.**
- **Objetivo 3: Simplificar la programación para tareas más sencillas sin la necesidad de conocimiento profundos de la programación. **
- **Objetivo 4: Simplificar las llamadas de API públicas para que todos sean capaces de hacer cambios simples a un API.** 

## Revisión del Estado del Arte
- **Compiladores similares:** PSeInt (PSEInt, s. f.), Scratch (Scratch, s. f.), Pseudocode Online Editor (PseudoEditor, s. f.)
- **Limitaciones de soluciones actuales:** Todos esos compiladores están limitados a un entorno virtual, por lo que no tiene acceso a archivos locales ni puede realizar llamadas a API. Los lenguajes pseudocódigos están limitados a un área, que es la enseñanza de programación básica.
- **Justificación del nuevo compilador:** El compilador se creará para plantear una propuesta de lenguaje pseudocódigo más cercano al lenguaje natural. Además, el nuevo compilador ofrecerá una manera en la que el programador realice llamadas a API y leer archivos, expandiendo su potencial para ofrecer un acercamiento a las tecnologías web y programas con acceso al sistema de archivos. Otro punto a destacar es que la potencia añadida del compilador

## Arquitectura y Diseño del Compilador
- **Diagrama de bloques:**

- **Explicación del flujo de datos:** El compilador recibe un flujo de caracteres en el formato GDint, pasa por los análisis léxico, sintáctico y semántico para crear un flujo de tokens y árboles sintácticos para crear la tabla de símbolos, la cual, es usada para generar código intermedio que es optimizado para producir código en el lenguaje de programación de python. Al final, el código generado es optimizado y se entrega como la salida del compilador.
- **Decisiones de diseño:** Se utiliza la arquitectura típica de un compilador, solo que se especifica que el flujo de caracteres es pseudocódigo GDint y la salida es código python en vez de código máquina.

## Análisis Léxico
- **Análisis léxico:**
  - Tokenización, identificación de palabras clave, operadores, etc.
Identificador: [a-z|A-Z][\w\S]*
integer: \d+
keyword: (Inicio|Imprimir|variable|constante|Leer,|Si|Entonces|Sino|FinSi|LeerArchivo|Consultar)
whitespace: \s+
- **Ejemplos:**

## Análisis Sintáctico

- **Análisis sintáctico:**
  - Uso de gramáticas y árboles sintácticos.

- **Ejemplos:**

## Análisis Semántico

- **Análisis sintáctico:**
  - Uso de gramáticas y árboles sintácticos.

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
PSEInt. (s. f.). PSEInt. https://pseint.sourceforge.net/
PseudoEditor. (s. f.). Pseudocode Editor online - PseudoEditor. https://pseudoeditor.com/
Scratch. (s. f.). Scratch - FAQ. https://scratch.mit.edu/faq

