#pragma once

#include <iostream>

#include "Helpers.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// getValue 
// ¬озвращает значение параметра по имени переменной или литералу
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Var getValue(Var* val,std::map<std::wstring, Var>* heap) {
	if ((*val).type == STR && (*val).getWStr()[0] == L'$') {
		try {
			return (*heap).at((*val).getWStr());
		}
		catch (std::out_of_range& ex) {
			std::string temp = ex.what();
			throw std::wstring{ L"ѕеременна€ " + (*val).getWStr() + L" не определена\n" };
		}
	}
	else {
		return *val;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// getLabel
// ¬озвращает значение параметра по имени переменной или литералу
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Var getLabel(Var* val,std::map<std::wstring, int>* pointers) {
	if ((*val).type == STR && (*val).getWStr()[0] == L'&') {
		try {
			return (*pointers).at((*val).getWStr());
		}
		catch (std::out_of_range& ex) {
			std::string temp = ex.what();
			throw std::wstring{ L"ћетка " + (*val).getWStr() + L" не определена\n" };
		}
	}
	else {
		return *val;
	}
	return 0;
}