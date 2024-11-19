lexer grammar Lexer;

// Reglas de tokens
IDENTIFIER: [a-zA-Z_][a-zA-Z_]*;
CONSTANT: [+-]?[0-9]+;
KEYWORD: 'si' | 'variable' | 'entonces' | 'sino' | 'finsi' | 'publicar' | 'obtener' | 'cambiar' | 'borrar';
PUNCTUATION: [\n(),# "]; // Incluye el espacio y la comilla doble como puntuación
OPERATOR: '+' | '-' | '=' | '*' | '/' | '==' | '**' | '||' | '&&' | '<' | '>' | '!' | '?';
STRING: '\'' .*? '\''; // Captura cualquier carácter entre comillas simples, excepto nuevas líneas

// Regla para manejar el orden de reconocimiento
fragment DIGIT: [0-9];
