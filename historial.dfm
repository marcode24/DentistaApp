object FormHistorial: TFormHistorial
  Left = 0
  Top = 0
  Caption = 'Historial de Pacientes'
  ClientHeight = 321
  ClientWidth = 418
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 32
    Top = 64
    Width = 41
    Height = 13
    Caption = 'Nombre:'
  end
  object Label1: TLabel
    Left = 47
    Top = 24
    Width = 26
    Height = 13
    Caption = 'Folio:'
  end
  object Label3: TLabel
    Left = 32
    Top = 93
    Width = 38
    Height = 13
    Caption = 'Historial'
  end
  object txtNombre: TEdit
    Left = 79
    Top = 61
    Width = 290
    Height = 21
    Enabled = False
    TabOrder = 0
  end
  object txtFolio: TEdit
    Left = 79
    Top = 21
    Width = 162
    Height = 21
    TabOrder = 1
  end
  object btnBuscar: TButton
    Left = 272
    Top = 19
    Width = 97
    Height = 25
    Caption = 'Buscar'
    TabOrder = 2
    OnClick = btnBuscarClick
  end
  object ListHistoria: TListBox
    Left = 79
    Top = 93
    Width = 290
    Height = 145
    ItemHeight = 13
    TabOrder = 3
  end
  object btnCancelar: TButton
    Left = 294
    Top = 264
    Width = 75
    Height = 25
    Caption = 'Regresar'
    TabOrder = 4
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
