//---------------------------------------------------------------------------

#ifndef inicioH
#define inicioH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Mask.hpp>
#include <Data.DB.hpp>
#include <Data.DbxSqlite.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
//---------------------------------------------------------------------------
class TInicio : public TForm
{
__published:	// IDE-managed Components
	TButton *btnNuevoPaciente;
	TButton *btnNuevoDentista;
	TButton *btnHistorial;
	TLabel *Label1;
	TLabel *Label2;
	TButton *btnBuscar;
	TEdit *txtNombre;
	TLabel *Label3;
	TEdit *txtConcepto;
	TLabel *Label4;
	TMaskEdit *txtPrecio;
	TEdit *txtFolio;
	TButton *btnGuardar;
	TButton *btnCancelar;
	TSQLConnection *SQLConnection1;
	TSQLQuery *SQLQuery1;
	void __fastcall btnNuevoDentistaClick(TObject *Sender);
	void __fastcall btnNuevoPacienteClick(TObject *Sender);
	void __fastcall btnBuscarClick(TObject *Sender);
	void __fastcall btnCancelarClick(TObject *Sender);
	void __fastcall btnGuardarClick(TObject *Sender);
	void __fastcall btnHistorialClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TInicio(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TInicio *Inicio;
//---------------------------------------------------------------------------
#endif
