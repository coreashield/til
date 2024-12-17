#ifndef _KSNET_COMM_H_
#define _KSNET_COMM_H_

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////
// Util Function
//////////////////////////////////////////////////////////////////////////
__declspec(dllexport) VOID __stdcall Binary2HexFunction(PCHAR pBinStr, INT iBinSize, PCHAR pHexStr);
__declspec(dllexport) VOID __stdcall Hex2BinaryFunction(PCHAR pHexStr, PCHAR pBinStr, INT iBinSize);
// LOG 기록 유무 (0 : 기록 안함, 그 외 : 기록함)
__declspec(dllexport) VOID __stdcall Logging(INT enable);

__declspec(dllexport) LONG __stdcall EncodingBase64(PCHAR data, long len, PCHAR encodingData);
__declspec(dllexport) LONG __stdcall DecodingBase64(PCHAR data, long len, PCHAR decodingData);

__declspec(dllexport) LONG __stdcall GenerateOTC(PCHAR termId, PCHAR tokenNumber, PCHAR time, PCHAR returnData);

//////////////////////////////////////////////////////////////////////////
// 암호화 Reader: KSR-01
//////////////////////////////////////////////////////////////////////////

// 공통
__declspec(dllexport) LONG __stdcall ReaderSerialPort(INT portNum, INT baudrate);
__declspec(dllexport) LONG __stdcall ReaderPortInfoRecv(SHORT enableFlag);
__declspec(dllexport) LONG __stdcall SearchReaderSerialPort(INT baudrate);

// 비동기화
#define READER_ERROR          0
#define READER_INITIALIZATION 1
#define READER_STATUS         2
#define READER_INTEGRITY      3
#define READER_CARD_STATUS    4
#define READER_CARD_DATA      5
#define READER_2ND_GENERATION 6
#define READER_SHARE_KEY      7
#define READER_POINT_CARD     8
#define READER_LOCK_MESSAGE   9
#define READER_CARD_KIND	 10

#define READER_NUMBER_OF_MESSAGE 11

#define WM_READER WM_USER + 0

#define WM_READER_ERROR          WM_READER + READER_ERROR          // 1024
#define WM_READER_INITIALIZATION WM_READER + READER_INITIALIZATION // 1025
#define WM_READER_STATUS         WM_READER + READER_STATUS         // 1026
#define WM_READER_INTEGRITY      WM_READER + READER_INTEGRITY      // 1027
#define WM_READER_CARD_STATUS    WM_READER + READER_CARD_STATUS    // 1028
#define WM_READER_CARD_DATA      WM_READER + READER_CARD_DATA      // 1029
#define WM_READER_2ND_GENERATION WM_READER + READER_2ND_GENERATION // 1030
#define WM_READER_SHARE_KEY      WM_READER + READER_SHARE_KEY      // 1031
#define WM_READER_POINT_CARD     WM_READER + READER_POINT_CARD     // 1032
#define WM_READER_LOCK_MESSAGE   WM_READER + READER_LOCK_MESSAGE   // 1033
#define WM_READER_CARD_KIND		 WM_READER + READER_CARD_KIND	   // 1034

__declspec(dllexport) LONG __stdcall ReaderAsyncOpen					(HWND window);
__declspec(dllexport) LONG __stdcall ReaderAsyncClose					(VOID);
__declspec(dllexport) LONG __stdcall ReaderAsyncInitialization		(PCHAR year       , PCHAR type);
__declspec(dllexport) LONG __stdcall ReaderAsyncInitialization_DONGHWA(PCHAR year       , PCHAR type);
__declspec(dllexport) LONG __stdcall ReaderAsyncInitialization_ENE	(PCHAR year       , PCHAR type);
__declspec(dllexport) LONG __stdcall ReaderAsyncInitialization_TATSNO	(PCHAR year       , PCHAR type);
__declspec(dllexport) LONG __stdcall ReaderAsyncStatus				(PCHAR modelNumber, PCHAR time  , PCHAR baudrate    , PCHAR reserve);
__declspec(dllexport) LONG __stdcall ReaderAsyncIntegrity				(PCHAR modelNumber, PCHAR type);
__declspec(dllexport) LONG __stdcall ReaderAsyncCardData				(PCHAR type       , PCHAR time  , PCHAR amount      , PCHAR timeout);
__declspec(dllexport) LONG __stdcall ReaderAsync2ndGeneration			(PCHAR time       , PCHAR amount, PCHAR responseCode, PCHAR count  , PCHAR emvData, INT emvLength);
__declspec(dllexport) LONG __stdcall ReaderAsyncShareKey				(PCHAR modelNumber, PCHAR time  , PCHAR reserve);
__declspec(dllexport) LONG __stdcall ReaderAsyncPointCard				(PCHAR timeout	  , PCHAR key);
__declspec(dllexport) LONG __stdcall ReaderAsyncUnLock();
__declspec(dllexport) LONG __stdcall ReaderAsyncLockStatus();
__declspec(dllexport) LONG __stdcall ReaderAsyncMotorInput();
__declspec(dllexport) LONG __stdcall ReaderAsyncInitialization_ODT	(PCHAR year		  , PCHAR type	, PCHAR model);
__declspec(dllexport) LONG __stdcall ReaderAsyncKeyInCardData			(PCHAR cardData	  , PCHAR time	, PCHAR amount, PCHAR timeout);
__declspec(dllexport) LONG __stdcall ReaderAsyncCardStatus();
__declspec(dllexport) LONG __stdcall ReaderAsyncCheckCardKind();
__declspec(dllexport) LONG __stdcall ReaderAsyncCashIC				(PCHAR time, PCHAR amount, PCHAR timeout, PCHAR password);
__declspec(dllexport) LONG __stdcall ReaderAsyncMSCardDataLockIn		(PCHAR time, PCHAR amount, PCHAR timeout);
__declspec(dllexport) LONG __stdcall ReaderAsyncSamsungPay			(PCHAR time, PCHAR amount, PCHAR timeout, PCHAR message1, PCHAR message2, PCHAR message3, PCHAR message4, PCHAR viewTime);
__declspec(dllexport) LONG __stdcall ReaderAsyncCashICRand			(PCHAR time, PCHAR amount, PCHAR timeout, PCHAR password, PCHAR randNum);

// 동기화
#define READER_READ_TIMEOUT 3000

__declspec(dllexport) LONG __stdcall ReaderSerialRead(UINT timeout, PUCHAR commandID, PUCHAR readData);

__declspec(dllexport) LONG __stdcall ReaderInitialization			(PCHAR readData, PCHAR year       , PCHAR type);
__declspec(dllexport) LONG __stdcall ReaderInitialization_DONGHWA	(PCHAR readData, PCHAR year       , PCHAR type);
__declspec(dllexport) LONG __stdcall ReaderInitialization_ENE		(PCHAR readData, PCHAR year       , PCHAR type);
__declspec(dllexport) LONG __stdcall ReaderInitialization_TATSNO	(PCHAR readData, PCHAR year       , PCHAR type);
__declspec(dllexport) LONG __stdcall ReaderStatus					(PCHAR readData, PCHAR modelNumber, PCHAR time  , PCHAR baudrate    , PCHAR reserve);
__declspec(dllexport) LONG __stdcall ReaderIntegrity				(PCHAR readData, PCHAR modelNumber, PCHAR type);
__declspec(dllexport) LONG __stdcall ReaderCardData				(PCHAR readData, PCHAR type       , PCHAR time  , PCHAR amount      , PCHAR timeout);
__declspec(dllexport) LONG __stdcall Reader2ndGeneration			(PCHAR readData, PCHAR time       , PCHAR amount, PCHAR responseCode, PCHAR count  , PCHAR emvData, INT emvLength);
__declspec(dllexport) LONG __stdcall ReaderShareKey				(PCHAR readData, PCHAR modelNumber, PCHAR time  , PCHAR reserve);
__declspec(dllexport) LONG __stdcall ReaderPointCard				(PCHAR readData, PCHAR timeout	  , PCHAR key);
__declspec(dllexport) LONG __stdcall ReaderUnLock					(PCHAR readData);
__declspec(dllexport) LONG __stdcall ReaderLockStatus				(PCHAR readData);
__declspec(dllexport) LONG __stdcall ReaderMotorInput				(PCHAR readData);
__declspec(dllexport) LONG __stdcall ReaderInitialization_ODT		(PCHAR readData, PCHAR year		  , PCHAR type	, PCHAR model);
__declspec(dllexport) LONG __stdcall ReaderKeyInCardData			(PCHAR readData, PCHAR cardData	  , PCHAR time	, PCHAR amount, PCHAR timeout);
__declspec(dllexport) LONG __stdcall ReaderCardStatus				(PCHAR readData);
__declspec(dllexport) LONG __stdcall ReaderCheckCardKind			(PCHAR readData);
__declspec(dllexport) LONG __stdcall ReaderCashIC					(PCHAR readData, PCHAR time, PCHAR amount, PCHAR timeout, PCHAR password);
__declspec(dllexport) LONG __stdcall ReaderMSCardDataLockIn		(PCHAR readData, PCHAR time, PCHAR amount, PCHAR timeout);
__declspec(dllexport) LONG __stdcall ReaderSamsungPay				(PCHAR readData, PCHAR time, PCHAR amount, PCHAR timeout, PCHAR message1, PCHAR message2, PCHAR message3, PCHAR message4, PCHAR viewTime);
__declspec(dllexport) LONG __stdcall ReaderCashICRand				(PCHAR readData, PCHAR time, PCHAR amount, PCHAR timeout, PCHAR password, PCHAR randNum);

// 리더기 Seed 암호화
__declspec(dllexport) LONG __stdcall GetSeedKey		();
__declspec(dllexport) LONG __stdcall SEEDDecryptData	(PCHAR encData, PCHAR key, PCHAR responseData);

// 리더기 RSA+Hight 복호화
__declspec(dllexport) LONG __stdcall DecryptPwdCardNo	(PCHAR data, PCHAR key, PCHAR outData);

//////////////////////////////////////////////////////////////////////////
// Sign/Pin Pad
//////////////////////////////////////////////////////////////////////////

// 공통
__declspec(dllexport) LONG __stdcall PadSerialPort(INT portNum, INT baudrate);

// 비동기화
#define PAD_ERROR            0
#define PAD_SUCCESS          1
#define PAD_REALTIME_XY      2
#define PAD_SIGN_DATA        3
#define PAD_SIGN_CANCEL      4
#define PAD_PIN              5
#define PAD_ENCRYPTED_PIN    6
#define PAD_MESSAGE          7
//#define PAD_REALTIME_PIN     8
//#define PAD_MSR_DATA         9
//#define PAD_RF_DATA          10
//#define PAD_IMAGE            11
//#define PAD_PRODUCT_NUMBER   12
//#define PAD_TOUCH_COORDINATE 13
#define PAD_SHARE_KEY        14
#define PAD_LINE_TOUCH       15

#define PAD_NUMBER_OF_MESSAGE 16

#define WM_PAD WM_USER + 100

#define WM_PAD_ERROR            WM_PAD + PAD_ERROR            // 1124
#define WM_PAD_SUCCESS          WM_PAD + PAD_SUCCESS          // 1125
#define WM_PAD_REALTIME_XY      WM_PAD + PAD_REALTIME_XY      // 1126
#define WM_PAD_SIGN_DATA        WM_PAD + PAD_SIGN_DATA        // 1127
#define WM_PAD_SIGN_CANCEL      WM_PAD + PAD_SIGN_CANCEL      // 1128
#define WM_PAD_PIN              WM_PAD + PAD_PIN              // 1129
#define WM_PAD_ENCRYPTED_PIN    WM_PAD + PAD_ENCRYPTED_PIN    // 1130
#define WM_PAD_MESSAGE          WM_PAD + PAD_MESSAGE          // 1131
//#define WM_PAD_REALTIME_PIN     WM_PAD + PAD_REALTIME_PIN     // 1132
//#define WM_PAD_MSR_DATA         WM_PAD + PAD_MSR_DATA         // 1133
//#define WM_PAD_RF_DATA          WM_PAD + PAD_RF_DATA          // 1134
//#define WM_PAD_IMAGE            WM_PAD + PAD_IMAGE            // 1135
//#define WM_PAD_PRODUCT_NUMBER   WM_PAD + PAD_PRODUCT_NUMBER   // 1136
//#define WM_PAD_TOUCH_COORDINATE WM_PAD + PAD_TOUCH_COORDINATE // 1137
#define WM_PAD_SHARE_KEY        WM_PAD + PAD_SHARE_KEY        // 1138
#define WM_PAD_LINE_TOUCH       WM_PAD + PAD_LINE_TOUCH       // 1139
#define WM_PAD_RAIL_PLUS        WM_PAD + PAD_RAIL_PLUS        // 1140

// LOG
__declspec(dllexport) LONG __stdcall PadLogPath    (PCHAR path);
__declspec(dllexport) LONG __stdcall PadLogDeletion(INT   days);

__declspec(dllexport) LONG __stdcall PadAsyncOpen          (HWND window);
__declspec(dllexport) LONG __stdcall PadAsyncClose         (VOID);
__declspec(dllexport) LONG __stdcall PadAsyncInitialization(VOID);
__declspec(dllexport) LONG __stdcall PadAsyncSign          (PCHAR hash               , PCHAR substitution             , PCHAR workingKey     , PCHAR message1  , PCHAR message2 , PCHAR message3 , PCHAR message4);
__declspec(dllexport) LONG __stdcall PadAsyncSignData      (VOID);
__declspec(dllexport) LONG __stdcall PadAsyncSignCancel    (VOID);
__declspec(dllexport) LONG __stdcall PadAsyncPIN           (PCHAR type               , PCHAR maxLength                , PCHAR message1       , PCHAR message2  , PCHAR message3 , PCHAR message4 , PCHAR time    );
__declspec(dllexport) LONG __stdcall PadAsyncEncryptedPIN  (PCHAR cardNumber         , PCHAR workingKeyIndex          , PCHAR workingKey     , PCHAR minLength , PCHAR maxLength, PCHAR message1 , PCHAR message2, PCHAR message3, PCHAR message4, PCHAR time    );
__declspec(dllexport) LONG __stdcall PadAsyncMessage       (PCHAR message1           , PCHAR message2                 , PCHAR message3       , PCHAR message4  , PCHAR time     );
__declspec(dllexport) LONG __stdcall PadAsyncShareKey      (PCHAR encryptedKey       , INT   encryptedKeyLength       );
__declspec(dllexport) LONG __stdcall PadAsyncEncryptedPIN2 (PCHAR encryptedCardNumber, INT   encryptedCardNumberLength, PCHAR workingKeyIndex, PCHAR workingKey, PCHAR minLength, PCHAR maxLength, PCHAR message1, PCHAR message2, PCHAR message3, PCHAR message4, PCHAR time);
__declspec(dllexport) LONG __stdcall PadAsyncPlaySound	 (INT	playNumber);
__declspec(dllexport) LONG __stdcall PadAsyncLineTouch	 (PCHAR line			   , PCHAR message1					, PCHAR message2	   , PCHAR message3	 , PCHAR message4 , PCHAR message5);
__declspec(dllexport) LONG __stdcall PadAsyncRailPlusCard	 (PCHAR commandID		   , PCHAR data						, LONG dataLength);

// 동기화
#define PAD_READ_TIMEOUT 3000

__declspec(dllexport) LONG __stdcall PadInitialization(VOID);
__declspec(dllexport) LONG __stdcall PadSignData      (PCHAR readData, INT timeout, PCHAR hash, PCHAR substitution, PCHAR workingKey, PCHAR message1, PCHAR message2, PCHAR message3, PCHAR message4);

//////////////////////////////////////////////////////////////////////////
// CAT: KS4060, KS9050
//////////////////////////////////////////////////////////////////////////

// LOG
__declspec(dllexport) LONG __stdcall CATLogPath    (PCHAR path);
__declspec(dllexport) LONG __stdcall CATLogDeletion(INT   days);

// 비동기화/동기화 공통
__declspec(dllexport) LONG __stdcall CATSerialPort(INT portNum, INT baudrate);

// 비동기화
#define CAT_ERROR 0
#define CAT_READ  1

#define CAT_NUMBER_OF_MESSAGE 2

#define WM_CAT WM_USER + 200

#define WM_CAT_ERROR WM_CAT + CAT_ERROR // 1224
#define WM_CAT_READ  WM_CAT + CAT_READ  // 1225

__declspec(dllexport) LONG __stdcall CATAsyncOpen (HWND window    );
__declspec(dllexport) LONG __stdcall CATAsyncClose(VOID);
__declspec(dllexport) LONG __stdcall CATAsyncWrite(PCHAR writeData, INT writeLength);
__declspec(dllexport) LONG __stdcall CATAsyncWriteLRC(PCHAR writeData, INT writeLength);

// Print 명령어
__declspec(dllexport) LONG __stdcall CATAsyncPrintImage(PCHAR bmpPath, INT xCnt, INT expandFlag);
__declspec(dllexport) LONG __stdcall CATAsyncPrintLineFeed(INT feedCnt);
__declspec(dllexport) LONG __stdcall CATAsyncPrintPaperCut();
__declspec(dllexport) LONG __stdcall CATAsyncPrintBarCode(PCHAR printNumber);
__declspec(dllexport) LONG __stdcall CATAsyncPrintString(PCHAR printData, SHORT nFlag);
__declspec(dllexport) LONG __stdcall CATAsyncPrintImageLineFeed(PCHAR bmpPath, INT xCnt, INT expandFlag, INT lineFeed);

// 이미지 저장
__declspec(dllexport) LONG __stdcall CATAsyncSaveToBitmap(PCHAR bmpPath);

// 동기화
#define CAT_READ_TIMEOUT 3000

// 동기화 return 코드
#define CAT_READ_SUCCESS "00"
#define CAT_READ_SERVER_REJECT "NE"
#define CAT_READ_INIT "XA"
#define CAT_READ_ACK "XB"
#define CAT_READ_NAK "XC"
#define CAT_READ_REMOVE_IC "XD"
#define CAT_READ_IC_BLOCK "XE"
#define CAT_READ_1ST_REJECT "XF"
//#define CAT_READ_FALLBACK "XF"
#define CAT_READ_COMM_ERROR "XG"
#define CAT_READ_COMM_CANCLE_S "XH"
#define CAT_READ_COMM_CANCLE_F "XI"
#define CAT_READ_IC_ERROR_S "XJ"
#define CAT_READ_IC_ERROR_F "XK"
#define CAT_READ_2ND_ERROR_S "XL"
#define CAT_READ_2ND_ERROR_F "XM"

#define CAT_ERROR_CODE_LEN	2

__declspec(dllexport) LONG __stdcall CATWriteRead(PCHAR readData, PCHAR writeData, INT writeLength);
__declspec(dllexport) LONG __stdcall CATWriteReadSync(PCHAR errCode, PCHAR readData, PCHAR writeData, INT writeLength, PCHAR timeout, INT flagLRC);

//////////////////////////////////////////////////////////////////////////
// KSCAT
//////////////////////////////////////////////////////////////////////////
__declspec(dllexport) LONG __stdcall KSCATApproval(PCHAR responseTelegram, PCHAR ip, INT port, PCHAR requestTelegram, INT requestTelegramLength, INT option);
__declspec(dllexport) LONG __stdcall KSCATApprovalMultiVan(PCHAR responseTelegram, PCHAR inputVan, PCHAR KSCatIp, INT KSCatPort, PCHAR requestTelegram, INT requestTelegramLength, PCHAR apprVan);
__declspec(dllexport) LONG __stdcall SettingVanInfo(PCHAR van, PCHAR ip, PCHAR port, PCHAR option, PCHAR rate);
__declspec(dllexport) LONG __stdcall InitErrVanInfo();
__declspec(dllexport) LONG __stdcall SetCardCheckCashIC(INT flag);
__declspec(dllexport) LONG __stdcall SetAutoCheckCup(INT flag);

__declspec(dllexport) LONG __stdcall KSCATApprovalMultiVanWithPath(PCHAR responseTelegram, PCHAR inputVan, PCHAR KSCatIp, INT KSCatPort, PCHAR requestTelegram, INT requestTelegramLength, PCHAR apprVan, PCHAR path);
__declspec(dllexport) LONG __stdcall SettingVanInfoWithPath(PCHAR van, PCHAR ip, PCHAR port, PCHAR option, PCHAR rate, PCHAR path);                                                                                   
__declspec(dllexport) LONG __stdcall InitErrVanInfoWithPath(PCHAR path);                                                                                                                                              
__declspec(dllexport) LONG __stdcall SetCardCheckCashICWithPath(INT flag, PCHAR path);                                                                                                                                
__declspec(dllexport) LONG __stdcall SetAutoCheckCupWithPath(INT flag, PCHAR path);                                                                                                                                   

//////////////////////////////////////////////////////////////////////////
// 승인
//////////////////////////////////////////////////////////////////////////

#define APPROVAL_ERROR_PARAMETER     -1
#define APPROVAL_ERROR_ENCRYPT       -2
#define APPROVAL_ERROR_CONNECTION    -3
#define APPROVAL_ERROR_SENDING       -4
#define APPROVAL_ERROR_RECEPTION     -5
#define APPROVAL_ERROR_DECRYPT       -6
#define APPROVAL_ERROR_ACK_SENDING   -7
#define APPROVAL_ERROR_EOT_RECEPTION -8
#define APPROVAL_ERROR_NC_TARGET     -9

#define APPROVAL_TELEGRAM_UNKWOUN 0
#define APPROVAL_TELEGRAM_200     1
#define APPROVAL_TELEGRAM_204     2
#define APPROVAL_TELEGRAM_204A    3
#define APPROVAL_TELEGRAM_240     4
#define APPROVAL_TELEGRAM_ENC     5
#define APPROVAL_TELEGRAM_ENC_CAT 6

#define APPROVAL_OPTION_NONE       0x00000000 // 0000 0000  0000 0000  0000 0000  0000 0000 :  0 - 암호화 + ACK & EOT + 망취소
#define APPROVAL_OPTION_NO_ENCRYPT 0x00000001 // 0000 0000  0000 0000  0000 0000  0000 0001 :  1 - 암호화하지 않음
#define APPROVAL_OPTION_NO_ACKEOT  0x00000002 // 0000 0000  0000 0000  0000 0000  0000 0010 :  2 - ACK & EOT하지 않음
#define APPROVAL_OPTION_NO_NC      0x00000004 // 0000 0000  0000 0000  0000 0000  0000 0100 :  4 - 망취소하지 않음
#define APPROVAL_OPTION_CAT        0x00000008 // 0000 0000  0000 0000  0000 0000  0000 1000 :  8 - CAT 프로토콜 사용
#define APPROVAL_OPTION_ADD_CRC    0x00000010 // 0000 0000  0000 0000  0000 0000  0001 0000 : 16 - 전문 끝에 CRC값 추가
#define APPROVAL_OPTION_TEST_NC    0x20000000 // 0010 0000  0000 0000  0000 0000  0000 0000 : 536870912 - 망취소 테스트용
#define APPROVAL_OPTION_DEBUG      0x40000000 // 0100 0000  0000 0000  0000 0000  0000 0000 : 1073741824 - debug용


__declspec(dllexport) LONG __stdcall Request( PCHAR responseTelegram,
											                        PCHAR ip,
											                        INT   port,
											                        INT   telegramType,
											                        PCHAR requestTelegram,
											                        INT   requestTelegramLen,
											                        INT   timeout,
											                        INT   option );

__declspec(dllexport) LONG __stdcall RequestEnc( PCHAR responseTelegram,
																							   PCHAR ip,
																							   INT port,
																							   INT telegramType,
																							   PCHAR requestTelegram,
																							   INT requestTelegramLen,
																							   INT timeout,
																							   INT option,
																							   PCHAR requestEncData,
																							   PCHAR responseEncData );
																							   
__declspec(dllexport) LONG __stdcall RequestEncWJPOS( PCHAR responseTelegram,
																									    PCHAR ip,
																									    INT port,
																									    INT telegramType,
																									    PCHAR requestTelegram,
																									    INT requestTelegramLen,
																									    INT timeout,
																									    INT option,
																									    PCHAR requestEncData,
																									    PCHAR responseEncData );
																									    
__declspec(dllexport) LONG __stdcall RequestIKEA( PCHAR responseTelegram, 
																								  PCHAR ip, 
																									INT port, 
																									INT telegramType, 
																									PCHAR requestTelegram, 
																									INT requestTelegramLen, 
																									INT timeout, 
																									INT option );

#ifdef __cplusplus
}
#endif



#endif // _KSNET_COMM_H_
