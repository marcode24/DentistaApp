object FormNewPaciente: TFormNewPaciente
  Left = 0
  Top = 0
  Caption = 'Nuevo Paciente'
  ClientHeight = 217
  ClientWidth = 465
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
    Top = 24
    Width = 44
    Height = 13
    Caption = 'Nombre: '
  end
  object Label1: TLabel
    Left = 28
    Top = 64
    Width = 72
    Height = 13
    Caption = 'Fecha de Nac: '
  end
  object Label2: TLabel
    Left = 54
    Top = 104
    Width = 46
    Height = 13
    Caption = 'T'#233'lefono:'
  end
  object Label3: TLabel
    Left = 256
    Top = 24
    Width = 44
    Height = 13
    Caption = 'Apellido: '
  end
  object Label4: TLabel
    Left = 256
    Top = 64
    Width = 31
    Height = 13
    Caption = 'Sexo: '
  end
  object Label5: TLabel
    Left = 23
    Top = 144
    Width = 77
    Height = 13
    Caption = 'Asigar Dentista:'
  end
  object txtName: TEdit
    Left = 106
    Top = 21
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object txtFecha: TEdit
    Left = 106
    Top = 61
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object txtPhone: TEdit
    Left = 106
    Top = 101
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object txtLastName: TEdit
    Left = 306
    Top = 21
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object btnCancelar: TButton
    Left = 28
    Top = 184
    Width = 75
    Height = 25
    Caption = 'Regresar'
    TabOrder = 4
    OnClick = btnCancelarClick
  end
  object btnGuardar: TButton
    Left = 152
    Top = 184
    Width = 75
    Height = 25
    Caption = 'Guardar'
    TabOrder = 5
    OnClick = btnGuardarClick
  end
  object cmbGender: TComboBox
    Left = 306
    Top = 61
    Width = 121
    Height = 21
    TabOrder = 6
  end
  object cmbDentistas: TComboBox
    Left = 106
    Top = 141
    Width = 121
    Height = 21
    TabOrder = 7
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
    Left = 360
    Top = 141
  end
  object SQLQuery1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 432
    Top = 141
  end
end
