#pragma once

namespace Project6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:	
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		double x1, x2, y1, y2, yyy1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;

	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ действияToolStripMenuItem;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ обновитьToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox7;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::GroupBox^ groupBox11;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TrackBar^ trackBar2;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TrackBar^ trackBar3;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::GroupBox^ groupBox8;




	private: System::Windows::Forms::TrackBar^ trackBar1;

	int ZoomX(double x);
	int ZoomY(double y);
	double func(double x);


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;

	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:

	private:
		int xx1, xx2, yy1, yy2;
		Graphics^ canvas;
		List <Point> points;
		Pen^ pen;
		bool draw;
		Bitmap^ background;
		Color color;
		Bitmap^ texture;
		double size;
		bool clearAll;
		String^ filename;
		int statePen;
		/*
			statePen = 1 - линия
			statePen = 2 - квадрат
			statePen = 3 - круг
			statePen = 4 - текстура
		*/
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->действияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->обновитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox11->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(191, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Количество точек по горизонтали, n";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Левая граница, х1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(4, 80);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(110, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Верхняя граница, у1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 107);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(108, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Нижняя граница, у2";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(213, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"100";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(213, 50);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 7;
			this->textBox2->Text = L"-1";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(213, 104);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 9;
			this->textBox4->Text = L"-1";
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(213, 77);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 10;
			this->textBox5->Text = L"10";
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::LemonChiffon;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(619, 311);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(159, 48);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Вывести график";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(19, 37);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(400, 400);
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->действияToolStripMenuItem,
					this->выходToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1188, 24);
			this->menuStrip1->TabIndex = 13;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// действияToolStripMenuItem
			// 
			this->действияToolStripMenuItem->Name = L"действияToolStripMenuItem";
			this->действияToolStripMenuItem->Size = System::Drawing::Size(12, 20);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::выходToolStripMenuItem_Click);
			// 
			// обновитьToolStripMenuItem
			// 
			this->обновитьToolStripMenuItem->Name = L"обновитьToolStripMenuItem";
			this->обновитьToolStripMenuItem->Size = System::Drawing::Size(32, 19);
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->numericUpDown);
			this->groupBox7->Location = System::Drawing::Point(619, 241);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(159, 49);
			this->groupBox7->TabIndex = 14;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Размер популяции";
			// 
			// numericUpDown
			// 
			this->numericUpDown->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDown->Location = System::Drawing::Point(11, 19);
			this->numericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
			this->numericUpDown->Name = L"numericUpDown";
			this->numericUpDown->Size = System::Drawing::Size(138, 20);
			this->numericUpDown->TabIndex = 10;
			this->numericUpDown->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->numericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::SandyBrown;
			this->button3->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(906, 320);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(141, 46);
			this->button3->TabIndex = 15;
			this->button3->Text = L"Начать";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(453, 186);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(144, 76);
			this->groupBox1->TabIndex = 16;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Кодирование";
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->radioButton2->Location = System::Drawing::Point(32, 42);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(104, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Целочисленное";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->radioButton1->Location = System::Drawing::Point(32, 19);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(100, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Вещественное";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// groupBox11
			// 
			this->groupBox11->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->groupBox11->Controls->Add(this->label6);
			this->groupBox11->Controls->Add(this->label8);
			this->groupBox11->Controls->Add(this->label9);
			this->groupBox11->Controls->Add(this->trackBar2);
			this->groupBox11->Location = System::Drawing::Point(806, 37);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Size = System::Drawing::Size(357, 70);
			this->groupBox11->TabIndex = 22;
			this->groupBox11->TabStop = false;
			this->groupBox11->Text = L"Мутации";
			this->groupBox11->Enter += gcnew System::EventHandler(this, &MyForm::groupBox11_Enter);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label6->Location = System::Drawing::Point(315, 40);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(36, 17);
			this->label6->TabIndex = 23;
			this->label6->Text = L"25%";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label8->Location = System::Drawing::Point(265, 21);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(33, 13);
			this->label8->TabIndex = 20;
			this->label8->Text = L"100%";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label9->Location = System::Drawing::Point(26, 19);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(21, 13);
			this->label9->TabIndex = 19;
			this->label9->Text = L"0%";
			// 
			// trackBar2
			// 
			this->trackBar2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->trackBar2->Location = System::Drawing::Point(30, 29);
			this->trackBar2->Maximum = 100;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(268, 45);
			this->trackBar2->TabIndex = 22;
			this->trackBar2->Value = 25;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar2_Scroll);
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->trackBar1);
			this->groupBox2->Location = System::Drawing::Point(806, 117);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(357, 73);
			this->groupBox2->TabIndex = 23;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Порог отсечения";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label7->Location = System::Drawing::Point(315, 36);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(36, 17);
			this->label7->TabIndex = 23;
			this->label7->Text = L"50%";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label10->Location = System::Drawing::Point(265, 21);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(33, 13);
			this->label10->TabIndex = 20;
			this->label10->Text = L"100%";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label11->Location = System::Drawing::Point(26, 19);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(21, 13);
			this->label11->TabIndex = 19;
			this->label11->Text = L"0%";
			// 
			// trackBar1
			// 
			this->trackBar1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->trackBar1->Location = System::Drawing::Point(23, 36);
			this->trackBar1->Maximum = 100;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(268, 45);
			this->trackBar1->TabIndex = 22;
			this->trackBar1->Value = 50;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->groupBox3->Controls->Add(this->label12);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Controls->Add(this->trackBar3);
			this->groupBox3->Location = System::Drawing::Point(806, 209);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(357, 80);
			this->groupBox3->TabIndex = 24;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Вероятность скрещивания";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label12->Location = System::Drawing::Point(315, 36);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(36, 17);
			this->label12->TabIndex = 23;
			this->label12->Text = L"90%";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label13->Location = System::Drawing::Point(265, 21);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(33, 13);
			this->label13->TabIndex = 20;
			this->label13->Text = L"100%";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label14->Location = System::Drawing::Point(26, 19);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(21, 13);
			this->label14->TabIndex = 19;
			this->label14->Text = L"0%";
			// 
			// trackBar3
			// 
			this->trackBar3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->trackBar3->Location = System::Drawing::Point(23, 36);
			this->trackBar3->Maximum = 100;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(268, 45);
			this->trackBar3->TabIndex = 22;
			this->trackBar3->Value = 90;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar3_Scroll);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->numericUpDown1);
			this->groupBox4->Location = System::Drawing::Point(619, 186);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(159, 49);
			this->groupBox4->TabIndex = 25;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Количество итераций";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(11, 19);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(138, 20);
			this->numericUpDown1->TabIndex = 11;
			this->numericUpDown1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->label5);
			this->groupBox5->Controls->Add(this->label1);
			this->groupBox5->Controls->Add(this->label2);
			this->groupBox5->Controls->Add(this->label4);
			this->groupBox5->Controls->Add(this->textBox1);
			this->groupBox5->Controls->Add(this->textBox2);
			this->groupBox5->Controls->Add(this->textBox4);
			this->groupBox5->Controls->Add(this->textBox5);
			this->groupBox5->Location = System::Drawing::Point(453, 37);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(325, 133);
			this->groupBox5->TabIndex = 26;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"График";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(6, 16);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(0, 16);
			this->label15->TabIndex = 27;
			this->label15->Click += gcnew System::EventHandler(this, &MyForm::label15_Click);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(6, 21);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(0, 16);
			this->label16->TabIndex = 28;
			// 
			// groupBox6
			// 
			this->groupBox6->BackColor = System::Drawing::Color::SandyBrown;
			this->groupBox6->Controls->Add(this->label15);
			this->groupBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox6->Location = System::Drawing::Point(453, 347);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(144, 46);
			this->groupBox6->TabIndex = 29;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Координата X";
			this->groupBox6->Enter += gcnew System::EventHandler(this, &MyForm::groupBox6_Enter);
			// 
			// groupBox8
			// 
			this->groupBox8->BackColor = System::Drawing::Color::SandyBrown;
			this->groupBox8->Controls->Add(this->label16);
			this->groupBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox8->Location = System::Drawing::Point(453, 276);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(144, 46);
			this->groupBox8->TabIndex = 30;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Координата Y";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(1188, 453);
			this->Controls->Add(this->groupBox8);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox11);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная работа №2";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox11->ResumeLayout(false);
			this->groupBox11->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			this->groupBox4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e);
private: System::Void trackBar3_Scroll(System::Object^ sender, System::EventArgs^ e);
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox11_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label15_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox6_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label17_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

};
}
