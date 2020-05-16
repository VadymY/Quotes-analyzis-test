#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Gogen::MyForm form;
	Application::Run(%form);
}


//System::IO::StreamReader ^ sr = gcnew StreamReader(openFileDialog1->FileName, System::Text::Encoding::Default);
//String ^ str = sr->ReadLine();
//array<String^> ^ StringArray = nullptr;
//while (!sr->EndOfStream)
//{
// str = sr->ReadLine();
// StringArray = str->Split(',');
// if (StringArray->Length > 1)
// {
//	 dat_tick->name = Sysstr_to_string(StringArray[0]);
//	 double  dt = Convert_from_DT(StringArray[2], StringArray[3]);
//	 double value = Double::Parse(StringArray[4], NumberStyles::Float, CultureInfo::CreateSpecificCulture("en-EN"));
//	 Int32 volume = Int32::Parse(StringArray[5], NumberStyles::Integer, CultureInfo::CreateSpecificCulture("en-EN"));
//	 dat_tick->dat.insert(std::make_pair(dt, trade_data(value, volume)));
// }
//}
//sr->Close();