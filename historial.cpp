//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "historial.h"
#include "inicio.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormHistorial *FormHistorial;
//---------------------------------------------------------------------------
__fastcall TFormHistorial::TFormHistorial(TComponent* Owner)
	: TForm(Owner)
{
	SQLConnection1->Params->Values["Database"] = "link";
}
//---------------------------------------------------------------------------
void __fastcall TFormHistorial::FormCreate(TObject *Sender)
{

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
		SQLConnection1->Open();
		SQLConnection1->Connected = true;
		String pacienteId = txtFolio->Text;
		SQLQuery1->Close();
		SQLQuery1->SQL->Clear();

		SQLQuery1->SQL->Add("SELECT id, nombre, apellido FROM Paciente WHERE id = :id;");
		SQLQuery1->ParamByName("id")->Value = pacienteId;
		SQLQuery1->Open();
		if(!SQLQuery1->Eof) {
			String nombreCompleto = SQLQuery1->FieldByName("nombre")->AsString +" "+ SQLQuery1->FieldByName("apellido")->AsString;
			txtNombre->Text = nombreCompleto;

			SQLQuery1->SQL->Clear();
			SQLQuery1->SQL->Add("SELECT concepto, precio FROM Historia WHERE id_paciente = :id;");
			SQLQuery1->ParamByName("id")->Value = pacienteId;
			SQLQuery1->Open();
			if(!SQLQuery1->Eof) {
				for(; !SQLQuery1->Eof; SQLQuery1->Next()){
					String conceptoCompleto = SQLQuery1->FieldByName("concepto")->AsString +", Precio: $"+ SQLQuery1->FieldByName("precio")->AsString;
					ListHistoria->Items->Add(conceptoCompleto);
				}
			}
		} else {
			ShowMessage("Paciente no encontrado, intente de nuevo");
			txtNombre->Text = "";
			ListHistoria->Clear();
		}
	} catch(Exception* e){
		ShowMessage("Error lista Dentistas: " + e->Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormHistorial::FormClose(TObject *Sender, TCloseAction &Action)
{
    SQLConnection1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormHistorial::btnCancelarClick(TObject *Sender)
{
	Inicio->Visible = true;
	FormHistorial->Visible = false;
}
//---------------------------------------------------------------------------

