#pragma once

#include <iostream>

#include "Helpers.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// checkExistValue
// Проверяет существование переменной
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void checkExistValue(Var* val, Machine* m) {
	if ((*val).type == STR && (*val).getWStr()[0] == L'$') {
		if ((*m).heap.find((*val).getWStr()) != (*m).heap.end()) {
			throw std::wstring{ L"Переменная " + (*val).getWStr() + L" уже определена\n" };
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// checkNotExistValue
// Проверяет отсутствие существования переменной
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void checkNotExistValue(Var* val, Machine* m) {
	if ((*val).type == STR && (*val).getWStr()[0] == L'$') {
		if ((*m).heap.find((*val).getWStr()) == (*m).heap.end()) {
			throw std::wstring{ L"Переменная " + (*val).getWStr() + L" не определена\n" };
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// checkExistLabel
// Проверяет существование метки
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void checkExistLabel(Var* val, Machine* m) {
	if ((*val).type == STR && (*val).getWStr()[0] == L'&') {
		if ((*m).jmp_pointers.find((*val).getWStr()) != (*m).jmp_pointers.end()) {
			throw std::wstring{ L"Метка " + (*val).getWStr() + L" уже определена\n" };
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// checkParameterCount
// Проверяет соответствие количества инструкций
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void checkParameterCount(unsigned char type, int count, Machine* m, std::wstring* name, int stricted, int min, int range[], int variant[]) {
	switch (type) {
	case STRICTED:
		if (count != stricted) {
			throw std::wstring{ L"Инструкция " + *name + L" принимает " + std::to_wstring(stricted) + L" параметр(а)(ов)\n" };
		}
		break;
	case MIN:
		if (count < min) {
			throw std::wstring{ L"Инструкция " + *name + L" принимает не меньше " + std::to_wstring(min) + L" параметра(ов)\n" };
		}
		break;
	case RANGE:
		if (count < range[0] || count > range[1]) {
			throw std::wstring{ L"Инструкция " + *name + L" принимает от " + std::to_wstring(range[0]) + L" до " + std::to_wstring(range[1]) + L" параметра(ов)\n" };
		}
		break;
	case VARIANTS: {
		int size = (int)sizeof(variant) / (int)sizeof(int);
		bool is_variant = false;
		for (int i = 0; i < size; ++i) {
			if (count == variant[i]) {
				is_variant = true;
				break;
			}
		}
		if (!is_variant) {
			std::wstring params_str = L"";
			for (int i = 0; i < size; ++i) {
				params_str += std::to_wstring(variant[i]);
				if (i + 1 != size) {
					params_str += L", ";
				}
			}
			throw std::wstring{ L"Инструкция " + *name + L" может принимать следующее число параметров: " + params_str + L"\n" };
		}
	}
				 break;
	default:
		throw std::wstring{ L"Указан неверный вариант валидации параметров" };
		break;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// requiredVar
// Проверяет то, что требуется переменная
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void requiredVar(Var* val, Machine* m, std::wstring* type, std::wstring num) {
	if ((*val).type != STR || (*val).getWStr()[0] != L'$') {
		throw std::wstring{ num + L" параметр инструкции " + (*type) + L" должен быть именем переменной\n" };
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// requiredLabel
// Проверяет то, что требуется метка
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void requiredLabel(Var* val, Machine* m, std::wstring* type, std::wstring num) {
	if ((*val).type != STR || (*val).getWStr()[0] != L'&') {
		throw std::wstring{ num + L" параметр инструкции " + (*type) + L" должен быть именем метки\n" };
	}
}