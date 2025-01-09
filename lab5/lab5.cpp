#include "pch.h"
#include <cliext/vector>

using namespace System;
using namespace cliext;

void CalculateWaterFlow() {
    const double PI = 3.14;

    double np, delta_p, L;
    int n;

    Console::Write("Введіть в'язкість рідини: ");
    np = Convert::ToDouble(Console::ReadLine());
    Console::Write("Введіть падіння тиску: ");
    delta_p = Convert::ToDouble(Console::ReadLine());
    Console::Write("Введіть довжину труби: ");
    L = Convert::ToDouble(Console::ReadLine());

    Console::Write("Введіть кількість радіусів: ");
    n = Convert::ToInt32(Console::ReadLine());

    vector<double>^ radii = gcnew vector<double>(n);
    Console::WriteLine("Введіть {0} значень радіусів:", n);
    for (int i = 0; i < n; i++) {
        Console::Write("R[{0}]: ", i + 1);
        radii[i] = Convert::ToDouble(Console::ReadLine());
    }

    vector<double>^ flowRates = gcnew vector<double>(n);
    for (int i = 0; i < n; i++) {
        double R = radii[i];
        flowRates[i] = (PI * pow(R, 4) * delta_p) / (8 * np * L);
    }

    Console::WriteLine("{0,-15}{1,-20}", "Радіус ", "Об'ємна витрата ");
    Console::WriteLine(gcnew String('-', 35));
    for (int i = 0; i < n; i++) {
        Console::WriteLine("{0,-15:F2}{1,-20:F2}", radii[i], flowRates[i]);
    }
}

void MultiplyMatrices() {
    int rows1, cols1, rows2, cols2;

    Console::Write("Введіть кількість рядків першої матриці: ");
    rows1 = Int32::Parse(Console::ReadLine());
    Console::Write("Введіть кількість стовпців першої матриці: ");
    cols1 = Int32::Parse(Console::ReadLine());

    Console::Write("Введіть кількість рядків другої матриці: ");
    rows2 = Int32::Parse(Console::ReadLine());
    Console::Write("Введіть кількість стовпців другої матриці: ");
    cols2 = Int32::Parse(Console::ReadLine());

    if (cols1 != rows2) {
        Console::WriteLine("Помилка: кількість стовпців першої матриці має дорівнювати кількості рядків другої матриці.");
        return;
    }

    array<int, 2>^ mat1 = gcnew array<int, 2>(rows1, cols1);
    array<int, 2>^ mat2 = gcnew array<int, 2>(rows2, cols2);
    array<int, 2>^ result = gcnew array<int, 2>(rows1, cols2);

    Console::WriteLine("Введіть елементи матриці A по рядках, розділяючи їх пробілами:");
    for (int i = 0; i < rows1; i++) {
        Console::Write("Рядок {0}: ", i + 1);
        String^ line = Console::ReadLine();
        array<String^>^ elements = line->Split(' ');
        for (int j = 0; j < cols1; j++) {
            mat1[i, j] = Int32::Parse(elements[j]);
        }
    }

    Console::WriteLine("Введіть елементи матриці B по рядках, розділяючи їх пробілами:");
    for (int i = 0; i < rows2; i++) {
        Console::Write("Рядок {0}: ", i + 1);
        String^ line = Console::ReadLine();
        array<String^>^ elements = line->Split(' ');
        for (int j = 0; j < cols2; j++) {
            mat2[i, j] = Int32::Parse(elements[j]);
        }
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i, j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i, j] += mat1[i, k] * mat2[k, j];
            }
        }
    }

    Console::WriteLine("Результат множення матриць:");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            Console::Write("{0,5}", result[i, j]);
        }
        Console::WriteLine();
    }
}

int main() {
    Console::OutputEncoding = Text::Encoding::UTF8;

    while (true) {
        Console::WriteLine("Оберіть режим роботи:");
        Console::WriteLine("1. Розрахунок об'ємних витрат води.");
        Console::WriteLine("2. Множення матриць.");
        Console::WriteLine("0. Вийти.");
        Console::Write("Ваш вибір: ");

        String^ choice = Console::ReadLine();

        if (choice == "1") {
            CalculateWaterFlow();
        }
        else if (choice == "2") {
            MultiplyMatrices();
        }
        else if (choice == "0") {
            Console::WriteLine("Програма завершена.");
            break;
        }
        else {
            Console::WriteLine("Неправильний вибір. Спробуйте ще раз.");
        }

        Console::WriteLine();
    }

    return 0;
}

