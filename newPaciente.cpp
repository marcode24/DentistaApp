//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "newPaciente.h"
#include "inicio.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormNewPaciente *FormNewPaciente;
//---------------------------------------------------------------------------
__fastcall TFormNewPaciente::TFormNewPaciente(TComponent* Owner)
	: TForm(Owner)
{
	cmbGender->AddItem("Masculino", NULL);
	cmbGender->AddItem("Femenino", NULL);
	cmbGender->ItemIndex = 0;
	SQLConnection1->Params->Values["Database"] = "link";
	try {
		SQLConnection1->Open();
		SQLConnection1->Connected = true;
	} catch (EDatabaseError& E) {
		ShowMessage("Error Conexion:" + E.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormNewPaciente::FormCreate(TObject *Sender)
{
	try {
    	SQLConnection1->Open();
		SQLConnection1->Connected = true;
		String consulta = "SELECT * FROM Dentista;";
		SQLQuery1->SQL->Clear();
		SQLQuery1->SQL->Add(consulta);
		SQLQuery1->Open();
		for(; !SQLQuery1->Eof; SQLQuery1->Next()){
			String nombreCompleto = SQLQuery1->FieldByName("nombre")->AsString +" "+ SQLQuery1->FieldByName("apellido")->AsString;
			cmbDentistas->AddItem(nombreCompleto, (TObject*)SQLQuery1->FieldByName("id")->AsInteger);
		}
	} catch(EDatabaseError& E){
		ShowMessage("Error lista Dentistas: " + E.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormNewPaciente::btnGuardarClick(TObject *Sender)
{
	try {
		String nombre = txtName->Text;
		String apellido = txtLastName->Text;
		String fecha = txtFecha->Text;
		Int64 telefono = StrToInt(txtPhone->Text);
		String sexo = cmbGender->Text;
		int id = cmbDentistas->ItemIndex;
		String dentistaId = (int)cmbDentistas->Items->Objects[id];
		String consulta = "INSERT INTO Paciente(nombre, apellido, telefono, sexo, nacimiento, id_dentista) VALUES (:Nombre, :Apellido, :Telefono, :Sexo, :Nacimiento, :Dentista);";
		SQLQuery1->SQL->Add(consulta);
		SQLQuery1->ParamByName("Nombre")->Value = nombre;
		SQLQuery1->ParamByName("Apellido")->Value = apellido;
		SQLQuery1->ParamByName("Nacimiento")->Value = fecha;
		SQLQuery1->ParamByName("Sexo")->Value = sexo;
		SQLQuery1->ParamByName("Telefono")->Value = telefono;
		SQLQuery1->ParamByName("Dentista")->Value = dentistaId;
		SQLQuery1->ExecSQL();
		if(SQLQuery1->RowsAffected >= 1) {
			ShowMessage("Paciente Agregado correctamente");
			txtName->Text = "";
			txtLastName->Text = "";
			txtFecha->Text = "";
			txtPhone->Text= "";
		}
		SQLConnection1->Close();
	} catch(EDatabaseError& E){
		ShowMessage("Error Nuevo Dentista: "+ E.Message);
	}

}
//---------------------------------------------------------------------------

void __fastcall TFormNewPaciente::btnCancelarClick(TObject *Sender)
{
  Inicio->Visible = true;
  FormNewPaciente-> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormNewPaciente::FormClose(TObject *Sender, TCloseAction &Action)

{
	SQLConnection1->Close();
}
//---------------------------------------------------------------------------

