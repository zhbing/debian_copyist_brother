/*

 This file is part of the Brother MFC/DCP backend for SANE.

 This program is free software; you can redistribute it and/or modify it
 under the terms of the GNU General Public License as published by the Free
 Software Foundation; either version 2 of the License, or (at your option)
 any later version.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 more details.

 You should have received a copy of the GNU General Public License along with
 this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 Place, Suite 330, Boston, MA  02111-1307  USA

*/



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//
//	Source filename: brcolor.h
//
//		Copyright(c) 2004-2006 Brother Industries, Ltd.  
//               All Rights Reserved.
//
//
//	Abstract:
//		
//
//
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


//#include "build.h"

// TWAIN カラーマッチング処預� ヘッダファイヂ� 
// Create 97.1.8  Brother Systems T.YUGUCHI

#ifndef _H_BRCOLOR_
#define _H_BRCOLOR_

#define HWND void *
typedef  int   long32;

//---------------------------------------------------------------------- 定数定蟻�
// TWAIN実行モード(カラーマッチング初期化処理実行時に指定）
#define	TWAIN_SCAN_MODE				0	//TWAIN実行  通常スキャナーモーヂ�
#define TWAIN_COPY_MODE				1	//TWAIN実行  ＰＣ ＣＯＰＢ� モード

// マッチング対象デーヂ� ＲＧＢデータ並び
#define CMATCH_DATALINE_RGB			0	// Red , Green , Blue
#define CMATCH_DATALINE_BGR			1	// Blue , Green, Red

// カラーマッチング種並�(カラーマッチング処理実行時に指定）
#define CMATCH_KIND_GAMMA			0	//γカーブ補正
#define CMATCH_KIND_LUT				1	//LUTによるカラーマッチング
#define CMATCH_KIND_MONITOR			2	//モニターキャリブレーショヂ�

// マッチング用テーブル領域サイズ
#define	GAMMA_TABLE_NAME			"BrGamma.dat"	
													//γカーブ定義テーブル名
#define GAMMA_TABLE_ID				"BSGT"			//γカーブ定義テーブヂ�ID
#define TABLE_GAMMA_SIZE			768 			//γカーブ定義テーブヂ�
													//γデータサイヂ� 256*3(byte)	

#define MONITOR_GAMMA_TABLE_NAME	"BrMonCal.dat"
													//モニターキャリブレーションγ値テーブル名
#define MONITOR_GAMMA_ID			"BRMC"			//モニターキャリブレーションγ値テーブヂ�ID

#define LUT_FILE_NAME				"BrLutCm.dat"
													//LUTデータ定義ファイル迷�
#define LUT_FILE_ID					"BLCM"			//LUTデータ定義ファイル

#define LUT_KIND_SCAN				"SLUT"			//通常スキャナー処理用ＬＵＢ�
#define LUT_KIND_COPY				"CLUT"			//PC COPY用ＬＵＢ�

#ifdef	TABLE_00
	#define	LUT_RGB						0				//LUT データ種別コード RGB
//  not used
//	#define LUT_CMY						1				//LUT データ種別コード CMY
//	#define	LUT_LAB						2				//LUT データ種別コード LAB
#endif	//TABLE_00
#ifdef	TABLE_VER
	#define	LUT_00						0				//grid only
	#define LUT_01						1				//grid , gamma , gray
#endif	//TABLE_VER

#define LUT_DEFINE_FILE				"BrLutDef.Dat"
													//LUT選択用定義ファイル
#define LUT_DEFINE_FILE_ID			"BRLD"			//LUT選択用定義ファイルID

//メディアタイプ定義
//現在使用していない使い方
#define MEDIA_PLAIN					0				//PLAIN PAPER
#define	MEDIA_COTED					1				//COTED PAPER 320
#define	MEDIA_COTED720				2				//COTED PAPER 720
#define	MEDIA_GROSSY				3				//GROSSY
#define	MEDIA_OHP					4				//OHP
#define MEDIA_OHPMIRROR				5				//OHP MIRROR
#define	MEDIA_PHOTO					6				//PHOTO
//こちらが現在の使い並�
#define	MEDIA_STD					0				//standard paper
//#define	MEDIA_PHOTO					6				//photo paper
#define	MEDIA_FB_STD				MEDIA_STD		//FB	standard paper
#define	MEDIA_FB_PHOTO				MEDIA_PHOTO		//FB	photo paper
#define	MEDIA_ADF_STD				7				//ADF	standard paper
#define	MEDIA_ADF_PHOTO				8				//ADF	photo paper

//ドキュメントモード定義
#define	DOCMODE_AUTO				0				//Document Mode AUTO
#define	DOCMODE_GRAPH				1				//Document Mode GRAPH
#define	DOCMODE_PHOTO				2				//Document Mode PHOTO
#define	DOCMODE_CUSTOM				3				//Document Mode Custom

//カラーマットングモード			
#define	COLOR_VIVID					0				//VIVID
#define	COLOR_MATCHSCREEN			1				//MATCH_SCREEN

//ICM(Win95)制御用
//#define ICM_OFF					0				//ICM Off
#define ICM_THROUGH					1				//ICM On
#define	ICM_MANUAL					2				//ICM Manual				

//プリンタードライバー名
#define MFC_PRINTER_NAME			"Brother MFC-7000 Series"
#define MC_PRINTER_NAME				"Brother MC3000"

//INIファイル名
#define MFC_INIFILE_NAME			"Brmfc97c.ini"
#define MC_INIFILE_NAME				"Brmc97c.ini"

//機種ＩＢ�
#define	MFC7000						0				//MFC-7000シリーヂ�
#define MC3000						1				//MC3000 (3in1)

//標準ＬＵＴ ID
#define DEFAULT_LUT					"DLUT"
#define DEFAULT_PHOTO_LUT			"PHTO"
#define ADF_STD_LUT					"DADF"
#define ADF_PHOTO_LUT				"PADF"
//--------------------------------------------------------------------- 構造体定義
#pragma pack(1)

typedef struct{					//カラーマッチング初期化モード指定構造体：ファイル名付き
	int		nRgbLine;			//RGBデータ並び	  (BGR  or RGB)
	int		nPaperType;			//原稿 紙種別
	int		nMachineId;			//機種ID
	LPSTR	lpLutName;			//Lut Name
}CMATCH_INIT;	

typedef struct{										//モニターキャリブレーションγ値構造体
	char	FileID[4];			//'BRMC'
	short	BlackPoint[4];		//index[0,1,2,3]=[r,g,b,reserved]
	float	Gamma[4];			//index[0,1,2,3]=[r,g,b,reserved]
	short	Flag;				//default Flag
}BRMONCALDAT; 

typedef struct{										//LUTデータ構造体
	short	sLutVer;			//lut version
}BRLUT_HEAD_DATA_VER;

typedef struct{										//LUTデータ構造体
//	short	sLutDataKind;		//LUTデータ識別コード

	float	s3D_Xmin;			//3D DATA X最小値
	float	s3D_Xmax;			//3D DATA X最大値
	float	s3D_Ymin;			//3D DATA Y最小値
	float	s3D_Ymax;			//3D DATA Y最大値
	float	s3D_Zmin;			//3D DATA Z最小値
	float	s3D_Zmax;			//3D DATA Z最大値

	short	s3D_Xsplit;			//3D DATA X方向分割数
	short	s3D_Ysplit;			//3D DATA Y方向分割数
	short	s3D_Zsplit;			//3D DATA Z方向分割数

//	float	f3D_Xspase;			//3D小立方体空間 Ｘ方向間隔
//	float	f3D_Yspase;			//3D小立方体空間 Ｙ方向間隔
//	float	f3D_Zspase;			//3D小立方体空間 Ｚ方向間隔

}BRLUT_HEAD_DATA_00;

#ifdef	TABLE_01
typedef struct{										//LUTデータ構造体
//	short	sLutDataKind;		//LUTデータ識別コード

	short	sLutnum;			//LUT data 紳�
	short	sGamnum;			//Gamma data 紳�
	short	sGraynum;			//Gray data 紳�

	short	s3D_Xmin;			//3D DATA X最小値
	short	s3D_Xmax;			//3D DATA X最大値
	short	s3D_Ymin;			//3D DATA Y最小値
	short	s3D_Ymax;			//3D DATA Y最大値
	short	s3D_Zmin;			//3D DATA Z最小値
	short	s3D_Zmax;			//3D DATA Z最大値

	short	s3D_Xgrid;			//3D DATA X方向grid紳�
	short	s3D_Ygrid;			//3D DATA Y方向grid紳�
	short	s3D_Zgrid;			//3D DATA Z方向grid紳�
	short	s3D_Xspace;			//3D DATA X方向grid size
	short	s3D_Yspace;			//3D DATA Y方向grid size
	short	s3D_Zspace;			//3D DATA Z方向grid size
}BRLUT_HEAD_DATA_01;
#endif	//TABLE_01

typedef struct{										//LUTデータ定義ファイルテーブルヘッダ情報構造体
	char	TableID[4];			//テーブル識別コード
	long32	lTableOffset;		//LUTデータ開始オフセット値
}BRLUT_FILE_HEAD;

typedef struct{										//LUTカラーマッチング対象データ情報
#ifdef	TABLE_00
	BYTE	*pbIndex_X;			//入力データ Ｂ�
	BYTE	*pbIndex_Y;			//入力データ Ｂ�
	BYTE	*pbIndex_Z;			//入力データ Ｂ�

	short	sColorType_X;		//入力データ Ｘカラータイヂ�  (Red = 0, Green = 1, Blue = 2) 
	short	sColorType_Y;		//入力データ Ｙカラータイヂ�
	short	sColorType_Z;		//入力データ Ｚカラータイヂ�
#endif	//TABLE_00
#ifdef	TABLE_01
	short	sData_X;			//入力データ Ｂ�
	short	sData_Y;			//入力データ Ｂ�
	short	sData_Z;			//入力データ Ｂ�
#endif	//TABLE_01

	short	sIndex_X;			//LUT参照インデックス Ｂ�
	short	sIndex_Y;			//LUT参照インデックス Ｂ�
	short	sIndex_Z;			//LUT参照インデックス Ｂ�
}BRLUT_INPUT_DATA;

typedef struct{										//LUT代表点(測色データ）格納構造体
	float	fExpPoint_X[8];		//代表点 Ｂ� Ｘ０〜Ｘ７
	float	fExpPoint_Y[8];		//代表点 Ｂ� Ｙ０〜Ｙ７
	float	fExpPoint_Z[8];		//代表点 Ｂ� Ｚ０〜Ｚ７
}BRLUT_EXP_POINT;

typedef struct{										//LUT代表点（論理データ）格納構造体
	float	fLogicPoint_X[8];
	float	fLogicPoint_Y[8];
	float	fLogicPoint_Z[8];
}BRLUT_LOGIC_POINT;

typedef struct{										//LUT代表点データ格納構造体
	float	fLutXData;			//代表点 Ｘ方向データ
	float	fLutYData;			//代表点 Ｙ方向データ
	float	fLutZData;			//代表点 Ｚ方向データ
}BRLUT_DATA;

#ifdef	GAMMA_ADJ
//typedef struct{										//LUTデータAdjust格納構造体
//	float	fGammaXData;			//Ｘ方向データ
//	float	fGammaYData;			//Ｙ方向データ
//	float	fGammaZData;			//Ｚ方向データ
//}BRLUT_GAMMA;
#endif	//GAMMA_ADJ

#ifdef	GRAY_ADJ
//typedef struct{										//LUTデータAdjust格納構造体
//	float	fAdjXData;			//Ｘ方向データ
//	float	fAdjYData;			//Ｙ方向データ
//	float	fAdjZData;			//Ｚ方向データ
//}BRLUT_GRAY;
#endif	//GRAY_ADJ

typedef struct{										//LUT選択用データ構造体
	short	nScanMode;			//スキャナーモードﾞ‖�SCAN or COPY)
	short	nInputMedia;		//入力メディア（紙タイプ）
	short	nOutputMedia;		//出力メディア
	short	nDocMode;			//ドキュメントモード
	short	nColorMatch;		//VIVID or MATCHSCREEN
	short	nIcmControl;		//ICM モード
}BRLUT_SELECT;	

typedef struct{										//Hash Table Data用構造詑�
	BYTE	yColorX;
	BYTE	yColorY;
	BYTE	yColorZ;
}COLOR_HASH_DAT;

typedef struct{										//Hash Table キー用構造体
	long32			nHashKey;	//Hash Key
	COLOR_HASH_DAT	*pColorDat;	//Hash Data Pointer
}COLOR_HASH_KEY;
#pragma pack()

//--------------------------------------------------------------------- 関数宣限�
#ifdef BRCOLOR

//カラーマッチング初期化処預�
BOOL ColorMatchingInit(CMATCH_INIT matchingInitDat);

//カラーマッチング終了処理
void ColorMatchingEnd(void);

//カラーマッチング処預�
BOOL ColorMatching(BYTE *pRgbData, long lRgbDataLength, long lLineCount);


//γカーブ補正用テーブル初期化処預�
BOOL InitGammaTable(void);

//モニターキャリブレーション初期化処理
BOOL InitMonitorGamma(void);

//LUT初期化処理
BOOL InitLUT(char* pcLutKind);

//γカーブ補正処理		
void GammaCurveMatching(BYTE *pRgbData, long lRgbDataLength, long lLineCount);

//LUT カラーマッチング処預�
BOOL LutColorMatching(BYTE *pRgbData, long lRgbDataLength, long lLineCount);

//モニターキャリブレーション処理
void MonitorCalibration(BYTE *pRgbData, long lRgbDataLength, long lLineCount);

//LUT参照インデックス取得処理
BOOL LutIndexGet(float fInPutData, short nLutColor, short *psIndex);

//LUT代表点測色取得処理(測色値‖�
BOOL LutExampleDataGet(BRLUT_INPUT_DATA	lutMatchInputData,
						BRLUT_EXP_POINT *plutExampleData);

//LUT代表点取得処預�(論理値‖�
BOOL LutLogicalDataGet(BRLUT_INPUT_DATA	lutMatchInputData,
						BRLUT_LOGIC_POINT *plutLogicData);

//マッチングデータ 計算処預�
BOOL CreateMatchData(BRLUT_INPUT_DATA lutMatchInputData, BRLUT_EXP_POINT lutExampleData,
					BRLUT_LOGIC_POINT lutLogicData);

//LUT選択処預�
BOOL LutSelect(BRLUT_SELECT lutSelectData, char * lutTableID);

//プリンターモード取得処理
BOOL GetPrinterMode(BRLUT_SELECT* plutSelectData);

//カラーマッチングハッシュ処理 ハッシュテーブル作成処理
BOOL StoreColorHash(void);

//カラーマッチングハッシュ処理 ハッシュ検索処理
BOOL LookupColorHash(BRLUT_INPUT_DATA lutMatchInputData);

//カラーマッチングハッシュ処理 終了処預�
BOOL EndColorHash(void);  

//LUT代表点(小空間 ８ポイント)測色データ取涜�
//LUT代表点(小空間 ８ポイント)論理データ値取得
//マッチングデータ 計算処預�
BOOL MatchDataGet(BRLUT_INPUT_DATA	*lutMatchInputData);

//-------------------------------------------------------------------マッチング用テーブヂ�
BRMONCALDAT		gMonitorGammaDat;		//モニターキャリブレーションγ値構造体


HANDLE			ghGammaCurveTable;		//γカーブ定義テーブヂ�
BYTE			*gpbGammaCurveTable;

BRLUT_HEAD_DATA_00	gLutDataHead00;		//LUT データヘッダ情報
#ifdef	TABLE_01
BRLUT_HEAD_DATA_01	gLutDataHead;		//LUT データヘッダ情報
#endif	//TABLE_01


HANDLE			ghLutDataTable;			//LUT テーブヂ�
BRLUT_DATA		*gpfLutDataTable;		//LUT DATA
#ifdef	GAMMA_ADJ

HANDLE			ghLutGammaTable;		//Gamma table
BRLUT_DATA		*gpfLutGammaTable;		//Gamma data
#endif	//GAMMA_ADJ
#ifdef	GRAY_ADJ

HANDLE			ghLutGrayTable;			//Gray table
BRLUT_DATA		*gpfLutGrayTable;		//Gray data
#endif	//GRAY_ADJ

CMATCH_INIT		gMatchingInitDat;		//カラーマッチング初期化情報構造詑�


BRLUT_SELECT 	glutSelectData;			//LUT選択情並�

char			szgWinSystem[145];		//Windows System ディレクトリ
#ifdef	INIT_LUT_NAME
char			szgLutDir[145];			//Lut Data ディレクトリ
#endif	//INIT_LUT_NAME
char			szgOpenFile[160];


HANDLE			ghHashTable;			//カラーマッチング高速化用ハッシュテーブル
COLOR_HASH_DAT	*gpHashTable;
//COLOR_HASH_KEY	colorHashKey[1000];		//カラーマッチング高速化用ハッシュキーテーブヂ�
//COLOR_HASH_KEY	colorHashKey[3375];		//カラーマッチング高速化用ハッシュキーテーブヂ�
int				gnColorHashFlag;		//カラーマッチング高速化用ハッシュ処理フラグ�ﾞ(=0 :OFF, =1 :ON)				

#else	//BRCOLOR
//---------------------------------------------------------------外部公蛎� 関数宣限�
//カラーマッチング初期化処預�
BOOL ColorMatchingInit(CMATCH_INIT matchingInitDat);
//カラーマッチング終了処理
void ColorMatchingEnd(void);
//カラーマッチング処預�
BOOL ColorMatching(BYTE *pRgbData, long lRgbDataLength, long lLineCount);

//カラーマッチング初期化処預�
typedef BOOL (*COLORINIT)(CMATCH_INIT);
//カラーマッチング終了処理
typedef void (*COLOREND)(void);
//カラーマッチング処預�
typedef BOOL (*COLORMATCHING)(BYTE *, long , long );

#endif	//BRCOLOR

#endif // _H_BRCOLOR_

