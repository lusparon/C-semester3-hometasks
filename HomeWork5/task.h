#ifndef TASK_H
#define TASK_H
using namespace std;
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <string.h>


//Посчитать значение данного выражения (целое число).
int eval(char * expr);

//Дана C-строка. Преобразовать в ней все прописные латинские буквы в строчные. Функция должна возвращать количество выполненных замен.
int to_lower(char * str);

//найдите первую латинскую гласную в данной строке, содержащей хотя бы одну такую букву.
char first_gossip(char * str);

//Дана строка с текстом. Пользуясь функцией strtok, распечатайте на консоль все слова текста.
void print_all_words(char* str );

//Найдите индекс последнего пробела в данной строке.
int last_space(char* str);

//Вычислите количество вхождений строки s2 в строку s1
int count_subs(char* s1 , char * s2);

//Удалите из строки s1 все вхождения строки s2.
void delete_all_subs(char* s1, char * s2);

//печатает символы от first до last
void print(const char * first, const char * last);

//Распечатайте все числа строки.
void print_numbers(char *str);

//Пользуясь только указателями, поменять местами его максимальный и минимальный элементы.
void swap_min_max(double *arr, int n);

//Дан массив целых чисел с чётным количеством элементов.Поменять местами его первую и вторую половины.
void swap_halves(int *arr, int n);


#endif TASK_H

