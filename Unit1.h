//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <FileCtrl.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TOpenDialog *OpenDialog1;
        TFontDialog *FontDialog1;
        TColorDialog *ColorDialog1;
        TMenuItem *Otwrz1;
        TMenuItem *Widok1;
        TMenuItem *Czcionka1;
        TMenuItem *To1;
        TMenuItem *Info1;
        TMenuItem *Pomoc1;
        TMenuItem *Credits1;
        TLabel *Label1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TRadioButton *RadioButton3;
        TRadioButton *RadioButton4;
        TButton *Button1;
        TMemo *Memo1;
        TButton *Button2;
        TImage *Image1;
        TImage *Image2;
        TMemo *Spoleczna1;
        TMenuItem *Zpliku1;
        TMenuItem *Spoeczna1;
        TMemo *Osobow1;
        TMemo *Etyka1;
        TMenuItem *Osobowo1;
        TMenuItem *Etyka2;
        TMenuItem *N1;
        void __fastcall To1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Czcionka1Click(TObject *Sender);
        void __fastcall Pomoc1Click(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Zpliku1Click(TObject *Sender);
        void __fastcall Spoeczna1Click(TObject *Sender);
        void __fastcall Osobowo1Click(TObject *Sender);
        void __fastcall Etyka2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
