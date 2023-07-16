//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
using namespace std;
#include<string>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

AnsiString sciezka;

int i=0;          //Licznik linijek

int points; //punkty gracza

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void onswitch(bool ch, bool en, bool vi)
{
    Form1->RadioButton1->Checked=ch;
    Form1->RadioButton2->Checked=ch;
    Form1->RadioButton3->Checked=ch;         //w��cznik p�l
    Form1->RadioButton4->Checked=ch;
    Form1->RadioButton1->Enabled=en;
    Form1->RadioButton2->Enabled=en;
    Form1->RadioButton3->Enabled=en;
    Form1->RadioButton4->Enabled=en;
    Form1->RadioButton1->Visible=vi;
    Form1->RadioButton2->Visible=vi;
    Form1->RadioButton3->Visible=vi;
    Form1->RadioButton4->Visible=vi;
}


//---------------------------------------------------------------------------


void __fastcall TForm1::To1Click(TObject *Sender)
{
    if(ColorDialog1->Execute())
    Form1->Color=ColorDialog1->Color;      //zmiania koloru t�a
}

//---------------------------------------------------------------------------

int win(AnsiString odp)     //Sprawdza wygran� wysy�a 1-wygrana 0-nie
{                      // koloruje prawid�owe/z�e odpowiedzi
    int win=0;
     if(odp.Trim()=="a" || odp.Trim()=="A")
     {
        if(Form1->RadioButton1->Checked) win=1;
        Form1->RadioButton1->Color=clLime;
      }
      else if(odp.Trim()=="b" || odp.Trim()=="B")
      {
        if(Form1->RadioButton2->Checked) win=1;
        Form1->RadioButton2->Color=clLime;
      }
      else if(odp.Trim()=="c" || odp.Trim()=="C")
      {
        if(Form1->RadioButton3->Checked) win=1;
        Form1->RadioButton3->Color=clLime;
      }
      else if(odp.Trim()=="d" || odp.Trim()=="D")
      {
        if(Form1->RadioButton4->Checked) win=1;
        Form1->RadioButton4->Color=clLime;
      }

    if(win==0)
    {
       if(Form1->RadioButton1->Checked) Form1->RadioButton1->Color=clRed;
       else if(Form1->RadioButton2->Checked) Form1->RadioButton2->Color=clRed;
       else if(Form1->RadioButton3->Checked) Form1->RadioButton3->Color=clRed;
       else if(Form1->RadioButton4->Checked) Form1->RadioButton4->Color=clRed;
    }
    return win;
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) //Sprawdza odpowied�, punktuje. Przechodzi do nast�pnego
{                                                     //Klawisz >>


    if(win(Memo1->Lines->Strings[i+5]))    //Wygrana
    {
       points++;          //Punkty
       Form1->Image2->Visible=true; Form1->Image1->Visible=false;
       Application->ProcessMessages(); Sleep(400);
       Form1->Image2->Visible=false; Form1->Image1->Visible=true;       //Animacje
       Application->ProcessMessages(); Sleep(400);
       Form1->Image2->Visible=true; Form1->Image1->Visible=false;
    }
    Application->ProcessMessages(); Sleep(900);
    Form1->Image1->Visible=false; Form1->Image2->Visible=false;


    if(i>=(Memo1->Lines->Count-7))
    {                                                //----Czy koniec---
        Button1->Enabled=false;
        Button1->Visible=false;
        Button2->Enabled=false;
        Button2->Visible=false;
        onswitch(false,false,false);
        OpenDialog1->Tag=0;
        Label1->Caption="KONIEC\n\n \
        Masz "+IntToStr(points)+" pkt na "+IntToStr((Memo1->Lines->Count)/6)+ " mo�liwych.   --^Wybierz quiz^--";
        AnsiString p=(IntToStr(points)+"/"+IntToStr((Memo1->Lines->Count)/6)+" --- "+Date().FormatString("dd-mm")+"  "+Time().FormatString("hh:nn"));
       // Memo2->Lines->Add(p);
        return;
    }


    i+=6;                                 //Kolejne pytanie

    Button2->Enabled=true;
    onswitch(false, true, true);
    RadioButton1->Color=clBtnFace;
    RadioButton2->Color=clBtnFace;      //Ustawienie tablicy
    RadioButton3->Color=clBtnFace;
    RadioButton4->Color=clBtnFace;

    if(OpenDialog1->Tag==1)
    {
        Label1->Caption=Utf8ToAnsi(Memo1->Lines->Strings[i]);
        RadioButton1->Caption=Utf8ToAnsi(Memo1->Lines->Strings[i+1]);
        RadioButton2->Caption=Utf8ToAnsi(Memo1->Lines->Strings[i+2]);     //Wczytanie nowych pyta�
        RadioButton3->Caption=Utf8ToAnsi(Memo1->Lines->Strings[i+3]);
        RadioButton4->Caption=Utf8ToAnsi(Memo1->Lines->Strings[i+4]);     //z polskimi znakami (pliki)
    }
    else
    {
        Label1->Caption=Memo1->Lines->Strings[i];
        RadioButton1->Caption=Memo1->Lines->Strings[i+1];
        RadioButton2->Caption=Memo1->Lines->Strings[i+2];     //Wczytanie nowych pyta�
        RadioButton3->Caption=Memo1->Lines->Strings[i+3];
        RadioButton4->Caption=Memo1->Lines->Strings[i+4];    //(memo2)
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) //Klawisz "?"
{                                                   //Sprawdza odpowied�, zaznacza poprawn�
  Button2->Enabled=false;
  RadioButton1->Enabled=false;
  RadioButton2->Enabled=false;
  RadioButton3->Enabled=false;
  RadioButton4->Enabled=false;

  win(Memo1->Lines->Strings[i+5]);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Czcionka1Click(TObject *Sender)
{
    if(FontDialog1->Execute())
     {                                                //Zmiana czcionek
     Label1->Font->Name = FontDialog1->Font->Name;
     Label1->Font->Color = FontDialog1->Font->Color;
     Label1->Font->Size =  FontDialog1->Font->Size;
     Label1->Font->Style = FontDialog1->Font->Style;
     RadioButton1->Font->Name = FontDialog1->Font->Name;
     RadioButton1->Font->Color = FontDialog1->Font->Color;
     RadioButton1->Font->Size = FontDialog1->Font->Size;
     RadioButton1->Font->Style = FontDialog1->Font->Style;
     RadioButton2->Font->Name = FontDialog1->Font->Name;
     RadioButton2->Font->Color = FontDialog1->Font->Color;
     RadioButton2->Font->Size = FontDialog1->Font->Size;
     RadioButton2->Font->Style = FontDialog1->Font->Style;
     RadioButton3->Font->Name = FontDialog1->Font->Name;
     RadioButton3->Font->Color = FontDialog1->Font->Color;
     RadioButton3->Font->Size = FontDialog1->Font->Size;
     RadioButton3->Font->Style = FontDialog1->Font->Style;
     RadioButton4->Font->Name = FontDialog1->Font->Name;
     RadioButton4->Font->Color = FontDialog1->Font->Color;
     RadioButton4->Font->Size = FontDialog1->Font->Size;
     RadioButton4->Font->Style = FontDialog1->Font->Style;
     }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Pomoc1Click(TObject *Sender)
{
   Form2->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{                                                //Enter i spacja jako klawisz >>
    if(Key==VK_RETURN || Key==VK_SPACE) Form1->Button1Click(Form1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    //Memo2->Lines->LoadFromFile("chart.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    //Memo2->Lines->SaveToFile("chart.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zpliku1Click(TObject *Sender)
{
if(OpenDialog1->Execute())                           //Otw�rz z pliku i rozpocznij quiz
{
  try
  {
    OpenDialog1->Tag=1;  // tag=1 - polskie znaki z pliku potrzebne
    i=0;
    points=0;
    Memo1->Lines->LoadFromFile(OpenDialog1->FileName);   //za�adowanie tre�ci quizu z pliku
    RadioButton1->Color=clBtnFace;
    RadioButton2->Color=clBtnFace;      //reset kolork�w
    RadioButton3->Color=clBtnFace;
    RadioButton4->Color=clBtnFace;
    Label1->Caption=Utf8ToAnsi(Memo1->Lines->Strings[0]);         //Utf8ToAnsi() dla polskich znak�w
    RadioButton1->Caption=Utf8ToAnsi(Memo1->Lines->Strings[1]);
    RadioButton2->Caption=Utf8ToAnsi(Memo1->Lines->Strings[2]);
    RadioButton3->Caption=Utf8ToAnsi(Memo1->Lines->Strings[3]);  //Za�adowanie pierwszego pytania po otwarciu quizu
    RadioButton4->Caption=Utf8ToAnsi(Memo1->Lines->Strings[4]);
    onswitch(false, true, true);
    Button1->Visible=true;               //w��czenie interfejsu
    Button1->Enabled=true;
    Button2->Visible=true;
    Button2->Enabled=true;
  }

  catch (...)
  {
      Application->MessageBox("B��d odczytu", "B��d", MB_OK) ;
  }
}
}
//---------------------------------------------------------------------------

void menuclick(TMemo *quiz)
{
    i=0;
    points=0;
    Form1->Memo1->Lines=quiz->Lines;   //za�adowanie tre�ci quizu z memo
    Form1->RadioButton1->Color=clBtnFace;
    Form1->RadioButton2->Color=clBtnFace;      //reset kolork�w
    Form1->RadioButton3->Color=clBtnFace;
    Form1->RadioButton4->Color=clBtnFace;
    Form1->Label1->Caption=Form1->Memo1->Lines->Strings[0];
    Form1->RadioButton1->Caption=Form1->Memo1->Lines->Strings[1];
    Form1->RadioButton2->Caption=Form1->Memo1->Lines->Strings[2];
    Form1->RadioButton3->Caption=Form1->Memo1->Lines->Strings[3];  //Za�adowanie pierwszego pytania po otwarciu quizu
    Form1->RadioButton4->Caption=Form1->Memo1->Lines->Strings[4];
    onswitch(false, true, true);
    Form1->Button1->Visible=true;               //w��czenie interfejsu
    Form1->Button1->Enabled=true;
    Form1->Button2->Visible=true;
    Form1->Button2->Enabled=true;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Spoeczna1Click(TObject *Sender)
{
                                             //Otw�rz z Spoleczna1 i rozpocznij quiz
    menuclick(Spoleczna1);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Osobowo1Click(TObject *Sender)
{
    menuclick(Osobow1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Etyka2Click(TObject *Sender)
{
      menuclick(Etyka1);
}
//---------------------------------------------------------------------------

