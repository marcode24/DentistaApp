object FormNewDentista: TFormNewDentista
  Left = 0
  Top = 0
  Caption = 'Agregar Dentista'
  ClientHeight = 217
  ClientWidth = 461
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
  object lblNombre: TLabel
    Left = 56
    Top = 32
    Width = 44
    Height = 13
    Caption = 'Nombre: '
  end
  object Label1: TLabel
    Left = 28
    Top = 72
    Width = 72
    Height = 13
    Caption = 'Fecha de Nac: '
  end
  object Label2: TLabel
    Left = 54
    Top = 112
    Width = 46
    Height = 13
    Caption = 'T'#233'lefono:'
  end
  object Label3: TLabel
    Left = 256
    Top = 32
    Width = 44
    Height = 13
    Caption = 'Apellido: '
  end
  object Label4: TLabel
    Left = 256
    Top = 72
    Width = 31
    Height = 13
    Caption = 'Sexo: '
  end
  object txtName: TEdit
    Left = 106
    Top = 29
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object txtFecha: TEdit
    Left = 106
    Top = 69
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object txtPhone: TEdit
    Left = 106
    Top = 109
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object txtLastName: TEdit
    Left = 306
    Top = 29
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object cmbGender: TComboBox
    Left = 306
    Top = 69
    Width = 121
    Height = 21
    TabOrder = 4
  end
  object btnCancelar: TButton
    Left = 54
    Top = 160
    Width = 75
    Height = 25
    Caption = 'Regresar'
    TabOrder = 5
    OnClick = btnCancelarClick
  end
  object btnGuardar: TButton
    Left = 152
    Top = 160
    Width = 75
    Height = 25
    Caption = 'Guardar'
    TabOrder = 6
    OnClick = btnGuardarClick
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
    Left = 304
    Top = 176
  end
  object SQLQuery1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 376
    Top = 176
  end
end
