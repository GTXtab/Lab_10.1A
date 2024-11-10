#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

/*
{ "Ivanenko", 2, 0 3 4 5 },
{ "Petrenko", 3, 1 2 3 4  },
{ "Sydorenko", 1, 2 5 5 5 }
*/

enum Specialnist { RI, IK, SSHI };
string specialnistStr[] = { "в", "��", "�ز" };

struct Student {
    string prizv;
    unsigned kurs;
    Specialnist specialnist;
    int ocinkaFizyka;
    int ocinkaMatematika;
    int ocinkaInformatika;
};

void Create(Student* s, const int N);
void Print(const Student* s, const int N);
int FindStudentWithMinAverage(const Student* s, const int N);
void CountSatisfactoryGrades(const Student* s, const int N);
void PrintStudentWithMinAverage(const Student* s, const int N);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "������ ������� ��������: "; cin >> N;

    Student* s = new Student[N];
    Create(s, N);
    Print(s, N);
    PrintStudentWithMinAverage(s, N);
    CountSatisfactoryGrades(s, N);

    delete[] s;
    return 0;
}

void Create(Student* s, const int N) {
    int specialnist;
    for (int i = 0; i < N; i++) {
        cout << "������� � " << i + 1 << ":" << endl;
        cin.get();
        cout << " �������: "; getline(cin, s[i].prizv);
        cout << " ����: "; cin >> s[i].kurs;
        cout << " ������������ (0 - в, 1 - ��, 2 - �ز): ";
        cin >> specialnist;
        s[i].specialnist = (Specialnist)specialnist;
        cout << " ������ � ������: "; cin >> s[i].ocinkaFizyka;
        cout << " ������ � ����������: "; cin >> s[i].ocinkaMatematika;
        cout << " ������ � �����������: "; cin >> s[i].ocinkaInformatika;
        cout << endl;
    }
}

void Print(const Student* s, const int N) {
    cout << "=================================================================================" << endl;
    cout << "| � | �������       | ���� | ������������ | Գ���� | ���������� | ����������� |" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++) {
        cout << "| " << setw(1) << i + 1
            << " | " << setw(15) << left << s[i].prizv
            << "|  " << setw(3) << left << s[i].kurs
            << " | " << setw(13) << left << specialnistStr[s[i].specialnist]
            << " | " << setw(6) << s[i].ocinkaFizyka
            << " | " << setw(10) << s[i].ocinkaMatematika
            << " | " << setw(11) << s[i].ocinkaInformatika << " |" << endl;
    }
    cout << "=================================================================================" << endl;
}

int FindStudentWithMinAverage(const Student* s, const int N) {
    int minIndex = 0;
    double minAvg = (s[0].ocinkaFizyka + s[0].ocinkaMatematika + s[0].ocinkaInformatika) / 3.0;

    for (int i = 1; i < N; i++) {
        double avg = (s[i].ocinkaFizyka + s[i].ocinkaMatematika + s[i].ocinkaInformatika) / 3.0;
        if (avg < minAvg) {
            minAvg = avg;
            minIndex = i;
        }
    }
    return minIndex; 
}

void PrintStudentWithMinAverage(const Student* s, const int N) {
    int minIndex = FindStudentWithMinAverage(s, N);
    cout << "������� � ��������� ������� �����: " << s[minIndex].prizv << endl;
}

void CountSatisfactoryGrades(const Student* s, const int N) {
    int satisfactoryPhysics = 0, satisfactoryMath = 0, satisfactoryInformatics = 0;

    for (int i = 0; i < N; i++) {
        if (s[i].ocinkaFizyka == 3) satisfactoryPhysics++;
        if (s[i].ocinkaMatematika == 3) satisfactoryMath++;
        if (s[i].ocinkaInformatika == 3) satisfactoryInformatics++;
    }

    cout << "ʳ������ ������ '���������' � ������: " << satisfactoryPhysics << endl;
    cout << "ʳ������ ������ '���������' � ����������: " << satisfactoryMath << endl;
    cout << "ʳ������ ������ '���������' � �����������: " << satisfactoryInformatics << endl;
}
