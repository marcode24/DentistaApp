//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("newDentista.cpp", FormNewDentista);
USEFORM("inicio.cpp", Inicio);
USEFORM("newPaciente.cpp", FormNewPaciente);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TInicio), &Inicio);
		Application->CreateForm(__classid(TFormNewDentista), &FormNewDentista);
		Application->CreateForm(__classid(TFormNewPaciente), &FormNewPaciente);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
