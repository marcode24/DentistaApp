//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "historial.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormHistorial *FormHistorial;
//---------------------------------------------------------------------------
__fastcall TFormHistorial::TFormHistorial(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormHistorial::FormCreate(TObject *Sender)
{
	SQLConnection1->Params->Add("tu link de la base aqui");
	try {
		SQLConnection1->Open();
		SQLConnection1->Connected = true;
	} catch (EDatabaseError& E) {
		ShowMessage("Error Conexion:" + E.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormHistorial::btnBuscarClick(TObject *Sender)
{
	String pacienteId = txtFolio->Text;
	try {
		String consulta = "SELECT nombre, apellido FROM Paciente WHERE id = :id;";
		SQLQuery1->SQL->Clear();
		SQLQuery1->SQL->Add(consulta);
		SQLQuery1->ParamByName("id")->Value = pacienteId;
		SQLQuery1->Open();
		/* if(!SQLQuery1->Eof) {
			String nombreCompleto = SQLQuery1->FieldByName("nombre")->AsString +" "+ SQLQuery1->FieldByName("apellido")->AsString;
			txtNombre->Text = nombreCompleto;
			for(; !SQLQuery1->Eof; SQLQuery1->Next()){
			String nombreCompleto = SQLQuery1->FieldByName("nombre")->AsString +" "+ SQLQuery1->FieldByName("apellido")->AsString;
			cmbDentistas->AddItem(nombreCompleto, (TObject*)SQLQuery1->FieldByName("id")->AsInteger);
		}

		} else {
			ShowMessage("Paciente no encontrado, intente de nuevo");
			txtNombre->Text = "";
		}  */
	} catch(Exception* e){
		ShowMessage("Error lista Dentistas: " + e->Message);
	}
}
//---------------------------------------------------------------------------

