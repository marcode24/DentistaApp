object Inicio: TInicio
  Left = 0
  Top = 0
  ActiveControl = btnNuevoPaciente
  Caption = 'Inicio'
  ClientHeight = 336
  ClientWidth = 405
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
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
  end
end
