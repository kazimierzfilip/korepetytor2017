object Form2: TForm2
  Left = 337
  Top = 248
  BorderStyle = bsToolWindow
  Caption = 'Tablica wynik'#243'w'
  ClientHeight = 280
  ClientWidth = 255
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object RichEdit1: TRichEdit
    Left = 0
    Top = 0
    Width = 255
    Height = 280
    Align = alClient
    Alignment = taCenter
    BorderStyle = bsNone
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = []
    Lines.Strings = (
      'Witaj w pomocy programu:)'
      ''
      'Quiz wybierasz za pomoc'#261' '
      'menu Otw'#243'rz, wybieraj'#261'c '
      'odpowiedni plik z katalogu '
      'quizy.'
      ''
      'Po za'#322'adowaniu quizu, naci'#347'nij '
      'klawisz ? aby pozna'#263' '
      'odpowied'#378', albo klawisz >> aby '
      'przej'#347#263' do '
      'nast'#281'pnego pytania. '
      'R'#243'wnolegle do klawisza >> mo'#380'na '
      'stosowa'#263' '
      'klawisz ENTER oraz SPACJA, z '
      'takim samym skutkiem.'
      ''
      'Czionk'#281' i t'#322'o aplikacji mo'#380'esz '
      'zmienia'#263' w menu Widok, '
      'odpowiednio w podmenu '
      'Czcionka i T'#322'o.'
      ''
      'Ewentualne pytania kieruj do '
      'autora programu.'
      ''
      'Kazimierz Filip'
      '')
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 0
  end
end
