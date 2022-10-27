/*
* Made by Akkshai Baskar
* Safekeep - a place to keep all your passwords safe and sound.
* Version 1.0.0.0
*/


#include "main.h"

//PROGRAM STARTS HERE
int main() {
	printf("Loading...");
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	Safekeep::main gui;
	System::Windows::Forms::Application::Run(%gui);
}