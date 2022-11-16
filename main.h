#pragma once
#include <string>
#include <vector>

#include "SQLConnector.h"
#include "dataRow.h"

static DataRowCustom* MyRecord; //user data

static std::string toStandardString(System::String^ string);



namespace Safekeep {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	


	/// <summary>
	/// Summary for main
	/// </summary>
	public ref class main : public System::Windows::Forms::Form
	{
	public:
		main(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: bool isDragging = false; //These 2 lines of code are for the custom toolbar.
	private: Point offset;

	private: String^ user; //These 3 lines of code are for login.
	private: int tries = 3;

	private: System::Windows::Forms::Panel^ pnlToolbar;
	private: System::Windows::Forms::Button^ btnExit;

	protected:

	private: System::Windows::Forms::Label^ lblName;
	private: System::Windows::Forms::TextBox^ txtInput;

	private: System::Windows::Forms::Label^ lblCaption;
	private: System::Windows::Forms::PictureBox^ pbIcon;

	private: System::Windows::Forms::DataGridView^ dgvMain;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ COLdomain;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ COLusern;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(main::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle11 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle12 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle13 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle14 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle15 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->pnlToolbar = (gcnew System::Windows::Forms::Panel());
			this->pbIcon = (gcnew System::Windows::Forms::PictureBox());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->txtInput = (gcnew System::Windows::Forms::TextBox());
			this->lblCaption = (gcnew System::Windows::Forms::Label());
			this->dgvMain = (gcnew System::Windows::Forms::DataGridView());
			this->COLdomain = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->COLusern = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pnlToolbar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbIcon))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvMain))->BeginInit();
			this->SuspendLayout();
			// 
			// pnlToolbar
			// 
			this->pnlToolbar->BackColor = System::Drawing::Color::Goldenrod;
			this->pnlToolbar->Controls->Add(this->pbIcon);
			this->pnlToolbar->Controls->Add(this->btnExit);
			this->pnlToolbar->Controls->Add(this->lblName);
			this->pnlToolbar->Location = System::Drawing::Point(-1, -2);
			this->pnlToolbar->Name = L"pnlToolbar";
			this->pnlToolbar->Size = System::Drawing::Size(299, 34);
			this->pnlToolbar->TabIndex = 0;
			this->pnlToolbar->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &main::pnlToolbar_MouseDown);
			this->pnlToolbar->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &main::pnlToolbar_MouseMove);
			this->pnlToolbar->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &main::pnlToolbar_MouseUp);
			// 
			// pbIcon
			// 
			this->pbIcon->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbIcon.BackgroundImage")));
			this->pbIcon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pbIcon->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbIcon.Image")));
			this->pbIcon->Location = System::Drawing::Point(0, 0);
			this->pbIcon->Name = L"pbIcon";
			this->pbIcon->Size = System::Drawing::Size(35, 34);
			this->pbIcon->TabIndex = 2;
			this->pbIcon->TabStop = false;
			this->pbIcon->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &main::pnlToolbar_MouseDown);
			this->pbIcon->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &main::pnlToolbar_MouseMove);
			this->pbIcon->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &main::pnlToolbar_MouseUp);
			// 
			// btnExit
			// 
			this->btnExit->FlatAppearance->BorderColor = System::Drawing::Color::Goldenrod;
			this->btnExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnExit->ForeColor = System::Drawing::Color::Black;
			this->btnExit->Location = System::Drawing::Point(268, 4);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(28, 27);
			this->btnExit->TabIndex = 1;
			this->btnExit->Text = L"X";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &main::btnExit_Click);
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblName->Location = System::Drawing::Point(39, 5);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(130, 27);
			this->lblName->TabIndex = 0;
			this->lblName->Text = L"SAFEKEEP";
			this->lblName->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &main::pnlToolbar_MouseDown);
			this->lblName->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &main::pnlToolbar_MouseMove);
			this->lblName->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &main::pnlToolbar_MouseUp);
			// 
			// txtInput
			// 
			this->txtInput->BackColor = System::Drawing::Color::Black;
			this->txtInput->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtInput->ForeColor = System::Drawing::Color::Goldenrod;
			this->txtInput->Location = System::Drawing::Point(43, 81);
			this->txtInput->Name = L"txtInput";
			this->txtInput->Size = System::Drawing::Size(215, 35);
			this->txtInput->TabIndex = 1;
			this->txtInput->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->txtInput->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &main::txtInput_KeyDown);
			// 
			// lblCaption
			// 
			this->lblCaption->AutoSize = true;
			this->lblCaption->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCaption->ForeColor = System::Drawing::Color::Goldenrod;
			this->lblCaption->Location = System::Drawing::Point(83, 43);
			this->lblCaption->Name = L"lblCaption";
			this->lblCaption->Size = System::Drawing::Size(147, 27);
			this->lblCaption->TabIndex = 2;
			this->lblCaption->Text = L"USERNAME:";
			this->lblCaption->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// dgvMain
			// 
			this->dgvMain->AllowUserToAddRows = false;
			this->dgvMain->AllowUserToDeleteRows = false;
			dataGridViewCellStyle11->BackColor = System::Drawing::Color::Black;
			dataGridViewCellStyle11->ForeColor = System::Drawing::Color::Goldenrod;
			dataGridViewCellStyle11->SelectionBackColor = System::Drawing::Color::Goldenrod;
			dataGridViewCellStyle11->SelectionForeColor = System::Drawing::Color::Black;
			this->dgvMain->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle11;
			this->dgvMain->BackgroundColor = System::Drawing::Color::Black;
			this->dgvMain->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->dgvMain->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle12->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle12->BackColor = System::Drawing::Color::Black;
			dataGridViewCellStyle12->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle12->ForeColor = System::Drawing::Color::Goldenrod;
			dataGridViewCellStyle12->SelectionBackColor = System::Drawing::Color::Goldenrod;
			dataGridViewCellStyle12->SelectionForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle12->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvMain->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle12;
			this->dgvMain->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvMain->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->COLdomain, this->COLusern });
			dataGridViewCellStyle13->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle13->BackColor = System::Drawing::Color::Black;
			dataGridViewCellStyle13->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle13->ForeColor = System::Drawing::Color::Goldenrod;
			dataGridViewCellStyle13->SelectionBackColor = System::Drawing::Color::Goldenrod;
			dataGridViewCellStyle13->SelectionForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle13->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgvMain->DefaultCellStyle = dataGridViewCellStyle13;
			this->dgvMain->EnableHeadersVisualStyles = false;
			this->dgvMain->GridColor = System::Drawing::Color::Goldenrod;
			this->dgvMain->Location = System::Drawing::Point(14, 151);
			this->dgvMain->Name = L"dgvMain";
			this->dgvMain->ReadOnly = true;
			dataGridViewCellStyle14->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle14->BackColor = System::Drawing::Color::Black;
			dataGridViewCellStyle14->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle14->ForeColor = System::Drawing::Color::Goldenrod;
			dataGridViewCellStyle14->SelectionBackColor = System::Drawing::Color::Goldenrod;
			dataGridViewCellStyle14->SelectionForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle14->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvMain->RowHeadersDefaultCellStyle = dataGridViewCellStyle14;
			dataGridViewCellStyle15->BackColor = System::Drawing::Color::Black;
			dataGridViewCellStyle15->ForeColor = System::Drawing::Color::Goldenrod;
			dataGridViewCellStyle15->SelectionBackColor = System::Drawing::Color::Goldenrod;
			dataGridViewCellStyle15->SelectionForeColor = System::Drawing::Color::Black;
			this->dgvMain->RowsDefaultCellStyle = dataGridViewCellStyle15;
			this->dgvMain->Size = System::Drawing::Size(273, 265);
			this->dgvMain->TabIndex = 4;
			this->dgvMain->Visible = false;
			// 
			// COLdomain
			// 
			this->COLdomain->HeaderText = L"DOMAIN";
			this->COLdomain->Name = L"COLdomain";
			this->COLdomain->ReadOnly = true;
			this->COLdomain->ToolTipText = L"DOMAIN";
			// 
			// COLusern
			// 
			this->COLusern->HeaderText = L"USERNAME";
			this->COLusern->MinimumWidth = 15;
			this->COLusern->Name = L"COLusern";
			this->COLusern->ReadOnly = true;
			this->COLusern->ToolTipText = L"USERNAME";
			this->COLusern->Width = 127;
			// 
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(300, 136);
			this->Controls->Add(this->dgvMain);
			this->Controls->Add(this->lblCaption);
			this->Controls->Add(this->txtInput);
			this->Controls->Add(this->pnlToolbar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SAFEKEEP";
			this->Load += gcnew System::EventHandler(this, &main::main_Load);
			this->pnlToolbar->ResumeLayout(false);
			this->pnlToolbar->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbIcon))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvMain))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pnlToolbar_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		isDragging = true;
		offset = e->Location;
	}
	private: System::Void pnlToolbar_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (isDragging) {
			Point current = PointToScreen(Point(e->X, e->Y));
			Location = Point(current.X - offset.X, current.Y - offset.Y);
		}
	}
	private: System::Void pnlToolbar_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		isDragging = false;
	}
	private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
		return System::Void();
	}
	private: System::Void txtInput_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
	private: System::Void main_Load(System::Object^ sender, System::EventArgs^ e);

	private: bool authenticate(std::string user, std::string pass);
};
}
