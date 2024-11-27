## Análisis Léxico
- **Análisis léxico:**
  [Tabla NFA a DFA](https://docs.google.com/spreadsheets/d/1d-Ae-Xse4y_mCXiTdAH2pxOPNWBGBultBXIrC_2EEV8/edit?usp=sharing)

![Automata](/resources/analizador_Lexico.jpg)
- Tokenización, identificación de palabras clave, operadores, etc.
    - Identificador: ```[a-z|_][a-z|_]*```
    - Constante: ```[+|-]?\d+```
    - Keyword: ```(si|variable|entonces|sino|finsi|publicar|obtener|cambiar|borrar)```
    - Whitespace: ```[\t\r\f\v]+```
    - Puntuación: ```[\n| |"|(|)|,|#|'|:|.]```
    - Operadores: ```[+|-|=|*|/|==| || |&&|<|>|!|?]```
### **Ejemplos:**
- a -> Identificador `Token(name: a, type: Identifier, line: 1)`
- +98 -> Constante `Token(name: a, type: Identifier, line: 1)`
- variable -> Keyword `Token(name: a, type: Identifier, line: 1)`
- ' -> Puntuación `Token(name: ', type: Punctuation, line: 1)`
- \t -> Whitespace ` ` (Eliminado en el preprocesado)
- || -> Operador `Token(name: ||, type: Operation, line: 1)`
- \` -> Error `Error lexico: cadena no reconocida por el automata en la linea: 1.`

![Ejemplo de éxito](/resources/lexerCorrect.jpg)

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
[Salida](Test/LexerValid.md)
