#include "realcoding.h"
#include "MyForm.h"
#include "Math.h"
#include "Windows.h"
#include "stdio.h"
#include <ctime>
#include "realcoding.h"

int  realcoding::get() {
    return  _memb;
}
void realcoding::set(int a) {
     _memb = a;
}


class Creature //Класс особи с генами X, Y
{
public:
    double X, Y;
    Creature()
    {
        X = (double)rand() - (double)rand();
        Y = X * X + 4;
    };
};

class Population //Класс популяция с массивом класса особей
{
    int size;
    Creature* Array;
public:
    Population(int n)
    {
        size = n;
        Array = new Creature[size];
    }
    Creature& operator[](int n)
    {
        return Array[n];
    }
};

class GeneticAlgorithm
{
    int size = 1000; //размер популяции
    int count = size; //текущий размер популяции
    Population A = Population(size); //Формируем популяцию
public:
    Creature Algorithm() //Основной алгоритм
    {
        int i, max_i = 100;
        for (i = 0; i < max_i; i++) // Количество итераций
        {
            Crossing(); //Скрещивание
            Mutation(); //Мутация
            Sort(); //Сортировка и рассчет приспособленности
            Selection(); //Селекция усечением
            if (fabs(A[0].Y - A[count].Y) <= 0.001) break; //Оценивание популяции
        }
        return A[0];
    }

    double func(double x)
    {
        return x * x + 4;
    }

    void Sort()
    {
        int i, j, h;
        for (i = 0; i < count; i++)
            A[i].Y = func(A[i].X); // рассчет приспособенности
        for (h = 1; h <= count / 9; h = h * 3 + 1); //сортировка Шелла
        while (h >= 1)
        {
            for (i = h; i < count; i++)
                for (j = i - h; (j >= 0) && (A[j].Y > A[j + h].Y); j -= h)
                {
                    Creature temp = A[j];
                    A[j] = A[j + h];
                    A[j + h] = temp;
                }
            h = (h - 1) / 3;
        }
    }

    void Selection()
    {
        double l = 0.5; //порог отсечения
        for (int i = size - 1; i > (l * size); i--) //очищаем наименее приспособленные особи
        {
            A[i].X = 0;
            A[i].Y = 0;
            count--;
        }
    }

    void Crossing()
    {
        int old_size = count; //Для формирования потомков
        double p = 0.9; //Вероятность скрещивания
        while (count < size) //Восстанавливаем количество потомков
        {
            int i = (int)(rand() % old_size);
            int j = (int)(rand() % old_size);
            double lambda = rand() % 10 * 0.01;
            if (p > (rand() % 10) * 0.01) //Скрещивание с вероятностью Р
            {
                A[count++].X = lambda * A[i].X + (1 - lambda) * A[j].X;
                A[count++].X = lambda * A[j].X + (1 - lambda) * A[i].X;
            }
        }
        count--;
    }

    void Mutation()
    {
        double mutate = 0.25; //вероятность мутации
        for (int i = 0; i < count; i++)
        {
            if (mutate > rand() % 100 * 0.01)
            {
                A[i].X += (((double)rand() / RAND_MAX) - 0.25) * 100;
            }
        }
    }
};