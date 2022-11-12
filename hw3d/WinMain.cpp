#include "Win.h"

#include "Window.h"

#include <string>
#include <sstream>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69);
		break;
	case WM_KEYDOWN:
		if (wParam == 'F')
		{
			SetWindowText(hWnd, L"Resprects");
		}
		break;
	case WM_KEYUP:
		if (wParam == 'F')
		{
			SetWindowText(hWnd, L"Happy Hard Window");
		}
		break;
	case WM_CHAR:
		{
			static std::wstring title;
			title.push_back((wchar_t)wParam);

			SetWindowText(hWnd, title.c_str());
		}
		break;
	case WM_LBUTTONDOWN:
		{
			const POINTS pt = MAKEPOINTS(lParam);
			std::wstringstream os;
			os << "(" << pt.x << "," << pt.y << ")";
			
			SetWindowText(hWnd, os.str().c_str());
		}
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevIstance, LPSTR lpCmdLine, int nCmdShow)
{
	Window wnd(800, 300, L"Donkey Fart Box");

	// message pump
	MSG		msg;
	BOOL	gResult;
	while ( (gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (gResult == -1)
	{
		return -1;
	}
	else
	{
		return msg.wParam;
	}

	return msg.wParam;
}