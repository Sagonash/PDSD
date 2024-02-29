#include "SetLab1_Ryazanskiy.h"

//создание пустого множества
Node* createEmptySet() {
	Node* start = NULL;
	return start;
}
//проверка пустое ли множество?
bool isEmpty(Node* start) {
	if (!start) return true;
	return false;
}
//проверка на наличие элемента в множестве
bool inSet(Node* start, int value) {
	if (isEmpty(start)) return false;
	Node* tmp = start;
	while (tmp) {
		if (tmp->_num == value) return true;
		tmp = tmp->_next;
	}
	return false;
}
//добавление элемента в начало множества
Node* addFirst(Node* start, int value) {
	if (inSet(start, value)) return start;
	Node* tmp = new Node;
	tmp->_num = value;
	tmp->_next = start;
	start = tmp;
	return start;
}
//создание множества
Node* createSet(int size, int min, int max, string s) {
	if (size <= 0 || max - min < size) return NULL;
	int multiple = 0;
	if (s == "a") multiple = 4;
	else if (s == "b") multiple = 8;
	else return NULL;
	srand(time(0));
	Node* set = createEmptySet();
	for (int i = 0; i < size; i++) {
		int num = (rand() % (max - min + 1) + min);
		num -= (num % multiple);
		while (inSet(set, num)) {
			num = rand() % (max - min + 1) + min;
			num -= (num % multiple);
		}
		set = addFirst(set, num);
	}
	return set;
}
//мощность множества
int powerOfSet(Node* start) {
	if (isEmpty(start)) return 0;
	int power = 0;
	Node* tmp = start;
	while (tmp) {
		power++;
		tmp = tmp->_next;
	}
	return power;
}
//вывод элементов множества	
string printSet(Node* start, char sep) {
	string out;
	if (isEmpty(start)) return out;
	Node* tmp = start;
	while (tmp) {
		out += to_string(tmp->_num) + sep;
		tmp = tmp->_next;
	}
	out.pop_back();
	return out;
}
//удаление множества
Node* deleteSet(Node* start) {
	if (isEmpty(start)) return start;
	Node* tmp = start;
	while (tmp) {
		tmp = tmp->_next;
		delete start;
		start = tmp;
	}
	return start;
}
//подмножество A-B
bool subSet(Node* a, Node* b) {
	if (isEmpty(a) || isEmpty(b)) return false;
	if (powerOfSet(a) > powerOfSet(b)) return false;
	bool check = false;
	for (Node* tmpa = a; tmpa->_next; tmpa = tmpa->_next) {
		check = false;
		for (Node* tmpb = b; tmpb->_next; tmpb = tmpb->_next) {
			if (tmpa->_num != tmpb->_num) {
				continue;
			}
			else {
				check = true;
				break;
			}
		}
		if (check == true) continue;
		else return false;
	}
	return true;
}
//равенство двух множеств
bool equalitySet(Node* a, Node* b) {
	if (subSet(a, b) && subSet(b, a)) return true;
	return false;
}
//объединение двух множеств
Node* combinationOfSets(Node* a, Node* b) {
	if (isEmpty(a) || isEmpty(b)) return NULL;
	Node* tmp = b;
	for (Node* tmp = b; tmp; tmp = tmp->_next) {
		a = addFirst(a, tmp->_num);
	}
	return a;
}
//пересечение двух множеств
Node* intersectionOfSets(Node* a, Node* b) {
	if (isEmpty(a) || isEmpty(b)) return NULL;
	Node* set = createEmptySet();
	for (Node* tmpa = a; tmpa->_next; tmpa = tmpa->_next) {
		if (inSet(b, tmpa->_num)) set = addFirst(set, tmpa->_num);
	}
	return set;
}
//разность двух множеств
Node* subtractionOfSets(Node* a, Node* b) {
	if (isEmpty(a) || isEmpty(b)) return NULL;
	Node* set = createEmptySet();
	for (Node* tmpa = a; tmpa->_next; tmpa = tmpa->_next) {
		if (!(inSet(b, tmpa->_num))) set = addFirst(set, tmpa->_num);
	}
	return set;
}
//симметричная разность двух множеств
Node* simmetricSubtrOfSets(Node* a, Node* b) {
	return subtractionOfSets(combinationOfSets(a, b), intersectionOfSets(a, b));
}