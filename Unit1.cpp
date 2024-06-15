//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
bool isNumberEntered=false;
int guessNumber;
int attemptsCounter=0;
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)

{   {
	TitleLabel->Text="Please enter the number:";
	CounterLabel->Text="0";
	HelperLabel->Text="";
}   }
//---------------------------------------------------------------------------
void __fastcall TForm1::ConfirmButtonClick(TObject *Sender)
{
	  if(!isNumberEntered){
		  guessNumber=Edit1->Text.ToInt();
		  isNumberEntered=true;
          TitleLabel->Text="Now you can guess the number:";
		   Edit1->Text="";
	  }
	  else{
		  int secondUserNumber=Edit1->Text.ToInt();

		  if(secondUserNumber == guessNumber){
			   HelperLabel->Text="You WON!! Congratulations yay!! ";
			   ConfirmButton->Enabled=false;
			   return ;
		  }
		  else if(secondUserNumber>guessNumber){
			 HelperLabel->Text="Number is too big!!";
			 attemptsCounter++;
             CounterLabel->Text= attemptsCounter;
		  }
		  else{
			  HelperLabel->Text="Number too low!!";
			  attemptsCounter++;
			  CounterLabel->Text= attemptsCounter;
		  }
		  if(attemptsCounter>6){
			  HelperLabel->Text="Too many attempts!!";
		  }
		  else{
              attemptsCounter++;
          }
	  }
}
//---------------------------------------------------------------------------

