#include <map>
std::map<int, std::map<char, int>> transitionTableDFA = {
    {0, {{'s', 1}, {'i', 2}, {'v', 3}, {'a', 2}, {'r', 2}, {'b', 4}, {'l', 2}, {'e', 5}, {'n', 2}, {'t', 2}, {'o', 11}, {'c', 6}, {'f', 7}, {'p', 8}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 13}, {'0', 10}, {'1', 10}, {'2', 10}, {'3', 10}, {'4', 10}, {'5', 10}, {'6', 10}, {'7', 10}, {'8', 10}, {'9', 10}, {'_', 2}, {'*', 12}, {'/', 12}, {'<', 12}, {'>', 12}, {'!', 12}, {'\n', 13}, {' ', 13}, {'"', 13}, {'(', 13}, {')', 13}, {',', 13}, {'#', 13}, {'.', 13}, {':', 13}, {'=', 14}, {'|', 15}, {'&', 16}, {'+', 17}, {'-', 17}}},
    {1, {{'s', 2}, {'i', 18}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {2, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {3, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 19}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {4, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 20}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {5, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 21}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {6, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 22}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {7, {{'s', 2}, {'i', 23}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {8, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 24}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {10, {{'0', 10}, {'1', 10}, {'2', 10}, {'3', 10}, {'4', 10}, {'5', 10}, {'6', 10}, {'7', 10}, {'8', 10}, {'9', 10}}},
    {11, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 27}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}}},
    {14, {{'=', 29}}},
    {15, {{'|', 30}}},
    {16, {{'&', 31}}},
    {17, {{'0', 10}, {'1', 10}, {'2', 10}, {'3', 10}, {'4', 10}, {'5', 10}, {'6', 10}, {'7', 10}, {'8', 10}, {'9', 10}}},
    {18, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 32}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {19, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 33}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {20, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 34}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {21, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 35}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {22, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 36}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {23, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 37}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {24, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 38}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {27, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 40}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {32, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 43}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {33, {{'s', 2}, {'i', 44}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {34, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 45}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {35, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 46}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {36, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 47}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {37, {{'s', 48}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {38, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 49}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {40, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 50}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {43, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {44, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 53}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {45, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 54}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {46, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 55}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {47, {{'s', 2}, {'i', 56}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {48, {{'s', 2}, {'i', 57}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {49, {{'s', 2}, {'i', 58}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {50, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 59}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {53, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 63}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {54, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 64}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {55, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 65}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {56, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 66}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {57, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {58, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 67}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {59, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 68}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {63, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 71}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {64, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {65, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 72}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {66, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 73}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {67, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 74}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {68, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 75}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {71, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 78}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {72, {{'s', 79}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {73, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {74, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 80}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {75, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {78, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {79, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}},
    {80, {{'s', 2}, {'i', 2}, {'v', 2}, {'a', 2}, {'r', 2}, {'b', 2}, {'l', 2}, {'e', 2}, {'n', 2}, {'t', 2}, {'o', 2}, {'c', 2}, {'f', 2}, {'p', 2}, {'u', 2}, {'m', 2}, {'d', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'w', 2}, {'x', 2}, {'y', 2}, {'z', 2}, {'?', 2}, {'0', 2}, {'1', 2}, {'2', 2}, {'3', 2}, {'4', 2}, {'5', 2}, {'6', 2}, {'7', 2}, {'8', 2}, {'9', 2}, {'_', 2}}}
};