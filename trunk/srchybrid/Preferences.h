//this file is part of eMule
//Copyright (C)2002-2008 Merkur ( strEmail.Format("%s@%s", "devteam", "emule-project.net") / http://www.emule-project.net )
//
//This program is free software; you can redistribute it and/or
//modify it under the terms of the GNU General Public License
//as published by the Free Software Foundation; either
//version 2 of the License, or (at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program; if not, write to the Free Software
//Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
#pragma once

const CString strDefaultToolbar = _T("0099010203040506070899091011");
// MORPH START show less controls
const CString strDefaultLessControlsToolbar = _T("0099020304059909991011");
// MORPH END  show less controls

// ==> Design Settings [eWombat/Stulle] - Stulle
#ifdef DESIGN_SETTINGS
#include "Ini2.h"
#endif
// <== Design Settings [eWombat/Stulle] - Stulle

enum EViewSharedFilesAccess{
	vsfaEverybody = 0,
	vsfaFriends = 1,
	vsfaNobody = 2
};

enum ENotifierSoundType{
	ntfstNoSound = 0,
	ntfstSoundFile = 1,
	ntfstSpeech = 2
};

enum EDefaultDirectory{
	EMULE_CONFIGDIR = 0,
	EMULE_TEMPDIR = 1,
	EMULE_INCOMINGDIR = 2,
	EMULE_LOGDIR = 3,
	EMULE_ADDLANGDIR = 4, // directories with languages installed by the eMule (parent: EMULE_EXPANSIONDIR)
	EMULE_INSTLANGDIR = 5, // directories with languages installed by the user or installer (parent: EMULE_EXECUTEABLEDIR)
	EMULE_WEBSERVERDIR = 6,
	EMULE_SKINDIR = 7,
	EMULE_DATABASEDIR = 8, // the parent directory of the incoming/temp folder
	EMULE_CONFIGBASEDIR = 9, // the parent directory of the config folder 
	EMULE_EXECUTEABLEDIR = 10, // assumed to be not writeable (!)
	EMULE_TOOLBARDIR = 11,
	EMULE_EXPANSIONDIR = 12, // this is a base directory accessable for all users for things eMule installs
	EMULE_WAPSERVERDIR = 13, // Wapserver [emulEspa�a]
	EMULE_FEEDSDIR = 14 // MORPH - Added, XML News [O�]
};


enum EToolbarLabelType;
enum ELogFileFormat;

// DO NOT EDIT VALUES like making a uint16 to uint32, or insert any value. ONLY append new vars
#pragma pack(1)
struct Preferences_Ext_Struct{
	uint8	version;
	uchar	userhash[16];
	WINDOWPLACEMENT EmuleWindowPlacement;
};
#pragma pack()

// deadlake PROXYSUPPORT
struct ProxySettings{
	uint16		type;
	uint16		port;
	CStringA	name;
	CStringA	user;
	CStringA	password;
	bool		EnablePassword;
	bool		UseProxy;
};

// khaos::categorymod+ View Filter Struct
#pragma pack(1)
struct CategoryViewFilter_Struct{
	//		General View Filters
	UINT	nFromCats;  // 0 == All; 1 == Unassigned; 2 == This Cat Only
	bool	bSuspendFilters;
	//		File Type View Filters
	bool	bVideo;
	bool	bAudio;
	bool	bArchives;
	bool	bImages;
	//		File State View Filters
	bool	bWaiting;
	bool	bTransferring;
	bool	bPaused;
	bool	bStopped;
	bool	bComplete;
	bool	bHashing;
	bool	bErrorUnknown;
	bool	bCompleting;
	bool	bSeenComplet; //MORPH - Added by SiRoB, Seen Complet filter
	//		File Size View Filters
	uint64	nFSizeMin;
	uint64	nFSizeMax;
	uint64	nRSizeMin;
	uint64	nRSizeMax;
	//		Time Remaining Filters
	uint32	nTimeRemainingMin;
	uint32	nTimeRemainingMax;
	//		Source Count Filters
	UINT	nSourceCountMin;
	UINT	nSourceCountMax;
	UINT	nAvailSourceCountMin;
	UINT	nAvailSourceCountMax;
	//		Advanced Filter Mask
	CString	sAdvancedFilterMask;
};
#pragma pack()

// Criteria Selection Struct
#pragma pack(1)
struct CategorySelectionCriteria_Struct{
	bool	bFileSize;
	bool	bAdvancedFilterMask;
};
#pragma pack()
// khaos::categorymod-

struct Category_Struct{
	CString	strIncomingPath;
	CString	strTitle;
	CString	strComment;
	DWORD	color;
	UINT	prio;
	// khaos::kmod+ Category Advanced A4AF Mode
	// 0 = Default, 1 = Balancing, 2 = Stacking
	UINT	iAdvA4AFMode;
	bool	bResumeFileOnlyInSameCat; //MORPH - Added by SiRoB, Resume file only in the same category
	// View Filter Struct
	CategoryViewFilter_Struct viewfilters;
	CategorySelectionCriteria_Struct selectioncriteria;
	// khaos::kmod-
	//MORPH - Removed by SiRoB, Due to Khaos Categorie
	/*
	CString autocat;
	CString	regexp;
	int		filter;
	bool	filterNeg;
	bool	care4all;
	bool	ac_regexpeval;
	*/
	bool	downloadInAlphabeticalOrder; // ZZ:DownloadManager
};


// ==> Design Settings [eWombat/Stulle] - Stulle
#ifdef DESIGN_SETTINGS
#define STYLE_VERSION 2
struct StylesStruct 
{
	short nOnOff;
	DWORD nFlags;
	COLORREF nFontColor;
	COLORREF nBackColor;
};

#define STYLE_BOLD		0x0001
#define STYLE_UNDERLINE	0x0002
#define STYLE_ITALIC	0x0003
#define STYLE_USED		0x80000000
#define STYLE_FONTMASK	0x0003

// master styles
enum eMasterStyles
{
	client_styles = 0,
	download_styles,
	share_styles,
	server_styles,
	background_styles,
	window_styles,
	master_count
};

// client styles
enum eClientStyles
{
	style_c_default = 0,
	style_c_friend,
	style_c_powershare,
	style_c_downloading,
	style_c_uploading,
	style_c_leecher,
	style_c_lowid,
	style_c_credits,
	style_c_count
};

// download styles
enum eDownloadStyles
{
	style_d_default = 0,
	style_d_downloading,
	style_d_complete,
	style_d_completing,
	style_d_hashing,
	style_d_paused,
	style_d_stopped,
	style_d_errunk,
	style_d_count
};

// share styles
enum eShareStyles
{
	style_s_default = 0,
	style_s_incomplete,
	style_s_powershare,
	style_s_auto,
	style_s_verylow,
	style_s_low,
	style_s_normal,
	style_s_high,
	style_s_release,
	style_s_permnoone,
	style_s_permfriends,
	style_s_permcomm,
	style_s_permall,
	style_s_shareable,
	style_s_count
};

// server styles
enum eServerStyles
{
	style_se_default = 0,
	style_se_connected,
	style_se_static,
	style_se_filtered,
	style_se_dead,
	style_se_unreliable,
	style_se_count
};

// background styles
enum eBackgroundStyles
{
	style_b_default = 0,
	style_b_clientlist,
	style_b_dlclientlist,
	style_b_queuelist,
	style_b_uploadlist,
	style_b_downloadlist,
	style_b_sharedlist,
	style_b_serverwnd,
	style_b_count
};

// window styles
enum eWindowStyles
{
	style_w_default = 0,
	style_w_kademlia,
	style_w_server,
	style_w_transfer,
	style_w_search,
	style_w_shared,
	style_w_messages,
	style_w_irc,
	style_w_statistic,
	style_w_statusbar,
	style_w_toolbar,
	style_w_count
};
#endif
// <== Design Settings [eWombat/Stulle] - Stulle

// ==> FunnyNick Tag - Stulle
enum FnTagSelection {
	CS_NONE = 0,
	CS_SHORT,
	CS_FULL,
	CS_CUST
};
// <== FunnyNick Tag - Stulle

// ==> Anti Uploader Ban - Stulle
enum AntiUploaderBanCaseSelection {
	CS_1 = 0,
	CS_2,
	CS_3
};
// <== Anti Uploader Ban - Stulle

class CPreferences
{
public:
	static	CString	strNick;
	// ZZ:UploadSpeedSense -->
	static	UINT	minupload; //MORPH uint16 is not enough
	// ZZ:UploadSpeedSense <--
	static	UINT maxupload; //MORPH uint16 is not enough
	static	UINT 	maxdownload; //MORPH uint16 is not enough
	static	LPCSTR	m_pszBindAddrA;
	static	CStringA m_strBindAddrA;
	static	LPCWSTR	m_pszBindAddrW;
	static	CStringW m_strBindAddrW;
	// MORPH START leuk_he upnp bindaddr
	static DWORD	 m_dwUpnpBindAddr;
	static bool      m_bBindAddrIsDhcp;
	// MORPH End leuk_he upnp bindaddr
	static	uint16	port;
	static	uint16	udpport;
	static	uint16	nServerUDPPort;
	static	UINT	maxconnections;
	static	UINT	maxhalfconnections;
	static	bool	m_bConditionalTCPAccept;
	static	bool	reconnect;
	static	bool	m_bUseServerPriorities;
	static	bool	m_bUseUserSortedServerList;
	static	CString	m_strIncomingDir;
	static	CStringArray	tempdir;
	static	bool	ICH;
	static	bool	m_bAutoUpdateServerList;
	static	bool	updatenotify;
	static	bool	mintotray;
	static	bool	autoconnect;
	static	bool	m_bAutoConnectToStaticServersOnly; // Barry
	static	bool	autotakeed2klinks;	   // Barry
	static	bool	addnewfilespaused;	   // Barry
	static	UINT	depth3D;			   // Barry
	static	bool	m_bEnableMiniMule;
	static	int		m_iStraightWindowStyles;
	static  bool	m_bUseSystemFontForMainControls;
	static	bool	m_bRTLWindowsLayout;
	static	CString	m_strSkinProfile;
	static	CString	m_strSkinProfileDir;
	static	bool	m_bAddServersFromServer;
	static	bool	m_bAddServersFromClients;
	static	UINT	maxsourceperfile;
	static	UINT	trafficOMeterInterval;
	static	UINT	statsInterval;
	static	bool	m_bFillGraphs;
	static	uchar	userhash[16];
	static	WINDOWPLACEMENT EmuleWindowPlacement;
	static	int		maxGraphDownloadRate;
	static	int		maxGraphUploadRate;
	static	uint32	maxGraphUploadRateEstimated;
	static	bool	beepOnError;
	static	bool	confirmExit;
	// ==> Source Graph - Stulle
	/*
	static	DWORD	m_adwStatsColors[16]; //MORPH - Changed by SiRoB, Powershare display
	*/
	static	DWORD	m_adwStatsColors[17];
	// <== Source Graph - Stulle
	static  bool	m_bIconflashOnNewMessage;

	static	bool	splashscreen;
	static	bool	startupsound;//Commander - Added: Enable/Disable Startupsound
	static	bool	sidebanner;//Commander - Added: Side Banner
	static	bool	filterLANIPs;
	static	bool	m_bAllocLocalHostIP;
	static	bool	onlineSig;

	// -khaos--+++> Struct Members for Storing Statistics

	// Saved stats for cumulative downline overhead...
	static	uint64	cumDownOverheadTotal;
	static	uint64	cumDownOverheadFileReq;
	static	uint64	cumDownOverheadSrcEx;
	static	uint64	cumDownOverheadServer;
	static	uint64	cumDownOverheadKad;
	static	uint64	cumDownOverheadTotalPackets;
	static	uint64	cumDownOverheadFileReqPackets;
	static	uint64	cumDownOverheadSrcExPackets;
	static	uint64	cumDownOverheadServerPackets;
	static	uint64	cumDownOverheadKadPackets;

	// Saved stats for cumulative upline overhead...
	static	uint64	cumUpOverheadTotal;
	static	uint64	cumUpOverheadFileReq;
	static	uint64	cumUpOverheadSrcEx;
	static	uint64	cumUpOverheadServer;
	static	uint64	cumUpOverheadKad;
	static	uint64	cumUpOverheadTotalPackets;
	static	uint64	cumUpOverheadFileReqPackets;
	static	uint64	cumUpOverheadSrcExPackets;
	static	uint64	cumUpOverheadServerPackets;
	static	uint64	cumUpOverheadKadPackets;

	// Saved stats for cumulative upline data...
	static	uint32	cumUpSuccessfulSessions;
	static	uint32	cumUpFailedSessions;
	static	uint32	cumUpAvgTime;
	// Cumulative client breakdown stats for sent bytes...
	static	uint64	cumUpData_EDONKEY;
	static	uint64	cumUpData_EDONKEYHYBRID;
	static	uint64	cumUpData_EMULE;
	static	uint64	cumUpData_MLDONKEY;
	static	uint64	cumUpData_AMULE;
	static	uint64	cumUpData_EMULECOMPAT;
	static	uint64	cumUpData_SHAREAZA;
	// Session client breakdown stats for sent bytes...
	static	uint64	sesUpData_EDONKEY;
	static	uint64	sesUpData_EDONKEYHYBRID;
	static	uint64	sesUpData_EMULE;
	static	uint64	sesUpData_MLDONKEY;
	static	uint64	sesUpData_AMULE;
	static	uint64	sesUpData_EMULECOMPAT;
	static	uint64	sesUpData_SHAREAZA;

	// Cumulative port breakdown stats for sent bytes...
	static	uint64	cumUpDataPort_4662;
	static	uint64	cumUpDataPort_OTHER;
	static	uint64	cumUpDataPort_PeerCache;
	// Session port breakdown stats for sent bytes...
	static	uint64	sesUpDataPort_4662;
	static	uint64	sesUpDataPort_OTHER;
	static	uint64	sesUpDataPort_PeerCache;

	// Cumulative source breakdown stats for sent bytes...
	static	uint64	cumUpData_File;
	static	uint64	cumUpData_Partfile;
	// Session source breakdown stats for sent bytes...
	static	uint64	sesUpData_File;
	static	uint64	sesUpData_Partfile;

	// Saved stats for cumulative downline data...
	static	uint32	cumDownCompletedFiles;
	static	uint32	cumDownSuccessfulSessions;
	static	uint32	cumDownFailedSessions;
	static	uint32	cumDownAvgTime;

	// Cumulative statistics for saved due to compression/lost due to corruption
	static	uint64	cumLostFromCorruption;
	static	uint64	cumSavedFromCompression;
	static	uint32	cumPartsSavedByICH;

	// Session statistics for download sessions
	static	uint32	sesDownSuccessfulSessions;
	static	uint32	sesDownFailedSessions;
	static	uint32	sesDownAvgTime;
	static	uint32	sesDownCompletedFiles;
	static	uint64	sesLostFromCorruption;
	static	uint64	sesSavedFromCompression;
	static	uint32	sesPartsSavedByICH;

	// Cumulative client breakdown stats for received bytes...
	static	uint64	cumDownData_EDONKEY;
	static	uint64	cumDownData_EDONKEYHYBRID;
	static	uint64	cumDownData_EMULE;
	static	uint64	cumDownData_MLDONKEY;
	static	uint64	cumDownData_AMULE;
	static	uint64	cumDownData_EMULECOMPAT;
	static	uint64	cumDownData_SHAREAZA;
	static	uint64	cumDownData_URL;
	// Session client breakdown stats for received bytes...
	static	uint64	sesDownData_EDONKEY;
	static	uint64	sesDownData_EDONKEYHYBRID;
	static	uint64	sesDownData_EMULE;
	static	uint64	sesDownData_MLDONKEY;
	static	uint64	sesDownData_AMULE;
	static	uint64	sesDownData_EMULECOMPAT;
	static	uint64	sesDownData_SHAREAZA;
	static	uint64	sesDownData_URL;

	// Cumulative port breakdown stats for received bytes...
	static	uint64	cumDownDataPort_4662;
	static	uint64	cumDownDataPort_OTHER;
	static	uint64	cumDownDataPort_PeerCache;
	// Session port breakdown stats for received bytes...
	static	uint64	sesDownDataPort_4662;
	static	uint64	sesDownDataPort_OTHER;
	static	uint64	sesDownDataPort_PeerCache;

	// Saved stats for cumulative connection data...
	static	float	cumConnAvgDownRate;
	static	float	cumConnMaxAvgDownRate;
	static	float	cumConnMaxDownRate;
	static	float	cumConnAvgUpRate;
	static	float	cumConnMaxAvgUpRate;
	static	float	cumConnMaxUpRate;
	static	time_t	cumConnRunTime;
	static	uint32	cumConnNumReconnects;
	static	uint32	cumConnAvgConnections;
	static	uint32	cumConnMaxConnLimitReached;
	static	uint32	cumConnPeakConnections;
	static	uint32	cumConnTransferTime;
	static	uint32	cumConnDownloadTime;
	static	uint32	cumConnUploadTime;
	static	uint32	cumConnServerDuration;

	// Saved records for servers / network...
	static	uint32	cumSrvrsMostWorkingServers;
	static	uint32	cumSrvrsMostUsersOnline;
	static	uint32	cumSrvrsMostFilesAvail;

	// Saved records for shared files...
	static	uint32	cumSharedMostFilesShared;
	static	uint64	cumSharedLargestShareSize;
	static	uint64	cumSharedLargestAvgFileSize;
	static	uint64	cumSharedLargestFileSize;

	// Save the date when the statistics were last reset...
	static	time_t	stat_datetimeLastReset;

	// Save new preferences for PPgStats
	static	UINT	statsConnectionsGraphRatio; // This will store the divisor, i.e. for 1:3 it will be 3, for 1:20 it will be 20.
	// Save the expanded branches of the stats tree
	static	CString	m_strStatsExpandedTreeItems;

	static	UINT	statsSaveInterval;
	static  bool	m_bShowVerticalHourMarkers;
	// <-----khaos- End Statistics Members


	// Original Stats Stuff
	static	uint64	totalDownloadedBytes;
	static	uint64	totalUploadedBytes;
	// End Original Stats Stuff
	static	WORD	m_wLanguageID;
	static	bool	transferDoubleclick;
	static	EViewSharedFilesAccess m_iSeeShares;
	static	UINT	m_iToolDelayTime;	// tooltip delay time in seconds
	static	bool	bringtoforeground;
	static	UINT	splitterbarPosition;
	static	UINT	splitterbarPositionSvr;

	static	UINT	m_uTransferWnd1;
	static	UINT	m_uTransferWnd2;
	//MORPH START - Added by SiRoB, Splitting Bar [O�]
	static	UINT	splitterbarPositionStat;
	static	UINT	splitterbarPositionStat_HL;
	static	UINT	splitterbarPositionStat_HR;
	static	UINT	splitterbarPositionFriend;
	static	UINT	splitterbarPositionIRC;
	static	UINT	splitterbarPositionShared;
	//MORPH END - Added by SiRoB, Splitting Bar [O�]
	static	UINT	m_uDeadServerRetries;
	static	DWORD	m_dwServerKeepAliveTimeout;
	// -khaos--+++> Changed data type to avoid overflows
	static	UINT	statsMax;
	// <-----khaos-
	static	UINT	statsAverageMinutes;

	static	CString	notifierConfiguration;
	static	bool	notifierOnDownloadFinished;
	static	bool	notifierOnNewDownload;
	static	bool	notifierOnChat;
	static	bool	notifierOnLog;
	static	bool	notifierOnImportantError;
	static	bool	notifierOnEveryChatMsg;
	static	bool	notifierOnNewVersion;
	static	ENotifierSoundType notifierSoundType;
	static	CString	notifierSoundFile;

	static	CString	m_strIRCServer;
	static	CString	m_strIRCNick;
	static	CString	m_strIRCChannelFilter;
	static	bool	m_bIRCAddTimeStamp;
	static	bool	m_bIRCUseChannelFilter;
	static	UINT	m_uIRCChannelUserFilter;
	static	CString	m_strIRCPerformString;
	static	bool	m_bIRCUsePerform;
	static	bool	m_bIRCGetChannelsOnConnect;
	static	bool	m_bIRCAcceptLinks;
	static	bool	m_bIRCAcceptLinksFriendsOnly;
	static	bool	m_bIRCPlaySoundEvents;
	static	bool	m_bIRCIgnoreMiscMessages;
	static	bool	m_bIRCIgnoreJoinMessages;
	static	bool	m_bIRCIgnorePartMessages;
	static	bool	m_bIRCIgnoreQuitMessages;
	static	bool	m_bIRCIgnoreEmuleAddFriendMsgs;
	static	bool	m_bIRCAllowEmuleAddFriend;
	static	bool	m_bIRCIgnoreEmuleSendLinkMsgs;
	static	bool	m_bIRCJoinHelpChannel;
	static	bool	m_bIRCEnableSmileys;
	static	bool	m_bMessageEnableSmileys;

	static	bool	m_bRemove2bin;
	static	bool	m_bShowCopyEd2kLinkCmd;
	static	bool	m_bpreviewprio;
	static	bool	m_bSmartServerIdCheck;
	static	uint8	smartidstate;
	static	bool	m_bSafeServerConnect;
	static	bool	startMinimized;
	static	bool	m_bAutoStart;
	static	bool	m_bRestoreLastMainWndDlg;
	static	int		m_iLastMainWndDlgID;
	static	bool	m_bRestoreLastLogPane;
	static	int		m_iLastLogPaneID;
	static	UINT	MaxConperFive;
	static	bool	checkDiskspace;
	static	UINT	m_uMinFreeDiskSpace;
	static	bool	m_bSparsePartFiles;
	static	CString	m_strYourHostname;
	static	bool	m_bEnableVerboseOptions;
	static	bool	m_bVerbose;
	//MORPH START - Added by SiRoB, XML News [O�]
	static	bool	enableNEWS;
	//MORPH END   - Added by SiRoB, XML News [O�]
	static	bool	m_bFullVerbose;
	static  int		m_byLogLevel;
	static	bool	m_bDebugSourceExchange; // Sony April 23. 2003, button to keep source exchange msg out of verbose log
	static	bool	m_bLogBannedClients;
	static	bool	m_bLogRatingDescReceived;
	static	bool	m_bLogSecureIdent;
	static	bool	m_bLogFilteredIPs;
	static	bool	m_bLogFileSaving;
    static  bool    m_bLogA4AF; // ZZ:DownloadManager
	static	bool	m_bLogUlDlEvents;
	// MORPH START - Added by Commander, WebCache 1.2f
	static	bool	m_bLogICHEvents;//JP log ICH events
	// MORPH END   - Added by Commander, WebCache 1.2f
	static	bool	m_bUseDebugDevice;
	static	int		m_iDebugServerTCPLevel;
	static	int		m_iDebugServerUDPLevel;
	static	int		m_iDebugServerSourcesLevel;
	static	int		m_iDebugServerSearchesLevel;
	static	int		m_iDebugClientTCPLevel;
	static	int		m_iDebugClientUDPLevel;
	static	int		m_iDebugClientKadUDPLevel;
	static	int		m_iDebugSearchResultDetailLevel;
	static	bool	m_bupdatequeuelist;
	static	bool	m_bManualAddedServersHighPriority;
	static	bool	m_btransferfullchunks;
	static	int		m_istartnextfile;
	static	bool	m_bshowoverhead;
	static	bool	m_bDAP;
	static	bool	m_bUAP;
	static	bool	m_bDisableKnownClientList;
	static	bool	m_bDisableQueueList;
	static	bool	m_bExtControls;
	// MORPH START show less controls
	static	bool	m_bShowLessControls;
	// MORPH END  show less controls
	static	bool	m_bTransflstRemain;

	static	UINT	versioncheckdays;
	static	bool	showRatesInTitle;

	static	CString	m_strTxtEditor;
	static	CString	m_strVideoPlayer;
	static	CString	m_strVideoPlayerArgs;
	static	bool	moviePreviewBackup;
	static	int		m_iPreviewSmallBlocks;
	static	bool	m_bPreviewCopiedArchives;
	static	int		m_iInspectAllFileTypes;
	static	bool	m_bPreviewOnIconDblClk;
	static	bool	m_bCheckFileOpen;
	static	bool	indicateratings;
	static	bool	watchclipboard;
	static	bool	filterserverbyip;
	static	bool	m_bFirstStart;
	static	bool	m_bCreditSystem;

	static	bool	log2disk;
	static	bool	debug2disk;
	static	int		iMaxLogBuff;
	static	UINT	uMaxLogFileSize;
	static	ELogFileFormat m_iLogFileFormat;
	static	bool	scheduler;
	static	bool	dontcompressavi;
	static  int   m_iCompressLevel;	 // MORPH setable compresslevel [leuk_he]
	
	static	bool	msgonlyfriends;
	static	bool	msgsecure;
	static	bool	m_bUseChatCaptchas;

	static	UINT	filterlevel;
	static	UINT	m_iFileBufferSize;
	static	UINT	m_iQueueSize;
	static	int		m_iCommitFiles;
	static	UINT	m_uFileBufferTimeLimit;

	static	UINT	maxmsgsessions;
	static	time_t	versioncheckLastAutomatic; //vs2005
	//MORPH START - Added by SiRoB, New Version check
	static	uint32	mversioncheckLastAutomatic;
	//MORPH START - Added by SiRoB, New Version check
	static	CString	messageFilter;
	static	CString	commentFilter;
	static	CString	filenameCleanups;
	static	CString	m_strDateTimeFormat;
	static	CString	m_strDateTimeFormat4Log;
	static	CString	m_strDateTimeFormat4Lists;
	static	LOGFONT m_lfHyperText;
	static	LOGFONT m_lfLogText;
	static	COLORREF m_crLogError;
	static	COLORREF m_crLogWarning;
	static	COLORREF m_crLogSuccess;
	//MORPH START - Added by SiRoB, Upload Splitting Class
	static	COLORREF m_crLogUSC;
	//MORPH END   - Added by SiRoB, Upload Splitting Class

	// ==> Slot Limit - Stulle
	static bool m_bSlotLimitThree;
	static bool m_bSlotLimitNum;
	static uint8 m_iSlotLimitNum;
	// <== Slot Limit - Stulle
	static	int		m_iExtractMetaData;
	static	bool	m_bAdjustNTFSDaylightFileTime;
	static	bool	m_bRearrangeKadSearchKeywords;
	static  bool    m_bAllocFull;


	// Web Server [kuchin]
	//>>> [ionix] - iONiX::Advanced WebInterface Account Management
	static	bool	m_bIonixWebsrv;
	//<<< [ionix] - iONiX::Advanced WebInterface Account Management
	static	CString	m_strWebPassword;
	static	CString	m_strWebLowPassword;
	static	uint16	m_nWebPort;
#ifdef USE_OFFICIAL_UPNP
	static	bool	m_bWebUseUPnP;
#endif
	static	bool	m_bWebEnabled;
	static	bool	m_bWebUseGzip;
	static	int		m_nWebPageRefresh;
	static	bool	m_bWebLowEnabled;
	static	int		m_iWebTimeoutMins;
	static	int		m_iWebFileUploadSizeLimitMB;
	static	CString	m_strTemplateFile;
	static	ProxySettings proxy; // deadlake PROXYSUPPORT
	static  bool	m_bAllowAdminHiLevFunc;
	static	CUIntArray m_aAllowedRemoteAccessIPs;

	static	bool	showCatTabInfos;
	static	bool	resumeSameCat;
	static	bool	dontRecreateGraphs;
	static	bool	autofilenamecleanup;
	//static	int		allcatType;
	//static	bool	allcatTypeNeg;
	static	bool	m_bUseAutocompl;
	static	bool	m_bShowDwlPercentage;
	static	bool	m_bShowClientPercentage; //Commander - Added: Client Percentage
	static	bool	m_bRemoveFinishedDownloads;
	static	UINT	m_iMaxChatHistory;
	// ==> Design Settings [eWombat/Stulle] - Stulle
#ifndef DESIGN_SETTINGS
	static	bool	m_bShowActiveDownloadsBold;
#endif
	// <== Design Settings [eWombat/Stulle] - Stulle

	static	int		m_iSearchMethod;
	static	bool	m_bAdvancedSpamfilter;
	static	bool	m_bUseSecureIdent;
	// mobilemule
	static	CString	m_strMMPassword;
	static	bool	m_bMMEnabled;
	static	uint16	m_nMMPort;

	static	bool	networkkademlia;
	static	bool	networked2k;

	// toolbar
	static	EToolbarLabelType m_nToolbarLabels;
	static	CString	m_sToolbarBitmap;
	static	CString	m_sToolbarBitmapFolder;
	static	CString	m_sToolbarSettings;
	static	bool	m_bReBarToolbar;
	static	CSize	m_sizToolbarIconSize;

	static	bool	m_bWinaTransToolbar;

	//preview
	static	bool	m_bPreviewEnabled;
	static	bool	m_bAutomaticArcPreviewStart;

	// ==> Design Settings [eWombat/Stulle] - Stulle
#ifndef DESIGN_SETTINGS
	static bool	enableDownloadInRed; //MORPH - Added by IceCream, show download in red
#endif
	// <== Design Settings [eWombat/Stulle] - Stulle
	//MORPH START - Added by schnulli900, filter clients with failed downloads [Xman]
	static bool	m_bFilterClientFailedDown; 
	//MORPH END   - Added by schnulli900, filter clients with failed downloads [Xman]
	static bool	enableAntiLeecher; //MORPH - Added by IceCream, enableAntiLeecher
	static bool	enableAntiCreditHack; //MORPH - Added by IceCream, enableAntiCreditHack
	static int	creditSystemMode; // EastShare - Added by linekin, creditsystem integration
	static bool	m_bEnableEqualChanceForEachFile;//Morph - added by AndCycle, Equal Chance For Each File
	static bool m_bFollowTheMajority; // EastShare       - FollowTheMajority by AndCycle
	static int	m_iFairPlay;	//EastShare	- FairPlay by AndCycle
	static bool	isautodynupswitching;//MORPH - Added by Yun.SF3, Auto DynUp changing
	static int	m_iPowershareMode; //MORPH - Added by SiRoB, Avoid misusing of powersharing
	static bool m_bPowershareInternalPrio; //Morph - added by AndCyle, selective PS internal Prio
	static int	maxconnectionsswitchborder;
	//EastShare Start- Added by Pretender, TBH-AutoBackup
	static bool	autobackup;
	static bool	autobackup2;
	//EastShare End - Added by Pretender, TBH-AutoBackup

	//MORPH START - Added by SiRoB, Datarate Average Time Management
	static int	m_iDownloadDataRateAverageTime;
	static int	m_iUploadDataRateAverageTime;
	//MORPH END   - Added by SiRoB, Datarate Average Time Management

	//MORPH START - Added by SiRoB, Upload Splitting Class
	static int	globaldataratefriend;
	static int	maxglobaldataratefriend;
	static int	globaldataratepowershare;
	static int	maxglobaldataratepowershare;
	static int	maxclientdataratefriend;
	static int	maxclientdataratepowershare;
	static int	maxclientdatarate;
	//MORPH END   - Added by SiRoB, Upload Splitting Class
	//MORPH START - Added by SiRoB, SLUGFILLER: lowIdRetry
	static int	LowIdRetries;
	static int	LowIdRetried;
	//MORPH END   - Added by SiRoB, SLUGFILLER: lowIdRetry
	//MORPH	Start	- Added by AndCycle, SLUGFILLER: Spreadbars - per file
	static int	m_iSpreadbarSetStatus;
	//MORPH	End	- Added by AndCycle, SLUGFILLER: Spreadbars - per file
	//MORPH START - Added by SiRoB, SLUGFILLER: hideOS
	static int	hideOS;
	static bool	selectiveShare;
	//MORPH END   - Added by SiRoB, SLUGFILLER: hideOS

	static bool	infiniteQueue;	//Morph - added by AndCycle, SLUGFILLER: infiniteQueue

	//MORPH START - Added by SiRoB, SHARE_ONLY_THE_NEED Wistily idea
	static int	ShareOnlyTheNeed;
	//MORPH END   - Added by SiRoB, SHARE_ONLY_THE_NEED Wistily idea
	
	//MORPH START - Added by SiRoB, POWERSHARE Limit
	static int	PowerShareLimit;
	//MORPH END   - Added by SiRoB, POWERSHARE Limit
	
	//MORPH START - Added by SiRoB, Show Permissions
	static int	permissions;
	//MORPH END   - Added by SiRoB, Show Permissions
	
	//EastShare Start - PreferShareAll by AndCycle
	static bool	shareall;	// SLUGFILLER: preferShareAll
	//EastShare End - PreferShareAll by AndCycle

	//EastShare - Added by Pretender, Option for ChunkDots
	static bool	m_bEnableChunkDots;
	//EastShare - Added by Pretender, Option for ChunkDots
	//EastShare START - Added by Pretender, modified Fine Credit System
	static bool	m_bFineCS;
	//EastShare END

	static TCHAR UpdateURLFakeList[256];//MORPH START - Added by milobac and Yun.SF3, FakeCheck, FakeReport, Auto-updating
	static TCHAR UpdateURLIPFilter[256];//MORPH START added by Yun.SF3: Ipfilter.dat update
	static TCHAR UpdateURLIP2Country[256]; //Commander - Added: IP2Country auto-updating

    //MORPH START - Added by Commander, ClientQueueProgressBar
    static bool m_bClientQueueProgressBar;
	//MORPH END - Added by Commander, ClientQueueProgressBar
    
	//MORPH START - Added by Commander, FolderIcons
	static bool m_bShowFolderIcons;
	//MORPH END - Added by Commander, FolderIcons

	static bool	m_bPayBackFirst;//EastShare - added by AndCycle, Pay Back First
	static uint8	m_iPayBackFirstLimit;//MORPH - Added by SiRoB, Pay Back First Tweak
	static bool	m_bOnlyDownloadCompleteFiles;//EastShare - Added by AndCycle, Only download complete files v2.1 (shadow)
	static bool	m_bSaveUploadQueueWaitTime;//Morph - added by AndCycle, Save Upload Queue Wait Time (MSUQWT)
	// EastShare START - Added by TAHO, .met file control
	static int	m_iKnownMetDays;
	static bool	m_bCompletlyPurgeOldKnownFiles;
	static bool m_bRemoveAichImmediatly;
	// EastShare END   - Added by TAHO, .met file control
	static bool	m_bDateFileNameLog;//Morph - added by AndCycle, Date File Name Log
	static bool m_bDontRemoveSpareTrickleSlot;//Morph - added by AndCycle, Dont Remove Spare Trickle Slot
	static bool	m_bFunnyNick;//MORPH - Added by SiRoB, Optionnal funnynick display
	static bool m_bUseDownloadOverhead; // MORPH leuk_he include download overhead in upload stats
	//MORPH START - Added by milobac, FakeCheck, FakeReport, Auto-updating
	static SYSTEMTIME		m_FakesDatVersion;
	static bool		UpdateFakeStartup;
	//MORPH END - Added by milobac, FakeCheck, FakeReport, Auto-updating

	//MORPH START added by Yun.SF3: Ipfilter.dat update
	static bool		AutoUpdateIPFilter; //added by milobac: Ipfilter.dat update
	static SYSTEMTIME		m_IPfilterVersion; //added by milobac: Ipfilter.dat update
	static uint32		m_uIPFilterVersionNum; //MORPH - Added by Stulle, New IP Filter by Ozzy [Stulle/Ozzy]
	//MORPH END added by Yun.SF3: Ipfilter.dat update

	//Commander - Added: IP2Country Auto-updating - Start
	static bool		AutoUpdateIP2Country; 
	static SYSTEMTIME	m_IP2CountryVersion;
    //Commander - Added: IP2Country Auto-updating - End

	//EastShare - added by AndCycle, IP to Country
	static int	m_iIP2CountryNameMode;
	static bool		m_bIP2CountryShowFlag;
	//EastShare - added by AndCycle, IP to Country

	// khaos::categorymod+
	static bool		m_bValidSrcsOnly;
	static bool		m_bShowCatNames;
	static bool		m_bActiveCatDefault;
	static bool		m_bSelCatOnAdd;
	static bool		m_bAutoSetResumeOrder;
	static bool		m_bSmallFileDLPush;
	static uint8		m_iStartDLInEmptyCats;
	static bool		m_bRespectMaxSources;
	static bool		m_bUseAutoCat;
	// khaos::categorymod-
	// khaos::kmod+
	static bool		m_bShowA4AFDebugOutput;
	static bool		m_bSmartA4AFSwapping;
	static uint8		m_iAdvancedA4AFMode; // 0 = disabled, 1 = balance, 2 = stack
	static bool		m_bUseSaveLoadSources;
	// khaos::categorymod-
	// MORPH START leuk_he disable catcolor
	static	bool   m_bDisableCatColors;
    // MORPH END   leuk_he disable catcolor
	
	// khaos::accuratetimerem+
	static uint8		m_iTimeRemainingMode; // 0 = both, 1 = real time, 2 = average
	// khaos::accuratetimerem-
	//MORPH START - Added by SiRoB, ICS Optional
	static bool		m_bUseIntelligentChunkSelection;
	//MORPH END   - Added by SiRoB, ICS Optional
	
	// Mighty Knife: Community Visualization, Report hashing files, Log friendlist activities
	static TCHAR	m_sCommunityName [256];
	static bool		m_bReportHashingFiles;
	static bool	    m_bLogFriendlistActivities;
	// [end] Mighty Knife

	// Mighty Knife: CRC32-Tag - not accessible in preferences dialog !
	static bool		m_bDontAddCRCToFilename;
	static bool		m_bCRC32ForceUppercase;
	static bool		m_bCRC32ForceAdding;
	static TCHAR		m_sCRC32Prefix [256];
	static TCHAR		m_sCRC32Suffix [256];
	// [end] Mighty Knife

	// Mighty Knife: Simple cleanup options
	static int      m_SimpleCleanupOptions;
	static CString  m_SimpleCleanupSearch;
	static CString  m_SimpleCleanupReplace;
	static CString  m_SimpleCleanupSearchChars;
	static CString  m_SimpleCleanupReplaceChars;
	// [end] Mighty Knife

	// Mighty Knife: Static server handling
	static bool		m_bDontRemoveStaticServers;
	// [end] Mighty Knife

	//MORPH START - Added by SiRoB, Smart Upload Control v2 (SUC) [lovelace]
	static bool		m_bSUCEnabled;
	static int		m_iSUCHigh;
	static int		m_iSUCLow;
	static int		m_iSUCPitch;
	static int		m_iSUCDrift;
	static bool		m_bSUCLog;
	//MORPH END - Added by SiRoB, Smart Upload Control v2 (SUC) [lovelace]

	//MORPH START - Added by SiRoB, ZZ Upload system (USS)
	static	bool	m_bDynUpEnabled;
	static	int		m_iDynUpPingTolerance;
	static	int		m_iDynUpGoingUpDivider;
	static	int		m_iDynUpGoingDownDivider;
	static	int		m_iDynUpNumberOfPings;
	static  int		m_iDynUpPingToleranceMilliseconds;
	static  bool	m_bDynUpUseMillisecondPingTolerance;
	static bool		m_bDynUpLog;
    static bool		m_bUSSUDP; //MORPH - Added by SiRoB, USS UDP preferency
	static short    m_sPingDataSize;  //MORPH leuk_he ICMP ping datasize <> 0 setting
	//MORPH END   - Added by SiRoB, ZZ Upload system (USS)

    //Commander - Added: Invisible Mode [TPT] - Start
    static bool		m_bInvisibleMode;		
	static UINT		m_iInvisibleModeHotKeyModifier;
	static char		m_cInvisibleModeHotKey;
    //Commander - Added: Invisible Mode [TPT] - End

	//MORPH START - Added by SiRoB, [MoNKi: -UPnPNAT Support-]
	static bool		m_bUPnPNat;
	static bool		m_bUPnPNatWeb;
	static bool		m_bUPnPVerboseLog;
	static uint16	m_iUPnPPort;
	static bool		m_bUPnPLimitToFirstConnection;
	static bool		m_bUPnPClearOnClose;
	static int    m_iDetectuPnP; //leuk_he autodetect in startup wizard
	static bool     m_bUPnPForceUpdate;
	//MORPH END   - Added by SiRoB, [MoNKi: -UPnPNAT Support-]

	//MORPH START - Added by SiRoB, [MoNKi: -Random Ports-]
	static bool		m_bRndPorts;
	static uint16	m_iMinRndPort;
	static uint16	m_iMaxRndPort;
	static bool		m_bRndPortsResetOnRestart;
	static uint16	m_iRndPortsSafeResetOnRestartTime;
	static uint16	m_iCurrentTCPRndPort;
	static uint16	m_iCurrentUDPRndPort;
	//MORPH END   - Added by SiRoB, [MoNKi: -Random Ports-]

	//MORPH START - Added by SiRoB, [MoNKi: -Improved ICS-Firewall support-]
	static bool		m_bICFSupport;
	static bool		m_bICFSupportFirstTime;
	static bool		m_bICFSupportStatusChanged;
	static bool		m_bICFSupportServerUDP;
	//MORPH END   - Added by SiRoB, [MoNKi: -Improved ICS-Firewall support-]

    //MORPH START - Added by SiRoB / Commander, Wapserver [emulEspa�a]
	static TCHAR	m_sWapTemplateFile[MAX_PATH];
	static bool		m_bWapEnabled;
	static uint16	m_nWapPort;
	static int		m_iWapGraphWidth;
	static int		m_iWapGraphHeight;
	static bool		m_bWapFilledGraphs;
	static int		m_iWapMaxItemsInPages;
	static bool		m_bWapSendImages;
	static bool		m_bWapSendGraphs;
	static bool		m_bWapSendProgressBars;
	static bool		m_bWapAllwaysSendBWImages;
	static UINT		m_iWapLogsSize;
	static CString	m_strWapServerDir;
	static CString	m_sWapPassword;
	static CString	m_sWapLowPassword;
	static bool		m_bWapLowEnabled;
	//MORPH END - Added by SiRoB / Commander, Wapserver [emulEspa�a]

    static bool     m_bA4AFSaveCpu; // ZZ:DownloadManager

    static bool     m_bHighresTimer;

	static	bool	m_bResolveSharedShellLinks;
	static	CStringList shareddir_list;
	static	CStringList sharedsubdir_list;	// SLUGFILLER: shareSubdir
	static	CStringList inactive_shareddir_list; // sharedsubdir inactive 
	static	CStringList inactive_sharedsubdir_list;	// sharedsubdir inactive
    
	static	CStringList addresses_list;

	static	int		m_iDbgHeap;
	static	UINT	m_nWebMirrorAlertLevel;
	static	bool	m_bRunAsUser;
	static	bool	m_bPreferRestrictedOverUser;

	static  bool	m_bUseOldTimeRemaining;

	// PeerCache
	static	uint32	m_uPeerCacheLastSearch;
	static	bool	m_bPeerCacheWasFound;
	static	bool	m_bPeerCacheEnabled;
	static	uint16	m_nPeerCachePort;
	static	bool	m_bPeerCacheShow;

	// Firewall settings
	static bool		m_bOpenPortsOnStartUp;

	//AICH Options
	static bool		m_bTrustEveryHash;
	
	// files
	static bool		m_bRememberCancelledFiles;
	static bool		m_bRememberDownloadedFiles;
	static bool		m_bPartiallyPurgeOldKnownFiles;

	//emil notifier
	static bool		m_bNotifierSendMail;
	static CString	m_strNotifierMailServer;
	static CString	m_strNotifierMailSender;
	static CString	m_strNotifierMailReceiver;

	// encryption / obfuscation / verification
	static bool		m_bCryptLayerRequested;
	static bool		m_bCryptLayerSupported;
	static bool		m_bCryptLayerRequired;
	static uint8	m_byCryptTCPPaddingLength;
	static uint32   m_dwKadUDPKey;

#ifdef USE_OFFICIAL_UPNP
	// UPnP
	static bool		m_bSkipWANIPSetup;
	static bool		m_bSkipWANPPPSetup;
	static bool		m_bEnableUPnP;
	static bool		m_bCloseUPnPOnExit;
	static bool		m_bIsWinServImplDisabled;
	static bool		m_bIsMinilibImplDisabled;
	static int		m_nLastWorkingImpl;
#endif

	// Spam
	static bool		m_bEnableSearchResultFilter;

	static BOOL		m_bIsRunningAeroGlass;
	static bool		m_bPreventStandby;
	static bool		m_bStoreSearches;


	static bool		m_bCryptLayerRequiredStrictServer; // MORPH lh require obfuscated server connection 

	//MORPH START - Added by Stulle, Global Source Limit
	static  UINT	m_uGlobalHL;
	static	bool	m_bGlobalHL;
	//MORPH END   - Added by Stulle, Global Source Limit
    // MORPH START leuk_he Advanced official preferences.
	static bool bMiniMuleAutoClose;
	static int  iMiniMuleTransparency ;
	static bool bCreateCrashDump;
	static bool bCheckComctl32 ;
	static bool bCheckShell32;
	static bool bIgnoreInstances;
	static CString sNotifierMailEncryptCertName;
	static CString sMediaInfo_MediaInfoDllPath ;
	static bool bMediaInfo_RIFF ;
	static bool bMediaInfo_ID3LIB; 
	static CString sInternetSecurityZone;
   // MORPH END  leuk_he Advanced official preferences. 

	static bool m_bStaticIcon; //MORPH - Added, Static Tray Icon

	static int m_iServiceStartupMode; // MORPH leuk_he:run as ntservice v1..
	// ==> [MoNKi: -USS initial TTL-] - Stulle
	static uint8	m_iUSSinitialTTL;
	// <== [MoNKi: -USS initial TTL-] - Stulle


	// ==> push small files [sivka] - Stulle
    static  bool	enablePushSmallFile;
    static	uint32	m_iPushSmallFiles;
	static	uint16	m_iPushSmallBoost;
	// <== push small files [sivka] - Stulle
    static  bool enablePushRareFile; // push rare file - Stulle

	static bool	showSrcInTitle; // Show sources on title - Stulle
	static bool	showOverheadInTitle; // show overhead on title - Stulle
	static bool ShowGlobalHL; // show global HL - Stulle
	static bool ShowFileHLconst; // show HL per file constantly
	static bool m_bShowInMSN7; //Show in MSN7 [TPT] - Stulle
	static bool m_bTrayComplete; // Completed in Tray - Stulle
	// ==> CPU/MEM usage [$ick$/Stulle] - Stulle
	static bool m_bSysInfo;
	static bool m_bSysInfoGlobal;
	// <== CPU/MEM usage [$ick$/Stulle] - Stulle
	static bool m_bShowSpeedMeter; // High resulution speedmeter on toolbar [eFMod/Stulle] - Stulle

	// ==> Sivka-Ban [cyrex2001] - Stulle
	static bool	enableSivkaBan;
	static uint16  m_iSivkaAskTime;
	static uint16  m_iSivkaAskCounter;
	static bool	m_bSivkaAskLog;
	static bool	SivkaAskLog;
	// <== Sivka-Ban [cyrex2001] - Stulle

	// ==> ban systems optional - Stulle
	static bool		m_bBadModString;
	static bool		m_bBadNickBan;
	static bool		m_bGhostMod;
	static bool		m_bAntiModIdFaker;
	static bool		m_bAntiNickThief;
	static bool		m_bEmptyNick;
	static bool		m_bFakeEmule;
	static bool		m_bLeecherName;
	static bool		m_bCommunityCheck;
	static bool		m_bHexCheck;
	static bool		m_bEmcrypt;
	static bool		m_bBadInfo;
	static bool		m_bBadHello;
	static bool		m_bSnafu;
	static bool		m_bExtraBytes;
	static bool		m_bNickChanger;
	static bool		m_bFileFaker;
	static bool		m_bVagaa;
	// <== ban systems optional - Stulle

	// ==> Reduce Score for leecher - Stulle
	static bool		m_bReduceScore;
	static float	m_fReduceFactor;
	// <== Reduce Score for leecher - Stulle

	static bool		m_bAntiXsExploiter; // Anti-XS-Exploit [Xman] - Stulle
	static bool		m_bSpamBan; // Spam Ban [Xman] - Stulle

	// ==> Inform Clients after IP Change - Stulle
	static bool		m_breaskSourceAfterIPChange;
	static bool		m_bInformQueuedClientsAfterIPChange;
	// <== Inform Clients after IP Change - Stulle

	static uint32	m_uReAskTimeDif; // Timer for ReAsk File Sources - Stulle

	// ==> Quick start [TPT] - Stulle
	static bool	m_bQuickStart;
	static uint16  m_iQuickStartMaxTime;
	static UINT    m_iQuickStartMaxConn;
	static uint16  m_iQuickStartMaxConnPerFive;
	static UINT    m_iQuickStartMaxConnBack;
	static uint16  m_iQuickStartMaxConnPerFiveBack;
	static bool	m_bQuickStartAfterIPChange;
	// <== Quick start [TPT] - Stulle

	// ==> FunnyNick Tag - Stulle
	static uint8	FnTagMode;
	static TCHAR	m_sFnCustomTag [256];
	static bool		m_bFnTagAtEnd;
	// <== FunnyNick Tag - Stulle

	// ==> Pay Back First for insecure clients - Stulle
	static bool		m_bPayBackFirst2;
	static uint16	m_iPayBackFirstLimit2;
	// <== Pay Back First for insecure clients - Stulle

	static DWORD	m_dwClientBanTime; // adjust ClientBanTime - Stulle

	// ==> drop sources - Stulle
	static	uint32	m_MaxSourcesPerFileTemp;
	static	bool	m_EnableAutoDropNNSTemp;
	static	DWORD	m_AutoNNS_TimerTemp;
	static	uint16  m_MaxRemoveNNSLimitTemp;
	static	bool	m_EnableAutoDropFQSTemp;
	static	DWORD	m_AutoFQS_TimerTemp;
	static	uint16  m_MaxRemoveFQSLimitTemp;
	static	bool	m_EnableAutoDropQRSTemp;
	static	DWORD	m_AutoHQRS_TimerTemp;
	static	uint16  m_MaxRemoveQRSTemp;
	static	uint16  m_MaxRemoveQRSLimitTemp;
	static	bool	m_bGlobalHlTemp; // Global Source Limit (customize for files) - Stulle
	static	bool	m_EnableAutoDropNNSDefault;
	static	DWORD	m_AutoNNS_TimerDefault;
	static	uint16  m_MaxRemoveNNSLimitDefault;
	static	bool	m_EnableAutoDropFQSDefault;
	static	DWORD	m_AutoFQS_TimerDefault;
	static	uint16  m_MaxRemoveFQSLimitDefault;
	static	bool	m_EnableAutoDropQRSDefault;
	static	DWORD	m_AutoHQRS_TimerDefault;
	static	uint16  m_MaxRemoveQRSDefault;
	static	uint16  m_MaxRemoveQRSLimitDefault;
	static	bool	m_MaxSourcesPerFileTakeOver;
	static	bool	m_EnableAutoDropNNSTakeOver;
	static	bool	m_AutoNNS_TimerTakeOver;
	static	bool	m_MaxRemoveNNSLimitTakeOver;
	static	bool	m_EnableAutoDropFQSTakeOver;
	static	bool	m_AutoFQS_TimerTakeOver;
	static	bool	m_MaxRemoveFQSLimitTakeOver;
	static	bool	m_EnableAutoDropQRSTakeOver;
	static	bool	m_AutoHQRS_TimerTakeOver;
	static	bool	m_MaxRemoveQRSTakeOver;
	static	bool	m_MaxRemoveQRSLimitTakeOver;
	static	bool	m_bGlobalHlTakeOver; // Global Source Limit (customize for files) - Stulle
	static	bool	m_TakeOverFileSettings;
	// <== drop sources - Stulle

	// ==> TBH: minimule - Stulle
	static  int		speedmetermin;
	static  int		speedmetermax;
	static  bool	m_bMiniMule;
	static  uint32	m_iMiniMuleUpdate;
	static  bool	m_bMiniMuleLives;
	static  uint8	m_iMiniMuleTransparency;
	static	bool	m_bMMCompl;
	static	bool	m_bMMOpen;
	// <== TBH: minimule - Stulle

	// ==> Anti Uploader Ban - Stulle
	static uint16 m_iAntiUploaderBanLimit;
	static uint8 AntiUploaderBanCaseMode;
	// <== Anti Uploader Ban - Stulle

	// ==> Spread Credits Slot - Stulle
	static bool	SpreadCreditsSlot;
	static uint16 SpreadCreditsSlotCounter;
	static bool m_bSpreadCreditsSlotPS;
	// <== Spread Credits Slot - Stulle

	// ==> Source Graph - Stulle
	static bool	m_bSrcGraph;
	static uint16  m_iStatsHLMin;
	static uint16  m_iStatsHLMax;
	static uint16  m_iStatsHLDif;
	// <== Source Graph - Stulle

	// ==> Global Source Limit (customize for files) - Stulle
	static	bool	m_bGlobalHlAll;
    static  bool	m_bGlobalHlDefault;
	// <== Global Source Limit (customize for files) - Stulle

	static time_t	m_uStulleVerCheckLastAutomatic; // StulleMule Version Check - Stulle

	// ==> Emulate others [WiZaRd/Spike/shadow2004] - Stulle
	static	bool	m_bEmuMLDonkey;
	static	bool	m_bEmueDonkey;
	static	bool	m_bEmueDonkeyHybrid;
	static	bool	m_bEmuShareaza;
	static  bool    m_bEmuLphant;
	static	bool	m_bLogEmulator;
	// <== Emulate others [WiZaRd/Spike/shadow2004] - Stulle

	static	uint8	m_uReleaseBonus; // Release Bonus [sivka] - Stulle
	static	bool	m_bReleaseScoreAssurance; // Release Score Assurance - Stulle

	// ==> Connection Checker [eWombat/WiZaRd] - Stulle
	static  bool	m_bICMP; 
	static	uint8	m_uiPingTimeOut;
	static	uint8	m_uiPingTTL; 
	static	bool	m_bCheckCon;
	// <== Connection Checker [eWombat/WiZaRd] - Stulle

	static int	PsAmountLimit; // Limit PS by amount of data uploaded - Stulle

	static bool m_bNoBadPushing; // Disable PS/PBF for leechers [Stulle/idea by sfrqlxert] - Stulle

	// ==> Global Mod statistics [Stulle/some code by SlugFiller] - Stulle
#ifdef GLOBAL_MOD_STATS
	static int	m_uMinModAmount;
#endif
	// <== Global Mod statistics [Stulle/some code by SlugFiller] - Stulle

	// ==> Design Settings [eWombat/Stulle] - Stulle
#ifdef DESIGN_SETTINGS
	// client styles
	static DWORD		nClientStyleFlags[style_c_count]; 
	static COLORREF		nClientStyleFontColor[style_c_count];
	static COLORREF		nClientStyleBackColor[style_c_count];
	static short		nClientStyleOnOff[style_c_count];

	// download styles
	static DWORD		nDownloadStyleFlags[style_d_count]; 
	static COLORREF		nDownloadStyleFontColor[style_d_count];
	static COLORREF		nDownloadStyleBackColor[style_d_count];
	static short		nDownloadStyleOnOff[style_d_count];

	// share styles
	static DWORD		nShareStyleFlags[style_s_count]; 
	static COLORREF		nShareStyleFontColor[style_s_count];
	static COLORREF		nShareStyleBackColor[style_s_count];
	static short		nShareStyleOnOff[style_s_count];

	// server styles
	static DWORD		nServerStyleFlags[style_se_count]; 
	static COLORREF		nServerStyleFontColor[style_se_count];
	static COLORREF		nServerStyleBackColor[style_se_count];
	static short		nServerStyleOnOff[style_se_count];

	// background styles
	static DWORD		nBackgroundStyleFlags[style_b_count]; 
	static COLORREF		nBackgroundStyleFontColor[style_b_count];
	static COLORREF		nBackgroundStyleBackColor[style_b_count];
	static short		nBackgroundStyleOnOff[style_b_count];

	// window styles
	static DWORD		nWindowStyleFlags[style_w_count]; 
	static COLORREF		nWindowStyleFontColor[style_w_count];
	static COLORREF		nWindowStyleBackColor[style_w_count];
	static short		nWindowStyleOnOff[style_w_count];

	static bool			m_bAutoTextColors;
#endif
	// <== Design Settings [eWombat/Stulle] - Stulle

	// ==> Automatic shared files updater [MoNKi] - Stulle
#ifdef ASFU
	static bool			m_bDirectoryWatcher;
	static bool			m_bSingleSharedDirWatcher;
	static uint32		m_uTimeBetweenReloads;
#endif
	// <== Automatic shared files updater [MoNKi] - Stulle

	// ==> Enforce Ratio - Stulle
	static bool		m_bEnforceRatio;
	static uint8	m_uRatioValue;
	static bool		m_bOnlyEnforce;
	// <== Enforce Ratio - Stulle

	// ==> Advanced Transfer Window Layout - Stulle
#ifdef ATWL
	static bool		m_bSplitWindow;
#endif
	// <== Advanced Transfer Window Layout - Stulle

	// ==> Adjustable NT Service Strings - Stulle
	static CString	m_strServiceName;
	static CString	m_strServiceDispName;
	static CString	m_strServiceDescr;
	// <== Adjustable NT Service Strings - Stulle

	static bool		m_bImport60Friends; // Import 0x66 FriendSlots - Stulle

	enum Table
	{
		tableDownload, 
		tableUpload, 
		tableQueue, 
		tableSearch,
		tableShared, 
		tableServer, 
		tableClientList,
		tableFilenames,
		tableIrcMain,
		tableIrcChannels,
		//MORPH START - Added, Downloaded History [Monki/Xman]
#ifndef NO_HISTORY
		tableHistory,
#endif
		//MORPH END   - Added, Downloaded History [Monki/Xman]
		tableDownloadClients
	};

	friend class CPreferencesWnd;
	friend class CPPgGeneral;
	friend class CPPgConnection;
	friend class CPPgServer;
	friend class CPPgDirectories;
	friend class CPPgFiles;
	friend class CPPgNotify;
	friend class CPPgIRC;
	friend class Wizard;
	friend class CPPgTweaks;
	friend class CPPgDisplay;
	friend class CPPgSecurity;
	friend class CPPgScheduler;
	friend class CPPgDebug;
	friend class CPPgMorph; //MORPH - Added by SiRoB, Morph Prefs
	friend class CPPgMorph2; //MORPH - Added by SiRoB, Morph Prefs
	//friend class CPPgMorph3; //Commander - Added: Morph III
	friend class CPPgEastShare; //EastShare - Added by Pretender, ES Prefs
	friend class CPPgNTService; // leuk_he run as ntservice

	friend class CPPgStulle; // StulleMule Preferences window - Stulle
	// ==> Design Settings [eWombat/Stulle] - Stulle
#ifdef DESIGN_SETTINGS
	friend class CPPgDesign;
#endif
	// <== Design Settings [eWombat/Stulle] - Stulle
	friend class CSivkaFileSettings; // drop sources - Stulle
	
	CPreferences();
	~CPreferences();

	static	void	Init();
	static	void	Uninit();

	static	LPCTSTR GetTempDir(int id = 0)				{return (LPCTSTR)tempdir.GetAt((id < tempdir.GetCount()) ? id : 0);}
	static	int		GetTempDirCount()					{return tempdir.GetCount();}
	static	bool	CanFSHandleLargeFiles();
	static	LPCTSTR GetConfigFile();
	static	const CString& GetFileCommentsFilePath()	{return m_strFileCommentsFilePath;}
	static	CString	GetMuleDirectory(EDefaultDirectory eDirectory, bool bCreate = true);
	static	void	SetMuleDirectory(EDefaultDirectory eDirectory, CString strNewDir);
	static	void	ChangeUserDirMode(int nNewMode);

	// SLUGFILLER: SafeHash remove - global form of IsTempFile unnececery
	/*
	static	bool	IsTempFile(const CString& rstrDirectory, const CString& rstrName);
	static	bool	IsShareableDirectory(const CString& rstrDirectory);
	static	bool	IsInstallationDirectory(const CString& rstrDir);
	*/
	static	bool	IsConfigFile(const CString& rstrDirectory, const CString& rstrName);
	// SLUGFILLER: SafeHash remove - removed installation dir unsharing

	static	bool	Save();
	static	void	SaveCats();

	static	bool	GetUseServerPriorities()			{return m_bUseServerPriorities;}
	static	bool	GetUseUserSortedServerList()		{return m_bUseUserSortedServerList;}
	static	bool	Reconnect()							{return reconnect;}
	static	const CString& GetUserNick()				{return strNick;}
	static	void	SetUserNick(LPCTSTR pszNick);
	static	int		GetMaxUserNickLength()				{return 50;}

	static	LPCSTR	GetBindAddrA()						{return m_pszBindAddrA; }
	static	LPCWSTR	GetBindAddrW()						{return m_pszBindAddrW; }
    static void      SetBindAddr(CStringW bindip); // MORPH leuk_he bindaddr
	// MORPH START leuk_he upnp bindaddr
	static DWORD	 GetUpnpBindAddr()				{return m_dwUpnpBindAddr; }
    static void      SetUpnpBindAddr(DWORD bindip); 
	static void      SetUpnpBindDhcp(bool BindAddrIsDhcp) {m_bBindAddrIsDhcp=BindAddrIsDhcp;};
	static bool      GetUpnpBindDhcp() {return m_bBindAddrIsDhcp;};
	// MORPH End leuk_he upnp bindaddr


	//MORPH START - Changed by SiRoB, [MoNKi: -UPnPNAT Support-] [MoNKi: -Random Ports-]
	// emulEspa�a: Modified by MoNKi [MoNKi: -UPnPNAT Support-]
	/*
	static	uint16	GetPort()							{return port;}
	static	uint16	GetUDPPort()						{return udpport;}
	*/
		// emulEspa�a: Modified by MoNKi [MoNKi: -Random Ports-]
		/*
		static	uint16	GetPort();
		static	uint16	GetUDPPort();
		*/
		static	uint16	GetPort(bool newPort = false, bool original = false, bool reset = false);
		static	uint16	GetUDPPort(bool newPort = false, bool original = false, bool reset = false);
	//MORPH END   - Changed by SiRoB, [MoNKi: -UPnPNAT Support-] [MoNKi: -Random Ports-]

	static	uint16	GetServerUDPPort()					{return nServerUDPPort;}
	static	uchar*	GetUserHash()						{return userhash;}
	// ZZ:UploadSpeedSense -->
	static	UINT GetMinUpload()	{return minupload;}	  //MORPH uint16 is not enough
	// ZZ:UploadSpeedSense <--
	static	UINT GetMaxUpload()	{return maxupload;} //MORPH uint16 is not enough
	static	bool	IsICHEnabled()						{return ICH;}
	static	bool	GetAutoUpdateServerList()			{return m_bAutoUpdateServerList;}
	static	bool	UpdateNotify()						{return updatenotify;}
	static	bool	GetMinToTray()						{return mintotray;}
	static	bool	DoAutoConnect()						{return autoconnect;}
	static	void	SetAutoConnect(bool inautoconnect)	{autoconnect = inautoconnect;}
	static	bool	GetAddServersFromServer()			{return m_bAddServersFromServer;}
	static	bool	GetAddServersFromClients()			{return m_bAddServersFromClients;}
	static	bool*	GetMinTrayPTR()						{return &mintotray;}
	static	UINT	GetTrafficOMeterInterval()			{return trafficOMeterInterval;}
	static	void	SetTrafficOMeterInterval(UINT in)	{trafficOMeterInterval=in;}
	static	UINT	GetStatsInterval()					{return statsInterval;}
	static	void	SetStatsInterval(UINT in)			{statsInterval=in;}
	static	bool	GetFillGraphs()						{return m_bFillGraphs;}
	static	void	SetFillGraphs(bool bFill)			{m_bFillGraphs = bFill;}

	// -khaos--+++> Many, many, many, many methods.
	static	void	SaveStats(int bBackUp = 0);
	static	void	SetRecordStructMembers();
	static	void	SaveCompletedDownloadsStat();
	static	bool	LoadStats(int loadBackUp = 0);
	static	void	ResetCumulativeStatistics();

   //Xman disable compression
	static bool m_bUseCompression;

	//MORPH Start - Added, Downloaded History [Monki/Xman]
	static bool		m_bHistoryShowShared;
	static bool		GetShowSharedInHistory()		{ return m_bHistoryShowShared; }
	static void		SetShowSharedInHistory(bool on)	{ m_bHistoryShowShared = on; }
	//MORPH END   - Added, Downloaded History [Monki/Xman]

	static	void	Add2DownCompletedFiles()			{cumDownCompletedFiles++;}
	static	void	SetConnMaxAvgDownRate(float in)		{cumConnMaxAvgDownRate = in;}
	static	void	SetConnMaxDownRate(float in)		{cumConnMaxDownRate = in;}
	static	void	SetConnAvgUpRate(float in)			{cumConnAvgUpRate = in;}
	static	void	SetConnMaxAvgUpRate(float in)		{cumConnMaxAvgUpRate = in;}
	static	void	SetConnMaxUpRate(float in)			{cumConnMaxUpRate = in;}
	static	void	SetConnPeakConnections(int in)		{cumConnPeakConnections = in;}
	static	void	SetUpAvgTime(int in)				{cumUpAvgTime = in;}
	static	void	Add2DownSAvgTime(int in)			{sesDownAvgTime += in;}
	static	void	SetDownCAvgTime(int in)				{cumDownAvgTime = in;}
	static	void	Add2ConnTransferTime(int in)		{cumConnTransferTime += in;}
	static	void	Add2ConnDownloadTime(int in)		{cumConnDownloadTime += in;}
	static	void	Add2ConnUploadTime(int in)			{cumConnUploadTime += in;}
	static	void	Add2DownSessionCompletedFiles()		{sesDownCompletedFiles++;}
	static	void	Add2SessionTransferData(UINT uClientID, UINT uClientPort, BOOL bFromPF, BOOL bUpDown, uint32 bytes, bool sentToFriend = false);
	static	void	Add2DownSuccessfulSessions()		{sesDownSuccessfulSessions++;
														 cumDownSuccessfulSessions++;}
	static	void	Add2DownFailedSessions()			{sesDownFailedSessions++;
														 cumDownFailedSessions++;}
	static	void	Add2LostFromCorruption(uint64 in)	{sesLostFromCorruption += in;}
	static	void	Add2SavedFromCompression(uint64 in) {sesSavedFromCompression += in;}
	static	void	Add2SessionPartsSavedByICH(int in)	{sesPartsSavedByICH += in;}

	// Saved stats for cumulative downline overhead
	static	uint64	GetDownOverheadTotal()				{return cumDownOverheadTotal;}
	static	uint64	GetDownOverheadFileReq()			{return cumDownOverheadFileReq;}
	static	uint64	GetDownOverheadSrcEx()				{return cumDownOverheadSrcEx;}
	static	uint64	GetDownOverheadServer()				{return cumDownOverheadServer;}
	static	uint64	GetDownOverheadKad()				{return cumDownOverheadKad;}
	static	uint64	GetDownOverheadTotalPackets()		{return cumDownOverheadTotalPackets;}
	static	uint64	GetDownOverheadFileReqPackets()		{return cumDownOverheadFileReqPackets;}
	static	uint64	GetDownOverheadSrcExPackets()		{return cumDownOverheadSrcExPackets;}
	static	uint64	GetDownOverheadServerPackets()		{return cumDownOverheadServerPackets;}
	static	uint64	GetDownOverheadKadPackets()			{return cumDownOverheadKadPackets;}

	// Saved stats for cumulative upline overhead
	static	uint64	GetUpOverheadTotal()				{return cumUpOverheadTotal;}
	static	uint64	GetUpOverheadFileReq()				{return cumUpOverheadFileReq;}
	static	uint64	GetUpOverheadSrcEx()				{return cumUpOverheadSrcEx;}
	static	uint64	GetUpOverheadServer()				{return cumUpOverheadServer;}
	static	uint64	GetUpOverheadKad()					{return cumUpOverheadKad;}
	static	uint64	GetUpOverheadTotalPackets()			{return cumUpOverheadTotalPackets;}
	static	uint64	GetUpOverheadFileReqPackets()		{return cumUpOverheadFileReqPackets;}
	static	uint64	GetUpOverheadSrcExPackets()			{return cumUpOverheadSrcExPackets;}
	static	uint64	GetUpOverheadServerPackets()		{return cumUpOverheadServerPackets;}
	static	uint64	GetUpOverheadKadPackets()			{return cumUpOverheadKadPackets;}

	// Saved stats for cumulative upline data
	static	uint32	GetUpSuccessfulSessions()			{return cumUpSuccessfulSessions;}
	static	uint32	GetUpFailedSessions()				{return cumUpFailedSessions;}
	static	uint32	GetUpAvgTime()						{return cumUpAvgTime;}

	// Saved stats for cumulative downline data
	static	uint32	GetDownCompletedFiles()				{return cumDownCompletedFiles;}
	static	uint32	GetDownC_SuccessfulSessions()		{return cumDownSuccessfulSessions;}
	static	uint32	GetDownC_FailedSessions()			{return cumDownFailedSessions;}
	static	uint32	GetDownC_AvgTime()					{return cumDownAvgTime;}
	
	// Session download stats
	static	uint32	GetDownSessionCompletedFiles()		{return sesDownCompletedFiles;}
	static	uint32	GetDownS_SuccessfulSessions()		{return sesDownSuccessfulSessions;}
	static	uint32	GetDownS_FailedSessions()			{return sesDownFailedSessions;}
	static	uint32	GetDownS_AvgTime()					{return GetDownS_SuccessfulSessions() ? sesDownAvgTime / GetDownS_SuccessfulSessions() : 0;}

	// Saved stats for corruption/compression
	static	uint64	GetCumLostFromCorruption()			{return cumLostFromCorruption;}
	static	uint64	GetCumSavedFromCompression()		{return cumSavedFromCompression;}
	static	uint64	GetSesLostFromCorruption()			{return sesLostFromCorruption;}
	static	uint64	GetSesSavedFromCompression()		{return sesSavedFromCompression;}
	static	uint32	GetCumPartsSavedByICH()				{return cumPartsSavedByICH;}
	static	uint32	GetSesPartsSavedByICH()				{return sesPartsSavedByICH;}

	// Cumulative client breakdown stats for sent bytes
	static	uint64	GetUpTotalClientData()				{return   GetCumUpData_EDONKEY()
																+ GetCumUpData_EDONKEYHYBRID()
																+ GetCumUpData_EMULE()
																+ GetCumUpData_MLDONKEY()
																+ GetCumUpData_AMULE()
																+ GetCumUpData_EMULECOMPAT()
																+ GetCumUpData_SHAREAZA();}
	static	uint64	GetCumUpData_EDONKEY()				{return (cumUpData_EDONKEY +		sesUpData_EDONKEY );}
	static	uint64	GetCumUpData_EDONKEYHYBRID()		{return (cumUpData_EDONKEYHYBRID +	sesUpData_EDONKEYHYBRID );}
	static	uint64	GetCumUpData_EMULE()				{return (cumUpData_EMULE +			sesUpData_EMULE );}
	static	uint64	GetCumUpData_MLDONKEY()				{return (cumUpData_MLDONKEY +		sesUpData_MLDONKEY );}
	static	uint64	GetCumUpData_AMULE()				{return (cumUpData_AMULE +			sesUpData_AMULE );}
	static	uint64	GetCumUpData_EMULECOMPAT()			{return (cumUpData_EMULECOMPAT +	sesUpData_EMULECOMPAT );}
	static	uint64	GetCumUpData_SHAREAZA()				{return (cumUpData_SHAREAZA +		sesUpData_SHAREAZA );}
	
	// Session client breakdown stats for sent bytes
	static	uint64	GetUpSessionClientData()			{return   sesUpData_EDONKEY 
																+ sesUpData_EDONKEYHYBRID 
																+ sesUpData_EMULE 
																+ sesUpData_MLDONKEY 
																+ sesUpData_AMULE
																+ sesUpData_EMULECOMPAT
																+ sesUpData_SHAREAZA;}
	static	uint64	GetUpData_EDONKEY()					{return sesUpData_EDONKEY;}
	static	uint64	GetUpData_EDONKEYHYBRID()			{return sesUpData_EDONKEYHYBRID;}
	static	uint64	GetUpData_EMULE()					{return sesUpData_EMULE;}
	static	uint64	GetUpData_MLDONKEY()				{return sesUpData_MLDONKEY;}
	static	uint64	GetUpData_AMULE()					{return sesUpData_AMULE;}
	static	uint64	GetUpData_EMULECOMPAT()				{return sesUpData_EMULECOMPAT;}
	static	uint64	GetUpData_SHAREAZA()				{return sesUpData_SHAREAZA;}

	// Cumulative port breakdown stats for sent bytes...
	static	uint64	GetUpTotalPortData()				{return   GetCumUpDataPort_4662() 
																+ GetCumUpDataPort_OTHER()
																+ GetCumUpDataPort_PeerCache();}
	static	uint64	GetCumUpDataPort_4662()				{return (cumUpDataPort_4662 +		sesUpDataPort_4662 );}
	static	uint64	GetCumUpDataPort_OTHER()			{return (cumUpDataPort_OTHER +		sesUpDataPort_OTHER );}
	static	uint64	GetCumUpDataPort_PeerCache()		{return (cumUpDataPort_PeerCache +	sesUpDataPort_PeerCache );}

	// Session port breakdown stats for sent bytes...
	static	uint64	GetUpSessionPortData()				{return   sesUpDataPort_4662 
																+ sesUpDataPort_OTHER
																+ sesUpDataPort_PeerCache;}
	static	uint64	GetUpDataPort_4662()				{return sesUpDataPort_4662;}
	static	uint64	GetUpDataPort_OTHER()				{return sesUpDataPort_OTHER;}
	static	uint64	GetUpDataPort_PeerCache()			{return sesUpDataPort_PeerCache;}

	// Cumulative DS breakdown stats for sent bytes...
	static	uint64	GetUpTotalDataFile()				{return (GetCumUpData_File() +		GetCumUpData_Partfile() );}
	static	uint64	GetCumUpData_File()					{return (cumUpData_File +			sesUpData_File );}
	static	uint64	GetCumUpData_Partfile()				{return (cumUpData_Partfile +		sesUpData_Partfile );}
	// Session DS breakdown stats for sent bytes...
	static	uint64	GetUpSessionDataFile()				{return (sesUpData_File +			sesUpData_Partfile );}
	static	uint64	GetUpData_File()					{return sesUpData_File;}
	static	uint64	GetUpData_Partfile()				{return sesUpData_Partfile;}

	// Cumulative client breakdown stats for received bytes
	static	uint64	GetDownTotalClientData()			{return   GetCumDownData_EDONKEY() 
																+ GetCumDownData_EDONKEYHYBRID() 
																+ GetCumDownData_EMULE() 
																+ GetCumDownData_MLDONKEY() 
																+ GetCumDownData_AMULE()
																+ GetCumDownData_EMULECOMPAT()
																+ GetCumDownData_SHAREAZA()
																+ GetCumDownData_URL();}
	static	uint64	GetCumDownData_EDONKEY()			{return (cumDownData_EDONKEY +			sesDownData_EDONKEY);}
	static	uint64	GetCumDownData_EDONKEYHYBRID()		{return (cumDownData_EDONKEYHYBRID +	sesDownData_EDONKEYHYBRID);}
	static	uint64	GetCumDownData_EMULE()				{return (cumDownData_EMULE +			sesDownData_EMULE);}
	static	uint64	GetCumDownData_MLDONKEY()			{return (cumDownData_MLDONKEY +			sesDownData_MLDONKEY);}
	static	uint64	GetCumDownData_AMULE()				{return (cumDownData_AMULE +			sesDownData_AMULE);}
	static	uint64	GetCumDownData_EMULECOMPAT()		{return (cumDownData_EMULECOMPAT +		sesDownData_EMULECOMPAT);}
	static	uint64	GetCumDownData_SHAREAZA()			{return (cumDownData_SHAREAZA +			sesDownData_SHAREAZA);}
	static	uint64	GetCumDownData_URL()				{return (cumDownData_URL +				sesDownData_URL);}
	
	// Session client breakdown stats for received bytes
	static	uint64	GetDownSessionClientData()			{return   sesDownData_EDONKEY 
																+ sesDownData_EDONKEYHYBRID 
																+ sesDownData_EMULE 
																+ sesDownData_MLDONKEY 
																+ sesDownData_AMULE
																+ sesDownData_EMULECOMPAT
																+ sesDownData_SHAREAZA
																+ sesDownData_URL;}
	static	uint64	GetDownData_EDONKEY()				{return sesDownData_EDONKEY;}
	static	uint64	GetDownData_EDONKEYHYBRID()			{return sesDownData_EDONKEYHYBRID;}
	static	uint64	GetDownData_EMULE()					{return sesDownData_EMULE;}
	static	uint64	GetDownData_MLDONKEY()				{return sesDownData_MLDONKEY;}
	static	uint64	GetDownData_AMULE()					{return sesDownData_AMULE;}
	static	uint64	GetDownData_EMULECOMPAT()			{return sesDownData_EMULECOMPAT;}
	static	uint64	GetDownData_SHAREAZA()				{return sesDownData_SHAREAZA;}
	static	uint64	GetDownData_URL()					{return sesDownData_URL;}

	// Cumulative port breakdown stats for received bytes...
	static	uint64	GetDownTotalPortData()				{return   GetCumDownDataPort_4662() 
																+ GetCumDownDataPort_OTHER()
																+ GetCumDownDataPort_PeerCache();}
	static	uint64	GetCumDownDataPort_4662()			{return cumDownDataPort_4662		+ sesDownDataPort_4662;}
	static	uint64	GetCumDownDataPort_OTHER()			{return cumDownDataPort_OTHER		+ sesDownDataPort_OTHER;}
	static	uint64	GetCumDownDataPort_PeerCache()		{return cumDownDataPort_PeerCache	+ sesDownDataPort_PeerCache;}

	// Session port breakdown stats for received bytes...
	static	uint64	GetDownSessionDataPort()			{return   sesDownDataPort_4662 
																+ sesDownDataPort_OTHER
																+ sesDownDataPort_PeerCache;}
	static	uint64	GetDownDataPort_4662()				{return sesDownDataPort_4662;}
	static	uint64	GetDownDataPort_OTHER()				{return sesDownDataPort_OTHER;}
	static	uint64	GetDownDataPort_PeerCache()			{return sesDownDataPort_PeerCache;}

	// Saved stats for cumulative connection data
	static	float	GetConnAvgDownRate()				{return cumConnAvgDownRate;}
	static	float	GetConnMaxAvgDownRate()				{return cumConnMaxAvgDownRate;}
	static	float	GetConnMaxDownRate()				{return cumConnMaxDownRate;}
	static	float	GetConnAvgUpRate()					{return cumConnAvgUpRate;}
	static	float	GetConnMaxAvgUpRate()				{return cumConnMaxAvgUpRate;}
	static	float	GetConnMaxUpRate()					{return cumConnMaxUpRate;}
	static	time_t	GetConnRunTime()					{return cumConnRunTime;}
	static	uint32	GetConnNumReconnects()				{return cumConnNumReconnects;}
	static	uint32	GetConnAvgConnections()				{return cumConnAvgConnections;}
	static	uint32	GetConnMaxConnLimitReached()		{return cumConnMaxConnLimitReached;}
	static	uint32	GetConnPeakConnections()			{return cumConnPeakConnections;}
	static	uint32	GetConnTransferTime()				{return cumConnTransferTime;}
	static	uint32	GetConnDownloadTime()				{return cumConnDownloadTime;}
	static	uint32	GetConnUploadTime()					{return cumConnUploadTime;}
	static	uint32	GetConnServerDuration()				{return cumConnServerDuration;}

	// Saved records for servers / network
	static	uint32	GetSrvrsMostWorkingServers()		{return cumSrvrsMostWorkingServers;}
	static	uint32	GetSrvrsMostUsersOnline()			{return cumSrvrsMostUsersOnline;}
	static	uint32	GetSrvrsMostFilesAvail()			{return cumSrvrsMostFilesAvail;}

	// Saved records for shared files
	static	uint32	GetSharedMostFilesShared()			{return cumSharedMostFilesShared;}
	static	uint64	GetSharedLargestShareSize()			{return cumSharedLargestShareSize;}
	static	uint64	GetSharedLargestAvgFileSize()		{return cumSharedLargestAvgFileSize;}
	static	uint64	GetSharedLargestFileSize()			{return cumSharedLargestFileSize;}

	// Get the long date/time when the stats were last reset
	static	time_t GetStatsLastResetLng()				{return stat_datetimeLastReset;}
	static	CString GetStatsLastResetStr(bool formatLong = true);
	static	UINT	GetStatsSaveInterval()				{return statsSaveInterval;}

	// Get and Set our new preferences
	static	void	SetStatsMax(UINT in)				{statsMax = in;}
	static	void	SetStatsConnectionsGraphRatio(UINT in) {statsConnectionsGraphRatio = in;}
	static	UINT	GetStatsConnectionsGraphRatio()		{return statsConnectionsGraphRatio;}
	static	void	SetExpandedTreeItems(CString in)	{m_strStatsExpandedTreeItems = in;}
	static	const CString &GetExpandedTreeItems()		{return m_strStatsExpandedTreeItems;}

	static	uint64	GetTotalDownloaded()				{return totalDownloadedBytes;}
	static	uint64	GetTotalUploaded()					{return totalUploadedBytes;}

	static	bool	IsErrorBeepEnabled()				{return beepOnError;}
	static	bool	IsConfirmExitEnabled()				{return confirmExit;}
	static	bool	UseSplashScreen()					{return splashscreen;}
	static  bool	UseStartupSound()			{return startupsound;}//Commander - Added: Enable/Disable Startupsound
	static  bool	UseSideBanner()			    {return sidebanner;}//Commander - Added: Side Banner	
	static	bool	FilterLANIPs()						{return filterLANIPs;}
	static	bool	GetAllowLocalHostIP()				{return m_bAllocLocalHostIP;}
	static	bool	IsOnlineSignatureEnabled()			{return onlineSig;}
	static	int		GetMaxGraphUploadRate(bool bEstimateIfUnlimited);
	static	int		GetMaxGraphDownloadRate()			{return maxGraphDownloadRate;}
	static	void	SetMaxGraphUploadRate(int in);
	static	void	SetMaxGraphDownloadRate(int in)		{maxGraphDownloadRate=(in)?in:96;}

	static	UINT 	GetMaxDownload();	//MORPH uint16 is not enough
	static	uint64	GetMaxDownloadInBytesPerSec(bool dynamic = false);
	static	UINT	GetMaxConnections()					{return maxconnections;}
	static	UINT	GetMaxHalfConnections()				{return maxhalfconnections;}
	static	UINT	GetMaxSourcePerFileDefault()		{return maxsourceperfile;}
	static	UINT	GetDeadServerRetries()				{return m_uDeadServerRetries;}
	static	DWORD	GetServerKeepAliveTimeout()			{return m_dwServerKeepAliveTimeout;}
	static	bool	GetConditionalTCPAccept()			{return m_bConditionalTCPAccept;}

	static	WORD	GetLanguageID();
	static	void	SetLanguageID(WORD lid);
	static	void	GetLanguages(CWordArray& aLanguageIDs);
	static	void	SetLanguage();
	static	bool	IsLanguageSupported(LANGID lidSelected, bool bUpdateBefore);
	static	CString GetLangDLLNameByID(LANGID lidSelected);
	static	void	InitThreadLocale();
	static	void	SetRtlLocale(LCID lcid);
	static	CString GetHtmlCharset();

	static	bool	IsDoubleClickEnabled()				{return transferDoubleclick;}
	static	EViewSharedFilesAccess CanSeeShares(void)	{return m_iSeeShares;}
	static	UINT	GetToolTipDelay(void)				{return m_iToolDelayTime;}
	static	bool	IsBringToFront()					{return bringtoforeground;}

	static	UINT	GetSplitterbarPosition()			{return splitterbarPosition;}
	static	void	SetSplitterbarPosition(UINT pos)	{splitterbarPosition=pos;}
	static	UINT	GetSplitterbarPositionServer()		{return splitterbarPositionSvr;}
	static	void	SetSplitterbarPositionServer(UINT pos)	{splitterbarPositionSvr=pos;}
	static	UINT	GetTransferWnd1()					{return m_uTransferWnd1;}
	static	void	SetTransferWnd1(UINT uWnd1)			{m_uTransferWnd1 = uWnd1;}
	static	UINT	GetTransferWnd2()					{return m_uTransferWnd2;}
	static	void	SetTransferWnd2(UINT uWnd2)			{m_uTransferWnd2 = uWnd2;}
	//MORPH START - Added by SiRoB, Splitting Bar [O�]
	static	UINT	GetSplitterbarPositionStat()		{return splitterbarPositionStat;}
	static	void	SetSplitterbarPositionStat(UINT pos) {splitterbarPositionStat=pos;}
	static	UINT	GetSplitterbarPositionStat_HL()		{return splitterbarPositionStat_HL;}
	static	void	SetSplitterbarPositionStat_HL(UINT pos) {splitterbarPositionStat_HL=pos;}
	static	UINT	GetSplitterbarPositionStat_HR()		{return splitterbarPositionStat_HR;}
	static	void	SetSplitterbarPositionStat_HR(UINT pos) {splitterbarPositionStat_HR=pos;}
	static	UINT	GetSplitterbarPositionFriend()		{return splitterbarPositionFriend;}
	static	void	SetSplitterbarPositionFriend(UINT pos) {splitterbarPositionFriend=pos;}
	static	UINT	GetSplitterbarPositionIRC()			{return splitterbarPositionIRC;}
	static	void	SetSplitterbarPositionIRC(UINT pos) {splitterbarPositionIRC=pos;}
	static	UINT	GetSplitterbarPositionShared()		{return splitterbarPositionShared;}
	static	void	SetSplitterbarPositionShared(UINT pos) {splitterbarPositionShared=pos;}
	//MORPH END   - Added by SiRoB, Splitting Bar [O�]
	// -khaos--+++> Changed datatype to avoid overflows
	static	UINT	GetStatsMax()						{return statsMax;}
	// <-----khaos-
	static	bool	UseFlatBar()						{return (depth3D==0);}
	static	int		GetStraightWindowStyles()			{return m_iStraightWindowStyles;}
	static  bool	GetUseSystemFontForMainControls()	{return m_bUseSystemFontForMainControls;}

	static	const CString& GetSkinProfile()				{return m_strSkinProfile;}
	static	void	SetSkinProfile(LPCTSTR pszProfile)	{m_strSkinProfile = pszProfile;}

	static	UINT	GetStatsAverageMinutes()			{return statsAverageMinutes;}
	static	void	SetStatsAverageMinutes(UINT in)	{statsAverageMinutes=in;}

	static	const CString& GetNotifierConfiguration()	{return notifierConfiguration;}
	static	void	SetNotifierConfiguration(LPCTSTR pszConfigPath) {notifierConfiguration = pszConfigPath;}
	static	bool	GetNotifierOnDownloadFinished()		{return notifierOnDownloadFinished;}
	static	bool	GetNotifierOnNewDownload()			{return notifierOnNewDownload;}
	static	bool	GetNotifierOnChat()					{return notifierOnChat;}
	static	bool	GetNotifierOnLog()					{return notifierOnLog;}
	static	bool	GetNotifierOnImportantError()		{return notifierOnImportantError;}
	static	bool	GetNotifierOnEveryChatMsg()			{return notifierOnEveryChatMsg;}
	static	bool	GetNotifierOnNewVersion()			{return notifierOnNewVersion;}
	static	ENotifierSoundType GetNotifierSoundType()	{return notifierSoundType;}
	static	const CString& GetNotifierSoundFile()		{return notifierSoundFile;}

	static	bool	GetEnableMiniMule()					{return m_bEnableMiniMule;}
	static	bool	GetRTLWindowsLayout()				{return m_bRTLWindowsLayout;}

	static	CString GetIRCNick()						{return m_strIRCNick;}
	static	void	SetIRCNick(LPCTSTR pszNick)			{m_strIRCNick = pszNick;}
	static	CString GetIRCServer()						{return m_strIRCServer;}
	static	bool	GetIRCAddTimeStamp()				{return m_bIRCAddTimeStamp;}
	static	bool	GetIRCUseChannelFilter()			{return m_bIRCUseChannelFilter;}
	static	CString GetIRCChannelFilter()				{return m_strIRCChannelFilter;}
	static	UINT	GetIRCChannelUserFilter()			{return m_uIRCChannelUserFilter;}
	static	bool	GetIRCUsePerform()					{return m_bIRCUsePerform;}
	static	CString GetIRCPerformString()				{return m_strIRCPerformString;}
	static	bool	GetIRCJoinHelpChannel()				{return m_bIRCJoinHelpChannel;}
	static	bool	GetIRCGetChannelsOnConnect()		{return m_bIRCGetChannelsOnConnect;}
	static	bool	GetIRCPlaySoundEvents()				{return m_bIRCPlaySoundEvents;}
	static	bool	GetIRCIgnoreMiscMessages()			{return m_bIRCIgnoreMiscMessages;}
	static	bool	GetIRCIgnoreJoinMessages()			{return m_bIRCIgnoreJoinMessages;}
	static	bool	GetIRCIgnorePartMessages()			{return m_bIRCIgnorePartMessages;}
	static	bool	GetIRCIgnoreQuitMessages()			{return m_bIRCIgnoreQuitMessages;}
	static	bool	GetIRCIgnoreEmuleAddFriendMsgs()	{return m_bIRCIgnoreEmuleAddFriendMsgs;}
	static	bool	GetIRCIgnoreEmuleSendLinkMsgs()		{return m_bIRCIgnoreEmuleSendLinkMsgs;}
	static	bool	GetIRCAllowEmuleAddFriend()			{return m_bIRCAllowEmuleAddFriend;}
	static	bool	GetIRCAcceptLinks()					{return m_bIRCAcceptLinks;}
	static	bool	GetIRCAcceptLinksFriendsOnly()		{return m_bIRCAcceptLinksFriendsOnly;}
	static	bool	GetIRCEnableSmileys()				{return m_bIRCEnableSmileys;}
	static	bool	GetMessageEnableSmileys()			{return m_bMessageEnableSmileys;}

	static	WORD	GetWindowsVersion();
	static  bool	IsRunningAeroGlassTheme();
	static	bool	GetStartMinimized()					{return startMinimized;}
	static	void	SetStartMinimized( bool instartMinimized) {startMinimized = instartMinimized;}
	static	bool	GetAutoStart()						{return m_bAutoStart;}
	static	void	SetAutoStart( bool val)				{m_bAutoStart = val;}

	static	bool	GetRestoreLastMainWndDlg()			{return m_bRestoreLastMainWndDlg;}
	static	int		GetLastMainWndDlgID()				{return m_iLastMainWndDlgID;}
	static	void	SetLastMainWndDlgID(int iID)		{m_iLastMainWndDlgID = iID;}

	static	bool	GetRestoreLastLogPane()				{return m_bRestoreLastLogPane;}
	static	int		GetLastLogPaneID()					{return m_iLastLogPaneID;}
	static	void	SetLastLogPaneID(int iID)			{m_iLastLogPaneID = iID;}

	static	bool	GetSmartIdCheck()					{return m_bSmartServerIdCheck;}
	static	void	SetSmartIdCheck(bool in_smartidcheck) {m_bSmartServerIdCheck = in_smartidcheck;}
	static	uint8	GetSmartIdState()					{return smartidstate;}
	static	void	SetSmartIdState(uint8 in_smartidstate) {smartidstate = in_smartidstate;}
	//MORPH START - Added by SiRoB, XML News [O�]
	static	bool	GetNews()							{return enableNEWS;}
	//MORPH END   - Added by SiRoB, XML News [O�]
	static	bool	GetPreviewPrio()					{return m_bpreviewprio;}
	static	void	SetPreviewPrio(bool in)				{m_bpreviewprio=in;}
	static	bool	GetUpdateQueueList()				{return m_bupdatequeuelist;}
	static	bool	GetManualAddedServersHighPriority()	{return m_bManualAddedServersHighPriority;}
	static	bool	TransferFullChunks()				{return m_btransferfullchunks;}
	static	void	SetTransferFullChunks( bool m_bintransferfullchunks )				{m_btransferfullchunks = m_bintransferfullchunks;}
	static	int		StartNextFile()						{return m_istartnextfile;}
	static	bool	ShowOverhead()						{return m_bshowoverhead;}
	static	void	SetNewAutoUp(bool m_bInUAP)			{m_bUAP = m_bInUAP;}
	static	bool	GetNewAutoUp()						{return m_bUAP;}
	static	void	SetNewAutoDown(bool m_bInDAP)		{m_bDAP = m_bInDAP;}
	static	bool	GetNewAutoDown()					{return m_bDAP;}
	static	bool	IsKnownClientListDisabled()			{return m_bDisableKnownClientList;}
	static	bool	IsQueueListDisabled()				{return m_bDisableQueueList;}
	static	bool	IsFirstStart()						{return m_bFirstStart;}
	static	bool	UseCreditSystem()					{return m_bCreditSystem;}
	static	void	SetCreditSystem(bool m_bInCreditSystem) {m_bCreditSystem = m_bInCreditSystem;}

	static	const CString& GetTxtEditor()				{return m_strTxtEditor;}
	static	const CString& GetVideoPlayer()				{return m_strVideoPlayer;}
	static	const CString& GetVideoPlayerArgs()			{return m_strVideoPlayerArgs;}

	static	UINT	GetFileBufferSize()					{return m_iFileBufferSize;}
	static	UINT	GetFileBufferTimeLimit()			{return m_uFileBufferTimeLimit;}
	static	UINT	GetQueueSize()						{return m_iQueueSize;}
	static	int		GetCommitFiles()					{return m_iCommitFiles;}
	static	bool	GetShowCopyEd2kLinkCmd()			{return m_bShowCopyEd2kLinkCmd;}

	// Barry
	static	UINT	Get3DDepth()						{return depth3D;}
	static	bool	AutoTakeED2KLinks()					{return autotakeed2klinks;}
	static	bool	AddNewFilesPaused()					{return addnewfilespaused;}

	static	bool	TransferlistRemainSortStyle()		{return m_bTransflstRemain;}
	static	void	TransferlistRemainSortStyle(bool in){m_bTransflstRemain=in;}

	static	DWORD	GetStatsColor(int index)			{return m_adwStatsColors[index];}
	static	void	SetStatsColor(int index, DWORD value){m_adwStatsColors[index] = value;}
	static	int		GetNumStatsColors()					{return ARRSIZE(m_adwStatsColors);}
	static	void	GetAllStatsColors(int iCount, LPDWORD pdwColors);
	static	bool	SetAllStatsColors(int iCount, const DWORD* pdwColors);
	static	void	ResetStatsColor(int index);

	static	void	SetMaxConsPerFive(UINT in)			{MaxConperFive=in;}
	static	LPLOGFONT GetHyperTextLogFont()				{return &m_lfHyperText;}
	static	void	SetHyperTextFont(LPLOGFONT plf)		{m_lfHyperText = *plf;}
	static	LPLOGFONT GetLogFont()						{return &m_lfLogText;}
	static	void	SetLogFont(LPLOGFONT plf)			{m_lfLogText = *plf;}
	static	COLORREF GetLogErrorColor()					{return m_crLogError;}
	static	COLORREF GetLogWarningColor()				{return m_crLogWarning;}
	static	COLORREF GetLogSuccessColor()				{return m_crLogSuccess;}
	//MORPH START - Added by SiRoB, Upload Splitting Class
	static	COLORREF GetLogUSCColor()					{return m_crLogUSC;}
	//MORPH END   - Added by SiRoB, Upload Splitting Class

	static	UINT	GetMaxConperFive()					{return MaxConperFive;}
	static	UINT	GetDefaultMaxConperFive();

	static	bool	IsSafeServerConnectEnabled()		{return m_bSafeServerConnect;}
	static	void	SetSafeServerConnectEnabled(bool in){m_bSafeServerConnect=in;}
	static	bool	IsMoviePreviewBackup()				{return moviePreviewBackup;}
	static	int		GetPreviewSmallBlocks()				{return m_iPreviewSmallBlocks;}
	static	bool	GetPreviewCopiedArchives()			{return m_bPreviewCopiedArchives;}
	static	int		GetInspectAllFileTypes()			{return m_iInspectAllFileTypes;}
	static	int		GetExtractMetaData()				{return m_iExtractMetaData;}
	static	bool	GetAdjustNTFSDaylightFileTime()		{return m_bAdjustNTFSDaylightFileTime;}
	static	bool	GetRearrangeKadSearchKeywords()		{return m_bRearrangeKadSearchKeywords;}

	static	const CString& GetYourHostname()			{return m_strYourHostname;}
	static	void	SetYourHostname(LPCTSTR pszHostname){m_strYourHostname = pszHostname;}
	static	bool	IsCheckDiskspaceEnabled()			{return checkDiskspace;}
	static	UINT	GetMinFreeDiskSpace()				{return m_uMinFreeDiskSpace;}
	static	bool	GetSparsePartFiles();
	static	void	SetSparsePartFiles(bool bEnable)	{m_bSparsePartFiles = bEnable;}
	static	bool	GetResolveSharedShellLinks()		{return m_bResolveSharedShellLinks;}

	static	void	SetMaxUpload(UINT in);
	static	void	SetMaxDownload(UINT in);

	static	WINDOWPLACEMENT GetEmuleWindowPlacement()	{return EmuleWindowPlacement;}
	static	void	SetWindowLayout(WINDOWPLACEMENT in) {EmuleWindowPlacement=in;}

	static	bool	GetAutoConnectToStaticServersOnly() {return m_bAutoConnectToStaticServersOnly;}
	static	UINT	GetUpdateDays()						{return versioncheckdays;}
	static	time_t	GetLastVC()				{return versioncheckLastAutomatic;} //vs2005
	static	void	UpdateLastVC();
	//MORPH START - Added by SiRoB, New Version check
	static	uint32	GetLastMVC()				{return mversioncheckLastAutomatic;}
	static	void	UpdateLastMVC();
	//MORPH END   - Added by SiRoB, New Version check
	static	int		GetIPFilterLevel()					{return filterlevel;}
	static	const CString& GetMessageFilter()			{return messageFilter;}
	static	const CString& GetCommentFilter()			{return commentFilter;}
	static	void	SetCommentFilter(const CString& strFilter) {commentFilter = strFilter;}
	static	const CString& GetFilenameCleanups()		{return filenameCleanups;}

	static	bool	ShowRatesOnTitle()					{return showRatesInTitle;}
	static	void	LoadCats();
	static	const CString& GetDateTimeFormat()			{return m_strDateTimeFormat;}
	static	const CString& GetDateTimeFormat4Log()		{return m_strDateTimeFormat4Log;}
	static	const CString& GetDateTimeFormat4Lists()	{return m_strDateTimeFormat4Lists;}

	// Download Categories (Ornis)
	static	int		AddCat(Category_Struct* cat)		{catMap.Add(cat); return catMap.GetCount()-1;}
	static	bool	MoveCat(UINT from, UINT to);
	static	void	RemoveCat(int index);
	static	int		GetCatCount()						{return catMap.GetCount();}
	/*// khaos::kmod+ Obsolete 
	static  bool	SetCatFilter(int index, int filter);
	static  int		GetCatFilter(int index);
	static	bool	GetCatFilterNeg(int index);
	static	void	SetCatFilterNeg(int index, bool val);
	*/
	static	Category_Struct* GetCategory(int index)		{if (index>=0 && index<catMap.GetCount()) return catMap.GetAt(index); else return NULL;}
	static	const CString &GetCatPath(int index)		{return catMap.GetAt(index)->strIncomingPath;}
	static	DWORD	GetCatColor(int index, int nDefault = COLOR_BTNTEXT);

	static	bool	GetPreviewOnIconDblClk()			{return m_bPreviewOnIconDblClk;}
	static	bool	GetCheckFileOpen()					{return m_bCheckFileOpen;}
	static	bool	ShowRatingIndicator()				{return indicateratings;}
	static	bool	WatchClipboard4ED2KLinks()			{return watchclipboard;}
	static	bool	GetRemoveToBin()					{return m_bRemove2bin;}
	static	bool	GetFilterServerByIP()				{return filterserverbyip;}

	static	bool	GetLog2Disk()						{return log2disk;}
	static	bool	GetDebug2Disk()						{return m_bVerbose && debug2disk;}
	static	int		GetMaxLogBuff()						{return iMaxLogBuff;}
	static	UINT	GetMaxLogFileSize()					{return uMaxLogFileSize;}
	static	ELogFileFormat GetLogFileFormat()			{return m_iLogFileFormat;}

	static int      GetServiceStartupMode(); // MORPH leuk_he:run as ntservice v1..

	// WebServer
	/*
	static	uint16	GetWSPort()							{return m_nWebPort;}
	*/
	static	uint16	GetWSPort();							// MORPH leuk_he:run as ntservice v1..: may be required before init! 
#ifdef USE_OFFICIAL_UPNP
	static	bool	GetWSUseUPnP()						{return m_bWebUseUPnP && GetWSIsEnabled();}
#endif
	static	void	SetWSPort(uint16 uPort)				{m_nWebPort=uPort;}
	//>>> [ionix] - iONiX::Advanced WebInterface Account Management
	static	bool	UseIonixWebsrv()						{ return m_bIonixWebsrv; }
	//<<< [ionix] - iONiX::Advanced WebInterface Account Management
	static	const CString& GetWSPass()					{return m_strWebPassword;}
	static	void	SetWSPass(CString strNewPass);
	static	bool	GetWSIsEnabled()					{return m_bWebEnabled;}
	static	void	SetWSIsEnabled(bool bEnable)		{m_bWebEnabled=bEnable;}
	static	bool	GetWebUseGzip()						{return m_bWebUseGzip;}
	static	void	SetWebUseGzip(bool bUse)			{m_bWebUseGzip=bUse;}
	static	int		GetWebPageRefresh()					{return m_nWebPageRefresh;}
	static	void	SetWebPageRefresh(int nRefresh)		{m_nWebPageRefresh=nRefresh;}
	static	bool	GetWSIsLowUserEnabled()				{return m_bWebLowEnabled;}
	static	void	SetWSIsLowUserEnabled(bool in)		{m_bWebLowEnabled=in;}
	static	const CString& GetWSLowPass()				{return m_strWebLowPassword;}
	static	int		GetWebTimeoutMins()					{return m_iWebTimeoutMins;}
	static  bool	GetWebAdminAllowedHiLevFunc()		{return m_bAllowAdminHiLevFunc;}
	static	void	SetWSLowPass(CString strNewPass);
	static  const CUIntArray& GetAllowedRemoteAccessIPs(){return m_aAllowedRemoteAccessIPs;}
	static	uint32	GetMaxWebUploadFileSizeMB()			{return m_iWebFileUploadSizeLimitMB;}

	static	void	SetMaxSourcesPerFile(UINT in)		{maxsourceperfile=in;}
	static	void	SetMaxConnections(UINT in)			{maxconnections =in;}
	static	void	SetMaxHalfConnections(UINT in)		{maxhalfconnections =in;}
	static	bool	IsSchedulerEnabled()				{return scheduler;}
	static	void	SetSchedulerEnabled(bool in)		{scheduler=in;}
	static	bool	GetDontCompressAvi()				{return dontcompressavi;}

	static	bool	MsgOnlyFriends()					{return msgonlyfriends;}
	static	bool	MsgOnlySecure()						{return msgsecure;}
	static	UINT	GetMsgSessionsMax()					{return maxmsgsessions;}
	static	bool	IsSecureIdentEnabled()				{return m_bUseSecureIdent;} // use clientcredits->CryptoAvailable() to check if crypting is really available and not this function
	static	bool	IsAdvSpamfilterEnabled()			{return m_bAdvancedSpamfilter;}
	static	bool	IsChatCaptchaEnabled()				{return IsAdvSpamfilterEnabled() && m_bUseChatCaptchas;}
	static	const CString& GetTemplate()				{return m_strTemplateFile;}
	static	void	SetTemplate(CString in)				{m_strTemplateFile = in;}
	static	bool	GetNetworkKademlia()				{return networkkademlia && udpport > 0;}
	static	void	SetNetworkKademlia(bool val);
	static	bool	GetNetworkED2K()					{return networked2k;}
	static	void	SetNetworkED2K(bool val)			{networked2k = val;}

	// mobileMule
	static	const CString& GetMMPass()					{return m_strMMPassword;}
	static	void	SetMMPass(CString strNewPass);
	static	bool	IsMMServerEnabled()					{return m_bMMEnabled;}
	static	void	SetMMIsEnabled(bool bEnable)		{m_bMMEnabled=bEnable;}
	static	uint16	GetMMPort()							{return m_nMMPort;}
	static	void	SetMMPort(uint16 uPort)				{m_nMMPort=uPort;}

	// deadlake PROXYSUPPORT
	static	const ProxySettings& GetProxySettings()		{return proxy;}
	static	void	SetProxySettings(const ProxySettings& proxysettings) {proxy = proxysettings;}

	static	bool	ShowCatTabInfos()					{return showCatTabInfos;}
	static	void	ShowCatTabInfos(bool in)			{showCatTabInfos=in;}

	static	bool	AutoFilenameCleanup()				{return autofilenamecleanup;}
	static	void	AutoFilenameCleanup(bool in)		{autofilenamecleanup=in;}
	static	void	SetFilenameCleanups(CString in)		{filenameCleanups=in;}

	static	bool	GetResumeSameCat()					{return resumeSameCat;}
	static	bool	IsGraphRecreateDisabled()			{return dontRecreateGraphs;}
	static	bool	IsExtControlsEnabled()				{return m_bExtControls;}
	static	void	SetExtControls(bool in)				{m_bExtControls=in;}
	static	bool	GetRemoveFinishedDownloads()		{return m_bRemoveFinishedDownloads;}
	// MORPH START show less controls
	static	bool	IsLessControls()						   { return m_bShowLessControls;}
	static  bool    SetLessControls(bool newvalue);
	// MORPH START show less controls 

	static	UINT	GetMaxChatHistoryLines()			{return m_iMaxChatHistory;}
	static	bool	GetUseAutocompletion()				{return m_bUseAutocompl;}
	static	bool	GetUseDwlPercentage()				{return m_bShowDwlPercentage;}
	static	void	SetUseDwlPercentage(bool in)		{m_bShowDwlPercentage=in;}
	// ==> Design Settings [eWombat/Stulle] - Stulle
#ifndef DESIGN_SETTINGS
	static	bool	GetShowActiveDownloadsBold()		{return m_bShowActiveDownloadsBold;}
#endif
	// <== Design Settings [eWombat/Stulle] - Stulle

    //Commander - Added: Client Percentage - Start
	static	bool	GetUseClientPercentage()					{ return m_bShowClientPercentage;}
	static	void	SetUseClientPercentage(bool in)				{ m_bShowClientPercentage=in;}
	//Commander - Added: Client Percentage - End

	//MORPH START - Added by Commander, ClientQueueProgressBar
	static bool ShowClientQueueProgressBar()					{ return m_bClientQueueProgressBar;}
    //MORPH END - Added by Commander, ClientQueueProgressBar

	//MORPH START - Added by Commander, FolderIcons
	static bool ShowFolderIcons()								{ return m_bShowFolderIcons;}
	//MORPH END - Added by Commander, FolderIcons

	//Toolbar
	static	const CString& GetToolbarSettings()					{return m_sToolbarSettings;}
	static	void	SetToolbarSettings(const CString& in)		{m_sToolbarSettings = in;}
	static	const CString& GetToolbarBitmapSettings()			{return m_sToolbarBitmap;}
	static	void	SetToolbarBitmapSettings(const CString& path){m_sToolbarBitmap = path;}
	static	EToolbarLabelType GetToolbarLabelSettings()			{return m_nToolbarLabels;}
	static	void	SetToolbarLabelSettings(EToolbarLabelType eLabelType) {m_nToolbarLabels = eLabelType;}
	static	bool	GetReBarToolbar()							{return m_bReBarToolbar;}
	static	bool	GetUseReBarToolbar();
	static	CSize	GetToolbarIconSize()				{return m_sizToolbarIconSize;}
	static	void	SetToolbarIconSize(CSize siz)		{m_sizToolbarIconSize = siz;}

	static	bool	IsTransToolbarEnabled()				{return m_bWinaTransToolbar;}

	static	int		GetSearchMethod()					{return m_iSearchMethod;}
	static	void	SetSearchMethod(int iMethod)		{m_iSearchMethod = iMethod;}

	// ZZ:UploadSpeedSense -->
	static	bool	IsDynUpEnabled();
	static	void	SetDynUpEnabled(bool newValue)		{m_bDynUpEnabled = newValue;}
	static	int		GetDynUpPingTolerance()				{return m_iDynUpPingTolerance;}
	static	int		GetDynUpGoingUpDivider()			{return m_iDynUpGoingUpDivider;}
	static	int		GetDynUpGoingDownDivider()			{return m_iDynUpGoingDownDivider;}
	static	int		GetDynUpNumberOfPings()				{return m_iDynUpNumberOfPings;}
    static  bool	IsDynUpUseMillisecondPingTolerance(){return m_bDynUpUseMillisecondPingTolerance;} // EastShare - Added by TAHO, USS limit
	static  int		GetDynUpPingToleranceMilliseconds() {return m_iDynUpPingToleranceMilliseconds;} // EastShare - Added by TAHO, USS limit
	static  void	SetDynUpPingToleranceMilliseconds(int in){m_iDynUpPingToleranceMilliseconds = in;}
	// ZZ:UploadSpeedSense <--

    static bool     GetA4AFSaveCpu()                    {return m_bA4AFSaveCpu;} // ZZ:DownloadManager

    static bool     GetHighresTimer()                   {return m_bHighresTimer;}

	static	CString	GetHomepageBaseURL()				{return GetHomepageBaseURLForLevel(GetWebMirrorAlertLevel());}
	static	CString	GetVersionCheckBaseURL();					
	static	void	SetWebMirrorAlertLevel(uint8 newValue){m_nWebMirrorAlertLevel = newValue;}
	static	bool	IsDefaultNick(const CString strCheck);
	static	UINT	GetWebMirrorAlertLevel();
	static	bool	UseSimpleTimeRemainingComputation()	{return m_bUseOldTimeRemaining;}

	static	bool	IsRunAsUserEnabled();
	static	bool	IsPreferingRestrictedOverUser()		{return m_bPreferRestrictedOverUser;}

	// PeerCache
	static	bool	IsPeerCacheDownloadEnabled()		{return (m_bPeerCacheEnabled && !IsClientCryptLayerRequested());}
	static	uint32	GetPeerCacheLastSearch()			{return m_uPeerCacheLastSearch;}
	static	bool	WasPeerCacheFound()					{return m_bPeerCacheWasFound;}
	static	void	SetPeerCacheLastSearch(uint32 dwLastSearch) {m_uPeerCacheLastSearch = dwLastSearch;}
	static	void	SetPeerCacheWasFound(bool bFound)	{m_bPeerCacheWasFound = bFound;}
	static	uint16	GetPeerCachePort()					{return m_nPeerCachePort;}
	static	void	SetPeerCachePort(uint16 nPort)		{m_nPeerCachePort = nPort;}
	static	bool	GetPeerCacheShow()					{return m_bPeerCacheShow;}

	// Verbose log options
	static	bool	GetEnableVerboseOptions()			{return m_bEnableVerboseOptions;}
	static	bool	GetVerbose()						{return m_bVerbose;}
	static	bool	GetFullVerbose()					{return m_bVerbose && m_bFullVerbose;}
	static	bool	GetDebugSourceExchange()			{return m_bVerbose && m_bDebugSourceExchange;}
	static	bool	GetLogBannedClients()				{return m_bVerbose && m_bLogBannedClients;}
	static	bool	GetLogRatingDescReceived()			{return m_bVerbose && m_bLogRatingDescReceived;}
	static	bool	GetLogSecureIdent()					{return m_bVerbose && m_bLogSecureIdent;}
	static	bool	GetLogFilteredIPs()					{return m_bVerbose && m_bLogFilteredIPs;}
	static	bool	GetLogFileSaving()					{return m_bVerbose && m_bLogFileSaving;}
    static	bool	GetLogA4AF()    					{return m_bVerbose && m_bLogA4AF;} // ZZ:DownloadManager
	static	bool	GetLogUlDlEvents()					{return m_bVerbose && m_bLogUlDlEvents;}
	static	bool	GetLogKadSecurityEvents()			{return m_bVerbose && true;}
	static	bool	GetLogICHEvents()					{return m_bVerbose && m_bLogICHEvents;}//JP log ICH events
	static	bool	GetUseDebugDevice()					{return m_bUseDebugDevice;}
	static	int		GetDebugServerTCPLevel()			{return m_iDebugServerTCPLevel;}
	static	int		GetDebugServerUDPLevel() 			{return m_iDebugServerUDPLevel;}
	static	int		GetDebugServerSourcesLevel()		{return m_iDebugServerSourcesLevel;}
	static	int		GetDebugServerSearchesLevel()		{return m_iDebugServerSearchesLevel;}
	static	int		GetDebugClientTCPLevel()			{return m_iDebugClientTCPLevel;}
	static	int		GetDebugClientUDPLevel()			{return m_iDebugClientUDPLevel;}
	static	int		GetDebugClientKadUDPLevel()			{return m_iDebugClientKadUDPLevel;}
	static	int		GetDebugSearchResultDetailLevel()	{return m_iDebugSearchResultDetailLevel;}
	static	int		GetVerboseLogPriority()				{return	m_byLogLevel;}

	// Firewall settings
	static  bool	IsOpenPortsOnStartupEnabled()		{return m_bOpenPortsOnStartUp;}
	
	//AICH Hash
	static	bool	IsTrustingEveryHash()				{return m_bTrustEveryHash;} // this is a debug option

	static	bool	IsRememberingDownloadedFiles()		{return m_bRememberDownloadedFiles;}
	static	bool	IsRememberingCancelledFiles()		{return m_bRememberCancelledFiles;}
	static  bool	DoPartiallyPurgeOldKnownFiles()		{return m_bPartiallyPurgeOldKnownFiles;}
	static	void	SetRememberDownloadedFiles(bool nv)	{m_bRememberDownloadedFiles = nv;}
	static	void	SetRememberCancelledFiles(bool nv)	{m_bRememberCancelledFiles = nv;}
	// mail notifier
	static	bool	IsNotifierSendMailEnabled()			{return m_bNotifierSendMail;}
	static	CString	GetNotifierMailServer()				{return m_strNotifierMailServer;}
	static	CString	GetNotifierMailSender()				{return m_strNotifierMailSender;}
	static	CString	GetNotifierMailReceiver()			{return m_strNotifierMailReceiver;}

	static	void	SetNotifierSendMail(bool nv)		{m_bNotifierSendMail = nv;}
	static  bool	DoFlashOnNewMessage()				{return m_bIconflashOnNewMessage;}
	static  void	IniCopy(CString si, CString di);

	static	void	EstimateMaxUploadCap(uint32 nCurrentUpload);
	static  bool	GetAllocCompleteMode()				{return m_bAllocFull;}
	static  void	SetAllocCompleteMode(bool in)		{m_bAllocFull=in;}

	// encryption
	static bool		IsClientCryptLayerSupported()		{return m_bCryptLayerSupported;}
	static bool		IsClientCryptLayerRequested()		{return IsClientCryptLayerSupported() && m_bCryptLayerRequested;}
	static bool		IsClientCryptLayerRequired()		{return IsClientCryptLayerRequested() && m_bCryptLayerRequired;}
	static bool		IsClientCryptLayerRequiredStrict()	{return false;} // not even incoming test connections will be answered
	// MORPH START :require obfuscated server connection 
	static bool		IsServerCryptLayerUDPEnabled()		{return IsClientCryptLayerSupported()||IsServerCryptLayerRequiredStrict(); }
	static bool		IsServerCryptLayerTCPRequested()	{return IsClientCryptLayerRequested()||IsServerCryptLayerRequiredStrict(); }
	// MORPH END  :require obfuscated server connection 
	static uint32	GetKadUDPKey()						{return m_dwKadUDPKey;}
	static uint8	GetCryptTCPPaddingLength()			{return m_byCryptTCPPaddingLength;}

#ifdef USE_OFFICIAL_UPNP
	// UPnP
	static bool		GetSkipWANIPSetup()					{return m_bSkipWANIPSetup;}
	static bool		GetSkipWANPPPSetup()				{return m_bSkipWANPPPSetup;}
	static bool		IsUPnPEnabled()						{return m_bEnableUPnP;}
	static void		SetSkipWANIPSetup(bool nv)			{m_bSkipWANIPSetup = nv;}
	static void		SetSkipWANPPPSetup(bool nv)			{m_bSkipWANPPPSetup = nv;}
	static bool		CloseUPnPOnExit()					{return m_bCloseUPnPOnExit;}
	static bool		IsWinServUPnPImplDisabled()			{return m_bIsWinServImplDisabled;}
	static bool		IsMinilibUPnPImplDisabled()			{return m_bIsMinilibImplDisabled;}
	static int		GetLastWorkingUPnPImpl()			{return m_nLastWorkingImpl;}
	static void		SetLastWorkingUPnPImpl(int val)		{m_nLastWorkingImpl = val;}
#endif

	// Spamfilter
	static bool		IsSearchSpamFilterEnabled()			{return m_bEnableSearchResultFilter;}
	// MORPH  require obfuscated server connection 
	static bool     IsServerCryptLayerRequiredStrict()  {return IsClientCryptLayerSupported() && m_bCryptLayerRequiredStrictServer && udpport > 0;} // MORPH lh require obfuscated server connection 
	
	static bool		IsStoringSearchesEnabled()			{return m_bStoreSearches;}
	static bool		GetPreventStandby()					{return m_bPreventStandby;}
	static uint16	GetRandomTCPPort();
	static uint16	GetRandomUDPPort();

	static	bool	IsUSSLog() {return m_bDynUpLog;} //MORPH - Added by SiRoB, ZZ Upload system (USS)
	static	bool	IsUSSUDP() {return m_bUSSUDP;} //MORPH - Added by SiRoB, USS UDP preferency

	//EastShare START - Added by Pretender, add USS settings in scheduler tab
	static	void	SetDynUpGoingUpDivider(int in) { m_iDynUpGoingUpDivider = in; }
	static	void	SetDynUpGoingDownDivider(int in) { m_iDynUpGoingDownDivider = in; }
	//EastShare END - Added by Pretender, add USS settings in scheduler tab

	//MORPH START - Added by IceCream, high process priority
	static	bool	enableHighProcess;
	static	bool	GetEnableHighProcess()					{ return enableHighProcess; }
	static	void	SetEnableHighProcess(bool enablehigh);
	//MORPH END   - Added by IceCream, high process priority

	static	bool	GetEnableAntiCreditHack()					{ return enableAntiCreditHack; }//MORPH - Added by IceCream, enable AntiCreditHack

	// ==> Design Settings [eWombat/Stulle] - Stulle
#ifndef DESIGN_SETTINGS
	static	bool GetEnableDownloadInRed()	{ return enableDownloadInRed; } //MORPH - Added by IceCream, show download in red
#endif
	// <== Design Settings [eWombat/Stulle] - Stulle
	//MORPH START - Added by schnulli900, filter clients with failed downloads [Xman]
	static	bool GetFilterClientFailedDown ()		{ return m_bFilterClientFailedDown; } 
	//MORPH END   - Added by schnulli900, filter clients with failed downloads [Xman]
	static	bool GetEnableAntiLeecher()		{ return enableAntiLeecher; } //MORPH - Added by IceCream, enable Anti-leecher
	
	static	int		GetCreditSystem()	{return creditSystemMode;} // EastShare - Added by linekin, creditsystem integration
	static	bool	IsEqualChanceEnable()	{ return m_bEnableEqualChanceForEachFile;}	//Morph - added by AndCycle, Equal Chance For Each File
	static	bool	IsFollowTheMajorityEnabled() { return m_bFollowTheMajority;}// EastShare       - FollowTheMajority by AndCycle
	static	int	GetFairPlay() { return m_iFairPlay; } //EastShare	- FairPlay by AndCycle
	// EastShare START - Added by TAHO, .met file control
	static	int		GetKnownMetDays()	{return m_iKnownMetDays;}
	static	bool	DoCompletlyPurgeOldKnownFiles()	{return m_bCompletlyPurgeOldKnownFiles;}
	static	bool	DoRemoveAichImmediatly() {return m_bRemoveAichImmediatly;}
	// EastShare END   - Added by TAHO, .met file control
	static	bool IsAutoDynUpSwitching()	{return isautodynupswitching;}//MORPH - Added by Yun.SF3, Auto DynUp changing
	static	int  GetPowerShareMode()	{return m_iPowershareMode;} //MORPH - Added by SiRoB, Avoid misusing of powersharing
	static	bool	IsPSinternalPrioEnable()	{return m_bPowershareInternalPrio;} //Morph - added by AndCyle, selective PS internal Prio
	//EastShare START - Pretender, TBH-AutoBackup
	static	bool    GetAutoBackup()	{ return autobackup;}
	static	bool    GetAutoBackup2()	{ return autobackup2;}
	static	void    SetAutoBackup(bool in) { autobackup = in;}
	static	void    SetAutoBackup2(bool in) { autobackup2 = in;}
	//EastShare END - Pretender, TBH-AutoBackup
	static	int	MaxConnectionsSwitchBorder() {return maxconnectionsswitchborder;}//MORPH - Added by Yun.SF3, Auto DynUp changing
	//MORPH START - Added & Modified by SiRoB, Smart Upload Control v2 (SUC) [lovelace]
	static	bool	IsSUCDoesWork();
	static	bool	IsSUCEnabled()				{return m_bSUCEnabled;}
	//MORPH START - Added by Yun.SF3, Auto DynUp changing
	static	void	SetSUCEnabled(bool newValue){m_bSUCEnabled = newValue;}
	//MORPH END - Added by Yun.SF3, Auto DynUp changing
	static	bool	IsSUCLog()					{return m_bSUCLog;}
	static	int		GetSUCHigh()				{return m_iSUCHigh;}
	static	int		GetSUCLow()					{return m_iSUCLow;}
	static	int		GetSUCDrift()				{return m_iSUCDrift;}
	static	int		GetSUCPitch()				{return m_iSUCPitch;}
	//MORPH END - Added & Modified by SiRoB, Smart Upload Control v2 (SUC) [lovelace]
	//MORPH START - Added by SiRoB, ZZ Ratio
	static	uint8	IsZZRatioDoesWork();
	//MORPH END - Added by SiRoB, ZZ Ratio
	static	void	SetKnownMetDays(int m_iInKnownMetDays)	{m_iKnownMetDays = m_iInKnownMetDays;}	//EastShare - Added by TAHO, .met file control
	static	bool	IsPayBackFirst()					{return m_bPayBackFirst;}	//EastShare - added by AndCycle, Pay Back First
	static	uint8	GetPayBackFirstLimit()				{return m_iPayBackFirstLimit;}	//MOPRH - Added by SiRoB, Pay Back First Tweak
	static	bool	OnlyDownloadCompleteFiles()			{return m_bOnlyDownloadCompleteFiles;} //EastShare - Added by AndCycle, Only download complete files v2.1 (shadow)
	static	bool	SaveUploadQueueWaitTime()			{return m_bSaveUploadQueueWaitTime;}//Morph - added by AndCycle, Save Upload Queue Wait Time (MSUQWT)
	static	bool	DoRemoveSpareTrickleSlot()			{return !m_bDontRemoveSpareTrickleSlot;}//Morph - added by AndCycle, Dont Remove Spare Trickle Slot
	static	bool	DisplayFunnyNick()					{return m_bFunnyNick;}//MORPH - Added by SiRoB, Optionnal funnynick display
	static	CString	GetUpdateURLFakeList()				{return CString(UpdateURLFakeList);}		//MORPH START - Added by milobac and Yun.SF3, FakeCheck, FakeReport, Auto-updating
	static	CString	GetUpdateURLIPFilter()				{return CString(UpdateURLIPFilter);}//MORPH START added by Yun.SF3: Ipfilter.dat update
	static  CString GetUpdateURLIP2Country()			{return CString(UpdateURLIP2Country);}//Commander - Added: IP2Country auto-updating
	//MORPH START - Added by milobac, FakeCheck, FakeReport, Auto-updating
	static LPSYSTEMTIME   GetFakesDatVersion()				{return &m_FakesDatVersion;}
	static	bool	IsUpdateFakeStartupEnabled()		{ return UpdateFakeStartup; }
	//MORPH END - Added by milobac, FakeCheck, FakeReport, Auto-updating

	//MORPH START added by Yun.SF3: Ipfilter.dat update
	static LPSYSTEMTIME   GetIPfilterVersion()				{return &m_IPfilterVersion;}
	static bool	IsAutoUPdateIPFilterEnabled()		{ return AutoUpdateIPFilter; }
	//MORPH START - Added by Stulle, New IP Filter by Ozzy [Stulle/Ozzy]
	static uint32		GetIPFilterVersionNum()			{return m_uIPFilterVersionNum;}
	static bool			IsIPFilterViaDynDNS(CString strURL = NULL);
	//MORPH END   - Added by Stulle, New IP Filter by Ozzy [Stulle/Ozzy]
	//MORPH END added by Yun.SF3: Ipfilter.dat update

	static LPSYSTEMTIME   GetIP2CountryVersion()	{return &m_IP2CountryVersion;}//Commander - Added: IP2Country auto-updating
	static bool IsAutoUPdateIP2CountryEnabled()		{ return AutoUpdateIP2Country; } //Commander - Added: IP2Country Auto-updating

	//EastShare - added by AndCycle, IP to Country
	int	GetIP2CountryNameMode()	{return m_iIP2CountryNameMode;}
	static bool	IsIP2CountryShowFlag()				{return m_bIP2CountryShowFlag;}
	//EastShare - added by AndCycle, IP to Country
	static	void	SetMinUpload(UINT in); //MORPH - Added by SiRoB, (SUC) & (USS)
	//MORPH START - Added by SiRoB, SLUGFILLER: lowIdRetry
	static	void	SetLowIdRetried()	{LowIdRetried--;}
	static	void	ResetLowIdRetried()	{LowIdRetried = LowIdRetries;}
	static	int	GetLowIdRetried()	{return LowIdRetried;}
	static	int	GetLowIdRetries()	{return LowIdRetries;}
	//MORPH END - Added by SiRoB, SLUGFILLER: lowIdRetry
	//MORPH	Start	- Added by AndCycle, SLUGFILLER: Spreadbars - per file
	static	int	GetSpreadbarSetStatus()	{return m_iSpreadbarSetStatus;}
	//MORPH	End	- Added by AndCycle, SLUGFILLER: Spreadbars - per file
	//MORPH START - Added by SiRoB, SLUGFILLER: hideOS
	static	int	GetHideOvershares()		{return hideOS;}
	static	bool	IsSelectiveShareEnabled()	{return selectiveShare;}
	//MORPH END   - Added by SiRoB, SLUGFILLER: hideOS
	static	bool	IsInfiniteQueueEnabled()		{return infiniteQueue;}	//Morph - added by AndCycle, SLUGFILLER: infiniteQueue
	//MORPH START - Added by SiRoB, SHARE_ONLY_THE_NEED Wistily idea
	static	int	GetShareOnlyTheNeed()	{return ShareOnlyTheNeed;}
	//MORPH END   - Added by SiRoB, SHARE_ONLY_THE_NEED Wistily idea
	//MORPH START - Added by SiRoB, POWERSHARE Limit
	static	int	GetPowerShareLimit() {return PowerShareLimit;}
	//MORPH END   - Added by SiRoB, POWERSHARE Limit
	//MORPH START - Added by SiRoB, Show Permissions
	static	int	GetPermissions()	{return permissions;}
	//MORPH END   - Added by SiRoB, Show Permissions
	//EastShare Start - PreferShareAll by AndCycle
	static	bool	ShareAll()			{return shareall;}	// SLUGFILLER: preferShareAll
	//EastShare End - PreferShareAll by AndCycle
	//EastShare - Added by Pretender, Option for ChunkDots
	static	bool	EnableChunkDots()			{return m_bEnableChunkDots;}
	//EastShare - Added by Pretender, Option for ChunkDots
	//EastShare - Added by Pretender, Invisible Mode
	static	bool	InvisibleMode()			{return m_bInvisibleMode;}
	//EastShare - Added by Pretender, Invisible Mode
	//EastShare START - Added by Pretender, modified Fine Credit System
	static	bool	FineCS()			{return m_bFineCS;}
	//EastShare END

	static	bool	DateFileNameLog()	{ return m_bDateFileNameLog;}//Morph - added by AndCycle, Date File Name Log

	// Mighty Knife: Community visualization, report hashing files, Log friendlist activities
	static	CString GetCommunityName ()						{ return m_sCommunityName; }
	static	void	SetCommunityName (CString _CommName)	{ _stprintf(m_sCommunityName,_T("%s"),_CommName); }
	static	bool	IsCommunityEnabled()					{ return m_sCommunityName [0] != '\0' ? true : false; }
	static	bool    GetReportHashingFiles ()				{ return m_bReportHashingFiles; }
	static	void	SetReportHashingFiles (bool _b)			{ m_bReportHashingFiles = _b; }
	static	bool    GetLogFriendlistActivities ()			{ return m_bLogFriendlistActivities; }
	static	void	SetLogFriendlistActivities (bool _b)	{ m_bLogFriendlistActivities = _b; }
	// [end] Mighty Knife

	// Mighty Knife: CRC32-Tag - not accessible in preferences dialog !
	static	bool    GetDontAddCRCToFilename ()				{ return m_bDontAddCRCToFilename; }
	static	void	SetDontAddCRCToFilename (bool _b)		{ m_bDontAddCRCToFilename = _b; }
	static	bool    GetCRC32ForceUppercase ()				{ return m_bCRC32ForceUppercase; }
	static	void	SetCRC32ForceUppercase (bool _b)		{ m_bCRC32ForceUppercase = _b; }
	static	bool    GetCRC32ForceAdding ()					{ return m_bCRC32ForceAdding; }
	static	void	SetCRC32ForceAdding (bool _b)			{ m_bCRC32ForceAdding = _b; }
	static	CString GetCRC32Prefix ()						{ return m_sCRC32Prefix; }
	static	void	SetCRC32Prefix (CString _s)				{ _stprintf (m_sCRC32Prefix,_T("%s"),_s); }
	static	CString GetCRC32Suffix ()						{ return m_sCRC32Suffix; }
	static	void	SetCRC32Suffix (CString _s)				{ _stprintf (m_sCRC32Suffix,_T("%s"),_s); }
	// [end] Mighty Knife

	// Mighty Knife: Simple cleanup options
	static	void	SetSimpleCleanupOptions (int _i)	      { m_SimpleCleanupOptions = _i; }
	static	int 	GetSimpleCleanupOptions ()			      { return m_SimpleCleanupOptions; }
	static	void	SetSimpleCleanupSearch (CString _s)	      { m_SimpleCleanupSearch = _s; }
	static	CString	GetSimpleCleanupSearch ()			      { return m_SimpleCleanupSearch; }
	static	void	SetSimpleCleanupReplace (CString _s)	  { m_SimpleCleanupReplace = _s; }
	static	CString	GetSimpleCleanupReplace ()				  { return m_SimpleCleanupReplace; }
	static	void	SetSimpleCleanupSearchChars (CString _s)  { m_SimpleCleanupSearchChars = _s; }
	static	CString	GetSimpleCleanupSearchChars ()			  { return m_SimpleCleanupSearchChars; }
	static	void	SetSimpleCleanupReplaceChars (CString _s) { m_SimpleCleanupReplaceChars = _s; }
	static	CString	GetSimpleCleanupReplaceChars ()			  { return m_SimpleCleanupReplaceChars; }
	// [end] Mighty Knife

	// Mighty Knife: Static server handling
	static	bool    GetDontRemoveStaticServers ()			  { return m_bDontRemoveStaticServers; }
	static	void	SetDontRemoveStaticServers (bool _b)	  { m_bDontRemoveStaticServers = _b; }
	// [end] Mighty Knife

	// khaos::categorymod+
	static	bool	ShowValidSrcsOnly()		{ return m_bValidSrcsOnly; }
	static	bool	ShowCatNameInDownList()	{ return m_bShowCatNames; }
	static	bool	SelectCatForNewDL()		{ return m_bSelCatOnAdd; }
	static	bool	UseActiveCatForLinks()	{ return m_bActiveCatDefault; }
	static	bool	AutoSetResumeOrder()	{ return m_bAutoSetResumeOrder; }
	static	bool	SmallFileDLPush()		{ return m_bSmallFileDLPush; }
	static	uint8	StartDLInEmptyCats()	{ return m_iStartDLInEmptyCats; } // 0 = disabled, otherwise num to resume
	static	bool	UseAutoCat()			{ return m_bUseAutoCat; }
	// khaos::categorymod-
	// khaos::kmod+
	static	bool	UseSmartA4AFSwapping()	{ return m_bSmartA4AFSwapping; } // only for NNP swaps and file completes, stops, cancels, etc.
	static	uint8	AdvancedA4AFMode()		{ return m_iAdvancedA4AFMode; } // 0 = disabled, 1 = balance, 2 = stack -- controls the balancing routines for on queue sources
	static	bool	RespectMaxSources()		{ return m_bRespectMaxSources; }
	static	bool	ShowA4AFDebugOutput()	{ return m_bShowA4AFDebugOutput; }
	static	bool	UseSaveLoadSources()	{ return m_bUseSaveLoadSources; }
	// khaos::categorymod-
	// khaos::accuratetimerem+
	static	uint8	GetTimeRemainingMode()	{ return m_iTimeRemainingMode; }
	// khaos::accuratetimerem-
	//MORPH START - Added by SiRoB, ICS Optional
	static	bool	UseICS()	{ return m_bUseIntelligentChunkSelection; }
	//MORPH END   - Added by SiRoB, ICS Optional

    //Commander - Added: Invisible Mode [TPT] - Start
    static	bool GetInvisibleMode() { return m_bInvisibleMode; }
	static	UINT GetInvisibleModeHKKeyModifier() { return m_iInvisibleModeHotKeyModifier; }
	static	char GetInvisibleModeHKKey() { return m_cInvisibleModeHotKey; }
	static	void SetInvisibleMode(bool on, UINT keymodifier, char key);
   //Commander - Added: Invisible Mode [TPT] - End

	//MORPH START - Added by SiRoB, Upload Splitting Class
	static	uint32	GetGlobalDataRateFriend();
	static	uint32	GetMaxGlobalDataRateFriend();
	static	uint32	GetGlobalDataRatePowerShare();
	static	uint32	GetMaxGlobalDataRatePowerShare();
	static	uint32	GetMaxClientDataRateFriend();
	static	uint32	GetMaxClientDataRatePowerShare();
	static	uint32	GetMaxClientDataRate();
	//MORPH END   - Added by SiRoB, Upload Splitting Class

	// ==> Slot Limit - Stulle
	static bool GetSlotLimitThree()		{ return m_bSlotLimitThree; }
	static bool GetSlotLimitNumB()		{ return m_bSlotLimitNum; }
	static uint8 GetSlotLimitNum()		{ return m_iSlotLimitNum; }
	// <== Slot Limit - Stulle


protected:
	static	CString m_strFileCommentsFilePath;
	static	Preferences_Ext_Struct* prefsExt;
	static	WORD m_wWinVer;
	static	CArray<Category_Struct*,Category_Struct*> catMap;
	// Morph START More dirs - by pindakaasmod
	/*
	static	CString	m_astrDefaultDirs[13];
	static	bool	m_abDefaultDirsCreated[13];
	*/
	static	CString	m_astrDefaultDirs[EMULE_FEEDSDIR+1];
	static	bool	m_abDefaultDirsCreated[EMULE_FEEDSDIR+1];
	static	int		m_nCurrentUserDirMode; // Only for PPgTweaks
    // Morph END More dirs
	static void	CreateUserHash();
	static void	SetStandartValues();
	static int	GetRecommendedMaxConnections();
	static void LoadPreferences();
	static void SavePreferences();
	static CString	GetHomepageBaseURLForLevel(int nLevel);
	static CString	GetDefaultDirectory(EDefaultDirectory eDirectory, bool bCreate = true);
public:
	//MORPH START - Added by SiRoB [MoNKi: -UPnPNAT Support-]
	static	bool	IsUPnPNat()						{ return m_bUPnPNat; }
	static	bool	GetUPnPNatWeb()						{ return m_bUPnPNatWeb; }
	static	void	SetUPnPNatWeb(bool on)				{ m_bUPnPNatWeb = on; }
	static	void	SetUPnPVerboseLog(bool on)			{ m_bUPnPVerboseLog = on; }
	static	bool	GetUPnPVerboseLog()					{ return m_bUPnPVerboseLog; }
	static	void	SetUPnPPort(uint16 port)			{ m_iUPnPPort = port; }
	static	uint16	GetUPnPPort()						{ return m_iUPnPPort; }
	static	void	SetUPnPClearOnClose(bool on)		{ m_bUPnPClearOnClose = on; }
	static	bool	GetUPnPClearOnClose()				{ return m_bUPnPClearOnClose; }
	static	bool	SetUPnPLimitToFirstConnection(bool on)	{ return m_bUPnPLimitToFirstConnection = on; }
	static	bool	GetUPnPLimitToFirstConnection()		{ return m_bUPnPLimitToFirstConnection; }
	static	int  	GetUpnpDetect()					{ return m_iDetectuPnP; } //leuk_he autodetect upnp in wizard
	static	void    SetUpnpDetect(int on)				{ m_iDetectuPnP=on; } //leuk_he autodetect upnp in wizard
    #define UPNP_DO_AUTODETECT 2
    #define UPNP_DETECTED 0
    #define UPNP_NOT_DETECTED -1 
	#define UPNP_NO_DETECTEDTION -2 
    #define UPNP_NOT_NEEDED -10
	
	//MORPH END   - Added by SiRoB [MoNKi: -UPnPNAT Support-]

	//MORPH START - Added by SiRoB [MoNKi: -Random Ports-]
	static	bool	GetUseRandomPorts()				{ return m_bRndPorts; }
	static	void	SetUseRandomPorts(bool on)		{ m_bRndPorts = on; }
	static	uint16	GetMinRandomPort()				{ return m_iMinRndPort; }
	static	void	SetMinRandomPort(uint16 min)	{ m_iMinRndPort = min; }
	static	uint16	GetMaxRandomPort()				{ return m_iMaxRndPort; }
	static	void	SetMaxRandomPort(uint16 max)	{ m_iMaxRndPort = max; }
	static	bool	GetRandomPortsResetOnRestart()	{ return m_bRndPortsResetOnRestart; }
	static	void	SetRandomPortsResetOnRestart(bool on)	{ m_bRndPortsResetOnRestart = on; }
	static	uint16	GetRandomPortsSafeResetOnRestartTime(){ return m_iRndPortsSafeResetOnRestartTime; }
	static	void	SetRandomPortsSafeResetOnRestartTime(uint16 time){ m_iRndPortsSafeResetOnRestartTime = time; }
	//MORPH END   - Added by SiRoB [MoNKi: -Random Ports-]

	//MORPH START - Added by SiRoB [MoNKi: -Improved ICS-Firewall support-]
	static	bool	GetICFSupport() { return m_bICFSupport; }
	static	void	SetICFSupport(bool on) { m_bICFSupport = on; }
	static	bool	GetICFSupportFirstTime() { return m_bICFSupportFirstTime; }
	static	void	SetICFSupportFirstTime(bool on) { m_bICFSupportFirstTime = on; }
	static	bool	GetICFSupportServerUDP() { return m_bICFSupportServerUDP; }
	static	void	SetICFSupportServerUDP(bool on) { m_bICFSupportServerUDP = on; }
	//MORPH END   - Added by SiRoB [MoNKi: -Improved ICS-Firewall support-]

	//MORPH START - Added by SiRoB / Commander, Wapserver [emulEspa�a]
	static CString	GetWapTemplate()				{ return CString(m_sWapTemplateFile);}
	static void		SetWapTemplate(CString in)		{ _stprintf(m_sWapTemplateFile,_T("%s"),in);}
	static bool		GetWapServerEnabled()			{ return m_bWapEnabled; }
	static void		SetWapServerEnabled(bool on)	{ m_bWapEnabled=on; }
	static uint16	GetWapPort()					{ return m_nWapPort; }
	static void		SetWapPort(uint16 uPort)		{ m_nWapPort=uPort; }
	static int		GetWapGraphWidth()				{ return m_iWapGraphWidth; }
	static int		GetWapGraphHeight()				{ return m_iWapGraphHeight; }
	static void		SetWapGraphWidth(int width)		{ m_iWapGraphWidth=width; }
	static void		SetWapGraphHeight(int height)	{ m_iWapGraphHeight=height; }
	static bool		GetWapGraphsFilled()			{ return m_bWapFilledGraphs; }
	static void		SetWapGraphsFilled(bool on)		{ m_bWapFilledGraphs=on; }
	static void		SetWapMaxItemsInPages(int n)    { m_iWapMaxItemsInPages=n; }
	static int		GetWapMaxItemsInPages()		    { return m_iWapMaxItemsInPages; }
	static void		SetWapSendImages(bool on)		{ m_bWapSendImages=on; }
	static bool		GetWapSendImages()				{ return m_bWapSendImages; }
	static void		SetWapSendGraphs(bool on)		{ m_bWapSendGraphs=on; }
	static bool		GetWapSendGraphs()				{ return m_bWapSendGraphs; }
	static void		SetWapSendProgressBars(bool on)	{ m_bWapSendProgressBars=on; }
	static bool		GetWapSendProgressBars()		{ return m_bWapSendProgressBars; }
	static bool		GetWapAllwaysSendBWImages()		{ return m_bWapAllwaysSendBWImages; }
	static void		SetWapAllwaysSendBWImages(bool on)	{ m_bWapAllwaysSendBWImages=on; }
	static UINT		GetWapLogsSize()				{ return m_iWapLogsSize; }
	static void		SetWapLogsSize(UINT size)		{ m_iWapLogsSize=size; }
	static const	CString& GetWapPass()				{ return m_sWapPassword; }
	static void		SetWapPass(CString strNewPass);
	static bool		GetWapIsLowUserEnabled()		{ return m_bWapLowEnabled; }
	static void		SetWapIsLowUserEnabled(bool in)	{ m_bWapLowEnabled=in; }
	static const	CString& GetWapLowPass()			{ return m_sWapLowPassword; }
	static void		SetWapLowPass(CString strNewPass);
	//MORPH END - Added by SiRoB / Commander, Wapserver [emulEspa�a]

	//MORPH START - Added by Stulle, Global Source Limit
	static UINT		GetGlobalHL()				{return m_uGlobalHL;} 
	static bool		IsUseGlobalHL()				{return m_bGlobalHL;} 
	//MORPH END   - Added by Stulle, Global Source Limit

	static bool		GetStaticIcon()				{return m_bStaticIcon;} //MORPH - Added, Static Tray Icon
	// ==> [MoNKi: -USS initial TTL-] - Stulle
	static void		SetUSSInitialTTL(uint8 i)		{ m_iUSSinitialTTL = i; }
	static uint8	GetUSSInitialTTL()				{ return m_iUSSinitialTTL; }
	// <== [MoNKi: -USS initial TTL-] - Stulle

	// ==> push small files [sivka] - Stulle
	static bool		GetEnablePushSmallFile()	{return enablePushSmallFile;}
	static uint32	GetPushSmallFileSize()		{return m_iPushSmallFiles;}
	static uint16	GetPushSmallFileBoost()		{return m_iPushSmallBoost;}
	// <== push small files [sivka] - Stulle
    static bool		GetEnablePushRareFile()		{return enablePushRareFile;} // push rare file - Stulle

	static	bool	ShowSrcOnTitle()		{ return showSrcInTitle;} // Show sources on title - Stulle
	static	bool	ShowOverheadOnTitle()	{ return showOverheadInTitle;} // show overhead on title - Stulle
	static	bool	GetShowGlobalHL()		{ return ShowGlobalHL; } // show global HL - Stulle
	static	bool	GetShowFileHLconst()	{ return ShowFileHLconst; } // show HL per file constantly
	static	bool	GetTrayComplete()		{ return m_bTrayComplete; } // Completed in Tray - Stulle
	// ==> Show in MSN7 [TPT] - Stulle
	static bool		GetShowMSN7()			{return m_bShowInMSN7;}
	static void		SetShowMSN7(bool state)	{ m_bShowInMSN7 = state;}
	// <== Show in MSN7 [TPT] - Stulle
	// ==> CPU/MEM usage [$ick$/Stulle] - Stulle
	static	bool	GetSysInfo()			{ return m_bSysInfo; }
	static	bool	GetSysInfoGlobal()		{ return m_bSysInfoGlobal; }
	// <== CPU/MEM usage [$ick$/Stulle] - Stulle
	static	bool	GetShowSpeedMeter()		{ return m_bShowSpeedMeter; }

	// ==> Sivka-Ban [cyrex2001] - Stulle
	static	bool GetEnableSivkaBan()			{ return enableSivkaBan; }
//	static void	SetSivkaAskTime(uint16 in)			{ m_iSivkaAskTime = in; }
	static uint16  GetSivkaAskTime()			{ return m_iSivkaAskTime; }
//	static void    SetSivkaAskCounter (uint16 in)	{ m_iSivkaAskCounter = in; }
	static uint16  GetSivkaAskCounter()			{ return m_iSivkaAskCounter; }
	static bool	GetSivkaAskLog()				{return m_bSivkaAskLog;}
	// <== Sivka-Ban [cyrex2001] - Stulle

	// ==> ban systems optional - Stulle
	static bool IsBadModString()		{return m_bBadModString;}
	static bool IsBadNickBan()			{return m_bBadNickBan;}
	static bool IsGhostMod()			{return m_bGhostMod;}
	static bool IsAntiModIdFaker()		{return m_bAntiModIdFaker;}
	static bool IsAntiNickThief()		{return m_bAntiNickThief;}
	static bool IsEmptyNick()			{return m_bEmptyNick;}
	static bool IsFakeEmule()			{return m_bFakeEmule;}
	static bool IsLeecherName()			{return m_bLeecherName;}
	static bool IsCommunityCheck()		{return m_bCommunityCheck;}
	static bool IsHexCheck()			{return m_bHexCheck;}
	static bool	IsEmcrypt()				{return m_bEmcrypt;}
	static bool	IsBadInfo()				{return m_bBadInfo;}
	static bool	IsBadHello()			{return m_bBadHello;}
	static bool	IsSnafu()				{return m_bSnafu;}
	static bool	IsExtraBytes()			{return m_bExtraBytes;}
	static bool	IsNickChanger()			{return m_bNickChanger;}
	static bool IsFileFaker()			{return m_bFileFaker;}
	static bool IsVagaa()				{return m_bVagaa;}
	// <== ban systems optional - Stulle

	// ==> Reduce Score for leecher - Stulle
	static bool	IsReduceScore()			{return m_bReduceScore;}
	static float GetReduceFactor()		{return m_fReduceFactor;}
	// <== Reduce Score for leecher - Stulle

	static bool GetAntiXSExploiter()	{return m_bAntiXsExploiter;} // Anti-XS-Exploit [Xman] - Stulle
	static bool GetSpamBan()	        {return m_bSpamBan;} // Spam Ban [Xman] - Stulle

	// ==> Inform Clients after IP Change - Stulle
	static bool		IsRASAIC()			{return m_breaskSourceAfterIPChange;}
	static bool		IsIQCAOC()			{return m_bInformQueuedClientsAfterIPChange;}
	// <== Inform Clients after IP Change - Stulle

	static uint32	GetReAskTimeDif()	{return m_uReAskTimeDif;} // Timer for ReAsk File Sources - Stulle

	// ==> Quick start [TPT] - Stulle
	static bool		GetQuickStart()						{return m_bQuickStart;}
	static void		SetMaxCon(int in)					{maxconnections=in;} 
	static UINT		GetMaxCon()							{ return maxconnections;}
	static uint16	GetQuickStartMaxTime()				{ return m_iQuickStartMaxTime; }
	static UINT		GetQuickStartMaxConn()				{ return m_iQuickStartMaxConn; }
	static uint16	GetQuickStartMaxConnPerFive()		{ return m_iQuickStartMaxConnPerFive; }
	static UINT		GetQuickStartMaxConnBack()			{ return m_iQuickStartMaxConnBack; }
	static uint16	GetQuickStartMaxConnPerFiveBack()	{ return m_iQuickStartMaxConnPerFiveBack; }
	static bool		GetQuickStartAfterIPChange()		{ return m_bQuickStartAfterIPChange;}
	// <== Quick start [TPT] - Stulle

	// ==> FunnyNick Tag - Stulle
	static	uint8	GetFnTag()	{return FnTagMode;}
	static	CString GetFnCustomTag ()						{ return m_sFnCustomTag; }
	static	bool	GetFnTagAtEnd()	{return m_bFnTagAtEnd;}
	// <== FunnyNick Tag - Stulle

	// ==> Pay Back First for insecure clients - Stulle
	static	bool	IsPayBackFirst2()			{return m_bPayBackFirst2;}
	static	uint16	GetPayBackFirstLimit2()		{return m_iPayBackFirstLimit2;}
	// <== Pay Back First for insecure clients - Stulle

	static DWORD	GetClientBanTime()		{ return m_dwClientBanTime; } // adjust ClientBanTime - Stulle

	// ==> drop sources - Stulle
	static uint32	GetMaxSourcesPerFileTemp(){return m_MaxSourcesPerFileTemp;}
	static bool		GetEnableAutoDropNNSTemp(){return m_EnableAutoDropNNSTemp;}
	static DWORD	GetAutoNNS_TimerTemp(){return m_AutoNNS_TimerTemp;}
	static uint16	GetMaxRemoveNNSLimitTemp(){return m_MaxRemoveNNSLimitTemp;}
	static bool		GetEnableAutoDropFQSTemp(){return m_EnableAutoDropFQSTemp;}
	static DWORD	GetAutoFQS_TimerTemp(){return m_AutoFQS_TimerTemp;}
	static uint16	GetMaxRemoveFQSLimitTemp(){return m_MaxRemoveFQSLimitTemp;}
	static bool		GetEnableAutoDropQRSTemp(){return m_EnableAutoDropQRSTemp;}
	static DWORD	GetAutoHQRS_TimerTemp(){return m_AutoHQRS_TimerTemp;}
	static uint16	GetMaxRemoveQRSTemp(){return m_MaxRemoveQRSTemp;}
	static uint16	GetMaxRemoveQRSLimitTemp(){return m_MaxRemoveQRSLimitTemp;}
	static bool		GetGlobalHlTemp(){return m_bGlobalHlTemp;} // Global Source Limit (customize for files) - Stulle
	static void		SetMaxSourcesPerFileTemp(uint32 in){m_MaxSourcesPerFileTemp=in;}
	static void		SetEnableAutoDropNNSTemp(bool in){m_EnableAutoDropNNSTemp=in;}
	static void		SetAutoNNS_TimerTemp(DWORD in){m_AutoNNS_TimerTemp=in;}
	static void		SetMaxRemoveNNSLimitTemp(uint16 in){m_MaxRemoveNNSLimitTemp=in;}
	static void		SetEnableAutoDropFQSTemp(bool in){m_EnableAutoDropFQSTemp=in;}
	static void		SetAutoFQS_TimerTemp(DWORD in){m_AutoFQS_TimerTemp=in;}
	static void		SetMaxRemoveFQSLimitTemp(uint16 in){m_MaxRemoveFQSLimitTemp=in;}
	static void		SetEnableAutoDropQRSTemp(bool in){m_EnableAutoDropQRSTemp=in;}
	static void		SetAutoHQRS_TimerTemp(DWORD in){m_AutoHQRS_TimerTemp=in;}
	static void		SetMaxRemoveQRSTemp(uint16 in){m_MaxRemoveQRSTemp=in;}
	static void		SetMaxRemoveQRSLimitTemp(uint16 in){m_MaxRemoveQRSLimitTemp=in;}
	static void		SetGlobalHlTemp(bool in){m_bGlobalHlTemp=in;} // Global Source Limit (customize for files) - Stulle
	static void		SetTakeOverFileSettings(bool in) {m_TakeOverFileSettings=in;}
	static bool		GetEnableAutoDropNNSDefault(){return m_EnableAutoDropNNSDefault;}
	static DWORD	GetAutoNNS_TimerDefault(){return m_AutoNNS_TimerDefault;}
	static uint16	GetMaxRemoveNNSLimitDefault(){return m_MaxRemoveNNSLimitDefault;}
	static bool		GetEnableAutoDropFQSDefault(){return m_EnableAutoDropFQSDefault;}
	static DWORD	GetAutoFQS_TimerDefault(){return m_AutoFQS_TimerDefault;}
	static uint16	GetMaxRemoveFQSLimitDefault(){return m_MaxRemoveFQSLimitDefault;}
	static bool		GetEnableAutoDropQRSDefault(){return m_EnableAutoDropQRSDefault;}
	static DWORD	GetAutoHQRS_TimerDefault(){return m_AutoHQRS_TimerDefault;}
	static uint16	GetMaxRemoveQRSDefault(){return m_MaxRemoveQRSDefault;}
	static uint16	GetMaxRemoveQRSLimitDefault(){return m_MaxRemoveQRSLimitDefault;}
	static bool		GetGlobalHlDefault(){return m_bGlobalHlDefault;} // Global Source Limit (customize for files) - Stulle
	static bool		GetMaxSourcesPerFileTakeOver(){return m_MaxSourcesPerFileTakeOver;}
	static bool		GetEnableAutoDropNNSTakeOver(){return m_EnableAutoDropNNSTakeOver;}
	static bool		GetAutoNNS_TimerTakeOver(){return m_AutoNNS_TimerTakeOver;}
	static bool		GetMaxRemoveNNSLimitTakeOver(){return m_MaxRemoveNNSLimitTakeOver;}
	static bool		GetEnableAutoDropFQSTakeOver(){return m_EnableAutoDropFQSTakeOver;}
	static bool		GetAutoFQS_TimerTakeOver(){return m_AutoFQS_TimerTakeOver;}
	static bool		GetMaxRemoveFQSLimitTakeOver(){return m_MaxRemoveFQSLimitTakeOver;}
	static bool		GetEnableAutoDropQRSTakeOver(){return m_EnableAutoDropQRSTakeOver;}
	static bool		GetAutoHQRS_TimerTakeOver(){return m_AutoHQRS_TimerTakeOver;}
	static bool		GetMaxRemoveQRSTakeOver(){return m_MaxRemoveQRSTakeOver;}
	static bool		GetMaxRemoveQRSLimitTakeOver(){return m_MaxRemoveQRSLimitTakeOver;}
	static bool		GetGlobalHlTakeOver(){return m_bGlobalHlTakeOver;} // Global Source Limit (customize for files) - Stulle
	static bool		GetTakeOverFileSettings() {return m_TakeOverFileSettings;}
	// <== drop sources - Stulle

	// ==> TBH: minimule - Stulle
	static	int		GetSpeedMeterMin()		{return speedmetermin;}
	static	int		GetSpeedMeterMax()		{return speedmetermax;}
	static	void	SetSpeedMeterMin(int in)	{speedmetermin = in;}
	static	void	SetSpeedMeterMax(int in)    {speedmetermax = in;}
	static	bool	IsMiniMuleEnabled() {return m_bMiniMule;}
	static	void	SetMiniMuleEnabled(bool in) {m_bMiniMule = in;}
	static	uint32	GetMiniMuleUpdate()	{return m_iMiniMuleUpdate;}
	static	void	SetMiniMuleUpdate(uint32 in)  {m_iMiniMuleUpdate = in;}
	static	void	SetMiniMuleLives(bool in) {m_bMiniMuleLives = in;}
	static	bool	GetMiniMuleLives()	{return m_bMiniMuleLives;}
	static	void	SetMiniMuleTransparency(uint8 in) {m_iMiniMuleTransparency = in;}
	static	uint8	GetMiniMuleTransparency() {return m_iMiniMuleTransparency;}
	static	bool	GetMMCompl()			{ return m_bMMCompl; }
	static	bool	GetMMOpen()				{ return m_bMMOpen; }
	// <== TBH: minimule - Stulle

	// ==> Anti Uploader Ban - Stulle
	static	uint16	GetAntiUploaderBanLimit()	{return m_iAntiUploaderBanLimit;}
	static	uint8	GetAntiUploaderBanCase()	{return AntiUploaderBanCaseMode;}
	// <== Anti Uploader Ban - Stulle

	// ==> Spread Credits Slot - Stulle
	static	bool	GetSpreadCreditsSlot()			{return SpreadCreditsSlot;}
	static  void    SetSpreadCreditsSlotCounter		(uint16 in) { SpreadCreditsSlotCounter = in; }
	static	uint16	GetSpreadCreditsSlotCounter()	{return SpreadCreditsSlotCounter;}
	static	bool	GetSpreadCreditsSlotPS()		{return m_bSpreadCreditsSlotPS;}
	// <== Spread Credits Slot - Stulle

	// ==> Source Graph - Stulle
	static	bool GetSrcGraph()			{ return m_bSrcGraph; }
	static uint16  GetStatsHLMin()		{ return m_iStatsHLMin; }
	static uint16  GetStatsHLMax()		{ return m_iStatsHLMax; }
	static uint16  GetStatsHLDif()		{ return m_iStatsHLDif; }
	// <== Source Graph - Stulle

	static bool		GetGlobalHlAll()			{return m_bGlobalHlAll;} // Global Source Limit (customize for files) - Stulle

	// ==> StulleMule Version Check - Stulle
	static	time_t	GetLastSVC()				{return m_uStulleVerCheckLastAutomatic;}
	static	void	UpdateLastSVC();
	// <== StulleMule Version Check - Stulle

	// ==> Emulate others [WiZaRd/Spike/shadow2004] - Stulle
	static	bool	IsEmuMLDonkey()			    {return m_bEmuMLDonkey;}
	static	bool	IsEmueDonkey()			    {return m_bEmueDonkey;}
	static	bool	IsEmueDonkeyHybrid()		{return m_bEmueDonkeyHybrid;}
	static	bool	IsEmuShareaza()				{return m_bEmuShareaza;}
	static  bool    IsEmuLphant()				{return m_bEmuLphant;}
	static	bool	IsEmuLog()					{return m_bLogEmulator;}
	// <== Emulate others [WiZaRd/Spike/shadow2004] - Stulle

	static	uint8	GetReleaseBonus()			{return m_uReleaseBonus;} // Release Bonus [sivka] - Stulle
	static	bool	GetReleaseScoreAssurance()	{return m_bReleaseScoreAssurance;} // Release Score Assurance - Stulle

	// ==> Connection Checker [eWombat/WiZaRd] - Stulle
	static	bool	GetICMP()						{return m_bICMP;} 
	static	void	SetICMP(const bool &b)			{m_bICMP = b;} 
	static	uint8	GetPingTimeout()				{return m_uiPingTimeOut;} 
	static	void	SetPingTimeout(const uint8 &in)	{m_uiPingTimeOut = in;} 
	static	uint8	GetPingTTL()					{return m_uiPingTTL;} 
	static	void	SetPingTTL(const uint8 &in)		{m_uiPingTTL = in;} 
	static	bool	GetCheckCon()					{return m_bCheckCon;} 
	static	void	SetCheckCon(const bool &b)		{m_bCheckCon = b;}
	// <== Connection Checker [eWombat/WiZaRd] - Stulle

	static	int		GetPsAmountLimit() {return PsAmountLimit;} // Limit PS by amount of data uploaded - Stulle

	static bool		GetNoBadPushing() {return m_bNoBadPushing;} // Disable PS/PBF for leechers [Stulle/idea by sfrqlxert] - Stulle

	// ==> Global Mod statistics [Stulle/some code by SlugFiller] - Stulle
#ifdef GLOBAL_MOD_STATS
	static int		GetMinModAmount() {return m_uMinModAmount;}
#endif
	// <== Global Mod statistics [Stulle/some code by SlugFiller] - Stulle

	// ==> Design Settings [eWombat/Stulle] - Stulle
#ifdef DESIGN_SETTINGS
	static void		InitStyles();
	static bool		GetStyle(int nMaster, int nStyle, StylesStruct *style=NULL);
	static bool		SetStyle(int nMaster, int nStyle, StylesStruct *style=NULL);
	static DWORD	GetStyleFlags(int nMaster, int nStyle);
	static void		SetStyleFlags(int nMaster, int nStyle, DWORD dwNew);
	static COLORREF	GetStyleFontColor(int nMaster, int nStyle);
	static void		SetStyleFontColor(int nMaster, int nStyle, COLORREF crNew);
	static COLORREF	GetStyleBackColor(int nMaster, int nStyle);
	static void		SetStyleBackColor(int nMaster, int nStyle, COLORREF crNew);
	static short	GetStyleOnOff(int nMaster, int nStyle);
	static void		SetStyleOnOff(int nMaster, int nStyle, short sNew);
	static void		SaveStylePrefs(CIni &ini);
	static void		LoadStylePrefs(CIni &ini);
	static bool		GetAutoTextColors()	{return m_bAutoTextColors;}
#endif
	// <== Design Settings [eWombat/Stulle] - Stulle

	// ==> Automatic shared files updater [MoNKi] - Stulle
#ifdef ASFU
	static	bool	GetDirectoryWatcher()				{ return m_bDirectoryWatcher; }
	static	void	SetDirectoryWatcher(bool in)		{ m_bDirectoryWatcher = in; }
	static	bool	GetSingleSharedDirWatcher()			{ return m_bSingleSharedDirWatcher; }
	static	void	SetSingleSharedDirWatcher(bool in)	{ m_bSingleSharedDirWatcher = in; }
	static	uint32	GetTimeBetweenReloads()				{ return m_uTimeBetweenReloads; }
	static	void	SetTimeBetweenReloads(uint32 in)	{ m_uTimeBetweenReloads = in; }
#endif
	// <== Automatic shared files updater [MoNKi] - Stulle

	// ==> Control download priority [tommy_gun/iONiX] - Stulle
	static	uint8	m_uiBowlfishMode;
	static	uint8	GetBowlfishMode()					{return m_uiBowlfishMode;}

	static	bool	GetBowlfishPrioPercent()			{return (m_uiBowlfishMode == 1);}
	static	void	SetBowlfishPrioPercent()			{m_uiBowlfishMode = 1;}

	static	bool	GetBowlfishPrioSize()				{return (m_uiBowlfishMode == 2);}
	static	void	SetBowlfishPrioSize()				{m_uiBowlfishMode = 2;}

	static	uint8	m_nBowlfishPrioPercentValue;
	static	uint8	GetBowlfishPrioPercentValue()		{return m_nBowlfishPrioPercentValue;}
	static	void	SetBowlfishPrioPercentValue(uint8 value)	{m_nBowlfishPrioPercentValue = value;}

	static	uint16	m_nBowlfishPrioSizeValue;
	static	uint16	GetBowlfishPrioSizeValue()			{return m_nBowlfishPrioSizeValue;}
	static	void	SetBowlfishPrioSizeValue(uint16 value)	{m_nBowlfishPrioSizeValue = value;}

	static	uint8	m_nBowlfishPrioNewValue;
	static	uint8	GetBowlfishPrioNewValue()			{return m_nBowlfishPrioNewValue;}
	static	void	SetBowlfishPrioNewValue(uint8 value)	{m_nBowlfishPrioNewValue = value;}
	// <== Control download priority [tommy_gun/iONiX] - Stulle

	// ==> Enforce Ratio - Stulle
	static	bool	GetEnforceRatio()	{ return m_bEnforceRatio; }
	static	uint8	GetRatioValue()		{ return m_uRatioValue; }
	static	bool	GetOnlyEnforce()	{ return m_bOnlyEnforce; } // call after IsZZRatioDoesWork()!!!
	// <== Enforce Ratio - Stulle

	// ==> Advanced Transfer Window Layout - Stulle
#ifdef ATWL
	static	bool	GetSplitWindow()		{ return m_bSplitWindow; }
	static	void	SetSplitWindow(bool in)	{ m_bSplitWindow = in; }
#endif
	// <== Advanced Transfer Window Layout - Stulle

	// ==> Adjustable NT Service Strings - Stulle
	static	CString	GetServiceName()				{ return m_strServiceName; }
	static	void	SetServiceName(CString in)		{ m_strServiceName = in; }
	static	CString	GetServiceDispName()			{ return m_strServiceDispName; }
	static	void	SetServiceDispName(CString in)	{ m_strServiceDispName = in; }
	static	CString	GetServiceDescr()				{ return m_strServiceDescr; }
	static	void	SetServiceDescr(CString in)		{ m_strServiceDescr = in; }
	// <== Adjustable NT Service Strings - Stulle

	// ==> ZZ Ratio Activation Changes - Stulle
public: 
    static void SetZZratioActive(bool isactive) { m_bZZratioActive = isactive; } 
    static bool GetZZratioActive() { return m_bZZratioActive; } 
private: 
    static bool	m_bZZratioActive;
    // <== ZZ Ratio Activation Changes - Stulle
};

extern CPreferences thePrefs;
extern bool g_bLowColorDesktop;