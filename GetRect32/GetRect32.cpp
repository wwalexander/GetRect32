// GetRect32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	HWND consoleWindow = GetConsoleWindow();

	if (consoleWindow == NULL) {
		return 1;
	}

	HWND foregroundWindow;

	while (1) {
		foregroundWindow = GetForegroundWindow();

		if (foregroundWindow != NULL && foregroundWindow != consoleWindow) {
			break;
		}

		Sleep(0);
	}

	RECT foregroundWindowRect;

	if (GetWindowRect(
		foregroundWindow,
		&foregroundWindowRect
	) == FALSE) {
		return 1;
	}

	long width = foregroundWindowRect.right - foregroundWindowRect.left;
	long height = foregroundWindowRect.bottom - foregroundWindowRect.top;

	printf(
		"%d,%d %dx%d\n",
		foregroundWindowRect.left,
		foregroundWindowRect.top,
		width,
		height
	);

	return 0;
}

