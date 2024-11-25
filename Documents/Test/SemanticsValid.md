````
Arbol creado
Program:
  Declaration:
    Variable:
      a (Type: Number)
    Value:
      0 (Type: Number)
  Assignment:
    Variable:
      a (Type: Number)
    Value:
      +
        Left:
          2 (Type: Number)
        Right:
          3 (Type: Number)
  Declaration:
    Variable:
      b (Type: Number)
    Value:
      +
        Left:
          *
            Left:
              5 (Type: Number)
            Right:
              a (Type: Number)
        Right:
          +
            Left:
              *
                Left:
                  0 (Type: Number)
                Right:
                  2 (Type: Number)
            Right:
              4 (Type: Number)
  Declaration:
    Variable:
      c (Type: String)
    Value:
      +
        Left:
          c (Type: String)
        Right:
          d (Type: String)
  Declaration:
    Variable:
      body (Type: String)
    Value:
      +
        Left:
          +
            Left:
              holaaa (Type: String)
            Right:
              4 (Type: String)
        Right:
          c (Type: String)
  Declaration:
    Variable:
      url (Type: String)
    Value:
      https://pokeapi.co/api/v2/pokemon/ditto (Type: String)
  GetHttp:
    Endpoint:
      url (Type: String)
    ApiKey:
      body (Type: String)
  PostHttp:
    Endpoint:
      url (Type: String)
    Body:
      body (Type: String)
  Declaration:
    Variable:
      id (Type: String)
    Value:
      alumno1 (Type: String)
  PutHttp:
    Endpoint:
      url (Type: String)
    Id:
      3 (Type: Number)
    Body:
      body (Type: String)
    ApiKey:
      body (Type: String)
  Condicional:
    Comparison:
      ||
        Left:
          <
            Left:
              a (Type: Number)
            Right:
              10 (Type: Number)
        Right:
          ==
            Left:
              a (Type: Number)
            Right:
              -3 (Type: Number)
    Then Block:
      Program:
        Assignment:
          Variable:
            id (Type: String)
          Value:
            pokemon2 (Type: String)
        Condicional:
          Comparison:
            ==
              Left:
                id (Type: String)
              Right:
                pokemon (Type: String)
          Then Block:
            Program:
              Assignment:
                Variable:
                  id (Type: String)
                Value:
                  si (Type: String)
        PutHttp:
          Endpoint:
            https://pokeapi.co/api/v2/pokemon/ditto (Type: String)
          Id:
            id (Type: String)
          Body:
            body (Type: String)
    Else Block:
      Program:
        Assignment:
          Variable:
            id (Type: String)
          Value:
            pokemon3 (Type: String)
        PutHttp:
          Endpoint:
            https://pokeapi.co/api/v2/pokemon/incineroar (Type: String)
          Id:
            id (Type: String)
          Body:
            body (Type: String)
Semantica valida
Program:
  Declaration:
    Variable:
      a (Type: Number)
    Value:
      0 (Type: Number)
  Assignment:
    Variable:
      a (Type: Number)
    Value:
      +
        Left:
          2 (Type: Number)
        Right:
          3 (Type: Number)
  Declaration:
    Variable:
      b (Type: Number)
    Value:
      +
        Left:
          25 (Type: Number)
        Right:
          4 (Type: Number)
  Declaration:
    Variable:
      c (Type: String)
    Value:
      +
        Left:
          c (Type: String)
        Right:
          d (Type: String)
  Declaration:
    Variable:
      body (Type: String)
    Value:
      +
        Left:
          holaaa4 (Type: String)
        Right:
          cd (Type: String)
  Declaration:
    Variable:
      url (Type: String)
    Value:
      https://pokeapi.co/api/v2/pokemon/ditto (Type: String)
  GetHttp:
    Endpoint:
      https://pokeapi.co/api/v2/pokemon/ditto (Type: String)
    ApiKey:
      holaaa4cd (Type: String)
  PostHttp:
    Endpoint:
      https://pokeapi.co/api/v2/pokemon/ditto (Type: String)
    Body:
      holaaa4cd (Type: String)
  Declaration:
    Variable:
      id (Type: String)
    Value:
      alumno1 (Type: String)
  PutHttp:
    Endpoint:
      https://pokeapi.co/api/v2/pokemon/ditto (Type: String)
    Id:
      3 (Type: Number)
    Body:
      holaaa4cd (Type: String)
    ApiKey:
      holaaa4cd (Type: String)
  Condicional:
    Comparison:
      ||
        Left:
          true (Type: Bool)
        Right:
          false (Type: Bool)
    Then Block:
      Program:
        Assignment:
          Variable:
            id (Type: String)
          Value:
            pokemon2 (Type: String)
        Condicional:
          Comparison:
            ==
              Left:
                pokemon2 (Type: String)
              Right:
                pokemon (Type: String)
        PutHttp:
          Endpoint:
            https://pokeapi.co/api/v2/pokemon/ditto (Type: String)
          Id:
            pokemon2 (Type: String)
          Body:
            holaaa4cd (Type: String)
Token(name: a, token type: Identifier, final value: 5, declaration line: 1, usage lines: [2, 3, 13, 13], data type: Number, size: 4 bytes, dimension: 1, scope: Global, address: 0x1000)
Token(name: b, token type: Identifier, final value: 29, declaration line: 3, usage lines: [], data type: Number, size: 4 bytes, dimension: 1, scope: Global, address: 0x1004)
Token(name: c, token type: Identifier, final value: cd, declaration line: 4, usage lines: [5], data type: String, size: 3 bytes, dimension: 1, scope: Global, address: 0x1008)
Token(name: body, token type: Identifier, final value: holaaa4cd, declaration line: 5, usage lines: [7, 8, 11, 11, 12, 18, 21], data type: String, size: 10 bytes, dimension: 1, scope: Global, address: 0x100B)
Token(name: url, token type: Identifier, final value: https://pokeapi.co/api/v2/pokemon/ditto, declaration line: 6, usage lines: [7, 8, 11, 12], data type: String, size: 40 bytes, dimension: 1, scope: Global, address: 0x1015)
Token(name: id, token type: Identifier, final value: pokemon2, declaration line: 9, usage lines: [14, 15, 16, 18, 20, 21], data type: String, size: 9 bytes, dimension: 1, scope: Global, address: 0x103D)
````