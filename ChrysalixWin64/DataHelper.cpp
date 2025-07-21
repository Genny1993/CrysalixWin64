#pragma once

#include <iostream>

#include "Helpers.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// getValue 
// ���������� �������� ��������� �� ����� ���������� ��� ��������
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Var getValue(Var* val,std::map<std::wstring, Var>* heap) {
	if ((*val).type == STR && (*val).getWStr()[0] == L'$') {
		try {
			return (*heap).at((*val).getWStr());
		}
		catch (std::out_of_range& ex) {
			std::string temp = ex.what();
			throw std::wstring{ L"���������� " + (*val).getWStr() + L" �� ����������\n" };
		}
	}
	else {
		return *val;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// getLabel
// ���������� �������� ��������� �� ����� ���������� ��� ��������
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Var getLabel(Var* val,std::map<std::wstring, int>* pointers) {
	if ((*val).type == STR && (*val).getWStr()[0] == L'&') {
		try {
			return (*pointers).at((*val).getWStr());
		}
		catch (std::out_of_range& ex) {
			std::string temp = ex.what();
			throw std::wstring{ L"����� " + (*val).getWStr() + L" �� ����������\n" };
		}
	}
	else {
		return *val;
	}
	return 0;
}