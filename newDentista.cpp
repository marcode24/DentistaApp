//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "newDentista.h"
#include "inicio.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormNewDentista *FormNewDentista;
//---------------------------------------------------------------------------
__fastcall TFormNewDentista::TFormNewDentista(TComponent* Owner)
	: TForm(Owner)
{
	cmbGender->AddItem("Masculino", NULL);
	cmbGender->AddItem("Femenino", NULL);
    cmbGender->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormNewDentista::FormCreate(TObject *Sender)
{
	SQLConnection1->Params->Values["Database"] = "link";
	try {
		SQLConnection1->Open();
		SQLConnection1->Connected = true;
	} catch (EDatabaseError& E) {
		ShowMessage("Error Conexion:" + E.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormNewDentista::btnGuardarClick(TObject *Sender)
{
	String nombre = txtName->Text;
	String apellido = txtLastName->Text;
	Int64 fecha = StrToInt(txtFecha->Text);
	String sexo = cmbGender->Text;
	Int64 telefono = StrToInt(txtPhone->Text);
	String consulta = "INSERT INTO Dentista(nombre, apellido, telefono, sexo, nacimiento) VALUES (:Nombre, :Apellido, :Telefono, :Sexo, :Nacimiento);";
	try {
    	SQLConnection1->Open();
		SQLConnection1->Connected = true;
		SQLQuery1->SQL->Clear();
		SQLQuery1->SQL->Add(consulta);
		SQLQuery1->ParamByName("Nombre")->AsString = nombre;
		SQLQuery1->ParamByName("Apellido")->AsString = apellido;
		SQLQuery1->ParamByName("Nacimiento")->Value = fecha;
		SQLQuery1->ParamByName("Sexo")->AsString = sexo;
		SQLQuery1->ParamByName("Telefono")->Value = telefono;
		SQLQuery1->ExecSQL();
		if(SQLQuery1->RowsAffected >= 1) {
			ShowMessage("Dentista Agregado correctamente");
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

void __fastcall TFormNewDentista::btnCancelarClick(TObject *Sender)
{
	FormNewDentista->Visible = false;
    Inicio->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormNewDentista::FormClose(TObject *Sender, TCloseAction &Action)

{
     SQLConnection1->Close();
}
//---------------------------------------------------------------------------

