#include "TTree.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//--------------------------------------------
int TTree::GetBattleField(int i)
{
	return(pCurr->battlefield[i]);
}

void TTree::SetBattleField(int num)
{
	pCurr->battlefield[num] = 0;
}

//--------------------------------------------
void TTree::GoNextLink()

{
	if (pCurr != NULL)
		if (pCurr->pNext != NULL)
		{
			path.Push(pCurr);
			pCurr = pCurr->pNext;
		}
}

void TTree::GoDownLink()
{
	if (pCurr != NULL)
		if (pCurr->pDown != NULL)
		{
			path.Push(pCurr);
			pCurr = pCurr->pDown;
		}
}

void TTree::GoPrevLink()
{
	if (!path.IsEmpty())
	{
		pCurr = path.Pop();
	}
}

void TTree::GoFirstLink()
{
	while (!path.IsEmpty())
	{
		path.Pop();
	}
	pCurr = pFirst;
}

//--------------------------------------------
void TTree::IncNextLine(int _str)
{
	if (pCurr != NULL)
	{
		TTreeLink *tmp = new TTreeLink(150, _str);
		tmp->pNext = pCurr->pNext;
		pCurr->pNext = tmp;
	}
}

void TTree::IncNextSection(int _str)
{
	if (pCurr != NULL)
	{
		TTreeLink *tmp = new TTreeLink(150, _str);
		tmp->pDown = pCurr->pNext;
		pCurr->pNext = tmp;
	}
}

void TTree::IncDownLine(int _str)
{
	if (pCurr != NULL)
	{
		TTreeLink *tmp = new TTreeLink(150, _str);
		tmp->pNext = pCurr->pDown;
		pCurr->pDown = tmp;
	}
}

void TTree::IncDownSection(int _str)
{
	if (pCurr != NULL)
	{
		TTreeLink *tmp = new TTreeLink(150, _str);
		tmp->pDown = pCurr->pDown;
		pCurr->pDown = tmp;
	}
}

void TTree::DelNextLine()
{
	if ((pCurr != NULL) && (pCurr->pNext != NULL))
	{
		TTreeLink *tmp = pCurr->pNext;
		pCurr->pNext = pCurr->pNext->pNext;
		delete tmp;
	}
}

void TTree::DelDownLine()
{
	if ((pCurr != NULL) && (pCurr->pDown != NULL))
	{
		TTreeLink *tmp = pCurr->pDown;
		pCurr->pDown = pCurr->pDown->pNext;
		delete tmp;
	}
}

//--------------------------------------------
void TTree::Reset()
{
	pCurr = pFirst;
	path.Clear();

	if (pCurr->pNext != NULL)
		path.Push(pCurr->pNext);
	if (pCurr->pDown != NULL)
		path.Push(pCurr->pDown);
}

void TTree::GoNext()
{
	if (!path.IsEmpty())
	{
		pCurr = path.Pop();

		if (pCurr->pNext != NULL)
			path.Push(pCurr->pNext);
		if (pCurr->pDown != NULL)
			path.Push(pCurr->pDown);
	}
}

bool TTree::IsEnd()
{
	return (path.IsEmpty());
}

//--------------------------------------------
TTreeLink* TTree::ReadSection(ifstream &ifs)
{
	TTreeLink* pHead = new TTreeLink; //"!"
	TTreeLink* pTmp = pHead;
	char flagC;
	int weight, position;
	string str;

	bool flag = true;

	while (!ifs.eof())
	{
		getline(ifs, str);

		if (str == "}")
			break;
		else
			if (str == "{")
				pTmp->pDown = ReadSection(ifs);
			else
				if (str == "/")
				{
					ifs >> weight;
					ifs >> position;
					getline(ifs, str);
					TTreeLink* q = new TTreeLink(weight, position);

					pTmp->pNext = q;
					pTmp = q;

					if (flag/*(pHead->pDown == NULL) && (pHead->pNext == NULL)*/)
					{
						//pTmp = pHead->pNext;
						delete pHead;
						pHead = pTmp;
						flag = false;
					}
				}

	}

	return(pHead);
}

void TTree::ReadFile(char* fname)
{
	ifstream ifs(fname);
	pCurr = pFirst = ReadSection(ifs);
}

void TTree::SaveSection(TTreeLink*p, ofstream& ofs)
{
	if (p != NULL)
	{
		int flag = 0;
		ofs << "/" << endl << p->weight << ' ' << p->position << endl;
		if (p->pDown != 0)
		{
			ofs << "{" << endl;
			flag = 1;
		}
		SaveSection(p->pDown, ofs);
		if (flag == 1) ofs << "}" << endl;
		SaveSection(p->pNext, ofs);
	}
}

void TTree::SaveText(char* fname)
{
	ofstream ofs(fname);
	SaveSection(pFirst, ofs);
}

//--------------------------------------------
TTreeLink* TTree::GetpFirst()
{
	return(pFirst);
}

void TTree::Allfilling()
{
	filling(pFirst, 0);
}

void TTree::filling(TTreeLink* p, int count)
{
	int arr[9]; // ћассив под новое position

	for (int i = 0; i < 9; i++)
	{
		arr[i] = p->battlefield[i];
	}

	for (int i = 0; i < 9; i++) // i < n - глубина просчета дерева
	{
		if (arr[i] == 1)
		{
			pCurr = p;
			if (count % 2 == 0)
				arr[i] = 2;
			else
				arr[i] = 3;

			IncDownLine(ToInt(arr));

			arr[i] = 1;

			if (p->pDown != NULL)
				filling(p->pDown, count + 1);
		}
	}
}

int TTree::ToInt(int *tmp)
{
	int val = 0;
	for (int i = 0; i < 9; i++)
	{
		val *= 10;
		val += tmp[i];
	}
	return val;
}

//--------------------------------------------
void TTree::IncWeight(int mn)
{
	pCurr->weight += mn;

	if (pCurr->weight < 1)
		pCurr->weight = 1;
}

void TTree::DontPush()
{
	path.Pop();
}

void TTree::BotMoveTree(int &x, int &y)
{
	TTreeLink *tmp;
	int sum = 0;
	srand(time(0));

	// «адавание рандома относительно веса
	for (tmp = pCurr->pDown; tmp != NULL; tmp = tmp->pNext) 
		sum += tmp->weight;
	int rd = (rand() % sum) + 1;

	sum = 0;
	for (tmp = pCurr->pDown; tmp->pNext != NULL; tmp = tmp->pNext)
	{
		sum += tmp->weight;
		if (rd <= sum)
		{
			break;
		}
	}

	sum = tmp->position - pCurr->position;

	int count = 1;
	while (sum % 10 == 0)
	{
		count++;
		sum = sum / 10;
	}

	if (count == 1) { x = 2; y = 2; }
	else if (count == 2) { x = 2; y = 1; }
	else if (count == 3) { x = 2; y = 0; }
	else if (count == 4) { x = 1; y = 2; }
	else if (count == 5) { x = 1; y = 1; }
	else if (count == 6) { x = 1; y = 0; }
	else if (count == 7) { x = 0; y = 2; }
	else if (count == 8) { x = 0; y = 1; }
	else if (count == 9) { x = 0; y = 0; }
}
