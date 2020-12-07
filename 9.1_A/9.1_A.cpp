#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Specialty { ІТ, КН, ПЗ, ВП, СА };

string strSpecialty[] = { "ІТ","КН","ПЗ","ВП","СА" };

struct Student
{
    string prizv;
    Specialty specialty;
    short unsigned kurs;
    short unsigned physics;
    short unsigned math;
    short unsigned informatics;
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
double well_students(Student* s, const int N);
void bestphysics(Student* s, const int N);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
   

    cout << "Введіть кількість студентів: "; cin >> N;
    Student* s = new Student[N];
    Create(s, N);
    Print(s, N);
    cout << "| Процент студентів, які вчаться на відмінно " << fixed << setprecision(2) << well_students(s, N) << '%' << setw(29) << "|" << endl;
    cout << "| Прізвища студентів, які отримали з фізики "  << char(34) << "5"<< char(34) << fixed << setprecision(2) << setw(33) << "|" << endl;
    bestphysics(s, N);
    cout << "================================================================================" << endl;
    delete[] s;
}

void Create(Student* s, const int N)
{
    int kurs, specialty;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент№ " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();
        cout << "  прізвище: "; getline(cin, s[i].prizv);
        cout << "  курс: "; cin >> s[i].kurs;
        cout << "  спеціальність (0 - ІТ, 1 - КН, 2 - ПЗ, 3 - ВП, 4 - СА): "; cin >> specialty;
        s[i].specialty = (Specialty)specialty;
        cout << "  оцінка з фізики: "; cin >> s[i].physics;
        cout << "  оцінка з математики: "; cin >> s[i].math;
        cout << "  оцінка з інформатики: "; cin >> s[i].informatics;
    }
}

void Print(Student* s, const int N)
{
    cout << "================================================================================"
        << endl;
    cout << "| №  | Прізвище     | Курс | Спеціальність | Фізика | Математика | Інформатика |"
        << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " "
            << "| " << setw(13) << left << s[i].prizv
            << "| " << setw(3) << right << s[i].kurs << "  "
            << "| " << setw(8) << right << strSpecialty[s[i].specialty] << "      "
            << "| " << setw(4) << right << s[i].physics << "   "
            << "| " << setw(6) << right << s[i].math << "      "
            << "| " << setw(6) << right << s[i].informatics << "     |" << endl;
    }
    cout << "================================================================================" << endl;
}
double well_students(Student* s, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        if (s[i].physics == 5 && s[i].math == 5 && s[i].informatics == 5)
            k++;
    return 100.0 * k / N;
}
void bestphysics(Student* s, const int N)
{
    for (int i = 0; i < N; i++)
    {
        if (s[i].physics == 5)
            cout << s[i].prizv << endl;
    }
}
