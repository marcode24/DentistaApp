//---------------------------------------------------------------------------

#ifndef inicioH
#define inicioH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TInicio : public TForm
{
__published:	// IDE-managed Components
	TButton *btnNuevoPaciente;
	TButton *btnNuevoDentista;
	TButton *btnHistorial;
	void __fastcall btnNuevoDentistaClick(TObject *Sender);
	void __fastcall btnNuevoPacienteClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TInicio(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TInicio *Inicio;
//---------------------------------------------------------------------------
#endif
