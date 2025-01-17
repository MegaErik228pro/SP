#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "../OS11_HTAPI/HT.h"
#pragma comment(lib, "../x64/Debug/OS11_HTAPI")
using namespace std;
using namespace HT;

int main(int argc, char* argv[]) //OS11_START os11_file.ht 
{
	setlocale(LC_ALL, "Russian");
	HMODULE libModule = NULL;
	try
	{
		HMODULE libModule = LoadLibrary(L"OS11_HTAPI");
		if (!libModule)
		{
			throw "���������� ��������� ����������";
		}
		if (argc != 2)
		{
			throw "������� ���������� ����������: 2";
		}
		const size_t cSize = strlen(argv[1]) + 1;
		wchar_t* wc = new wchar_t[cSize];
		mbstowcs(wc, argv[1], cSize);

		HTHANDLE* HT = Open(wc);
		if (HT == NULL)
		{
			throw "��������� �� �������";
		}

		cout << "HT-Storage Start !" << endl;
		wcout << "filename = " << wc << endl;
		cout << "snapshotinterval = " << HT->SecSnapshotInterval << endl;
		cout << "capacity = " << HT->Capacity << endl;
		cout << "maxkeylength = " << HT->MaxKeyLength << endl;
		cout << "maxdatalength = " << HT->MaxPayloadLength << endl;

		while (true) {
			Sleep((HT->SecSnapshotInterval) * 1000);
			Snap(HT);
			cout << "----SNAPSHOT in Thread----" << endl;
		}
		Snap(HT);
		Close(HT);
		FreeLibrary(libModule);
	}
	catch (const char* err)
	{
		cout << err << endl;
		FreeLibrary(libModule);
		exit(-1);
	}

	exit(0);
}