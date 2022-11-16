#include "main.h"


System::Void Safekeep::main::txtInput_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
    if (e->KeyCode.Equals(Keys::Enter)) {
		if (lblCaption->Text->Equals("  SEARCH:")) {
			if (txtInput->Text->Equals("")) {
				return;
			}
			int x = this->ClientSize.Height;
			if (this->ClientSize.Height > 200) {
				dgvMain->Visible = false;
				for (int i = 0; i < 30; i++) { // close animation
					this->ClientSize = System::Drawing::Size(this->ClientSize.Width, this->ClientSize.Height - 10);
					this->Refresh();
				}
			}
			dgvMain->Rows->Clear();
			std::vector<int> indices = MyRecord->includes(toStandardString(txtInput->Text));
			if (indices.size() != 0) {
				for (int i = 0; i < indices.size(); i++) {
					dgvMain->Rows->Add(gcnew String(MyRecord->accs.at(indices.at(i))->domain.c_str()), gcnew String(MyRecord->accs.at(indices.at(i))->username.c_str()));
				}
			}
			dgvMain->Visible = true;
			for (int i = 0; i < 30; i++) { // open animation
				this->ClientSize = System::Drawing::Size(this->ClientSize.Width, this->ClientSize.Height + 10);
				this->Refresh();
			}
		}
		else if (lblCaption->Text->Equals("USERNAME:")) {
			if (tries == 0) {
				MessageBox::Show("Maximum Tries Reached!", "LOCKED OUT");
				txtInput->Clear();
				return;
			}
			user = gcnew String(txtInput->Text);
			lblCaption->Text = "PASSWORD:";
			txtInput->PasswordChar = '*';
			txtInput->Clear();
		}
		else {
			System::String^ pass = gcnew String(txtInput->Text);
			if (authenticate(toStandardString(user), toStandardString(pass))) {
				//std::string domain = MyRecord->accs.at(0)->domain;
				txtInput->Clear();
				txtInput->PasswordChar = '\0';
				lblCaption->Text = "  SEARCH:";
				return;
			}
			txtInput->PasswordChar = '\0';
			tries--;
			lblCaption->Text = "USERNAME:";
			//delete user; //manual delete?
			//delete pass; //manual delete?
			if (tries == 0) {
				MessageBox::Show("Maximum Tries Reached!", "LOCKED OUT");
			}
			else {
				MessageBox::Show("Incorrect Credentials!\nTries Left: " + tries + "!", "INCORRECT CREDENTIALS!");
			}
			txtInput->Clear();
		}
    }
    return System::Void();
}

System::Void Safekeep::main::main_Load(System::Object^ sender, System::EventArgs^ e)
{
	//load from file?
    SQLConnector::setHost("localhost");
    SQLConnector::setPass("yellow09");
	SQLConnector::setDb("safekeep");
    SQLConnector::setPort(3306);
    SQLConnector::setUser("root");
    bool conSucceed = SQLConnector::startConnection();
    if (!conSucceed) {
        MessageBox::Show("Failed to connect to MySQL!");
		txtInput->Enabled = false;
    }
    return System::Void();
}

std::string toStandardString(System::String^ string)
{
	System::IntPtr pointer = System::Runtime::InteropServices::Marshal::Marshal::StringToHGlobalAnsi(string);
	char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
	std::string returnString(charPointer, string->Length);
	System::Runtime::InteropServices::Marshal::Marshal::FreeHGlobal(pointer);
	return returnString;
}

bool Safekeep::main::authenticate(std::string user, std::string pass) {
	MYSQL_RES* res;
	MYSQL_ROW row;
	std::string query = "SELECT * FROM main";
	const char* q = query.c_str();
	int qstate;
	qstate = mysql_query(SQLConnector::getSession(), q);
	if (qstate) {
		MessageBox::Show(gcnew String(mysql_error(SQLConnector::getSession())), "Server Error");
	}
	else {
		res = mysql_store_result(SQLConnector::getSession());
		while (row = mysql_fetch_row(res))
		{
			DataRowCustom DRow(atoi(row[0]), row[1], row[2], std::string(row[3]));
			if (((gcnew System::String(DRow.username))->Equals(gcnew String(user.c_str()))) && ((gcnew System::String(DRow.password))->Equals(gcnew String(pass.c_str())))) {
				MyRecord = new DataRowCustom(atoi(row[0]), row[1], row[2], std::string(row[3]));
				return true;
			}
		}
	}
	return false;
}