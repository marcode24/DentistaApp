//---------------------------------------------------------------------------

#ifndef historialH
#define historialH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Data.DbxSqlite.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>
//---------------------------------------------------------------------------
class TFormHistorial : public TForm
{
__published:	// IDE-managed Components
	TEdit *txtNombre;
	TEdit *txtFolio;
	TButton *btnBuscar;
	TLabel *Label2;
	TLabel *Label1;
	TSQLConnection *SQLConnection1;
	TSQLQuery *SQLQuery1;
	TListBox *ListHistoria;
	TLabel *Label3;
	TButton *btnCancelar;
	void __fastcall btnBuscarClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btnCancelarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormHistorial(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormHistorial *FormHistorial;
//---------------------------------------------------------------------------
#endif
