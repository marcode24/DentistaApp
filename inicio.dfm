object Inicio: TInicio
  Left = 0
  Top = 0
  ActiveControl = btnNuevoPaciente
  Caption = 'Inicio'
  ClientHeight = 314
  ClientWidth = 396
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 47
    Top = 80
    Width = 26
    Height = 13
    Caption = 'Folio:'
  end
  object Label2: TLabel
    Left = 32
    Top = 120
    Width = 41
    Height = 13
    Caption = 'Nombre:'
  end
  object Label3: TLabel
    Left = 23
    Top = 168
    Width = 50
    Height = 13
    Caption = 'Concepto:'
  end
  object Label4: TLabel
    Left = 32
    Top = 250
    Width = 33
    Height = 13
    Caption = 'Precio:'
  end
  object btnNuevoPaciente: TButton
    Left = 32
    Top = 24
    Width = 89
    Height = 25
    Caption = 'Nuevo Paciente'
    TabOrder = 0
    OnClick = btnNuevoPacienteClick
  end
  object btnNuevoDentista: TButton
    Left = 152
    Top = 24
    Width = 89
    Height = 25
    Caption = 'Nuevo Dentista'
    TabOrder = 1
    OnClick = btnNuevoDentistaClick
  end
  object btnHistorial: TButton
    Left = 272
    Top = 24
    Width = 97
    Height = 25
    Caption = 'Historial Pacientes'
    TabOrder = 2
    OnClick = btnHistorialClick
  end
  object btnBuscar: TButton
    Left = 272
    Top = 75
    Width = 97
    Height = 25
    Caption = 'Buscar'
    TabOrder = 3
    OnClick = btnBuscarClick
  end
  object txtNombre: TEdit
    Left = 79
    Top = 117
    Width = 290
    Height = 21
    Enabled = False
    TabOrder = 4
  end
  object txtConcepto: TEdit
    Left = 79
    Top = 165
    Width = 290
    Height = 21
    Enabled = False
    TabOrder = 5
  end
  object txtPrecio: TMaskEdit
    Left = 79
    Top = 242
    Width = 50
    Height = 21
    Enabled = False
    EditMask = '!999.99;1;'
    MaxLength = 6
    TabOrder = 6
    Text = '   .  '
  end
  object txtFolio: TEdit
    Left = 79
    Top = 77
    Width = 162
    Height = 21
    TabOrder = 7
  end
  object btnGuardar: TButton
    Left = 280
    Top = 245
    Width = 89
    Height = 25
    Caption = 'Guardar'
    Enabled = False
    TabOrder = 8
    OnClick = btnGuardarClick
  end
  object btnCancelar: TButton
    Left = 152
    Top = 245
    Width = 89
    Height = 25
    Caption = 'Cancelar'
    Enabled = False
    TabOrder = 9
    OnClick = btnCancelarClick
  end
  object SQLConnection1: TSQLConnection
    DriverName = 'Sqlite'
    KeepConnection = False
    LoginPrompt = False
    Params.Strings = (
      'DriverUnit=Data.DbxSqlite'
      
        'DriverPackageLoader=TDBXSqliteDriverLoader,DBXSqliteDriver200.bp' +
        'l'
      
        'MetaDataPackageLoader=TDBXSqliteMetaDataCommandFactory,DbxSqlite' +
        'Driver200.bpl'
      'FailIfMissing=True')
    Left = 8
    Top = 263
  end
  object SQLQuery1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 40
    Top = 263
  end
end
