#include "SetLab1_Ryazanskiy.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    Node* A = createSet(rand() % (9 - 6 + 1) + 6, 12, 99, "a");
    Node* B = createSet(rand() % (9 - 6 + 1) + 6, 16, 99, "b");
    cout << "Множества A и B созданы" << endl;
    cout << "Вывод множества A: " + printSet(A, ',') << endl;
    cout << "Вывод множества B: " + printSet(B, ',') << endl;
    cout << "Множество A является подмножеством B: " + to_string(subSet(A, B)) << endl;
    cout << "Множество A является подмножеством A: " + to_string(subSet(A, A)) << endl;
    cout << "Множество A равно подмножеству B: " + to_string(equalitySet(A, B)) << endl;
    cout << "Множество A равно подмножеству A: " + to_string(equalitySet(A, A)) << endl;
    Node* C = combinationOfSets(A, B);
    cout << "Объединение двух множеств: " + printSet(C, ',') << endl;
    Node* D = intersectionOfSets(A, B);
    cout << "Пересечение двух множеств: " + printSet(D, ',') << endl;
    Node* E = subtractionOfSets(A, B);
    Node* F = subtractionOfSets(B, A);
    cout << "Разность A-B: " + printSet(E, ',') << endl;
    cout << "Разность B-A: " + printSet(F, ',') << endl;
    Node* G = simmetricSubtrOfSets(A, B);
    cout << "Симметричная разность множеств: " + printSet(G, ',') << endl;
}