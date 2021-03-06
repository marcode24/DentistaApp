//---------------------------------------------------------------------------

#ifndef newPacienteH
#define newPacienteH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.DbxSqlite.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
//---------------------------------------------------------------------------
class TFormNewPaciente : public TForm
{
__published:	// IDE-managed Components
	TLabel *lblNombre;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *txtName;
	TEdit *txtFecha;
	TEdit *txtPhone;
	TEdit *txtLastName;
	TButton *btnCancelar;
	TButton *btnGuardar;
	TSQLConnection *SQLConnection1;
	TSQLQuery *SQLQuery1;
	TLabel *Label4;
	TComboBox *cmbGender;
	TLabel *Label5;
	TComboBox *cmbDentistas;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btnGuardarClick(TObject *Sender);
	void __fastcall btnCancelarClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TFormNewPaciente(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormNewPaciente *FormNewPaciente;
//---------------------------------------------------------------------------
#endif
