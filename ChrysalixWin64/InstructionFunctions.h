﻿#pragma once

#include <iostream>
#include <cmath>
#include <algorithm>
#include "windows.h"

#include "Helpers.h"

typedef void (*func)(Machine* m, Instruction* i, bool prevalidate, bool prego);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Прототипы функций - инструкций
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void nop(Machine* m, Instruction* i, bool prevalidate, bool prego);
void end(Machine* m, Instruction* i, bool prevalidate, bool prego);
void pause(Machine* m, Instruction* i, bool prevalidate, bool prego);
void sleep(Machine* m, Instruction* i, bool prevalidate, bool prego);
void var(Machine* m, Instruction* i, bool prevalidate, bool prego);
void print(Machine* m, Instruction* i, bool prevalidate, bool prego);
void free(Machine* m, Instruction* i, bool prevalidate, bool prego);
void label(Machine* m, Instruction* i, bool prevalidate, bool prego);
void jump(Machine* m, Instruction* i, bool prevalidate, bool prego);
void input(Machine* m, Instruction* i, bool prevalidate, bool prego);
void change(Machine* m, Instruction* i, bool prevalidate, bool prego);
void to(Machine* m, Instruction* i, bool prevalidate, bool prego);
void calc(Machine* m, Instruction* i, bool prevalidate, bool prego);
void newtemp(Machine* m, Instruction* i, bool prevalidate, bool prego);
void forget(Machine* m, Instruction* i, bool prevalidate, bool prego);
void tcount(Machine* m, Instruction* i, bool prevalidate, bool prego);
void isset(Machine* m, Instruction* i, bool prevalidate, bool prego);
void typeof(Machine* m, Instruction* i, bool prevalidate, bool prego);
void comp(Machine* m, Instruction* i, bool prevalidate, bool prego);
void logic(Machine* m, Instruction* i, bool prevalidate, bool prego);
void jif(Machine* m, Instruction* i, bool prevalidate, bool prego);
void jifnot(Machine* m, Instruction* i, bool prevalidate, bool prego);
void dlabel(Machine* m, Instruction* i, bool prevalidate, bool prego);
void swap(Machine* m, Instruction* i, bool prevalidate, bool prego);
void arr(Machine* m, Instruction* i, bool prevalidate, bool prego);
void vtoarr(Machine* m, Instruction* i, bool prevalidate, bool prego);
void pushb(Machine* m, Instruction* i, bool prevalidate, bool prego);
void popb(Machine* m, Instruction* i, bool prevalidate, bool prego);
void pushf(Machine* m, Instruction* i, bool prevalidate, bool prego);
void popf(Machine* m, Instruction* i, bool prevalidate, bool prego);
void erase(Machine* m, Instruction* i, bool prevalidate, bool prego);
void insrt(Machine* m, Instruction* i, bool prevalidate, bool prego);
void clear(Machine* m, Instruction* i, bool prevalidate, bool prego);
void sizearr(Machine* m, Instruction* i, bool prevalidate, bool prego);
void getval(Machine* m, Instruction* i, bool prevalidate, bool prego);
void setval(Machine* m, Instruction* i, bool prevalidate, bool prego);
void slice(Machine* m, Instruction* i, bool prevalidate, bool prego);
void merge(Machine* m, Instruction* i, bool prevalidate, bool prego);
void sort(Machine* m, Instruction* i, bool prevalidate, bool prego);
void unique(Machine* m, Instruction* i, bool prevalidate, bool prego);
void reverse(Machine* m, Instruction* i, bool prevalidate, bool prego);
void equal(Machine* m, Instruction* i, bool prevalidate, bool prego);
void iexist(Machine* m, Instruction* i, bool prevalidate, bool prego);
void in(Machine* m, Instruction* i, bool prevalidate, bool prego);
void inall(Machine* m, Instruction* i, bool prevalidate, bool prego);
void rin(Machine* m, Instruction* i, bool prevalidate, bool prego);
void rinall(Machine* m, Instruction* i, bool prevalidate, bool prego);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Массив с функциями - инструкциями
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
func functions[] = {
	&nop,
	&end,
	&pause,
	&sleep,
	&var,
	&print,
	&free,
	&label,
	&jump,
	&input,
	&change,
	&to,
	&calc,
	&newtemp,
	&forget,
	&tcount,
	&isset,
	&typeof,
	&comp,
	&logic,
	&jif,
	&jifnot,
	&dlabel,
	&swap,
	&arr,
	&vtoarr,
	&pushb,
	&popb,
	&pushf,
	&popf,
	&erase,
	&insrt,
	&clear,
	&sizearr,
	&getval,
	&setval,
	&slice,
	&merge,
	&sort,
	&unique,
	&reverse,
	&equal,
	&iexist,
	&in,
	&inall,
	&rin,
	&rinall
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// NOP
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void nop(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"NOP";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 0);
	}
	else {
		//Ничего
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		++(*m).instruct_number;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// END
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void end(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"END";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 1);
	}
	else {
		//Ничего
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		(*m).ret_data = getValue(&(*i).parameters[0], &(*m).heap);
		(*m).instruct_number = -1;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PAUSE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pause(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"PAUSE";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 0);
	}
	else {
		//Ничего
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		system("pause");
		++(*m).instruct_number;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SLEEP
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sleep(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"SLEEP";
		if (prevalidate) {
			checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 1);
		}
	}
	else {
		//Ничего
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		Sleep((DWORD)getValue(&(*i).parameters[0], &(*m).heap).toUNTG().getUInt());
		++(*m).instruct_number;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// VAR
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void var(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"VAR";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 2);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");
	}
	else {
		checkExistValue(&(*i).parameters[0], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		(*m).heap[(*i).parameters[0].getWStr()] = getValue(&(*i).parameters[1], &(*m).heap);
		++(*m).instruct_number;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PRINT
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void print(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"PRINT";
		checkParameterCount(MIN, (int)(*i).parameters.size(), m, &name, 0, 1);
	}
	else {
		//Ничего
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		for (Var& v : (*i).parameters)
		{
			std::wcout << getValue(&v, &(*m).heap);
		}
		++(*m).instruct_number;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FREE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void free(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"FREE";
		checkParameterCount(MIN, (int)(*i).parameters.size(), m, &name, 0, 1);
		for (Var& i : (*i).parameters)
		{
			requiredVar(&i, m, &name, i.toSTR().getWStr());
		}
	}
	else {
		for (Var& i : (*i).parameters)
		{
			checkNotExistValue(&i, m);
		}
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		for (Var& v : (*i).parameters)
		{
			(*m).heap.erase(v.getWStr());
		}
		++(*m).instruct_number;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// LABEL
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void label(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"LABEL";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 1);
		requiredLabel(&(*i).parameters[0], m, &name, L"Единственный");
		checkExistLabel(&(*i).parameters[0], m);
	}
	else {
		//Ничего
	}

	if (prego) {
		(*m).jmp_pointers[(*i).parameters[0].toSTR().getWStr()] = (*m).instruct_number + 1;
		++(*m).instruct_number;
	}
	else {
		++(*m).instruct_number;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// JUMP
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void jump(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"JUMP";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 1);
	}
	else {
		//Ничего
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		(*m).instruct_number = (int)getLabel(&(*i).parameters[0], &(*m).jmp_pointers).toUNTG().getUInt();
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// INPUT
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void input(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"INPUT";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 1);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");
	}
	else {
		checkNotExistValue(&(*i).parameters[0], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		std::wstring str;
		getline(std::wcin, str);
		(*m).heap[(*i).parameters[0].getWStr()] = Var(str);
		++(*m).instruct_number;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CHANGE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void change(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"CHANGE";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 2);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");
	}
	else {
		checkNotExistValue(&(*i).parameters[0], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		(*m).heap[(*i).parameters[0].getWStr()] = getValue(&(*i).parameters[1], &(*m).heap);
		++(*m).instruct_number;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TO
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void to(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"TO";
		int v[2]{ 2, 3 };
		checkParameterCount(VARIANTS, (int)(*i).parameters.size(), m, &name, 0, 0, nullptr, v);
		requiredVar(&(*i).parameters[1], m, &name, L"Второй");
	}
	else {
		checkNotExistValue(&(*i).parameters[1], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		std::wstring type = getValue(&(*i).parameters[0], &(*m).heap).toSTR().getWStr();

		if ((*i).parameters.size() == 2) {
			if (type == L"NTG" || type == L"ntg") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[1], &(*m).heap).toNTG();
			}
			else if (type == L"UNTG" || type == L"untg") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[1], &(*m).heap).toUNTG();
			}
			else if (type == L"DBL" || type == L"dbl") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[1], &(*m).heap).toDBL();
			}
			else if (type == L"CHR" || type == L"chr") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[1], &(*m).heap).toCHR();
			}
			else if (type == L"UCHR" || type == L"uchr") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[1], &(*m).heap).toUCHR();
			}
			else if (type == L"BLN" || type == L"bln") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[1], &(*m).heap).toBLN();
			}
			else if (type == L"STR" || type == L"str") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[1], &(*m).heap).toSTR();
			}
			else if (type == L"ARR" || type == L"arr") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[1], &(*m).heap).toARR();
			}
			else {
				throw std::wstring{ L"Тип данных " + type + L" неизвестен\n" };
			}
		}
		else if ((*i).parameters.size() == 3) {
			if (type == L"NTG" || type == L"ntg") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[2], & (*m).heap).toNTG();
			}
			else if (type == L"UNTG" || type == L"untg") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[2], &(*m).heap).toUNTG();
			}
			else if (type == L"DBL" || type == L"dbl") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[2], &(*m).heap).toDBL();
			}
			else if (type == L"CHR" || type == L"chr") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[2], &(*m).heap).toCHR();
			}
			else if (type == L"UCHR" || type == L"uchr") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[2], &(*m).heap).toUCHR();
			}
			else if (type == L"BLN" || type == L"bln") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[2], &(*m).heap).toBLN();
			}
			else if (type == L"STR" || type == L"str") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[2], &(*m).heap).toSTR();
			}
			else if (type == L"ARR" || type == L"arr") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[2], &(*m).heap).toARR();
			}
			else {
				throw std::wstring{ L"Тип данных " + type + L" неизвестен\n" };
			}
		}
		++(*m).instruct_number;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CALC
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calc(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"CALC";
		int v[2]{ 2, 4 };
		checkParameterCount(RANGE, (int)(*i).parameters.size(), m, &name, 0, 0, v);
		requiredVar(&(*i).parameters[1], m, &name, L"Второй");

	}
	else {
		checkNotExistValue(&(*i).parameters[1], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		std::wstring type = getValue(&(*i).parameters[0], &(*m).heap).toSTR().getWStr();
		if (type != L"+"
			&& type != L"-"
			&& type != L"*"
			&& type != L"/"
			&& type != L"%"
			&& type != L"^"
			&& type != L"INC"
			&& type != L"DEC"
			&& type != L"LOG"
			&& type != L"LN"
			&& type != L"FACT"
			&& type != L"ROOT"
			&& type != L"inc"
			&& type != L"dec"
			&& type != L"log"
			&& type != L"ln"
			&& type != L"fact"
			&& type != L"root") {
			throw std::wstring{ L"Математическая операция " + type + L" неизвестна\n" };
		}
		if ((*i).parameters.size() == 2) {
			if (type == L"INC" || type == L"inc") {
				(*m).heap[(*i).parameters[1].getWStr()] += Var(1);
			}
			else if (type == L"DEC" || type == L"dec") {
				(*m).heap[(*i).parameters[1].getWStr()] -= Var(1);
			}
			else if (type == L"FACT" || type == L"fact") {
				int fact = (int)(*m).heap[(*i).parameters[1].getWStr()].toUNTG().getUInt();
				unsigned long long int result = 1;
				for (int i = 1; i <= fact; ++i) {
					result *= i;
				}
				(*m).heap[(*i).parameters[1].getWStr()] = Var(result);
			}
			else if (type == L"LN" || type == L"ln") {
				(*m).heap[(*i).parameters[1].getWStr()] = Var(log((*m).heap[(*i).parameters[1].getWStr()].toDBL().getDouble()));
			}
			else {
				throw std::wstring{ L"Математическая операция " + type + L" принимает 2 и больше параметров\n" };
			}
		}
		if ((*i).parameters.size() == 3) {
			if (type == L"INC" || type == L"inc") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[2], &(*m).heap) + Var(1);
			}
			else if (type == L"DEC" || type == L"dec") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[2], &(*m).heap) - Var(1);
			}
			else if (type == L"FACT" || type == L"fact") {
				long long int fact = getValue(&(*i).parameters[2], &(*m).heap).toUNTG().getUInt();
				unsigned long long int result = 1;
				for (int i = 1; i <= fact; ++i) {
					result *= i;
				}
				(*m).heap[(*i).parameters[1].getWStr()] = Var(result);
			}
			else if (type == L"LN" || type == L"ln") {
				(*m).heap[(*i).parameters[1].getWStr()] = Var(log(getValue(&(*i).parameters[2], &(*m).heap).toDBL().getDouble()));
			}
			else if (type == L"+") {
				(*m).heap[(*i).parameters[1].getWStr()] += getValue(&(*i).parameters[2], &(*m).heap);
			}
			else if (type == L"-") {
				(*m).heap[(*i).parameters[1].getWStr()] -= getValue(&(*i).parameters[2], &(*m).heap);
			}
			else if (type == L"*") {
				(*m).heap[(*i).parameters[1].getWStr()] *= getValue(&(*i).parameters[2], &(*m).heap);
			}
			else if (type == L"/") {
				Var param = getValue(&(*i).parameters[2], &(*m).heap);
				if (param == Var(0)) {
					throw std::wstring{ L"Деление на 0. Параметр " + (*i).parameters[2].toSTR().getWStr() + L" равен нулю\n"};
				}
				(*m).heap[(*i).parameters[1].getWStr()] /= getValue(&(*i).parameters[2], &(*m).heap);
			}
			else if (type == L"%") {
				Var param = getValue(&(*i).parameters[2], &(*m).heap);
				if (param == Var(0)) {
					throw std::wstring{ L"Деление на 0. Параметр " + (*i).parameters[2].toSTR().getWStr() + L" равен нулю\n" };
				}
				(*m).heap[(*i).parameters[1].getWStr()] %= getValue(&(*i).parameters[2], &(*m).heap);
			}
			else if (type == L"^") {
				(*m).heap[(*i).parameters[1].getWStr()] = Var(pow(getValue(&(*i).parameters[1], &(*m).heap).toDBL().getDouble(), getValue(&(*i).parameters[2], &(*m).heap).toDBL().getDouble()));
			}
			else if (type == L"ROOT" || type == L"root") {
				(*m).heap[(*i).parameters[1].getWStr()] = Var(pow(getValue(&(*i).parameters[1], &(*m).heap).toDBL().getDouble(), 1.0 / getValue(&(*i).parameters[2], &(*m).heap).toDBL().getDouble()));
			}
			else if (type == L"LOG" || type == L"log") {
				(*m).heap[(*i).parameters[1].getWStr()] = log(getValue(&(*i).parameters[1], &(*m).heap).toDBL().getDouble()) / log(getValue(&(*i).parameters[2], &(*m).heap).toDBL().getDouble());

			}
		}
		if ((*i).parameters.size() == 4) {
			if (type == L"+") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[2], &(*m).heap) + getValue(&(*i).parameters[3], &(*m).heap);
			}
			else if (type == L"-") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[2], &(*m).heap) - getValue(&(*i).parameters[3], &(*m).heap);
			}
			else if (type == L"*") {
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[2], &(*m).heap) * getValue(&(*i).parameters[3], &(*m).heap);
			}
			else if (type == L"/") {
				Var param = getValue(&(*i).parameters[3], &(*m).heap);
				if (param == Var(0)) {
					throw std::wstring{ L"Деление на 0. Параметр " + (*i).parameters[3].toSTR().getWStr() + L" равен нулю\n" };
				}
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[2], &(*m).heap) / getValue(&(*i).parameters[3], &(*m).heap);
			}
			else if (type == L"%") {
				Var param = getValue(&(*i).parameters[3], &(*m).heap);
				if (param == Var(0)) {
					throw std::wstring{ L"Деление на 0. Параметр " + (*i).parameters[3].toSTR().getWStr() + L" равен нулю\n" };
				}
				(*m).heap[(*i).parameters[1].getWStr()] = getValue(&(*i).parameters[2], &(*m).heap) % getValue(&(*i).parameters[3], &(*m).heap);
			}
			else if (type == L"^") {
				(*m).heap[(*i).parameters[1].getWStr()] = Var(pow(getValue(&(*i).parameters[2], &(*m).heap).toDBL().getDouble(), getValue(&(*i).parameters[3], &(*m).heap).toDBL().getDouble()));
			}
			else if (type == L"ROOT" || type == L"root") {
				(*m).heap[(*i).parameters[1].getWStr()] = Var(pow(getValue(&(*i).parameters[2], &(*m).heap).toDBL().getDouble(), 1.0 / getValue(&(*i).parameters[3], &(*m).heap).toDBL().getDouble()));
			}
			else if (type == L"LOG" || type == L"log") {
				(*m).heap[(*i).parameters[1].getWStr()] = log(getValue(&(*i).parameters[2], &(*m).heap).toDBL().getDouble()) / log(getValue(&(*i).parameters[3], &(*m).heap).toDBL().getDouble());

			}
			else {
				throw std::wstring{ L"Математическая операция " + type + L" принимает до 3 параметров\n" };
			}
		}

		++(*m).instruct_number;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// NEWTEMP
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void newtemp(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"NEWTEMP";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 1);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		int start = (*m).tmp_count;
		(*m).tmp_count += (int)getValue(&(*i).parameters[0], & (*m).heap).toUNTG().getUInt();
		for (unsigned int it = start; it < (*m).tmp_count; ++it) {
			(*m).heap[L"$" + std::to_wstring(it)] = Var();
		}
		++(*m).instruct_number;
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FORGET
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void forget(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"FORGET";
		int v[2]{ 0, 1 };
		checkParameterCount(VARIANTS, (int)(*i).parameters.size(), m, &name, 0, 0, nullptr, v);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		if ((*i).parameters.size() == 0) {
			int start = (*m).tmp_count - 1;
			(*m).tmp_count = 0;
			for (int it = start; it >= (int)(*m).tmp_count; --it) {
				(*m).heap.erase(L"$" + std::to_wstring(it));
			}
		}
		else if ((*i).parameters.size() == 1) {
			int start = (*m).tmp_count - 1;
			(*m).tmp_count -= (int)getValue(&(*i).parameters[0], &(*m).heap).toUNTG().getUInt();
			for (int it = start; it >= (int)(*m).tmp_count; --it) {
				(*m).heap.erase(L"$" + std::to_wstring(it));
			}
		}
		++(*m).instruct_number;
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TCOUNT
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void tcount(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"TCOUNT";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 1);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");
	}
	else {
		checkNotExistValue(&(*i).parameters[0], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		(*m).heap[(*i).parameters[0].toSTR().getWStr()] = Var((*m).tmp_count);
		++(*m).instruct_number;
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ISSET
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void isset(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"ISSET";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 2);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");
		requiredVar(&(*i).parameters[1], m, &name, L"Второй");
	}
	else {
		checkNotExistValue(&(*i).parameters[0], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		if ((*m).heap.find((*i).parameters[1].toSTR().getWStr()) != (*m).heap.end()) {
			(*m).heap[(*i).parameters[0].toSTR().getWStr()] = Var(true);
		}
		else {
			(*m).heap[(*i).parameters[0].toSTR().getWStr()] = Var(false);
		}
		++(*m).instruct_number;
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TYPEOF
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void typeof(Machine* m, Instruction* i, bool prevalidate, bool prego) {

	if (prevalidate) {
		std::wstring name = L"TYPEOF";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 2);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");
	}
	else {
		checkNotExistValue(&(*i).parameters[0], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		(*m).heap[(*i).parameters[0].toSTR().getWStr()] = getValue(&(*i).parameters[1], &(*m).heap).typeOf();
		++(*m).instruct_number;
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// COMP
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void comp(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"COMP";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 4);
		requiredVar(&(*i).parameters[1], m, &name, L"Второй");
	}
	else {
		checkNotExistValue(&(*i).parameters[1], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		std::wstring type = getValue(&(*i).parameters[0], &(*m).heap).toSTR().getWStr();

		if (type == L"==") {
			(*m).heap[(*i).parameters[1].toSTR().getWStr()] = getValue(&(*i).parameters[2], &(*m).heap) == getValue(&(*i).parameters[3], &(*m).heap);
		}
		else if (type == L"!=") {
			(*m).heap[(*i).parameters[1].toSTR().getWStr()] = getValue(&(*i).parameters[2], &(*m).heap) != getValue(&(*i).parameters[3], &(*m).heap);
		}
		else if (type == L">") {
			(*m).heap[(*i).parameters[1].toSTR().getWStr()] = getValue(&(*i).parameters[2], &(*m).heap) > getValue(&(*i).parameters[3], &(*m).heap);
		}
		else if (type == L"<") {
			(*m).heap[(*i).parameters[1].toSTR().getWStr()] = getValue(&(*i).parameters[2], &(*m).heap) < getValue(&(*i).parameters[3], &(*m).heap);
		}
		else if (type == L">=") {
			(*m).heap[(*i).parameters[1].toSTR().getWStr()] = getValue(&(*i).parameters[2], &(*m).heap) >= getValue(&(*i).parameters[3], &(*m).heap);
		}
		else if (type == L"<=") {
			(*m).heap[(*i).parameters[1].toSTR().getWStr()] = getValue(&(*i).parameters[2], &(*m).heap) <= getValue(&(*i).parameters[3], &(*m).heap);
		}
		else {
			throw std::wstring{ L"Операция сравнения " + type + L" неизвестна\n" };
		}
		++(*m).instruct_number;
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// LOGIC
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void logic(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"LOGIC";
		int v[2]{ 3, 4 };
		checkParameterCount(VARIANTS, (int)(*i).parameters.size(), m, &name, 0, 0, nullptr, v);
		requiredVar(&(*i).parameters[1], m, &name, L"Второй");

	}
	else {
		checkNotExistValue(&(*i).parameters[1], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		std::wstring type = getValue(&(*i).parameters[0], &(*m).heap).toSTR().getWStr();
		if (type != L"NOT"
			&& type != L"AND"
			&& type != L"OR"
			&& type != L"NAND"
			&& type != L"NOR"
			&& type != L"XOR"
			&& type != L"XNOR"
			&& type != L"not"
			&& type != L"and"
			&& type != L"or"
			&& type != L"nand"
			&& type != L"nor"
			&& type != L"xor"
			&& type != L"xnor") {
			throw std::wstring{ L"Логическая операция " + type + L" неизвестна\n" };
		}
		if ((*i).parameters.size() == 3) {
			if (type == L"NOT" || type == L"not") {
				(*m).heap[(*i).parameters[1].toSTR().getWStr()] = !getValue(&(*i).parameters[2], &(*m).heap).toBLN().getBool();
			}
			else {
				throw std::wstring{ L"Логическая операция " + type + L" принимет не менее 4 параметров\n" };
			}
		}
		else if ((*i).parameters.size() == 4) {
			if (type == L"AND" || type == L"and") {
				(*m).heap[(*i).parameters[1].toSTR().getWStr()] = getValue(&(*i).parameters[2], &(*m).heap).toBLN().getBool() && getValue(&(*i).parameters[3], &(*m).heap).toBLN().getBool();
			}
			else if (type == L"OR" || type == L"or") {
				(*m).heap[(*i).parameters[1].toSTR().getWStr()] = getValue(&(*i).parameters[2], &(*m).heap).toBLN().getBool() || getValue(&(*i).parameters[3], &(*m).heap).toBLN().getBool();
			}
			else if (type == L"NAND" || type == L"nand") {
				(*m).heap[(*i).parameters[1].toSTR().getWStr()] = !(getValue(&(*i).parameters[2], &(*m).heap).toBLN().getBool() && getValue(&(*i).parameters[3], &(*m).heap).toBLN().getBool());
			}
			else if (type == L"NOR" || type == L"nor") {
				(*m).heap[(*i).parameters[1].toSTR().getWStr()] = !(getValue(&(*i).parameters[2], &(*m).heap).toBLN().getBool() || getValue(&(*i).parameters[3], &(*m).heap).toBLN().getBool());
			}
			else if (type == L"XOR" || type == L"xor") {
				(*m).heap[(*i).parameters[1].toSTR().getWStr()] = !(getValue(&(*i).parameters[2], &(*m).heap).toBLN().getBool()) != !(getValue(&(*i).parameters[3], &(*m).heap).toBLN().getBool());
			}
			else if (type == L"XNOR" || type == L"xnor") {
				(*m).heap[(*i).parameters[1].toSTR().getWStr()] = getValue(&(*i).parameters[2], &(*m).heap).toBLN().getBool() == getValue(&(*i).parameters[3], &(*m).heap).toBLN().getBool();
			}
			else {
				throw std::wstring{ L"Логическая операция " + type + L" принимет не более 3 параметров\n" };
			}
		}
		++(*m).instruct_number;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// JIF
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void jif(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"JIF";
		int v[2]{ 1, 2 };
		checkParameterCount(VARIANTS, (int)(*i).parameters.size(), m, &name, 1, 2, nullptr, v);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		bool swtch = getValue(&(*i).parameters[0], &(*m).heap).toBLN().getBool();
		if (swtch) {
			(*m).instruct_number = (int)getLabel(&(*i).parameters[1], &(*m).jmp_pointers).toUNTG().getUInt();
		}
		else {
			++(*m).instruct_number;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// JIFNOT
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void jifnot(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"JIFNOT";
		int v[2]{ 1, 2 };
		checkParameterCount(VARIANTS, (int)(*i).parameters.size(), m, &name, 1, 2, nullptr, v);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		bool swtch = getValue(&(*i).parameters[0], &(*m).heap).toBLN().getBool();
		if (swtch) {
			++(*m).instruct_number;
		}
		else {
			(*m).instruct_number = (int)getLabel(&(*i).parameters[1], &(*m).jmp_pointers).toUNTG().getUInt();
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DLABEL
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void dlabel(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"DLABEL";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 1);
		requiredLabel(&(*i).parameters[0], m, &name, L"Единственный");
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		(*m).jmp_pointers[(*i).parameters[0].toSTR().getWStr()] = (*m).instruct_number + 1;
		++(*m).instruct_number;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SWAP
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void swap(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"SWAP";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 2);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");
		requiredVar(&(*i).parameters[1], m, &name, L"Второй");
	}
	else {
		checkNotExistValue(&(*i).parameters[0], m);
		checkNotExistValue(&(*i).parameters[1], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		Var firstval = getValue(&(*i).parameters[0], &(*m).heap);
		Var secondval = getValue(&(*i).parameters[1], &(*m).heap);
		swap(firstval, secondval);

		(*m).heap[(*i).parameters[0].toSTR().getWStr()] = firstval;
		(*m).heap[(*i).parameters[1].toSTR().getWStr()] = secondval;
		++(*m).instruct_number;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ARRAY
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void arr(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"ARRAY";
		checkParameterCount(MIN, (int)(*i).parameters.size(), m, &name, 0, 2);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");
	}
	else {
		checkExistValue(&(*i).parameters[0], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		int dimensions = (int)(*i).parameters.size() - 1;
		Var result = Var();
		for (int iter = dimensions; iter > 0; --iter) {
			int dimension = (int)getValue(&(*i).parameters[iter], &(*m).heap).toUNTG().getUInt();
			std::vector<Var> v;
			Var arr = Var(v);
			for (int j = 0; j < dimension; ++j) {
				arr.pushb(result);
			}
			result = arr;
		}

		(*m).heap[(*i).parameters[0].getWStr()] = result;
		++(*m).instruct_number;
	}

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// VTOARR
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void vtoarr(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"VTOARR";
		checkParameterCount(MIN, (int)(*i).parameters.size(), m, &name, 0, 2);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");
	}
	else {
		checkExistValue(&(*i).parameters[0], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		int size = (int)(*i).parameters.size() - 1;
		std::vector<Var> v;
		Var arr = Var(v);
		for (int iter = 1; iter <= size; ++iter) {
			arr.pushb(getValue(&(*i).parameters[iter], &(*m).heap));
		}

		(*m).heap[(*i).parameters[0].getWStr()] = arr;
		++(*m).instruct_number;
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PUSHB
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pushb(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"PUSHB";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 2);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");

	}
	else {
		checkNotExistValue(&(*i).parameters[0], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		(*m).heap[(*i).parameters[0].toSTR().getWStr()].pushb(getValue(&(*i).parameters[1], &(*m).heap));
		++(*m).instruct_number;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// POPB
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void popb(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"POPB";
		int v[2]{ 1, 2 };
		checkParameterCount(VARIANTS, (int)(*i).parameters.size(), m, &name, 0, 0, nullptr, v);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");
		if ((*i).parameters.size() == 2) {
			requiredVar(&(*i).parameters[1], m, &name, L"Второй");
		}
	}
	else {
		checkNotExistValue(&(*i).parameters[0], m);
		if ((*i).parameters.size() == 2) {
			checkNotExistValue(&(*i).parameters[2], m);
		}
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		if ((*i).parameters.size() == 1) {
			(*m).heap[(*i).parameters[0].toSTR().getWStr()].popb();
			++(*m).instruct_number;
		}
		else {
			(*m).heap[(*i).parameters[0].toSTR().getWStr()] = (*m).heap[(*i).parameters[1].toSTR().getWStr()].popb();
			++(*m).instruct_number;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PUSHF
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pushf(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"PUSHF";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 2);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");
	}
	else {
		checkNotExistValue(&(*i).parameters[0], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		(*m).heap[(*i).parameters[0].toSTR().getWStr()].pushf(getValue(&(*i).parameters[1], &(*m).heap));
		++(*m).instruct_number;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// POPF
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void popf(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"POPF";
		int v[2]{ 1, 2 };
		checkParameterCount(VARIANTS, (int)(*i).parameters.size(), m, &name, 0, 0, nullptr, v);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");
		if ((*i).parameters.size() == 2) {
			requiredVar(&(*i).parameters[1], m, &name, L"Второй");
		}
	}
	else {
		checkNotExistValue(&(*i).parameters[0], m);
		if ((*i).parameters.size() == 2) {
			checkNotExistValue(&(*i).parameters[1], m);
		}
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		if ((*i).parameters.size() == 1) {
			(*m).heap[(*i).parameters[0].toSTR().getWStr()].popf();
			++(*m).instruct_number;
		}
		else {
			(*m).heap[(*i).parameters[0].toSTR().getWStr()] = (*m).heap[(*i).parameters[1].toSTR().getWStr()].popf();
			++(*m).instruct_number;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ERASE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void erase(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"ERASE";
		int v[2]{ 2, 3 };
		checkParameterCount(VARIANTS, (int)(*i).parameters.size(), m, &name, 0, 0, nullptr, v);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");
		if ((*i).parameters.size() == 3) {
			requiredVar(&(*i).parameters[1], m, &name, L"Второй");
		}
	}
	else {
		checkNotExistValue(&(*i).parameters[0], m);
		if ((*i).parameters.size() == 3) {
			checkNotExistValue(&(*i).parameters[1], m);
		}
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		if ((*i).parameters.size() == 2) {
			(*m).heap[(*i).parameters[0].toSTR().getWStr()].erase(getValue(&(*i).parameters[1], &(*m).heap));
			++(*m).instruct_number;
		}
		else {
			(*m).heap[(*i).parameters[0].toSTR().getWStr()] = (*m).heap[(*i).parameters[1].toSTR().getWStr()].erase(getValue(&(*i).parameters[2], &(*m).heap));
			++(*m).instruct_number;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// INSERT
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void insrt(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"INSERT";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 3);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");
	}
	else {
		checkNotExistValue(&(*i).parameters[0], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		(*m).heap[(*i).parameters[0].toSTR().getWStr()].insert_vector(getValue(&(*i).parameters[2], &(*m).heap), getValue(&(*i).parameters[1], &(*m).heap));
		++(*m).instruct_number;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CLEAR
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void clear(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"CLEAR";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 1);
		requiredVar(&(*i).parameters[0], m, &name, L"Единственный");
	}
	else {
		checkNotExistValue(&(*i).parameters[0], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		(*m).heap[(*i).parameters[0].toSTR().getWStr()].clear();
		++(*m).instruct_number;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SIZE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sizearr(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"SIZE";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 2);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");
		requiredVar(&(*i).parameters[1], m, &name, L"Второй");
	}
	else {
		checkNotExistValue(&(*i).parameters[0], m);
		checkNotExistValue(&(*i).parameters[1], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		(*m).heap[(*i).parameters[0].toSTR().getWStr()] = (*m).heap[(*i).parameters[1].toSTR().getWStr()].len();
		++(*m).instruct_number;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GETVAL
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void getval(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"GETVAL";
		checkParameterCount(MIN, (int)(*i).parameters.size(), m, &name, 0, 3);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");
		requiredVar(&(*i).parameters[1], m, &name, L"Второй");
	}
	else {
		checkNotExistValue(&(*i).parameters[0], m);
		checkNotExistValue(&(*i).parameters[1], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		int dimensions = (int)(*i).parameters.size() - 2;
		Var result = (*m).heap[(*i).parameters[1].toSTR().getWStr()];
		for (int iter = 0; iter  < dimensions; ++iter) {
			int dimension = (int)getValue(&(*i).parameters[(long long int)iter + 2], &(*m).heap).toUNTG().getUInt();
			try {
				Var res = result.getArr().at(dimension);
				result = res;
			}
			catch (std::out_of_range& ex) {
				std::string temp = ex.what();
				throw std::wstring{ L"Индекс " + std::to_wstring(dimension) + L" не существует\n" };
			}
		}
		(*m).heap[(*i).parameters[0].toSTR().getWStr()] = result;
		++(*m).instruct_number;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SETVAL
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setval(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"SETVAL";
		checkParameterCount(MIN, (int)(*i).parameters.size(), m, &name, 0, 3);
		requiredVar(&(*i).parameters[1], m, &name, L"Второй");
	}
	else {
		checkNotExistValue(&(*i).parameters[1], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {

		int dimensions = (int)(*i).parameters.size() - 2;
		Var* result = &((*m).heap[(*i).parameters[1].toSTR().getWStr()]);

		for (int iter = 0; iter < dimensions; ++iter) {
			int dimension = (int)getValue(&(*i).parameters[(long long int)iter + 2], &(*m).heap).toUNTG().getUInt();
			if (iter == dimensions - 1) {
				(*result)[getValue(&(*i).parameters[(long long int)iter + 2], &(*m).heap)] = getValue(&(*i).parameters[0], &(*m).heap);
				break;
			}
			Var* res = &(*result)[dimension];
			result = res;
		}

		++(*m).instruct_number;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SLICE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void slice(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"SPLIT";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 4);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");
		requiredVar(&(*i).parameters[1], m, &name, L"Второй");
	}
	else {
		checkNotExistValue(&(*i).parameters[0], m);
		checkNotExistValue(&(*i).parameters[1], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		Var x = getValue(&(*i).parameters[2], &(*m).heap);
		Var y = getValue(&(*i).parameters[3], &(*m).heap);

		if (x < 0) {
			throw std::wstring{ L"Параметр " + (*i).parameters[2].toSTR().getWStr() + L" меньше нуля\n"};
		}
		if (y < 0) {
			throw std::wstring{ L"Параметр " + (*i).parameters[3].toSTR().getWStr() + L" меньше нуля\n" };
		}
		if (y < x) {
			throw std::wstring{ L"Параметр " + (*i).parameters[2].toSTR().getWStr() + L" больше параметра " + (*i).parameters[3].toSTR().getWStr() + L"\n" };
		}
		if (x > (*m).heap[(*i).parameters[1].toSTR().getWStr()].csize() - 1) {
			throw std::wstring{ L"Индекс " + (*i).parameters[2].toSTR().getWStr() + L" не существует\n" };
		}
		if (y > (*m).heap[(*i).parameters[1].toSTR().getWStr()].csize() - 1) {
			throw std::wstring{ L"Индекс " + (*i).parameters[3].toSTR().getWStr() + L" не существует\n" };
		}

		(*m).heap[(*i).parameters[0].toSTR().getWStr()] = getValue(&(*i).parameters[1], &(*m).heap).slice(x, y);
		++(*m).instruct_number;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MERGE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void merge(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"MERGE";
		int v[2]{ 2, 3 };
		checkParameterCount(VARIANTS, (int)(*i).parameters.size(), m, &name, 0, 0, nullptr, v);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");
		requiredVar(&(*i).parameters[1], m, &name, L"Второй");
		if ((*i).parameters.size() == 3) {
			requiredVar(&(*i).parameters[2], m, &name, L"Третий");
		}
	}
	else {
		checkNotExistValue(&(*i).parameters[0], m);
		checkNotExistValue(&(*i).parameters[1], m);
		if ((*i).parameters.size() == 3) {
			checkNotExistValue(&(*i).parameters[2], m);
		}
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		if ((*i).parameters.size() == 2) {
			(*m).heap[(*i).parameters[0].toSTR().getWStr()] = getValue(&(*i).parameters[0], &(*m).heap).merge(getValue(&(*i).parameters[1], &(*m).heap));
		}
		else {
			(*m).heap[(*i).parameters[0].toSTR().getWStr()] = getValue(&(*i).parameters[1], &(*m).heap).merge(getValue(&(*i).parameters[2], &(*m).heap));
		}
		++(*m).instruct_number;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SORT
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sort(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"SORT";
		int v[2]{ 2, 3 };
		checkParameterCount(VARIANTS, (int)(*i).parameters.size(), m, &name, 0, 0, nullptr, v);
		requiredVar(&(*i).parameters[1], m, &name, L"Второй");
		if ((*i).parameters.size() == 3) {
			requiredVar(&(*i).parameters[2], m, &name, L"Третий");
		}
	}
	else {
		checkNotExistValue(&(*i).parameters[1], m);
		if ((*i).parameters.size() == 3) {
			checkNotExistValue(&(*i).parameters[2], m);
		}
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		std::wstring type = getValue(&(*i).parameters[0], &(*m).heap).toSTR().getWStr();
		if (type != L"ASC"
			&& type != L"DESC"
			&& type != L"asc"
			&& type != L"desc") {
			throw std::wstring{ L"Способ сортировки " + type + L" неизвестен\n" };
		}

		std::vector<Var> temp;
		if ((*i).parameters.size() == 2) {
			temp = getValue(&(*i).parameters[1], &(*m).heap).toARR().getArr();
		}
		else {
			temp = getValue(&(*i).parameters[2], &(*m).heap).toARR().getArr();
		}

		if (type == L"ASC" || type == L"asc") {
			sort(temp.begin(), temp.end());
		}
		else if (type == L"DESC" || type == L"desc") {
			sort(temp.begin(), temp.end(), std::greater<Var>());
		}
		(*m).heap[(*i).parameters[1].toSTR().getWStr()] = Var(temp);
		++(*m).instruct_number;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// UNIQUE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void unique(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"UNIQUE";
		int v[2]{ 2, 3 };
		checkParameterCount(VARIANTS, (int)(*i).parameters.size(), m, &name, 0, 0, nullptr, v);
		requiredVar(&(*i).parameters[1], m, &name, L"Второй");
		if ((*i).parameters.size() == 3) {
			requiredVar(&(*i).parameters[2], m, &name, L"Третий");
		}
	}
	else {
		checkNotExistValue(&(*i).parameters[1], m);
		if ((*i).parameters.size() == 3) {
			checkNotExistValue(&(*i).parameters[2], m);
		}
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		std::wstring type = getValue(&(*i).parameters[0], &(*m).heap).toSTR().getWStr();
		if (type != L"STRICT"
			&& type != L"DYNAMIC"
			&& type != L"strict"
			&& type != L"dynamic") {
			throw std::wstring{ L"Способ сравнения " + type + L" неизвестен\n" };
		}

		std::vector<Var> arr;
		if ((*i).parameters.size() == 2) {
			arr = getValue(&(*i).parameters[1], &(*m).heap).toARR().getArr();
		}
		else {
			arr = getValue(&(*i).parameters[2], &(*m).heap).toARR().getArr();
		}

		std::vector<Var> result;
		int size = (int)arr.size();
		for (int i = 0; i < size; ++i) {
			bool is_unique = true;
			for (int j = i; j < size; ++j) {
				if (j == i) { continue; }
				if (arr[i] == arr[j]) {
					if (type == L"STRICT" || type == L"strict") {
						if (arr[i].type == arr[j].type) {
							if (arr[i].type == ARR && arr[j].type == ARR) {
								is_unique = !eq(arr[i], arr[j]).getBool();
							}
							else {
								is_unique = false;
							}
							break;
						}
					}
					else if (type == L"DYNAMIC" || type == L"dynamic") {
						is_unique = false;
						break;
					}
				}
			}
			if (is_unique) {
				result.push_back(arr[i]);
			}
		}
		(*m).heap[(*i).parameters[1].toSTR().getWStr()] = Var(result);
		++(*m).instruct_number;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// REVERSE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void reverse(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"REVERSE";
		int v[2]{ 1, 2 };
		checkParameterCount(VARIANTS, (int)(*i).parameters.size(), m, &name, 0, 0, nullptr, v);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");
		if ((*i).parameters.size() == 2) {
			requiredVar(&(*i).parameters[1], m, &name, L"Второй");
		}
	}
	else {
		checkNotExistValue(&(*i).parameters[0], m);
		if ((*i).parameters.size() == 2) {
			checkNotExistValue(&(*i).parameters[1], m);
		}
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		if ((*i).parameters.size() == 1) {
			(*m).heap[(*i).parameters[0].toSTR().getWStr()] = getValue(&(*i).parameters[0], &(*m).heap).rev();
		}
		else {
			(*m).heap[(*i).parameters[0].toSTR().getWStr()] = getValue(&(*i).parameters[1], &(*m).heap).rev();
		}
		++(*m).instruct_number;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// EQUAL
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void equal(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"EQUAL";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 4);
		requiredVar(&(*i).parameters[1], m, &name, L"Второй");
		requiredVar(&(*i).parameters[2], m, &name, L"Третий");
		requiredVar(&(*i).parameters[3], m, &name, L"Четвертый");
	}
	else {
		checkNotExistValue(&(*i).parameters[1], m);
		checkNotExistValue(&(*i).parameters[2], m);
		checkNotExistValue(&(*i).parameters[3], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		std::wstring type = getValue(&(*i).parameters[0], &(*m).heap).toSTR().getWStr();
		if (type != L"STRICT"
			&& type != L"DYNAMIC"
			&& type != L"strict"
			&& type != L"dynamic") {
			throw std::wstring{ L"Способ сравнения " + type + L" неизвестен\n" };
		}

		if (type == L"STRICT" || type == L"strict") {
			(*m).heap[(*i).parameters[1].toSTR().getWStr()] = eq(getValue(&(*i).parameters[2], &(*m).heap), getValue(&(*i).parameters[3], &(*m).heap));
		}
		else if (type == L"DYNAMIC" || type == L"dynamic") {
			(*m).heap[(*i).parameters[1].toSTR().getWStr()] = deq(getValue(&(*i).parameters[2], &(*m).heap), getValue(&(*i).parameters[3], &(*m).heap));
		}
		++(*m).instruct_number;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// IEXIST
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void iexist(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"IEXIST";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 3);
		requiredVar(&(*i).parameters[0], m, &name, L"Первый");
		requiredVar(&(*i).parameters[1], m, &name, L"Второй");
	}
	else {
		checkNotExistValue(&(*i).parameters[0], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		if (getValue(&(*i).parameters[1], &(*m).heap).type != ARR) {
			throw std::wstring{ L"Инструкция IEXIST работает только с типом ARR\n" };
		}
		Var size = getValue(&(*i).parameters[1], &(*m).heap).csize();
		if (getValue(&(*i).parameters[2], &(*m).heap).toNTG() >= size || getValue(&(*i).parameters[2], &(*m).heap).toNTG() < 0) {
			(*m).heap[(*i).parameters[0].toSTR().getWStr()] = Var(false);
		}
		else {
			(*m).heap[(*i).parameters[0].toSTR().getWStr()] = Var(true);
		}
		++(*m).instruct_number;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// IN
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void in(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"IN";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 4);
		requiredVar(&(*i).parameters[1], m, &name, L"Второй");
		requiredVar(&(*i).parameters[2], m, &name, L"Третий");
	}
	else {
		checkNotExistValue(&(*i).parameters[1], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		std::wstring type = getValue(&(*i).parameters[0], &(*m).heap).toSTR().getWStr();
		if (type != L"STRICT"
			&& type != L"DYNAMIC"
			&& type != L"strict"
			&& type != L"dynamic") {
			throw std::wstring{ L"Способ сравнения " + type + L" неизвестен\n" };
		}

		if (type == L"STRICT" || type == L"strict") {
			(*m).heap[(*i).parameters[1].toSTR().getWStr()] = in(getValue(&(*i).parameters[2], &(*m).heap), getValue(&(*i).parameters[3], &(*m).heap));
		}
		else if (type == L"DYNAMIC" || type == L"dynamic") {
			(*m).heap[(*i).parameters[1].toSTR().getWStr()] = din(getValue(&(*i).parameters[2], &(*m).heap), getValue(&(*i).parameters[3], &(*m).heap));
		}
		++(*m).instruct_number;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// INALL
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void inall(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"INALL";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 4);
		requiredVar(&(*i).parameters[1], m, &name, L"Второй");
		requiredVar(&(*i).parameters[2], m, &name, L"Третий");
	}
	else {
		checkNotExistValue(&(*i).parameters[1], m);
		checkNotExistValue(&(*i).parameters[2], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		std::wstring type = getValue(&(*i).parameters[0], &(*m).heap).toSTR().getWStr();
		if (type != L"STRICT"
			&& type != L"DYNAMIC"
			&& type != L"strict"
			&& type != L"dynamic") {
			throw std::wstring{ L"Способ сравнения " + type + L" неизвестен\n" };
		}

		if (type == L"STRICT" || type == L"strict") {
			(*m).heap[(*i).parameters[1].toSTR().getWStr()] = inall(getValue(&(*i).parameters[2], &(*m).heap), getValue(&(*i).parameters[3], &(*m).heap));
		}
		else if (type == L"DYNAMIC" || type == L"dynamic") {
			(*m).heap[(*i).parameters[1].toSTR().getWStr()] = dinall(getValue(&(*i).parameters[2], &(*m).heap), getValue(&(*i).parameters[3], &(*m).heap));
		}
		++(*m).instruct_number;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// RIN
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rin(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"RIN";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 4);
		requiredVar(&(*i).parameters[1], m, &name, L"Второй");
		requiredVar(&(*i).parameters[2], m, &name, L"Третий");
	}
	else {
		checkNotExistValue(&(*i).parameters[1], m);
		checkNotExistValue(&(*i).parameters[2], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		std::wstring type = getValue(&(*i).parameters[0], &(*m).heap).toSTR().getWStr();
		if (type != L"STRICT"
			&& type != L"DYNAMIC"
			&& type != L"strict"
			&& type != L"dynamic") {
			throw std::wstring{ L"Способ сравнения " + type + L" неизвестен\n" };
		}

		if (type == L"STRICT" || type == L"strict") {
			Var result = rin(getValue(&(*i).parameters[2], &(*m).heap), getValue(&(*i).parameters[3], &(*m).heap));
			if (result.type == ARR) {
				result.popb();
			}
			(*m).heap[(*i).parameters[1].toSTR().getWStr()] = result;
		}
		else if (type == L"DYNAMIC" || type == L"dynamic") {
			Var result = drin(getValue(&(*i).parameters[2], &(*m).heap), getValue(&(*i).parameters[3], &(*m).heap));
			if (result.type == ARR) {
				result.popb();
			}
			(*m).heap[(*i).parameters[1].toSTR().getWStr()] = drin(getValue(&(*i).parameters[2], &(*m).heap), getValue(&(*i).parameters[3], &(*m).heap));
		}
		++(*m).instruct_number;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// RINALL
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rinall(Machine* m, Instruction* i, bool prevalidate, bool prego) {
	if (prevalidate) {
		std::wstring name = L"RINALL";
		checkParameterCount(STRICTED, (int)(*i).parameters.size(), m, &name, 4);
		requiredVar(&(*i).parameters[1], m, &name, L"Второй");
		requiredVar(&(*i).parameters[2], m, &name, L"Третий");
	}
	else {
		checkNotExistValue(&(*i).parameters[1], m);
		checkNotExistValue(&(*i).parameters[2], m);
	}

	if (prego) {
		++(*m).instruct_number;
	}
	else {
		std::wstring type = getValue(&(*i).parameters[0], &(*m).heap).toSTR().getWStr();
		if (type != L"STRICT"
			&& type != L"DYNAMIC"
			&& type != L"strict"
			&& type != L"dynamic") {
			throw std::wstring{ L"Способ сравнения " + type + L" неизвестен\n" };
		}
		(*m).heap[(*i).parameters[1].toSTR().getWStr()] = rinall(type, getValue(&(*i).parameters[2], &(*m).heap), getValue(&(*i).parameters[3], &(*m).heap));
		++(*m).instruct_number;
	}
}