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
//---------------------------------------------------------------------------
class TFormHistorial : public TForm
{
__published:	// IDE-managed Components
	TEdit *txtNombre;
	TEdit *txtFolio;
	TButton *btnBuscar;
	TLabel *Label2;
	TLabel *Label1;
	TDBGrid *DBGrid1;
	TSQLConnection *SQLConnection1;
	TSQLQuery *SQLQuery1;
	void __fastcall btnBuscarClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormHistorial(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormHistorial *FormHistorial;
//---------------------------------------------------------------------------
#endif