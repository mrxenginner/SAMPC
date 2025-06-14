
#include "main.h"



CDialog::CDialog(IDirect3DDevice9* pDevice)
{
	m_pDevice = pDevice;
	m_iWidth = 600;
	m_iHeight = 300;
	m_iButtonWidth = 100;
	m_iButtonHeight = 30;
	m_pDialog = NULL;
	m_pListBox = NULL;
	m_pEditBox = NULL;
	m_szContent = NULL;
	m_iDialogID = 0;
	m_iDialogStyle = 0;
	m_bSendResponse = false;
	m_bVisible = false;
}

void CDialog::ResetDialogControls()
{
	SAFE_DELETE(m_pDialog);

	m_pDialog = new CDXUTDialog();
	m_pDialog->Init(pDialogResourceManager);
	m_pDialog->SetCallback(CDialog::OnEvent);
	m_pDialog->SetLocation(0, 0);
	m_pDialog->SetSize(600, 300);
	m_pDialog->EnableMouseInput(true);
	m_pDialog->EnableKeyboardInput(true);
	m_pDialog->SetBackgroundColors(D3DCOLOR_ARGB(220, 5, 5, 5));
	m_pDialog->SetVisible(false);

	m_pListBox = new CDXUTListBox(m_pDialog);
	m_pDialog->AddControl(m_pListBox);
	m_pListBox->SetLocation(10,10);
	m_pListBox->SetSize(m_iWidth, m_iHeight - 100);
	m_pListBox->OnInit();
	m_pListBox->GetElement(0)->TextureColor.Init(D3DCOLOR_ARGB(200, 255, 255, 255));
	m_pListBox->m_nColumns = 0;
	m_pListBox->SetEnabled(false);
	m_pListBox->SetVisible(false);

	m_pDialog->AddButton(IDC_DLGBUTTON1, "BUTTON1", 10, 5, m_iButtonWidth, m_iButtonHeight);
	m_pDialog->AddButton(IDC_DLGBUTTON2, "BUTTON2", 110, 5, m_iButtonWidth, m_iButtonHeight);
	m_pDialog->AddIMEEditBox(IDC_DLGEDITBOX, "", 10, 175, 570, 40, true, &m_pEditBox);

	if (pConfigFile->GetInt("ime"))
	{
		CDXUTIMEEditBox::EnableImeSystem(true);
		CDXUTIMEEditBox::StaticOnCreateDevice();
	}

	m_pEditBox->GetElement(0)->TextureColor.Init(D3DCOLOR_ARGB(240, 5, 5, 5));
	m_pEditBox->SetTextColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	m_pEditBox->SetCaretColor(D3DCOLOR_ARGB(255, 150, 150, 150));
	m_pEditBox->SetSelectedBackColor(D3DCOLOR_ARGB(255, 185, 34, 40));
	m_pEditBox->SetSelectedTextColor(D3DCOLOR_ARGB(255, 10, 10, 15));
	m_pEditBox->SetEnabled(false);
	m_pEditBox->SetVisible(false);
}

bool CDialog::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return CDXUTIMEEditBox::StaticMsgProc(uMsg, wParam, lParam) != false;
}

bool CDialog::IsCandidateActive()
{
	if (m_pEditBox)
	{
		return CDXUTIMEEditBox::IsCandidateActive();
	}
	return false;
}

void CDialog::GetRect(RECT* rect)
{

}

LONG CDialog::GetTextWidth(char* szText)
{
	ID3DXFont* pFont = m_pDialog->GetFont(1)->pFont;
	if (szText && szText[0] != 0 && pFont)
	{
		char szBuffer[128];
		RECT rect;
		strcpy_s(szBuffer, szText);
		RemoveColorEmbedsFromString(szBuffer);
		pFont->DrawTextA(0, szBuffer, -1, &rect, DT_EXPANDTABS | DT_NOCLIP | DT_CALCRECT, -1);
		return rect.right - rect.left;
	}
	return -1;
}

LONG CDialog::GetFontHeight()
{
	return m_pDialog->GetFont(1)->nHeight;
}

void CDialog::Hide()
{
	pGame->ToggleKeyInputsDisabled(0);
	m_pDialog->SetVisible(false);
}

void CDialog::Show(int iID, int iStyle, char* szCaption,
	char* szContent, char* szButton1, char* szButton2, bool bSendResponse)
{
	SIZE size;

	if (iID >= 0)
	{
		if (pCmdWindow && pCmdWindow->isEnabled())
			pCmdWindow->Disable();

		m_iDialogID = iID;
		m_iDialogStyle = iStyle;
		m_bSendResponse = bSendResponse;

		SecureZeroMemory(m_szCaption, sizeof(m_szCaption));
		strncpy_s(m_szCaption, szCaption, 64);

		if (m_szContent)
			free(m_szContent);
		DWORD dwLen = strlen(szContent);
		m_szContent = (char*)calloc(1, dwLen + 64);
		strcpy_s(m_szContent, dwLen, szContent);

		pDefaultFont->MeasureSmallerText(&m_ContentSize, m_szContent, DT_EXPANDTABS);

		if (szCaption[0] != '\0')
		{
			pDefaultFont->MeasureText(&size, "Y", 0); // DT_LEFT ?
			m_pDialog->SetCaptionText(szCaption);
			m_pDialog->EnableCaption(true);
			m_pDialog->SetCaptionHeight(size.cy + 4);
			
		}

		switch (m_iDialogStyle)
		{
		case DIALOG_STYLE_MSGBOX:
		{
			m_iWidth = m_ContentSize.cx + 40;
			m_iHeight = m_ContentSize.cy + m_pDialog->GetCaptionHeight() + m_iButtonHeight + 25;
			m_pEditBox->SetVisible(false);
			m_pEditBox->SetEnabled(false);
			m_pListBox->SetVisible(false);
			m_pListBox->SetEnabled(false);
			break;
		}
		case DIALOG_STYLE_INPUT:
		{
			m_iWidth = m_ContentSize.cx + 40;
			m_iHeight = m_iButtonHeight +
						m_ContentSize.cy +
						(m_pDialog->GetFont(1)->nHeight * 1.6f + 14.0f) +
						m_pDialog->GetCaptionHeight() + 25;

			m_pEditBox->SetVisible(true);
			m_pEditBox->SetEnabled(true);
			m_pEditBox->SetText("");
			m_pListBox->SetVisible(false);
			m_pListBox->SetEnabled(false);
			break;
		}
		case DIALOG_STYLE_LIST:
			break;
		case DIALOG_STYLE_PASSWORD:
			break;
		case DIALOG_STYLE_TABLIST:
			break;
		case DIALOG_STYLE_TABLIST_HEADERS:
			break;
		}

		m_pDialog->GetButton(IDC_DLGBUTTON1)->SetText(szButton1);

		CDXUTButton* pButton = m_pDialog->GetButton(IDC_DLGBUTTON2);
		if (szButton2[0] != '\0')
		{
			pButton->SetText(szButton2);
			pButton->SetVisible(true);
		}
		else
		{
			pButton->SetText("");
			pButton->SetVisible(false);
		}

		m_pDialog->SetVisible(true);

		switch (m_iDialogStyle)
		{
		case DIALOG_STYLE_INPUT:
		case DIALOG_STYLE_PASSWORD:
			m_pDialog->RequestFocus(m_pEditBox);
			break;
		case DIALOG_STYLE_LIST:
		case DIALOG_STYLE_TABLIST:
		case DIALOG_STYLE_TABLIST_HEADERS:
			m_pDialog->RequestFocus(m_pListBox);
			m_pListBox->SelectItem(0);
			break;
		}

		m_bVisible = true;
	}
	else if (m_bVisible)
	{
		Hide();
	}
}

void CALLBACK CDialog::OnEvent(UINT nEvent, int nControlID,
	CDXUTControl* pControl, void* pUserContext)
{

}
