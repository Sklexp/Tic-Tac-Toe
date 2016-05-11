#pragma once
#include "TZeroOne3.h"
#include <cstdlib>
#include <ctime>

namespace Test24 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:	
		// Объявление переменной типа нашего рабочего класса TZeroOne
		TZeroOne3 Dot;
		// Переменная куда записывается кто побудил для дальнейшего анализа
		int WinnerFlag = 0;
		// Переменная отвечающая за то, кто сейчас ходит
		bool cheker;
		int flagtruf = 3;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  gameToolStripMenuItem;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::Button^  button10;
		
	public:
	MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			WinnerFlag = 0;
			cheker = true;
		}

	//-----------------------Наши функции-----------------------
	void idButtom(int x, int y, int XO)
	{
		if ((x == 0) && (y == 0))
		{
			if (XO == 3) button1->Text = "O";
			else button1->Text = "X";
			button1->Enabled = false;
		}
		else if ((x == 0) && (y == 1))
		{
			if (XO == 3) button2->Text = "O";
			else button2->Text = "X";
			button2->Enabled = false;
		}
		else if ((x == 0) && (y == 2))
		{
			if (XO == 3) button3->Text = "O";
			else button3->Text = "X";
			button3->Enabled = false;
		}
		else if ((x == 1) && (y == 0))
		{
			if (XO == 3) button4->Text = "O";
			else button4->Text = "X";
			button4->Enabled = false;
		}
		else if ((x == 1) && (y == 1))
		{
			if (XO == 3) button5->Text = "O";
			else button5->Text = "X";
			button5->Enabled = false;
		}
		else if ((x == 1) && (y == 2))
		{
			if (XO == 3) button6->Text = "O";
			else button6->Text = "X";
			button6->Enabled = false;
		}
		else if ((x == 2) && (y == 0))
		{
			if (XO == 3) button7->Text = "O";
			else button7->Text = "X";
			button7->Enabled = false;
		}
		else if ((x == 2) && (y == 1))
		{
			if (XO == 3) button8->Text = "O";
			else button8->Text = "X";
			button8->Enabled = false;
		}
		else
		{
			if (XO == 3) button9->Text = "O";
			else button9->Text = "X";
			button9->Enabled = false;
		}
	}

	// Функция для закрытия двоек
	bool WinCloser(int &x, int &y)
	{
		for (int i = 3; i > 1; i--)
		{
			if ((Dot.GetGamebox(0) == i) && (Dot.GetGamebox(1) == i) && (Dot.GetGamebox(2) == 1)) { x = 0; y = 2; return false; }
			else if ((Dot.GetGamebox(0) == i) && (Dot.GetGamebox(2) == i) && (Dot.GetGamebox(1) == 1)) { x = 0; y = 1; return false; }
			else if ((Dot.GetGamebox(0) == i) && (Dot.GetGamebox(3) == i) && (Dot.GetGamebox(6) == 1)) { x = 2; y = 0; return false; }
			else if ((Dot.GetGamebox(0) == i) && (Dot.GetGamebox(6) == i) && (Dot.GetGamebox(3) == 1)) { x = 1; y = 0; return false; }
			else if ((Dot.GetGamebox(1) == i) && (Dot.GetGamebox(2) == i) && (Dot.GetGamebox(0) == 1)) { x = 0; y = 0; return false; }
			else if ((Dot.GetGamebox(1) == i) && (Dot.GetGamebox(4) == i) && (Dot.GetGamebox(7) == 1)) { x = 2; y = 1; return false; }
			else if ((Dot.GetGamebox(1) == i) && (Dot.GetGamebox(7) == i) && (Dot.GetGamebox(4) == 1)) { x = 1; y = 1; return false; }
			else if ((Dot.GetGamebox(2) == i) && (Dot.GetGamebox(5) == i) && (Dot.GetGamebox(8) == 1)) { x = 2; y = 2; return false; }
			else if ((Dot.GetGamebox(2) == i) && (Dot.GetGamebox(8) == i) && (Dot.GetGamebox(5) == 1)) { x = 1; y = 2; return false; }

			else if ((Dot.GetGamebox(3) == i) && (Dot.GetGamebox(6) == i) && (Dot.GetGamebox(0) == 1)) { x = 0; y = 0; return false; }
			else if ((Dot.GetGamebox(3) == i) && (Dot.GetGamebox(4) == i) && (Dot.GetGamebox(5) == 1)) { x = 1; y = 2; return false; }
			else if ((Dot.GetGamebox(3) == i) && (Dot.GetGamebox(5) == i) && (Dot.GetGamebox(4) == 1)) { x = 1; y = 1; return false; }
			else if ((Dot.GetGamebox(4) == i) && (Dot.GetGamebox(7) == i) && (Dot.GetGamebox(1) == 1)) { x = 0; y = 1; return false; }
			else if ((Dot.GetGamebox(4) == i) && (Dot.GetGamebox(5) == i) && (Dot.GetGamebox(3) == 1)) { x = 1; y = 0; return false; }
			else if ((Dot.GetGamebox(5) == i) && (Dot.GetGamebox(8) == i) && (Dot.GetGamebox(2) == 1)) { x = 0; y = 2; return false; }

			else if ((Dot.GetGamebox(6) == i) && (Dot.GetGamebox(7) == i) && (Dot.GetGamebox(8) == 1)) { x = 2; y = 2; return false; }
			else if ((Dot.GetGamebox(6) == i) && (Dot.GetGamebox(8) == i) && (Dot.GetGamebox(7) == 1)) { x = 2; y = 1; return false; }
			else if ((Dot.GetGamebox(7) == i) && (Dot.GetGamebox(8) == i) && (Dot.GetGamebox(6) == 1)) { x = 2; y = 0; return false; }

			else if ((Dot.GetGamebox(0) == i) && (Dot.GetGamebox(4) == i) && (Dot.GetGamebox(8) == 1)) { x = 2; y = 2; return false; }
			else if ((Dot.GetGamebox(0) == i) && (Dot.GetGamebox(8) == i) && (Dot.GetGamebox(4) == 1)) { x = 1; y = 1; return false; }
			else if ((Dot.GetGamebox(4) == i) && (Dot.GetGamebox(8) == i) && (Dot.GetGamebox(0) == 1)) { x = 0; y = 0; return false; }
			else if ((Dot.GetGamebox(2) == i) && (Dot.GetGamebox(4) == i) && (Dot.GetGamebox(6) == 1)) { x = 2; y = 0; return false; }
			else if ((Dot.GetGamebox(2) == i) && (Dot.GetGamebox(6) == i) && (Dot.GetGamebox(4) == 1)) { x = 1; y = 1; return false; }
			else if ((Dot.GetGamebox(4) == i) && (Dot.GetGamebox(6) == i) && (Dot.GetGamebox(2) == 1)) { x = 0; y = 2; return false; }
		}

		return true;
	}

	// Функция вызывающая Бота
	void bot(int XO)
	{
		if (!Dot.IsFull())
		{
			int Xr, Yr;

			if (XO == 3)
			{
				if (flagtruf >= 4)
				{
					if (WinCloser(Xr, Yr))
						Dot.BotMove(Xr, Yr);
				}
				else
					Dot.BotMove(Xr, Yr);
			}
			else 
			{
				Xr = rand() % 3;
				Yr = rand() % 3;

				while (!Dot.IsEmpty(Xr, Yr))
				{
					Xr = rand() % 3;
					Yr = rand() % 3;
				}
			}

			if (XO == 3)
			{
				Dot.DoMove(Xr, Yr, 'O');
				idButtom(Xr, Yr, 3);
				if (Dot.locality(Xr, Yr, 3) == 3) {
					label2->Text = "O"; label2->Text += " - win"; win(3);
				}
			}
			else
			{
				Dot.DoMove(Xr, Yr, 'X');
				idButtom(Xr, Yr, 2);
				if (Dot.locality(Xr, Yr, 2) == 2) {
					label2->Text = "X"; label2->Text += " - win"; win(2);
				}
			}

			cheker = !cheker;
		}
	}

	// Функция печатающая текущий GameBox
	void printGameBox()
	{
		label1->Text = " ";
		for (int i = 0; i < 9; i++)
			label1->Text += Dot.GetGamebox(i);
	}

	// Функция вызывающаяся после победы и переводит игровое поле в финальное состояние
	void win(int XO)
	{
		button1->Enabled = false;
		button2->Enabled = false;
		button3->Enabled = false;
		button4->Enabled = false;
		button5->Enabled = false;
		button6->Enabled = false;
		button7->Enabled = false;
		button8->Enabled = false;
		button9->Enabled = false;

		WinnerFlag = XO;
	}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				Dot.~TZeroOne3();
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	protected:

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(20, 40);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(70, 70);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(100, 40);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(70, 70);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(180, 40);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(70, 70);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(20, 120);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(70, 70);
			this->button4->TabIndex = 3;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Enabled = false;
			this->button5->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(100, 120);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(70, 70);
			this->button5->TabIndex = 4;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Enabled = false;
			this->button6->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(180, 120);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(70, 70);
			this->button6->TabIndex = 5;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Enabled = false;
			this->button7->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(20, 200);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(70, 70);
			this->button7->TabIndex = 6;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Enabled = false;
			this->button8->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->Location = System::Drawing::Point(100, 200);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(70, 70);
			this->button8->TabIndex = 7;
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Enabled = false;
			this->button9->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->Location = System::Drawing::Point(180, 200);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(70, 70);
			this->button9->TabIndex = 8;
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->newToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(270, 24);
			this->menuStrip1->TabIndex = 9;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->gameToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->newToolStripMenuItem->Text = L"Game";
			// 
			// gameToolStripMenuItem
			// 
			this->gameToolStripMenuItem->Name = L"gameToolStripMenuItem";
			this->gameToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->gameToolStripMenuItem->Text = L"New Game";
			this->gameToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::gameToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(20, 277);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(11, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"*";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(20, 303);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(11, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"*";
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::SystemColors::Control;
			this->button10->Font = (gcnew System::Drawing::Font(L"DendaNewBlackCondC", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button10->Location = System::Drawing::Point(180, 277);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(70, 39);
			this->button10->TabIndex = 12;
			this->button10->Text = L"start";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(270, 360);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Разум из коробка";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (cheker)
		{
			Dot.DoMove(0, 0, 'X');
			button1->Text = "X";
			if (Dot.locality(0, 0, 2) == 2) {
				label2->Text = "X"; label2->Text += " - win"; win(2); return;
			}
		}
		else
		{
			Dot.DoMove(0, 0, 'O');
			button1->Text = "O";
			if (Dot.locality(0, 0, 3) == 3) {
				label2->Text += 'O'; label2->Text += " - win"; win(3); return;
			}
		}		

		button1->Enabled = false;
		cheker = !cheker;
		bot(3);
		printGameBox();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (cheker)
		{
			Dot.DoMove(0, 1, 'X');
			button2->Text = "X";
			if (Dot.locality(0, 1, 2) == 2) {
				label2->Text = "X"; label2->Text += " - win"; win(2); return;
			}
		}
		else
		{
			Dot.DoMove(0, 1, 'O');
			button2->Text = "O";
			if (Dot.locality(0, 1, 3) == 3) {
				label2->Text = "O"; label2->Text += " - win"; win(3); return;
			}
		}

		button2->Enabled = false;
		cheker = !cheker;
		bot(3);
		printGameBox();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (cheker)
		{
			Dot.DoMove(0, 2, 'X');
			button3->Text = "X";
			if (Dot.locality(0, 2, 2) == 2) {
				label2->Text = "X"; label2->Text += " - win"; win(2); return;
			}
		}
		else
		{
			Dot.DoMove(0, 2, 'O');
			button3->Text = "O";
			if (Dot.locality(0, 2, 3) == 3) {
				label2->Text = "O"; label2->Text += " - win"; win(3); return;
			}
		}

		button3->Enabled = false;
		cheker = !cheker;
		bot(3);
		printGameBox();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (cheker)
		{
			Dot.DoMove(1, 0, 'X');
			button4->Text = "X";
			if (Dot.locality(1, 0, 2) == 2) {
				label2->Text = "X"; label2->Text += " - win"; win(2); return;
			}
		}
		else
		{
			Dot.DoMove(1, 0, 'O');
			button4->Text = "O";
			if (Dot.locality(1, 0, 3) == 3) {
				label2->Text = "O"; label2->Text += " - win"; win(3); return;
			}
		}

		button4->Enabled = false;
		cheker = !cheker;
		bot(3);
		printGameBox();
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (cheker)
		{
			Dot.DoMove(1, 1, 'X');
			button5->Text = "X";
			if (Dot.locality(1, 1, 2) == 2) {
				label2->Text = "X"; label2->Text += " - win"; win(2); return;
			}
		}
		else
		{
			Dot.DoMove(1, 1, 'O');
			button5->Text = "O";
			if (Dot.locality(1, 1, 3) == 3) {
				label2->Text = "O"; label2->Text += " - win"; win(3); return;
			}
		}

		button5->Enabled = false;
		cheker = !cheker;
		bot(3);
		printGameBox();
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (cheker)
		{
			Dot.DoMove(1, 2, 'X');
			button6->Text = "X";
			if (Dot.locality(1, 2, 2) == 2) {
				label2->Text = "X"; label2->Text += " - win"; win(2); return;
			}
		}
		else
		{
			Dot.DoMove(1, 2, 'O');
			button6->Text = "O";
			if (Dot.locality(1, 2, 3) == 3) {
				label2->Text = "O"; label2->Text += " - win"; win(3); return;
			}
		}

		button6->Enabled = false;
		cheker = !cheker;
		bot(3);
		printGameBox();
	}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (cheker)
		{
			Dot.DoMove(2, 0, 'X');
			button7->Text = "X";
			if (Dot.locality(2, 0, 2) == 2) {
				label2->Text = "X"; label2->Text += " - win"; win(2); return;
			}
		}
		else
		{
			Dot.DoMove(2, 0, 'O');
			button7->Text = "O";
			if (Dot.locality(2, 0, 3) == 3) {
				label2->Text = "O"; label2->Text += " - win"; win(3); return;
			}
		}

		button7->Enabled = false;
		cheker = !cheker;
		bot(3);
		printGameBox();
	}
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (cheker)
		{
			Dot.DoMove(2, 1, 'X');
			button8->Text = "X";
			if (Dot.locality(2, 1, 2) == 2) {
				label2->Text = "X"; label2->Text += " - win"; win(2); return;
			}
		}
		else
		{
			Dot.DoMove(2, 1, 'O');
			button8->Text = "O";
			if (Dot.locality(2, 1, 3) == 3) {
				label2->Text = "O"; label2->Text += " - win"; win(3); return;
			}
		}

		button8->Enabled = false;
		cheker = !cheker;
		bot(3);
		printGameBox();
	}
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (cheker)
		{
			Dot.DoMove(2, 2, 'X');
			button9->Text = "X";
			if (Dot.locality(2, 2, 2) == 2) {
				label2->Text = "X"; label2->Text += " - win"; win(2); return;
			}
		}
		else
		{
			Dot.DoMove(2, 2, 'O');
			button9->Text = "O";
			if (Dot.locality(2, 2, 3) == 3) {
				label2->Text = "O"; label2->Text += " - win"; win(3); return;
			}
		}

		button9->Enabled = false;
		cheker = !cheker;
		bot(3);
		printGameBox();
	}
	private: System::Void gameToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{

			Dot.EndOfTheGame(WinnerFlag);

			button1->Enabled = true; button1->Text = "";
			button2->Enabled = true; button2->Text = "";
			button3->Enabled = true; button3->Text = "";
			button4->Enabled = true; button4->Text = "";
			button5->Enabled = true; button5->Text = "";
			button6->Enabled = true; button6->Text = "";
			button7->Enabled = true; button7->Text = "";
			button8->Enabled = true; button8->Text = "";
			button9->Enabled = true; button9->Text = "";

			cheker = true;
			WinnerFlag = 0;
			label1->Text = "111111111";
			label2->Text = "*";
	}

private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e)
{
	// Клавиша START

	int Armageddon = 20000;
	flagtruf++;

	while (Armageddon != 0)
	{
		//-----------------------------
		for (int i = 0; i < 5; i++)
		{
			if (WinnerFlag == 0)
				bot(2);
			if (WinnerFlag == 0)
				bot(3);
		}
		//-----------------------------

		Dot.EndOfTheGame(WinnerFlag);

		button1->Enabled = true; button1->Text = "";
		button2->Enabled = true; button2->Text = "";
		button3->Enabled = true; button3->Text = "";
		button4->Enabled = true; button4->Text = "";
		button5->Enabled = true; button5->Text = "";
		button6->Enabled = true; button6->Text = "";
		button7->Enabled = true; button7->Text = "";
		button8->Enabled = true; button8->Text = "";
		button9->Enabled = true; button9->Text = "";

		cheker = true;
		WinnerFlag = 0;

		Armageddon--;
	}
}
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	Close();
}
};
}
