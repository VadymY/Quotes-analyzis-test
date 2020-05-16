#pragma once
#include <random>
#include "DataTicker.h"


namespace Gogen {

	using namespace System;
	using namespace System::Globalization;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace ZedGraph;
	using namespace System::IO::MemoryMappedFiles;

	delegate int opDelegate(MemoryMappedViewStream ^);

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			dat_tick = new DataTicker;
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	public:
		DataTicker * dat_tick;
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
	private: System::Windows::Forms::Panel^  panel1;
	private: ZedGraph::ZedGraphControl^  zedGraphControl1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  outputToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->zedGraphControl1 = (gcnew ZedGraph::ZedGraphControl());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->outputToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->Controls->Add(this->zedGraphControl1);
			this->panel1->Location = System::Drawing::Point(200, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(280, 396);
			this->panel1->TabIndex = 0;
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zedGraphControl1->Location = System::Drawing::Point(0, 0);
			this->zedGraphControl1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->zedGraphControl1->Name = L"zedGraphControl1";
			this->zedGraphControl1->ScrollGrace = 0;
			this->zedGraphControl1->ScrollMaxX = 0;
			this->zedGraphControl1->ScrollMaxY = 0;
			this->zedGraphControl1->ScrollMaxY2 = 0;
			this->zedGraphControl1->ScrollMinX = 0;
			this->zedGraphControl1->ScrollMinY = 0;
			this->zedGraphControl1->ScrollMinY2 = 0;
			this->zedGraphControl1->Size = System::Drawing::Size(280, 396);
			this->zedGraphControl1->TabIndex = 0;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(482, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openToolStripMenuItem,
					this->outputToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(44, 24);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(130, 26);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// outputToolStripMenuItem
			// 
			this->outputToolStripMenuItem->Name = L"outputToolStripMenuItem";
			this->outputToolStripMenuItem->Size = System::Drawing::Size(130, 26);
			this->outputToolStripMenuItem->Text = L"Output";
			this->outputToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::outputToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(24, 46);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(124, 34);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Need out folder";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) { L"5", L"10", L"15", L"20", L"30", L"40", L"50" });
			this->comboBox1->Location = System::Drawing::Point(27, 96);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->Text = L"100";
			this->comboBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(27, 161);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"100";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(27, 206);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 5;
			this->textBox2->Text = L"50";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(27, 141);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 17);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Profit";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(27, 186);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 17);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Loss";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(24, 255);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Math";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(27, 319);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(75, 17);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Dispersion";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(24, 272);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(18, 20);
			this->label5->TabIndex = 10;
			this->label5->Text = L"0";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(27, 336);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(18, 20);
			this->label6->TabIndex = 11;
			this->label6->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(482, 405);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"GoGen";
			this->panel1->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 opDelegate ^ opd = gcnew opDelegate(this, &Gogen::MyForm::Read_file);
					 dat_tick->size_quotes = MMF_read(openFileDialog1->FileName, opd);
					 button1->Visible = true;
					 if (dat_tick->out_path == "")
					 {
						 outputToolStripMenuItem_Click(sender, e);
						 dat_tick->out_full_fname = dat_tick->out_path + "\\" + dat_tick->out_fname;
					 }
					 comboBox1_TextChanged(sender, e);
					 textBox1_TextChanged(sender, e);
					 textBox2_TextChanged(sender, e);
					 button1->Text = "Start";
					 button1->BackColor = Color::LightGreen;
				 }
	}

	private: int MMF_read(String ^ fname, opDelegate ^ oper){
				 FileStream ^ file = gcnew  FileStream(fname, FileMode::Open);
				 long long length = file->Length;
				 file->Close();
				 int ret;
				 MemoryMappedFile ^mappedFile = nullptr;
				 try{
					 mappedFile = MemoryMappedFile::CreateFromFile(fname, System::IO::FileMode::OpenOrCreate, "fileHandle", length, MemoryMappedFileAccess::ReadWrite);
					 MemoryMappedViewStream ^ mmview = nullptr;
					 try{
						 mmview = mappedFile->CreateViewStream(0, length, MemoryMappedFileAccess::Read);
						 ret = oper(mmview);
						 mmview->Close();
					 }
					 finally{
						 if (mmview != nullptr)
						 {
							 delete mmview;
						 }
					 }
				 }
				 finally{
					 if (mappedFile != nullptr)
						 delete mappedFile;
				 }
				 return ret;
	}

	private: int Read_file(MemoryMappedViewStream ^ mmvs){
				 const int size_reserve = 10000;
				 dat_tick->dat.clear();
				 dat_tick->dat_vec.clear();
				 System::IO::StreamReader ^ sr = gcnew System::IO::StreamReader(mmvs);
				 String ^ str = sr->ReadLine();
				 array<String^> ^ StringArray = nullptr;
				 int count = 0;
				 int reserve = size_reserve;
				 dat_tick->dat_vec.reserve(size_reserve);
				 dat_tick->max_gap = 0.0;
				 double current, previous, dif;
				 while (!sr->EndOfStream)
				 {
					 str = sr->ReadLine();
					 StringArray = str->Split(',');
					 if (StringArray->Length > 1)
					 {
						 if (count == 0)
						 {
							 dat_tick->name = Sysstr_to_string(StringArray[0]);
						 }
						 double  dt = Convert_from_DT(StringArray[2], StringArray[3]);
						 double value = Double::Parse(StringArray[4], NumberStyles::Float, CultureInfo::CreateSpecificCulture("en-EN"));
						 Int32 volume = Int32::Parse(StringArray[5], NumberStyles::Integer, CultureInfo::CreateSpecificCulture("en-EN"));
						 dat_tick->dat_vec.emplace_back(std::make_pair(dt, trade_data(value, volume)));
						 if (++count >= reserve)
						 {
							 reserve += size_reserve;
							 dat_tick->dat_vec.reserve(reserve);
						 }
					 }
				 }
				 sr->Close();
				 textBox1->Visible = true;
				 textBox2->Visible = true;
				 label1->Visible = true;
				 label2->Visible = true;
				 return dat_tick->dat_vec.size();
	}

	private: double Convert_from_DT(String ^ st1, String ^ st2){
				 double ret;
				 Int32 ms = Int32::Parse(st2, NumberStyles::Integer, CultureInfo::CreateSpecificCulture("en-EN"));
				 String ^ year = st1->Substring(0, 4);
				 String ^ month = st1->Substring(4, 2);
				 String ^ day = st1->Substring(6, 2);
				 Int32 y_int = Int32::Parse(year, NumberStyles::Integer, CultureInfo::CreateSpecificCulture("en-EN"));
				 Int32 m_int = Int32::Parse(month, NumberStyles::Integer, CultureInfo::CreateSpecificCulture("en-EN"));
				 Int32 d_int = Int32::Parse(day, NumberStyles::Integer, CultureInfo::CreateSpecificCulture("en-EN"));
				 String ^ s_str = st2->Substring(st2->Length - 2, 2);
				 Int32 s_int = Int32::Parse(s_str, NumberStyles::Integer, CultureInfo::CreateSpecificCulture("en-EN"));
				 String ^ mn_str = st2->Substring(st2->Length - 4, 2);
				 Int32 mn_int = Int32::Parse(mn_str, NumberStyles::Integer, CultureInfo::CreateSpecificCulture("en-EN"));
				 String ^ h_str = st2->Substring(0, 2);
				 Int32 h_int = Int32::Parse(h_str, NumberStyles::Integer, CultureInfo::CreateSpecificCulture("en-EN"));
				 System::DateTime dt(y_int, m_int, d_int, h_int, mn_int, s_int);
				 ret = (XDate)dt;
				 return ret;
	}

	private: String ^ toSysString(std::string str){
				 String ^ ret = gcnew String("");
				 for (auto & item : str)
				 {
					 ret += (wchar_t)item;
				 }
				 return ret;
	}

	private:	std::string Sysstr_to_string(System::String ^ st){
					IntPtr ip = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(st);
					char *Ex = static_cast<char*>(ip.ToPointer());
					std::string res = Ex;
					return res;
	}
	private: System::Void outputToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 dat_tick->out_path = Sysstr_to_string(folderBrowserDialog1->SelectedPath);
				 }
	}
private: System::Void comboBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 button1->Text = "Start";
			 if (comboBox1->Text->Length > 0)
			 {
				 dat_tick->iter_number = Int32::Parse(comboBox1->Text, NumberStyles::Integer, CultureInfo::CreateSpecificCulture("en-EN"));
			 }
}


private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 button1->Text = "Start";
			 if (textBox2->Text->Length > 0)
			 {
				 dat_tick->loss = Int32::Parse(textBox2->Text, NumberStyles::Integer, CultureInfo::CreateSpecificCulture("en-EN"));
			 }
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (textBox1->Text->Length > 0)
			 {
				 dat_tick->profit = Int32::Parse(textBox1->Text, NumberStyles::Integer, CultureInfo::CreateSpecificCulture("en-EN"));
			 }
			 button1->Text = "Start";
}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 std::random_device rd;
				 std::mt19937 mersenne(rd());
				 dat_tick->profit_set.clear();
				 dat_tick->profit_set.reserve(dat_tick->iter_number);
				 dat_tick->loss_set.clear();
				 dat_tick->loss_set.reserve(dat_tick->iter_number);
				 dat_tick->all_set.clear();
				 dat_tick->all_set.reserve(dat_tick->iter_number);
				 bool direction;
				 for (int i = 0; i < dat_tick->iter_number; ++i)
				 {
					 int number = mersenne() % dat_tick->size_quotes;
					 direction = (bool)(mersenne() % 2);
					 int start = 0;
					 for (int i2 = number + 1; i2 >= 0; --i2)
					 {
						 if (dat_tick->dat_vec[i2].first < dat_tick->dat_vec[number].first)
						 {
							 start = i2 + 1;
							 break;
						 }
					 }
					 double start_value = dat_tick->dat_vec[start].second.value;
					 for (int i3 = start; i3 < dat_tick->size_quotes; ++i3)
					 {
						 if (direction)
						 {
							 if (dat_tick->dat_vec[i3].second.value >= start_value + dat_tick->profit)
							 {
								 auto data = std::make_tuple(dat_tick->dat_vec[i3].second.value - start_value, dat_tick->dat_vec[start].first,
									 dat_tick->dat_vec[start].second.value, dat_tick->dat_vec[i3].first, dat_tick->dat_vec[i3].second.value, direction, start, i3);
								 dat_tick->profit_set.emplace_back(data);
								 dat_tick->all_set.emplace_back(data);
								 break;
							 }
							 else if (dat_tick->dat_vec[i3].second.value <= start_value - dat_tick->loss)
							 {
								 auto data = std::make_tuple(dat_tick->dat_vec[i3].second.value - start_value, dat_tick->dat_vec[start].first,
									 dat_tick->dat_vec[start].second.value, dat_tick->dat_vec[i3].first, dat_tick->dat_vec[i3].second.value, direction, start, i3);
								 dat_tick->loss_set.emplace_back(data);
								 dat_tick->all_set.emplace_back(data);
								 break;
							 }
						 }
						 else{
							 if (dat_tick->dat_vec[i3].second.value <= start_value - dat_tick->profit)
							 {
								 auto data = std::make_tuple(start_value - dat_tick->dat_vec[i3].second.value, dat_tick->dat_vec[start].first,
									 dat_tick->dat_vec[start].second.value, dat_tick->dat_vec[i3].first, dat_tick->dat_vec[i3].second.value, direction, start, i3);
								 dat_tick->profit_set.emplace_back(data);
								 dat_tick->all_set.emplace_back(data);
								 break;
							 }
							 else if (dat_tick->dat_vec[i3].second.value >= start_value + dat_tick->loss)
							 {
								 auto data = std::make_tuple(start_value - dat_tick->dat_vec[i3].second.value, dat_tick->dat_vec[start].first,
									 dat_tick->dat_vec[start].second.value, dat_tick->dat_vec[i3].first, dat_tick->dat_vec[i3].second.value, direction, start, i3);
								 dat_tick->loss_set.emplace_back(data);
								 dat_tick->all_set.emplace_back(data);
								 break;
							 }
						 }
					 }
				 }

				 dat_tick->middle = 0;
				 for (auto& item : dat_tick->all_set)
				 {
					 dat_tick->middle += std::get<0>(item);
				 }

				 dat_tick->middle /= dat_tick->all_set.size();
				 label5->Text = dat_tick->middle.ToString();
				 dat_tick->dispersion = 0;
				 for (auto& item : dat_tick->all_set)
				 {
					 dat_tick->dispersion += pow(std::get<0>(item) - dat_tick->middle, 2);
				 }

				 dat_tick->dispersion /= dat_tick->all_set.size();
				 dat_tick->dispersion = sqrt(dat_tick->dispersion);
				 label6->Text = dat_tick->dispersion.ToString();

				 dat_tick->series_middle.clear();
				 dat_tick->get_middle_series();
				 drawGraph();
				 writeFile();
				 button1->Text = "Processed";
	}

		private: void	 writeFile()
		{
					 StreamWriter ^ sr = gcnew StreamWriter(toSysString(dat_tick->out_full_fname), false, System::Text::Encoding::Default);
					 String ^ str = "";
					 sr->WriteLine("Math : {0}\n", dat_tick->middle);
					 sr->WriteLine("Dispersion : {0}\n", dat_tick->dispersion);
					 sr->WriteLine("{0} \t {1} \t {2} \t\t\t {3} \t\t\t {4}  {5}  {6}", gcnew String("Number"), gcnew String("Type"), gcnew String("Start"),
						 gcnew String("Stop"), gcnew String("Result"), gcnew String("Start point"), gcnew String("Stop point"));

					 for (int i = 0; i < dat_tick->all_set.size(); ++i)
					 {
						 str = "";
						 DateTime dt_start = (XDate)std::get<1>(dat_tick->all_set[i]);
						 DateTime dt_end = (XDate)std::get<3>(dat_tick->all_set[i]);
						 String ^ type_order = (std::get<5>(dat_tick->all_set[i])) ? "Up" : "Down";
						 double balanse = std::get<0>(dat_tick->all_set[i]);
						 int number_start = std::get<6>(dat_tick->all_set[i]) + 1;
						 int number_stop = std::get<7>(dat_tick->all_set[i]) + 1;
						 str = (i + 1).ToString(CultureInfo::CreateSpecificCulture("en-GB"));
						 sr->WriteLine("{0} \t {1} \t {2:G} \t\ {3:G} \t {4} \t {5}      {6}", str, type_order, dt_start,
							 dt_end, balanse, number_start, number_stop);
					 }
					 sr->Close();
		}

			 private: void drawGraph(){
						  // Получим панель для рисования
						  GraphPane ^  pane = zedGraphControl1->GraphPane;
						  // Очистим список кривых на тот случай, если до этого сигналы уже были нарисованы
						  pane->CurveList->Clear();
						  int size = dat_tick->all_set.size();

						  int pos_min1 = 0, pos_max1 = 0, pos_min2 = 0, pos_max2 = 0;
						  array <double> ^ arx = gcnew array <double>(size);
						  array <double> ^ ary1 = gcnew array <double>(size);
						  array <double> ^ ary2 = gcnew array <double>(size);

						  for (int i = 0; i < size; i++)
						  {
							  arx[i] = i;
							  ary1[i] = std::get<0>(dat_tick->all_set[i]);
							  ary2[i] = dat_tick->series_middle[i];
							  if (ary1[pos_min1] > ary1[i]){
								  pos_min1 = i;
							  }
							  if (ary1[pos_max1] < ary1[i]){
								  pos_max1 = i;
							  }

							  if (ary2[pos_min2] > ary2[i]){
								  pos_min2 = i;
							  }
							  if (ary2[pos_max2] < ary2[i]){
								  pos_max2 = i;
							  }
						  }

						  FilteredPointList ^ filter_ins1 = gcnew FilteredPointList(arx, ary1);
						  FilteredPointList ^ filter_ins2 = gcnew FilteredPointList(arx, ary2);
						  int width = zedGraphControl1->Size.Width;

						  double min_value = (ary2[pos_min2] < ary1[pos_min1]) ? ary2[pos_min2] : ary1[pos_min1];
						  double max_value = (ary1[pos_max1]  > ary2[pos_max2]) ? ary1[pos_max1] : ary2[pos_max2];
						  pane->YAxis->Scale->Min = min_value;
						  pane->YAxis->Scale->Max = max_value;

						  pane->XAxis->Scale->Min = arx[0];
						  pane->XAxis->Scale->Max = arx[size - 1];
						  ZedGraph::LineItem ^ myCurveIns1 = pane->AddCurve("", filter_ins1, Color::Blue, SymbolType::None);
						  ZedGraph::LineItem ^ myCurveIns2 = pane->AddCurve("", filter_ins2, Color::Red, SymbolType::None);

						  filter_ins1->SetBounds(pane->XAxis->Scale->Min, pane->XAxis->Scale->Max, width);
						  filter_ins2->SetBounds(pane->XAxis->Scale->Min, pane->XAxis->Scale->Max, width);

						  pane->YAxis->Title->Text = "Values";
						  pane->XAxis->Title->Text = "Numbers";

						  pane->Title->Text = toSysString(dat_tick->name);
						  zedGraphControl1->AxisChange();
						  zedGraphControl1->Invalidate();
			 }


};
}
