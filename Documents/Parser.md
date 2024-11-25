## Análisis Sintáctico
- **Análisis sintáctico:**

[Bosquejo de análisis sintáctico](Res/Bosquejo.pdf)
  
- **Nota**: Por cuestiones de implementación, " " se escribe como space en las reglas, y \n como salto únicamente en el archivo de gramática (LL1Grammar.txt), al igual que || se escribe como or en dicho archivo, esto para ser interpretado correctamente por el lector de gramática.
- **Gramatica:**
  - [LL1Grammar.txt](../Input/LL1Grammar.txt)
    - CODIGO->BLOQUE CODIGO'
    - CODIGO'->BLOQUE CODIGO'|ε
    - BLOQUE->INSTRUCCION BLOQUE'
    - BLOQUE'->salto INSTRUCCION BLOQUE'|ε
    - ANIDADO->INSTBLOQ salto ANIDADO'
    - ANIDADO'->INSTBLOQ salto ANIDADO'|ε
    - INSTBLOQ->ASIGNACION|OBTENER|PUBLICAR|CAMBIAR|BORRAR|COMENTARIO|CONDICIONAL
    - INSTRUCCION->DECLARACION|ASIGNACION|OBTENER|PUBLICAR|CAMBIAR|BORRAR|COMENTARIO|CONDICIONAL|SALTO
    - CONDICIONAL->si ESPACIO CONDICION ESPACIO entonces salto ANIDADO SINO finsi
    - SINO->sino salto ANIDADO|ε
    - CONDICION->COMPARACION CONDICION'
    - CONDICION'->&& COMPARACION CONDICION'|or COMPARACION CONDICION'|ε
    - COMPARACION->BOOL COMPARACION'
    - COMPARACION'->== BOOL COMPARACION'|< BOOL COMPARACION'|> BOOL COMPARACION'|ε
    - BOOL->identificador|constante|STRING
    - COMENTARIO-># STRING
    - OBTENER->obtener ESPACIO STRPARAM ESPACIO APIKEY
    - PUBLICAR->publicar ESPACIO STRPARAM ESPACIO STRPARAM ESPACIO APIKEY
    - CAMBIAR->cambiar ESPACIO STRPARAM ESPACIO DATO ESPACIO STRPARAM ESPACIO APIKEY
    - BORRAR->borrar ESPACIO STRPARAM ESPACIO DATO ESPACIO APIKEY
    - APIKEY->STRPARAM|ε
    - STRPARAM->STRING|identificador
    - DECLARACION->variable ESPACIO identificador ESPACIO = ESPACIO EXP
    - ASIGNACION->identificador ESPACIO = ESPACIO EXP
    - EXP->TERM EXP'
    - EXP'->ESPACIO OPSIMP ESPACIO TERM EXP'|ε
    - OPSIMP->+|-
    - TERM->FACTOR TERM'
    - TERM'->* FACTOR TERM'|/ FACTOR TERM'|ε
    - FACTOR->identificador|constante|STRING|( EXP )
    - ESPACIO->space ESPACIO|ε
    - SALTO->salto SALTO|ε
    - DATO->constante|STRING|identificador
    - STRING->' CADENA '
    - CADENA->∈Σ-' CADENA'
    - CADENA'->∈Σ-' CADENA'|ε
- **Análisis first:**
  - CODIGO=variable identificador obtener publicar cambiar borrar # si \n ε
  - CODIGO'=variable identificador obtener publicar cambiar borrar # si \n ε ε
  - BLOQUE=variable identificador obtener publicar cambiar borrar # si \n ε
  - BLOQUE'=\n ε
  - ANIDADO=identificador obtener publicar cambiar borrar # si
  - ANIDADO'=identificador obtener publicar cambiar borrar # si ε
  - INSTBLOQ=identificador obtener publicar cambiar borrar # si
  - INSTRUCCION=variable identificador obtener publicar cambiar borrar # si \n ε
  - CONDICIONAL=si
  - SINO=sino ε
  - CONDICION=identificador constante '
  - CONDICION'=&& || ε
  - COMPARACION=identificador constante '
  - COMPARACION'=== < > ε
  - BOOL=identificador constante '
  - COMENTARIO=#
  - OBTENER=obtener
  - PUBLICAR=publicar
  - CAMBIAR=cambiar
  - BORRAR=borrar
  - APIKEY=' identificador ε
  - STRPARAM=' identificador
  - DECLARACION=variable
  - ASIGNACION=identificador
  - EXP=identificador constante ' (
  - EXP'=space ε ε
  - OPSIMP=+ -
  - TERM=identificador constante ' (
  - TERM'=* / ε
  - FACTOR=identificador constante ' (
  - ESPACIO=space ε
  - SALTO=\n ε
  - DATO=constante ' identificador
  - STRING='
  - CADENA=∈Σ-'
  - CADENA'=∈Σ-' ε
- **Análisis Follow:**
  - CODIGO = EOF
  - CODIGO' = EOF
  - BLOQUE = \n # EOF borrar cambiar identificador obtener publicar si variable
  - BLOQUE' = \n # EOF borrar cambiar identificador obtener publicar si variable
  - ANIDADO = \n # EOF borrar cambiar finsi identificador obtener publicar si sino variable
  - ANIDADO' = \n # EOF borrar cambiar finsi identificador obtener publicar si sino variable
  - INSTBLOQ = \n
  - INSTRUCCION = \n # EOF borrar cambiar identificador obtener publicar si variable
  - CONDICIONAL = \n # EOF borrar cambiar identificador obtener publicar si variable
  - SINO = finsi
  - CONDICION = \n space # EOF borrar cambiar identificador obtener publicar si variable
  - CONDICION' = \n space # EOF borrar cambiar identificador obtener publicar si variable
  - COMPARACION = \n space # && EOF borrar cambiar identificador obtener publicar si variable ||
  - COMPARACION' = \n space # && EOF borrar cambiar identificador obtener publicar si variable ||
  - BOOL = \n space # && < == > EOF borrar cambiar identificador obtener publicar si variable ||
  - COMENTARIO = \n # EOF borrar cambiar identificador obtener publicar si variable
  - OBTENER = \n # EOF borrar cambiar identificador obtener publicar si variable
  - PUBLICAR = \n # EOF borrar cambiar identificador obtener publicar si variable
  - CAMBIAR = \n # EOF borrar cambiar identificador obtener publicar si variable
  - BORRAR = \n # EOF borrar cambiar identificador obtener publicar si variable
  - APIKEY = \n # EOF borrar cambiar identificador obtener publicar si variable
  - STRPARAM = \n space # EOF borrar cambiar identificador obtener publicar si variable
  - DECLARACION = \n # EOF borrar cambiar identificador obtener publicar si variable
  - ASIGNACION = \n # EOF borrar cambiar identificador obtener publicar si variable
  - EXP = \n # ) EOF borrar cambiar identificador obtener publicar si variable
  - EXP' = \n # ) EOF borrar cambiar identificador obtener publicar si variable
  - OPSIMP = \n space # ) EOF borrar cambiar identificador obtener publicar si variable
  - TERM = \n space # ) EOF borrar cambiar identificador obtener publicar si variable
  - TERM' = \n space # ) EOF borrar cambiar identificador obtener publicar si variable
  - FACTOR = \n space # ) * / EOF borrar cambiar identificador obtener publicar si variable
  - ESPACIO = \n # ' ( + - = EOF borrar cambiar constante entonces identificador obtener publicar si variable
  - SALTO = \n # EOF borrar cambiar identificador obtener publicar si variable
  - DATO = \n space # EOF borrar cambiar identificador obtener publicar si variable
  - STRING = \n space # && ) * / < == > EOF borrar cambiar identificador obtener publicar si variable ||
  - CADENA = '
  - CADENA' = '
- **Reglas de parseo (Parsing Table):**
    - [Tabla de parseo](https://docs.google.com/spreadsheets/d/1QxdhRR3tCjMBeSxMir3cwsD7_051wFhnC_6Y7lOdV9g/edit?usp=sharing)
    - En \<ANIDADO> dado [#] produce: INSTBLOQ \n ANIDADO'
    - En \<ANIDADO> dado [borrar] produce: INSTBLOQ \n ANIDADO'
    - En \<ANIDADO> dado [cambiar] produce: INSTBLOQ \n ANIDADO'
    - En \<ANIDADO> dado [identificador] produce: INSTBLOQ \n ANIDADO'
    - En \<ANIDADO> dado [obtener] produce: INSTBLOQ \n ANIDADO'
    - En \<ANIDADO> dado [publicar] produce: INSTBLOQ \n ANIDADO'
    - En \<ANIDADO> dado [si] produce: INSTBLOQ \n ANIDADO'
    - En \<ANIDADO'> dado [\n] produce: ε
    - En \<ANIDADO'> dado [#] produce: INSTBLOQ \n ANIDADO'
    - En \<ANIDADO'> dado [EOF] produce: ε
    - En \<ANIDADO'> dado [borrar] produce: INSTBLOQ \n ANIDADO'
    - En \<ANIDADO'> dado [cambiar] produce: INSTBLOQ \n ANIDADO'
    - En \<ANIDADO'> dado [finsi] produce: ε
    - En \<ANIDADO'> dado [identificador] produce: INSTBLOQ \n ANIDADO'
    - En \<ANIDADO'> dado [obtener] produce: INSTBLOQ \n ANIDADO'
    - En \<ANIDADO'> dado [publicar] produce: INSTBLOQ \n ANIDADO'
    - En \<ANIDADO'> dado [si] produce: INSTBLOQ \n ANIDADO'
    - En \<ANIDADO'> dado [sino] produce: ε
    - En \<ANIDADO'> dado [variable] produce: ε
    - En \<ANIDADO'> dado [ε] produce: ε
    - En \<APIKEY> dado [\n] produce: ε
    - En \<APIKEY> dado [#] produce: ε
    - En \<APIKEY> dado ['] produce: STRPARAM
    - En \<APIKEY> dado [EOF] produce: ε
    - En \<APIKEY> dado [borrar] produce: ε
    - En \<APIKEY> dado [cambiar] produce: ε
    - En \<APIKEY> dado [identificador] produce: STRPARAM
    - En \<APIKEY> dado [obtener] produce: ε
    - En \<APIKEY> dado [publicar] produce: ε
    - En \<APIKEY> dado [si] produce: ε
    - En \<APIKEY> dado [variable] produce: ε
    - En \<APIKEY> dado [ε] produce: ε
    - En \<ASIGNACION> dado [identificador] produce: identificador ESPACIO = ESPACIO EXP
    - En \<BLOQUE> dado [\n] produce: INSTRUCCION BLOQUE'
    - En \<BLOQUE> dado [#] produce: INSTRUCCION BLOQUE'
    - En \<BLOQUE> dado [borrar] produce: INSTRUCCION BLOQUE'
    - En \<BLOQUE> dado [cambiar] produce: INSTRUCCION BLOQUE'
    - En \<BLOQUE> dado [identificador] produce: INSTRUCCION BLOQUE'
    - En \<BLOQUE> dado [obtener] produce: INSTRUCCION BLOQUE'
    - En \<BLOQUE> dado [publicar] produce: INSTRUCCION BLOQUE'
    - En \<BLOQUE> dado [si] produce: INSTRUCCION BLOQUE'
    - En \<BLOQUE> dado [variable] produce: INSTRUCCION BLOQUE'
    - En \<BLOQUE> dado [ε] produce: INSTRUCCION BLOQUE'
    - En \<BLOQUE'> dado [\n] produce: \n INSTRUCCION BLOQUE'
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
    - En \<BOOL> dado ['] produce: STRING
    - En \<BOOL> dado [constante] produce: constante
    - En \<BOOL> dado [identificador] produce: identificador
    - En \<BORRAR> dado [borrar] produce: borrar ESPACIO STRPARAM ESPACIO DATO ESPACIO APIKEY
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
    - En \<CAMBIAR> dado [cambiar] produce: cambiar ESPACIO STRPARAM ESPACIO DATO ESPACIO STRPARAM ESPACIO APIKEY
    - En \<CODIGO> dado [\n] produce: BLOQUE CODIGO'
    - En \<CODIGO> dado [#] produce: BLOQUE CODIGO'
    - En \<CODIGO> dado [borrar] produce: BLOQUE CODIGO'
    - En \<CODIGO> dado [cambiar] produce: BLOQUE CODIGO'
    - En \<CODIGO> dado [identificador] produce: BLOQUE CODIGO'
    - En \<CODIGO> dado [obtener] produce: BLOQUE CODIGO'
    - En \<CODIGO> dado [publicar] produce: BLOQUE CODIGO'
    - En \<CODIGO> dado [si] produce: BLOQUE CODIGO'
    - En \<CODIGO> dado [variable] produce: BLOQUE CODIGO'
    - En \<CODIGO> dado [ε] produce: BLOQUE CODIGO'
    - En \<CODIGO'> dado [\n] produce: BLOQUE CODIGO'
    - En \<CODIGO'> dado [#] produce: BLOQUE CODIGO'
    - En \<CODIGO'> dado [EOF] produce: ε
    - En \<CODIGO'> dado [borrar] produce: BLOQUE CODIGO'
    - En \<CODIGO'> dado [cambiar] produce: BLOQUE CODIGO'
    - En \<CODIGO'> dado [identificador] produce: BLOQUE CODIGO'
    - En \<CODIGO'> dado [obtener] produce: BLOQUE CODIGO'
    - En \<CODIGO'> dado [publicar] produce: BLOQUE CODIGO'
    - En \<CODIGO'> dado [si] produce: BLOQUE CODIGO'
    - En \<CODIGO'> dado [variable] produce: BLOQUE CODIGO'
    - En \<CODIGO'> dado [ε] produce: BLOQUE CODIGO'
    - En \<COMENTARIO> dado [#] produce: # STRING
    - En \<COMPARACION> dado ['] produce: BOOL COMPARACION'
    - En \<COMPARACION> dado [constante] produce: BOOL COMPARACION'
    - En \<COMPARACION> dado [identificador] produce: BOOL COMPARACION'
    - En \<COMPARACION'> dado [\n] produce: ε
    - En \<COMPARACION'> dado [space] produce: ε
    - En \<COMPARACION'> dado [#] produce: ε
    - En \<COMPARACION'> dado [&&] produce: ε
    - En \<COMPARACION'> dado [<] produce: < BOOL COMPARACION'
    - En \<COMPARACION'> dado [==] produce: == BOOL COMPARACION'
    - En \<COMPARACION'> dado [>] produce: > BOOL COMPARACION'
    - En \<COMPARACION'> dado [EOF] produce: ε
    - En \<COMPARACION'> dado [borrar] produce: ε
    - En \<COMPARACION'> dado [cambiar] produce: ε
    - En \<COMPARACION'> dado [identificador] produce: ε
    - En \<COMPARACION'> dado [obtener] produce: ε
    - En \<COMPARACION'> dado [publicar] produce: ε
    - En \<COMPARACION'> dado [si] produce: ε
    - En \<COMPARACION'> dado [variable] produce: ε
    - En \<COMPARACION'> dado [||] produce: ε
    - En \<COMPARACION'> dado [ε] produce: ε
    - En \<CONDICION> dado ['] produce: COMPARACION CONDICION'
    - En \<CONDICION> dado [constante] produce: COMPARACION CONDICION'
    - En \<CONDICION> dado [identificador] produce: COMPARACION CONDICION'
    - En \<CONDICION'> dado [\n] produce: ε
    - En \<CONDICION'> dado [space] produce: ε
    - En \<CONDICION'> dado [#] produce: ε
    - En \<CONDICION'> dado [&&] produce: && COMPARACION CONDICION'
    - En \<CONDICION'> dado [EOF] produce: ε
    - En \<CONDICION'> dado [borrar] produce: ε
    - En \<CONDICION'> dado [cambiar] produce: ε
    - En \<CONDICION'> dado [identificador] produce: ε
    - En \<CONDICION'> dado [obtener] produce: ε
    - En \<CONDICION'> dado [publicar] produce: ε
    - En \<CONDICION'> dado [si] produce: ε
    - En \<CONDICION'> dado [variable] produce: ε
    - En \<CONDICION'> dado [||] produce: || COMPARACION CONDICION'
    - En \<CONDICION'> dado [ε] produce: ε
    - En \<CONDICIONAL> dado [si] produce: si ESPACIO CONDICION ESPACIO entonces \n ANIDADO SINO finsi
    - En \<DATO> dado ['] produce: STRING
    - En \<DATO> dado [constante] produce: constante
    - En \<DATO> dado [identificador] produce: identificador
    - En \<DECLARACION> dado [variable] produce: variable ESPACIO identificador ESPACIO = ESPACIO EXP
    - En \<ESPACIO> dado [\n] produce: ε
    - En \<ESPACIO> dado [space] produce: space ESPACIO
    - En \<ESPACIO> dado [#] produce: ε
    - En \<ESPACIO> dado ['] produce: ε
    - En \<ESPACIO> dado [(] produce: ε
    - En \<ESPACIO> dado [+] produce: ε
    - En \<ESPACIO> dado [-] produce: ε
    - En \<ESPACIO> dado [=] produce: ε
    - En \<ESPACIO> dado [EOF] produce: ε
    - En \<ESPACIO> dado [borrar] produce: ε
    - En \<ESPACIO> dado [cambiar] produce: ε
    - En \<ESPACIO> dado [constante] produce: ε
    - En \<ESPACIO> dado [entonces] produce: ε
    - En \<ESPACIO> dado [identificador] produce: ε
    - En \<ESPACIO> dado [obtener] produce: ε
    - En \<ESPACIO> dado [publicar] produce: ε
    - En \<ESPACIO> dado [si] produce: ε
    - En \<ESPACIO> dado [variable] produce: ε
    - En \<ESPACIO> dado [ε] produce: ε
    - En \<EXP> dado ['] produce: TERM EXP'
    - En \<EXP> dado [(] produce: TERM EXP'
    - En \<EXP> dado [constante] produce: TERM EXP'
    - En \<EXP> dado [identificador] produce: TERM EXP'
    - En \<EXP'> dado [\n] produce: ε
    - En \<EXP'> dado [space] produce: ESPACIO OPSIMP ESPACIO TERM EXP'
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
    - En \<EXP'> dado [ε] produce: ESPACIO OPSIMP ESPACIO TERM EXP'
    - En \<FACTOR> dado ['] produce: STRING
    - En \<FACTOR> dado [(] produce: ( EXP )
    - En \<FACTOR> dado [constante] produce: constante
    - En \<FACTOR> dado [identificador] produce: identificador
    - En \<INSTBLOQ> dado [#] produce: COMENTARIO
    - En \<INSTBLOQ> dado [borrar] produce: BORRAR
    - En \<INSTBLOQ> dado [cambiar] produce: CAMBIAR
    - En \<INSTBLOQ> dado [identificador] produce: ASIGNACION
    - En \<INSTBLOQ> dado [obtener] produce: OBTENER
    - En \<INSTBLOQ> dado [publicar] produce: PUBLICAR
    - En \<INSTBLOQ> dado [si] produce: CONDICIONAL
    - En \<INSTRUCCION> dado [\n] produce: SALTO
    - En \<INSTRUCCION> dado [#] produce: COMENTARIO
    - En \<INSTRUCCION> dado [borrar] produce: BORRAR
    - En \<INSTRUCCION> dado [cambiar] produce: CAMBIAR
    - En \<INSTRUCCION> dado [identificador] produce: ASIGNACION
    - En \<INSTRUCCION> dado [obtener] produce: OBTENER
    - En \<INSTRUCCION> dado [publicar] produce: PUBLICAR
    - En \<INSTRUCCION> dado [si] produce: CONDICIONAL
    - En \<INSTRUCCION> dado [variable] produce: DECLARACION
    - En \<INSTRUCCION> dado [ε] produce: SALTO
    - En \<OBTENER> dado [obtener] produce: obtener ESPACIO STRPARAM ESPACIO APIKEY
    - En \<OPSIMP> dado [+] produce: +
    - En \<OPSIMP> dado [-] produce: -
    - En \<PUBLICAR> dado [publicar] produce: publicar ESPACIO STRPARAM ESPACIO STRPARAM ESPACIO APIKEY
    - En \<SALTO> dado [\n] produce: \n SALTO
    - En \<SALTO> dado [#] produce: ε
    - En \<SALTO> dado [EOF] produce: ε
    - En \<SALTO> dado [borrar] produce: ε
    - En \<SALTO> dado [cambiar] produce: ε
    - En \<SALTO> dado [identificador] produce: ε
    - En \<SALTO> dado [obtener] produce: ε
    - En \<SALTO> dado [publicar] produce: ε
    - En \<SALTO> dado [si] produce: ε
    - En \<SALTO> dado [variable] produce: ε
    - En \<SALTO> dado [ε] produce: ε
    - En \<SINO> dado [finsi] produce: ε
    - En \<SINO> dado [sino] produce: sino \n ANIDADO
    - En \<SINO> dado [ε] produce: ε
    - En \<STRING> dado ['] produce: ' CADENA '
    - En \<STRPARAM> dado ['] produce: STRING
    - En \<STRPARAM> dado [identificador] produce: identificador
    - En \<TERM> dado ['] produce: FACTOR TERM'
    - En \<TERM> dado [(] produce: FACTOR TERM'
    - En \<TERM> dado [constante] produce: FACTOR TERM'
    - En \<TERM> dado [identificador] produce: FACTOR TERM'
    - En \<TERM'> dado [\n] produce: ε
    - En \<TERM'> dado [space] produce: ε
    - En \<TERM'> dado [#] produce: ε
    - En \<TERM'> dado [)] produce: ε
    - En \<TERM'> dado [*] produce: * FACTOR TERM'
    - En \<TERM'> dado [/] produce: / FACTOR TERM'
    - En \<TERM'> dado [EOF] produce: ε
    - En \<TERM'> dado [borrar] produce: ε
    - En \<TERM'> dado [cambiar] produce: ε
    - En \<TERM'> dado [identificador] produce: ε
    - En \<TERM'> dado [obtener] produce: ε
    - En \<TERM'> dado [publicar] produce: ε
    - En \<TERM'> dado [si] produce: ε
    - En \<TERM'> dado [variable] produce: ε
    - En \<TERM'> dado [ε] produce: ε
- **Ejemplos:**
````
variable b = a*9
variable c = 'a' + 'b'
variable d = 4 + 'b'
si a<4&&a==-3 entonces
obtener 'https://pokeapi.co/api/v2/pokemon/ditto'
obtener 'https://pokeapi.co/api/v2/pokemon/incineroar'
sino
obtener 'https://pokeapi.co/api/v2/pokemon/incineroar'
finsi
#'variable body es para el metodo POST'
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
- [Salida en consola](Test/ParserValid.md)
````
obtener 'https://pokeapi.co/api/v2/pokemon/ditto'
publicar 'https://pokeapi.co/api/v2/pokemon/incineroar'
````
Salida: `Error de sintaxis`

````
variable a
a = 3 +
variable b = a*9
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
Salida: `Error de sintaxis en el simbolo no terminal: =`
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