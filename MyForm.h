#pragma once
#include "Plex.h"

TChart* Plex;
TPoint* CurrPoint;
Point* p = new Point;
Point* Tmp = new Point;
TChart* LineNew;
TPoint* PointsForm;

namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			BackColor = Color::White;
			gr = CreateGraphics();
			Plex = new TChart;
			Plex->SetVisible(false);
			CurrPoint = new TPoint;
			CurrPoint->SetX(0);
			CurrPoint->SetY(0);
		}
	public:
		Graphics^ gr;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(21, 15);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(250, 70);
			this->button1->TabIndex = 0;
			this->button1->TabStop = false;
			this->button1->Text = L"Нарисовать треугольник";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(287, 18);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(231, 66);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Скрыть";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(540, 20);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(222, 64);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Переместить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(790, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"По Х:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(939, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 25);
			this->label2->TabIndex = 4;
			this->label2->Text = L"По Y:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(795, 59);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(99, 26);
			this->textBox1->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(944, 58);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(98, 26);
			this->textBox2->TabIndex = 6;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1120, 687);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		TChart* BC = new TChart;
		TChart* CA = new TChart;
		TPoint* B = new TPoint(400, 200);
		TPoint* C = new TPoint(300, 400);
		TPoint* A = new TPoint(200, 200);

		CurrPoint->SetX(-1);
		CurrPoint->SetY(-1);

		BC->SetFirst(B);
		BC->SetLast(C);
		CA->SetFirst(BC);
		CA->SetLast(A);

		Plex->SetFirst(CA);
		Plex->SetLast(B);
		Plex->Show(gr, Pens::Black);
		Plex->SetVisible(true);
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (Plex->GetVisible())
	{
		Plex->Hide(gr, Pens::White);
		Plex->SetVisible(false);
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	int x = Convert::ToInt32(textBox1->Text);
	int y = Convert::ToInt32(textBox2->Text);

	Plex->Hide(gr, Pens::White);
	Plex->MoveTo(x, y);
	Plex->Show(gr, Pens::Black);
	Plex->Reset();
}
	   private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	   }
private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (Plex->GetVisible())
	{
		*p = PointToClient(Control::MousePosition);
		CurrPoint = Plex->SetCurrPoint(gr, Pens::Black, p->X, p->Y);
	}
}
private: System::Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (Plex->GetVisible() && CurrPoint->GetX() > 0 && CurrPoint->GetY() > 0 && e->X != CurrPoint->GetX() && e->Y != CurrPoint->GetY())
	{
		*Tmp = PointToClient(Control::MousePosition);

		PointsForm = new TPoint(Tmp->X, Tmp->Y);
		LineNew = new TChart;

		LineNew->SetFirst(PointsForm);
		LineNew->SetLast(CurrPoint);

		Plex->AddLine(gr, Pens::Black, CurrPoint, LineNew);
		Plex->Show(gr, Pens::Black);
	}
}
};
}
