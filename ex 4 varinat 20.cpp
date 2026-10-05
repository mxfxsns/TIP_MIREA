#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Проверяет, существует ли треугольник с заданными сторонами
bool canBuildTriangle(double a, double b, double c) {
    return a > 0 && b > 0 && c > 0 &&
           a + b > c &&
           a + c > b &&
           b + c > a;
}

// Решает квадратный многочлен ax^2 + bx + c = 0
void solvePolynomial(double a, double b, double c) {
    const double EPS = 1e-9;

    // Если a = 0, уравнение становится линейным или тождественным
    if (abs(a) < EPS) {
        if (abs(b) < EPS) {
            if (abs(c) < EPS) {
                cout << "Корнем является любое действительное число." << endl;
            } else {
                cout << "Корней нет." << endl;
            }
        } else {
            double x = -c / b;
            cout << "Корень: x = " << x << endl;
        }
        return;
    }

    // Вычисляем дискриминант квадратного уравнения
    double discriminant = b * b - 4 * a * c;

    if (discriminant < -EPS) {
        cout << "Действительных корней нет." << endl;
    } else if (abs(discriminant) < EPS) {
        double x = -b / (2 * a);
        cout << "Один корень: x = " << x << endl;
    } else {
        double sqrtDiscriminant = sqrt(discriminant);
        double x1 = (-b + sqrtDiscriminant) / (2 * a);
        double x2 = (-b - sqrtDiscriminant) / (2 * a);

        cout << "Два корня: x1 = " << x1 << ", x2 = " << x2 << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Ввод коэффициентов многочлена
    double a, b, c;
    cin >> a >> b >> c;

    // Ввод символа, определяющего необходимое действие
    int symbol;
    cin >> symbol;

    // Выполнение действия в зависимости от выбранного символа
    switch (symbol) {
        case 1:
            // Вывод фамилии и имени студента
            cout << "ИВАНОВ ИВАН" << endl;
            break;

        case 2:
            // Поиск корней квадратного многочлена
            solvePolynomial(a, b, c);
            break;

        case 3: {
            // Ввод трех сторон треугольника
            double sideA, sideB, sideC;
            cin >> sideA >> sideB >> sideC;

            if (canBuildTriangle(sideA, sideB, sideC)) {
                cout << "Треугольник построить можно." << endl;
            } else {
                cout << "Треугольник построить нельзя." << endl;
            }

            break;
        }

        default:
            cout << "Некорректный символ." << endl;
            break;
    }

    return 0;
}