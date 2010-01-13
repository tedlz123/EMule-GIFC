#pragma once
#include "PPGtooltipped.h"

// MORPH START leuk_he tooltipped
/*
class CPPgServer : public CPropertyPage
*/
class CPPgServer : public CPPgtooltipped  
// MORPH END leuk_he tooltipped
{
	DECLARE_DYNAMIC(CPPgServer)

public:
	CPPgServer();
	virtual ~CPPgServer();

	// Dialog Data
	enum { IDD = IDD_PPG_SERVER };

	void Localize(void);

protected:
	void LoadSettings(void);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnApply();
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()
	afx_msg void OnSettingsChange()					{ SetModified(); }
	afx_msg void OnBnClickedEditadr();
	afx_msg void OnHelp();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
};
