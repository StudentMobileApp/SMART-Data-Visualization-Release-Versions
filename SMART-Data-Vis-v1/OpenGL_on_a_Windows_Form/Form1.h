///-------------------------------------------------------------------------------------------------
// file:	Form1.h
//
// summary:	Declares the form 1 class
///-------------------------------------------------------------------------------------------------

#pragma once

#include "OpenGL3.h"


///-------------------------------------------------------------------------------------------------
// namespace: OpenGL_on_a_Windows_Form
//
// summary:	.
///-------------------------------------------------------------------------------------------------

namespace OpenGL_on_a_Windows_Form 
{


///-------------------------------------------------------------------------------------------------
// namespace: System
//
// summary:	.
///-------------------------------------------------------------------------------------------------

	using namespace System;

///-------------------------------------------------------------------------------------------------
// namespace: System
//
// summary:	.
///-------------------------------------------------------------------------------------------------

	using namespace System::ComponentModel;

///-------------------------------------------------------------------------------------------------
// namespace: System
//
// summary:	.
///-------------------------------------------------------------------------------------------------

	using namespace System::Collections;

///-------------------------------------------------------------------------------------------------
// namespace: System
//
// summary:	.
///-------------------------------------------------------------------------------------------------

	using namespace System::Windows::Forms;

///-------------------------------------------------------------------------------------------------
// namespace: System
//
// summary:	.
///-------------------------------------------------------------------------------------------------

	using namespace System::Data;

///-------------------------------------------------------------------------------------------------
// namespace: System
//
// summary:	.
///-------------------------------------------------------------------------------------------------

	using namespace System::Drawing;

///-------------------------------------------------------------------------------------------------
// namespace: OpenGLForm
//
// summary:	.
///-------------------------------------------------------------------------------------------------

	using namespace OpenGLForm;

	/// <summary>	Type of the graph. </summary>
	int graphType = -1;
	/// <summary>	True if fileopened. </summary>
	bool fileopened = false;

	/// <summary>	Just to hold the file name for now to send to the graphs. </summary>
	ClassData data;
	FileHandling test;

	/// <summary>	The old zoom value. </summary>
	int oldZoomValue = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 	Summary for Form1
	/// 	
	/// 	WARNING: If you change the name of this class, you will need to change the
	/// 	         'Resource File Name' property for the managed resource compiler tool associated
	/// 	         with all .resx files this class depends on.  Otherwise, the designers will not
	/// 	         be able to interact properly with localized resources associated with this form.
	/// </summary>
	///
	/// <remarks>	Barim, 3/3/2019. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Default constructor. </summary>
		///
		////////////////////////////////////////////////////////////////////////////////////////////////////

		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			OpenGL3 = gcnew COpenGL3(this, this->Width - this->panel1->Width - 40 - 200, //Width
				this->Height - this->menuStrip1->Height - this->statusStrip1->Height - 55, //Height
				graphType);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Destructor. </summary>
		///
		////////////////////////////////////////////////////////////////////////////////////////////////////

		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	/// <summary>	The components. </summary>
	private: System::ComponentModel::IContainer^  components;
	protected:
	/// <summary>	The first timer. </summary>
	/// <summary>	The first timer. </summary>
	private: System::Windows::Forms::Timer^  timer1;
	/// <summary>	The first graph. </summary>
	private: System::Windows::Forms::Button^  graph1;
	/// <summary>	The second graph. </summary>
	private: System::Windows::Forms::Button^  graph2;
	/// <summary>	The third graph. </summary>
	private: System::Windows::Forms::Button^  graph3;
	/// <summary>	The fourth graph. </summary>
	private: System::Windows::Forms::Button^  graph4;
	/// <summary>	The first panel. </summary>
	private: System::Windows::Forms::Panel^  panel1;
	/// <summary>	The first menu strip. </summary>
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	/// <summary>	The file tool strip menu item. </summary>
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	/// <summary>	The open tool strip menu item. </summary>
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	/// <summary>	The view tool strip menu item. </summary>


	/// <summary>	The graph 6. </summary>
	private: System::Windows::Forms::Button^  graph6;
	/// <summary>	The fifth graph. </summary>
	private: System::Windows::Forms::Button^  graph5;
	/// <summary>	The graph 7. </summary>
	private: System::Windows::Forms::Button^  graph7;
	/// <summary>	The first scroll bar. </summary>
	private: System::Windows::Forms::VScrollBar^  vScrollBar1;
	/// <summary>	The first scroll bar. </summary>
	private: System::Windows::Forms::HScrollBar^  hScrollBar1;
	/// <summary>	The first track bar. </summary>
	private: System::Windows::Forms::TrackBar^  trackBar1;
	/// <summary>	The pannning label. </summary>
	private: System::Windows::Forms::Label^  PannningLabel;
	/// <summary>	The zooming label. </summary>
	private: System::Windows::Forms::Label^  ZoomingLabel;
	/// <summary>	The first status strip. </summary>
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	/// <summary>	The graph 8. </summary>
	private: System::Windows::Forms::Button^  graph8;
	/// <summary>	The first group box. </summary>
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  graph9;


	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::Button^  colorButton;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  TS_SPC_CPC_button;









	private:
		/// <summary>	Required designer variable. </summary>

		OpenGLForm::COpenGL3 ^ OpenGL3;

#pragma region Windows Form Designer generated code

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// 	Required method for Designer support - do not modify the contents of this method with the
		/// 	code editor.
		/// </summary>
		///
		////////////////////////////////////////////////////////////////////////////////////////////////////

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->graph1 = (gcnew System::Windows::Forms::Button());
			this->graph2 = (gcnew System::Windows::Forms::Button());
			this->graph3 = (gcnew System::Windows::Forms::Button());
			this->graph4 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->graph9 = (gcnew System::Windows::Forms::Button());
			this->graph8 = (gcnew System::Windows::Forms::Button());
			this->graph5 = (gcnew System::Windows::Forms::Button());
			this->graph7 = (gcnew System::Windows::Forms::Button());
			this->graph6 = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->ZoomingLabel = (gcnew System::Windows::Forms::Label());
			this->vScrollBar1 = (gcnew System::Windows::Forms::VScrollBar());
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->PannningLabel = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->colorButton = (gcnew System::Windows::Forms::Button());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->TS_SPC_CPC_button = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// graph1
			// 
			this->graph1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->graph1->Location = System::Drawing::Point(15, 11);
			this->graph1->Margin = System::Windows::Forms::Padding(6);
			this->graph1->Name = L"graph1";
			this->graph1->Size = System::Drawing::Size(164, 60);
			this->graph1->TabIndex = 0;
			this->graph1->Text = L"Separated CPC";
			this->graph1->UseVisualStyleBackColor = true;
			this->graph1->Click += gcnew System::EventHandler(this, &Form1::graph1_Click);
			// 
			// graph2
			// 
			this->graph2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->graph2->Location = System::Drawing::Point(15, 83);
			this->graph2->Margin = System::Windows::Forms::Padding(6);
			this->graph2->Name = L"graph2";
			this->graph2->Size = System::Drawing::Size(164, 60);
			this->graph2->TabIndex = 1;
			this->graph2->Text = L"Combined CPC";
			this->graph2->UseVisualStyleBackColor = true;
			this->graph2->Click += gcnew System::EventHandler(this, &Form1::graph2_Click);
			// 
			// graph3
			// 
			this->graph3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->graph3->Location = System::Drawing::Point(15, 155);
			this->graph3->Margin = System::Windows::Forms::Padding(6);
			this->graph3->Name = L"graph3";
			this->graph3->Size = System::Drawing::Size(164, 60);
			this->graph3->TabIndex = 2;
			this->graph3->Text = L"Separated SPC";
			this->graph3->UseVisualStyleBackColor = true;
			this->graph3->Click += gcnew System::EventHandler(this, &Form1::graph3_Click);
			// 
			// graph4
			// 
			this->graph4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->graph4->Location = System::Drawing::Point(15, 227);
			this->graph4->Margin = System::Windows::Forms::Padding(6);
			this->graph4->Name = L"graph4";
			this->graph4->Size = System::Drawing::Size(164, 60);
			this->graph4->TabIndex = 3;
			this->graph4->Text = L"Combined SPC";
			this->graph4->UseVisualStyleBackColor = true;
			this->graph4->Click += gcnew System::EventHandler(this, &Form1::graph4_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->panel1->Controls->Add(this->graph9);
			this->panel1->Controls->Add(this->graph8);
			this->panel1->Controls->Add(this->graph5);
			this->panel1->Controls->Add(this->graph7);
			this->panel1->Controls->Add(this->graph6);
			this->panel1->Controls->Add(this->graph2);
			this->panel1->Controls->Add(this->graph1);
			this->panel1->Controls->Add(this->graph4);
			this->panel1->Controls->Add(this->graph3);
			this->panel1->Location = System::Drawing::Point(0, 44);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(200, 676);
			this->panel1->TabIndex = 4;
			// 
			// graph9
			// 
			this->graph9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->graph9->Location = System::Drawing::Point(15, 587);
			this->graph9->Margin = System::Windows::Forms::Padding(6);
			this->graph9->Name = L"graph9";
			this->graph9->Size = System::Drawing::Size(164, 60);
			this->graph9->TabIndex = 9;
			this->graph9->Text = L"Continuous Parallel Coordinates Difference";
			this->graph9->UseVisualStyleBackColor = true;
			this->graph9->Click += gcnew System::EventHandler(this, &Form1::graph9_Click);
			// 
			// graph8
			// 
			this->graph8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->graph8->Location = System::Drawing::Point(15, 515);
			this->graph8->Margin = System::Windows::Forms::Padding(6);
			this->graph8->Name = L"graph8";
			this->graph8->Size = System::Drawing::Size(164, 60);
			this->graph8->TabIndex = 8;
			this->graph8->Text = L"Continuous Parallel Coordinates";
			this->graph8->UseVisualStyleBackColor = true;
			this->graph8->Click += gcnew System::EventHandler(this, &Form1::graph8_Click);
			// 
			// graph5
			// 
			this->graph5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->graph5->Location = System::Drawing::Point(15, 443);
			this->graph5->Margin = System::Windows::Forms::Padding(6);
			this->graph5->Name = L"graph5";
			this->graph5->Size = System::Drawing::Size(164, 60);
			this->graph5->TabIndex = 7;
			this->graph5->Text = L"Separated Time Series SPC";
			this->graph5->UseVisualStyleBackColor = true;
			this->graph5->Click += gcnew System::EventHandler(this, &Form1::graph5_Click);
			// 
			// graph7
			// 
			this->graph7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->graph7->Location = System::Drawing::Point(15, 371);
			this->graph7->Margin = System::Windows::Forms::Padding(6);
			this->graph7->Name = L"graph7";
			this->graph7->Size = System::Drawing::Size(164, 60);
			this->graph7->TabIndex = 9;
			this->graph7->Text = L"Difference Time Series";
			this->graph7->UseVisualStyleBackColor = true;
			this->graph7->Click += gcnew System::EventHandler(this, &Form1::graph7_Click);
			// 
			// graph6
			// 
			this->graph6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->graph6->Location = System::Drawing::Point(15, 299);
			this->graph6->Margin = System::Windows::Forms::Padding(6);
			this->graph6->Name = L"graph6";
			this->graph6->Size = System::Drawing::Size(164, 60);
			this->graph6->TabIndex = 8;
			this->graph6->Text = L"Standard Time Series";
			this->graph6->UseVisualStyleBackColor = true;
			this->graph6->Click += gcnew System::EventHandler(this, &Form1::graph6_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->BackColor = System::Drawing::SystemColors::Control;
			this->trackBar1->LargeChange = 1;
			this->trackBar1->Location = System::Drawing::Point(9, 122);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(185, 45);
			this->trackBar1->TabIndex = 9;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Form1::trackBar1_Scroll);
			// 
			// ZoomingLabel
			// 
			this->ZoomingLabel->AutoSize = true;
			this->ZoomingLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ZoomingLabel->Location = System::Drawing::Point(15, 102);
			this->ZoomingLabel->Name = L"ZoomingLabel";
			this->ZoomingLabel->Size = System::Drawing::Size(43, 16);
			this->ZoomingLabel->TabIndex = 11;
			this->ZoomingLabel->Text = L"Zoom";
			// 
			// vScrollBar1
			// 
			this->vScrollBar1->Location = System::Drawing::Point(79, 26);
			this->vScrollBar1->Minimum = -100;
			this->vScrollBar1->Name = L"vScrollBar1";
			this->vScrollBar1->Size = System::Drawing::Size(42, 50);
			this->vScrollBar1->TabIndex = 7;
			this->vScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Form1::vScrollBar1_Scroll);
			// 
			// hScrollBar1
			// 
			this->hScrollBar1->Location = System::Drawing::Point(17, 45);
			this->hScrollBar1->Minimum = -100;
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->Size = System::Drawing::Size(50, 40);
			this->hScrollBar1->TabIndex = 8;
			this->hScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Form1::hScrollBar1_Scroll);
			// 
			// PannningLabel
			// 
			this->PannningLabel->AutoSize = true;
			this->PannningLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PannningLabel->Location = System::Drawing::Point(15, 27);
			this->PannningLabel->Name = L"PannningLabel";
			this->PannningLabel->Size = System::Drawing::Size(57, 16);
			this->PannningLabel->TabIndex = 10;
			this->PannningLabel->Text = L"Panning";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1530, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->openToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openToolStripMenuItem_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->statusStrip1->Location = System::Drawing::Point(0, 698);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1530, 22);
			this->statusStrip1->TabIndex = 6;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->trackBar1);
			this->groupBox1->Controls->Add(this->PannningLabel);
			this->groupBox1->Controls->Add(this->ZoomingLabel);
			this->groupBox1->Controls->Add(this->vScrollBar1);
			this->groupBox1->Controls->Add(this->hScrollBar1);
			this->groupBox1->Location = System::Drawing::Point(1, 173);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 174);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			// 
			// colorButton
			// 
			this->colorButton->Location = System::Drawing::Point(4, 78);
			this->colorButton->Name = L"colorButton";
			this->colorButton->Size = System::Drawing::Size(192, 71);
			this->colorButton->TabIndex = 0;
			this->colorButton->Text = L"Choose Color";
			this->colorButton->UseVisualStyleBackColor = true;
			this->colorButton->Click += gcnew System::EventHandler(this, &Form1::colorButton_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->comboBox1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->colorButton, 0, 2);
			this->tableLayoutPanel1->Location = System::Drawing::Point(1, 9);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 51.19048F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 48.80952F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 78)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(200, 155);
			this->tableLayoutPanel1->TabIndex = 9;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(4, 1);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(127, 16);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Change Class Color";
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->comboBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(4, 42);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(192, 21);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->BackColor = System::Drawing::SystemColors::Info;
			this->numericUpDown1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->numericUpDown1->Location = System::Drawing::Point(44, 52);
			this->numericUpDown1->MaximumSize = System::Drawing::Size(56, 0);
			this->numericUpDown1->MinimumSize = System::Drawing::Size(56, 0);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(56, 20);
			this->numericUpDown1->TabIndex = 10;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown1_ValueChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(554, 8);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 11;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->numericUpDown1);
			this->groupBox2->Location = System::Drawing::Point(1, 441);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(197, 82);
			this->groupBox2->TabIndex = 12;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"TS-SPC-CPC Column Size";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(196, 43);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(37, 33);
			this->button1->TabIndex = 10;
			this->button1->Text = L"<<";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->TS_SPC_CPC_button);
			this->panel2->Controls->Add(this->groupBox2);
			this->panel2->Controls->Add(this->tableLayoutPanel1);
			this->panel2->Controls->Add(this->groupBox1);
			this->panel2->Location = System::Drawing::Point(1320, 43);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(209, 655);
			this->panel2->TabIndex = 13;
			// 
			// TS_SPC_CPC_button
			// 
			this->TS_SPC_CPC_button->Location = System::Drawing::Point(19, 551);
			this->TS_SPC_CPC_button->Name = L"TS_SPC_CPC_button";
			this->TS_SPC_CPC_button->Size = System::Drawing::Size(166, 74);
			this->TS_SPC_CPC_button->TabIndex = 13;
			this->TS_SPC_CPC_button->Text = L"Change Connecting Line Color";
			this->TS_SPC_CPC_button->UseVisualStyleBackColor = true;
			this->TS_SPC_CPC_button->Click += gcnew System::EventHandler(this, &Form1::TS_SPC_CPC_button_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1277, 42);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(37, 33);
			this->button2->TabIndex = 14;
			this->button2->Text = L">>";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(1530, 720);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(12);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"General Paired Coordinate Graphs and Time Series";
			this->TransparencyKey = System::Drawing::Color::Transparent;
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Converts a str to a standard string. </summary>
		///
		/// <param name="str">	The string. </param>
		///
		/// <returns>	Str as a std::string. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		std::string toStandardString(System::String^ str)
		{
			const char* location = (const char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str).ToPointer();
			std::string temp(location);
			/* Clean up the const char* location memory */
			System::Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)location));
			return temp;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Opens a file. </summary>
		///
		/// <author>	Allyn Vo and Paul Collet </author>
		///
		/// <param name="parameter1">	The first parameter. </param>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		System::Void openFile(System::Void)
		{
			OpenFileDialog^ ofd = gcnew OpenFileDialog;
			ofd->InitialDirectory = ""; // NOTE "c:\\" for future reference.
			ofd->Filter = "Text Files (*.csv, *.txt, *.text)|*.csv; *.txt; *.text";
			ofd->FilterIndex = 1;
			ofd->RestoreDirectory = true;

			if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				/* Convert System::String^ to a std::string */
				System::String^ path = ofd->FileName;

				data.fileName = toStandardString(path);

				/*
				try{
					test.openFile(data);
					test.sortGraph(data);
					if (data.xdata.empty()) {
						throw std::exception();
						return;
					}

				}
				catch(...){
					// display an error message
					MessageBox::Show("WARNING: Cannot correctly read data from file, try reformatting or another file.", "Trouble Reading File", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				*/

				graphType = -1;
				oldZoomValue = 0;
				graph1_oldZoom = 0;
				graph2_oldZoom = 0;
				graph3_oldZoom = 0;
				graph4_oldZoom = 0;
				graph5_oldZoom = 0;
				graph6_oldZoom = 0;
				graph7_oldZoom = 0;
				graph8_oldZoom = 0;
				graph9_oldZoom = 0;

				panel1showing = true;
				panel2showing = true;
				OpenGL3->resetDrawingArea();

				Controls->Clear();
				InitializeComponent();

				graphType = 1;
				OpenGL3->graphType = 1;
				trackBar1->Value = graph1_oldZoom;
				classnumberselected = -1;

				fileopened = true;

				numericUpDown1->Hide();
				TS_SPC_CPC_button->Hide();
				groupBox2->Hide();

				
			}
		}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Timer 1 tick. </summary>
	///
	/// <author>	Allyn Vo </author>
	///
	/// <param name="sender">	The sender. </param>
	/// <param name="e">	 	The System::EventArgs to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		UNREFERENCED_PARAMETER(sender);
		UNREFERENCED_PARAMETER(e);

		if (graphType == 1) { 				//Separated CPC graph1
			OpenGL3->Render();
		}
		else if (graphType == 2)			//Combined CPC graph2
		{
			OpenGL3->Render2();
		}
		else if (graphType == 3)			//Separated SPC graph3
		{
			OpenGL3->Render3();
		}
		else if (graphType == 4)			//Combined SPC graph4
		{
			OpenGL3->Render4();
		}
		else if (graphType == 5)			// Separated Time Series SPC graph 5
		{
			OpenGL3->Render5();
			
		}
		else if (graphType == 6)			// Time Series graph 6
		{
			OpenGL3->Render6();
		}
		else if (graphType == 7)			// Distance Time Series graph 7
		{
			OpenGL3->Render7();
		}
		else if (graphType == 8)			// Continuous Parallel Coordinate graph 8
		{
			OpenGL3->Render8();
		}
		else if (graphType == 9)			// Distance Continuous Parallel Coordinate graph 8
		{
			OpenGL3->Render9();
		}


		OpenGL3->SwapOpenGLBuffers();
	}

			 // BUTTONS TO CHOOSE DISPLAY OF GRAPH TYPE

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Graph 1 click. </summary>
	///
	/// <author>	Allyn Vo </author>
	///
	/// <param name="sender">	The sender. </param>
	/// <param name="e">	 	The System::EventArgs to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void graph1_Click(System::Object^  sender, System::EventArgs^  e) {	//Separated CPC graph1
		if (fileopened) {
			graphType = 1;
			OpenGL3->graphType = 1;
			trackBar1->Value = graph1_oldZoom;

			numericUpDown1->Hide();
			TS_SPC_CPC_button->Hide();
			groupBox2->Hide();
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Graph 2 click. </summary>
	///
	/// <author>	Allyn Vo </author>
	///
	/// <param name="sender">	The sender. </param>
	/// <param name="e">	 	The System::EventArgs to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void graph2_Click(System::Object^  sender, System::EventArgs^  e) {	//Combined CPC graph2
		if (fileopened) {
			graphType = 2;
			OpenGL3->graphType = 2;
			trackBar1->Value = graph2_oldZoom;

			numericUpDown1->Hide();
			TS_SPC_CPC_button->Hide();
			groupBox2->Hide();
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Graph 3 click. </summary>
	///
	/// <author>	Allyn Vo </author>
	///
	/// <param name="sender">	The sender. </param>
	/// <param name="e">	 	The System::EventArgs to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void graph3_Click(System::Object^  sender, System::EventArgs^  e) {	//Separated SPC graph3
		if (fileopened) {
			graphType = 3;
			OpenGL3->graphType = 3;
			trackBar1->Value = graph3_oldZoom;

			numericUpDown1->Hide();
			TS_SPC_CPC_button->Hide();
			groupBox2->Hide();
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Graph 4 click. </summary>
	///
	/// <author>	Allyn Vo </author>
	///
	/// <param name="sender">	The sender. </param>
	/// <param name="e">	 	The System::EventArgs to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void graph4_Click(System::Object^  sender, System::EventArgs^  e) {	//Combined SPC graph4
		if (fileopened) {
			graphType = 4;
			OpenGL3->graphType = 4;
			trackBar1->Value = graph4_oldZoom;

			numericUpDown1->Hide();
			TS_SPC_CPC_button->Hide();
			groupBox2->Hide();
		}
	}
	protected:
		/// <summary>	The graph 1 old zoom. </summary>
		/// <summary>	The graph 1 old zoom. </summary>
		int graph1_oldZoom;
		/// <summary>	The graph 2 old zoom. </summary>
		int graph2_oldZoom;
		/// <summary>	The graph 3 old zoom. </summary>
		int graph3_oldZoom;
		/// <summary>	The graph 4 old zoom. </summary>
		int graph4_oldZoom;
		/// <summary>	The graph 5 old zoom. </summary>
		int graph5_oldZoom;
		/// <summary>	The graph 6 old zoom. </summary>
		int graph6_oldZoom;
		/// <summary>	The graph 7 old zoom. </summary>
		int graph7_oldZoom;
		/// <summary>	The graph 8 old zoom. </summary>
		int graph8_oldZoom;
		/// <summary>	The graph 9 old zoom. </summary>
		int graph9_oldZoom;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Opens tool strip menu item click. </summary>
	///
	/// <author>	Allyn Vo </author>
	/// 
	/// <param name="sender">	The sender. </param>
	/// <param name="e">	 	The System::EventArgs to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		UNREFERENCED_PARAMETER(sender);
		UNREFERENCED_PARAMETER(e);

		openFile(); // starts select file window
		if (fileopened) {
			OpenGL3->setFileName(data);


			// clear the list to prevent duplicates on update
			this->comboBox1->Items->Clear();
			this->comboBox1->Items->Clear();
			data.numOfClasses = OpenGL3->getClassSize();
			for (int i = 1; i <= data.numOfClasses; i++) {
					this->comboBox1->Items->Add(i); // set the combobox for "Class combobox" to the data in item1 

			}
		}


	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Graph 5 click. </summary>
	///
	/// <author>	Allyn Vo </author>
	///
	/// <param name="sender">	The sender. </param>
	/// <param name="e">	 	The System::EventArgs to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void graph5_Click(System::Object^  sender, System::EventArgs^  e) { // Separated Time Series SPC graph 5
		if (fileopened) {
			graphType = 5;
			OpenGL3->graphType = 5;
			trackBar1->Value = graph5_oldZoom;
			numericUpDown1->Show();
			TS_SPC_CPC_button->Show();
			groupBox2->Show();
		}


	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Graph 6 click. </summary>
	///
	/// <author>	Allyn Vo </author>
	///
	/// <param name="sender">	The sender. </param>
	/// <param name="e">	 	The System::EventArgs to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void graph6_Click(System::Object^  sender, System::EventArgs^  e) { // Time Series graph 6
		if (fileopened) {
			graphType = 6;
			OpenGL3->graphType = 6;
			trackBar1->Value = graph6_oldZoom;

			numericUpDown1->Hide();
			TS_SPC_CPC_button->Hide();
			groupBox2->Hide();
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Graph 7 click. </summary>
	///
	/// <author>	Allyn Vo </author>
	///
	/// <param name="sender">	The sender. </param>
	/// <param name="e">	 	The System::EventArgs to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void graph7_Click(System::Object^  sender, System::EventArgs^  e) { // Distance Time Series graph 7
		if (fileopened) {
			graphType = 7;
			OpenGL3->graphType = 7;
			trackBar1->Value = graph7_oldZoom;

			numericUpDown1->Hide();
			TS_SPC_CPC_button->Hide();
			groupBox2->Hide();
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Graph 8 click. </summary>
	///
	/// <author>	Allyn Vo </author>
	///
	/// <param name="sender">	The sender. </param>
	/// <param name="e">	 	The System::EventArgs to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void graph8_Click(System::Object^  sender, System::EventArgs^  e) { // Continuous Parallel Coordinates
		if (fileopened) {
			graphType = 8;
			OpenGL3->graphType = 8;
			trackBar1->Value = graph8_oldZoom;

			numericUpDown1->Hide();
			TS_SPC_CPC_button->Hide();
			groupBox2->Hide();
		}
	}

	 ////////////////////////////////////////////////////////////////////////////////////////////////////
	 /// <summary>	Graph 9 click. </summary>
	 ///
	 /// <author>	Allyn Vo </author>
	 ///
	 /// <param name="sender">	The sender. </param>
	 /// <param name="e">	 	The System::EventArgs to process. </param>
	 ////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void graph9_Click(System::Object^  sender, System::EventArgs^  e) {
		if (fileopened) {
			graphType = 9;
			OpenGL3->graphType = 9;
			trackBar1->Value = graph9_oldZoom;

			numericUpDown1->Hide();
			TS_SPC_CPC_button->Hide();
			groupBox2->Hide();
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Scroll bar 1 scroll. </summary>
	///
	/// <author>	Allyn Vo </author>
	///
	/// <param name="sender">	The sender. </param>
	/// <param name="e">	 	The System::Windows::Forms::ScrollEventArgs to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void hScrollBar1_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		if (e->NewValue > e->OldValue)
		{
			//moved right
			OpenGL3->panHorizontal(true); // true for going right



		}
		else if (e->NewValue < e->OldValue)
		{
			//moved left
			OpenGL3->panHorizontal(false); // true for going right else false for going left

		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Scroll bar 1 scroll. </summary>
	///
	/// <author>	Allyn Vo </author>
	///
	/// <param name="sender">	The sender. </param>
	/// <param name="e">	 	The System::Windows::Forms::ScrollEventArgs to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void vScrollBar1_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		if (e->NewValue > e->OldValue)
		{
			//moved up
			OpenGL3->panVertical(true); // true for going up else flase for down
		}
		else if (e->NewValue < e->OldValue)
		{
			//moved down
			OpenGL3->panVertical(false); // true for going up else flase for down
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Track bar 1 scroll. </summary>
	///
	/// <author>	Allyn Vo </author>
	///
	/// <param name="sender">	The sender. </param>
	/// <param name="e">	 	The System::EventArgs to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
		//int value = trackBar1->Value;
		//MessageBox::Show("" + value);

		if (graphType == 1) {
			OpenGL3->zoom(trackBar1->Value - graph1_oldZoom);
			graph1_oldZoom = trackBar1->Value;
		}
		else if (graphType == 2) {
			OpenGL3->zoom(trackBar1->Value - graph2_oldZoom);
			graph2_oldZoom = trackBar1->Value;
		}
		else if (graphType == 3) {
			OpenGL3->zoom(trackBar1->Value - graph3_oldZoom);
			graph3_oldZoom = trackBar1->Value;
		}
		else if (graphType == 4) {
			OpenGL3->zoom(trackBar1->Value - graph4_oldZoom);
			graph4_oldZoom = trackBar1->Value;
		}
		else if (graphType == 5) {
			OpenGL3->zoom(trackBar1->Value - graph5_oldZoom);
			graph5_oldZoom = trackBar1->Value;
		}
		else if (graphType == 6) {
			OpenGL3->zoom(trackBar1->Value - graph6_oldZoom);
			graph6_oldZoom = trackBar1->Value;
		}
		else if (graphType == 7) {
			OpenGL3->zoom(trackBar1->Value - graph7_oldZoom);
			graph7_oldZoom = trackBar1->Value;
		}
		else if (graphType == 8) {
			OpenGL3->zoom(trackBar1->Value - graph8_oldZoom);
			graph8_oldZoom = trackBar1->Value;
		}
		else if (graphType == 9) {
			OpenGL3->zoom(trackBar1->Value - graph9_oldZoom);
			graph9_oldZoom = trackBar1->Value;
		}
	}



	int classnumberselected = -1;
private: System::Void colorButton_Click(System::Object^  sender, System::EventArgs^  e) {
	// FOR CHANGING COLOR
	if (colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		//this->colorPanel->BackColor = this->colorDialog1->Color;
		float red = this->colorDialog1->Color.R;
		float green = this->colorDialog1->Color.G;
		float blue = this->colorDialog1->Color.B;

		OpenGL3->setClassColor(red, green, blue, classnumberselected);
	}

	
}

private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	classnumberselected = comboBox1->SelectedIndex + 1;

}
private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	
	if (graphType == 5) {
		OpenGL3->setGraph5ColumnSize((int)numericUpDown1->Value);
	}
}
		 bool panel1showing = true;
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (panel1showing) {
		panel1->Hide();
		button1->Text = ">>";
		button1->Left = 5;
		OpenGL3->resizeDrawingArea1(-panel1->Width);
		panel1showing = false;
	}
	else if (!panel1showing) {
		panel1->Show();
		button1->Text = "<<";
		button1->Left = panel1->Right - 5;
		OpenGL3->resizeDrawingArea1(panel1->Width);
		panel1showing = true;
	}

}
		 bool panel2showing = true;
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	if (panel2showing) {
		panel2->Hide();
		button2->Text = "<<";
		button2->Left += panel2->Width;
		OpenGL3->resizeDrawingArea2(-panel2->Width);
		panel2showing = false;
	}
	else if (!panel2showing) {
		panel2->Show();
		button2->Text = ">>";
		button2->Left -= panel2->Width;
		OpenGL3->resizeDrawingArea2(panel2->Width);
		panel2showing = true;
	}
}

private: System::Void TS_SPC_CPC_button_Click(System::Object^  sender, System::EventArgs^  e) {

	// FOR CHANGING COLOR
	if (colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		//this->colorPanel->BackColor = this->colorDialog1->Color;
		float red = this->colorDialog1->Color.R;
		float green = this->colorDialog1->Color.G;
		float blue = this->colorDialog1->Color.B;

		OpenGL3->setGraph5ConnectedLineColor(red, green, blue);
	}

}

};
}

