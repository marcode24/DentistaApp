//---------------------------------------------------------------------------

#ifndef newDentistaH
#define newDentistaH
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
class TFormNewDentista : public TForm
{
__published:	// IDE-managed Components
	TLabel *lblNombre;
	TEdit *txtName;
	TEdit *txtFecha;
	TLabel *Label1;
	TEdit *txtPhone;
	TLabel *Label2;
	TEdit *txtLastName;
	TLabel *Label3;
	TComboBox *cmbGender;
	TLabel *Label4;
	TButton *btnCancelar;
	TButton *btnGuardar;
	TSQLConnection *SQLConnection1;
	TSQLQuery *SQLQuery1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btnGuardarClick(TObject *Sender);
	void __fastcall btnCancelarClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TFormNewDentista(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormNewDentista *FormNewDentista;
//---------------------------------------------------------------------------
#endif
