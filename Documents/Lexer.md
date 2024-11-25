## Análisis Léxico
- **Análisis léxico:**
  [Tabla NFA a DFA](https://docs.google.com/spreadsheets/d/1d-Ae-Xse4y_mCXiTdAH2pxOPNWBGBultBXIrC_2EEV8/edit?usp=sharing)

![Automata](/resources/analizador_Lexico.jpg)
- Tokenización, identificación de palabras clave, operadores, etc.
    - Identificador: ```[a-z|_][a-z|_]*```
    - Constante: ```[+|-]?\d+```
    - Keyword: ```(si|variable|entonces|sino|finsi|publicar|obtener|cambiar|borrar)```
    - Whitespace: ```[\t\r\f\v]+```
    - Puntuacion: ```[\n| |"|(|)|,|#|'|:]```
    - Operadores: ```[+|-|=|*|/|==| || |&&|<|>|!|?]```
- **Ejemplos:**
- a -> Identificador
- +98 -> Constante
- variable -> Keyword
- ' -> Puntuacion
- \t -> Whitespace
- || -> Operador

![Ejemplo de éxito](/resources/lexerCorrect.jpg)