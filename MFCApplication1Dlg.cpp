
// MFCApplication1Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"


using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_COMBO_FONTLIST, m_fontNameSelectList);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
//	ON_WM_SHOWWINDOW()
ON_WM_TIMER()
ON_WM_CLOSE()
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	//LoadFontNae();
	//SetTimer(1, 100, NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	LoadFontNae();
}


void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	GerFontContoursPoinData();
}


void CMFCApplication1Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	GerOrignFontContoursPoinData();

}


void CMFCApplication1Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CreatNewFontDataSimulate();
}



void CMFCApplication1Dlg::GerFontContoursPoinData()
{
	// TODO: 在此添加控件通知处理程序代码
	//GetLinePointData myGetLinePointData = GetLinePointData();

	//SPLINE line1;								//定义全局变量

	//pSPLINE pLine1 = &line1;
	//+++++++++++++++++

	CDC * pCurDC = this->GetWindowDC();
	this->RedrawWindow();
	HDC dc = pCurDC->GetSafeHdc();
	CString cstrFontName, EditText;
	int iXPos = 300, iYPos = 300;



	m_fontNameSelectList.GetWindowTextW(cstrFontName);
	((CEdit*)GetDlgItem(IDC_EDIT1))->GetWindowTextW(EditText);
	CString cstr = (CString)"鬓";

	system("cls");

	LOGFONT logfont;
	memset(&logfont, 0, sizeof(LOGFONT));
	logfont.lfHeight = 280;
	//logfont.lfUnderline = true;
	//logfont.lfStrikeOut = 1;
	//logfont.lfOrientation = 10;
	//logfont.lfCharSet = GB2312_CHARSET;//CHINESEBIG5_CHARSET
	logfont.lfCharSet = DEFAULT_CHARSET;//CHINESEBIG5_CHARSET
	//_tcscpy(logfont.lfFaceName, _T("楷书"));



	wcscpy_s(logfont.lfFaceName, cstrFontName);
	//_tcscpy(logfont.lfFaceName, cstrFontName);
	CFont font;
	font.CreateFontIndirect(&logfont);
	CFont* pOldFont = pCurDC->SelectObject(&font);

	pCurDC->TextOutW(50, iYPos, EditText);

	MAT2 mat2 = { {0,1}, {0,0}, {0,0}, {0,-1} };

	POINT buffer[1024];
	GLYPHMETRICS gm;

	wchar_t thisChar = L'鬓';

	const char* chrLengthMsg;
	memset(&chrLengthMsg, thisChar, sizeof(thisChar));


	//BYTE*pBuffer = NULL;
 //  DWORD	dwBufSize = 0;
	///*dwRetVal = pDC->GetGlyphOutline(c, GGO_NATIVE, &GpMtic, dwBufSize, pBuffer, &mat);*/
	//DWORD dwRetVal = ::GetGlyphOutline(pCurDC->GetSafeHdc(), *EditText, GGO_BEZIER, &gm, dwBufSize, pBuffer, &mat2);
	//if (dwRetVal == -1)
	//{
	//	//NMsg::MsgErr();
	//	goto Done;
	//}

	//dwBufSize = dwRetVal;
	//pBuffer = new BYTE[dwBufSize];
	//memset(pBuffer, 0, dwBufSize);

	//dwRetVal = pDC->GetGlyphOutline(*EditText, GGO_NATIVE, &GpMtic, dwBufSize, pBuffer, &mat);
	//DWORD returnBytes = GetGlyphOutlineW(pCurDC->GetSafeHdc(), *EditText, GGO_BEZIER, &gm, dwBufSize, pBuffer, &mat2);

	DWORD returnBytes = GetGlyphOutlineW(pCurDC->GetSafeHdc(), *EditText, GGO_BEZIER, &gm, sizeof(buffer), buffer, &mat2);
	if (returnBytes != GDI_ERROR)
	{
		TTPOLYGONHEADER* pTTPH = (TTPOLYGONHEADER*)buffer;
		_ASSERTE(pTTPH->dwType == TT_POLYGON_TYPE);

		// 对闭合路径进行循环
		while (returnBytes > 0)
		{
			pCurDC->MoveTo(pTTPH->pfxStart.x.value + iXPos, pTTPH->pfxStart.y.value + iYPos);
			TTPOLYCURVE* pCurrentCurve = (TTPOLYCURVE*)(pTTPH + 1);
			int remainBytes = pTTPH->cb - sizeof(TTPOLYGONHEADER);


			while (remainBytes > 0)
			{

				//for (int i = 0; i < pCurrentCurve->cpfx; ++i)
				//{
				//	pCurDC->LineTo(pCurrentCurve->apfx[i].x.value + iXPos, pCurrentCurve->apfx[i].y.value + iYPos);
				//}




				switch (pCurrentCurve->wType)
				{
				case TT_PRIM_LINE:
				{
					goto RunOneLineDarw;
					//POINT*Points = new POINT[pCurrentCurve->cpfx + 1];
					////Points[] = 
					//for (size_t i = 0; i < pCurrentCurve->cpfx; i++)
					//{
					//	//pCurDC->LineTo(pCurrentCurve->apfx[i].x.value  +iXPos, pCurrentCurve->apfx[i].y.value + iYPos);
					//}
					//break;
				}
				case TT_PRIM_QSPLINE:
				{
					goto RunOneLineDarw;
					//int PointCount = 1 + (pCurrentCurve->cpfx - 1) * 3;
					//POINT *pPoints = new POINT[PointCount];
					//POINT P0, P1, P2;
					//P0 = pCurDC->GetCurrentPosition();
					//pPoints[0] = P0;
					//int icurrent = 1;

					//for (size_t i = 0; i < pCurrentCurve->cpfx; i++)
					//{
					//	P1.x  = FIXEDToInt( pCurrentCurve->apfx[i++].x);
					//	P1.y =  FIXEDToInt(pCurrentCurve->apfx[i++].y);
					//	if (i == pCurrentCurve->cpfx - 1)
					//	{
					//		P2.x = FIXEDToInt(pCurrentCurve->apfx[i++].x);
					//		P2.y = FIXEDToInt(pCurrentCurve->apfx[i++].y);
					//	}
					//	else
					//	{
					//		P2.x = FIXEDToInt(pCurrentCurve->apfx[i].x)+ iXPos;
					//		P2.y = FIXEDToInt(pCurrentCurve->apfx[i].y);

					//		P2.x = (P1.x + P2.x) / 2;
					//		P2.y = (P1.y + P2.y) / 2;
					//	}

					//	pPoints[icurrent + 0].x = P0.x + 2 * (P1.x - P0.x) / 3;
					//	pPoints[icurrent + 0].y = P0.y + 2 * (P1.y - P0.y) / 3;
					//	pPoints[icurrent + 1].x = P1.x + 1* (P2.x - P1.x) / 3;
					//	pPoints[icurrent + 1].y = P1.y + 1 * (P2.y - P1.y) / 3;

					//	pPoints[icurrent + 2] = P2;
					//	icurrent += 3;
					//	P0 = P2;
					//}
					//COLORREF de = PEN_FLAG_BARREL;
					////pCurDC->SetDCPenColor(de);
					//pCurDC->PolyBezier(pPoints, icurrent);
					//delete[]pPoints;
					//for (size_t i = 0; i < pCurrentCurve->cpfx; i++)
					//{
					//	pCurDC->LineTo(pCurrentCurve->apfx[i].x.value  +iXPos, pCurrentCurve->apfx[i].y.value + iYPos);
					//}
					//break;
				}
				case TT_PRIM_CSPLINE:
				{
					CPoint cp = pCurDC->GetCurrentPosition();
					POINT pPoint = { cp.x,cp.y };
					m_LinePoint.clear();
					POINT GetSysPoint[4];
					memset(GetSysPoint, 0, sizeof(POINT));
					GetSysPoint[0] = pPoint;
					for (size_t i = 0; i < pCurrentCurve->cpfx; i++)
					{
						//GetSysPoint[i + 1].x = FIXEDToInt(pCurrentCurve->apfx[i].x);
						//GetSysPoint[i + 1].y = FIXEDToInt(pCurrentCurve->apfx[i].y);
						pCurDC->LineTo(pCurrentCurve->apfx[i].x.value + iXPos, pCurrentCurve->apfx[i].y.value + iYPos);
					}
					//m_LinePoint = NewLineByBezier(GetSysPoint);
					//for (size_t i = 0; i < m_LinePoint.size(); i++)
					//{
					//	pCurDC->LineTo(m_LinePoint[i].x + iXPos, m_LinePoint[i].y + iYPos);
					//}
					//delete[]GetSysPoint;


						//int PointCount = 1 + (pCurrentCurve->cpfx - 1) * 3;
						//POINT *pPoints = new POINT[PointCount];
						//POINT P0, P1, P2;
						//P0 = pCurDC->GetCurrentPosition();
						//pPoints[0] = P0;
						//int icurrent = 1;

						//for (size_t i = 0; i < pCurrentCurve->cpfx; i++)
						//{
						//	P1.x  = FIXEDToInt( pCurrentCurve->apfx[i++].x);
						//	P1.y =  FIXEDToInt(pCurrentCurve->apfx[i++].y);
						//	if (i == pCurrentCurve->cpfx - 1)
						//	{
						//		P2.x = FIXEDToInt(pCurrentCurve->apfx[i++].x);
						//		P2.y = FIXEDToInt(pCurrentCurve->apfx[i++].y);
						//	}
						//	else
						//	{
						//		P2.x = FIXEDToInt(pCurrentCurve->apfx[i].x)+ iXPos;
						//		P2.y = FIXEDToInt(pCurrentCurve->apfx[i].y);

						//		P2.x = (P1.x + P2.x) / 2;
						//		P2.y = (P1.y + P2.y) / 2;
						//	}

						//	pPoints[icurrent + 0].x = P0.x + 2 * (P1.x - P0.x) / 3;
						//	pPoints[icurrent + 0].y = P0.y + 2 * (P1.y - P0.y) / 3;
						//	pPoints[icurrent + 1].x = P1.x + 1* (P2.x - P1.x) / 3;
						//	pPoints[icurrent + 1].y = P1.y + 1 * (P2.y - P1.y) / 3;

						//	pPoints[icurrent + 2] = P2;
						//	icurrent += 3;
						//	P0 = P2;
						//}
						//COLORREF de = PEN_FLAG_BARREL;
						////pCurDC->SetDCPenColor(de);
						//pCurDC->PolyBezier(pPoints, icurrent);
						//for (size_t i = 0; i < icurrent; i++)
						//{
						//	pCurDC->LineTo(pPoints[i].x + iXPos, pPoints[i].y + iYPos);
						//}
						//delete[]pPoints;
						//for (size_t i = 0; i < pCurrentCurve->cpfx; i++)
						//{
						//	pCurDC->LineTo(pCurrentCurve->apfx[i].x.value  +iXPos, pCurrentCurve->apfx[i].y.value + iYPos);
						//}
						break;
					//for (int i = 0; i < pCurrentCurve->cpfx; ++i)
					//{
					//	pCurDC->LineTo(pCurrentCurve->apfx[i].x.value  + iXPos, pCurrentCurve->apfx[i].y.value + iYPos);
					//}
				}

RunOneLineDarw:
				break;

				}

				int count = sizeof(TTPOLYCURVE) + (pCurrentCurve->cpfx - 1) * sizeof(POINTFX);
				pCurrentCurve = (TTPOLYCURVE*)((char*)pCurrentCurve + count);
				remainBytes -= count;
			}
			//pCurDC->LineTo(pTTPH->pfxStart.x.value + iXPos, pTTPH->pfxStart.y.value + iYPos);
			returnBytes -= pTTPH->cb;
			pTTPH = (TTPOLYGONHEADER*)((char*)pTTPH + pTTPH->cb);
		}
	}


	//line1.point_num = 3;

	//line1.begin_k1 = 1;			//开始点出的一阶导数

	//line1.end_k1 = -1;				//结尾点的一阶导数

	////++++++++++++++++
	////line1.x[0] = cp.x;
	////line1.y[0] = cp.y;
	//for (int i = 0; i < myGetLinePointData.mySimulatePointData.size(); ++i)
	//{
	//	line1.x[i] = myGetLinePointData.mySimulatePointData[i].x;
	//	line1.y[i] = myGetLinePointData.mySimulatePointData[i].y;


	//	

	//}
	//myGetLinePointData.mySimulatePointData.clear();
	//myGetLinePointData.Spline3(pLine1);
	//myGetLinePointData.DrawCubicSpline(pLine1);

	//+++++++++++++++++
	//for (size_t i = 0; i < myGetLinePointData.mySimulatePointData.size(); i++)
	//{
	//	//pCurDC->LineTo(myGetLinePointData.mySimulatePointData[i].x + iXPos, myGetLinePointData.mySimulatePointData[i].y + iYPos);
	//	//curPointData[iPointIndex].point.x = myGetLinePointData.mySimulatePointData[i].x;
	//	//curPointData[iPointIndex].point.y = myGetLinePointData.mySimulatePointData[i].y;
	//	//curPointData[iPointIndex].typle = TT_PRIM_CSPLINE;
	//	//iPointIndex++;
	//}
Done:
	pCurDC->SelectObject(pOldFont);

	pCurDC->DeleteDC();
	ReleaseDC(pCurDC);

}

void CMFCApplication1Dlg::GerOrignFontContoursPoinData()
{
	// TODO: 在此添加控件通知处理程序代码
	CDC * pCurDC = this->GetWindowDC();
	//this->RedrawWindow();

	CString cstrFontName, EditText;
	int iXPos = 600, iYPos = 600;
	vector<WORD>myWIndex;

	((CEdit*)GetDlgItem(IDC_EDIT1))->GetWindowTextW(EditText);

	CString cstr = (CString)"鬓";

	//system("cls");


	CDC *         pDC;
	CString           cStr;
	TCHAR          c;
	GLYPHMETRICS    GpMtic;
	BYTE *         pBuffer;
	DWORD          dwBufSize;
	MAT2          mat;
	CFont         font;
	CFont *           pOldFont;
	LOGFONT           lf;
	DWORD          dwRetVal;
	int           x, y;
	BOOL          bBit;
	int iXpos = 400;
	int iYpos = 400;
	c = _T('人');

	cStr = c;
	pDC = this->GetWindowDC();

	memset(&lf, 0, sizeof(LOGFONT));

	//++++++++
	((CEdit*)GetDlgItem(IDC_EDIT1))->GetWindowTextW(EditText);
	m_fontNameSelectList.GetWindowTextW(cstrFontName);
	//CString cstr = (CString)"鬓";

	system("cls");
	MulDiv(8, GetDeviceCaps(pCurDC->GetSafeHdc(), LOGPIXELSY), 72);
	LOGFONT logfont;
	memset(&logfont, 0, sizeof(LOGFONT));
	logfont.lfHeight = 280;
	//logfont.lfHeight = MulDiv(8, GetDeviceCaps(pCurDC->GetSafeHdc(), LOGPIXELSY), 72);
	//logfont.lfUnderline = false;
	//logfont.lfOutPrecision = 0;
	//logfont.lfQuality = 0;
	//logfont.lfWeight = 400;
	//logfont.lfClipPrecision = CLIP_EMBEDDED;
	//logfont.lfOrientation = 10;
	//logfont.lfCharSet = GB2312_CHARSET;//CHINESEBIG5_CHARSET
	logfont.lfCharSet = GB2312_CHARSET;//CHINESEBIG5_CHARSET
	//_tcscpy(logfont.lfFaceName, _T("隶书"));
	wcscpy_s(logfont.lfFaceName, cstrFontName);

	//_tcscpy(logfont.lfFaceName, cstrFontName);

	//++



	lf.lfHeight = 300;


	font.CreateFontIndirect(&lf);

	pOldFont = pDC->SelectObject(&font);
	pDC->TextOut(0, 0, EditText);

	//NSys::IdleSleep(200);

	memset(&GpMtic, 0, sizeof(GpMtic));
	memset(&mat, 0, sizeof(mat));
	mat.eM11.value = 1;
	mat.eM22.value = 1;

	pBuffer = NULL;
	dwBufSize = 0;
	/*dwRetVal = pDC->GetGlyphOutline(c, GGO_NATIVE, &GpMtic, dwBufSize, pBuffer, &mat);*/
	dwRetVal = ::GetGlyphOutline(pDC->m_hDC, *EditText, GGO_NATIVE, &GpMtic, dwBufSize, pBuffer, &mat);
	if (dwRetVal == -1)
	{
		//NMsg::MsgErr();
		goto Done;
	}

	dwBufSize = dwRetVal;
	pBuffer = new BYTE[dwBufSize];
	memset(pBuffer, 0, dwBufSize);
	TTPOLYGONHEADER *pHeader = (TTPOLYGONHEADER*)pBuffer;
	dwRetVal = pDC->GetGlyphOutline(*EditText, GGO_NATIVE, &GpMtic, dwBufSize, pBuffer, &mat);
	if (dwRetVal == -1)
	{
		delete[] pBuffer;
		goto Done;
	}
	while (dwRetVal > 0)
	{
		//计算字符轮廓的起点，转换坐标

		int xOld = FIXEDToInt(pHeader->pfxStart.x);

		int yOld = FIXEDToInt(pHeader->pfxStart.y);
		pDC->MoveTo(iXpos + xOld, iYpos - yOld);
		TTPOLYCURVE *pCurrentCurve = (TTPOLYCURVE*)(pHeader + 1);
		int remainByte = pHeader->cb - sizeof(TTPOLYGONHEADER);
		while (remainByte > 0)
		{
			POINT lpPoint[1000];
			POINT vbezi[2];
			int index;



			CString cstrIndex;
			cstrIndex.Format(_T("%d"), pCurrentCurve->cpfx);
			((CEdit*)GetDlgItem(IDC_EDIT1))->SetWindowTextW(cstrIndex);


			for (index = 0; index < pCurrentCurve->cpfx; ++index)
			{
				lpPoint[index].x = iXpos + FIXEDToInt(pCurrentCurve->apfx[index].x);
				lpPoint[index].y = iYpos - FIXEDToInt(pCurrentCurve->apfx[index].y);
				//pDC->LineTo(lpPoint[index].x, lpPoint[index].y);
			}
			myWIndex.push_back(pCurrentCurve->cpfx);


			switch (pCurrentCurve->wType)
			{

			case TT_PRIM_LINE:

				for (index = 0; index < pCurrentCurve->cpfx; index++)
				{
					//pDC->LineTo(lpPoint[index].x, lpPoint[index].y);
				}
				//break;
			case TT_PRIM_QSPLINE:
			{
				for (index = 0; index < pCurrentCurve->cpfx; index++)
				{
					pDC->LineTo(lpPoint[index].x, lpPoint[index].y);
				}
				break;

				MessageBoxA(nullptr, "", "", NULL);
				//CPoint  pp = pDC->GetCurrentPosition();

				//CBezierCurve curev;
				//POINT p = { pp.x ,pp.y };

				//curev.SetCtrlPoint(p);
				//curev.SetCtrlPoint(lpPoint[0]);

				//curev.SetCtrlPoint(lpPoint[1]);


				//curev.CreateCurve();
				//curev.Draw(pDC);

				//pDC->MoveTo(lpPoint[1]);

				break;
			}
			case TT_PRIM_CSPLINE:
			{
				for (index = 0; index < pCurrentCurve->cpfx; index++)
				{
					pDC->LineTo(lpPoint[index].x, lpPoint[index].y);
				}
				break;
			}
			case 4:
			{
				for (index = 0; index < pCurrentCurve->cpfx; index++)
				{
					pDC->LineTo(lpPoint[index].x, lpPoint[index].y);
				}
				break;
			}
			case 9:
			{
				for (index = 0; index < pCurrentCurve->cpfx; index++)
				{
					pDC->LineTo(lpPoint[index].x, lpPoint[index].y);
				}
				break;
			}
			default:
				//MessageBox(_T("字体不支持"));
				break;
			}

			int count = sizeof(TTPOLYCURVE) + (pCurrentCurve->cpfx - 1) * sizeof(POINTFX);
			pCurrentCurve = (TTPOLYCURVE*)((char*)pCurrentCurve + count);
			remainByte -= count;


		}
		pDC->LineTo(iXpos + xOld, iYpos - yOld);
		dwRetVal -= pHeader->cb;
		pHeader = (TTPOLYGONHEADER*)((char*)pHeader + pHeader->cb);
	}

	delete[] pBuffer;
Done:
	pDC->SelectObject(pOldFont);
	this->ReleaseDC(pDC);

}

void CMFCApplication1Dlg::CreatNewFontDataSimulate()
{


	CDC *         pDC;
	CString           cStr;
	TCHAR          c;
	GLYPHMETRICS    GpMtic;
	BYTE *         pBuffer;
	DWORD          dwBufSize;
	MAT2          mat;
	CFont         font;
	CFont *           pOldFont;
	LOGFONT           lf;
	DWORD          dwRetVal;
	int           x, y;
	BOOL          bBit;
	int iXpos = 600;
	int iYpos = 600;
	c = _T('人');

	cStr = c;
	pDC = this->GetWindowDC();

	memset(&lf, 0, sizeof(LOGFONT));

	lf.lfHeight = 200;
	lf.lfCharSet = DEFAULT_CHARSET;

	//
	CString EditText, cstrFontName;
	((CEdit*)GetDlgItem(IDC_EDIT1))->GetWindowTextW(EditText);
	m_fontNameSelectList.GetWindowTextW(cstrFontName);


	//lstrcpy(lf.lfFaceName, _T("等线"));
	lstrcpy(lf.lfFaceName, cstrFontName);
	font.CreateFontIndirect(&lf);

	pOldFont = pDC->SelectObject(&font);
	pDC->TextOut(0, 0, cStr);

	//NSys::IdleSleep(200);

	memset(&GpMtic, 0, sizeof(GpMtic));
	memset(&mat, 0, sizeof(mat));
	mat.eM11.value = 1;
	mat.eM22.value = 1;

	pBuffer = NULL;
	dwBufSize = 0;
	/*dwRetVal = pDC->GetGlyphOutline(c, GGO_NATIVE, &GpMtic, dwBufSize, pBuffer, &mat);*/
	dwRetVal = ::GetGlyphOutline(pDC->m_hDC, *EditText, GGO_NATIVE, &GpMtic, dwBufSize, pBuffer, &mat);
	if (dwRetVal == -1)
	{
		//NMsg::MsgErr();
		goto Done;
	}

	dwBufSize = dwRetVal;
	pBuffer = new BYTE[dwBufSize];
	memset(pBuffer, 0, dwBufSize);
	TTPOLYGONHEADER *pHeader = (TTPOLYGONHEADER*)pBuffer;
	dwRetVal = pDC->GetGlyphOutline(*EditText, GGO_NATIVE, &GpMtic, dwBufSize, pBuffer, &mat);
	if (dwRetVal == -1)
	{
		delete[] pBuffer;
		goto Done;
	}
	while (dwRetVal > 0)
	{
		//计算字符轮廓的起点，转换坐标

		int xOld = FIXEDToInt(pHeader->pfxStart.x);

		int yOld = FIXEDToInt(pHeader->pfxStart.y);
		pDC->MoveTo(iXpos + xOld, iYpos - yOld);
		TTPOLYCURVE *pCurrentCurve = (TTPOLYCURVE*)(pHeader + 1);
		int remainByte = pHeader->cb - sizeof(TTPOLYGONHEADER);
		while (remainByte > 0)
		{
			POINT lpPoint[1000];
			POINT vbezi[2];
			int index;

			for (index = 0; index < pCurrentCurve->cpfx; ++index)
			{
				lpPoint[index].x = iXpos + FIXEDToInt(pCurrentCurve->apfx[index].x);
				lpPoint[index].y = iYpos - FIXEDToInt(pCurrentCurve->apfx[index].y);

			}
			switch (pCurrentCurve->wType)
			{

			case TT_PRIM_LINE:

				for (index = 0; index < pCurrentCurve->cpfx; index++)
				{
					pDC->LineTo(lpPoint[index].x, lpPoint[index].y);
				}
				break;
			case TT_PRIM_QSPLINE:
			{
				CPoint  pp = pDC->GetCurrentPosition();

				CBezierCurve curev;
				POINT p = { pp.x ,pp.y };

				curev.SetCtrlPoint(p);
				curev.SetCtrlPoint(lpPoint[0]);

				curev.SetCtrlPoint(lpPoint[1]);


				curev.CreateCurve();
				curev.Draw(pDC);

				pDC->MoveTo(lpPoint[1]);

				break;
			}
			case TT_PRIM_CSPLINE:
			{
				for (index = 0; index < pCurrentCurve->cpfx; index++)
				{
					pDC->LineTo(lpPoint[index].x, lpPoint[index].y);
				}
				break;
			}
			case 4:
			{
				CPoint  pp = pDC->GetCurrentPosition();

				CBezierCurve curev;
				POINT p = { pp.x ,pp.y };

				curev.SetCtrlPoint(p);
				curev.SetCtrlPoint(lpPoint[0]);

				curev.SetCtrlPoint(lpPoint[1]);


				curev.CreateCurve();
				curev.Draw(pDC);

				pDC->MoveTo(lpPoint[1]);

				break;
			}
			default:
				MessageBox(_T("字体不支持"));
				break;
			}

			int count = sizeof(TTPOLYCURVE) + (pCurrentCurve->cpfx - 1) * sizeof(POINTFX);
			pCurrentCurve = (TTPOLYCURVE*)((char*)pCurrentCurve + count);
			remainByte -= count;


		}
		pDC->LineTo(iXpos + xOld, iYpos - yOld);
		dwRetVal -= pHeader->cb;
		pHeader = (TTPOLYGONHEADER*)((char*)pHeader + pHeader->cb);
	}

	delete[] pBuffer;
Done:
	pDC->SelectObject(pOldFont);
	this->ReleaseDC(pDC);

}

vector<POINT> CMFCApplication1Dlg::NewLineByBezier(POINT * pPOINTDATA)
{

	vector<POINT> newPointData;
	POINT NewPoint = POINT();
	float fStep = 0.2;
	float ft = 0;
	for (float i = 0; i <1.0; i +=fStep)
	{
		ft = i ;
		NewPoint.x = pPOINTDATA[0].x * (-pow(ft, 3.0) + 3 * pow(ft, 2.0) - 3*ft + 1) + (3 * pow(ft, 3.0) - 6 * pow(ft, 2.0) + 3 * ft)*pPOINTDATA[1].x + (-3 * pow(ft, 3.0) + 3 * pow(ft, 2)*pPOINTDATA[2].x) + pow(ft, 3)*pPOINTDATA[3].x;

		NewPoint.y = pPOINTDATA[0].y * (-pow(ft, 3.0) + 3 * pow(ft, 2.0) - 3 * ft + 1) + (3 * pow(ft, 3.0) - 6 * pow(ft, 2.0) + 3 * ft)*pPOINTDATA[1].y + (-3 * pow(ft, 3.0) + 3 * pow(ft, 2)*pPOINTDATA[2].y) + pow(ft, 3)*pPOINTDATA[3].y;
		newPointData.push_back(NewPoint);
	}
	return newPointData;
}






int CMFCApplication1Dlg::LoadFontNae()
{

	
	//COMBO IDC_COMBO_FontNameList

	//IDC_COMBO_FontNameList
	//string strPathL  = "F:\\HCJ2018\\设备程序\\测试功能算法验证\\DrawLineOrAir\\DrawCIrcleText\\bin\\Debug\\FontNameSys.txt";
	const char * strPath = "F:\\HCJ2018\\设备程序\\测试功能算法验证\\DrawLineOrAir\\DrawCIrcleText\\bin\\Debug\\FontNameSys.txt";
	FILE* pFl =NULL;
	fopen_s(&pFl,strPath, "r");
	//const char* pMsg[256];
	//fread(pMsg, sizeof(char), sizeof(pFl), pFl);
	//
	//LPCTSTR STR;
	//m_fontNameSelectList.AddString(STR);




	////
	//fseek(pFl, 0, SEEK_END);
	//long lSize = ftell(pFl);
	//rewind(pFl);
	////开辟存储空间
	////int num = lSize / sizeof(double);
	////double *pos = (double*)malloc(sizeof(double)*num);
	//int num = lSize / sizeof(char);
	//char *pos = (char*)malloc(sizeof(char)*num);
	//if (pos == NULL)
	//{
	//	printf("开辟空间出错");
	//	return 0;
	//}
	//fread(pos, sizeof(char), num, pFl);

	LPCTSTR comList;
	char *curBt = new char();
	while (!feof(pFl))
	{
		fgets(curBt, 1024, pFl);
		int strlength = strlen(curBt);
		if (curBt[strlength - 1] == '\n')
		{
			strlength--;
			curBt[strlength] = '\0';


			////    
			int num = MultiByteToWideChar(0, 0, curBt, -1, NULL, 0);
			wchar_t *wide = new wchar_t[num];
			MultiByteToWideChar(0, 0, curBt, -1, wide, num);
			//const char* de = curBt;
			LPCSTR  CUR = GetUTFL(curBt);
			const char* NewFontName = curBt;
			CString str(CUR);
			//LPCTSTR CE = CUR;
			//((CComboBoxEx*)GetDlgItem(IDC_COMBO))->AddString(str);
			//(CComboBox*)GetDlgItem(m_fontNameSelectList)
			m_fontNameSelectList.AddString( str);

		}


		//comList = _T(&curBt);
		//m_fontNameSelectList.InsertString(0,(LPCTSTR)&curBt);
		//comList = _T(&curBt);
		//m_fontNameSelectList.InsertString(0, comList);
	}
	fclose(pFl);
	fclose(pFl);
	m_fontNameSelectList.SetCurSel(0);

	KillTimer(1);
	return 0;
}


LPSTR CMFCApplication1Dlg::GetUTFL(const char * str)
{
	//string result;	
	WCHAR *strSrc;
	LPSTR szRes;
	//获得临时变量的大小
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);
	//获得临时变量的大小	
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);
	//result = szRes;	
	delete[]strSrc;
	/*delete[]szRes;*/
	return szRes;

}


int CMFCApplication1Dlg::FIXEDToInt(FIXED& fixed)

{

	if (fixed.fract >= 0x8000)

		return(fixed.value + 1);

	else

		return(fixed.value);

}

//void CMFCApplication1Dlg::OnShowWindow(BOOL bShow, UINT nStatus)
//{
//	CDialogEx::OnShowWindow(bShow, nStatus);
//	LoadFontNae();
//	// TODO: 在此处添加消息处理程序代码
//}


void CMFCApplication1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	switch (nIDEvent)

	{
	case 1:
	{
		LoadFontNae();
		break;
	}
	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CMFCApplication1Dlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_fontNameSelectList.Clear();
	this->RedrawWindow();
	Sleep(300);
	CDialogEx::OnClose();
}
