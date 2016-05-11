#pragma once
#include "TTreeLink.h"
using namespace std;

class TTreeLink;

class TTree
{
	// Указатель на первый элемент дерева - "Корень"
	TTreeLink *pFirst;

	// Указатель на текущий элемент дерева
	TTreeLink *pCurr;

	// Стек для запоминания пути, который прошел pCurr и возврата по нему
	TStack <TTreeLink*> path;

public:

	TTree(TTreeLink *_pFirst = NULL) : path(100)
	{
		if (_pFirst != 0)
			pFirst = pCurr = _pFirst;
		else
		{
			pCurr = pFirst;
		}
	}

	~TTree(){}

	//--------------------------------------------
	// Функции для доступа и изменения BattleField

	int GetBattleField(int i);

	void SetBattleField(int num);

	//--------------------------------------------
	// Функции навигации по дереву

	// Перейти по указателю pNext
	void GoNextLink();

	// Перейти по указателю pDown
	void GoDownLink();

	// Вернуться к преддущему положению
	void GoPrevLink();

	// Перейти к "Корню"
	void GoFirstLink();

	// (4) Функции добавления вернин в дереве
	void IncNextLine(int _str);

	void IncNextSection(int _str);

	void IncDownLine(int _str);

	void IncDownSection(int _str);

	// (2) Функции удаления вершин в дереве
	void DelNextLine();

	void DelDownLine();

	//--------------------------------------------
	// Функции для обхода дерева
	void Reset();

	void GoNext();

	bool IsEnd();

	//--------------------------------------------
	// Функции для работы с файлами

	TTreeLink* ReadSection(ifstream &ifs);

	void ReadFile(char* fname);

	void SaveSection(TTreeLink*p, ofstream &ofs);

	void SaveText(char* fname);

	//--------------------------------------------
	// Функция возвращающая указатель на pFirst
	TTreeLink* GetpFirst();

	// (2) Функции прощитывающие дерево решений 
	void Allfilling();

	void filling(TTreeLink* p, int count);

	// Функция переводящая int массив в одно число
	int ToInt(int *tmp);

	//--------------------------------------------
	// Функция добавляющая вес вершине взависимости от итога игры
	void IncWeight(int mn);

	// Функция убирающая из стека оду вершину
	void DontPush();

	// Функция выбирающая куда ходить Боту
	void BotMoveTree(int &x, int &y);
};
