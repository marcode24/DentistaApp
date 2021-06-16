//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("newPaciente.cpp", FormNewPaciente);
USEFORM("newDentista.cpp", FormNewDentista);
USEFORM("inicio.cpp", Inicio);
USEFORM("historial.cpp", FormHistorial);
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
		Application->CreateForm(__classid(TFormHistorial), &FormHistorial);
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
