#include <iostream>

using namespace std;

class Device{
	bool m_workingDevice = false;
public:
	Device(){}
	Device(bool turnOn): m_workingDevice(turnOn){}
	bool GetWorkingDevice()const{ 
		  return m_workingDevice; 
	}
	void TurnOn(){
		if (m_workingDevice == true)
		{
			cout << "Device is already ON";
		}
		else
		{
			m_workingDevice = true;
		}
	}
	void TurnOff(){
		if (m_workingDevice == false)
		{
			cout << "Device is already OFF";
		}
		else
		{
			m_workingDevice = false;
		}
	}
	virtual void GetStatus() const  = 0;
	virtual ~Device(){};
};

class Printer : virtual public Device{
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

class Scaner : virtual public  Device{
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
	MFU() : Printer(), Scaner(){}
	MFU(bool autoOn) : Device(autoOn), Printer(), Scaner() {}
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
	MFU mfuB(true);
	cout << "======================MFU with constructor=====================" << endl;
	mfuB.GetStatus();
	mfuB.Print();
	mfuB.Scan();
	cout << "======================Printer(off)=====================" << endl;
	printer.GetStatus();
	printer.Print();
	cout << "======================Scaner(off)=====================" << endl;
	scaner.GetStatus();
	scaner.Scan();
	cout << "======================MFU(off)=====================" << endl;
	mfu.GetStatus();
	mfu.Print();
	mfu.Scan();
	cout << "======================Turning ON Devices=====================" << endl;
	printer.TurnOn();
	scaner.TurnOn();
	mfu.TurnOn();
	cout << "======================Devices work=====================" << endl;
	printer.GetStatus();
	printer.Print();
	scaner.GetStatus();
	scaner.Scan();
	mfu.GetStatus();
	mfu.Print();
	mfu.Scan();
	return 0;
}