#ifndef TASK_H
#define TASK_H
using namespace std;
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <string.h>


//��������� �������� ������� ��������� (����� �����).
int eval(char * expr);

//���� C-������. ������������� � ��� ��� ��������� ��������� ����� � ��������. ������� ������ ���������� ���������� ����������� �����.
int to_lower(char * str);

//������� ������ ��������� ������� � ������ ������, ���������� ���� �� ���� ����� �����.
char first_gossip(char * str);

//���� ������ � �������. ��������� �������� strtok, ������������ �� ������� ��� ����� ������.
void print_all_words(char* str );

//������� ������ ���������� ������� � ������ ������.
int last_space(char* str);

//��������� ���������� ��������� ������ s2 � ������ s1
int count_subs(char* s1 , char * s2);

//������� �� ������ s1 ��� ��������� ������ s2.
void delete_all_subs(char* s1, char * s2);

//�������� ������� �� first �� last
void print(const char * first, const char * last);

//������������ ��� ����� ������.
void print_numbers(char *str);

//��������� ������ �����������, �������� ������� ��� ������������ � ����������� ��������.
void swap_min_max(double *arr, int n);

//��� ������ ����� ����� � ������ ����������� ���������.�������� ������� ��� ������ � ������ ��������.
void swap_halves(int *arr, int n);


#endif TASK_H

