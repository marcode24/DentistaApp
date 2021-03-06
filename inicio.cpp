//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "inicio.h"
#include "newDentista.h"
#include "newPaciente.h"
#include "historial.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TInicio *Inicio;
//---------------------------------------------------------------------------
__fastcall TInicio::TInicio(TComponent* Owner)
	: TForm(Owner)
{
	SQLConnection1->Params->Values["Database"] = "link";
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
String idPaciente = "";
void __fastcall TInicio::btnBuscarClick(TObject *Sender)
{
	try {
		SQLConnection1->Open();
		SQLConnection1->Connected = true;
		String pacienteId = txtFolio->Text;
		SQLQuery1->Close();
		SQLQuery1->SQL->Clear();
		String consulta = "SELECT id, nombre, apellido FROM Paciente WHERE id = :id;";
		SQLQuery1->SQL->Add(consulta);
		SQLQuery1->ParamByName("id")->Value = pacienteId;
		SQLQuery1->Open();
		if(!SQLQuery1->Eof) {
			idPaciente = SQLQuery1->FieldByName("id")->AsString;
			String nombreCompleto = SQLQuery1->FieldByName("nombre")->AsString +" "+ SQLQuery1->FieldByName("apellido")->AsString;
			txtNombre->Text = nombreCompleto;
			txtConcepto->Enabled = true;
			txtPrecio->Enabled = true;
			btnCancelar->Enabled = true;
			btnGuardar->Enabled = true;

		} else {
			ShowMessage("Paciente no encontrado, intente de nuevo");
			txtNombre->Text = "";
			txtConcepto->Enabled = false;
			txtPrecio->Enabled = false;
			btnCancelar->Enabled = false;
			btnGuardar->Enabled = false;
		}
		SQLConnection1->Close();
	} catch(EDatabaseError& E){
		ShowMessage("Error lista Dentistas: " + E.Message);
	}
}
//---------------------------------------------------------------------------


void __fastcall TInicio::btnCancelarClick(TObject *Sender)
{
	txtFolio->Text = "";
	txtNombre->Text = "";
	txtConcepto->Enabled = false;
	txtPrecio->Enabled = false;
	btnCancelar->Enabled = false;
	btnGuardar->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TInicio::btnGuardarClick(TObject *Sender)
{
	String concepto = txtConcepto->Text;
	Double precio = txtPrecio->Text.ToDouble();
	if(idPaciente == "") {
		return ShowMessage("ingrese un folio de paciente");
	}
	try {
		SQLConnection1->Open();
		SQLQuery1->SQL->Clear();
		String consulta = "INSERT INTO Historia(id_paciente, concepto, precio) VALUES (:id, :concepto, :precio);";
		SQLQuery1->SQL->Add(consulta);
		SQLQuery1->ParamByName("id")->Value = idPaciente;
		SQLQuery1->ParamByName("concepto")->Value = concepto;
		SQLQuery1->ParamByName("precio")->Value = precio;
		SQLQuery1->ExecSQL();
		if(SQLQuery1->RowsAffected >= 1) {
			txtFolio->Text = "";
			txtNombre->Text = "";
			txtConcepto->Text = "";
            txtPrecio->Text = "";
			txtConcepto->Enabled = false;
			txtPrecio->Enabled = false;
			btnCancelar->Enabled = false;
			btnGuardar->Enabled = false;
			ShowMessage("Consulta guardada correctamente");
		}
		SQLConnection1->Close();
	} catch(EDatabaseError& E){
		ShowMessage("Error Nueva Consulta: "+ E.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TInicio::btnHistorialClick(TObject *Sender)
{
	FormHistorial->Visible = true;
	Inicio->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TInicio::FormClose(TObject *Sender, TCloseAction &Action)
{
	SQLConnection1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TInicio::FormCreate(TObject *Sender)
{
	try {
		SQLConnection1->Open();
		SQLConnection1->Connected = true;
	} catch (EDatabaseError& E) {
		ShowMessage("Error Conexion:" + E.Message);
	}
}
//---------------------------------------------------------------------------

