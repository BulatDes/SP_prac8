// SP_prac8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

struct Publication {
    char author[100];
    char title[100];
    char type[100];
    union
    {
        struct {
            char city[100];
            char isdatel[100];
            int yearPublish;
        } book;

        struct {
            char journalName[100];
            int journalYear;
            int journalNumber;
        } journal;

    };
    Publication(const char* aut, const char* tit, const char* tp, const char* city, const char* izdat, int year) {
        strncpy_s(author, aut, sizeof(author));
        strncpy_s(title, tit, sizeof(title));
        strncpy_s(type, tp, sizeof(type));
        strncpy_s(book.city, city, sizeof(book.city));
        strncpy_s(book.isdatel, izdat, sizeof(book.isdatel));
        book.yearPublish = year;
    }
    Publication(const char* aut, const char* tit, const char* tp, const char* jourName, int ye, int num)
    {
        strncpy_s(author, aut, sizeof(author));
        strncpy_s(title, tit, sizeof(title));
        strncpy_s(type, tp, sizeof(type));
        strncpy_s(journal.journalName, jourName, sizeof(journal.journalName));
        journal.journalYear = ye;
        journal.journalNumber = num;
    }
    Publication() {};
};

bool compareByAuthor(const Publication& a, const Publication& b) {
    return strcmp(a.author, b.author) < 0;
}
bool isJournal(const Publication& pub) {
    const char* search = "журнал";
    return strcmp(pub.type, search) == 0;
}
int main()
{
    setlocale(LC_ALL, "rus");
    Publication publications[] = {
       Publication("Обама", "Человек-паук", "книга", "Нью-йорк","Джон Джонс",2005),
       Publication{"ЗИЛ", "Обо всем на свете", "журнал", "Непоседа", 2011, 2},
       Publication{"Онана", "Сетка", "журнал", "Комсомолькая правда", 2000, 3},
       Publication("Бейл", "Скорость - это сила?", "книга", "Москва","Правда",2005),
       Publication{"Криро", "В здоровом теле", "журнал", "EA Sports", 2013, 4},
    };
    cout << "Все публикации:\n\n";
    vector<Publication> journalPublications;
    for (const auto& publication : publications) {
        if (isJournal(publication)) {
            journalPublications.push_back(publication);
        }
        cout << "Автор:" << publication.author <<"\n" << "Название публикации:" << publication.title <<"\n"
            << "Тип:" <<publication.type << "\n\n";
    }
    cout << "\n";

    sort(journalPublications.begin(), journalPublications.end(), compareByAuthor);
    cout << "Журналы:\n";
    for (const auto& publication : journalPublications) {
        std::cout << publication.author << ": " << publication.title << "\n";
    }

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
