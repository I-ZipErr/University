#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>
#include <fstream>
#include <algorithm>

using namespace std;

struct birth_date
{
    short day_of_birth;
    short month_of_birth;
    short year_of_birth;
};
struct student
{
    string last_name; //фамилия
    string first_name; //имя
    string middle_name; //отчество
    birth_date date;
    short age;
    string description_of_student;
};

void CinStudents(student* students, int number_of_students);
void ReadStudentsFromFile(student* students, string path);
void OutStudents(student* students, int number_of_students);
bool CompLastNameUp(student first, student second);
bool CompFirstNameUp(student first, student second);
bool CompMiddleNameUp(student first, student second);
bool CompAgeUp(student first, student second);
bool CompLastNameDown(student first, student second);
bool CompFirstNameDown(student first, student second);
bool CompMiddleNameDown(student first, student second);
bool CompAgeDown(student first, student second);
int age_calculator;

int main()
{
    setlocale(LC_ALL, "rus");
    bool inp_answer;
    SYSTEMTIME sys_time;
    GetSystemTime(&sys_time);
    cout << "Желаете ли вы ввести свои данные студентов или использовать заготовленные?\n\
Введите 0 для заготовленных. Введите 1 для ввода своих.\n > "; cin >> inp_answer;
    int number_of_students;
    student* students_arr;
    if (inp_answer)
    {
        cout << "Вы выбрали ввод своих данных.\n";
        cout << "Введите число студентов:\n > "; cin >> number_of_students;
        student* students_arr = new student[number_of_students];
        CinStudents(students_arr, number_of_students);
        OutStudents(students_arr, number_of_students);
        int choose;
        cout << "Введите, каким образом Вы хотите отсортировать студентов:\n\
1.Возрастание фамилии\n2.Убывание фамилии\n3.Возрастание имени\n4.Убывание имени\n\
\n3.Возрастание отчества\n4.Убывание отчества\n7.Возрастание возраста\n8.Убывание возраста.\
\nВведите номер операции:\n > "; cin >> choose;
        switch (choose)
        {
        case 1:
            sort(students_arr, students_arr + number_of_students, CompLastNameUp);
            break;
        case 2:
            sort(students_arr, students_arr + number_of_students, CompLastNameDown);
            break;
        case 3:
            sort(students_arr, students_arr + number_of_students, CompFirstNameUp);
            break;
        case 4:
            sort(students_arr, students_arr + number_of_students, CompFirstNameDown);
            break;
        case 5:
            sort(students_arr, students_arr + number_of_students, CompMiddleNameUp);
            break;
        case 6:
            sort(students_arr, students_arr + number_of_students, CompMiddleNameDown);
            break;
        case 7:
            sort(students_arr, students_arr + number_of_students, CompAgeUp);
            break;
        case 8:
            sort(students_arr, students_arr + number_of_students, CompAgeDown);
            break;
        default:
            cout << "Надо было вводить нормально число...";
            return 0;
            break;
        }
        OutStudents(students_arr, number_of_students);
    }
    else
    {
        ifstream file;
        file.open("students.txt");
        if (!file)
        {
            cout << "\nФайл не открывается!";
            return -1;
        };
        file >> number_of_students;
        student* students_arr = new student[number_of_students];
        ReadStudentsFromFile(students_arr, "students.txt");
        file.close();
        OutStudents(students_arr, number_of_students);
        int choose;
        cout << "\nВведите, каким образом Вы хотите отсортировать студентов:\n\
1.Возрастание фамилии\n2.Убывание фамилии\n3.Возрастание имени\n4.Убывание имени\n\
3.Возрастание отчества\n4.Убывание отчества\n7.Возрастание возраста\n8.Убывание возраста.\
\nВведите номер операции:\n > "; cin >> choose;
        switch (choose)
        {
        case 1:
            sort(students_arr, students_arr + number_of_students, CompLastNameUp);
            break;
        case 2:
            sort(students_arr, students_arr + number_of_students, CompLastNameDown);
            break;
        case 3:
            sort(students_arr, students_arr + number_of_students, CompFirstNameUp);
            break;
        case 4:
            sort(students_arr, students_arr + number_of_students, CompFirstNameDown);
            break;
        case 5:
            sort(students_arr, students_arr + number_of_students, CompMiddleNameUp);
            break;
        case 6:
            sort(students_arr, students_arr + number_of_students, CompMiddleNameDown);
            break;
        case 7:
            sort(students_arr, students_arr + number_of_students, CompAgeUp);
            break;
        case 8:
            sort(students_arr, students_arr + number_of_students, CompAgeDown);
            break;
        default:
            cout << "Надо было вводить нормально число...";
            return 0;
            break;
        }
        OutStudents(students_arr, number_of_students);
    }
};

void CinStudents(student* students, int number_of_students)
{
    int i;
    cout << "Введите данные Ваших студентов.\n\
Вводить данные в виде: \"[Фамилия] [Имя] [Отчество] [День рождения] [Месяц] [Год] [Пометки, если есть]\"\n\
Если отсутсвует отчество, ставить знак минуса.\n";
    SYSTEMTIME sys_time;
    GetSystemTime(&sys_time);
    string buffer;
    for (i = 0; i < number_of_students; i++)
    {
        cout << i + 1 << "й студент: "; cin >> students[i].last_name >> \
            students[i].first_name >> students[i].middle_name >> \
            students[i].date.day_of_birth >> students[i].date.month_of_birth >> \
            students[i].date.year_of_birth;
        while (cin.peek() != '\n' && cin.peek() != EOF)
        {
            cin >> buffer;
            students[i].description_of_student += buffer;
            students[i].description_of_student += " ";
        };
        students[i].age = sys_time.wYear - students[i].date.year_of_birth-1;
        if (students[i].date.month_of_birth <= sys_time.wMonth)
        {
            if (students[i].date.month_of_birth < sys_time.wMonth)
            {
                students[i].age++;
            }
            else
            {
                if (students[i].date.day_of_birth <= sys_time.wDay)
                {
                    students[i].age++;
                };
            };
        };
    };
};

void ReadStudentsFromFile(student* students, string path)
{
    int number_of_students;
    int i;
    string buffer;
    ifstream file(path);
    SYSTEMTIME sys_time;
    file >> number_of_students;
    GetSystemTime(&sys_time);
    for (i = 0; i < number_of_students; i++)
    {
        file >> students[i].last_name >> \
            students[i].first_name >> students[i].middle_name >> \
            students[i].date.day_of_birth >> students[i].date.month_of_birth >> \
            students[i].date.year_of_birth;
        while (file.peek() != '\n' && file.peek() != EOF)
        {
            file >> buffer;
            students[i].description_of_student += buffer;
            students[i].description_of_student += " ";
        };
        students[i].age = sys_time.wYear - students[i].date.year_of_birth - 1;
        if (students[i].date.month_of_birth <= sys_time.wMonth)
        {
            if (students[i].date.month_of_birth < sys_time.wMonth)
            {
                students[i].age++;
            }
            else
            {
                if (students[i].date.day_of_birth <= sys_time.wDay)
                {
                    students[i].age++;
                };
            };
        };
    }
    file.close();
}

void OutStudents(student* students, int number_of_students)
{
    cout << "Студенты:";
    int i;
    for (i = 0; i < number_of_students; i++)
    {
        cout << endl << endl << i + 1 << "й студент\n";
        cout << "ФИО: " << students[i].last_name << " " << \
            students[i].first_name << " ";
        if (students[i].middle_name != "-")
        {
            cout << students[i].middle_name;
        };
        cout << endl << "Инициалы: " << students[i].last_name << " " << \
            students[i].first_name[0] << ". ";
        if (students[i].middle_name != "-")
        {
            cout << students[i].middle_name[0] << ". ";
        };
        cout << endl << "Дата рождения: " << students[i].date.day_of_birth << "." <<\
            students[i].date.month_of_birth << "." << \
            students[i].date.year_of_birth << " (" << students[i].age << "y.o.)" << endl;
        cout << "Прочие пометки: " << students[i].description_of_student;
    };
}

bool CompLastNameUp(student first, student second)
{
    if (first.last_name < second.last_name)
    {
        return true;
    }
    else
    {
        if (first.last_name == second.last_name)
        {
            return CompFirstNameUp(first, second);
        };
    };
    return false;
}

bool CompFirstNameUp(student first, student second)
{
    if (first.first_name < second.first_name)
    {
        return true;
    }
    else
    {
        if (first.first_name == second.first_name)
        {
            return CompMiddleNameUp(first, second);
        };
    };
    return false;
}

bool CompMiddleNameUp(student first, student second)
{
    return first.middle_name < second.middle_name;
}

bool CompAgeUp(student first, student second)
{
    if (first.age < second.age)
    {
        return true;
    }
    else
    {
        if (first.age > second.age) return false;
        if (first.date.year_of_birth > second.date.year_of_birth)
        {
            return true;
        }
        else
        {
            if (first.date.year_of_birth < second.date.year_of_birth) return false;
            if (first.date.month_of_birth > second.date.month_of_birth)
            {
                return true;
            }
            else
            {
                if (first.date.month_of_birth < second.date.month_of_birth) return false;
                if (first.date.day_of_birth > second.date.day_of_birth)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool CompLastNameDown(student first, student second)
{
    return !CompLastNameUp(first, second);
}

bool CompFirstNameDown(student first, student second)
{
    return !CompFirstNameUp(first, second);
}

bool CompMiddleNameDown(student first, student second)
{
    return !CompMiddleNameUp(first, second);
}

bool CompAgeDown(student first, student second)
{
    return !CompAgeUp(first, second);
}

