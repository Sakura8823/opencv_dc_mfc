// DISPLAY_DIALOG1.cpp : 实现文件
//

#include "stdafx.h"
#include "opencv_dc_mfc.h"
#include "DISPLAY_DIALOG1.h"
#include "afxdialogex.h"
#include "opencv_dc_mfcDlg.h"

// DISPLAY_DIALOG1 对话框
CString file_address;  //#文件地址变量#
int flag_1=0;//#判断是否已经添加文件#
IMPLEMENT_DYNAMIC(DISPLAY_DIALOG1, CDialogEx)


DISPLAY_DIALOG1::DISPLAY_DIALOG1(CWnd* pParent /*=NULL*/)
	: CDialogEx(DISPLAY_DIALOG1::IDD, pParent)
{

}

DISPLAY_DIALOG1::~DISPLAY_DIALOG1()
{
}

void DISPLAY_DIALOG1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DISPLAY_DIALOG1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_READ, &DISPLAY_DIALOG1::OnBnClickedButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &DISPLAY_DIALOG1::OnBnClickedButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_PLAY, &DISPLAY_DIALOG1::OnBnClickedButtonPlay)
	ON_BN_CLICKED(IDCANCEL, &DISPLAY_DIALOG1::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT1, &DISPLAY_DIALOG1::OnEnChangeEditFile)
	ON_EN_CHANGE(IDC_EDIT1, &DISPLAY_DIALOG1::OnEnChangeEdit1)
END_MESSAGE_MAP()


// DISPLAY_DIALOG1 消息处理程序

BOOL DISPLAY_DIALOG1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

void DISPLAY_DIALOG1::OnBnClickedButtonRead()
{
	// TODO:  在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("mp4(*.mp4)|*.mp4|jpg(*.jpg)|*.jpg|bmp(*.bmp)|*.bmp|All files(*.*)|*.*||" ); //可供选择的后缀
	// 构造保存文件对话框   
	
	CFileDialog fileDlg(TRUE, 0, 0, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, NULL);
	CString strFilePath;   //文件路径

	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“保存”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetFileName();
		SetDlgItemText(IDC_EDIT1, strFilePath);
		//将文件地址传给全局变量
		file_address = strFilePath;
		flag_1 = 1;//表示已经添加文件
	}
}


void DISPLAY_DIALOG1::OnBnClickedButtonReset()
{
	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_EDIT1)->SetWindowText(_T(""));
	flag_1 = 0; //撤销操作会删除已经选择的文件，将flag_1赋值为1
}


void DISPLAY_DIALOG1::OnBnClickedButtonPlay()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	if (flag_1 == 0){
		AfxMessageBox(_T("没有选择任何文件！"));
		DISPLAY_DIALOG1 dlg;
		dlg.DoModal();
		//没有添加文件则返回原来界面
	}
	else{
		CopencvdcmfcDlg dlg;
		dlg.DoModal();
		//已经添加文件则跳转到视频播放界面
	}

}


void DISPLAY_DIALOG1::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}





void DISPLAY_DIALOG1::OnEnChangeEditFile()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void DISPLAY_DIALOG1::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
