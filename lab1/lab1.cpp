#include "pch.h"
using namespace System;

int main() {
    Console::OutputEncoding = Text::Encoding::UTF8;

    while (true) {
        Console::WriteLine("Оберіть режим роботи:");
        Console::WriteLine("1. Додати слова на початок і в кінець рядка.");
        Console::WriteLine("2. Підрахувати кількість заданого символу у фразі.");
        Console::WriteLine("0. Вийти.");
        Console::Write("Ваш вибір: ");

        String^ choice = Console::ReadLine();

        if (choice == "1") {
            Console::Write("Введіть початковий рядок: ");
            String^ phrase = Console::ReadLine();
            Console::Write("Введіть слово для додавання на початок: ");
            String^ prefix = Console::ReadLine();
            Console::Write("Введіть слово для додавання в кінець: ");
            String^ suffix = Console::ReadLine();

            String^ result = prefix + phrase + suffix;
            Console::WriteLine("Одержаний рядок: {0}", result);
            Console::WriteLine("Довжина одержаного рядка: {0}", result->Length);
        }
        else if (choice == "2") {
            Console::Write("Введіть фразу: ");
            String^ phrase = Console::ReadLine();
            Console::Write("Введіть символ, який потрібно знайти: ");
            wchar_t searchChar = Char::ToLower(Console::ReadLine()[0]);

            int count = 0;
            for each (wchar_t c in phrase) {
                if (Char::ToLower(c) == searchChar) {
                    count++;
                }
            }
            Console::WriteLine("Символ '{0}' зустрічається {1} раз(ів) у фразі.", searchChar, count);
        }
        else if (choice == "0") {
            Console::WriteLine("Програма завершена.");
            break;
        }
        else {
            Console::WriteLine("Неправильний вибір. Спробуйте ще раз.");
        }

        Console::WriteLine();

    return 0;
}
