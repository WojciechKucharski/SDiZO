#pragma once
#pragma warning(disable:4996)
#ifndef HEAD_HPP
#define HEAD_HPP
#endif
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <windows.h>
#include <stdlib.h> 
#include <time.h>
#include <cmath>
#include <ctime>

using namespace std;

void cont(); 

int read(vector <float>*);
int readA(vector <float>*, string);
void write(vector<float>*);
void show(vector<float>*);
void writeplot(vector<float>*, string);

int InterfaceSelect(int);

void choices(int,vector <float>*);

void generate(vector<float>*);
void generateA2(vector<float>*, int);
void generateA(vector<float>*, float, float, float);

void stats(vector<float>*);

void bubble(vector<float>*);
double bubbleA(vector<float>*, bool);


void qsort(vector<float>*);
double qsortA(vector<float>*, int, int, bool, int);

void hsort(vector<float>*);
double hsortA(vector<float>*, bool);

void csort(vector<float>*);
double csortA(vector<float>*, bool);

void analyze(vector<float>*);

int plot(vector <float>*);