#include "MyForm.h"
#include "Math.h"
#include "Windows.h"
#include "stdio.h"
#include <ctime>
#include <iostream>


#pragma comment(lib,"user32.lib")

using namespace System;
using namespace System::Windows::Forms;

int popsize, numiter;
double Prg, permut, procsb;
double* SrPoints = new double[1000];
double* MinPoints = new double[1000];
int k = 0;


class individual //Класс "Особь", содержащий массив генов
{
public:
    double X, fitness; // X - Хромосома, fitness- значение приспобленности
    individual()
    {
        X = (double)(rand() % (1000 - (-1000) + 1) + (-1000)) / 100; // случайная генерациия гена
    };
};

class Population //Класс "Популяция",содержащий массив объектов класса "Особь"
{
    int size;
    individual* Array;
public:
    Population(int n)
    {
        size = n;
        Array = new individual[size];
    }
    individual& operator[](int n) // перегрузка оператора индексирования
    {                             // для доступа к элементам через индекс
        return Array[n];
    }
};

class GeneticAlgorithm // управляющий класс
{
    int size = popsize; //начальный размер популяции
    int sizeN = size; //размер популяции, который будет изменяться во время работы программы
    Population A = Population(size); //Формирование популяции
public:
    individual GenAlgorithm()
    {
        for (int i = 0; i < numiter; i++) // Количество итераций
        {
            Assessment(); //Метод, выполняющий рассчет приспособленности и сортировку по значению оценочной функции 
            TruncSelection(); //Метод, благодаря которому осуществляется отбор особей
            Crossbreeding(); //Метод, который реализует скрещивание особей
            Mutation(); //Метод, отвечающий за мутацию
            Graphic(); // для графика
            
            if (fabs(A[0].fitness - A[sizeN - 1].fitness) <= 0.001) break; // проверка на вырожденную популяцию
        }
        k = 0; return A[0];
    }

    double func(double x)// возвращает значение функции от параметра
    {
        return (x * x + 4); // оценочная функция
    }

    void Graphic()// нахождение минимального значения и среднего значения функции по итерациям
    {
        double sum = 0;
        double min = 99999;
        for (int i = 0; i < sizeN; i++)
        {
            sum += func(A[i].X);
            if (min > func(A[i].X)) 
                min = func(A[i].X);
        }
        sum = sum / sizeN;
        SrPoints[k] = sum;
        MinPoints[k] = min;
        k++;
    }

    void Assessment()
    {
        int h;
        for (int i = 0; i < sizeN; i++) // рассчет оценочной функции(приспобленности)
            A[i].fitness = func(A[i].X); 
        for (h = 1; h <= sizeN / 9; h = h * 3 + 1); //сортировка Шелла (Индекс у более приспобленных меньше)
        while (h >= 1)
        {
            for (int i = h; i < sizeN; i++)
                for (int j = i - h; (j >= 0) && (A[j].fitness > A[j + h].fitness); j -= h)
                {
                    individual temp = A[j];
                    A[j] = A[j + h];
                    A[j + h] = temp;
                }
            h = (h - 1) / 3;
        }
    }

    void TruncSelection()// селекция усечением
    {
        double l = Prg/100; //порог отсечения
        for (int i = size - 1; i > (l * size); i--) //удаляем наименее приспособленные особи
        {
            A[i].X = NULL;
            A[i].fitness = NULL;
            sizeN--;
        }
    }

    void Crossbreeding() // Метод, осуществляющий арифметический кроссинговер
    {
        int Size = sizeN; 
        double p = procsb/100; //Вероятность скрещивания
        while (sizeN < size) //цикл будет до тех пор, пока число особей не вернется к первоначальному количеству
        {
            int i = (int)(rand() % Size);
            int j = (int)(rand() % Size);
            double L = rand() % 100 * 0.01;
            if (p > (rand() % 100) * 0.01) 
            {
                A[sizeN++].X = L * A[i].X + (1 - L) * A[j].X;
            }
        }
        sizeN--;
    }

    void Mutation()
    {
        double mut = permut/100; //вероятность мутации
        for (int i = 0; i < sizeN; i++)
        {
            if (mut > rand() % 100 * 0.01)
            {
                A[i].X += (rand() % 50) * 0.01 - (rand() % 50) * 0.01;
            }
        }
    }
};

class individual2
{
    int xmin = -10;
    int xmax = 10;
public:
    double X, fitness; // X - Хромосома, fitness- значение приспобленности
    bool* string;
    int size = 10;//разрядность
    individual2()
    {
        string = new bool[size];
        for (int i = 0; i < size; i++)
        {
            string[i] = rand() % 2; // случайная генерациия гена
        }
    };

    void decode() //метод декодирования, 
    {             //для перевода закодированного двоичного значения гена в дробное;
        double value = 0.0; double razryad = 1;
        for (int j = size - 1; j >= 0; j--)
        {
            if (string[j]) value = value + razryad;
            razryad = razryad * 2;
        }
        X = xmin + (xmax - xmin) * value / (razryad - 1);
        fitness = X * X + 4;
    };
};

class Population2 //Класс Популяция, содержащий массив объектов класса Особь
{
    int size;
    individual2* Array;
public:
    Population2(int n)
    {
        size = n;
        Array = new individual2[size];
    }

    individual2& operator[](int n)// перегрузка оператора индексирования
    {                             // для доступа к элементам через индекс
        return Array[n];
    }
};

class GeneticAlgorithm1
{
    int size = popsize; //начальный размер популяции
    int sizeN = size; //размер популяции, который будет изменяться во время работы программы
    Population2 A = Population2(size); //формирование популяции
public:
    individual2 Algorithm1() //Основной алгоритм
    {
        int i;
        for (i = 0; i < numiter; i++) // Количество итераций
        { 

            Crossing1(); //Метод, который реализует скрещивание особей
            Mutation1(); //Метод, отвечающий за мутацию
            Assessment(); //Метод, выполняющий рассчет приспособленности и сортировку по значению оценочной функции 
            TruncSelection(); //Метод, благодаря которому осуществляется отбор особей
            Graphic();

            if (abs(A[0].fitness - A[sizeN].fitness) <= 0.001) break; // проверка на вырожденную популяцию
        }
        k = 0; 
        return A[0];
    }

    double func(double x) // возвращает значение функции от параметра
    {
        return x * x + 4;
    }

    void Assessment()
    {
        int h;
        for (int i = 0; i < sizeN; i++)
            A[i].fitness = func(A[i].X);  // рассчет оценочной функции(приспобленности)
        for (h = 1; h <= sizeN / 9; h = h * 3 + 1); //сортировка Шелла
        while (h >= 1)
        {
            for (int i = h; i < sizeN; i++)
                for (int j = i - h; j >= 0 && A[j].fitness > A[j + h].fitness; j -= h)
                {
                    individual2 temp = A[j];
                    A[j] = A[j + h];
                    A[j + h] = temp;
                }
            h = (h - 1) / 3;
        }
    }
    void Graphic()// нахождение минимального значения и среднего значения функции по итерациям
    {
        double sum = 0;
        double min = 99999;
        for (int i = 0; i < sizeN; i++)
        {
            sum += func(A[i].X);
            if (min > func(A[i].X))
                min = func(A[i].X);
        }
        sum = sum / sizeN;
        SrPoints[k] = sum;
        MinPoints[k] = min;
        k++;
    }
    void TruncSelection()
    {
        double l = Prg / 100; //порог отсечения
        for (int i = size - 1; i > (l * size); i--) //удаляет наименее приспособленные особи
        {
            for (int j = 0; j < 10; j++)
            {
                A[i].string[j] = 0;
            }
            A[i].decode();
            sizeN--;
        }
    }

    void Crossing1() // Скрещивание особей с помощью 1 - точечного кроссинговера
    {
        int R = rand() % (10 - 2) + 1;// случайная точка разрыва
        double p = procsb / 100; //Вероятность скрещивания
        int Size = sizeN; //Для формирования потомков
        while (sizeN < size) //Восстанавливаем количество потомков
        {
            int i = (int)(rand() % Size);
            int j = (int)(rand() % Size);
            if (p > (rand() % 100) * 0.01) // вероятность скрещивания
            {
                for (int r = 0; r < R; r++) // гены до 1 точки разрыва
                {
                    A[sizeN].string[r] = A[i].string[r];
                }
                for (int t = R; t < 10; t++) // гены после 1 точки разрыва
                {
                    A[sizeN].string[t] = A[j].string[t];
                }
                A[sizeN].decode();
                sizeN++;
            }
        }
    };

    void Mutation1() // битовая мутация
    {
        double mut = permut / 100; //вероятность мутации
        for (int i = 0; i < sizeN; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (mut > rand() % 100 * 0.01)
                {
                    A[i].string[j] = !A[i].string[j];
                }
            }
            A[i].decode();
        }
    };
};


struct Vector2D
{
    int x, y;
};

Vector2D mousePosition;

System::Void Project6::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    popsize = System::Convert::ToInt32(Project6::MyForm::numericUpDown->Value);// число особей
    Prg =  System::Convert::ToInt32(trackBar1->Value); // порог отсечения
    permut =  System::Convert::ToInt32(trackBar2->Value); // вероятность мутации
    procsb =  System::Convert::ToInt32(trackBar3->Value); // вероятность скрещивания 
    numiter =  System::Convert::ToInt32(Project6::MyForm::numericUpDown1->Value); // число итераций
	if (radioButton1->Checked)
	{
        srand(time(0));
        GeneticAlgorithm GA;
        individual result = GA.GenAlgorithm();
        label15->Text = System::Convert::ToString(result.X);
        label16->Text = System::Convert::ToString(result.fitness);
	}
    if (radioButton2->Checked)
    {
        srand(time(0));
        GeneticAlgorithm1 GA;
        individual2 result = GA.Algorithm1();
        label15->Text = System::Convert::ToString(result.X);
        label16->Text = System::Convert::ToString(result.fitness);
    }

    return System::Void();
}

System::Void Project6::MyForm::trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    label6->Text = System::Convert::ToString(trackBar2->Value)+" %";
}

System::Void Project6::MyForm::trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    label7->Text = System::Convert::ToString(trackBar1->Value) + " %";
}

System::Void Project6::MyForm::trackBar3_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    label12->Text = System::Convert::ToString(trackBar3->Value) + " %";
}
int Project6::MyForm::ZoomX(double x) // масштаб 
{
    int ret;
    ret = xx1 + (int)((x - x1) * (xx2 - xx1) / (x2 - x1));
    return ret;
}

int Project6::MyForm::ZoomY(double y) // масштаб 
{
    int ret;
    ret = yy2 + (int)((y - y1) * (yy1 - yy2) / (y2 - y1));
    return ret;
}

double Project6::MyForm::func(double x)
{
    double ret;
    ret = x * x + 4; // функция, для которой строится график
    return ret;
}
System::Void Project6::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    pictureBox1->Refresh();
    Graphics^ Графика = pictureBox1->CreateGraphics();
    Графика->Clear(SystemColors::Control);
    int tx, ty, rx, ry;
    int i;
    double x, y;
    int n = Convert::ToInt32(textBox1->Text);
    x1 = Convert::ToDouble(textBox2->Text);
    x2 = numiter;
    y1 = Convert::ToDouble(textBox4->Text);
    y2 = Convert::ToDouble(textBox5->Text);


    // 1. Установка границ экранных координат
    xx1 = 0;
    yy1 = 0;
    xx2 = pictureBox1->Width;
    yy2 = pictureBox1->Height;

    // 2. Рисование графика

    Brush^ Заливка = gcnew SolidBrush(Color::White);

    Pen^ Перо = gcnew Pen(Color::Black);
    Графика->DrawRectangle(Перо, 0, 0, pictureBox1->Width, pictureBox1->Height);

    // 2.1. Рисование осей координат
    pen = gcnew Pen(Color::Black, size);
    // 2.2. Взять экранную точку начала координат X
    rx = ZoomX(0);
    ry = ZoomY(y1);
    // провести линию оси координат X
    tx = ZoomX(0);
    ty = ZoomY(y2);
    Графика->DrawLine(System::Drawing::Pens::Black, rx, ry, tx, ty);

    // 2.3. Точка начала координат Y
    rx = ZoomX(x1);
    ry = ZoomY(0);
    // нарисовать ось Y
    tx = ZoomX(x2);
    ty = ZoomY(0);
    Графика->DrawLine(System::Drawing::Pens::Black, rx, ry, tx, ty);

    // 3. Рисование графика функции

    // координаты первой точки
    x = 0.01;
    y = (double)MinPoints[0];
    rx = ZoomX(x);
    ry = ZoomY(y);
    for (i = 1; i < numiter; i++)
    {
        tx = ZoomX(i);
        ty = ZoomY(MinPoints[i]);
        Графика->DrawLine(System::Drawing::Pens::Red, rx, ry, tx, ty);
        rx = tx;
        ry = ty;
    }
    x = 0.01;
    y = SrPoints[0];
    rx = ZoomX(x);
    ry = ZoomY(y);
    for (i = 1; i < numiter; i++)
    {
        tx = ZoomX(i);
        ty = ZoomY(SrPoints[i]); 
        Графика->DrawLine(System::Drawing::Pens::Black, rx, yy2 - 30, rx, yy2 - 45);
        Графика->DrawLine(System::Drawing::Pens::Blue, rx, ry, tx, ty);
        rx = tx;
        ry = ty;
    }
}


System::Void Project6::MyForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();//Выход из приложения
}

int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Project6::MyForm form;
    Application::Run(% form);

}

