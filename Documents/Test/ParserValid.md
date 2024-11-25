````
CODIGO
  BLOQUE
    INSTRUCCION
      DECLARACION
        Token(name: variable, token type: Keyword, line: 1, data type: -)
        ESPACIO
          Token(name: space, token type: Punctuation, line: 1, data type: -)
          ESPACIO
            ε
        Token(name: a, token type: Identifier, line: 1, data type: Number)
        ESPACIO
          Token(name: space, token type: Punctuation, line: 1, data type: -)
          ESPACIO
            ε
        Token(name: =, token type: Operation, line: 1, data type: -)
        ESPACIO
          Token(name: space, token type: Punctuation, line: 1, data type: -)
          ESPACIO
            ε
        EXP
          TERM
            FACTOR
              Token(name: 0, token type: Constant, line: 1, data type: Number)
            TERM'
              ε
          EXP'
            ε
    BLOQUE'
      Token(name: \n, token type: Punctuation, line: 1, data type: -)
      INSTRUCCION
        ASIGNACION
          Token(name: a, token type: Identifier, line: 2, data type: Number)
          ESPACIO
            Token(name: space, token type: Punctuation, line: 2, data type: -)
            ESPACIO
              ε
          Token(name: =, token type: Operation, line: 2, data type: -)
          ESPACIO
            Token(name: space, token type: Punctuation, line: 2, data type: -)
            ESPACIO
              ε
          EXP
            TERM
              FACTOR
                Token(name: 3, token type: Constant, line: 2, data type: Number)
              TERM'
                ε
            EXP'
              ESPACIO
                Token(name: space, token type: Punctuation, line: 2, data type: -)
                ESPACIO
                  ε
              OPSIMP
                Token(name: +, token type: Operation, line: 2, data type: -)
              ESPACIO
                Token(name: space, token type: Punctuation, line: 2, data type: -)
                ESPACIO
                  ε
              TERM
                FACTOR
                  Token(name: 2, token type: Constant, line: 2, data type: Number)
                TERM'
                  ε
              EXP'
                ε
      BLOQUE'
        Token(name: \n, token type: Punctuation, line: 2, data type: -)
        INSTRUCCION
          DECLARACION
            Token(name: variable, token type: Keyword, line: 3, data type: -)
            ESPACIO
              Token(name: space, token type: Punctuation, line: 3, data type: -)
              ESPACIO
                ε
            Token(name: b, token type: Identifier, line: 3, data type: Number)
            ESPACIO
              Token(name: space, token type: Punctuation, line: 3, data type: -)
              ESPACIO
                ε
            Token(name: =, token type: Operation, line: 3, data type: -)
            ESPACIO
              Token(name: space, token type: Punctuation, line: 3, data type: -)
              ESPACIO
                ε
            EXP
              TERM
                FACTOR
                  Token(name: a, token type: Identifier, line: 3, data type: Number)
                TERM'
                  Token(name: *, token type: Operation, line: 3, data type: -)
                  FACTOR
                    Token(name: 9, token type: Constant, line: 3, data type: Number)
                  TERM'
                    ε
              EXP'
                ε
        BLOQUE'
          Token(name: \n, token type: Punctuation, line: 3, data type: -)
          INSTRUCCION
            DECLARACION
              Token(name: variable, token type: Keyword, line: 4, data type: -)
              ESPACIO
                Token(name: space, token type: Punctuation, line: 4, data type: -)
                ESPACIO
                  ε
              Token(name: c, token type: Identifier, line: 4, data type: String)
              ESPACIO
                Token(name: space, token type: Punctuation, line: 4, data type: -)
                ESPACIO
                  ε
              Token(name: =, token type: Operation, line: 4, data type: -)
              ESPACIO
                Token(name: space, token type: Punctuation, line: 4, data type: -)
                ESPACIO
                  ε
              EXP
                TERM
                  FACTOR
                    STRING
                      Token(name: ', token type: Punctuation, line: 4, data type: String)
                      CADENA
                        Token(name: a, token type: Identifier, line: 4, data type: String)
                        CADENA'
                          ε
                      Token(name: ', token type: Punctuation, line: 4, data type: String)
                  TERM'
                    ε
                EXP'
                  ESPACIO
                    Token(name: space, token type: Punctuation, line: 4, data type: -)
                    ESPACIO
                      ε
                  OPSIMP
                    Token(name: +, token type: Operation, line: 4, data type: -)
                  ESPACIO
                    Token(name: space, token type: Punctuation, line: 4, data type: -)
                    ESPACIO
                      ε
                  TERM
                    FACTOR
                      STRING
                        Token(name: ', token type: Punctuation, line: 4, data type: String)
                        CADENA
                          Token(name: b, token type: Identifier, line: 4, data type: String)
                          CADENA'
                            ε
                        Token(name: ', token type: Punctuation, line: 4, data type: String)
                    TERM'
                      ε
                  EXP'
                    ε
          BLOQUE'
            Token(name: \n, token type: Punctuation, line: 4, data type: -)
            INSTRUCCION
              DECLARACION
                Token(name: variable, token type: Keyword, line: 5, data type: -)
                ESPACIO
                  Token(name: space, token type: Punctuation, line: 5, data type: -)
                  ESPACIO
                    ε
                Token(name: d, token type: Identifier, line: 5, data type: String)
                ESPACIO
                  Token(name: space, token type: Punctuation, line: 5, data type: -)
                  ESPACIO
                    ε
                Token(name: =, token type: Operation, line: 5, data type: -)
                ESPACIO
                  Token(name: space, token type: Punctuation, line: 5, data type: -)
                  ESPACIO
                    ε
                EXP
                  TERM
                    FACTOR
                      Token(name: 4, token type: Constant, line: 5, data type: Number)
                    TERM'
                      ε
                  EXP'
                    ESPACIO
                      Token(name: space, token type: Punctuation, line: 5, data type: -)
                      ESPACIO
                        ε
                    OPSIMP
                      Token(name: +, token type: Operation, line: 5, data type: -)
                    ESPACIO
                      Token(name: space, token type: Punctuation, line: 5, data type: -)
                      ESPACIO
                        ε
                    TERM
                      FACTOR
                        STRING
                          Token(name: ', token type: Punctuation, line: 5, data type: String)
                          CADENA
                            Token(name: b, token type: Identifier, line: 5, data type: String)
                            CADENA'
                              ε
                          Token(name: ', token type: Punctuation, line: 5, data type: String)
                      TERM'
                        ε
                    EXP'
                      ε
            BLOQUE'
              Token(name: \n, token type: Punctuation, line: 5, data type: -)
              INSTRUCCION
                CONDICIONAL
                  Token(name: si, token type: Keyword, line: 6, data type: -)
                  ESPACIO
                    Token(name: space, token type: Punctuation, line: 6, data type: -)
                    ESPACIO
                      ε
                  CONDICION
                    COMPARACION
                      BOOL
                        Token(name: a, token type: Identifier, line: 6, data type: Number)
                      COMPARACION'
                        Token(name: <, token type: Operation, line: 6, data type: -)
                        BOOL
                          Token(name: 4, token type: Constant, line: 6, data type: Number)
                        COMPARACION'
                          ε
                    CONDICION'
                      Token(name: &&, token type: Operation, line: 6, data type: -)
                      COMPARACION
                        BOOL
                          Token(name: a, token type: Identifier, line: 6, data type: Number)
                        COMPARACION'
                          Token(name: ==, token type: Operation, line: 6, data type: -)
                          BOOL
                            Token(name: -3, token type: Constant, line: 6, data type: Number)
                          COMPARACION'
                            ε
                      CONDICION'
                        ε
                  ESPACIO
                    Token(name: space, token type: Punctuation, line: 6, data type: -)
                    ESPACIO
                      ε
                  Token(name: entonces, token type: Keyword, line: 6, data type: -)
                  Token(name: \n, token type: Punctuation, line: 6, data type: -)
                  ANIDADO
                    INSTBLOQ
                      OBTENER
                        Token(name: obtener, token type: Keyword, line: 7, data type: -)
                        ESPACIO
                          Token(name: space, token type: Punctuation, line: 7, data type: -)
                          ESPACIO
                            ε
                        STRPARAM
                          STRING
                            Token(name: ', token type: Punctuation, line: 7, data type: String)
                            CADENA
                              Token(name: https, token type: Identifier, line: 7, data type: String)
                              CADENA'
                                Token(name: :, token type: Punctuation, line: 7, data type: String)
                                CADENA'
                                  Token(name: /, token type: Operation, line: 7, data type: String)
                                  CADENA'
                                    Token(name: /, token type: Operation, line: 7, data type: String)
                                    CADENA'
                                      Token(name: pokeapi, token type: Identifier, line: 7, data type: String)
                                      CADENA'
                                        Token(name: ., token type: Punctuation, line: 7, data type: String)
                                        CADENA'
                                          Token(name: co, token type: Identifier, line: 7, data type: String)
                                          CADENA'
                                            Token(name: /, token type: Operation, line: 7, data type: String)
                                            CADENA'
                                              Token(name: api, token type: Identifier, line: 7, data type: String)
                                              CADENA'
                                                Token(name: /, token type: Operation, line: 7, data type: String)
                                                CADENA'
                                                  Token(name: v2, token type: Identifier, line: 7, data type: String)
                                                  CADENA'
                                                    Token(name: /, token type: Operation, line: 7, data type: String)
                                                    CADENA'
                                                      Token(name: pokemon, token type: Identifier, line: 7, data type: String)
                                                      CADENA'
                                                        Token(name: /, token type: Operation, line: 7, data type: String)
                                                        CADENA'
                                                          Token(name: ditto, token type: Identifier, line: 7, data type: String)
                                                          CADENA'
                                                            ε
                            Token(name: ', token type: Punctuation, line: 7, data type: String)
                        ESPACIO
                          ε
                        APIKEY
                          ε
                    Token(name: \n, token type: Punctuation, line: 7, data type: -)
                    ANIDADO'
                      INSTBLOQ
                        OBTENER
                          Token(name: obtener, token type: Keyword, line: 8, data type: -)
                          ESPACIO
                            Token(name: space, token type: Punctuation, line: 8, data type: -)
                            ESPACIO
                              ε
                          STRPARAM
                            STRING
                              Token(name: ', token type: Punctuation, line: 8, data type: String)
                              CADENA
                                Token(name: https, token type: Identifier, line: 8, data type: String)
                                CADENA'
                                  Token(name: :, token type: Punctuation, line: 8, data type: String)
                                  CADENA'
                                    Token(name: /, token type: Operation, line: 8, data type: String)
                                    CADENA'
                                      Token(name: /, token type: Operation, line: 8, data type: String)
                                      CADENA'
                                        Token(name: pokeapi, token type: Identifier, line: 8, data type: String)
                                        CADENA'
                                          Token(name: ., token type: Punctuation, line: 8, data type: String)
                                          CADENA'
                                            Token(name: co, token type: Identifier, line: 8, data type: String)
                                            CADENA'
                                              Token(name: /, token type: Operation, line: 8, data type: String)
                                              CADENA'
                                                Token(name: api, token type: Identifier, line: 8, data type: String)
                                                CADENA'
                                                  Token(name: /, token type: Operation, line: 8, data type: String)
                                                  CADENA'
                                                    Token(name: v2, token type: Identifier, line: 8, data type: String)
                                                    CADENA'
                                                      Token(name: /, token type: Operation, line: 8, data type: String)
                                                      CADENA'
                                                        Token(name: pokemon, token type: Identifier, line: 8, data type: String)
                                                        CADENA'
                                                          Token(name: /, token type: Operation, line: 8, data type: String)
                                                          CADENA'
                                                            Token(name: incineroar, token type: Identifier, line: 8, data type: String)
                                                            CADENA'
                                                              ε
                              Token(name: ', token type: Punctuation, line: 8, data type: String)
                          ESPACIO
                            ε
                          APIKEY
                            ε
                      Token(name: \n, token type: Punctuation, line: 8, data type: -)
                      ANIDADO'
                        ε
                  SINO
                    Token(name: sino, token type: Keyword, line: 9, data type: -)
                    Token(name: \n, token type: Punctuation, line: 9, data type: -)
                    ANIDADO
                      INSTBLOQ
                        OBTENER
                          Token(name: obtener, token type: Keyword, line: 10, data type: -)
                          ESPACIO
                            Token(name: space, token type: Punctuation, line: 10, data type: -)
                            ESPACIO
                              ε
                          STRPARAM
                            STRING
                              Token(name: ', token type: Punctuation, line: 10, data type: String)
                              CADENA
                                Token(name: https, token type: Identifier, line: 10, data type: String)
                                CADENA'
                                  Token(name: :, token type: Punctuation, line: 10, data type: String)
                                  CADENA'
                                    Token(name: /, token type: Operation, line: 10, data type: String)
                                    CADENA'
                                      Token(name: /, token type: Operation, line: 10, data type: String)
                                      CADENA'
                                        Token(name: pokeapi, token type: Identifier, line: 10, data type: String)
                                        CADENA'
                                          Token(name: ., token type: Punctuation, line: 10, data type: String)
                                          CADENA'
                                            Token(name: co, token type: Identifier, line: 10, data type: String)
                                            CADENA'
                                              Token(name: /, token type: Operation, line: 10, data type: String)
                                              CADENA'
                                                Token(name: api, token type: Identifier, line: 10, data type: String)
                                                CADENA'
                                                  Token(name: /, token type: Operation, line: 10, data type: String)
                                                  CADENA'
                                                    Token(name: v2, token type: Identifier, line: 10, data type: String)
                                                    CADENA'
                                                      Token(name: /, token type: Operation, line: 10, data type: String)
                                                      CADENA'
                                                        Token(name: pokemon, token type: Identifier, line: 10, data type: String)
                                                        CADENA'
                                                          Token(name: /, token type: Operation, line: 10, data type: String)
                                                          CADENA'
                                                            Token(name: incineroar, token type: Identifier, line: 10, data type: String)
                                                            CADENA'
                                                              ε
                              Token(name: ', token type: Punctuation, line: 10, data type: String)
                          ESPACIO
                            ε
                          APIKEY
                            ε
                      Token(name: \n, token type: Punctuation, line: 10, data type: -)
                      ANIDADO'
                        ε
                  Token(name: finsi, token type: Keyword, line: 11, data type: -)
              BLOQUE'
                Token(name: \n, token type: Punctuation, line: 11, data type: -)
                INSTRUCCION
                  COMENTARIO
                    Token(name: #, token type: Punctuation, line: 12, data type: -)
                    STRING
                      Token(name: ', token type: Punctuation, line: 12, data type: String)
                      CADENA
                        Token(name: variable, token type: Keyword, line: 12, data type: String)
                        CADENA'
                          Token(name: space, token type: Punctuation, line: 12, data type: String)
                          CADENA'
                            Token(name: body, token type: Identifier, line: 12, data type: String)
                            CADENA'
                              Token(name: space, token type: Punctuation, line: 12, data type: String)
                              CADENA'
                                Token(name: es, token type: Identifier, line: 12, data type: String)
                                CADENA'
                                  Token(name: space, token type: Punctuation, line: 12, data type: String)
                                  CADENA'
                                    Token(name: para, token type: Identifier, line: 12, data type: String)
                                    CADENA'
                                      Token(name: space, token type: Punctuation, line: 12, data type: String)
                                      CADENA'
                                        Token(name: el, token type: Identifier, line: 12, data type: String)
                                        CADENA'
                                          Token(name: space, token type: Punctuation, line: 12, data type: String)
                                          CADENA'
                                            Token(name: metodo, token type: Identifier, line: 12, data type: String)
                                            CADENA'
                                              Token(name: space, token type: Punctuation, line: 12, data type: String)
                                              CADENA'
                                                Token(name: post, token type: Identifier, line: 12, data type: String)
                                                CADENA'
                                                  ε
                      Token(name: ', token type: Punctuation, line: 12, data type: String)
                BLOQUE'
                  Token(name: \n, token type: Punctuation, line: 12, data type: -)
                  INSTRUCCION
                    DECLARACION
                      Token(name: variable, token type: Keyword, line: 13, data type: -)
                      ESPACIO
                        Token(name: space, token type: Punctuation, line: 13, data type: -)
                        ESPACIO
                          ε
                      Token(name: body, token type: Identifier, line: 12, data type: String)
                      ESPACIO
                        Token(name: space, token type: Punctuation, line: 13, data type: -)
                        ESPACIO
                          ε
                      Token(name: =, token type: Operation, line: 13, data type: -)
                      ESPACIO
                        Token(name: space, token type: Punctuation, line: 13, data type: -)
                        ESPACIO
                          ε
                      EXP
                        TERM
                          FACTOR
                            STRING
                              Token(name: ', token type: Punctuation, line: 13, data type: String)
                              CADENA
                                Token(name: \n, token type: Punctuation, line: 13, data type: String)
                                CADENA'
                                  Token(name: doe, token type: Identifier, line: 14, data type: String)
                                  CADENA'
                                    Token(name: :, token type: Punctuation, line: 14, data type: String)
                                    CADENA'
                                      Token(name: space, token type: Punctuation, line: 14, data type: String)
                                      CADENA'
                                        Token(name: ", token type: Punctuation, line: 14, data type: String)
                                        CADENA'
                                          Token(name: a, token type: Identifier, line: 14, data type: String)
                                          CADENA'
                                            Token(name: space, token type: Punctuation, line: 14, data type: String)
                                            CADENA'
                                              Token(name: deer, token type: Identifier, line: 14, data type: String)
                                              CADENA'
                                                Token(name: ,, token type: Punctuation, line: 14, data type: String)
                                                CADENA'
                                                  Token(name: space, token type: Punctuation, line: 14, data type: String)
                                                  CADENA'
                                                    Token(name: a, token type: Identifier, line: 14, data type: String)
                                                    CADENA'
                                                      Token(name: space, token type: Punctuation, line: 14, data type: String)
                                                      CADENA'
                                                        Token(name: female, token type: Identifier, line: 14, data type: String)
                                                        CADENA'
                                                          Token(name: space, token type: Punctuation, line: 14, data type: String)
                                                          CADENA'
                                                            Token(name: deer, token type: Identifier, line: 14, data type: String)
                                                            CADENA'
                                                              Token(name: ", token type: Punctuation, line: 14, data type: String)
                                                              CADENA'
                                                                Token(name: \n, token type: Punctuation, line: 14, data type: String)
                                                                CADENA'
                                                                  Token(name: space, token type: Punctuation, line: 15, data type: String)
                                                                  CADENA'
                                                                    Token(name: ray, token type: Identifier, line: 15, data type: String)
                                                                    CADENA'
                                                                      Token(name: :, token type: Punctuation, line: 15, data type: String)
                                                                      CADENA'
                                                                        Token(name: space, token type: Punctuation, line: 15, data type: String)
                                                                        CADENA'
                                                                          Token(name: ", token type: Punctuation, line: 15, data type: String)
                                                                          CADENA'
                                                                            Token(name: a, token type: Identifier, line: 15, data type: String)
                                                                            CADENA'
                                                                              Token(name: space, token type: Punctuation, line: 15, data type: String)
                                                                              CADENA'
                                                                                Token(name: drop, token type: Identifier, line: 15, data type: String)
                                                                                CADENA'
                                                                                  Token(name: space, token type: Punctuation, line: 15, data type: String)
                                                                                  CADENA'
                                                                                    Token(name: of, token type: Identifier, line: 15, data type: String)
                                                                                    CADENA'
                                                                                      Token(name: space, token type: Punctuation, line: 15, data type: String)
                                                                                      CADENA'
                                                                                        Token(name: golden, token type: Identifier, line: 15, data type: String)
                                                                                        CADENA'
                                                                                          Token(name: space, token type: Punctuation, line: 15, data type: String)
                                                                                          CADENA'
                                                                                            Token(name: sun, token type: Identifier, line: 15, data type: String)
                                                                                            CADENA'
                                                                                              Token(name: ", token type: Punctuation, line: 15, data type: String)
                                                                                              CADENA'
                                                                                                Token(name: \n, token type: Punctuation, line: 15, data type: String)
                                                                                                CADENA'
                                                                                                  Token(name: space, token type: Punctuation, line: 16, data type: String)
                                                                                                  CADENA'
                                                                                                    Token(name: pi, token type: Identifier, line: 16, data type: String)
                                                                                                    CADENA'
                                                                                                      Token(name: :, token type: Punctuation, line: 16, data type: String)
                                                                                                      CADENA'
                                                                                                        Token(name: space, token type: Punctuation, line: 16, data type: String)
                                                                                                        CADENA'
                                                                                                          Token(name: 3, token type: Constant, line: 16, data type: String)
                                                                                                          CADENA'
                                                                                                            Token(name: ., token type: Punctuation, line: 16, data type: String)
                                                                                                            CADENA'
                                                                                                              Token(name: 14159, token type: Constant, line: 16, data type: String)
                                                                                                              CADENA'
                                                                                                                Token(name: \n, token type: Punctuation, line: 16, data type: String)
                                                                                                                CADENA'
                                                                                                                  Token(name: space, token type: Punctuation, line: 17, data type: String)
                                                                                                                  CADENA'
                                                                                                                    Token(name: xmas, token type: Identifier, line: 17, data type: String)
                                                                                                                    CADENA'
                                                                                                                      Token(name: :, token type: Punctuation, line: 17, data type: String)
                                                                                                                      CADENA'
                                                                                                                        Token(name: space, token type: Punctuation, line: 17, data type: String)
                                                                                                                        CADENA'
                                                                                                                          Token(name: true, token type: Identifier, line: 17, data type: String)
                                                                                                                          CADENA'
                                                                                                                            Token(name: \n, token type: Punctuation, line: 17, data type: String)
                                                                                                                            CADENA'
                                                                                                                              Token(name: space, token type: Punctuation, line: 18, data type: String)
                                                                                                                              CADENA'
                                                                                                                                Token(name: french, token type: Identifier, line: 18, data type: String)
                                                                                                                                CADENA'
                                                                                                                                  Token(name: -, token type: Operation, line: 18, data type: String)
                                                                                                                                  CADENA'
                                                                                                                                    Token(name: hens, token type: Identifier, line: 18, data type: String)
                                                                                                                                    CADENA'
                                                                                                                                      Token(name: :, token type: Punctuation, line: 18, data type: String)
                                                                                                                                      CADENA'
                                                                                                                                        Token(name: space, token type: Punctuation, line: 18, data type: String)
                                                                                                                                        CADENA'
                                                                                                                                          Token(name: 3, token type: Constant, line: 18, data type: String)
                                                                                                                                          CADENA'
                                                                                                                                            Token(name: \n, token type: Punctuation, line: 18, data type: String)
                                                                                                                                            CADENA'
                                                                                                                                              Token(name: space, token type: Punctuation, line: 19, data type: String)
                                                                                                                                              CADENA'
                                                                                                                                                Token(name: calling, token type: Identifier, line: 19, data type: String)
                                                                                                                                                CADENA'
                                                                                                                                                  Token(name: -, token type: Operation, line: 19, data type: String)
                                                                                                                                                  CADENA'
                                                                                                                                                    Token(name: birds, token type: Identifier, line: 19, data type: String)
                                                                                                                                                    CADENA'
                                                                                                                                                      Token(name: :, token type: Punctuation, line: 19, data type: String)
                                                                                                                                                      CADENA'
                                                                                                                                                        Token(name: \n, token type: Punctuation, line: 19, data type: String)
                                                                                                                                                        CADENA'
                                                                                                                                                          Token(name: space, token type: Punctuation, line: 20, data type: String)
                                                                                                                                                          CADENA'
                                                                                                                                                            Token(name: space, token type: Punctuation, line: 20, data type: String)
                                                                                                                                                            CADENA'
                                                                                                                                                              Token(name: space, token type: Punctuation, line: 20, data type: String)
                                                                                                                                                              CADENA'
                                                                                                                                                                Token(name: -, token type: Operation, line: 20, data type: String)
                                                                                                                                                                CADENA'
                                                                                                                                                                  Token(name: space, token type: Punctuation, line: 20, data type: String)
                                                                                                                                                                  CADENA'
                                                                                                                                                                    Token(name: huey, token type: Identifier, line: 20, data type: String)
                                                                                                                                                                    CADENA'
                                                                                                                                                                      Token(name: \n, token type: Punctuation, line: 20, data type: String)
                                                                                                                                                                      CADENA'
                                                                                                                                                                        Token(name: space, token type: Punctuation, line: 21, data type: String)
                                                                                                                                                                        CADENA'
                                                                                                                                                                          Token(name: space, token type: Punctuation, line: 21, data type: String)
                                                                                                                                                                          CADENA'
                                                                                                                                                                            Token(name: space, token type: Punctuation, line: 21, data type: String)
                                                                                                                                                                            CADENA'
                                                                                                                                                                              Token(name: -, token type: Operation, line: 21, data type: String)
                                                                                                                                                                              CADENA'
                                                                                                                                                                                Token(name: space, token type: Punctuation, line: 21, data type: String)
                                                                                                                                                                                CADENA'
                                                                                                                                                                                  Token(name: dewey, token type: Identifier, line: 21, data type: String)
                                                                                                                                                                                  CADENA'
                                                                                                                                                                                    Token(name: \n, token type: Punctuation, line: 21, data type: String)
                                                                                                                                                                                    CADENA'
                                                                                                                                                                                      Token(name: space, token type: Punctuation, line: 22, data type: String)
                                                                                                                                                                                      CADENA'
                                                                                                                                                                                        Token(name: space, token type: Punctuation, line: 22, data type: String)
                                                                                                                                                                                        CADENA'
                                                                                                                                                                                          Token(name: space, token type: Punctuation, line: 22, data type: String)
                                                                                                                                                                                          CADENA'
                                                                                                                                                                                            Token(name: -, token type: Operation, line: 22, data type: String)
                                                                                                                                                                                            CADENA'
                                                                                                                                                                                              Token(name: space, token type: Punctuation, line: 22, data type: String)
                                                                                                                                                                                              CADENA'
                                                                                                                                                                                                Token(name: louie, token type: Identifier, line: 22, data type: String)
                                                                                                                                                                                                CADENA'
                                                                                                                                                                                                  Token(name: \n, token type: Punctuation, line: 22, data type: String)
                                                                                                                                                                                                  CADENA'
                                                                                                                                                                                                    Token(name: space, token type: Punctuation, line: 23, data type: String)
                                                                                                                                                                                                    CADENA'
                                                                                                                                                                                                      Token(name: space, token type: Punctuation, line: 23, data type: String)
                                                                                                                                                                                                      CADENA'
                                                                                                                                                                                                        Token(name: space, token type: Punctuation, line: 23, data type: String)
                                                                                                                                                                                                        CADENA'
                                                                                                                                                                                                          Token(name: -, token type: Operation, line: 23, data type: String)
                                                                                                                                                                                                          CADENA'
                                                                                                                                                                                                            Token(name: space, token type: Punctuation, line: 23, data type: String)
                                                                                                                                                                                                            CADENA'
                                                                                                                                                                                                              Token(name: fred, token type: Identifier, line: 23, data type: String)
                                                                                                                                                                                                              CADENA'
                                                                                                                                                                                                                Token(name: \n, token type: Punctuation, line: 23, data type: String)
                                                                                                                                                                                                                CADENA'
                                                                                                                                                                                                                  Token(name: space, token type: Punctuation, line: 24, data type: String)
                                                                                                                                                                                                                  CADENA'
                                                                                                                                                                                                                    Token(name: xmas, token type: Identifier, line: 24, data type: String)
                                                                                                                                                                                                                    CADENA'
                                                                                                                                                                                                                      Token(name: -, token type: Operation, line: 24, data type: String)
                                                                                                                                                                                                                      CADENA'
                                                                                                                                                                                                                        Token(name: fifth, token type: Identifier, line: 24, data type: String)
                                                                                                                                                                                                                        CADENA'
                                                                                                                                                                                                                          Token(name: -, token type: Operation, line: 24, data type: String)
                                                                                                                                                                                                                          CADENA'
                                                                                                                                                                                                                            Token(name: day, token type: Identifier, line: 24, data type: String)
                                                                                                                                                                                                                            CADENA'
                                                                                                                                                                                                                              Token(name: :, token type: Punctuation, line: 24, data type: String)
                                                                                                                                                                                                                              CADENA'
                                                                                                                                                                                                                                Token(name: \n, token type: Punctuation, line: 24, data type: String)
                                                                                                                                                                                                                                CADENA'
                                                                                                                                                                                                                                  Token(name: space, token type: Punctuation, line: 25, data type: String)
                                                                                                                                                                                                                                  CADENA'
                                                                                                                                                                                                                                    Token(name: space, token type: Punctuation, line: 25, data type: String)
                                                                                                                                                                                                                                    CADENA'
                                                                                                                                                                                                                                      Token(name: space, token type: Punctuation, line: 25, data type: String)
                                                                                                                                                                                                                                      CADENA'
                                                                                                                                                                                                                                        Token(name: calling, token type: Identifier, line: 25, data type: String)
                                                                                                                                                                                                                                        CADENA'
                                                                                                                                                                                                                                          Token(name: -, token type: Operation, line: 25, data type: String)
                                                                                                                                                                                                                                          CADENA'
                                                                                                                                                                                                                                            Token(name: birds, token type: Identifier, line: 25, data type: String)
                                                                                                                                                                                                                                            CADENA'
                                                                                                                                                                                                                                              Token(name: :, token type: Punctuation, line: 25, data type: String)
                                                                                                                                                                                                                                              CADENA'
                                                                                                                                                                                                                                                Token(name: space, token type: Punctuation, line: 25, data type: String)
                                                                                                                                                                                                                                                CADENA'
                                                                                                                                                                                                                                                  Token(name: four, token type: Identifier, line: 25, data type: String)
                                                                                                                                                                                                                                                  CADENA'
                                                                                                                                                                                                                                                    Token(name: \n, token type: Punctuation, line: 25, data type: String)
                                                                                                                                                                                                                                                    CADENA'
                                                                                                                                                                                                                                                      Token(name: space, token type: Punctuation, line: 26, data type: String)
                                                                                                                                                                                                                                                      CADENA'
                                                                                                                                                                                                                                                        Token(name: space, token type: Punctuation, line: 26, data type: String)
                                                                                                                                                                                                                                                        CADENA'
                                                                                                                                                                                                                                                          Token(name: space, token type: Punctuation, line: 26, data type: String)
                                                                                                                                                                                                                                                          CADENA'
                                                                                                                                                                                                                                                            Token(name: french, token type: Identifier, line: 26, data type: String)
                                                                                                                                                                                                                                                            CADENA'
                                                                                                                                                                                                                                                              Token(name: -, token type: Operation, line: 26, data type: String)
                                                                                                                                                                                                                                                              CADENA'
                                                                                                                                                                                                                                                                Token(name: hens, token type: Identifier, line: 26, data type: String)
                                                                                                                                                                                                                                                                CADENA'
                                                                                                                                                                                                                                                                  Token(name: :, token type: Punctuation, line: 26, data type: String)
                                                                                                                                                                                                                                                                  CADENA'
                                                                                                                                                                                                                                                                    Token(name: space, token type: Punctuation, line: 26, data type: String)
                                                                                                                                                                                                                                                                    CADENA'
                                                                                                                                                                                                                                                                      Token(name: 3, token type: Constant, line: 26, data type: String)
                                                                                                                                                                                                                                                                      CADENA'
                                                                                                                                                                                                                                                                        Token(name: \n, token type: Punctuation, line: 26, data type: String)
                                                                                                                                                                                                                                                                        CADENA'
                                                                                                                                                                                                                                                                          Token(name: space, token type: Punctuation, line: 27, data type: String)
                                                                                                                                                                                                                                                                          CADENA'
                                                                                                                                                                                                                                                                            Token(name: space, token type: Punctuation, line: 27, data type: String)
                                                                                                                                                                                                                                                                            CADENA'
                                                                                                                                                                                                                                                                              Token(name: space, token type: Punctuation, line: 27, data type: String)
                                                                                                                                                                                                                                                                              CADENA'
                                                                                                                                                                                                                                                                                Token(name: golden, token type: Identifier, line: 27, data type: String)
                                                                                                                                                                                                                                                                                CADENA'
                                                                                                                                                                                                                                                                                  Token(name: -, token type: Operation, line: 27, data type: String)
                                                                                                                                                                                                                                                                                  CADENA'
                                                                                                                                                                                                                                                                                    Token(name: rings, token type: Identifier, line: 27, data type: String)
                                                                                                                                                                                                                                                                                    CADENA'
                                                                                                                                                                                                                                                                                      Token(name: :, token type: Punctuation, line: 27, data type: String)
                                                                                                                                                                                                                                                                                      CADENA'
                                                                                                                                                                                                                                                                                        Token(name: space, token type: Punctuation, line: 27, data type: String)
                                                                                                                                                                                                                                                                                        CADENA'
                                                                                                                                                                                                                                                                                          Token(name: 5, token type: Constant, line: 27, data type: String)
                                                                                                                                                                                                                                                                                          CADENA'
                                                                                                                                                                                                                                                                                            Token(name: \n, token type: Punctuation, line: 27, data type: String)
                                                                                                                                                                                                                                                                                            CADENA'
                                                                                                                                                                                                                                                                                              Token(name: space, token type: Punctuation, line: 28, data type: String)
                                                                                                                                                                                                                                                                                              CADENA'
                                                                                                                                                                                                                                                                                                Token(name: space, token type: Punctuation, line: 28, data type: String)
                                                                                                                                                                                                                                                                                                CADENA'
                                                                                                                                                                                                                                                                                                  Token(name: space, token type: Punctuation, line: 28, data type: String)
                                                                                                                                                                                                                                                                                                  CADENA'
                                                                                                                                                                                                                                                                                                    Token(name: partridges, token type: Identifier, line: 28, data type: String)
                                                                                                                                                                                                                                                                                                    CADENA'
                                                                                                                                                                                                                                                                                                      Token(name: :, token type: Punctuation, line: 28, data type: String)
                                                                                                                                                                                                                                                                                                      CADENA'
                                                                                                                                                                                                                                                                                                        Token(name: \n, token type: Punctuation, line: 28, data type: String)
                                                                                                                                                                                                                                                                                                        CADENA'
                                                                                                                                                                                                                                                                                                          Token(name: space, token type: Punctuation, line: 29, data type: String)
                                                                                                                                                                                                                                                                                                          CADENA'
                                                                                                                                                                                                                                                                                                            Token(name: space, token type: Punctuation, line: 29, data type: String)
                                                                                                                                                                                                                                                                                                            CADENA'
                                                                                                                                                                                                                                                                                                              Token(name: space, token type: Punctuation, line: 29, data type: String)
                                                                                                                                                                                                                                                                                                              CADENA'
                                                                                                                                                                                                                                                                                                                Token(name: space, token type: Punctuation, line: 29, data type: String)
                                                                                                                                                                                                                                                                                                                CADENA'
                                                                                                                                                                                                                                                                                                                  Token(name: space, token type: Punctuation, line: 29, data type: String)
                                                                                                                                                                                                                                                                                                                  CADENA'
                                                                                                                                                                                                                                                                                                                    Token(name: count, token type: Identifier, line: 29, data type: String)
                                                                                                                                                                                                                                                                                                                    CADENA'
                                                                                                                                                                                                                                                                                                                      Token(name: :, token type: Punctuation, line: 29, data type: String)
                                                                                                                                                                                                                                                                                                                      CADENA'
                                                                                                                                                                                                                                                                                                                        Token(name: space, token type: Punctuation, line: 29, data type: String)
                                                                                                                                                                                                                                                                                                                        CADENA'
                                                                                                                                                                                                                                                                                                                          Token(name: 1, token type: Constant, line: 29, data type: String)
                                                                                                                                                                                                                                                                                                                          CADENA'
                                                                                                                                                                                                                                                                                                                            Token(name: \n, token type: Punctuation, line: 29, data type: String)
                                                                                                                                                                                                                                                                                                                            CADENA'
                                                                                                                                                                                                                                                                                                                              Token(name: space, token type: Punctuation, line: 30, data type: String)
                                                                                                                                                                                                                                                                                                                              CADENA'
                                                                                                                                                                                                                                                                                                                                Token(name: space, token type: Punctuation, line: 30, data type: String)
                                                                                                                                                                                                                                                                                                                                CADENA'
                                                                                                                                                                                                                                                                                                                                  Token(name: space, token type: Punctuation, line: 30, data type: String)
                                                                                                                                                                                                                                                                                                                                  CADENA'
                                                                                                                                                                                                                                                                                                                                    Token(name: space, token type: Punctuation, line: 30, data type: String)
                                                                                                                                                                                                                                                                                                                                    CADENA'
                                                                                                                                                                                                                                                                                                                                      Token(name: space, token type: Punctuation, line: 30, data type: String)
                                                                                                                                                                                                                                                                                                                                      CADENA'
                                                                                                                                                                                                                                                                                                                                        Token(name: location, token type: Identifier, line: 30, data type: String)
                                                                                                                                                                                                                                                                                                                                        CADENA'
                                                                                                                                                                                                                                                                                                                                          Token(name: :, token type: Punctuation, line: 30, data type: String)
                                                                                                                                                                                                                                                                                                                                          CADENA'
                                                                                                                                                                                                                                                                                                                                            Token(name: space, token type: Punctuation, line: 30, data type: String)
                                                                                                                                                                                                                                                                                                                                            CADENA'
                                                                                                                                                                                                                                                                                                                                              Token(name: ", token type: Punctuation, line: 30, data type: String)
                                                                                                                                                                                                                                                                                                                                              CADENA'
                                                                                                                                                                                                                                                                                                                                                Token(name: a, token type: Identifier, line: 30, data type: String)
                                                                                                                                                                                                                                                                                                                                                CADENA'
                                                                                                                                                                                                                                                                                                                                                  Token(name: space, token type: Punctuation, line: 30, data type: String)
                                                                                                                                                                                                                                                                                                                                                  CADENA'
                                                                                                                                                                                                                                                                                                                                                    Token(name: pear, token type: Identifier, line: 30, data type: String)
                                                                                                                                                                                                                                                                                                                                                    CADENA'
                                                                                                                                                                                                                                                                                                                                                      Token(name: space, token type: Punctuation, line: 30, data type: String)
                                                                                                                                                                                                                                                                                                                                                      CADENA'
                                                                                                                                                                                                                                                                                                                                                        Token(name: tree, token type: Identifier, line: 30, data type: String)
                                                                                                                                                                                                                                                                                                                                                        CADENA'
                                                                                                                                                                                                                                                                                                                                                          Token(name: ", token type: Punctuation, line: 30, data type: String)
                                                                                                                                                                                                                                                                                                                                                          CADENA'
                                                                                                                                                                                                                                                                                                                                                            Token(name: \n, token type: Punctuation, line: 30, data type: String)
                                                                                                                                                                                                                                                                                                                                                            CADENA'
                                                                                                                                                                                                                                                                                                                                                              Token(name: space, token type: Punctuation, line: 31, data type: String)
                                                                                                                                                                                                                                                                                                                                                              CADENA'
                                                                                                                                                                                                                                                                                                                                                                Token(name: space, token type: Punctuation, line: 31, data type: String)
                                                                                                                                                                                                                                                                                                                                                                CADENA'
                                                                                                                                                                                                                                                                                                                                                                  Token(name: space, token type: Punctuation, line: 31, data type: String)
                                                                                                                                                                                                                                                                                                                                                                  CADENA'
                                                                                                                                                                                                                                                                                                                                                                    Token(name: turtle, token type: Identifier, line: 31, data type: String)
                                                                                                                                                                                                                                                                                                                                                                    CADENA'
                                                                                                                                                                                                                                                                                                                                                                      Token(name: -, token type: Operation, line: 31, data type: String)
                                                                                                                                                                                                                                                                                                                                                                      CADENA'
                                                                                                                                                                                                                                                                                                                                                                        Token(name: doves, token type: Identifier, line: 31, data type: String)
                                                                                                                                                                                                                                                                                                                                                                        CADENA'
                                                                                                                                                                                                                                                                                                                                                                          Token(name: :, token type: Punctuation, line: 31, data type: String)
                                                                                                                                                                                                                                                                                                                                                                          CADENA'
                                                                                                                                                                                                                                                                                                                                                                            Token(name: space, token type: Punctuation, line: 31, data type: String)
                                                                                                                                                                                                                                                                                                                                                                            CADENA'
                                                                                                                                                                                                                                                                                                                                                                              Token(name: two, token type: Identifier, line: 31, data type: String)
                                                                                                                                                                                                                                                                                                                                                                              CADENA'
                                                                                                                                                                                                                                                                                                                                                                                Token(name: \n, token type: Punctuation, line: 31, data type: String)
                                                                                                                                                                                                                                                                                                                                                                                CADENA'
                                                                                                                                                                                                                                                                                                                                                                                  ε
                              Token(name: ', token type: Punctuation, line: 32, data type: String)
                          TERM'
                            ε
                        EXP'
                          ε
                  BLOQUE'
                    Token(name: \n, token type: Punctuation, line: 32, data type: -)
                    INSTRUCCION
                      PUBLICAR
                        Token(name: publicar, token type: Keyword, line: 33, data type: -)
                        ESPACIO
                          Token(name: space, token type: Punctuation, line: 33, data type: -)
                          ESPACIO
                            ε
                        STRPARAM
                          STRING
                            Token(name: ', token type: Punctuation, line: 33, data type: String)
                            CADENA
                              Token(name: https, token type: Identifier, line: 33, data type: String)
                              CADENA'
                                Token(name: :, token type: Punctuation, line: 33, data type: String)
                                CADENA'
                                  Token(name: /, token type: Operation, line: 33, data type: String)
                                  CADENA'
                                    Token(name: /, token type: Operation, line: 33, data type: String)
                                    CADENA'
                                      Token(name: pokeapi, token type: Identifier, line: 33, data type: String)
                                      CADENA'
                                        Token(name: ., token type: Punctuation, line: 33, data type: String)
                                        CADENA'
                                          Token(name: co, token type: Identifier, line: 33, data type: String)
                                          CADENA'
                                            Token(name: /, token type: Operation, line: 33, data type: String)
                                            CADENA'
                                              Token(name: api, token type: Identifier, line: 33, data type: String)
                                              CADENA'
                                                Token(name: /, token type: Operation, line: 33, data type: String)
                                                CADENA'
                                                  Token(name: v2, token type: Identifier, line: 33, data type: String)
                                                  CADENA'
                                                    Token(name: /, token type: Operation, line: 33, data type: String)
                                                    CADENA'
                                                      Token(name: pokemon, token type: Identifier, line: 33, data type: String)
                                                      CADENA'
                                                        Token(name: /, token type: Operation, line: 33, data type: String)
                                                        CADENA'
                                                          Token(name: ditto, token type: Identifier, line: 33, data type: String)
                                                          CADENA'
                                                            ε
                            Token(name: ', token type: Punctuation, line: 33, data type: String)
                        ESPACIO
                          Token(name: space, token type: Punctuation, line: 33, data type: -)
                          ESPACIO
                            ε
                        STRPARAM
                          Token(name: body, token type: Identifier, line: 33, data type: String)
                        ESPACIO
                          ε
                        APIKEY
                          ε
                    BLOQUE'
                      Token(name: \n, token type: Punctuation, line: 33, data type: -)
                      INSTRUCCION
                        DECLARACION
                          Token(name: variable, token type: Keyword, line: 34, data type: -)
                          ESPACIO
                            Token(name: space, token type: Punctuation, line: 34, data type: -)
                            ESPACIO
                              ε
                          Token(name: f, token type: Identifier, line: 34, data type: String)
                          ESPACIO
                            Token(name: space, token type: Punctuation, line: 34, data type: -)
                            ESPACIO
                              ε
                          Token(name: =, token type: Operation, line: 34, data type: -)
                          ESPACIO
                            Token(name: space, token type: Punctuation, line: 34, data type: -)
                            ESPACIO
                              ε
                          EXP
                            TERM
                              FACTOR
                                STRING
                                  Token(name: ', token type: Punctuation, line: 34, data type: String)
                                  CADENA
                                    Token(name: h, token type: Identifier, line: 34, data type: String)
                                    CADENA'
                                      ε
                                  Token(name: ', token type: Punctuation, line: 34, data type: String)
                              TERM'
                                ε
                            EXP'
                              ε
                      BLOQUE'
                        ε
  CODIGO'
    ε
Token(name: a, token type: Identifier, line: 1, data type: Number, usage lines: [2, 3, 6, 6])
Token(name: b, token type: Identifier, line: 3, data type: Number)
Token(name: c, token type: Identifier, line: 4, data type: String)
Token(name: d, token type: Identifier, line: 5, data type: String)
Token(name: body, token type: Identifier, line: 12, data type: String, usage lines: [33])
Token(name: f, token type: Identifier, line: 34, data type: String)
Valido
```