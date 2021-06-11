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


class individual //����� "�����", ���������� ������ �����
{
public:
    double X, fitness; // X - ���������, fitness- �������� ���������������
    individual()
    {
        X = (double)(rand() % (1000 - (-1000) + 1) + (-1000)) / 100; // ��������� ���������� ����
    };
};

class Population //����� "���������",���������� ������ �������� ������ "�����"
{
    int size;
    individual* Array;
public:
    Population(int n)
    {
        size = n;
        Array = new individual[size];
    }
    individual& operator[](int n) // ���������� ��������� ��������������
    {                             // ��� ������� � ��������� ����� ������
        return Array[n];
    }
};

class GeneticAlgorithm // ����������� �����
{
    int size = popsize; //��������� ������ ���������
    int sizeN = size; //������ ���������, ������� ����� ���������� �� ����� ������ ���������
    Population A = Population(size); //������������ ���������
public:
    individual GenAlgorithm()
    {
        for (int i = 0; i < numiter; i++) // ���������� ��������
        {
            Assessment(); //�����, ����������� ������� ����������������� � ���������� �� �������� ��������� ������� 
            TruncSelection(); //�����, ��������� �������� �������������� ����� ������
            Crossbreeding(); //�����, ������� ��������� ����������� ������
            Mutation(); //�����, ���������� �� �������
            Graphic(); // ��� �������
            
            if (fabs(A[0].fitness - A[sizeN - 1].fitness) <= 0.001) break; // �������� �� ����������� ���������
        }
        k = 0; return A[0];
    }

    double func(double x)// ���������� �������� ������� �� ���������
    {
        return (x * x + 4); // ��������� �������
    }

    void Graphic()// ���������� ������������ �������� � �������� �������� ������� �� ���������
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
        for (int i = 0; i < sizeN; i++) // ������� ��������� �������(���������������)
            A[i].fitness = func(A[i].X); 
        for (h = 1; h <= sizeN / 9; h = h * 3 + 1); //���������� ����� (������ � ����� ������������� ������)
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

    void TruncSelection()// �������� ���������
    {
        double l = Prg/100; //����� ���������
        for (int i = size - 1; i > (l * size); i--) //������� �������� ��������������� �����
        {
            A[i].X = NULL;
            A[i].fitness = NULL;
            sizeN--;
        }
    }

    void Crossbreeding() // �����, �������������� �������������� ������������
    {
        int Size = sizeN; 
        double p = procsb/100; //����������� �����������
        while (sizeN < size) //���� ����� �� ��� ���, ���� ����� ������ �� �������� � ��������������� ����������
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
        double mut = permut/100; //����������� �������
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
    double X, fitness; // X - ���������, fitness- �������� ���������������
    bool* string;
    int size = 10;//�����������
    individual2()
    {
        string = new bool[size];
        for (int i = 0; i < size; i++)
        {
            string[i] = rand() % 2; // ��������� ���������� ����
        }
    };

    void decode() //����� �������������, 
    {             //��� �������� ��������������� ��������� �������� ���� � �������;
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

class Population2 //����� ���������, ���������� ������ �������� ������ �����
{
    int size;
    individual2* Array;
public:
    Population2(int n)
    {
        size = n;
        Array = new individual2[size];
    }

    individual2& operator[](int n)// ���������� ��������� ��������������
    {                             // ��� ������� � ��������� ����� ������
        return Array[n];
    }
};

class GeneticAlgorithm1
{
    int size = popsize; //��������� ������ ���������
    int sizeN = size; //������ ���������, ������� ����� ���������� �� ����� ������ ���������
    Population2 A = Population2(size); //������������ ���������
public:
    individual2 Algorithm1() //�������� ��������
    {
        int i;
        for (i = 0; i < numiter; i++) // ���������� ��������
        { 

            Crossing1(); //�����, ������� ��������� ����������� ������
            Mutation1(); //�����, ���������� �� �������
            Assessment(); //�����, ����������� ������� ����������������� � ���������� �� �������� ��������� ������� 
            TruncSelection(); //�����, ��������� �������� �������������� ����� ������
            Graphic();

            if (abs(A[0].fitness - A[sizeN].fitness) <= 0.001) break; // �������� �� ����������� ���������
        }
        k = 0; 
        return A[0];
    }

    double func(double x) // ���������� �������� ������� �� ���������
    {
        return x * x + 4;
    }

    void Assessment()
    {
        int h;
        for (int i = 0; i < sizeN; i++)
            A[i].fitness = func(A[i].X);  // ������� ��������� �������(���������������)
        for (h = 1; h <= sizeN / 9; h = h * 3 + 1); //���������� �����
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
    void Graphic()// ���������� ������������ �������� � �������� �������� ������� �� ���������
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
        double l = Prg / 100; //����� ���������
        for (int i = size - 1; i > (l * size); i--) //������� �������� ��������������� �����
        {
            for (int j = 0; j < 10; j++)
            {
                A[i].string[j] = 0;
            }
            A[i].decode();
            sizeN--;
        }
    }

    void Crossing1() // ����������� ������ � ������� 1 - ��������� �������������
    {
        int R = rand() % (10 - 2) + 1;// ��������� ����� �������
        double p = procsb / 100; //����������� �����������
        int Size = sizeN; //��� ������������ ��������
        while (sizeN < size) //��������������� ���������� ��������
        {
            int i = (int)(rand() % Size);
            int j = (int)(rand() % Size);
            if (p > (rand() % 100) * 0.01) // ����������� �����������
            {
                for (int r = 0; r < R; r++) // ���� �� 1 ����� �������
                {
                    A[sizeN].string[r] = A[i].string[r];
                }
                for (int t = R; t < 10; t++) // ���� ����� 1 ����� �������
                {
                    A[sizeN].string[t] = A[j].string[t];
                }
                A[sizeN].decode();
                sizeN++;
            }
        }
    };

    void Mutation1() // ������� �������
    {
        double mut = permut / 100; //����������� �������
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
    popsize = System::Convert::ToInt32(Project6::MyForm::numericUpDown->Value);// ����� ������
    Prg =  System::Convert::ToInt32(trackBar1->Value); // ����� ���������
    permut =  System::Convert::ToInt32(trackBar2->Value); // ����������� �������
    procsb =  System::Convert::ToInt32(trackBar3->Value); // ����������� ����������� 
    numiter =  System::Convert::ToInt32(Project6::MyForm::numericUpDown1->Value); // ����� ��������
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
int Project6::MyForm::ZoomX(double x) // ������� 
{
    int ret;
    ret = xx1 + (int)((x - x1) * (xx2 - xx1) / (x2 - x1));
    return ret;
}

int Project6::MyForm::ZoomY(double y) // ������� 
{
    int ret;
    ret = yy2 + (int)((y - y1) * (yy1 - yy2) / (y2 - y1));
    return ret;
}

double Project6::MyForm::func(double x)
{
    double ret;
    ret = x * x + 4; // �������, ��� ������� �������� ������
    return ret;
}
System::Void Project6::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    pictureBox1->Refresh();
    Graphics^ ������� = pictureBox1->CreateGraphics();
    �������->Clear(SystemColors::Control);
    int tx, ty, rx, ry;
    int i;
    double x, y;
    int n = Convert::ToInt32(textBox1->Text);
    x1 = Convert::ToDouble(textBox2->Text);
    x2 = numiter;
    y1 = Convert::ToDouble(textBox4->Text);
    y2 = Convert::ToDouble(textBox5->Text);


    // 1. ��������� ������ �������� ���������
    xx1 = 0;
    yy1 = 0;
    xx2 = pictureBox1->Width;
    yy2 = pictureBox1->Height;

    // 2. ��������� �������

    Brush^ ������� = gcnew SolidBrush(Color::White);

    Pen^ ���� = gcnew Pen(Color::Black);
    �������->DrawRectangle(����, 0, 0, pictureBox1->Width, pictureBox1->Height);

    // 2.1. ��������� ���� ���������
    pen = gcnew Pen(Color::Black, size);
    // 2.2. ����� �������� ����� ������ ��������� X
    rx = ZoomX(0);
    ry = ZoomY(y1);
    // �������� ����� ��� ��������� X
    tx = ZoomX(0);
    ty = ZoomY(y2);
    �������->DrawLine(System::Drawing::Pens::Black, rx, ry, tx, ty);

    // 2.3. ����� ������ ��������� Y
    rx = ZoomX(x1);
    ry = ZoomY(0);
    // ���������� ��� Y
    tx = ZoomX(x2);
    ty = ZoomY(0);
    �������->DrawLine(System::Drawing::Pens::Black, rx, ry, tx, ty);

    // 3. ��������� ������� �������

    // ���������� ������ �����
    x = 0.01;
    y = (double)MinPoints[0];
    rx = ZoomX(x);
    ry = ZoomY(y);
    for (i = 1; i < numiter; i++)
    {
        tx = ZoomX(i);
        ty = ZoomY(MinPoints[i]);
        �������->DrawLine(System::Drawing::Pens::Red, rx, ry, tx, ty);
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
        �������->DrawLine(System::Drawing::Pens::Black, rx, yy2 - 30, rx, yy2 - 45);
        �������->DrawLine(System::Drawing::Pens::Blue, rx, ry, tx, ty);
        rx = tx;
        ry = ty;
    }
}


System::Void Project6::MyForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();//����� �� ����������
}

int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Project6::MyForm form;
    Application::Run(% form);

}

