#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string fileName;
    cout << "Podaj nazwe pliku: ";
    cin >> fileName;

    fstream file;
    file.open(fileName.c_str(), ios::in | ios::out | ios::app);

    if (!file)
    {
        cout << "Nie mo¿na otworzyc pliku.";
        return 1;
    }

    int choice;
    while (true)
    {
        cout << "\nWybierz jedna z poni¿szych opcji:\n";
        cout << "1 - Zapisz do pliku\n";
        cout << "2 - Odczytaj z pliku\n";
        cout << "3 - Wyjdz z programu\n";
        cin >> choice;

        if (choice == 1)
        {
            string text;
            cout << "Wpisz tekst: ";
            cin >> text;
            file << text << endl;
        }
        else if (choice == 2)
        {
            string line;
            while (getline(file, line))
            {
                cout << line << endl;
            }
        }
        else if (choice == 3)
        {
            file.close();
            return 0;
        }
        else
        {
            cout << "Nieprawidlowa opcja.";
        }
    }

    return 0;
}

