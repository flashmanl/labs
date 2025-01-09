#include "pch.h" 
using namespace System; 

int main() {
    // Встановлення кодування консолі на UTF-8 для роботи з символами різних мов
    Console::OutputEncoding = Text::Encoding::UTF8;

    // Безкінечний цикл для повторення роботи програми, поки користувач не вибере вихід
    while (true) {
        // Головне меню
        Console::WriteLine("Оберіть режим роботи:");
        Console::WriteLine("1. Додати слова на початок і в кінець рядка.");
        Console::WriteLine("2. Підрахувати кількість заданого символу у фразі.");
        Console::WriteLine("0. Вийти.");
        Console::Write("Ваш вибір: ");

        // Зчитування вибору користувача
        String^ choice = Console::ReadLine();

        // Вибір користувача
        if (choice == "1") {
            //Додавання слів на початок і в кінець рядка
            Console::Write("Введіть початковий рядок: ");
            String^ phrase = Console::ReadLine();
            Console::Write("Введіть слово для додавання на початок: ");
            String^ prefix = Console::ReadLine();
            Console::Write("Введіть слово для додавання в кінець: ");
            String^ suffix = Console::ReadLine();

            // Формування нового рядка
            String^ result = prefix + phrase + suffix;
            Console::WriteLine("Одержаний рядок: {0}", result);
            Console::WriteLine("Довжина одержаного рядка: {0}", result->Length); // Довжина рядка
        }
        else if (choice == "2") {
            Console::Write("Введіть фразу: ");
            String^ phrase = Console::ReadLine();
            Console::Write("Введіть символ, який потрібно знайти: ");
            wchar_t searchChar = Char::ToLower(Console::ReadLine()[0]);

            int count = 0;
            // Перебір символів у фразі
            for each (wchar_t c in phrase) {
                if (Char::ToLower(c) == searchChar) {
                    count++;
                }
            }
            // Виведення результату
            Console::WriteLine("Символ '{0}' зустрічається {1} раз(ів) у фразі.", searchChar, count);
        }
        else if (choice == "0") {
            Console::WriteLine("Програма завершена.");
            break;
        }
        else {
            Console::WriteLine("Неправильний вибір. Спробуйте ще раз.");
        }

        Console::WriteLine(); // Порожній рядок для зручності читання виводу
    }

    return 0;
}

