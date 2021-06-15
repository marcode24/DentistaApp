//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "newPaciente.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormNewPaciente *FormNewPaciente;
//---------------------------------------------------------------------------
__fastcall TFormNewPaciente::TFormNewPaciente(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------


void __fastcall TFormNewPaciente::FormCreate(TObject *Sender)
{
	SQLConnection1->Params->Add("Database=C:\\Users\\karla\\Documents\\Embarcadero\\Studio\\Projects\\Dentista\\Dentista1.db");
	try {
		SQLConnection1->Open();
		SQLConnection1->Connected = true;
		String consulta = "SELECT id, nombre, apellido FROM Dentista;";
		SQLQuery1->SQL->Clear();
		SQLQuery1->SQL->Add(consulta);
		SQLQuery1->Open();
		SQLQuery1->ExecSQL();
		for(; !SQLQuery1->Eof; SQLQuery1->Next()){
			cmbDentistas->AddItem(SQLQuery1->FieldByName("nombre")->AsString, (TObject*)SQLQuery1->FieldByName("id")->AsInteger);
		}
	} catch (EDatabaseError& E) {
		ShowMessage("Error Conexion:" + E.Message);
	}
}
//---------------------------------------------------------------------------

