//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "inicio.h"
#include "newDentista.h"
#include "newPaciente.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TInicio *Inicio;
//---------------------------------------------------------------------------
__fastcall TInicio::TInicio(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TInicio::btnNuevoDentistaClick(TObject *Sender)
{
	FormNewDentista->Visible = true;
	Inicio->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TInicio::btnNuevoPacienteClick(TObject *Sender)
{
	FormNewPaciente->Visible = true;
	Inicio->Visible = false;
}
//---------------------------------------------------------------------------

