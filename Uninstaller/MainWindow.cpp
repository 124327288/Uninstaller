#include "stdafx.h"
#include "MainWindow.h"

MainWindow::MainWindow() : Window(MainWndProc, _T("UNINSTALLER"), _T("Uninstaller"), 800, 600)
{
	hMenu = LoadMenu(WindowManager::GetHInstance(), MAKEINTRESOURCE(IDC_UNINSTALLER));
	SetMenu(hWnd, hMenu);
	Init();
}


MainWindow::~MainWindow()
{
	
}

void MainWindow::Show()
{
	//Refrech controls
	Window::Show();
}

void MainWindow::Hide()
{
	Window::Hide();
}

void MainWindow::Init()
{
	RECT clientRect;
	GetClientRect(hWnd, &clientRect);
	listViewPrograms = new ProgramListView(0, 50, clientRect.right, clientRect.bottom - 50, hWnd, WindowManager::GetHInstance());
}

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT message,WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		
	}
	break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// ��������� ����� � ����:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogManager::GetInstance()->ShowDialog(DIALOG_TYPE::ABOUT, hWnd);
			//DialogBox(WindowManager::GetHInstance(), MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: �������� ���� ����� ��� ����������, ������������ HDC...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
