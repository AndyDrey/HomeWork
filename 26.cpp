#include <iostream>

using namespace std;

class Device{
	bool workingDevice = false;
public:
	bool GetWorkingDevice()const{ 
		  return workingDevice; 
	}
	void TurnOn(){
		if (workingDevice == true)
		{
			cout << "Device is already ON";
		}
		else
		{
			workingDevice = true;
		}
	}
	void TurnOff(){
		if (workingDevice == false)
		{
			cout << "Device is already OFF";
		}
		else
		{
			workingDevice = false;
		}
	}
	virtual void GetStatus() const  = 0;
};

class Printer : public virtual Device{
public:
	void Print(){
		if (GetWorkingDevice())
		{
			cout << "Print" << endl;
		}
		else
		{
			cout << "Device is turn off" << endl;
		}
	}
	void GetStatus() const{
		if (GetWorkingDevice())
		{
			cout << "This is Printer. It is working now." << endl;
		}
		else
		{
			cout << "This is Printer. It is not working now." << endl;
		}
	}
};

class Scaner : public virtual Device{
public:
	void Scan(){
		if (GetWorkingDevice())
		{
			cout << "Scan" << endl;
		}
		else
		{
			cout << "Device is turn off" << endl;
		}
	}
	void GetStatus() const{
		if (GetWorkingDevice())
		{
			cout << "This is Scaner. It is working now." << endl;
		}
		else
		{
			cout << "This is Scaner. It is not working now." << endl;
		}
	}
};

class MFU : public Printer, public Scaner{
public:
	void GetStatus() const{
		if (GetWorkingDevice())
		{
			cout << "This is MFU. It is working now." << endl;
		}
		else
		{
			cout << "This is MFU. It is not working now." << endl;
		}
	}
};

int main(){

	Printer printer;
	Scaner scaner;
	MFU mfu;
	printer.GetStatus();
	printer.Print();
	scaner.GetStatus();
	scaner.Scan();
	mfu.GetStatus();
	mfu.Print();
	mfu.Scan();
	printer.TurnOn();
	scaner.TurnOn();
	mfu.TurnOn();
	printer.GetStatus();
	printer.Print();
	scaner.GetStatus();
	scaner.Scan();
	mfu.GetStatus();
	mfu.Print();
	mfu.Scan();
	return 0;
}