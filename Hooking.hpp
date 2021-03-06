#pragma once
#include "MinHook.h"
#include "Menu.hpp"

class Hooking
{
public:
	void Initialize();
	void Uninitialize();

	void GotDevice();

	Menu* menu;
};

static int(*original_Direct3DInit)();
static int hooked_Direct3DInit();

static void(__thiscall* original_PCRenderContext_Present)(DWORD*, int, int, int);
void __fastcall hooked_PCRenderContext_Present(DWORD* _this, void* _, int a2, int a3, int a4);

static LRESULT(__stdcall* original_RegularWndProc)(HWND, UINT, WPARAM, LPARAM);
static LRESULT hooked_RegularWndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

static BOOL(WINAPI* original_SetCursorPos)(int, int);
static BOOL WINAPI hooked_SetCursorPos(int x, int y);