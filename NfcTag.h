#ifndef NfcTag_h
#define NfcTag_h

#include <inttypes.h>
#include <Arduino.h>
#include <Ndef.h>

class NfcTag
{
	public:
		NfcTag();
		NfcTag(uint8_t* uid, uint8_t uidLength, String tech, NdefMessage& ndefMessage);
		NfcTag(uint8_t* uid, uint8_t uidLength, String tagType, const uint8_t * ndefData, const int ndefDataLength);  
		~NfcTag(void);
		uint8_t getUidLength();
		void getUid(uint8_t* uid, uint8_t uidLength);
		String getUidString();
		String getTagType();
		NdefMessage& getNdefMessage();
		void print();
	private:
		uint8_t* _uid;
		uint8_t _uidLength;
		String _tagType; // Mifare Classic, NDEF Forum Type {1,2,3,4}, Unknown
		NdefMessage* _ndefMessage;
};

#endif