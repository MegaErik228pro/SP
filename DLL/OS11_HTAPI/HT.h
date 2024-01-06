#pragma once
#include <Windows.h>
#include <iomanip>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS

#ifdef OS11HTAPI_EXPORTS
#define OS11HTAPI __declspec(dllexport)
#else
#define OS11HTAPI __declspec(dllimport)
#endif

namespace HT    // HT API
{
	extern "C" OS11HTAPI struct HTHANDLE
	{
		HTHANDLE();
		HTHANDLE(int Capacity, int SecSnapshotInterval, int MaxKeyLength, int MaxPayloadLength, const wchar_t FileName[512]);
		int     Capacity;
		int     SecSnapshotInterval;
		int     MaxKeyLength;
		int     MaxPayloadLength;
		char    FileName[512];
		HANDLE  File;
		HANDLE  FileMapping;
		LPVOID  Addr;
		char    LastErrorMessage[512];
		time_t  Lastsnaptime;
		HANDLE  Mutex;
		int ElementCount;
		HANDLE SnapshotThread;
	};

	extern "C" OS11HTAPI struct Element
	{
		OS11HTAPI Element();
		OS11HTAPI Element(const void* key, int keylength);                                             // for Get
		OS11HTAPI Element(const void* key, int keylength, const void* payload, int  payloadlength);    // for Insert
		OS11HTAPI Element(Element* oldelement, const void* newpayload, int  newpayloadlength);         // for update
		void* key;
		int keylength;
		void* payload;
		int payloadlength;
	};
	extern "C" OS11HTAPI HTHANDLE * OpenExist
	(
		const wchar_t    FileName[512]
	);

	extern "C" OS11HTAPI HTHANDLE * Create              
	(
		int	  Capacity,					   
		int   SecSnapshotInterval,		   
		int   MaxKeyLength,                
		int   MaxPayloadLength,            
		const wchar_t FileName[512]        
	);

	extern "C" OS11HTAPI HTHANDLE * Open            
	(
		const wchar_t FileName[512] 

	);
	extern "C" OS11HTAPI HTHANDLE * OpenExist(const wchar_t FileName[512]);

	extern "C" OS11HTAPI BOOL Snap  
	(
		HTHANDLE * ht          
	);


	extern "C" OS11HTAPI BOOL Close  
	(
		HTHANDLE * ht
	); 


	extern "C" OS11HTAPI BOOL Insert
	(
		HTHANDLE * ht,
		Element * el 
	);


	extern "C" OS11HTAPI BOOL Delete
	(
		HTHANDLE * ht,
		Element * el 
	);

	extern "C" OS11HTAPI Element * Get
	(
		HTHANDLE * ht,
		Element * el
	);


	extern "C" OS11HTAPI BOOL Update
	(
		HTHANDLE * ht,
		Element * oldelement,          
		const void* newpayload,
		int             newpayloadlength
	);

	char* GetLastError
	(
		HTHANDLE* ht                   
	);

	const int DELETED = -1;

	void SetDeletedFlag(Element* el);

	void SetLastError(HTHANDLE* ht, const char* message);

	BOOL CheckElementParm(HTHANDLE* ht, Element* el);

	BOOL CheckElementParm(HTHANDLE* ht, int payloadLength);

	BOOL CheckEqualElementKeys(Element* el1, Element* el2);

	int HashFunction(const Element* el, int size, int p);

	int NextHash(int hash, int size, int p);

	Element* GetElementFromHT(HTHANDLE* ht, int hash);

	BOOL SetElementToHT(HTHANDLE* ht, Element* el, int n);

	DWORD WINAPI SnapshotRoutine(HTHANDLE* ht);

	BOOL IsDeleted(Element* el);

	void UpdateElement(HTHANDLE* ht, Element* el, const void* newpayload, int newpayloadlength);

	extern "C" OS11HTAPI void Print                              
	(
		const Element * el
	);
};