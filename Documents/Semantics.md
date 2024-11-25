## Análisis Semántico
- Definiciones dirigidas por sintaxis:

Donde `ε` es `nullptr`

Notas:
- Los identificadores se agregan a la tabla de símbolos en el analizador sintáctico.
- Siempre que hay una operación, se evalúa si los tipos son iguales cuando estos pueden ser diferentes (en condicionales el tipo siempre es Bool).
````
CODIGO->BLOQUE CODIGO' {CODIGO.nodo += CODIGO.nodo.hijos.nodo}
CODIGO'->BLOQUE CODIGO'|ε {CODIGO'.nodo += CODIGO'.nodo.hijos.nodo}
BLOQUE->INSTRUCCION BLOQUE' {BLOQUE.nodo += BLOQUE.nodo.hijos.nodo}
BLOQUE'->salto INSTRUCCION BLOQUE' {BLOQUE'.nodo += BLOQUE'.nodo.(hijos-salto).nodo}
BLOQUE'->ε {BLOQUE'.nodo += BLOQUE'.nodo.hijos.nodo}
ANIDADO->INSTBLOQ salto ANIDADO' {ANIDADO.nodo += ANIDADO.nodo.(hijos-salto).nodo}
ANIDADO'->INSTBLOQ salto ANIDADO' {ANIDADO'.nodo += ANIDADO'.nodo.(hijos-salto).nodo}
ANIDADO'->ε {ANIDADO'.nodo += ANIDADO'.nodo.hijos.nodo}
INSTBLOQ->ASIGNACION|OBTENER|PUBLICAR|CAMBIAR|BORRAR|COMENTARIO|CONDICIONAL {INSTBLOQ.nodo += INSTBLOQ.nodo.hijos.nodo}
INSTRUCCION->DECLARACION|ASIGNACION|OBTENER|PUBLICAR|CAMBIAR|BORRAR|COMENTARIO|CONDICIONAL|SALTO {INSTRUCCION.nodo += INSTRUCCION.nodo.hijos.nodo}
INSTRUCCION->SALTO {INSTRUCCION.nodo += ε}
CONDICIONAL->si ESPACIO CONDICION ESPACIO entonces salto ANIDADO SINO finsi
{
    CONDICIONAL.comparacion->CONDICION.node
    CONDICIONAL.then->ANIDADO.node
    CONDICIONAL.else->SINO.node
}
SINO->sino salto ANIDADO {SINO.node->ANIDADO}
SINO->ε {SINO.node->ε}
CONDICION->COMPARACION CONDICION'
{
    CONDICION'.tipo = Bool
    CONDICION.val = COMPARACION.val CONDICION'.op CONDICION'.val
    || CONDICION.val = COMPARACION.val
}
CONDICION'->&& COMPARACION CONDICION'1
{
    CONDICION'.tipo = Bool
    CONDICION'.op = &&
    CONDICION'.val = COMPARACION.val CONDICION'1.op CONDICION'1.val
    || CONDICION'.val = COMPARACION.val
}
CONDICION'->or COMPARACION CONDICION'1
{
    CONDICION'.tipo = Bool
    CONDICION'.op = or
    CONDICION'.val = COMPARACION.val CONDICION'1.op CONDICION'1.val
    || CONDICION'.val = COMPARACION.val
}
CONDICION'->ε {CONDICION'.nodo = ε}
COMPARACION->BOOL COMPARACION'
{
    COMPARACION.tipo = Bool
    COMPARACION.val = BOOL.val COMPARACION'.op COMPARACION'.val
    || COMPARACION.val = BOOL.val
}
COMPARACION'->== BOOL COMPARACION'1
{
    COMPARACION'.tipo = Bool
    COMPARACION'.op = ==
    COMPARACION'.val = BOOL.val COMPARACION'1.op COMPARACION'1.val
    || COMPARACION'.val = BOOL.val
}
COMPARACION'->< BOOL COMPARACION'1
{
    COMPARACION'.tipo = Bool
    COMPARACION'.op = <
    COMPARACION'.val = BOOL.val COMPARACION'1.op COMPARACION'1.val
    || COMPARACION'.val = BOOL.val
}
COMPARACION'->> BOOL COMPARACION'1
{
    COMPARACION'.tipo = Bool
    COMPARACION'.op = >
    COMPARACION'.val = BOOL.val COMPARACION'1.op COMPARACION'1.val
    || COMPARACION'.val = BOOL.val
}
COMPARACION'-> ε {COMPARACION'.nodo = ε}
BOOL->identificador|constante|STRING
{
    BOOL.tipo = BOOL.nodo.hijo.tipo
    BOOL.val = BOOL.nodo.hijo.val
}
COMENTARIO-># STRING {COMENTARIO.nodo = ε}
OBTENER->obtener ESPACIO STRPARAM ESPACIO APIKEY
{
    OBTENER.endpoint = OBTENER.nodo.STRPARAM.nodo
    OBTENER.apikey = OBTENER.nodo.APIKEY.nodo
}
PUBLICAR->publicar ESPACIO STRPARAM1 ESPACIO STRPARAM2 ESPACIO APIKEY
{
    PUBLICAR.endpoint = PUBLICAR.nodo.STRPARAM1.nodo
    PUBLICAR.body = PUBLICAR.nodo.STRPARAM2.nodo
    PUBLICAR.apikey = PUBLICAR.nodo.APIKEY.nodo
}
CAMBIAR->cambiar ESPACIO STRPARAM1 ESPACIO DATO ESPACIO STRPARAM2 ESPACIO APIKEY
{
    CAMBIAR.endpoint = CAMBIAR.nodo.STRPARAM1.nodo
    CAMBIAR.id = CAMBIAR.nodo.DATO.nodo
    CAMBIAR.body = CAMBIAR.nodo.STRPARAM2.nodo
    CAMBIAR.apikey = CAMBIAR.nodo.APIKEY.nodo
}
BORRAR->borrar ESPACIO STRPARAM ESPACIO DATO ESPACIO APIKEY
{
    BORRAR.endpoint = BORRAR.nodo.STRPARAM.nodo
    BORRAR.id = BORRAR.nodo.DATO.nodo
    BORRAR.apikey = BORRAR.nodo.APIKEY.nodo
}
APIKEY->STRPARAM {APIKEY.val = APIKEY.nodo.hijo.val}
APIKEY->ε {APIKEY.nodo = ε}
STRPARAM->STRING|identificador {STRPARAM.val = STRPARAM.nodo.hijo.val}
DECLARACION->variable ESPACIO identificador ESPACIO = ESPACIO EXP
{
    DECLARACION.variable = identificador.nodo
    DECLARACION.expression = EXP.nodo
    identificador.val = EXP.val
}
ASIGNACION->identificador ESPACIO = ESPACIO EXP
{
    ASIGNACION.variable = identificador.nodo
    ASIGNACION.expression = EXP.nodo
    identificador.val = EXP.val
}
EXP->TERM EXP'
{
    EXP.tipo = EXP.nodo.hijos.tipo
    EXP.val = TERM.val EXP'.op EXP'.val || EXP.val = TERM.val
}
EXP'->ESPACIO OPSIMP ESPACIO TERM EXP'1
{
    EXP'.tipo = EXP'.nodo.TERM.tipo
    EXP'.op = OPSIMP.val
    EXP'.val = TERM.val EXP'1.op EXP'1.val || EXP'.val = TERM.val
}
EXP'->ε {EXP.nodo = ε}
OPSIMP->+|- {OPSIMP.val = OPSIMP.nodo.hijo.val}
TERM->FACTOR TERM'
{
    TERM.tipo = TERM.nodo.hijos.tipo
    TERM.val = FACTOR.val TERM'.op TERM'.val || TERM.val = FACTOR.val
}
TERM'->* FACTOR TERM'1
{
    TERM'.tipo = TERM'.nodo.(hijos-*).tipo
    TERM'.op = *
    TERM'.val = FACTOR.val TERM'1.op TERM'1.val || TERM'.val = FACTOR.val
}
TERM'->/ FACTOR TERM'1
{
    TERM'.tipo = TERM'.nodo.(hijos-/).tipo
    TERM'.op = /
    TERM'.val = FACTOR.val TERM'1.op TERM'1.val || TERM'.val = FACTOR.val
}
TERM'->ε { TERM'.nodo = ε}
FACTOR->identificador|constante|STRING
{
    BOOL.tipo = BOOL.nodo.hijo.tipo
    BOOL.val = BOOL.nodo.hijo.val
}
FACTOR->( EXP )
{
    BOOL.tipo = BOOL.nodo.EXP.tipo
    BOOL.val = BOOL.nodo.EXP.val
}
ESPACIO->space ESPACIO|ε {ESPACIO.nodo = ε}
SALTO->salto SALTO|ε {SALTO.nodo = ε}
DATO->constante|STRING|identificador
{
    DATO.tipo = DATO.nodo.hijo.tipo
    DATO.val = DATO.nodo.hijo.val
}
STRING->' CADENA '
{
    STRING.tipo = String
    STRING.val = CADENA.val
}
CADENA->∈Σ-' CADENA'
{
    CADENA.val = ∈Σ-'.val + CADENA'.val
    || CADENA.val = ∈Σ-'.val
}
CADENA'->∈Σ-' CADENA'1|ε
{
    CADENA'.val = ∈Σ-'.val + CADENA'1.val
    || CADENA'.val = ∈Σ-'.val
}
````
### **Ejemplos:**
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
[Salida](Test/SemanticsValid.md)
````
variable a = 0
a = '0'
````
`Error semantico: se puede asignar String a Number`
[Salida](Test/SemanticsAssignType.md)
````
variable a = 0*'0'
````
`Error semantico: tipos de datos incompatibles entre si en *`
[Salida](Test/SemanticsExpTypes.md)
````
variable url = 0
obtener url
````
`Error semantico: el url debe ser String en GetHttp`
[Salida](Test/SemanticsApiParam.md)
````
variable a = 'a'*'b'
````
`Error semantico: no se permite la operacion * en String`
[Salida](Test/SemanticsOpTypes.md)
````
si 1>'2' entonces
    obtener 'url'
finsi
````
`Error semantico: tipos de datos incompatibles entre si en >`
[Salida](Test/SemanticsIfTypes.md)
